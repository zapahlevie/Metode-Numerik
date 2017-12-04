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
void tab_newtab();
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
	printf("6. Metode Newton Raphson + Tabel\n");
	printf("Masukkan pilihan : ");
	scanf("%d", &c);
	if(c==1 || c==2 || c==3 || c==6)
	{
		if (c==6)
			printf("\n--Input untuk Metode Tabel\n");
		printf("Masukkan batas bawah : ");
		scanf("%f", &bbaw);
		printf("Masukkan batas atas : ");
		scanf("%f", &bats);
		if (fungsi(bbaw)*fungsi(bats) > 0)
		{
			cek = 0;
			goto exit;
		}
		printf("Masukkan banyak iterasi : ");
		scanf("%f", &n);
		if (c != 1 && c!=6)
		{
			printf("Masukkan toleransi error : ");
			scanf("%f", &e);
		}
	}
	if (c == 4 || c==5 || c==6)
	{
		if (c==6)
			printf("\n--Input untuk Metode Newton Raphson\n");
		if (c!=6)
		{
			printf("Masukkan x : ");
			scanf("%f", &ex);
		}
		printf("Masukkan banyak iterasi : ");
		scanf("%f", &n);
		printf("Masukkan toleransi error : ");
		scanf("%f", &e);
		if (c == 5)
		{
			printf("Masukkan epsilon : ");
			scanf("%f", &s);
		}
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
		tab_newton(ex);
		break;
	case 6:
		tab_newtab();
		break;
	default:
		printf("\nMaaf, menu tidak tersedia!\n");
		break;
	}
exit:
	if (cek == 0)
		printf("\nTidak terdapat akar pada range tersebut!\n");
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
	printf("--------------------------------\n");
	printf("| I|      x      |    f(x)     |\n");
	printf("--------------------------------\n");
	for (i = 0;i <= n;i++)
	{
		x[i] = bbaw + (i*h);
		fx[i] = fungsi(x[i]);
		printf("|%2d|%13.3f|%13.8f|\n", i, x[i], fx[i]);
	}
	printf("--------------------------------\n");
	for (i = 0;i<n;i++)
	{
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
			printf("Koreksi error sebesar : %.8f\n", error);
			break;
		}
	}
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
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\nAkar \t= %.4f\n", x[i]);
	printf("Error \t= %.8f\n", fabs(fx[i]));
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
	printf("\nAkar \t= %.4f\n", x[i]);
	printf("Error \t= %.8f\n", fabs(fx[i]));
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
	printf("Error \t= %.8f\n", fabs(fx[i]));
}

void tab_newton(float ex)
{
	int i;
	float x[MAKS], fx[MAKS], dfx[MAKS];
	x[0] = ex;
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
	printf("Error \t= %.8f\n", fabs(fx[i]));
}

void tab_newtab()
{
	tab_tabel();
	tab_newton(akar);
}