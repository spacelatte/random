// PERFORMANCE TESTING APPLICATION
// PERFORNANCE TESTING ON A SINGLE CPU & CORE...
// MOSTLY DEPENDS ON GIGAHERTZES OF CPU/CORE BUT LITTLE
// CHANGES WITH INSTRUCTION SETS IN TERMS OF X86 FAMILY PROCESSORS...
// AUTHOR: MERT AKENGIN
// VERSION 1.01
// LAST UPDATE: 5 DEC. 2013
// ALL RIGHTS RESERVED, FREE TO USE FOR NON-PROFIT ORGANIZATIONS...

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

//THOSE ARE NOT NEEDED ANYMORE...
//#include <stdint.h>
//#include <limits.h>
//#include <unistd.h>

//DEFINITIONS
#define MAXVAL (pow(10,4.5))
//-DEFINITIONS

//PROTOTYPES
int main(int argc, char *argv[]);
double getCurrTime();
void primecount(unsigned long int limit);
long setDefaults(int *sel);
unsigned int *getSel(int argc, char *argv[]);
//-PROTOTYPES

//GLOBAL DECLARATIONS
long int maxval = MAXVAL;
long int lts1=0,lts2=pow(10,4);
bool nthprime;
//-GLOBAL DECLARATIONS

int main(int argc, char *argv[])
{
	double start,finish,result,precise;
	setDefaults(getSel(argc,argv));
	printf(" -> Starting sequence with %ld ...\n",maxval);
	start = getCurrTime();
	primecount(maxval);
	finish = getCurrTime();
	result = (finish - start)/lts2;
	//printf("\nResult is: %6.3lf.\n",result);
	precise = abs(lts1 - result);
	printf("\nResult is: %6.3lf.\n",precise);
	return (int)(result/1);
}

double getCurrTime()
{
//	double ctime;
//	clock_t time;
//	time = clock();
//	ctime = (double)time;
	// EASIER WAY TO DO :)
	return (double)clock();
}

long setDefaults(int *sel)
{
	int cases=0,k=3;
	char *err = "Undefined value! Error occured!\nExiting...\n";
	lts2 = pow(10,4);
	switch(sel[1])
	{
		case 1:
			nthprime = false;
			break;
		case 2:
			nthprime = true;
			break;
		default:
			printf("%s",err);
			exit(1);
	}
	switch(sel[2])
	{
		case 1:
			cases = sel[2] + k;
			break;
		case 2:
			cases = sel[2] + k;
			break;
		case 3:
			cases = sel[2] + k;
			break;
		case 4:
			maxval = 1046872;
			break;
		case 5:
			maxval = sel[0];
			break;
		default:
			printf("%s",err);
			exit(1);
	}
	if(cases)
	{
		maxval = pow(10,cases);
		if(!nthprime)
		{
			lts1 = pow(10,cases-2);
			lts2 = pow(10,cases-1);
		}else{
			lts1 = pow(10,cases-1);
			lts2 = pow(10,cases-0);
		}
	}
	//free(err);
	return maxval;
}

unsigned int *getSel(int argc, char *argv[])
{
	char *sec1[] = {"normal","hardcore"};
	char *sec2[] = {"low","medium","high","ultra","custom"};
	char *des1[] = {"Running normally / Count numbers/integers to given value...",
					"Intensive running / Count to Nth prime number, N is given value..." };
	char *des2[] = {"Use small amount of numbers and time to test.",
					"Use medium amount of numbers and time to test.",
					"Use high amount of numbers and time to test. (May take long time...)",
					"Use highest number possible (array limit) to test. Use with caution!",
					"Instead of using pre-defined values, use custom integer limit to test your CPU." };
	char *warn[] = {"Normal means count until some positive integer and find primes in that interval,",
					"and Hardcore means count prime numbers until reaching limit...",
					"Note: non-custom modes are rated by higher is better but custom rated as lower is better!" };
	int gas = 32,secval[3]={0,0,0};
	char *getsec,*getdes;
	char *input = (char*)malloc(80*sizeof(char));
	getsec = (char*)malloc(gas*sizeof(char));
	getdes = (char*)malloc(gas*sizeof(char));
	long int custom,i;
	//1: normal / hardcore
	//2: low - med - high - ultra - custom
	//3: selection number
	if(argc > 1)
	{
		getsec = argv[1];
		getdes = argv[2];
		//if(argv[3])
			custom = atol(argv[3]);
	}
//	i=0;
	if(argc < 2)
	{
		for(i=0;i<2;i++)
			printf("   %ld) %s : %s\n",i+1,sec1[i],des1[i]);
		printf(" Enter selection name or number to continue: ");
		scanf("%s",getsec);
	}
//	i=0;
	for(i=0;i<2;i++)
		if(!strcmp(getsec,sec1[i]) || atoi(getsec) == i+1)
			secval[1] = i+1;
	//free(getsec);
																		
//	i=0;
	if(argc < 2)
	{
		for(i=0;i<5;i++)
			printf("   %ld) %s : %s\n",i+1,sec2[i],des2[i]);
		printf(" Enter selection name or number to continue: ");
		scanf("%s",getdes);
	}
	i=0;
	for(i=0;i<5;i++)
		if(!strcmp(getdes,sec2[i]) || atoi(getdes) == i+1)
			secval[2] = i+1;
	//free(getdes);
//	i=0;
	if(argc > 1 && secval[2] == 5) //CMDLINE ARG FIX
		secval[0] = custom;
	if(argc < 2 && secval[2] == 5)
	{
		printf(" Enter custom limit (as positive integer): ");
		scanf("%ld",&custom);
		if(custom < 0)
			custom *= -1;
		if(secval[1] == 2)
		{
			for(i=0;i<3;i++)
				printf("%s\n",warn[i]);
			printf("Do you agree and take all responsibility of damage? [Y/N]: ");
			scanf("%s",input);
			if( input[0] != 'Y' && input[0] != 'y')
				exit(0);
		}
		secval[0] = custom;
	}
	/*
	free(sec1);
	free(sec2);
	free(des1);
	free(des2);
	free(warn);
	*/
	return secval;
}

void primecount(unsigned long int limit)
{
	int a,b;
	bool isprime;
	float percent;
	unsigned long int i,x,y;
	unsigned long int prime=0,count=0;
	unsigned long int pa_size = limit + 1; //+1 for number 'two'
	unsigned long int pa[pa_size] ;
	for(i=0;i<pa_size;i++)
			pa[i] = 0;
	pa[0] = 2;
	for(i=3;(nthprime)?(i>0):(i<pa_size);i+=2)
	{
		for(x=0;pa[x]>0;x++)
		{
			isprime = false;
			if( (i%pa[x]) == 0 )
			{
				isprime = false;
				break;
			}else{
				isprime = true;
				prime = x+1;
			}
		}
		if(isprime)
		{
			pa[prime] = i;
			count += 1;
			if(nthprime)
			{
				a = i;
				b = count-1;
			}else{
				a = count+1;
				b = i;
			}
			percent = ((float)b / limit) * 100;
			printf("\r Current (in test): %lu #%lu/%lu (%03.1f%%) ",a,b,limit,percent);
		}
		if(count >= pa_size)
			break;
	}
	//free(pa);
}
