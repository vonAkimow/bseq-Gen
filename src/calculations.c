#include "calculations.h"
inline uint16_t MaxValue(int16_t value1, int16_t value2);
inline uint16_t MaxPeakLevel(int16_t val1,int16_t val2,uint32_t length);
inline double AveragePeakLevel(double ExpVal, uint32_t length);

/*Ñóììà ïî ìîäóëþ 2, ðåçóëüòàò â basesequence*/
void SeqPSeq(uint8_t* baseSequence, uint8_t* sequence, uint32_t length)
{
	for (uint32_t i = 0; i < length; i++)
	{
		baseSequence[i] ^= sequence[i];
	}
}

/*РАСЧЁТ ПЕРИОДИЧЕСКОЙ АКФ*/
void PACF(int8_t* sequence, uint32_t length, int16_t* CF)
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

/*РАСЧЁТ АПЕРИОДИЧЕСКОЙ АКФ*/
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

/*РАСЧЁТ ПЕРИОДИЧЕСКОЙ ВКФ*/
void PVCF(int8_t* sequence1, int8_t* sequence2, uint32_t length, int16_t* CF)
{

	int16_t* r = (int16_t*)calloc(length, sizeof(int16_t));
	int8_t* Sequence1 = (int8_t*)calloc(length, sizeof(int8_t));
	int8_t* Sequence2 = (int8_t*)calloc(length, sizeof(int8_t));
	uint16_t tau = 0, f = 0, g = 0;
	int16_t sum = 0;

	for (f = 0; f < length; f++)/*Замена нулей на "-1"*/
	{
		if (sequence1[f] == 0) sequence1[f] = -1;
		else sequence1[f] = 1;
	}
	for (f = 0; f < length; f++)/*Замена нулей на "-1"*/
	{
		if (sequence2[f] == 0) sequence2[f] = -1;
		else sequence2[f] = 1;
	}

	memcpy(Sequence1, sequence1, length);
	memcpy(Sequence2, sequence2, length);

	for(f = 0; f < length ; f++)
		{
			r[f] = Sequence1[f]*Sequence2[f];
			sum += r[f];
		}
    CF[0]=sum;
    sum = 0;

	for (tau = 1; tau < length; tau++)
	{
		register int8_t c = Sequence2[length - 1];
		for (g = length-1; g > 0; g--)
		{
			Sequence2[g] = Sequence2[g - 1];
		}
		Sequence2[0] = c;
		for(f = 0 ; f < length ; f++)
		{
			r[f] = Sequence1[f]*Sequence2[f];
			sum = sum + r[f];
		}
		CF[tau] = sum;
		sum = 0;
	}
	free(Sequence1);
	free(Sequence2);
	free(r);
}

/*РАСЧЁТ АПЕРИОДИЧЕСКОЙ ВКФ*/
void AVCF(int8_t* sequence1, int8_t* sequence2, uint32_t length, int16_t* CF)
{

	int16_t* r = (int16_t*)calloc(length, sizeof(int16_t));
	int8_t* Sequence1 = (int8_t*)calloc(length, sizeof(int8_t));
	int8_t* Sequence2 = (int8_t*)calloc(length, sizeof(int8_t));
	uint16_t tau = 0, f = 0, g = 0;
	int16_t sum = 0;

	for (f = 0; f < length; f++)/*Замена нулей на "-1"*/
	{
		if (sequence1[f] == 0) sequence1[f] = -1;
		else sequence1[f] = 1;
	}
	for (f = 0; f < length; f++)/*Замена нулей на "-1"*/
	{
		if (sequence2[f] == 0) sequence2[f] = -1;
		else sequence2[f] = 1;
	}

	memcpy(Sequence1, sequence1, length);
	memcpy(Sequence2, sequence2, length);

	for(f = 0; f < length ; f++)
		{
			r[f] = Sequence1[f]*Sequence2[f];
			sum += r[f];
		}
    CF[0]=sum;
    sum = 0;


	for (tau = 1; tau < length; tau++)
	{
		for (g = length-1; g > 0; g--)
		{
			Sequence2[g] = Sequence2[g - 1];
		}
		for(f = tau; f < length ; f++)
		{
			r[f] = Sequence1[f]*Sequence2[f];
			sum += r[f];
		}
		CF[tau] = sum;
		sum = 0;
	}
	free(Sequence1);
	free(Sequence2);
	free(r);
}
/*Ïðåîáðàçîâàíèå ìàññèâà ÷èñåë â ñòðîêó*/
void IntToString(char* str,uint8_t* sequence,uint32_t length)
{
    for (uint32_t i = 0; i < length; i++)
    {
     sprintf(&str[i], "%d",sequence[i]);
    }

    str[length] = '\0';/*Добавляем в конец массива терминальный нуль*/

}

