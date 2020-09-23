#include <stdio.h>

void swap (int val1, int val2);

void print (int *val1, int *val2);

int main(){

	int i = 50;
	int j = 100;

	print(&i, &j);
	swap(i, j);
	printf("Exiting swap function:\n");
	print(&i, &j);

	return 0;
}

void swap (int val1, int val2){
	int temp;
	printf("Before swap function:\n");
	print(&val1, &val2);
	temp = val1;
	val1 = val2;
	val2 = temp;
	printf("After swap function:\n");
	print(&val1, &val2);
}

void print(int *val1, int *val2){
	printf("i: %d at %p\n", *val1, val1);
	printf("j: %d at %p\n", *val2, val2);
}


