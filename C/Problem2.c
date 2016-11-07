/*
 * =====================================================================================
 *
 *       Filename:  Problem2.c
 *
 *    Description:  Solution to Project Euler Problem 2
 *
 *        Version:  1.0
 *        Created:  11/07/2016 18:38:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christopher Lawrence (clawrence), jake.lawrence@temple.edu
 *        Company:  Temple University
 *
 * =====================================================================================
 */

#include <stdio.h>

int fibonacci(int x, int y, int z, int cap, int sum);

int main(){

	int sum = fibonacci(0,1,1,4000000, 0);
	
	printf("%d\n", sum);

	return 0;
}

int fibonacci(int x, int y, int z, int cap, int sum){
	if(x > cap){
		return sum;
	}
	if(x % 2 ==0)
		sum += x;
	return fibonacci(y,z,y+z,cap, sum);
}
