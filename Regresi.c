#include <stdio.h>
#include <math.h>
#define MAX 100

int n;
float x[MAX], y[MAX];
float t[MAX], dt[MAX];

float count_m(float x, float y, float xy, float xx) {
	return ((n*xy) - (x*y)) / ((n*xx) - x*x);
}

float count_c(float x, float y, float m) {
	return (y / n) - m*(x / n);
}

void main() {
	int i = 0, met; char again;
	float tot_x = 0, tot_y = 0, tot_xy = 0, tot_xx = 0, m, xbaru, ybaru;
	float tot_t = 0, tot_t2 = 0, tot_t3 = 0, tot_t4 = 0, tot_dt = 0, tot_tdt = 0, tot_t2dt = 0;
	float gama, epsilon, teta, alpha, beta, a, b, c;
	printf(".:REGRESI:.\n\n");
	printf("Metode\n");
	printf("1. Regresi Linier\n");
	printf("2. Regresi Kuadratik\n");
	printf("Pilih : ");
	scanf("%d", &met);
	switch (met) {
	case 1:
		printf("\nInput n : ");
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			printf("Masukkan (x%d,y%d) : ", i, i);
			scanf("%f,%f", &x[i], &y[i]);
		}
		printf("=========================================\n");
		printf("|       |   x   |   y   |  x*y  |  x^2  |\n");
		printf("=========================================\n");
		for (i = 1; i <= n; i++) {
			printf("|       |%7g|%7g|%7g|%7g|\n", x[i], y[i], x[i] * y[i], x[i] * x[i]);
			tot_x += x[i];
			tot_y += y[i];
			tot_xy += x[i] * y[i];
			tot_xx += x[i] * x[i];
		}
		printf("=========================================\n");
		printf("| total |%7g|%7g|%7g|%7g|\n", tot_x, tot_y, tot_xy, tot_xx);
		printf("=========================================\n");
		m = count_m(tot_x, tot_y, tot_xy, tot_xx);
		printf("m = %g\n", m);
		c = count_c(tot_x, tot_y, m);
		printf("c = %g\n", c);
		printf("Fungsi Linier :\n");
		printf("y = %gx + %g\n", m, c);
		do {
			printf("Masukkan x baru : ");
			scanf("%f", &xbaru);
			ybaru = m*xbaru + c;
			printf("titik baru = (%g,%g)\n", xbaru, ybaru);
			fflush(stdin);
			printf("Mau lagi ?");
			again = getchar();
		} while (again == 'y' || again == 'Y');
		break;
	case 2:
		printf("\nInput n  : ");
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			printf("Input t  : ");
			scanf("%f", &t[i]);
			printf("Input dt : ");
			scanf("%f", &dt[i]);
		}
		printf("=================================================================\n");
		printf("|       |   t   |  t^2  |  t^3  |  t^4  |   dt  |  tdt  |  t2dt |\n");
		printf("=================================================================\n");
		for (i = 1; i <= n; i++) {
			printf("|       |%7g|%7g|%7g|%7g|%7g|%7g|%7g|\n", t[i], pow(t[i], 2), pow(t[i], 3), pow(t[i], 4), dt[i], t[i] * dt[i], pow(t[i], 2) * dt[i]);
			tot_t += t[i];
			tot_t2 += pow(t[i], 2);
			tot_t3 += pow(t[i], 3);
			tot_t4 += pow(t[i], 4);
			tot_dt += dt[i];
			tot_tdt += t[i] * dt[i];
			tot_t2dt += pow(t[i], 2) * dt[i];
		}
		printf("=================================================================\n");
		printf("| total |%7g|%7g|%7g|%7g|%7g|%7g|%7g\n", tot_t, tot_t2, tot_t3, tot_t4, tot_dt, tot_tdt, tot_t2dt);
		printf("=================================================================\n");
		gama = pow(tot_t2, 2) - (n * tot_t4);
		epsilon = (tot_t * tot_dt) - (n * tot_tdt);
		teta = (tot_t2 * tot_dt) - (n * tot_t2dt);
		alpha = (tot_t * tot_t2) - (n * tot_t3);
		beta = pow(tot_t, 2) - (n * tot_t2);
		b = ((gama * epsilon) - (teta * alpha)) / ((gama * beta) - pow(alpha, 2));
		c = (teta - (b * alpha)) / gama;
		a = (tot_dt / n) - (b * tot_t / n) - (c * tot_t2 / n);
		printf("Fungsi Kuadratik :\n");
		printf("d'(t) = %g + %gt + %gt^2\n", a, b, c);
		do {
			printf("Masukkan t baru : ");
			scanf("%f", &xbaru);
			ybaru = a + (b * xbaru) + (c * pow(xbaru, 2));
			printf("d'(t) = %g\n", ybaru);
			fflush(stdin);
			printf("Mau lagi ?");
			again = getchar();
		} while (again == 'y' || again == 'Y');
		break;
	default:
		printf("Maaf, inputan salah!\n");
		break;
	}

}