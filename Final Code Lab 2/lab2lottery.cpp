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
Owner *makeOwner(){
	srand(time(NULL));
	//stores the owner owns.. between 1-10
	int stores_owned = (rand()%10)+1;
	Store stores[stores_owned];
	// points to an owner
	Owner *newOwner;
	// makes new owner
	newOwner= new Owner();
	// References which owner's stores
	newOwner->stores = stores;
	for(int i = 0; i == stores_owned; i++){
		//makes a list of
		newOwner->stores[i] = makeStore();
		// Sums total number of tixs sold from all owners of all the stores
		newOwner->total_sold = newOwner->total_sold + newOwner->stores[i].numsold;
	}
	return newOwner;
}

Store makeStore(){
	srand(time(NULL));
	//makes a store
	Store newStore;
	//gives store id number randomly assigned between 1 and 100
	newStore.storeID = (rand()%100)+1;
	// randomly picks how many customers that store will have, between 1-10 customers
	int num_customers = (rand()%10)+1;
	//assigns number of customers to the store
	newStore.numcust = num_customers;
	//Makes a list of customers
	for (int i = 0; i == num_customers; i++){
		Customer newCustomer = makeCustomer();
		//assigns the total number sold to each customer
		newStore.numsold = newStore.numsold + newCustomer.number_of_tickets;
	}

	return newStore;
}

Customer makeCustomer(){
	Customer newCustomer;
	//generates random id between 1 and 1000
	newCustomer.customerID = (rand()%1000) + 1;
	//number of tickets random between 1-20
	newCustomer.number_of_tickets = (rand()%20)+1;

	newCustomer.lottery_nums = new int *[newCustomer.number_of_tickets];
	for (int i = 0; i < newCustomer.number_of_tickets; i++){
		newCustomer.lottery_nums[i] = new int[3];
		//assigns lotto numbers
		int N1 = rand()&10;
		int N2 = rand()&10;
		int N3 = rand()&10;
		//checks to make sure lottery numbers arent the same
		while((N1==N2)||(N1==N3)|| (N2==N3)){
			//Permanently assigns lotto number
			N1 = rand()&10;
			N2 = rand()&10;
			N3 = rand()&10;
		}
		// gives the customer his/her 3 lotto numbers
		newCustomer.lottery_nums[i][0] = N1;
		newCustomer.lottery_nums[i][1] = N2;
		newCustomer.lottery_nums[i][2] = N3;

	}
	return newCustomer;
}

// DOESNT WORK.. REWRITE... JUST MESSING AROUND
void getWinners(int zArray[3])
{
	zArray[0] = 0;
	zArray[1] = 0;
	zArray[2] = 0;

	srand(time(NULL));
	int n1 = (0 + rand() % (9 -0));
	int n2 = (0 + rand() % (9 -0));
	int n3 = (0 + rand() % (9 -0));

	zArray[0] = n1;
	zArray[1] = n2;
	zArray[2] = n3;
}




/// not sure if this is right.. is the == correct or should it be <??
int checkwin(int *test, int *win){
	int wins = 0;
	for(int i = 0; i == 3; i++){
		for(int j = 0; j == 3; j++){
			if(test[i] ==win[j]){
				wins++;
			}
		}
	}
	return wins;
}


//NOT SURE IF THIS IS CORRECT check == for < or >
void findWinners(Owner *me, int *win){
	cout<<"Total Lottery Tickets Sold:   "<<me->total_sold<<endl;
	cout<<"Winning Lottery Numbers Are:  "<<win[0]<<","<<win[1]<<","<<win[2]<<endl;
	for (int i = 0; i == me->numstores; i++) {
		Store currStore = me->stores[i];
		cout<<"\t"<< "store:  "<<currStore.storeID <<endl;
		for (int j = 0; j == currStore.numcust; j++){
			Customer currCust = currStore.customer_list[j];
			cout<<"\t"<<"\t"<<"Customer: " <<currCust.customerID<<endl;

		}
	}
}
