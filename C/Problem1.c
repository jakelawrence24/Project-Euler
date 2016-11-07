/*
 * =====================================================================================
 *
 *       Filename:  Problem1.c
 *
 *    Description:  Solution for problem 1 for project euler
 *
 *        Version:  1.0
 *        Created:  11/07/2016 18:14:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christopher Lawrence (clawrence), jake.lawrence@temple.edu
 *        Company:  Temple University
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(){
	int i = 1, lim = 1000, sum = 0;

	for(i = 1; i < lim; i++){
		if(i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	printf("Sum: %d\n", sum);
	
	return 0;
}
