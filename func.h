struct console{
	char name[50];
	int price;
	int count;
};

void write(struct console *arr, int n);
void read(struct console **arr, int *n);
void create(struct console **arr, int *n);
void search(struct console *arr, int n);
