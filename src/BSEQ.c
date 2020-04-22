#include "BSEQ.h"


/*#########################ТЕЛО ГЛАВНОЙ ПРОГРАММЫ#########################*/
int BGEN(void)
{
	const uint16_t number = 991;  /*простое число = длина последовательности*/
	double* acf = (double*)calloc(number, sizeof(double));/*массив значений АКФ*/
	atexit(ExitMessage);/*вывод сообщения по завершении программы*/

#ifdef SHIFTNUMBER1
	uint8_t* BaseSequence;
	uint8_t* sequence1;

	BaseSequence = (uint8_t*)calloc(number, sizeof(uint8_t)); /*выделили память для динамического массива (=последовательность)*/
	sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
	MakePrimeSequence(BaseSequence, number);
	MakePrimeSequence(sequence1, number);
	MakeBSequence(number, BaseSequence, sequence1);
#endif /*SHIFTNUMBER1*/

#ifdef SHIFTNUMBER2
	uint8_t* BaseSequence;
	uint8_t* sequence1;
	uint8_t* sequence2;

	BaseSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
	sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
	sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));
	MakePrimeSequence(BaseSequence, number);
	MakePrimeSequence(sequence1, number);
	MakePrimeSequence(sequence2, number);
	MakeBSequence(number, BaseSequence, sequence1, sequence2);
#endif /*SHIFTNUMBER2*/

#ifdef SHIFTNUMBER3
	uint8_t* BaseSequence;
	uint8_t* sequence1;
	uint8_t* sequence2;
	uint8_t* sequence3;

	BaseSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
	sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
	sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));
	sequence3 = (uint8_t*)calloc(number, sizeof(uint8_t));
	MakePrimeSequence(BaseSequence, number);
	MakePrimeSequence(sequence1, number);
	MakePrimeSequence(sequence2, number);
	MakePrimeSequence(sequence3, number);
	MakeBSequence(number, BaseSequence, sequence1, sequence2, sequence3);
#endif /*SHIFTNUMBER3*/

#ifdef SHIFTNUMBER4
	uint8_t* BaseSequence;
	uint8_t* Sequence1;
	uint8_t* Sequence2;
	uint8_t* Sequence3;
	uint8_t* Sequence4;

	BaseSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
	Sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
	Sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));
	Sequence3 = (uint8_t*)calloc(number, sizeof(uint8_t));
	Sequence4 = (uint8_t*)calloc(number, sizeof(uint8_t));

	MakePrimeSequence(BaseSequence, number);
	MakePrimeSequence(Sequence1, number);
	MakePrimeSequence(Sequence2, number);
	MakePrimeSequence(Sequence3, number);
	MakePrimeSequence(Sequence4, number);
	MakeBSequence(number, BaseSequence, Sequence1, Sequence2, Sequence3, Sequence4);

#endif /*SHIFTNUMBER4*/

#ifdef SHIFTNUMBERS5
	uint8_t* BaseSequence;
	uint8_t* sequence1;
	uint8_t* sequence2;
	uint8_t* sequence3;
	uint8_t* sequence4;
	uint8_t* sequence5;

	BaseSequence = (uint8_t*)calloc(number, sizeof(uint8_t));
	sequence1 = (uint8_t*)calloc(number, sizeof(uint8_t));
	sequence2 = (uint8_t*)calloc(number, sizeof(uint8_t));
	sequence3 = (uint8_t*)calloc(number, sizeof(uint8_t));
	sequence4 = (uint8_t*)calloc(number, sizeof(uint8_t));
	sequence5 = (uint8_t*)calloc(number, sizeof(uint8_t));
	MakePrimeSequence(BaseSequence, number);
	MakePrimeSequence(sequence1, number);
	MakePrimeSequence(sequence2, number);
	MakePrimeSequence(sequence3, number);
	MakePrimeSequence(sequence4, number);
	MakePrimeSequence(sequence5, number);
	MakeBSequence(number, BaseSequence, sequence1, sequence2, sequence3, sequence4, sequence5);
#endif /*SHIFTNUMBER5*/


#if 0
	ACF((int8_t*)BaseSequence, number, acf);
	qsort((void*)acf, (size_t)number, sizeof(double), DescendingSort); /*быстрая сортировка по убыванию*/
	/*DisplayCorrelation(acf, number, "ACF : ");*/
	CalcProperties(acf, number);
#endif

	return 0;
}
/*#################################################################################*/


/*#################################ФУНКЦИИ#########################################*/

/*расчёт макс/мин выбросов и частоты их появления*/
static void CalcProperties(double* ACF, uint32_t length)
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
	printf("\n\nSidePeakMax =  %.3f, %i times.", max, CountD(ACF, length, max));


	for (uint32_t s = 1; s < length; ++s)
	{
		if (ACF[s] < min)
		{
			min = ACF[s];
		}
	}
	printf("\nSidePeakMin = %.3f, %i times.", min, CountD(ACF, length, min));

}

