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
void initArray(char s_aPal[], int aPal);
void duplicateArray(char s_aPal[], char rs_aPal[], int length_aPal);
void reverseString(char rs_aPal[], int length);

int main(){
	int aPal = 800433;
	toStri(aPal);

	//printf("%s\n", sPal);

	return 0;
}

void toStri(int aPal){
	int length_aPal = 0;
	length_aPal = getLength(aPal);
	char s_aPal[length_aPal];
	initArray(s_aPal, aPal);
	char rs_aPal[length_aPal];
	duplicateArray(s_aPal, rs_aPal, length_aPal);
	//reverseString(rs_aPal, length_aPal);

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
		char c = 'c';
		aPal /= 10;
		s_aPal[i] = c;
		i++;
	}
}

void duplicateArray(char s_aPal[], char rs_aPal[], int length_aPal){
	int i;
	for(i = 0; i < length_aPal; i++){
		rs_aPal[i] = s_aPal[i];
	}
}

void reverseString(char rs_aPal[], int length){
	int i;
	for(i = 0; i < length / 2; i++){
		char temp = rs_aPal[length - i];
		rs_aPal[length - 1] = rs_aPal[i];
		rs_aPal[i] = temp;
	}
}
		


	
		
