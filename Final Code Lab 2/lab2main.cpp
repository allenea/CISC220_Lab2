/*
 * lab2mains.cpp


 *
 *  Created on: Oct 3, 2016
 *      Author: Eric Allen, John Pae.  Leighanne Hsu. Lab 2.
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
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
	cout << "won with 1 number: "<< me->total_winners[0] << endl;
	cout << "won with 2 numbers: " << me->total_winners[1] << endl;
	cout << "won with 3 numbers: " << me->total_winners[2] << endl;
	//cout << x << endl;
	return 0;
} //main


