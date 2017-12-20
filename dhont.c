//
// Created by Eduardo Castillo on 17/12/2017.
//

#include "dhont.h"

#define DHONT_FORMULA(p) ((p).votes/((p).seats + 1))

void dhont_distribute(Party *parliament, const unsigned int n_parties, const unsigned int n_seats) {
	unsigned int i; //for iteration purposes :)
	/*
	ALGORITHM:
	1. Apply Hont's formula to each party
	2. Assign a seat to the party with most votes
	3. Repeat until all seats are assigned
	*/
	for(i = 0; i < n_seats;i++){
		//get the major party according to the formula
		unsigned int max_dhont = 0,max_dhont_index = 0,p;
		for(p = 0; p < n_parties;p++){
			const unsigned int dhont = DHONT_FORMULA(parliament[p]);
			if(dhont > max_dhont){
				max_dhont = dhont;
				max_dhont_index = p;
			}
		}

		//now we have the index of the major party, we use it to increase its seats by one
		parliament[max_dhont_index].seats++;
	}
}
