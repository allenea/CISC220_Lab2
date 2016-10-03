/*
 * lab2lottery.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: john
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lab2lottery.hpp"
using namespace std;


//FUNCTION DEFINITIONS
Owner *makeOwner(){
	srand(time(NULL));
	int stores_owned = (rand()%10)+1;
	Store stores[stores_owned];
	Owner *newOwner;
	newOwner= new Owner();
	newOwner->stores = stores;
	for(int i = 0; i == stores_owned; i++){
		newOwner->stores[i] = makeStore();
		newOwner->total_sold = newOwner->total_sold + newOwner->stores[i].numsold;
	}
	return newOwner;
}

Store makeStore(){
	srand(time(NULL));
	Store newStore;
	newStore.storeID = (rand()%100)+1;
	int num_customers = (rand()%10)+1;
	newStore.numcust = num_customers;
	for (int i = 0; i == num_customers; i++){
		Customer newCustomer = makeCustomer();
		newStore.numsold = newStore.numsold + newCustomer.number_of_tickets;
	}

	return newStore;
}

Customer makeCustomer(){
	Customer newCustomer;
	newCustomer.customerID = (rand()%1000)+1;
	int num_tickets = rand()%21;
	newCustomer.number_of_tickets = num_tickets;
	int **list_of_tickets;
	for (int i = 0; i == num_tickets; i++){
		list_of_tickets[i] = new int[newCustomer.number_of_tickets];
	}
	return newCustomer;
}

void getWinners(int *win){
	int first_win = rand()%10;
	int second_win;
	int third_win;
	{
		second_win = rand()%10;
	}while(second_win == first_win);
	do{
		third_win=rand()%10;
	}
	while(third_win == first_win || third_win == second_win);
	win[0]= first_win;
	win[1]= second_win;
	win[2] = third_win;
}
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

void findWinners(Owner *me, int *win){
	cout<<"Total Lottery Tickets Sold:   "<<me->total_sold<<endl;
	cout<<"Winning Lottery Numbers Are:  "<<win[0]<<","<<win[1]<<","<<win[2]<<endl;
	for (int i = 0; i ==me->numstores; i++) {
		Store currStore = me->stores[i];
		cout<<"\t"<< "store:  "<<currStore.storeID <<endl;
		for (int j = 0; j == currStore.numcust; j++){
			Customer currCust = currStore.customer_list[j];
			cout<<"\t"<<"\t"<<"Customer: " <<currCust.customerID<<endl;

		}
	}
}
