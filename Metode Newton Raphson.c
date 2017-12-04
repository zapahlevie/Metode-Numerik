#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAKS 30
float fungsi(float);
float fungsig(float);
float fungsidf(float);
void tab_tabel();
void tab_biseksi();
void tab_falsi();
void tab_iterasi();
void tab_newton(float);
float bbaw, bats, n, e, s, ex, akar;
int  cek = 1;

void main()
{
	int c; char kar;
	printf("Metode penyelesaian : \n");
	printf("---Metode Tertutup---\n");
	printf("1. Metode Tabel\n");
	printf("2. Metode Biseksi\n");
	printf("3. Metode Regula Falsi\n");
	printf("---Metode Terbuka---\n");
	printf("4. Metode Iterasi Sederhana\n");
	printf("5. Metode Newton Raphson\n");
	printf("Masukkan pilihan : ");
	scanf("%d", &c);
	if (c == 4 || c==5)
	{
		printf("Masukkan x : ");
		scanf("%f", &ex);
	}
	if(c==1 || c==2 || c==3)
	{
		printf("Masukkan batas bawah : ");
		scanf("%f", &bbaw);
		printf("Masukkan batas atas : ");
		scanf("%f", &bats);
	}
	printf("Masukkan banyak iterasi : ");
	scanf("%f", &n);
	if (c != 1)
	{
		printf("Masukkan toleransi error : ");
		scanf("%f", &e);
	}
	if (c == 5)
	{
		printf("Masukkan epsilon : ");
		scanf("%f", &s);
	}
	switch (c)
	{
	case 1:
		tab_tabel();
		break;
	case 2:
		tab_biseksi();
		break;
	case 3:
		tab_falsi();
		break;
	case 4:
		tab_iterasi();
		break;
	case 5:
		printf("\nIngin digabung dengan metode tabel(y/n) ?: ");
		fflush(stdin);scanf("");
		scanf("%c",&kar);
		if (kar == 'y' || kar == 'Y')
		{
			tab_tabel();
			tab_newton(akar);
		}
		else
			tab_newton(ex);
		break;
	default:
		printf("\nMaaf, menu tidak tersedia!\n");
		break;
	}
}

float fungsi(float x)
{
	float fx;
	fx = x + exp(x);
	return fx;
}

float fungsig(float x)
{
	float gx;
	gx = exp(x)*-1;
	return gx;
}

float fungsidf(float x)
{
	float dfx;
	dfx = 1 + exp(x);
	return dfx;
}

void tab_tabel()
{
	int i;
	float h, x[MAKS], fx[MAKS], error;
	h = (bats - bbaw) / n;
	printf("\nIterasi\tx\tf(x)\n");
	for (i = 0;i <= n;i++)
	{
		if (fungsi(bbaw)*fungsi(bats) > 0)
		{
			cek = 0;
			break;
		}
		x[i] = bbaw + (i*h);
		fx[i] = fungsi(x[i]);
		printf("%d\t%.4f\t%f\n", i, x[i], fx[i]);
	}
	for (i = 0;i<n;i++)
	{
		if (fungsi(bbaw)*fungsi(bats) > 0)
		{
			cek = 0;
			break;
		}
		if ((fx[i] * fx[i + 1]) == 0)
		{
			cek = 1;
			akar = x[i];
			printf("\n%.4f adalah akar\n", akar);
		}
		else if ((fx[i] * fx[i + 1])<0)
		{
			cek = 1;
			printf("\nAkar di antara %.4f dan %.4f\n", x[i], x[i + 1]);
			if (fabs(fx[i])<fabs(fx[i + 1]))
			{
				akar = x[i];
				error = fabs(fx[i]);
			}
			else
			{
				akar = x[i + 1];
				error = fabs(fx[i + 1]);
			}
			printf("Akar lebih dekat ke %.4f\n", akar);
			printf("Koreksi error sebesar : %f\n", error);
			break;
		}
	}
	if (cek == 0)
		printf("\nTidak terdapat akar pada range tersebut!\n");
}

