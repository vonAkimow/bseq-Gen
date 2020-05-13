#ifndef CALC_H
#define CALC_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#include "bgeneration.h"

/*FUNCTION PROTOTYPES*/
void OneRightShift(uint8_t* sequence, uint32_t length);
bool NumberIsPrime(uint32_t p);
void RightShifts(uint8_t* sequence, uint32_t length, uint32_t nshifts);
void SeqPSeq(uint8_t* baseSequence, uint8_t* sequence, uint32_t length);
void PACF(int8_t* sequence, uint32_t length, int16_t* CF);
void AACF(int8_t* sequence, uint32_t length, int16_t* CF);
void PVCF(int8_t* sequence1, int8_t* sequence2, uint32_t length, int16_t* CF);
void AVCF(int8_t* sequence1, int8_t* sequence2, uint32_t length, int16_t* CF);
int DescendingSort(const void* p1, const void* p2);
uint32_t CountI(uint8_t* sequence, uint32_t length, int8_t value);
uint32_t CountD(int16_t* sequence, uint32_t length, int16_t value);
void CalcProperties(int16_t* CF, uint32_t length);
void IntToString(char* str,uint8_t* sequence,uint32_t length);
double ExpVal(int16_t* CF, uint32_t length,bool absUsage);
double SigmaVal(int16_t* CF, uint32_t length,double ExpVal);

extern inline uint16_t MaxValue(int16_t value1, int16_t value2);
extern inline double MaxPeakLevel(int16_t val1,int16_t val2,uint32_t length);
extern inline double AveragePeakLevel(double ExpVal, uint32_t length);


#endif
