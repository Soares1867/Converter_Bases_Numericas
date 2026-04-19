#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


void tabela_desenho(int entrada){
    int i, j, k, l; 
    float linha, vf;
    char nome[30] = "ABCDEFGHIJKLMNOPQRTUVWXYZ";//Sem o S, porque ele significará SAIDA
    linha=pow(2,entrada);
 
    for (i=0; i<entrada; i++){
        j=0;
        vf=pow(2, entrada - i - 1); //sequencia de v e f que vai aparecer na tabela  OR, eu pedi essaformula para o chat

        printf("| %c |",nome[i]); 
           
        while(j<linha){
            for (k=0; k<vf; k++){
                printf(" v |");
                j++;
            }
            for (l=0; l<vf; l++){
                printf(" f |");
                j++;
            }                
        }
        printf("\n");   
    }
}
// 0 1 2 3 4 
// a v v f f
// b v f v f


void saida(int digitado, int entrada, bool digitado_3){
    float linha;
    int i;
    
    linha=pow(2,entrada);//OR
 
    printf("| S |");

    if (digitado==1){  //or
        if (digitado_3==false){
            for (i=0; i<linha-1; i++){
                printf(" v |");
            }
            printf(" f |");
        }
        if (digitado_3==true){
            for (i=0; i<linha-1; i++){
                printf(" f |");
            }
            printf(" v |");
        }
    }


    if (digitado==2){ //and
        if (digitado_3==false){
            printf(" v |");
            for (i=0; i<linha-1; i++){
                printf(" f |");
            }
        }
        if (digitado_3==true){
            printf(" f |");
            for (i=0; i<linha-1; i++){
                printf(" v |");
            }
        }
        
    }
}


int main(){
    int digitado, entrada;
    bool digitado_3=false;

    printf("*************************************************************\n");
    printf("                      Tabela Verdade                         \n");
    printf("*************************************************************\n");
    printf("\n");
    printf("                           Menu                              \n");
    printf("#Digite [1] OR...............................................\n");
    printf("#Digite [2] AND..............................................\n");
    printf("#Digite [3] NOT..............................................\n");
    printf("#Digite [4] para Sair........................................\n");
    
    scanf(" %d", &digitado); //1

    if (digitado==1 || digitado==2){
        printf("Digite o numero de entradas da tabela verdade: \n");
        scanf(" %d", &entrada); //4
    }

    if (digitado==3){
        digitado_3=true;
        printf("Digite o operador logico que você quer inverter: \n");
        printf("OR[1]: \n");
        printf("AND[2]: \n");
        scanf(" %d", &digitado); //4

        printf("Digite o numero de entradas da tabela verdade: \n");
        scanf(" %d", &entrada);
    }

    tabela_desenho(entrada);
    saida(digitado, entrada, digitado_3);

    return 0;
}
