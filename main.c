#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "func.h"

int main(){
	struct console *arr = NULL;
	int n = 0;
	int stop = 0;

	while (stop != 1){
		int key;

		printf("1 - create, 2 - read, 3 - print, 4 - search\n");
		scanf("%d", &key);

		switch(key){
			case 1:
				create(&arr, &n);
				if (arr) write(arr, n);
				break;

			case 2:
				read(&arr, &n);
				if (!arr) printf("Read Error\n");
				else printf("Loaded %d\n", n);
				break;

			case 3:
				for (int i = 0; i < n; i++)
				printf("%s, price = %d, count = %d\n", arr[i].name, arr[i].price, arr[i].count);
				break;

			case 4:
				if (!arr) read(&arr, &n);
				search(arr, n);
				if (!arr) printf("Scan Error\n");
				break;

			default:
				stop = 1;
				break;
		}
	}

	if (arr) free(arr);
	return 0;
}
