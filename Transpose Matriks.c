#include <stdio.h>
#define MAKS 10

void main()
{
	int i, j, a, b, data[MAKS][MAKS];
	printf("Input ordo Matriks!\n");
	printf("Baris : ");
	scanf("%d",&a);
	printf("Kolom : ");
	scanf("%d",&b);
	printf("\n");
	for (i=1;i<=a;i++)
	{
		for (j=1;j<=b;j++)
		{
			printf("Input elemen baris ke-%d kolom ke-%d : ",i,j);
			scanf("%d",&data[i][j]);
		}
	}
	printf("Sebelum ditaranspose !\n");
	for (i=1;i<=a;i++)
	{
		for (j=1;j<=b;j++)
		{
			printf("%d ",data[i][j]);
		}
		printf("\n");
	}
	printf("Setelah ditaranspose !\n");
	for (j=1;j<=b;j++)
	{
		for (i=1;i<=a;i++)
		{
			printf("%d ",data[i][j]);
		}
		printf("\n");
	}
}