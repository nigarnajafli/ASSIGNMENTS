#include <stdio.h>
void swapStrings(char *destination, char *source);

int main(){
        char str1[] = "Hello";
        char str2[] = "World";
    // define and initialize str1
    // define and initialize str2

    printf("str1: %s, str2: %s\n",str1,str2);
    swapStrings(str1, str2);
    printf("str1: %s, str2: %s\n",str1,str2);
    return 0;
}
    // swaps contents of two strings 
    // implement this function without using any built in functions    
void swapStrings(char *destination, char *source){
    for (; *destination != '\0'; destination++, source++){
        int temp = *destination;
        *destination = *source;
        *source = temp;}
}