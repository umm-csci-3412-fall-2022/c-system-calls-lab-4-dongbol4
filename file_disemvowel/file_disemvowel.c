#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void disemvowel(FILE* inputFile, FILE* outputFile) {
    char* str = calloc(BUF_SIZE + 1,sizeof(char));
    char* result;
    int i = 0;
    int j = 0;
    while(fgets(str,BUF_SIZE,inputFile) != 0 ){
        i = 0;
        j = 0;
        result = (char*) calloc(strlen(str)+1, sizeof(char));
        for(i=0;str[i];i++){
            char temp[1]={str[i]};
            if(strpbrk(temp,"aeiouAEIOU")){
            }else{
                result[j++] = str[i];
            }
        }
        result[j] = '\0';
        fwrite(result,1,strlen(result),outputFile);
        free(result);
    }
    free(str);
}

int main(int argc, char *argv[]) {
    FILE *inputFile = stdin;
    FILE *outputFile = stdout;
    
    if(argc == 2) {
        inputFile = fopen(argv[1], "r");
    } else if (argc == 3) {
        inputFile = fopen(argv[1], "r");
        outputFile = fopen(argv[2], "w");
    } else if (argc > 3) { 
        fprintf(stderr, "File Error, please try again. : )");
        exit(1);
    }
    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "File Error, please try again. : )");
        exit(1);
    }

    disemvowel(inputFile, outputFile);
    
    if(inputFile != stdin) {
        fclose(inputFile);
    }
    if(outputFile != stdout) {
        fclose(outputFile);
    }

    return 0;
}
