// AUTHOR: MERT AKENGIN
// THINGS WE DO IN JAVA CLASS, WRITTEN IN C...
// HAVE-FUN!

#define CNAME "phoenix"
#define VER 1
#define SUBVER 0
#define BUILD 11
#define AUTHOR "MERT AKENGIN"
#define B_DATE "8 NOV 13"
#define B_TIME "11:00"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
//#include <gmp.h>
//#include <gmpxx.h>
//#include <linux/threads.h>
//#include <omp.h>

static unsigned long int excode=0,lastp;
int i,j,x,y,z;
bool isquiet;
char* input;
char *func[] = {"list","myname","temperature","random","leapyear",
				"trirect","primecheck","decimals","primenums","fibonacci",
				"primecount","stars","primeinterval","pie","primelate",
				"revofmatrix","nextprime","closestmultip","remain",
				"exit/quit"};

void main(int argc, char *argv[]); //prototype
int retval()
{
	return excode;
}

void myname(int argc, char *argv[])
{
	input = (char*)malloc(256);
	if(argc > 1)
		for(i=2;i<argc+1;i++)
		{
			strcat(input,argv[i]);
			strcat(input," ");
		}
	else{
		printf("Please enter your full name: ");
		scanf("% s",input);
		scanf("%[0-9a-zA-Z ]s",input);
	}
	//to get white spaces...
	printf("I have just learned that your name is %s.\n",input);
	excode = strlen(input);
}

void temperature(int argc, char *argv[])
{
	int input;
	if(argc > 1)
		input = atoi(argv[2]);
	else{
		printf("Value to convert: ");
		scanf("%d",&input);
	}
	printf("%d celcius is %d fahrenheit.\n",(int)input,((int)input)*9/5+32);
	printf("%d fahrenheit is %d celcius.\n",(int)input,((int)input-32)*5/9);
	excode = ((input*9/5)+32)-((input-32)*5/9);
}

void randomcheck(int argc, char *argv[])
{
	int r;
	srand(time(NULL));
	int num[5], gen[3];
	for(j=0;j<3;j++) {
		r = rand();
		gen[j] = (int)r%50+1;
		if(gen[j] == 50) gen[j]=49;
	}
	printf("Enter 5 numbers, each in new line.\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&input);
		if((int)input < 50) num[i] = (int)input;
		else{
			printf("Enter number less than 50: ");
			scanf("%d",&input);
			num[i] = (int)(((int)input%50)+0);
		}
	}
	static int matched,missed = 0;
	for(i=0;i<5;i++)
	for(j=0;j<3;j++)
	{
		if(gen[j] == num[i]) {
		printf("Generated %2d (index %d) matched with user's %2d (index %d).\n",gen[j],j,num[i],i);
		++matched; }else{
		printf("Generated %2d (index %d) not matched with user's %2d (index %d).\n",gen[j],j,num[i],i);
		--missed; }
	}
	double result = (double)( (double)(matched)/(matched-missed)*100.0 );
	printf("Your ratio is: %3.2f%%\n",result);
	excode = (int)(result*100);
}

void leapyear(int argc, char *argv[])
{
	long int input;
	bool leap;
	char *result;
	if(argc > 1)
		input = atol(argv[2]);
	else{
		printf("Enter year to check leap: ");
		scanf("%ld",&input);
	}
	if((input%4 == 0 && input%100 != 0) || input%400 == 0) leap=true; else leap=false;
	if(leap) result="is a leap"; else result="is not a leap";
	printf("Year %ld %s year.\n",input,result);
	if(leap) excode = 1; else excode = 0;
	//excode = (leap)?(1):(0);
}

void trirect(int argc, char *argv[])
{
	char input[5];
	bool type;
	float wi,he;
	if(argc > 1)
	{
		if( argc < 3 || !argv[3] || !argv[4] || !argv[2] )
		{
			printf("Syntax error. Correct sytnax is: %s %s [type] [height] [width]\n",argv[0],argv[1]);
			exit(1);
		}
		strncpy(input,argv[2],4);
		he = atof(argv[3]);
		wi = atof(argv[4]);
	}else{
		printf("Please enter type of area (rect/tri): ");
		scanf("%s",input);
	}
	if(strncmp("tri",input,3) == 0) type=false;
	else if(strncmp("rect",input,4) == 0) type=true;
	else { trirect(argc,argv); exit(0); }
	if(argc < 2)
	{
		printf("Please enter [H]eight: ");
		scanf("%f",&he);
		printf("Please enter floor [W]idth: ");
		scanf("%f",&wi);
	}
	double result = (wi * he);
	if(!type) result /= 2;
	printf("The result is: %.3lf\n",result);
	excode = (int)result;
}

