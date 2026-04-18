#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


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


void saida(int digitado, int entrada){
    float linha;
    int i;
    
    linha=pow(2,entrada);//OR
 
    printf("| S |");
    if (digitado==1){  //or
        for (i=0; i<linha-1; i++){
            printf(" v |");
        }
        printf(" f |");
    }

    if (digitado==2){ //and
        printf(" v |");
        for (i=0; i<linha-1; i++){
            printf(" f |");
        }
        
    }
}


int main(){
    int digitado, entrada;

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
        printf("Digite");
    }

    tabela_desenho(entrada);
    saida(digitado, entrada);

    return 0;
}
