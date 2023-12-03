#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void write(struct console *arr, int n){
	if (n <= 0) return;

	FILE *f = fopen("file.txt", "w");
	if (!f) return;
	fprintf(f, "%d\n", n);

	for (int i = 0; i < n; i++)
	fprintf(f, "%s %d %d\n", arr[i].name, arr[i].price, arr[i].count);

	fclose(f); 
}

void read(struct console **arr, int *n){
	FILE *f = fopen("file.txt", "r");
	if (!f) return;

	if (fscanf(f, "%d", n) != 1) return;
	if (*n <= 0) return;

	*arr = (struct console*)calloc(*n, sizeof(struct console));
	for (int i = 0; i < *n; i++)
	fscanf(f, "%s %d %d", (*arr)[i].name, &(*arr)[i].price, &(*arr)[i].count);

	fclose(f);
}

void create(struct console **arr, int *n){
	printf("n = ");
	scanf("%d", n);
	if(*n <= 0) return;

	*arr = (struct console*)calloc(*n, sizeof(struct console));
	for (int i = 0; i < *n; i++){
		printf("name = ");
		scanf("%s", (*arr)[i].name);
		printf("price = ");
		scanf("%d", &(*arr)[i].price);

		while ((*arr)[i].price <= 0){
			printf("Incorrect price!\n");
			printf("price = ");
			scanf("%d", &(*arr)[i].price);
		}

		printf("count = ");
		scanf("%d", &(*arr)[i].count);

		while ((*arr)[i].count < 0){
			printf("Incorrect count!\n");
			printf("count = ");
			scanf("%d", &(*arr)[i].count);
		}
	}
}
