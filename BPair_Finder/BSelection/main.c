#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
volatile uint16_t number = 509, shift1 = 0, shift2 = 0, shift3 = 0, shift4 = 0, k = 0;


static void PACF(int8_t* sequence, uint32_t length, int16_t* CF)
{

	int16_t* r = (int16_t*)calloc(length, sizeof(int16_t));
	int8_t* sequence1 = (int8_t*)calloc(length, sizeof(int8_t));
	uint16_t tau = 0, f = 0, g = 0;
	int16_t sum = 0;
	CF[0] = length;

	for (f = 0; f < length; f++)//çàìåíà íóëåé íà "-1"
	{
		if (sequence[f] == 0) sequence[f] = -1;
		else sequence[f] = 1;
	}
	memcpy(sequence1, sequence, length); /*êîïèðóåì sequence â sequence1*/

	for (tau = 1; tau < length; tau++)
	{
		register int8_t c = sequence1[length - 1]; /*çàïîìíèëè ïîñëåäíèé ýëåìåíò ïîñëåäîâàòåëüíîñòè*/
		for (g = length-1; g > 0; g--)
		{
			sequence1[g] = sequence1[g - 1];
		}
		sequence1[0] = c; /*ïåðâûé ýëåìåíò ðàâåí ïîñëåäíåìó*/
		for(f = 0 ; f < length ; f++)
		{
			r[f] = sequence1[f]*sequence[f];
			sum = sum + r[f];
		}
		CF[tau] = sum;
		sum = 0;
	}
	free(sequence1);
	free(r);
}
bool NumberIsPrime(uint16_t p)
{
	if (p < 2) return false;
	if (p == 2) return true;
	if (p % 2 == 0) return false;

	double limit = sqrt(p);

	for (uint16_t i = 3; i <= limit; i += 2)
	{
		if ((p % i) == 0) return false;
	}
	return true;
}
static void SeqPSeq(uint8_t* baseSequence, uint8_t* sequence, uint32_t length)
{
	for (uint32_t i = 0; i < length; i++)
	{
		baseSequence[i] ^= sequence[i];
	}
}
static void MakePrimeSequence(uint8_t* sequence, uint32_t number)
{
	uint8_t j = 1;
	for (uint32_t i = 0; i < number; i++)
	{
		sequence[i] = NumberIsPrime(j);
		j++;
	}
}
static void DisplaySequence(uint8_t* sequence, uint32_t length, char* name)
{
	printf("\n%s", name);
	for (uint16_t i = 0; i < length; i++)
	{
		printf("%i", sequence[i]);
	}
}

static void DisplayCorrelation(int16_t* CF, uint32_t length, char* name)
{
	printf("\n");
	printf("\n%s", name);
	for (uint16_t i = 0; i < length; i++)
	{
		printf("\n%d", CF[i]);
	}
	printf("\n");
}
static void IntToString(char* str,uint8_t* sequence,uint32_t length)
{
    for (uint32_t i = 0; i < length; i++)
    {
     sprintf(&str[i], "%d",sequence[i]);
    }

    str[length] = '\0';/*Добавляем в конец массива терминальный нуль*/

}

static uint32_t CountD(int16_t* sequence, uint32_t length, int16_t value)
{
	uint32_t result = 0;
	for (uint32_t i = 0; i < length; ++i)
	{
		if (sequence[i] == value)
		{
			++result;
		}
	}
	return result;
}

/*×èñëî âõîæäåíèé öåëî÷èñëåííîãî ýëåìåíòà â ìàññèâ*/
static uint32_t CountI(uint8_t* sequence, uint32_t length, int8_t value)
{
	uint32_t result = 0;
	for (uint32_t i = 0; i < length; ++i)
	{
		if (sequence[i] == value)
		{
			++result;
		}
	}
	printf("\n%i - %i times", value, result);
	return result;
}
static void OneRightShift(uint8_t* sequence, uint32_t length)
{

	for (uint32_t i = length - 1; i > 0; i--)
	{
		sequence[i] = sequence[i - 1];
	}
}

/*Ñäâèã âïðàâî íà nshifts ýëåìåíòîâ*/
static void RightShifts(uint8_t* sequence, uint32_t length, uint32_t nshifts)
{
	if (nshifts > 0)
	{
		for (uint32_t l = 1; l <= nshifts; l++)
		{
			OneRightShift(sequence, length);
		}
	}
	else
	{
		MakePrimeSequence(sequence, length);
	}
}

static void calc_umax(void)
{
    uint8_t* BaseSequence = (uint8_t*)calloc(number, sizeof(uint8_t)); /*выделили память для динамического массива (=последовательность)*/
    uint8_t* Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
    uint8_t* Sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));
    uint8_t* Sequence3 = (uint8_t*)calloc(number, sizeof(uint8_t));
    uint8_t* Sequence4 = (uint8_t*)calloc(number, sizeof(uint8_t));
    int16_t* pacf = (int16_t*)calloc(number, sizeof(int16_t));/*массив значений ПАКФ*/

    int16_t Umax = 0;

        MakePrimeSequence(BaseSequence, number);//b(k)
        MakePrimeSequence(Sequence1, number);//S1
        MakePrimeSequence(Sequence2, number);//S2
        MakePrimeSequence(Sequence3, number);//S3
        MakePrimeSequence(Sequence4, number);//S3

        RightShifts(Sequence1, number, shift1); //S1>>shift1
        RightShifts(Sequence2, number, shift2); //S2>>shift2
        RightShifts(Sequence3, number, shift3); //S3>>shift3
        RightShifts(Sequence4, number, shift4); //S4>>shift4

        SeqPSeq(Sequence1, Sequence2, number); //S1+S2
        SeqPSeq(Sequence3, Sequence1, number); //S1+S2+S3
        SeqPSeq(Sequence4, Sequence3, number); //S1+S2+S3
        SeqPSeq(BaseSequence, Sequence4, number); //S1+S2+S3+S4+b(k)

        PACF((int8_t*)BaseSequence, number, pacf);/*Расчёт ПАКФ*/

        for (uint16_t k = 1; k < number; ++k) {

            if (pacf[k] > Umax) {

                Umax = pacf[k];
            }
        }
        //printf("...\n");
        if (Umax < 58)
            printf("Umax = %d, S1:%d,   S2:%d,  S3:%d,  S4:%d\n",   Umax,  shift1,   shift2,    shift3,  shift4);



        free(Sequence1);
        free(Sequence2);
        free(Sequence3);
        free(Sequence4);
        free(BaseSequence);
        free(pacf);
}




int main(void) {

    for (shift1 = 190; shift1 > 185; shift1--) {

       for (shift2 = 190; shift2 > 180; shift2--) {

          for (shift3 = 50; shift3 > 1; shift3--) {

             for (shift4 = 160; shift4 > 55; shift4--) {

                  /*Генерация В-последовательности -> Расчёт ПАКФ -> Выбор максимального выброса*/
                  calc_umax();
             }
          }
       }
    }

    return 0;
}