void primecheck(int argc, char *argv[])
{
	long int input;
	bool isprime;
	isprime=true;
	isquiet = false;
	char* result;
	if(argc > 1)
	{
		input = atol(argv[2]);
		isquiet = true;
	}else{
		printf("Please enter a number to check if is prime: ");
		scanf("%d",&input);
	}
	unsigned long int x = (unsigned long int)input;

	for(i=3;i<input;i+=2)
		if( (x%i) == 0 )
			isprime=false;
	if( x < 3 || x%2 == 0 )
		isprime=false;

	if(isprime)
		result = "a";
	else
		result = "NOT a";
	if(!isquiet)
		printf("%ld is %s prime number.\n",input,result);
	if(isprime) excode = 1; else excode = 0;
	//excode = (isprime)?(1):(0);
}

void decimals(int argc, char *argv[])
{
	char input[256];
	long int i,x,y;
	if(argc > 1)
		strcpy(input,argv[2]);
	else{
		printf("Please enter an integer: ");
		scanf("%s",input);
	}
	i = atol(input);
	x = strlen(input);
	if(i < 0)
		x--; //for negative numbers, \
			string length becomes 1 more \
			because of negative sign... fix for it.
	for(y=0;y<x;y++)
		printf("%ld ",(long int)( i/pow(10,y) )%10);
	printf("\n");
	excode = y;
}

void primenums(int argc, char *argv[])
{
	unsigned long int input,prime;
	bool isprime;
	bool isquiet = false;
	if(argc > 1)
		input = atol(argv[2]);
	else{
		printf("Enter the maximum limit (as integer): ");
		scanf("%lu",&input);
	}
	if( argc > 1 && argv[3] && strcmp(argv[3],"quiet") == 0 )
		isquiet = true;
	unsigned long int pa_size = 524288+262144+131072+65536+32768+16384+8192+4096+2048+256+64+16+8+2-1;
	unsigned long int pa[pa_size];
	//long int pa_size = sizeof(pa)/4;
	// this is from old trial and error method. ignore it...
	unsigned long int i,x,y;
	for(i=0;i<pa_size;i++)
		/*if(strcmp("","cont") == 0)
			if(!pa[i])
				pa[i] = 4294967295;
		else*/
			pa[i] = 0;
	pa[0] = 2;
	unsigned long int count = 0;
	if( !isquiet )
		printf("% 5u ",2);
	for(i=3;i<input;i+=2)
	{
		for(x=0;pa[x]>0;x++)
		{
			isprime = false;
			if( (i%((unsigned long int)sqrt(pa[x])+1)) == 0 ) //used nice thing for testing...
			{
				isprime = false;
				//prime = 0;
				break;
			}else{
				isprime = true;
				prime = x+1;
			}
		}
		if(isprime)
		{
			if(prime%10 == 0 && !isquiet)
				printf(" (#% 5lu) \n",count+1,i);
			if( !isquiet )
				printf("% 5lu ",i);
			pa[prime] = i;
			count += 1;
			lastp = i;
		}
		if(count == pa_size)
			break;
	}
	if( !isquiet )
	//printf("\n");
	printf("\n%lu prime number(s) have been listed...\n",count+1);
	if( input > 1 )
		excode = count+1;
	else
		excode = count;
}

void fibonacci(int argc, char *argv[])
{
	unsigned int input;
	unsigned long long int i,x,y,z;
	if(argc > 1)
		input = atoi(argv[2]);
	else{
		printf("Enter maximum limit of numbers to shown: ");
		scanf("%u",&input);
	}
	unsigned long int fa[2];
	fa[0] = 1;
	fa[1] = 1;
	printf("% 3d\n% 3d\n",1,1);
	for(i=0;i<input-2;i++)
	{
		z = (fa[0]+fa[1]);
		printf("% 5llu \n",z);
		//at above code, should i use %llu or just %u? because i defined unsigned long long int.
		//more numbers, more power...

		if( (i%2) == 0)
			fa[0] = z;
		else
			fa[1] = z;

		if( (i%10) == 0 && i != 0)
			printf("\n");
	}
	printf("\n");
	excode = z;
}

