/*
 * lab2lottery.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: Eric Allen, John Pae.  Leighanne Hsu. Lab 2.
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lab2lottery.hpp"
using namespace std;

//FUNCTION DEFINITIONS
Owner *makeOwner() {
	Owner *newOwner;
	newOwner = new Owner;
	//stores the owner owns.. between 1-10
	newOwner->total_sold = 0;
	newOwner->total_winners[0] = 0;
	newOwner->total_winners[1] = 0;
	newOwner->total_winners[2] = 0;
	newOwner->numstores = (rand() % 10) + 1;
	newOwner->storeL = new Store[newOwner->numstores];
	cout << "Stores Owned:" << newOwner->numstores << endl;

	// points to an owner
	// makes new owner
	// References which owner's stores
	//newOwner->stores = stores;

	for (int i = 0; i < newOwner->numstores; i++) { //less than
		//makes a list of
		newOwner->storeL[i] = makeStore();
	}
	for (int i = 0; i < newOwner->numstores; i++) { //less than
		newOwner->total_sold += newOwner->storeL[i].numsold;
		// Sums total number of tixs sold from all owners of all the stores
	}
	return newOwner;
}

Store makeStore() {
	//makes a store
	Store newStore;
	//gives store id number randomly assigned between 1 and 100
	newStore.storeID = (rand() % 100) + 1;
	//cout << "StoreID:  " << newStore.storeID << endl; //COMMENT OUT

	// randomly picks how many customers that store will have, between 1-10 customers
	newStore.numcust = (rand() % 10) + 1;
	cout << "Number of Customers:  " << newStore.numcust << endl; //COMMENT OUT
	//set to 0 to initialize
	newStore.numsold = 0;
	newStore.customer_list = new Customer[newStore.numcust];
	//assigns number of customers to the store
	//Makes a list of customers
	for (int i = 0; i < newStore.numcust; i++) {
		newStore.customer_list[i] = makeCustomer();
		//assigns the total number sold to each customer
	}
	for (int i =0; i<newStore.numcust; i++){
		newStore.numsold += newStore.customer_list[i].number_of_tickets;

	}
	//cout<<"Sold at Store:"<<newStore.numsold<<endl; //COMMENT OUT

	return newStore;
}

Customer makeCustomer() {
	Customer newCustomer;

	newCustomer.customerID = (rand() % 1000) + 1; //generates random id between 1 and 1000
	newCustomer.number_of_tickets = (rand() % 20) + 1; //number of tickets random between 1-20
	newCustomer.lottery_nums = new int *[newCustomer.number_of_tickets];

	//cout<< "Customer ID:  " <<newCustomer.customerID<<endl;  //COMMENT OUT
	//cout<< "# of Tix:  " <<newCustomer.number_of_tickets <<endl; //COMMENT OUT

	for (int i = 0; i < newCustomer.number_of_tickets; i++) {
		newCustomer.lottery_nums[i] = new int[3];
		//assigns lotto numbers
		int N1 = rand() % 10;
		int N2 = rand() % 10;
		int N3 = rand() % 10;
		//checks to make sure lottery numbers arent the same
		while ((N1 == N2) || (N1 == N3) || (N2 == N3)) {
			//Permanently assigns lotto number
			N1 = rand() % 10;
			N2 = rand() % 10;
			N3 = rand() % 10;
		}	// gives the customer his/her 3 lotto numbers
		newCustomer.lottery_nums[i][0] = N1;
		newCustomer.lottery_nums[i][1] = N2;
		newCustomer.lottery_nums[i][2] = N3;

	}
	return newCustomer;
}

void getWinners(int win[]) {
	// initialize variables
	int first_win, second_win, third_win;
	do {
		//randomize
		first_win = rand() % 10;
		second_win = rand() % 10;
		third_win = rand() % 10;
	}
	//while they aren't the same
	while (second_win == first_win || third_win == first_win
			|| third_win == second_win);
	//assignment
	win[0] = first_win;
	win[1] = second_win;
	win[2] = third_win;
}

int checkwin(int arr1[2], int arr2[2]) {
	int win = 0;
	int N1 = arr1[0];
	int N2 = arr1[1];
	int N3 = arr1[2];
	for (int i = 0; i < 3; i++) {
		if (N1 == arr2[i] || N2 == arr2[i] || N3 == arr2[i]) {
			win++;
		}
	}
	return win;
}

void findWinners(Owner *owner, int *win) {

	cout << "Total Lottery Tickets Sold:   " << owner->total_sold << endl;
	cout << "Winning Lottery Numbers Are:  " << win[0] << "," << win[1] << ","<< win[2] <<endl;
	for (int i = 0; i < owner->numstores; i++) {
		Store currStore = owner->storeL[i];
		cout << "\t" << "Store ID:  " << currStore.storeID << endl;
		for (int j = 0; j < currStore.numcust; j++) {
			Customer currCust = currStore.customer_list[j];
			cout << "\t" << "\t" << "Customer ID:  " << currCust.customerID
					<< endl;
			for (int k = 0; k < currStore.numsold; k++) {
				int num_correct = checkwin(currCust.lottery_nums[k], win);
				if (num_correct == 1) {
					owner->total_winners[0] += 1;
					//count1 += 1;
				} else if (num_correct == 2) {
					owner->total_winners[1] += 1;
					//count2 += 1;

				} else if (num_correct == 3) {
					owner->total_winners[2] += 1;
					//count3 += 1;
				}
				cout << "\t" << "\t" << "\t" << "Ticket:"
						<< currCust.lottery_nums[k][0] << ","
						<< currCust.lottery_nums[k][1] << ","
						<< currCust.lottery_nums[k][2] << "\t" << "Matched:  "
						<< num_correct << endl;
				cout << "Match1: " << owner->total_winners[0] << "||  Match2:" << owner->total_winners[1] << "Match3:"<< owner->total_winners[2] << "||  Out Of:" << owner->storeL[i].numsold << "Tickets"<< endl;

			}

		}

	}
}
