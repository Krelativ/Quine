//============================================================================
// Name        : QuineM.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<ctime>
#include<conio.h>
#include "QuineM.h"
#undef TESTBENCH
using namespace std;
//m(0,1,2,5,6,7,8,9,10,14)
//Test
//f(a,b,c,d)=∑m(0,1,2,5,6,7,8,9,10,14)=>
//10
//f = a’bd + b’c’ + cd’

#define MAX_SIZE 256
#define BIT_MASK1 0x80000000
#define BIT_MASK2 0x00000001
#define INPUT_VARIABLES 10


int main(int argc, char *argv []) {
    int h;

#ifdef TESTBENCH
	//printf("Enter the number of SOP: \n");
    Quine_SopCount=atoi(argv[1]);
 	//printf("Enter your SOP: \n");
 	for(h=2;h<argc;h++){

		Quine_SopInput[h-2].SOP= atoi(argv[h]);
		cout<<Quine_SopInput[h-2].SOP<<"\t";
		if(Quine_HighestSOP < Quine_SopInput[h-2].SOP)
		Quine_HighestSOP=Quine_SopInput[h-2].SOP;
 	}
#endif

#ifndef TESTBENCH
	printf("Enter the number of SOP: \n");
 	cin>>Quine_SopCount;
 	printf("Enter your SOP: \n");
 	Quine_SopStore();
#endif
	Quine_SOPGrouping();
	Quine_SOPGroupSort();
	Quine_SopDisplay();
	Quine_SopGroupDisplay();
    cout<<"\n\n\n\n\n\t\t\t\t\t\t THE SYSTEM INPUTS : "<<Quine_NumberOfBits(Quine_GetHighestSOP());
    cout<<"\n\n>>> THE CANONICAL EXPRESSION = \n";
    Quine_DisplaySopCompleteExpression();
    Quine_ColumnI();
#ifdef DEBUG_COL2
    Quine_DisplayMask();
    cout<<"\n################################";
#endif
    Quine_ColumnII();
#ifdef DEBUG_COL2
    Quine_DisplayUpdatedMask();
#endif
    Quine_ReducedExpression();
    Quine_OutputExpression();
    Quine_RedundencyRemoval();
#ifdef TESTBENCH
	cin>>h;
#endif
	return 0;

}