/*число вхождений элемента value в массив sequence*/
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

/*число вхождений целочисленного элемента в массив*/
void CountI(uint8_t* sequence, uint32_t length, int8_t value)
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
}

/*сортировка элементов по возрастанию*/
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

/*сообщение по окончании выполнения программы*/
static void ExitMessage(void)
{
	puts("\n\n###################################");
	puts("Calculations are over.");
	puts("Soft created by Akimov Dmitry, 2020.");
	puts("###################################\n");
}

static void OneRightShift(uint8_t* sequence, uint32_t length)
{

	for (uint32_t i = length - 1; i > 0; i--)
	{
		sequence[i] = sequence[i - 1];
	}
}

/*сдвиг вправо на nshifts элементов*/
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

/*Строим двоичную последовательность простых чисел*/
void MakePrimeSequence(uint8_t* sequence, uint32_t number)
{
	uint8_t j = 1;
	for (uint32_t i = 0; i < number; i++)
	{
		sequence[i] = NumberIsPrime(j);
		j++;
	}
}

/*построение В-последовательности*/
void MakeBSequence(uint32_t length, uint8_t* basesequence, uint8_t* sequence1, ...)
{
	va_list argptr;
	va_start(argptr, sequence1); //argptr - ссылка на значение первого необязательного параметра (после sequence1)


#ifdef SHIFTNUMBER1
	DisplaySequence(sequence1, length, "S1:    ");
	RightShifts(sequence1, length, 11);
	DisplaySequence(sequence1, length, "S1->11: ");

	SeqPSeq(basesequence, sequence1, length);
	printf("\n");
	DisplaySequence(basesequence, length, "B-Sequence :");
	CountI(BaseSequence, number, 1);
	CountI(BaseSequence, number, 0);
	free(sequence1); //освобождаем выделенную память
#endif // SHIFTNUMBER1

#ifdef SHIFTNUMBER2
	uint8_t* sequence2 = va_arg(argptr, uint8_t*); //получаем значение первого необязательного параметра

	DisplaySequence(sequence2, length, "S2   : ");
	DisplaySequence(sequence1, length, "S1   : ");
	DisplaySequence(basesequence, length, "b(k) : ");
	printf("\n");

	RightShifts(sequence1, length, 37);
	RightShifts(sequence2, length, 113);

	DisplaySequence(sequence1, length, "S1->37: ");
	DisplaySequence(sequence2, length, "S2->113: ");
	printf("\n");

	SeqPSeq(sequence1, sequence2, length);
	DisplaySequence(sequence1, length, "S1+S2: ");
	SeqPSeq(basesequence, sequence1, length);
	printf("\n");
	DisplaySequence(basesequence, length, "B-Sequence : ");
	CountI(basesequence, length, 1);
	CountI(basesequence, length, 0);
	free(sequence1);
	free(sequence2);
#endif // SHIFTNUMBER2

#ifdef SHIFTNUMBER3
	uint8_t* sequence2 = va_arg(argptr, uint8_t*); //получаем значение первого необязательного параметра
	uint8_t* sequence3 = va_arg(argptr, uint8_t*); //получаем значение второго необязательного параметра

	// DisplaySequence(sequence3,length,"S3   : ");
	// DisplaySequence(sequence2,length,"S2   : ");
	// DisplaySequence(sequence1,length,"S1   : ");
	// DisplaySequence(basesequence,length,"b(k) : ");
	// printf("\n");

	 RightShifts(sequence1, length, 11);
	RightShifts(sequence2, length, 55);
	RightShifts(sequence3, length, 222);

	//DisplaySequence(sequence1,length,"S1->11: ");
   // DisplaySequence(sequence2,length,"S2->50: ");
   // DisplaySequence(sequence3,length,"S3->222: ");
    printf("\n");

	SeqPSeq(sequence1, sequence2, length);
	// DisplaySequence(sequence1,length,"S1+S2: ");
	 SeqPSeq(sequence3, sequence1, length);
	// DisplaySequence(sequence3,length,"S1+S2+S3 : ");
	// DisplaySequence(basesequence,length,"b(k)     : ");
	 SeqPSeq(basesequence, sequence3, length);
	printf("\n");
	DisplaySequence(basesequence, length, "B-Sequence : ");
	CountI(basesequence, length, 1);
	CountI(basesequence, length, 0);
	free(sequence1);
	free(sequence2);
	free(sequence3);
#endif // SHIFTNUMBER3

#ifdef SHIFTNUMBER4
	uint8_t* sequence2 = va_arg(argptr, uint8_t*);
	uint8_t* sequence3 = va_arg(argptr, uint8_t*);
	uint8_t* sequence4 = va_arg(argptr, uint8_t*);
	va_end(argptr);

	RightShifts(sequence1, length, 15); //S1->15
	RightShifts(sequence2, length, 266); //S2->266
	RightShifts(sequence3, length, 299); //S3->299
	RightShifts(sequence4, length, 650); //S4->650

	SeqPSeq(sequence1, sequence2, length); //S1+S2
	SeqPSeq(sequence3, sequence1, length); //S1+S2+S3
	SeqPSeq(sequence4, sequence3, length); //S1+S2+S3+S4
	SeqPSeq(basesequence, sequence4, length); //S1+S2+S3+S4+b(k)
	printf("\n");
	printf("Length: %i \n", length);
	printf("Shifters: 4\n");
	DisplaySequence(basesequence, length, "B-Sequence :\n");
	printf("\n");
	CountI(basesequence, length, 1);
	CountI(basesequence, length, 0);

	free(sequence1);
	free(sequence2);
	free(sequence3);
	free(sequence4);
#endif // SHIFTNUMBER4

#ifdef SHIFTNUMBER5
	uint8_t* sequence2 = va_arg(argptr, uint8_t*);
	uint8_t* sequence3 = va_arg(argptr, uint8_t*);
	uint8_t* sequence4 = va_arg(argptr, uint8_t*);
	uint8_t* sequence5 = va_arg(argptr, uint8_t*);

	DisplaySequence(sequence5, length, "S5   : ");
	DisplaySequence(sequence4, length, "S4   : ");
	DisplaySequence(sequence3, length, "S3   : ");
	DisplaySequence(sequence2, length, "S2   : ");
	DisplaySequence(sequence1, length, "S1   : ");
	DisplaySequence(basesequence, length, "b(k) : ");
	printf("\n");

	RightShifts(sequence1, length, 1);
	RightShifts(sequence2, length, 2);
	RightShifts(sequence3, length, 3);
	RightShifts(sequence4, length, 4);
	RightShifts(sequence5, length, 5);

	DisplaySequence(sequence1, length, "S1->1: ");
	DisplaySequence(sequence2, length, "S2->2: ");
	DisplaySequence(sequence3, length, "S3->3: ");
	DisplaySequence(sequence4, length, "S4->4: ");
	DisplaySequence(sequence5, length, "S5->5: ");
	printf("\n");

	SeqPSeq(sequence1, sequence2, length);
	DisplaySequence(sequence1, length, "S1+S2: ");
	SeqPSeq(sequence3, sequence1, length);
	DisplaySequence(sequence3, length, "S1+S2+S3 : ");
	SeqPSeq(sequence4, sequence3, length);
	DisplaySequence(sequence4, length, "S1+S2+S3+S4 : ");
	SeqPSeq(sequence5, sequence4, length);
	DisplaySequence(sequence5, length, "S1+S2+S3+S4+S5 : ");

	DisplaySequence(basesequence, length, "b(k)           : ");
	SeqPSeq(basesequence, sequence5, length);
	printf("\n");
	DisplaySequence(basesequence, length, "B-Sequence : ");
	CountI(basesequence, length, 1);
	CountI(basesequence, length, 0);
	free(sequence1);
	free(sequence2);
	free(sequence3);
	free(sequence4);
	free(sequence5);
#endif // SHIFTNUMBER5

}

