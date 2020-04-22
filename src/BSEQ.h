#ifndef BSEQ_H
#define BSEQ_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

/*#############œ–Œ“Œ“»œ€ ‘”Õ ÷»…#############*/
int BGEN(void);
void MakePrimeSequence(uint8_t* sequence, uint32_t number);
static bool NumberIsPrime(uint32_t p);
void DisplaySequence(uint8_t* sequence, uint32_t length, char* name);
void DisplayCorrelation(double* CF, uint32_t length, char* name);
static void OneRightShift(uint8_t* sequence, uint32_t length);
 void RightShifts(uint8_t* sequence, uint32_t length, uint32_t nshifts);
void MakeBSequence(uint32_t length, uint8_t* basesequence, uint8_t* sequence1, ...);
void SeqPSeq(uint8_t* baseSequence, uint8_t* sequence, uint32_t length);
void ACF(int8_t* sequence, uint32_t length, double* CF);
static void ExitMessage(void);
int DescendingSort(const void* p1, const void* p2);
void CountI(uint8_t* sequence, uint32_t length, int8_t value);
uint32_t CountD(double* sequence, uint32_t length, double value);
static void CalcProperties(double* sequence, uint32_t length);
/*#################################################*/



#endif // BSEQ_H

