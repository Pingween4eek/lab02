#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

void search(struct console **arr, int *n){
	char s[50];
	FILE *f = fopen("file.txt", "r");
        if (!f) return;

        if (fscanf(f, "%d", n) != 1) return;
        if (*n <= 0) return;

        *arr = (struct console*)calloc(*n, sizeof(struct console));
        for (int i = 0; i < *n; i++)
        fscanf(f, "%s %d %d", (*arr)[i].name, &(*arr)[i].price, &(*arr)[i].count);

	printf("What model are you searching? ");
	scanf("%s", s);

	for (int i = 0; i < strlen(s); i++)
		s[i] = tolower(s[i]);

	int flag = 0;
	for (int i = 0; i < *n; i++){
		char m_name[50];
		strcpy(m_name, (*arr)[i].name);

		for(int j = 0; j < strlen((*arr)[i].name); j++)
			m_name[j] = tolower(m_name[j]);

		if (strcmp(s, m_name) == 0){
			printf("%s, price = %d, count = %d\n", (*arr)[i].name, (*arr)[i].price, (*arr)[i].count);
			flag = 1;
			break;
		}
	}

	if (flag == 0) printf("There are no matches\n");
	fclose(f);
}
