/*
 * QuineM.h
 *
 *  Created on: May 16, 2017
 *      Author: kmuhamm1
 */

#ifndef QUINEM_H_
#define QUINEM_H_


#define MAX_SIZE 256
#define BIT_MASK1 0x80000000
#define BIT_MASK2 0x00000001
#define INPUT_VARIABLES 10
//#define DEBUG_COL1
#undef DEBUG_COL2
#define SHIFT ((8*sizeof(x))-Quine_NumberOfBits(Quine_HighestSOP))


struct ColumnElement {
	unsigned int SOP;
	unsigned int prime;
	unsigned int Group;
	unsigned int IsRepresented;
};

struct Result{
	unsigned int Mask;
	unsigned int Element;
	unsigned int Essential;
	unsigned int temp;
};
struct MaskElement {
	unsigned int Mask;
	unsigned int UpdatedMask;
	unsigned int prime;
	unsigned int Group;
	unsigned int GroupElement;
	unsigned int PreGroupElement;
};

extern struct ColumnElement Quine_SopInput[MAX_SIZE];
extern MaskElement Quine_Mask[MAX_SIZE];
extern Result Quine_Result[MAX_SIZE];

extern unsigned int Quine_SopCount;
extern unsigned int Quine_HighestSOP;
extern unsigned int Quine_SopMaxBits;
extern unsigned int Quine_MaskLimit;
extern unsigned int Quine_MaskNewLimit;
extern unsigned int Quine_ResultLimit;

void Quine_SopStore(void);
void Quine_SOPGrouping(void);
void Quine_SOPGroupSort(void);
void Quine_SopDisplay(void);
void Quine_SopGroupDisplay(void);
void Quine_DisplaySopCompleteExpression(void);
unsigned int Quine_GetHighestSOP(void);
unsigned int Quine_NumberOfBits(unsigned int);
unsigned int Quine_NumberOfOnes(unsigned int );
void Quine_DisplaySopElementExpression(unsigned int);
void Quine_DisplaySopElementReducedExpression(unsigned int,unsigned int);
void Quine_DisplaySopCompleteExpression(void);
void Quine_SOPGroupSort(void);
void Quine_ColumnI(void);
void Quine_ColumnII(void);
void Quine_DisplayMask(void);
void Quine_ReducedExpression(void);
void Quine_DisplayUpdatedMask(void);
void Quine_RedundencyRemoval(void);
void Quine_OutputExpression(void);
unsigned int  Quine_GetSimilarityCode(unsigned int ,unsigned int);



#endif /* QUINEM_H_ */
