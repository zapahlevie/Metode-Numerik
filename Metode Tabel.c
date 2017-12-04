#include <stdio.h>
#include <math.h>
#define MAKS 30
void tampil_tabel (float, float);
void cari_akar (float, float);
float n;

void main()
{
	float  a, b;
	printf("Masukkan batas bawah : ");
	scanf("%f",&a);
	printf("Masukkan batas atas : ");
	scanf("%f",&b);
	printf("Masukkan banyak iterasi : ");
	scanf("%f",&n);
	tampil_tabel(a,b);
	cari_akar(a,b);
}

void tampil_tabel (float a, float b)
{
	int i;
	float h, x[MAKS], fx[MAKS];
	h=(b-a)/n;
	printf("\nIterasi\tx\tf(x)\n");
	for(i=0;i<=n;i++)
	{
		x[i]=a+(i*h);
		fx[i]=x[i]+exp(x[i]);
		printf("%d\t%.4f\t%f\n",i,x[i],fx[i]);
	}
}

void cari_akar(float a, float b)
{
	int i, cek=0;
	float h, x[MAKS], fx[MAKS], akar, error;
	h=(b-a)/n;
	for(i=0;i<=n;i++)
	{
		x[i]=a+(i*h);
		fx[i]=x[i]+exp(x[i]);
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