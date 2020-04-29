#include "bgeneration.h"


/***************************ÔÓÍÊÖÈÈ, ÈÑÏÎËÜÇÓÅÌÛÅ ÄËß ÃÅÍÅÐÀÖÈÈ Â-ÏÎÑËÅÄÎÂÀÒÅËÜÍÎÑÒÅÉ****************************************/


/*Ðàñ÷¸ò ìàêñ/ìèí âûáðîñîâ è ÷àñòîòû èõ ïîÿâëåíèÿ*/


/*Îòîáðàæåíèå ìàññèâîâ ðàçëè÷íûõ òèïîâ â òåðìèíàëå*/
void DisplaySequence(uint8_t* sequence, uint32_t length, char* name)
{
	printf("\n%s", name);
	for (uint16_t i = 0; i < length; i++)
	{
		printf("%i", sequence[i]);
	}
}

void DisplayCorrelation(int16_t* CF, uint32_t length, char* name)
{
	printf("\n");
	printf("\n%s", name);
	for (uint16_t i = 0; i < length; i++)
	{
		printf("\n%d", CF[i]);
	}
	printf("\n");
}



/*Ñòðîèì äâîè÷íóþ ïîñëåäîâàòåëüíîñòü ïðîñòûõ ÷èñåë*/
void MakePrimeSequence(uint8_t* sequence, uint32_t number)
{
	uint8_t j = 1;
	for (uint32_t i = 0; i < number; i++)
	{
		sequence[i] = NumberIsPrime(j);
		j++;
	}
}

