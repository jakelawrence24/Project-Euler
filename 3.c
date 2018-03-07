/*
 * =====================================================================================
 *
 *       Filename:  Problem3.c
 *
 *    Description:  Solution for problem 3 for project euler
 *
 *        Version:  1.0
 *        Created:  11/09/2016 16:29:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christopher Lawrence (clawrence), jake.lawrence@temple.edu
 *        Company:  Temple University
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <math.h>

int getMaxPrimeFactor(double value);
int isPrime(double value);

int main(){
	double value = 600851475143;
	int maxPrimeFactor = getMaxPrimeFactor(value);

	printf("Max prime factor of %.0lf: %d\n", value, maxPrimeFactor);

	return 0;
}

int getMaxPrimeFactor(double value){
	double i, g = 0;
	double product = 1;
	for(i = 1; i < value / 2.0; i++){
		if(isPrime(i) && fmod(value, i) == 0){
			g = i;
			product *= i;
		}

		if(product >= value)
			break;
	}

	return (int)g;
}

int isPrime(double value){
	int i;
	for(i = 2; i < value; i++){
		if(fmod(value, i) == 0)
			return 0;
	}

	return 1;
}


