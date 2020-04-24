#include "BSEQ.h"



/***************************�������, ������������ ��� ��������� �-�������������������****************************************/


/*������ ����/��� �������� � ������� �� ���������*/
void CalcProperties(double* ACF, uint32_t length)
{
	double min = 0;
	double max = 0;

	for (uint32_t k = 1; k < length; ++k)
	{
		if (ACF[k] > max)
		{
			max = ACF[k];
		}
	}
	printf("\n\nSidePeakMax =  %.3f, %i times.\n", max, CountD(ACF, length, max));


	for (uint32_t s = 1; s < length; ++s)
	{
		if (ACF[s] < min)
		{
			min = ACF[s];
		}
	}
	printf("\nSidePeakMin = %.3f, %i times.\n", min, CountD(ACF, length, min));

}

/*����� ��������� �������� value � ������ sequence*/
uint32_t CountD(double* sequence, uint32_t length, double value)
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

/*����� ��������� �������������� �������� � ������*/
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

/*���������� ��������� �� �����������*/
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

/*����� ������ �� 1 �������*/
static void OneRightShift(uint8_t* sequence, uint32_t length)
{

	for (uint32_t i = length - 1; i > 0; i--)
	{
		sequence[i] = sequence[i - 1];
	}
}

/*����� ������ �� nshifts ���������*/
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

/*����������� �������� ��������� ����� � ���������*/
void DisplaySequence(uint8_t* sequence, uint32_t length, char* name)
{
	printf("\n%s", name);
	for (uint32_t i = 0; i < length; i++)
	{
		printf("%i", sequence[i]);
	}
}

void DisplayCorrelation(double* CF, uint32_t length, char* name)
{
	printf("\n");
	printf("\n%s", name);
	for (uint32_t i = 0; i < length; i++)
	{
		printf("\n%.3f", CF[i]);
	}
}

/*���������� ������� �����*/
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

/*������ �������� ������������������ ������� �����*/
void MakePrimeSequence(uint8_t* sequence, uint32_t number)
{
	uint8_t j = 1;
	for (uint32_t i = 0; i < number; i++)
	{
		sequence[i] = NumberIsPrime(j);
		j++;
	}
}

/*����� �� ������ 2, ��������� � basesequence*/
void SeqPSeq(uint8_t* baseSequence, uint8_t* sequence, uint32_t length)
{
	for (uint32_t i = 0; i < length; i++)
	{
		baseSequence[i] ^= sequence[i];
	}
}

/*������ ������������������ ������� ������������������ sequence ����� length*/
void ACF(int8_t* sequence, uint32_t length, double* CF)
{

	int32_t* r = (int32_t*)calloc(length, sizeof(int32_t));
	int8_t* sequence1 = (int8_t*)calloc(length, sizeof(int8_t));
	uint32_t tau = 0, f = 0, g = 0;
	double sum = 0;
	CF[0] = 1;

	for (f = 0; f < length; f++)//������ ����� �� "-1"
	{
		if (sequence[f] == 0) sequence[f] = -1;
		else sequence[f] = 1;
	}
	memcpy(sequence1, sequence, length); /*�������� sequence � sequence1*/

	for (tau = 1; tau < length; tau++)
	{
		register int8_t c = sequence1[length - 1]; /*��������� ��������� ������� ������������������*/
		for (g = length; g > 0; g--)
		{
			sequence1[g] = sequence1[g - 1];
		}
		sequence1[0] = c; /*������ ������� ����� ����������*/
		for(f = 0 ; f < length ; f++)
		{
			r[f] = sequence1[f]*sequence[f];
			sum = sum + r[f];
		}
		CF[tau] = sum / (double)length;
		sum = 0;
	}
	free(sequence1);
	free(r);
}

/*�������������� ������� ����� � ������*/
void IntToString(char* str,uint8_t* sequence,uint32_t length)
{
    for (uint32_t i = 0; i < length; i++)
    {
     sprintf(&str[i], "%d",sequence[i]);
    }

    str[length] = '\0';/*�������� ������ ����� ������ � ��������� �������*/

}

