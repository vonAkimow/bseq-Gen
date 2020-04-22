#ifndef BSEQ_H
#define BSEQ_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

/*#############опнрнрхош тсмйжхи#############*/

static void MakePrimeSequence(uint8_t* sequence, uint32_t number);
static bool NumberIsPrime(uint32_t p);
static void DisplaySequence(uint8_t* sequence, uint32_t length, char* name);
static void DisplayCorrelation(double* CF, uint32_t length, char* name);
static void OneRightShift(uint8_t* sequence, uint32_t length);
static void RightShifts(uint8_t* sequence, uint32_t length, uint32_t nshifts);
static void MakeBSequence(uint32_t length, uint8_t* basesequence, uint8_t* sequence1, ...);
static void SeqPSeq(uint8_t* baseSequence, uint8_t* sequence, uint32_t length);
static void ACF(int8_t* sequence, uint32_t length, double* CF);
static void ExitMessage(void);
int DescendingSort(const void* p1, const void* p2);
static void CountI(uint8_t* sequence, uint32_t length, int8_t value);
static uint32_t CountD(double* sequence, uint32_t length, double value);
static void CalcProperties(double* sequence, uint32_t length);
/*#################################################*/



/*#############бшанп йнкхвеярбю ядбхцнб#############*/

/*#define SHIFTNUMBER1*/
/*#define SHIFTNUMBER2*/
/*#define SHIFTNUMBER3*/
#define SHIFTNUMBER4
/*#define SHIFTNUMBER5*/

/*#################################################*/

#endif // BSEQ_H

