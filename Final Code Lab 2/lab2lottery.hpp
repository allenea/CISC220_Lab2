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
	int customerID, number_of_tickets;
	int **lottery_nums;// 3D array
};

struct Store{
	//simplified list of attributes
	int storeID, numcust, numsold, numwinners[3];
	Customer *customer_list;
};


struct Owner{
	//simplified list of attributes
	int numstores, total_sold, total_winners[3];
	Store *stores;
};

//FUNCTION DECLARATIONS
Owner *makeOwner();
Store makeStore();
Customer makeCustomer();
void getWinners (int winners[]);
void findWinners(Owner *owner, int *ls);
int checkwin(int *nums, int *winners);

#endif /* LAB2LOTTERY_HPP_ */
