#include <stdio.h>
#include <math.h>
#define MAX 30
#define pi 3.14159265f

float radian(float x){
	return(x * pi / 180);
}

float fungsi(float x){
	return (exp(x*-1)*sin(radian(2 * x)) + 1);
}

float feksak(float x){
	return ((2 * exp(x*-1)*cos(radian(2 * x))) - (exp(x*-1)*sin(radian(2 * x))));
}

void main(){
	int i, met, dif = 1;
	float a, b, h, ex, dfx, feks, fsel, average = 0, terror;
	char metode[][12] = { "f'(x)mundur", "f'(x)tengah", "f'(x)maju" };
	char dfr[][10] = { "f'(x)", "f''(x)", "f'''(x)", "f''''(x)", "f'''''(x)", };
	printf("Inputkan batas bawah : ");
	scanf("%f", &a);
	printf("Inputkan batas atas : ");
	scanf("%f", &b);
	printf("Inputkan step : ");
	scanf("%f", &h);
	printf("Inputkan toleransi error : ");
	scanf("%f", &terror);
	printf("Metode\n");
	printf("1. Mundur\n");
	printf("2. Tengah\n");
	printf("3. Maju\n");
	printf("Pilih : ");
	scanf("%d", &met);
	if (met == 2){
		printf("Turunan ke : ");
		do {
			scanf("%d", &dif);
		} while (dif < 1 || dif > 5);
	}
	ex = a;
	fsel = terror + 1;
	if (dif == 1)
		printf("Itr |     x     |   f(x)    |%11s|  f'eksak  |   error   |\n", metode[met - 1]);
	else
		printf("Itr |     x     |   f(x)    |%11s|\n", dfr[dif - 1]);
	for (i = 0; ex < b && fsel > terror; i++){
		ex = a + ((i)*h);
		feks = feksak(ex);
		switch (met){
		case 1: //selisih mundur
			dfx = (fungsi(ex) - fungsi(ex - h)) / h;
			break;
		case 2: //selisih tengah
			if (dif == 1)
				dfx = (fungsi(ex + h) - fungsi(ex - h)) / (2 * h);
			else if (dif == 2)
				dfx = (fungsi(ex + (2 * h)) - (2 * fungsi(ex)) + fungsi(ex - (2 * h))) / (4 * (pow(h, 2)));
			else if (dif == 3)
				dfx = (fungsi(ex + (3 * h)) - (3 * fungsi(ex + h)) + (3 * fungsi(ex - h)) - fungsi(ex - (3 * h))) / (8 * (pow(h, 3)));
			else if (dif == 4)
				dfx = (fungsi(ex + (4 * h)) - (4 * fungsi(ex + (2 * h))) + (6 * fungsi(ex)) - (4 * fungsi(ex - (2 * h))) + fungsi(ex - (4 * h))) / (16 * (pow(h, 4)));
			else
				dfx = (fungsi(ex + (5 * h)) - (5 * fungsi(ex + (3 * h))) + (10 * fungsi(ex + h)) - (10 * fungsi(ex - h)) + (5 * fungsi(ex - (3 * h))) - fungsi(ex - (5 * h))) / (32 * (pow(h, 5)));
			break;
		case 3: //selisih maju
			dfx = (fungsi(ex + h) - fungsi(ex)) / h;
			break;
		default:
			break;
		}
		fsel = fabs(dfx - feks);
		average += fsel;
		if (dif == 1)
			printf("%2d. | %9f | %9f | %9f | %9f | %9f |\n", i, ex, fungsi(ex), dfx, feks, fsel);
		else
			printf("%2d. | %9f | %9f | %9f |\n", i, ex, fungsi(ex), dfx);
	}
	if (dif == 1)
	{
		average /= i;
		printf("Rata - rata error = %f\n", average);
	}
}