void primecount(int argc, char *argv[])
{
	unsigned long int result,omax,omin;
	char *imax = (char*)malloc(256);
	char *imin = (char*)malloc(256);
	//= (char*)malloc(256);
	//char **alteredargs;
	if(argc > 1)
	{
		imax = (argv[2]);
		imin = (argv[3]);
	}else{
		printf("Enter max. limit: ");
		scanf("%s",imax);
		printf("Enter min. limit: ");
		scanf("%s",imin);
	}
	char *alteredargs[] = {argv[0],argv[1],"","quiet"};
	alteredargs[2] = imax;
	primenums(argc+1,alteredargs);
	omax = excode;
			//sep
	alteredargs[2] = imin;
	primenums(argc+1,alteredargs);
	omin = excode;
	result = (omax-omin);
	printf("%lu \n",result);
	excode = result;
}

void stars(int argc, char *argv[])
{
	unsigned int input,i,x;
	if(argc > 1)
		input = (unsigned int)atoi(argv[2]);
	else
	{
		printf("Enter maximum number of stars: ");
		scanf("%u",&input);
	}
	for(i=0;i<input;i++)
	{
		for(x=i;x>0;x--)
			printf("*");
		printf("\n");
	}
	for(i=input;i>0;i--)
	{
		for(x=0;x<i;x++)
			printf("*");
		printf("\n");
	}
	//and the reverse one...
	unsigned int space,star,limit;
	limit = input;
	for(i=input+1;i>0;i--)
	{
		for(space=i-1;space>0;space--)
			printf(" ");
		for(star=0;star<input-i+1;star++)
			printf("*");
		printf("\n");
	}
	for(i=0;i<input;i++)
	{
		for(space=0;space<=i;space++)
			printf(" ");
		for(star=input-i-1;star>0;star--)
			printf("*");
		printf("\n");
	}
}

void primeinterval(int argc, char *argv[])
{
	char *min = (char*)malloc(256);
	char *max = (char*)malloc(256);
	//char *pas = (char*)malloc(256);
	long int i,count;
	if(argc > 1)
	{
		min = (argv[2]);
		max = (argv[3]);
	}else{
		printf("Enter start point: ");
		scanf("%s",min);
		printf("Enter end point: ");
		scanf("%s",max);
	}
	count = 0;
	char *alteredargs[] = {argv[0],argv[1],""};
	for(i=atol(min);i<atol(max);i++)
	{
		alteredargs[2] = (char*)malloc(128);
		sprintf(alteredargs[2],"%ld",i);
		primecheck(argc+1,alteredargs);
		if(excode == 1)
		{
			printf("% 5ld ",i);
			count += 1;
			if( count%10 == 0 && count != 0 )
				printf("\n");
		}
	}

	printf("\n%ld prime numbers found...\n",count);
	excode = count;
}

void pie(int argc, char *argv[])
{
	// HAS PROBLEM IN 1/10^16
	long long int input;
	unsigned long long int i,j,x,y,z;
	long double pi;
	long long int multip;
	if(argc > 1)
		input = atoll(argv[2]);
	else{
		printf("Enter max. digit count: ");
		scanf("%lld",&input);
	}
	multip = pow(10,input);
	i=input+2;
		pi=( 2*(i+1)-1 );
		pi=( (2*i-1)+(i*i)/pi );
		pi=( (2*(i-1)-1)+(i-1)*(i-1)/pi );
	for(i=input;i>0;i--)
		pi=( ((2*i)-1)+((i*i)/pi) );
	printf("3,%lld \n",(long long int)(4*multip/pi)-3*multip);
	i=1; pi=( (i*i)/7 );
	while(i<input)
	{
		i+=2;
		pi=( (pi*100)/(6+(i*i)) );
	}
	printf("%llf \n",pi);
}

void primelate(int argc, char *argv[])
{
	unsigned long int input;
	//long int input;
	if(argc > 1)
		input = (unsigned long int)atol(argv[2]);
	else{
		printf("Please enter number (should be prime to get another prime): ");
		scanf("%lu",&input);
	}
	char *alteredargs[]={argv[0],argv[1],""};
	alteredargs[2] = (char*)malloc(128);
	sprintf(alteredargs[2],"%lu",input);
	primecheck(argc+1,alteredargs);
	(excode == 0) ? (input = lastp) : ( (input < 3) ? (input = 3) : (input) ) ;
	printf("%lu is equalivent of %lu. \n",(~input)+1,input);
}

