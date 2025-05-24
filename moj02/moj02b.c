#include <stdio.h>

void backwards(char *string, int i){
    if(string[i]!='\0') backwards(string, i+1); //com ++i não tava funcionando
    if(i>=0 && string[i]!='\0') printf("%c",string[i]);
}

int main(){
    char s[500];
    scanf(" %[^\n]",s);
    backwards(s,0);
}