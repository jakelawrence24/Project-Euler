/*
 * =====================================================================================
 *
 *       Filename:  Problem5.c
 *
 *    Description:  Solution for problem 5 of project euler
 *
 *        Version:  1.0
 *        Created:  11/09/2016 23:29:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christopher Lawrence (clawrence), jake.lawrence@temple.edu
 *        Company:  Temple University
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

void toStri(int aPal);
int getLength(int aPal);

int main(){
	int aPal = 800433;
	toStri(aPal);

	//printf("%s\n", sPal);

	return 0;
}

void toStri(int aPal){
	int length_aPal = getLength(aPal);
	char s_aPal[length_aPal];
	initArray(s_aPal, aPal);
	char rs_aPal[] = s_aPal;
	reverseString(rs_aPal, length_aPal);

	printf("S1: %s S2: %s\n", s_aPal, rs_aPal);
}

int getLength(int aPal){
	int i = 0;
	while(aPal > 0){
		aPal /= 10;
		i++;
	}

	return i;
}

void initArray(char s_aPal[], int aPal){
	int i = 0;
	while(aPal > 0){
		char c = (char) aPal % 10;
		aPal /= 10;
		s_aPal[i] = c;
		i++;
	}
}

void reverseString(char rs_aPal, int length){
	int i;
	for(i = 0; i < length / 2; i++){
		char temp = rs_aPal[length - i];
		rs_aPal[length - 1] = rs_aPal[i];
		rs_aPal[i] = temp;
	}
}
		


	
		