void revofmatrix(int argc, char *argv[])
{
	//decided to out to console, if user wanted a file, he/she can redirect output easily...
	long int columns, lines;
	int i,j,x,y;
	//i = j = x = y = 0;
	char *infile_n = (char*)malloc(pow(2,8)*sizeof(char)); //, *outfile_n;
	FILE *infile; //, *outfile;
	if(argc > 1)
	{
		infile_n = (argv[2]);
		//outfile_n = (argv[3]);
		lines = atol(argv[3]);
		columns = atol(argv[4]);
	}else{
		printf("Enter input file (read matrix): ");
		scanf("%s",infile_n);
		printf("Enter line and column count (seperate by space): ");
		scanf("%ld",&lines);
		scanf("%ld",&columns);
		//printf("Enter output file (write matrix): ");
		//scanf("%s",outfile_n);
	}
	infile = fopen(infile_n,"r");
	//outfile = fopen(outfile_n,"w");
	if(infile == NULL) // || outfile != NULL)
	{
		//(infile == NULL)?(
		printf("Input file is empty, should be 1x1 atleast...\n");
		//):(NULL);
		//(outfile != NULL)?(printf("Output file is NOT empty, should be...\n"));
		excode = 1;
		//fclose(infile);
		main(argc,argv);
		exit(excode);
	}//else{
		double data[lines][columns];
		for(i=0;i<lines;i++)
			for(j=0;j<columns;j++)
				fscanf(infile,"%lf",&data[i][j]);
		double newdata[lines][columns];
		int a=0,b=0,c=0,m=0;
		for(i=0;i<lines;i++)
			for(j=0;j<columns;j++)
			{
				x = lines - i - 1;
				y = columns - j - 1;
				newdata[i][j] = data[x][y];
				a = newdata[i][j];
				b=0;
				if(a<0)
				{
					a*=-1;
					m=1;
				}
				while(a>0)
				{
					a = (int)(a/10);
					b++;
				}
				if(b>=c)
					c = b + m;
			}
		for(i=0;i<lines;i++)
		{
			for(j=0;j<columns;j++)
			{
				a = newdata[i][j];
				b = 0;
				m=c;
				if(a<0)
				{
					m=c-1;
					a*=-1;
				}
				while(a>0)
				{
					a = a/10;
					b++;
				}
				while(b<m)
				{
					printf(" ");
					b++;
				}
				printf("%.3lf ",newdata[i][j]);
			}
			printf("\n");
		}
		fclose(infile);
		excode = 0;
	//}
}

/*
for(i=0;giris[i] != NULL; i++)
	boyut1 = i;
	for(j=0;giris[i][j] != NULL; j++)
		boyut2[j] = j;
	for(x=0;boyut2[x] != NULL; x++)
		for(y=x;y>=0;y--)
			if(boyut2[x] != boyut[y])
				return -1;
*/

void nextprime(int argc, char *argv[])
{
	unsigned long int input,val,i;
	if(argc > 1)
		input = atol(argv[2]);
	else{
		printf("Enter number to find next prime: ");
		scanf("%ld",&input);
	}
	//char *alteredargs[]={argv[0],argv[1],""};
	//alteredargs[2] = (char*)malloc(128);
	bool excluded;
	val = input;
	while(true)
	{
		if(input < 3)
		{
			input=2;
			break;
		}
		excluded = false;
		if(input%2 == 0)
			input++;
		for(i=3;i<input;i+=2)
			if(input%i == 0)
			{
				excluded = true;
				break;
			}
		if(!excluded)
			break;
		else
			input+=2;
	}
	excode = ( input - val );
	printf("%lu is next prime number. (after %lu)\n",input,excode);
}

void closestmultip(int argc, char *argv[])
{
	long int input,num,result;
	if(argc > 1)
	{
		input = atol(argv[2]);
		num = atol(argv[3]);
	}else{
		printf("Enter number to find multiplier: ");
		scanf("%ld",&input);
		printf("Enter multiplied value to find multiplier: ");
		scanf("%ld",&num);
	}
	if(num < input)
	{
		printf("Warning! Multiplied value less than multiplier!\n");
	}else{
		//do the math
		result = (num-(num%input))/input;
		if( argc < 2)
			printf("%ld is closest (floor) multiplier. (to get %ld)\n",result,(input*result));
		excode = result;
	}
}

void remain(int argc, char *argv[])
{
	long int num,div,i;
	if(argc > 1)
	{
		num = atol(argv[2]);
		div = atol(argv[3]);
	}else{
		printf("Enter a number to divide: ");
		scanf("%ld",&num);
		printf("Enter diviser to find remainder: ");
		scanf("%ld",&div);
	}
	double res;
	excode = num;
	for(i=0;i<num;i++)
	{
		res = ( (double)(num-i) / div );
		if( res == (int)res )
		{
			excode = i;
			break;
		}
	}
	if(argc < 2)
		printf("%ld is remainder from %ld/%ld.\n",excode,num,div);
}

