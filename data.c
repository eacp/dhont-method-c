//
// Created by Eduardo Castillo on 17/12/2017.
//

#include "data.h"

//Gets the data from a file and turn it into a PARTY structure
Party get_party_from_file(FILE *file) {
	Party p;
	fscanf(file,"%s %u",p.name,&p.votes);
	p.seats = 0;
	return p;
}

//Gets the total number of votes given the number of parties
unsigned int sum_votes(Party *parties, const unsigned int n_parties) {
	unsigned int sum = 0,i;
	for(i = 0; i < n_parties;i++) sum+=parties[i].votes;
	return sum;
}

//Enforce the policy that some countries have about minumum percentages
void enforce_min_percentage_policy(Party *parties, const unsigned int np, const unsigned int min) {
	unsigned int i;
	//here we get the minimum votes required
	const unsigned int min_votes = (unsigned int)(sum_votes(parties,np)*(min/100.0f));
	//here we iterate over the Party array and set to 0 all the parties below the minimum
	for(i = 0; i < np;i++) if(parties[i].votes < min_votes) parties[i].votes = 0;
}
