#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void write(struct console *arr, int n){
	if (n <= 0) return;

	FILE *f = fopen("file.txt", "w");
	if (!f) return;
	fprint(f, "%d\n", n);

	for (int i = 0; i < n; i++)
	fprint(f, "%s, price = %d, count = %d\n", arr[i].name, arr[i].price, arr[i].count);

	fclose(f); 
}

void read(struct console **arr, int *n){
	FILE *f = fopen("file.txt", "r");
	if (!f) return;

	if (fscanf(f, "%d", n) != 1) return;
	if (*n <= 0) return;

	*arr = (struct console*)calloc(*n, sizeof(struct console));
	for (int i = 0; i < *n; i++)
	fscanf(f, "%s %d %d", (arr*)[i].name, &(arr*)[i].price, &(arr*)[i].count);

	fclose(f);
}