int getfunc(int argc, char *argv[])
{
	char input[80];
	//printf("%s %s %s",argv[0],argv[1],argv[2]);
	if(argc > 1)
		strcpy(input,argv[1]);
	else{
		printf("Enter func. name or number (enter 0 or 'list' to see all): ");
		scanf("%s",input);
	}
	if( strcmp(input,"exit") == 0 || strcmp(input,"quit") == 0 || strcmp(input,"EOF") == 0 || atoi(input) == 100-2 )
		exit(0);
	for(i=0;func[i] != NULL;i++)
	{
		if( strcmp(input,func[i]) == 0  )
			return i;
	}
	if( strcmp(input,"debug") == 0 )
		return 99;
	i = atoi(input);
	if(i >= 0 && i < 100)
		return i;
	return -1;
}

void debugging(int argc, char *argv[])
{
	char *input = (char*)malloc(256);
	printf("\r| %d.%d-%02d \"%s\" -> ",VER,SUBVER,BUILD,CNAME);
	scanf("%s",input);
	//printf(">> %i\n",input[0]);
	if( strcmp(input,"exit") == 0 )
		exit(0);
	if( strcmp(input,"size") == 0 )
		printf("%d\n",sizeof(0));
	if( strcmp(input,"addr") == 0 )
		printf("%x\n",&input);
	if( strcmp(input,"cls") == 0 )
		//system("cls; clear");
		printf("\e[1;1H\e[2J \n| Cleared...\n",12);
		//either way has own permissions and specialities...
	if( strcmp(input,"info") == 0 )
		printf("Build %d, %s %s | Author: %s\n",BUILD,B_DATE,B_TIME,AUTHOR);
	if( strcmp(input,"ret") == 0 )
	{
		main(argc,argv);
		exit(excode);
	}
	if( strcmp(input,"free") == 0 )
	{
		char *result = (char*)malloc(64);
		free(input);
		free(argv);
		free(result);
	}
	if( strcmp(input,"keycode") == 0 )
		while(true)
		{
			printf("keystroke: ");
			scanf("%s",input);
			if( strcmp(input,"exit") == 0 )
				break;
			for(i=0;i<strlen(input);i++)
				printf("%d ",input[i]);
			printf("\n");
		}
	if( strcmp(input,"milliondots") == 0 )
	{
		long int limit = pow(10,8);
		long int rn[limit];
		srand(time(NULL));
		for(i=0;i<limit;i++)
		{
			rn[i] = rand();
			printf("%ld ",rn[i]);
		}
	}
	input = NULL;
	debugging(argc,argv);
	exit(excode);
}

void list()
{
	printf("Available functions:\n");
	for(i=0;func[i] != NULL;i++)
		printf(" -> [%d] %s\n",i,func[i]);
	excode = i+1;
}

void main(int argc, char *argv[])
//void main()
{
	//if(!excode)
	//	excode = 0;
	if(argc == 0)
		exit(99);
	switch(getfunc(argc,argv))
	{
		case 0:
			list();
			break;
		case 1:
			myname(argc,argv);
			break;
		case 2:
			temperature(argc,argv);
			break;
		case 3:
			randomcheck(argc,argv);
			break;
		case 4:
			leapyear(argc,argv);
			break;
		case 5:
			trirect(argc,argv);
			break;
		case 6:
			primecheck(argc,argv);
			break;
		case 7:
			decimals(argc,argv);
			break;
		case 8:
			primenums(argc,argv);
			break;
		case 9:
			fibonacci(argc,argv);
			break;
		case 10:
			primecount(argc,argv);
			break;
		case 11:
			stars(argc,argv);
			break;
		case 12:
			primeinterval(argc,argv);
			break;
		case 13:
			pie(argc,argv);
			break;
		case 14:
			primelate(argc,argv);
			break;
		case 15:
			revofmatrix(argc,argv);
			break;
		case 16:
			nextprime(argc,argv);
			break;
		case 17:
			closestmultip(argc,argv);
			break;
		case 18:
			remain(argc,argv);
			break;
		case 99:
			debugging(argc,argv);
			break;
		default:
			printf("Exiting application...\n");
			exit(excode);
			break;
	}
	if(argc < 2)
		main(argc,argv);
	else
		exit(excode);
}

/*
	char input[3];
	printf("Enter the function number you want to use (0 for see all): ");
	scanf("%s",input);
	i = atoi(input);
	//instead of below code, you can use
	//scanf("%d",&input);
	//switch((int)input)
	//'input' is declared at top of the code...
	//This is the longest but accurate way to do.
	//return 0;
*/

/*
void main(int argc, char *argv[])
{
	start(argc,argv);
	exit(0);
}
*/
