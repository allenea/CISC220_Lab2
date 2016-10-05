/*
 * lab2lottery.hpp
 *
 *  Created on: Sep 21, 2016
 *      Author: Eric Allen, John Pae.  Leighanne Hsu. Lab 2.
 */

#ifndef LAB2LOTTERY_HPP_
#define LAB2LOTTERY_HPP_

struct Customer{
	//simplified list of attributes
	int customerID;
	int number_of_tickets;
	int **lottery_nums;// 3D array
};//customer

struct Store{
	//simplified list of attributes
	int storeID, numcust, numsold, numwinners[3];
	Customer *customer_list;
};//store


struct Owner{
	//simplified list of attributes
	int numstores, total_winners[3];
	int total_sold;
	Store *storeL;
};//owner

//FUNCTION DECLARATIONS
Owner *makeOwner();
Store makeStore();
Customer makeCustomer();
void getWinners (int winners[]);
void findWinners(Owner *owner, int *ls);
int checkwin(int *nums, int *winners);

#endif /* LAB2LOTTERY_HPP_ */
