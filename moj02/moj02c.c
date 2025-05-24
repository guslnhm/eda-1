#include <stdio.h>

int degree9(char a[], int sum){
    /*
    999999999999
    preciso converter cada um desses números para o seu correspondente em int
    preciso achar o final do número também, então tenho que saber onde tá o '\0'
    */
   /*for(i=0; a[i]!='\0';i++);
   printf("%d\n",i); //funciona para obter a quantidade de caracteres
   //mas vou utilizar isso de fato? é uma abordagem recursiva

   // pego o primeiro número da string, parseio, somo à uma variável
   // vou para o próximo
   // faço isso até encontrar o '\0'
   // então a strlen funcionaria para saber onde tá o '\0', mas posso apenas colocar uma condição de parada
   // onde entra a recursão aqui?*/



   // parseando - 
     // sum += a[0] - 48;
     // printf("soma nessa iteracao: %d\n",sum);
     // if(a[0]!='\0'){
     //      for(int j=0; a[j]!='\0'; j++){
     //           a[j] = a[j+1];
     //      }
     //      printf("nova string: %s\n",a);
     //      //degree9(a, sum);
     // }
     // return sum;
     // printf("soma final: %d\n",sum);
     while(a[0]!='\0'){
          sum += a[0] - 48;
          if(a[0]!='\0'){
               for(int j=0; a[j]!='\0'; j++){
                    a[j] = a[j+1];
               }
               printf("nova string: %s\n",a);
          }
          sum += degree9(a,sum);
     }
}

int main(){
    /*
         0123456789...
    a[0] 999999999999999
         0
    a[1] 9
         0123456789
    a[2] 9999999999
         0123456789...
    a[3] 999999999999999999999 (1000 dígitos)
    na minha string, então colocar 1001, pra contar o espaço do '\0'
    */
   char a[1000][1001];
   int i=0, resultado;
   while(1){
    scanf(" %[^\n]",a[i]);
    if(a[i][0]=='0' && a[i][1]=='\0') break;
    i++;
   }
   //printf("%d\n",i);
   //for(int j=0;j<i;j++) printf("%s\n",a[j]);
   for(int k=0;k<i;k++){
    resultado = degree9(a[k], 0);
    //printf("%d\n", resultado);
   }
}

