#include <stdio.h>
#include <math.h>
#define MAX 30

float f(float x){
	return pow(x, 2);
}

float int_f(float x){
	return pow(x, 3) / 3;
}

float a, b, n, h;

void reimann()
{
	int i;
	float l = 0, lcal = 0, x[MAX], fx[MAX], e;
	n = (b - a) / h;
	printf("\nx\t|");
	for (i = 0; i <= n; i++)
	{
		x[i] = a + (h * i);
		printf("%g\t", x[i]);
	}
	printf("\nf(x)\t|");
	for (i = 0; i <= n; i++)
	{
		fx[i] = f(x[i]);
		printf("%.4f\t", fx[i]);
		l += fx[i];
	}
	printf("\n\nL = (%g)(%g)\n", h, l);
	l *= h;
	printf("L = %g\n", l);
	printf("\nSecara Kalkulus\n");
	lcal += int_f(b) - int_f(a);
	printf("L = %g\n", lcal);
	e = fabs(l - lcal);
	printf("\nError = %g\n", e);
}

void trapezoida()
{
	int i;
	float l = 0, lcal = 0, x[MAX], fx[MAX], e;
	n = (b - a) / h;
	printf("\nx\t|");
	for (i = 0; i <= n; i++)
	{
		x[i] = a + (h * i);
		printf("%g\t", x[i]);
	}
	printf("\nf(x)\t|");
	for (i = 0; i <= n; i++)
	{
		fx[i] = f(x[i]);
		printf("%.4f\t", fx[i]);
		if (i == 0 || i == n)
			l += fx[i];
		else
			l += 2*fx[i];
	}
	printf("\n\nL = (%g/2)(%g)\n", h, l);
	l = l * h / 2;
	printf("L = %g\n", l);
	printf("\nSecara Kalkulus\n");
	lcal += int_f(b) - int_f(a);
	printf("L = %g\n", lcal);
	e = fabs(l - lcal);
	printf("\nError = %g\n", e);
}

void simpson_1per3()
{
	int i;
	float l = 0, lcal = 0, x[MAX], fx[MAX], e;
	n = (b - a) / h;
	printf("\nx\t|");
	for (i = 0; i <= n; i++)
	{
		x[i] = a + (h * i);
		printf("%g\t", x[i]);
	}
	printf("\nf(x)\t|");
	for (i = 0; i <= n; i++)
	{
		fx[i] = f(x[i]);
		printf("%.4f\t", fx[i]);
		if (i == 0 || i == n)
			l += fx[i];
		else if (i % 2 != 0)
			l += 4 * fx[i];
		else
			l += 2 * fx[i];
	}
	printf("\n\nL = (%g/3)(%g)\n", h, l);
	l = l * h / 3;
	printf("L = %g\n", l);
	printf("\nSecara Kalkulus\n");
	lcal += int_f(b) - int_f(a);
	printf("L = %g\n", lcal);
	e = fabs(l - lcal);
	printf("\nError = %g\n", e);
}

void simpson_3per8()
{
	int i;
	float l = 0, lcal = 0, x[MAX], fx[MAX], e;
	n = (b - a) / h;
	printf("\nx\t|");
	for (i = 0; i <= n; i++)
	{
		x[i] = a + (h * i);
		printf("%g\t", x[i]);
	}
	printf("\nf(x)\t|");
	for (i = 0; i <= n; i++)
	{
		fx[i] = f(x[i]);
		printf("%.4f\t", fx[i]);
		if (i == 0 || i == n)
			l += fx[i];
		else if (i % 3 != 0)
			l += 3 * fx[i];
		else
			l += 2 * fx[i];
	}
	printf("\n\nL = (3(%g)/8)(%g)\n", h, l);
	l = l * 3 * h / 8;
	printf("L = %g\n", l);
	printf("\nSecara Kalkulus\n");
	lcal += int_f(b) - int_f(a);
	printf("L = %g\n", lcal);
	e = fabs(l - lcal);
	printf("\nError = %g\n", e);
}

void main(){
	int met;
	printf("Inputkan batas bawah(a)  : ");
	scanf("%f", &a);
	printf("Inputkan batas atas(b)   : ");
	scanf("%f", &b);
	printf("Inputkan step pembagi(h) : ");
	scanf("%f", &h);
	printf("Metode\n");
	printf("1. Reimann\n");
	printf("2. Trapezoida\n");
	printf("3. Simpson 1/3\n");
	printf("4. Simpson 3/8\n");
	printf("5. ...\n");
	printf("6. ...\n");
	printf("Pilih : ");
	scanf("%d", &met);
	switch (met)
	{
	case 1:
		reimann();
		break;
	case 2:
		trapezoida();
		break;
	case 3:
		simpson_1per3();
		break;
	case 4:
		simpson_3per8();
		break;
	default:
		printf("\nMenu tidak ada!\n");
		break;
	}
}