inline uint16_t MaxValue(int16_t value1, int16_t value2)
{
    if (abs(value1) > abs(value2))
    {
        return abs(value1);
    }
    else return abs(value2);
}
inline double AveragePeakLevel(double ExpVal, uint32_t length)
{
    double h = 0;

    h = 100*ExpVal/length;

    return h;

}
inline uint16_t MaxPeakLevel(int16_t val1,int16_t val2,uint32_t length)
{
    uint16_t h = 0;
    uint16_t Max = MaxValue(val1,val2);

    h = 100*Max/length;

    return h;

}
/*Íàõîæäåíèå ïðîñòûõ ÷èñåë*/
bool NumberIsPrime(uint32_t p)
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
void CalcProperties(int16_t* CF, uint32_t length)
{
	int16_t Umin = 0, Umax = 0, nUmin = 0, nUmax = 0;



	for (uint16_t k = 1; k < length; ++k)
	{
		if (CF[k] > Umax)
		{
			Umax = CF[k];
		}
	}
	nUmax = CountD(CF, length, Umax);
	printf("\n\nSidePeakMax =  %d, %i times.\n", Umax, nUmax);


	for (uint16_t s  = 1; s < length; ++s)
	{
		if (CF[s] < Umin)
		{
			Umin = CF[s];
		}
	}
	nUmin = CountD(CF, length, Umin);
	printf("\nSidePeakMin = %d, %i times.\n", Umin, nUmin);
	printf("\nMax value is: %d\n",MaxValue(Umin,Umax));

    double        Mu = ExpVal(CF,length,false);
    double     absMu = ExpVal(CF,length,true);
    printf("\nMu = %.3f\n", Mu);
    printf("\nabsMu = %.3f\n", absMu);
    double  absSigma = SigmaVal(CF,length,absMu);
    double     Sigma = SigmaVal(CF,length,Mu);
    printf("\nabsSigma = %.3f\n", absSigma);
    printf("\n Sigma = %.3f\n", Sigma);

    printf("\nMaxPeakPercentage: %d\n",MaxPeakLevel(Umin,Umax,length));
	printf("\nAveragePeakPercentage: %.2f\n",AveragePeakLevel(absMu,length));

}
double ExpVal(int16_t* CF, uint32_t length,bool absUsage)
{
    double sum = 0, Mu =0;

    if (absUsage == false)
    {
        for (uint16_t k = 1; k < length; k++)
        {
            sum += CF[k];
        }
    }
    else if (absUsage == true)
    {
        for (uint16_t k = 1; k < length; k++)
        {
            sum += abs(CF[k]);
        }
    }
    else return 1;/*Ошибка*/

	Mu = sum / (float)(length-1);

    return Mu;

}

double SigmaVal(int16_t* CF, uint32_t length,double ExpVal)
{
    double sum = 0, Sigma = 0;

    for (uint16_t k = 1; k < length; k++)
    {
        sum += pow(CF[k] - ExpVal, 2) ;
    }

    Sigma = sqrt(sum/(float)(length-1));

    return Sigma;

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
void OneRightShift(uint8_t* sequence, uint32_t length)
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
