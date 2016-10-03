/*
 * lab2mains.cpp


 *
 *  Created on: Oct 3, 2016
 *      Author: ericallen
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lab2lottery.cpp" //not needed but I get redlines under cout and endl otherwise....
#include "lab2lottery.hpp"


int main() {
	srand(time(NULL));
	Owner *me= makeOwner();
	int winners[3] = {0,0,0};
	getWinners (winners);
	for (int i = 0; i < 3; i++) {
		cout << winners[i] << endl;
	}
	findWinners(me, winners);
	cout<<"Won with 1 number: "<<me-> total_winners[0]<< endl;
	cout<<"Won with 2 numbers: "<< me->total_winners[1]<< endl;
	cout<< "Won with 3 numbers: "<<me->total_winners[3]<< endl;

	//cout << x << endl;
	return 0;
} //main

