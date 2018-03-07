/*
 * =====================================================================================
 *
 *       Filename:  10.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/06/2018 18:52:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christopher Lawrence (clawrence), jake.lawrence@temple.edu
 *        Company:  Temple University
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int val);

int main(int argc, char* argv[]){
	int count = 10;

	if(argc == 2){
		count = atoi(argv[argc-1]);
	}

	printf("%d\n", count);
	double sum = 2;
	int i;
	for(i = 3; i < count; i+=2){
		if(isPrime(i))
			sum += i;
	}

	printf("%lf\n", sum);

	return 0;
}

int isPrime(int val){
	int i;
	if(val % 2 == 0)
		return 0;
	for(i = 3; i < sqrt(val)+1; i+=2){
		if(val % i == 0)
			return 0;
	}
	return 1;
}
