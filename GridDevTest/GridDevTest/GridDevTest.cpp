// GridDevTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GridObjects.h" // Header file for the TicketEvent Object
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <sstream>
#include "math.h"
#include <time.h>
#include "vecmath.h" //imported to manipute co-ords as vector objects


using namespace std;

//Calculates the manhatten distance between two points

double Distance(int userX, int userY, int ObjectX, int ObjectY)
{
	double result = sqrt(((ObjectX - userX)*(ObjectX - userX)) + ((ObjectY - userY)*(ObjectY - userY)));
	return result;
}



int main()
{
	//intilise user input variables,  temp variables, distance matrix, blacklist(duplicate checklist), flag for input extraction and randomiser seed.
	int userX = 0;
	int userY = 0;
	string temp1 = "";
	string temp2 = "";
	int travelDistance[10][2];
	string userInput = "";
	vec2 blacklist[10];
	vec2 userCoOrd = (0,0);
	bool flag = false;
	srand(time(NULL));

	//create 10 events and set their variables to suitble random variables
	ticketEvent* Events = new ticketEvent[10];

	for (int i = 0; i < 10; i++)

	{	
		Events[i].positionX = rand() % 20 - 10;
		Events[i].positionY = rand() % 20 - 10;
		Events[i].position(0) = Events[i].positionX;
		Events[i].position(1) = Events[i].positionY;

		Events[i].noOfTickets = rand() % 100;
		Events[i].price = rand() % 1000;
		Events[i].price = Events[i].price* 1.37;
		Events[i].eventIndex = i;

		//before commiting the position, ensure its not on the blacklist, re-roll until non-duplicate.
		for (int j = 0; j < 10; j++)
		{
			if (Events[i].position == blacklist[j])
			{
				while (Events[i].position == blacklist[j]) //re-roll
				{
					Events[i].positionX = rand() % 20 - 10;
					Events[i].positionY = rand() % 20 - 10;
					Events[i].position(0) = Events[i].positionX;
					Events[i].position(1) = Events[i].positionY;
					j = -1; //reset duplicate check
				}			
			}
		}
					blacklist[i] = Events[i].position;
		
	}
	

	cout<<"Please Enter X and Y co-ordinates of your position seperated by a comma (range of -10 to 10) without Spaces" << endl;
    cin >>  userInput;

	//Take user input and manually delimit by comma variable.
	for (int i = 0; i < userInput.length(); i++)
	{ 
	
		if ((flag == true) && (userInput[i] != ','))
		{
			temp2 = temp2 + userInput[i];
		}
		else
		if ((flag == false) && (userInput[i] != ','))
		{
		 temp1 = temp1 + userInput[i];
		}
		else
			if (userInput[i] = ',')
			{
				flag = true; //once comma is his, flag switchs and causes loop to fill the second element
			}
		
	};

	// string -> numerics, set values for user position accordingly.
	userX = stoi(temp1);
	userY = stoi(temp2);
	userCoOrd(0) = userX;
	userCoOrd(1) = userY;

	//Generate and array of distances from the user and attach those distances with an object's index. 
	for (int i = 0; i < 10; i++)
	{
		travelDistance[i][0] = Distance(userCoOrd(0), userCoOrd(1), Events[i].positionX, Events[i].positionY);
		travelDistance[i][1] = i;
	}



	//Sorts a 2-d array on 1 column or cell, 
	//this is taking the distance list and arranning from shortest to longest whilst ensuring the index is still attached to that distance.
	qsort(travelDistance, 10, sizeof(*travelDistance),
		[](const void *arg1, const void *arg2)->int
	{
		int const *lhs = static_cast<int const*>(arg1);
		int const *rhs = static_cast<int const*>(arg2);
		return (lhs[0] < rhs[0]) ? -1
			: ((rhs[0] < lhs[0]) ? 1
				: (lhs[1] < rhs[1] ? -1
					: ((rhs[1] < lhs[1] ? 1 : 0))));
	});


	//display elements 0 - 4 from the distance array after sorting, These are the 5 closest results. 
	cout << "The closest events are:" << endl;


for (int i = 0; i < 5; i++)
{
		int index = travelDistance[i][1];
		
		cout << "Event: " << travelDistance[i][1] << " Distance: " << travelDistance[i][0] << " Price: $" << Events[index].price << " Quanitiy: " << Events[index].noOfTickets << endl;
}




return 0;
}








