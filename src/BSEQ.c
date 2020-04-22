#include "BSEQ.h"

/*#########################ПЕРВЫЕ 500 ПРОСТЫХ ЧИСЕЛ (20x25)#########################*/
const uint16_t PrimeTable[] =
{
	2, 3, 5, 7, 11,
	13, 17, 19, 23,
	29,
	31, 37, 41, 43, 47,
	53, 59, 61, 67, 71,
	73,
	79, 83, 89, 97, 101,
	103, 107, 109, 113, 127,
	131, 137, 139, 149, 151, 157, 163, 167, 173,
	179,
	181,
	191, 193, 197, 199, 211,
	223, 227, 229, 233, 239,
	241, 251, 257, 263,
	269,
	271, 277, 281,
	283, 293,
	307,
	311, 313, 317, 331, 337,
	347, 349, 353, 359,
	367,
	373, 379, 383, 389, 397,
	401, 409,
	419, 421, 431, 433,
	439, 443, 449, 457, 461,
	463, 467, 479, 487, 491,
	499, 503, 509, 521, 523,
	541,
	547, 557, 563, 569,
	571,
	577, 587, 593, 599, 601,
	607, 613, 617, 619, 631,
	641, 643, 647, 653,
	659,
	661,
	673, 677, 683, 691,
	701,
	709, 719, 727, 733, 739,
	743, 751, 757, 761, 769,
	773, 787, 797, 809,
	811,
	821,
	823, 827, 829, 839,
	853,
	857, 859, 863, 877, 881,
	883, 887, 907, 911,
	919,
	929, 937, 941,
	947, 953, 967,
	971, 977, 983, 991, 997, 1009,
	1013, 1019, 1021, 1031, 1033,
	1039, 1049, 1051, 1061, 1063,
	1069,
	1087, 1091, 1093, 1097, 1103,
	1109, 1117, 1123, 1129,
	1151,
	1153, 1163, 1171, 1181, 1187,
	1193, 1201, 1213, 1217,
	1223,
	1229,
	1231, 1237, 1249, 1259, 1277,
	1279, 1283, 1289, 1291, 1297,
	1301, 1303, 1307, 1319, 1321,
	1327, 1361, 1367, 1373,
	1381, 1399,
	1409, 1423, 1427, 1429, 1433,
	1439, 1447, 1451, 1453,
	1459,
	1471, 1481, 1483, 1487, 1489,
	1493, 1499, 1511,
	1523, 1531,
	1543,
	1549, 1553, 1559, 1567, 1571,
	1579, 1583, 1597, 1601, 1607,
	1609,
	1613, 1619, 1621, 1627, 1637,
	1657,
	1663, 1667, 1669, 1693,
	1697,
	1699, 1709, 1721, 1723, 1733,
	1741, 1747, 1753, 1759, 1777,
	1783, 1787, 1789, 1801, 1811,
	1823,
	1831, 1847, 1861, 1867, 1871,
	1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933,
	1949,
	1951, 1973, 1979, 1987,
	1993, 1997,
	1999, 2003, 2011, 2017, 2027,
	2029, 2039, 2053, 2063,
	2069,
	2081, 2083, 2087, 2089,
	2099,
	2111, 2113, 2129,
	2131, 2137, 2141,
	2143, 2153, 2161, 2179,
	2203,
	2207, 2213, 2221, 2237, 2239,
	2243, 2251, 2267, 2269, 2273, 2281,
	2287,
	2293, 2297, 2309, 2311, 2333,
	2339, 2341, 2347, 2351, 2357,
	2371, 2377, 2381, 2383, 2389,
	2393, 2399, 2411, 2417,
	2423,
	2437,
	2441, 2447, 2459, 2467, 2473,
	2477, 2503, 2521, 2531, 2539,
	2543, 2549, 2551, 2557,
	2579,
	2591, 2593, 2609, 2617,
	2621,
	2633,
	2647, 2657, 2659, 2663, 2671,
	2677, 2683, 2687, 2689, 2693,
	2699, 2707, 2711, 2713,
	2719,
	2729, 2731, 2741,
	2749, 2753,
	2767,
	2777, 2789, 2791, 2797, 2801,
	2803, 2819, 2833, 2837,
	2843,
	2851, 2857, 2861, 2879, 2887,
	2897, 2903,
	2909, 2917, 2927, 2939,
	2953, 2957, 2963, 2969, 2971,
	2999, 3001, 3011, 3019, 3023,
	3037, 3041, 3049, 3061, 3067,
	3079,
	3083, 3089, 3109, 3119,
	3121,
	3137, 3163, 3167, 3169, 3181,
	3187, 3191, 3203, 3209, 3217,
	3221, 3229, 3251, 3253,
	3257,
	3259,
	3271, 3299, 3301, 3307,
	3313,
	3319, 3323, 3329, 3331, 3343,
	3347, 3359, 3361, 3371,
	3373,
	3389, 3391, 3407, 3413,
	3433, 3449,
	3457, 3461, 3463, 3467, 3469,
	3491, 3499, 3511, 3517, 3527,
	3529, 3533, 3539, 3541, 3547,
	3557, 3559, 3571
};


/*#########################ТЕЛО ГЛАВНОЙ ПРОГРАММЫ#########################*/
int main(void)
{
	const uint16_t number = 991;  /*простое число = длина последовательности*/
	double* acf = (double*)calloc(number, sizeof(double));/*массив значений АКФ*/
	atexit(ExitMessage);/*вывод сообщения по завершении программы*/
	FILE* fp;
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

	

	ACF((int8_t*)BaseSequence, number, acf);
	qsort((void*)acf, (size_t)number, sizeof(double), DescendingSort); /*быстрая сортировка по убыванию*/
	/*DisplayCorrelation(acf, number, "ACF : ");*/
	CalcProperties(acf, number);
	if ((fp = fopen_s("acf.txt", "w")) == NULL)
	{
		printf("ERROR!\n");
	}
	else printf("SUCCESS\n");
	
	return NULL;
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
static uint32_t CountD(double* sequence, uint32_t length, double value)
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
static void CountI(uint8_t* sequence, uint32_t length, int8_t value)
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

static void DisplaySequence(uint8_t* sequence, uint32_t length, char* name)
{
	printf("\n%s", name);
	for (uint32_t i = 0; i < length; i++)
	{
		printf("%i", sequence[i]);
	}
}

static void DisplayCorrelation(double* CF, uint32_t length, char* name)
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
static void MakePrimeSequence(uint8_t* sequence, uint32_t number)
{
	uint8_t j = 1;
	for (uint32_t i = 0; i < number; i++)
	{
		sequence[i] = NumberIsPrime(j);
		j++;
	}
}

/*построение В-последовательности*/
static void MakeBSequence(uint32_t length, uint8_t* basesequence, uint8_t* sequence1, ...)
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
static void SeqPSeq(uint8_t* baseSequence, uint8_t* sequence, uint32_t length)
{
	for (uint32_t i = 0; i < length; i++)
	{
		baseSequence[i] ^= sequence[i];
	}
}

/*Расчёт автокорреляционной функции последовательности sequence длины length*/
static void ACF(int8_t* sequence, uint32_t length, double* CF)
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