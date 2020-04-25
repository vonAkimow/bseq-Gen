#include "BSEQ.h"



/***************************ÔÓÍÊÖÈÈ, ÈÑÏÎËÜÇÓÅÌÛÅ ÄËß ÃÅÍÅÐÀÖÈÈ Â-ÏÎÑËÅÄÎÂÀÒÅËÜÍÎÑÒÅÉ****************************************/


/*Ðàñ÷¸ò ìàêñ/ìèí âûáðîñîâ è ÷àñòîòû èõ ïîÿâëåíèÿ*/
void CalcProperties(int16_t* ACF, uint32_t length)
{
	int16_t min = 0;
	int16_t max = 0;

	for (uint16_t k = 1; k < length; ++k)
	{
		if (ACF[k] > max)
		{
			max = ACF[k];
		}
	}
	printf("\n\nSidePeakMax =  %d, %i times.\n", max, CountD(ACF, length, max));


	for (uint32_t s = 1; s < length; ++s)
	{
		if (ACF[s] < min)
		{
			min = ACF[s];
		}
	}
	printf("\nSidePeakMin = %d, %i times.\n", min, CountD(ACF, length, min));

}

/*×èñëî âõîæäåíèé ýëåìåíòà value â ìàññèâ sequence*/
uint32_t CountD(int16_t* sequence, uint32_t length, int16_t value)
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
uint32_t CountI(uint8_t* sequence, uint32_t length, int8_t value)
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

/*Ñîðòèðîâêà ýëåìåíòîâ ïî âîçðàñòàíèþ*/
int DescendingSort(const void* p1, const void* p2)
{
	const double* a1 = (const double*)p1;
	const double* a2 = (const double*)p2;

	if (*a2 < *a1)
		return -1;
	else if (*a1 == *a2)
		return 0;
	else
		return 1;
}

/*Ñäâèã âïðàâî íà 1 ýëåìåíò*/
static void OneRightShift(uint8_t* sequence, uint32_t length)
{

	for (uint32_t i = length - 1; i > 0; i--)
	{
		sequence[i] = sequence[i - 1];
	}
}

/*Ñäâèã âïðàâî íà nshifts ýëåìåíòîâ*/
void RightShifts(uint8_t* sequence, uint32_t length, uint32_t nshifts)
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

/*Íàõîæäåíèå ïðîñòûõ ÷èñåë*/
static bool NumberIsPrime(uint32_t p)
{
	if (p < 2) return false;
	if (p == 2) return true;
	if (p % 2 == 0) return false;

	double limit = sqrt(p);

	for (uint32_t i = 3; i <= limit; i += 2)
	{
		if ((p % i) == 0) return false;
	}
	return true;
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

/*Ñóììà ïî ìîäóëþ 2, ðåçóëüòàò â basesequence*/
void SeqPSeq(uint8_t* baseSequence, uint8_t* sequence, uint32_t length)
{
	for (uint32_t i = 0; i < length; i++)
	{
		baseSequence[i] ^= sequence[i];
	}
}

/*Ðàñ÷¸ò àâòîêîððåëÿöèîííîé ôóíêöèè ïîñëåäîâàòåëüíîñòè sequence äëèíû length*/
void PACF(int8_t* sequence, uint32_t length, int16_t* CF)
{

	int16_t* r = (int16_t*)calloc(length, sizeof(int16_t));
	int8_t* sequence1 = (int8_t*)calloc(length, sizeof(int8_t));
	uint32_t tau = 0, f = 0, g = 0;
	int16_t sum = 0;
	CF[0] = 1;

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

/*РАСЧЁТ ПЕРИОДИЧЕСКОЙ АКФ*/
void AACF(int8_t* sequence, uint32_t length, int16_t* CF)
{

	int16_t* r = (int16_t*)calloc(length, sizeof(int16_t));
	int8_t* sequence1 = (int8_t*)calloc(length, sizeof(int8_t));
	uint16_t tau = 0, f = 0, g = 0;
	uint16_t sum = 0;
	CF[0] = length;

	for (f = 0; f < length; f++)/*Замена нулей на "-1"*/
	{
		if (sequence[f] == 0) sequence[f] = -1;
		else sequence[f] = 1;
	}
	memcpy(sequence1, sequence, length); /*Скопировали sequence в sequence1*/

    for (tau = 1; tau < length; tau++)
	{
		for (g = length - 1; g > 0; g--)
		{
			sequence1[g] = sequence1[g - 1];
		}

		for(f = tau ; f < length ; f++)
		{
			r[f] = sequence1[f]*sequence[f];
			sum += r[f];
		}
		CF[tau] = sum;
		sum = 0;
	}

	free(sequence1);
	free(r);
}

/*Ïðåîáðàçîâàíèå ìàññèâà ÷èñåë â ñòðîêó*/
void IntToString(char* str,uint8_t* sequence,uint32_t length)
{
    for (uint32_t i = 0; i < length; i++)
    {
     sprintf(&str[i], "%d",sequence[i]);
    }

    str[length] = '\0';/*Äîáàâèëè ñèìâîë êîíöà ñòðîêè â ïîñëåäíèé ýëåìåíò*/

}

