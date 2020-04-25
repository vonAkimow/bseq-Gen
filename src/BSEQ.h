#ifndef BSEQ_H
#define BSEQ_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

/*#################Прототипы функций#################*/
void MakePrimeSequence(uint8_t* sequence, uint32_t number);
static bool NumberIsPrime(uint32_t p);
void DisplaySequence(uint8_t* sequence, uint32_t length, char* name);
void DisplayCorrelation(int16_t* CF, uint32_t length, char* name);
static void OneRightShift(uint8_t* sequence, uint32_t length);
void RightShifts(uint8_t* sequence, uint32_t length, uint32_t nshifts);
void SeqPSeq(uint8_t* baseSequence, uint8_t* sequence, uint32_t length);
void PACF(int8_t* sequence, uint32_t length, int16_t* CF);
void AACF(int8_t* sequence, uint32_t length, int16_t* CF);
int DescendingSort(const void* p1, const void* p2);
uint32_t CountI(uint8_t* sequence, uint32_t length, int8_t value);
uint32_t CountD(int16_t* sequence, uint32_t length, int16_t value);
void CalcProperties(int16_t* sequence, uint32_t length);
void IntToString(char* str,uint8_t* sequence,uint32_t length);
/*#################################################*/



#endif // BSEQ_H