/*сумма по модулю 2, результат в basesequence*/
void SeqPSeq(uint8_t* baseSequence, uint8_t* sequence, uint32_t length)
{
	for (uint32_t i = 0; i < length; i++)
	{
		baseSequence[i] ^= sequence[i];
	}
}

/*Расчёт автокорреляционной функции последовательности sequence длины length*/
void ACF(int8_t* sequence, uint32_t length, double* CF)
{

	int32_t* r = (int32_t*)calloc(length+1, sizeof(int32_t));
	int8_t* sequence1 = (int8_t*)calloc(length+1, sizeof(int8_t));
	uint32_t tau = 0, f = 0, g = 0;
	double sum = 0;
	CF[0] = 1;

	for (f = 0; f < length; f++)//замена нулей на "-1"
	{
		if (sequence[f] == 0) sequence[f] = -1;
		else sequence[f] = 1;
	}
	memcpy(sequence1, sequence, length); /*копируем sequence в sequence1*/

	for (tau = 1; tau <= length; tau++)
	{
		register int8_t c = sequence1[length - 1]; /*запомнили последний элемент последовательности*/
		for (g = length; g > 0; g--)
		{
			sequence1[g] = sequence1[g - 1];
		}
		sequence1[0] = c; /*первый элемент равен последнему*/
		for(f = 0 ; f < length ; f++)
		{
			r[f] = sequence1[f]*sequence[f];
			sum = sum + r[f];
		}
		CF[tau] = sum / (float)length;
		sum = 0;
	}
	free(sequence1);
	free(r);
}

/*#################################################################################*/
