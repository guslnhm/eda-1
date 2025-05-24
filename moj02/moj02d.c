#include <stdio.h>

void movex(char *string, int contador, int i){
    //move todos os x pro final da string
    //exemplo: xxre -> rexx
    //xxhixx -> hixxxx
    if(string[i]=='x' && string[i]!='\0'){
        contador++;
        movex(string, contador, i+1);
    }
    printf("quantidade de Xs: %d\nstrlen: %d\n", contador,i);
}

int main(){
    char string[101];
    scanf(" %[^\n]", string, 0, 0);
}