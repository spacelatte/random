#include <stdio.h>

int main()
{
	printf("phy1002_exp2 calculator\n");
	int i;
	double a,p=0,z=0;
	printf("Enter A: ");
	scanf("%lf",&a);
	//printf("Enter value count: ");
	//scanf("%d",&cnt);
	//double v[cnt],x[cnt],r[cnt];
	double *v,*x,*r;
	for(i=0;;i++)
	{
		double v[i],x[i],r[i];
		printf("Enter V for #%d: ",i+1);
		scanf("%lf",&v[i]);
		if(v[i] <= 0)
			break;
		printf("Enter I for #%d: ",i+1);
		scanf("%lf",&x[i]);
		if(x[i] <= 0)
			break;
		r[i] = v[i] / x[i];
		z = z + r[i];
		printf("R for #%d is: %lf\n",i+1,r[i]);
		p = p + (r[i] * a / x[i]);
	}
	printf("Ravg is: %lf\nPavg is: %lf\n",z/i,p/i);
	return 0;
}