void tab_biseksi()
{
	int i;
	float a[MAKS], b[MAKS], x[MAKS], fa[MAKS], fx[MAKS];
	char indikasi[MAKS];
	a[0] = bbaw;
	b[0] = bats;
	x[0] = (a[0] + b[0]) / 2;
	fa[0] = fungsi(a[0]);
	fx[0] = fungsi(x[0]);
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("| I|      a      |      b      |      x      |     f(a)    |     f(x)    |  f(a)*f(x)  |         Indikasi Akar         |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	for (i = 0;i<n;i++)
	{
		if (fungsi(bbaw)*fungsi(bats) > 0)
		{
			cek = 0;
			break;
		}
		if ((fa[i] * fx[i])<0)
			strcpy(indikasi, "Ada akar antara a dan x");
		else
			strcpy(indikasi, "Tidak ada akar antara a dan x");
		printf("|%2d|%13.8f|%13.8f|%13.8f|%13.8f|%13.8f|%13.8f|  %29s|\n", i + 1, a[i], b[i], x[i], fa[i], fx[i], fa[i] * fx[i], indikasi);
		if (i == n - 1 || fabs(fx[i])<e)
			break;
		if ((fa[i] * fx[i])<0)
		{
			a[i + 1] = a[i];
			b[i + 1] = x[i];
		}
		else
		{
			a[i + 1] = x[i];
			b[i + 1] = b[i];
		}
		x[i + 1] = (a[i + 1] + b[i + 1]) / 2;
		fa[i + 1] = fungsi(a[i + 1]);
		fx[i + 1] = fungsi(x[i + 1]);
	}printf("------------------------------------------------------------------------------------------------------------------------\n");
	if (cek == 0)
		printf("\nTidak terdapat akar pada range tersebut!\n");
	else
	{
		printf("\nAkar \t= %.4f\n", x[i]);
		printf("Error \t= %f\n", fabs(fx[i]));
	}
}

void tab_falsi()
{
	int i;
	float a[MAKS], b[MAKS], x[MAKS], fa[MAKS], fb[MAKS], fx[MAKS];
	char indikasi[MAKS];
	a[0] = bbaw;
	b[0] = bats;
	fa[0] = fungsi(a[0]);
	fb[0] = fungsi(b[0]);
	x[0] = ((fb[0] * a[0]) - (fa[0] * b[0])) / (fb[0] - fa[0]);
	fx[0] = fungsi(x[0]);
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| I|      a      |      b      |      x      |     f(a)    |     f(b)    |     f(x)    |  f(a)*f(x)  |         Indikasi Akar         |\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
	for (i = 0;i < n;i++)
	{
		if (fungsi(bbaw)*fungsi(bats) > 0)
		{
			cek = 0;
			break;
		}
		if ((fa[i] * fx[i]) < 0)
			strcpy(indikasi, "Ada akar antara a dan x");
		else
			strcpy(indikasi, "Tidak ada akar antara a dan x");
		printf("|%2d|%13.8f|%13.8f|%13.8f|%13.8f|%13.8f|%13.8f|%13.8f|  %29s|\n", i + 1, a[i], b[i], x[i], fa[i], fb[i], fx[i], fa[i] * fx[i], indikasi);
		if (i == n - 1 || fabs(fx[i]) < e)
			break;
		if ((fa[i] * fx[i]) < 0)
		{
			a[i + 1] = a[i];
			b[i + 1] = x[i];
		}
		else
		{
			a[i + 1] = x[i];
			b[i + 1] = b[i];
		}
		fa[i + 1] = fungsi(a[i + 1]);
		fb[i + 1] = fungsi(b[i + 1]);
		x[i + 1] = ((fb[i + 1] * a[i + 1]) - (fa[i + 1] * b[i + 1])) / (fb[i + 1] - fa[i + 1]);
		fx[i + 1] = fungsi(x[i + 1]);
	}printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
	if (cek == 0)
		printf("\nTidak terdapat akar pada range tersebut!\n");
	else
	{
		printf("\nAkar \t= %.4f\n", x[i]);
		printf("Error \t= %f\n", fabs(fx[i]));
	}
}

void tab_iterasi()
{
	int i;
	float x[MAKS], fx[MAKS];
	x[0] = ex;
	fx[0] = fungsi(x[0]);
	printf("\n--------------------------------\n");
	printf("| I|      x      |     f(x)    |\n");
	printf("--------------------------------\n");
	for (i = 0;i < n;i++)
	{
		printf("|%2d|%13.8f|%13.8f|\n", i + 1, x[i], fx[i]);
		if (i == n - 1 || fabs(fx[i]) < e)
			break;
		x[i + 1] = fungsig(x[i]);
		fx[i + 1] = fungsi(x[i + 1]);
	}
	printf("--------------------------------\n");
	printf("\nAkar \t= %.4f\n", x[i]);
	printf("Error \t= %f\n", fabs(fx[i]));
}

void tab_newton(float)
{
	int i;
	float x[MAKS], fx[MAKS], dfx[MAKS];
	x[0] = bbaw;
	fx[0] = fungsi(x[0]);
	dfx[0] = fungsidf(x[0]);
	if (dfx[0] == 0)
	{
		x[0] += s;
		fx[0] = fungsi(x[0]);
		dfx[0] = fungsidf(x[0]);
	}
	printf("\n----------------------------------------------\n");
	printf("| I|      x      |     f(x)    |    f'(x)    |\n");
	printf("----------------------------------------------\n");
	for (i = 0;i < n;i++)
	{
		printf("|%2d|%13.8f|%13.8f|%13.8f|\n", i + 1, x[i], fx[i], dfx[i]);
		if (i == n - 1 || fabs(fx[i]) < e)
			break;
		x[i + 1] = x[i] - (fx[i] / dfx[i]);
		fx[i + 1] = fungsi(x[i + 1]);
		dfx[i + 1] = fungsidf(x[i + 1]);
		if (dfx[i + 1] == 0)
		{
			x[i + 1] += s;
			fx[i + 1] = fungsi(x[i + 1]);
			dfx[i + 1] = fungsidf(x[i + 1]);
		}
	}
	printf("----------------------------------------------\n");
	printf("\nAkar \t= %.4f\n", x[i]);
	printf("Error \t= %f\n", fabs(fx[i]));
}