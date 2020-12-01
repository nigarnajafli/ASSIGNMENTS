#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 512

char *readLine(char *buf, int num, FILE * stream){
    for (int i=0; i<num-1; i++){
        if(fread(buf+i, 1, 1, stream) == 0){
            if (i==0){
                buf[i]='\0';
                return NULL;
            }
            else{
                buf[i]='\0';
                break;
            }
        }
        if (buf[i]=='\n'){
            buf[i]='\0';
            break;
        }
    }
    buf[num-1]='\0';
    return buf;
}

int main(int argc, char**argv){
    if (argc<2){
        fprintf(stderr, "Needs at least one argument\n");
        exit(2);
    }

    FILE * stream = fopen(argv[1], "r");
    if (stream == NULL){
        fprintf(stderr, "can't open the file\n");
        exit(2);
    }
    char buf[BUF_SIZE];
    for (; readLine(buf, BUF_SIZE, stream) != NULL;){
        printf("another line: %s\n", buf);
    }
}
