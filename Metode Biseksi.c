#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAKS 30
void tab_tabel (float, float);
void tab_biseksi (float, float);
float n, e;

void main()
{
	float  a, b;
	int c;
	printf("Masukkan batas bawah : ");
	scanf("%f",&a);
	printf("Masukkan batas atas : ");
	scanf("%f",&b);
	printf("Masukkan banyak iterasi : ");
	scanf("%f",&n);
	printf("Masukkan toleransi error : ");
	scanf("%f",&e);
	printf("Metode penyelesaian : \n");
	printf("1. Metode Tabel\n");
	printf("2. Metode Biseksi\n");
	printf("Masukkan pilihan : ");
	scanf("%d",&c);
	switch (c)
	{
	case 1:
		tab_tabel(a,b);
		break;
	case 2:
		tab_biseksi(a,b);
		break;
	default:
		printf("\nMaaf, menu tidak tersedia!\n");
		break;
	}
}

void tab_tabel (float a, float b)
{
	int i, cek=0;
	float h, x[MAKS], fx[MAKS], akar, error;
	h=(b-a)/n;
	printf("\nIterasi\tx\tf(x)\n");
	for(i=0;i<=n;i++)
	{
		x[i]=a+(i*h);
		fx[i]=x[i]+exp(x[i]);
		printf("%d\t%.4f\t%f\n",i,x[i],fx[i]);
	}
	for(i=0;i<n;i++)
	{
		if((fx[i]*fx[i+1])==0)
		{
			cek = 1;
			akar=x[i];
			printf("\n%.4f adalah akar\n",akar);
		}
		else if((fx[i]*fx[i+1])<0)
		{
			cek = 1;
			printf("\nAkar di antara %.4f dan %.4f\n",x[i],x[i+1]);
			if(fabs(fx[i])<fabs(fx[i+1]))
			{
				akar=x[i];
				error=fabs(fx[i]);
			}
			else
			{
				akar=x[i+1];
				error=fabs(fx[i+1]);
			}
			printf("Akar lebih dekat ke %.4f\n",akar);
			printf("Koreksi error sebesar : %f\n",error);
			break;
		}
	}
	if (cek==0)
		printf("\nTidak terdapat akar pada range tersebut!\n");
}

void tab_biseksi (float bbaw, float bats)
{
	int i;
	float a[MAKS], b[MAKS], x[MAKS], fa[MAKS], fx[MAKS];
	char indikasi[MAKS];
	a[0] = bbaw;
	b[0] = bats;
	x[0]=(a[0]+b[0])/2;
	fa[0]=a[0]+exp(a[0]);
	fx[0]=x[0]+exp(x[0]);
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("| I|      a      |      b      |      x      |     f(a)    |     f(x)    |  f(a)*f(x)  |         Indikasi Akar         |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		if ((fa[i]*fx[i])<0)
			strcpy(indikasi,"Ada akar antara a dan x");
		else
			strcpy(indikasi,"Tidak ada akar antara a dan x");
		printf("|%2d|%13.8f|%13.8f|%13.8f|%13.8f|%13.8f|%13.8f|  %29s|\n",i+1,a[i],b[i],x[i],fa[i],fx[i],fa[i]*fx[i],indikasi);
		if (i==n-1 || fabs(fx[i])<e)
			break;
		if((fa[i]*fx[i])<0)
		{
			a[i+1]=a[i];
			b[i+1]=x[i];
		}
		else
		{
			a[i+1]=x[i];
			b[i+1]=b[i];
		}
		x[i+1]=(a[i+1]+b[i+1])/2;
		fa[i+1]=a[i+1]+exp(a[i+1]);
		fx[i+1]=x[i+1]+exp(x[i+1]);
	}printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\nAkar \t= %.4f\n",x[i]);
	printf("Error \t= %f\n",fabs(fx[i]));
}