#include <stdio.h>

void function(char *source, char *integer, char *nonInteger)
{
	int j=0;
	int k=0;
	for (int i=0; source[i] != '\0'; i++){
		if (source[i] >= 48 && source[i]<=57){
			integer[j] = source[i];
			j++;
		}
		else{
			nonInteger[k] = source[i];
			k++;
		}
	}
	integer[j]='\0';
	nonInteger[k]='\0';
}



int main(){
	char source[]="abc123 [{def99";
	char integers[256];
	char nonIntegers[256];

	function(source, integers, nonIntegers);

	printf("Integers: %s\n", integers);
	printf("Non integers: %s\n", nonIntegers);
}
