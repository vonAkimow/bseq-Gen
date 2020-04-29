#ifndef BGEN_H
#define BGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#include "calculations.h"

/*FUNCTION PROTOTYPES*/
void MakePrimeSequence(uint8_t* sequence, uint32_t number);
void DisplaySequence(uint8_t* sequence, uint32_t length, char* name);
void DisplayCorrelation(int16_t* CF, uint32_t length, char* name);





#endif // BGEN_H

