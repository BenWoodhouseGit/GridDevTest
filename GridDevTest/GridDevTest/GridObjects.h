#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<math.h>
#include "vecmath.h"


class ticketEvent
{

public:

	//object index, object vector and individual positions, ticket quantitiy and price of said tickets. 
	int eventIndex;
	vec2 position;
	double positionX;
	double positionY;
	int noOfTickets;
	double price;

	
	//default contructor
	ticketEvent() :position(0.0),noOfTickets(0),price(0.00)
	{}

	
};
