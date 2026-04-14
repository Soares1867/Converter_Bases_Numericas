#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    //Variaveis gerais
    int base_entrada, base_saida, digitado;

    //Variaveis de 10 para 2
    int numero, resto, a[40], i, posicao;

    int somador=0, f, tamanho_do_vetor, j=0;
    char numeroB[400];

    int quantia, g, b[40], soma=0, numeroA;

    int restoC, numeroC, contador=0, p;
    char c[400];

    int base_digitado_3, numero_gerado=0, posicao3;


    printf("*************************************************************\n");
    printf("                     Bases Numericas                         \n");
    printf("*************************************************************\n");
    printf("\n");
    printf("                           Menu                              \n");
    printf("#Digite 1 para conversõ de bases.............................\n");
    printf("#Digite 2 para encontrar o MSB (most significant bit) e LSD\n (least significant bit) do valor digitado...................\n");
    printf("#Digite 3 para saber a quantia de numeros formados por n\n posições.....................................................\n");
    scanf(" %d", &digitado);
    printf("\n");

    if (digitado==1){
        //Base de entrada
        printf("Digite a Base que voce quer de entrada: \n");
        printf("[10] Base 10\n[16] Base 16\n[2] Base 2: \n");
        scanf(" %d", &base_entrada);

        //Base de saida
        printf("Digite a Base que voce quer de saida: \n");
        printf("[10] Base 10\n[16] Base 16\n[2] Base 2: \n");
        scanf(" %d", &base_saida);

        //Numero para transformar
        printf("Digite o numero: "); //17



        //10 para 2
        if (base_entrada==10 && base_saida==2){
            posicao=0;
            scanf(" %d", &numero);

            while(numero>0){
                resto=numero%2;
                numero=numero/2;
                a[posicao]=resto;
                posicao++;
            }

            for (i=posicao-1; i>=0; i--){
                printf(" %d", a[i]);
            }

        }


        //2 para 10
        if (base_entrada==2 && base_saida==10){
            quantia=0;
            scanf(" %d", &numeroA);
            while (numeroA>0){
                b[quantia]=numeroA%10;  //note que o numero vai ser colocado no vetor de forma ao contraria
                numeroA=numeroA/10; //110   011
                quantia++;
            }

            for(g=0; g<quantia; g++){
                if (b[g]==1){
                    soma+=b[g]*pow(2,g);
                }
            }

            printf(" %d", soma);
        }


        //16 para 10
        if (base_entrada==16 && base_saida==10){  //356 base 16
            // fgets ler string, substitui o scanf, ver no capitulo do livro que fala de string
            setbuf(stdin, NULL);                         //limpar o fgets
            fgets(numeroB, sizeof(numeroB), stdin);      //12A   1 2 A \n \0 assim tem 5 digitos, o strlen vai aparecer 4, contando o \n
            numeroB[strcspn(numeroB, "\n")] = '\0';      //para tirar o \n usamos esse comando, assim, vi contar 1 2 A, OU SEJA 3
            tamanho_do_vetor = strlen(numeroB);

            for (f=0; f<=tamanho_do_vetor-1; f++){ //f<=2, porque strlen vaidar 3, (1,2,3), mas aposição começa do 0,(0,1,2)
                if(numeroB[f]=='A' || numeroB[f]=='a'){
                    numeroB[f]=10;                        //12a= 1 2 10, trocou a por 10
                } else if(numeroB[f]=='B' || numeroB[f]=='b'){
                    numeroB[f]=11;
                } else if(numeroB[f]=='C' || numeroB[f]=='c'){
                    numeroB[f]=12;
                } else if(numeroB[f]=='D' || numeroB[f]=='d'){
                    numeroB[f]=13;
                } else if(numeroB[f]=='E' || numeroB[f]=='e'){
                    numeroB[f]=14;
                } else if(numeroB[f]=='F' || numeroB[f]=='f'){
                    numeroB[f]=15;
                } else{
                    numeroB[f] = numeroB[f] - '0'; // como esta em char, os numeros são convertidos para letras da tabela, exemplo, digito 1, vai aparecer 49, lembrando de '0' é igul a 48, é só tirar 48 de 49, ue da 1
                }
            }

            for (i=tamanho_do_vetor-1; i>=0; i--){ //quando eu pedir o scanf para char, cada digito do numero digitado já vai automaticamente para uma posição do vetor
                somador+=numeroB[i] * pow(16,j);
                j++;
            }

            printf("%d", somador);

        }


        //10 para 16
        if(base_entrada==10 && base_saida==16){
            scanf(" %d", &numeroC);
            for(p=0;numeroC!=0;p++){
                restoC=numeroC%16;  //35/16= 2, resto 3   2/16=0, resto 2
                numeroC=numeroC/16;
                if (restoC==10){
                    c[p]='A';
                }else if (restoC==11){
                    c[p]='B';
                }else if (restoC==12){
                    c[p]='C';
                }else if (restoC==13){
                    c[p]='D';
                }else if (restoC==14){
                    c[p]='E';
                }else if (restoC==15){
                    c[p]='F';
                }else{
                    c[p]=restoC;
                    c[p] = c[p] + '0'; //eu digito o 5, e não é tranformado em char, porque usei scanf, esta tudo bem, é só somar o '0', ao inves de tirar
                }
                contador++;
            }

            for (p=contador-1;p>=0;p--){ //menos 1 porque 12A tem 3 no contador, mas as posições são 0,1,2
                printf("%c", c[p]);
            }


        }
    }

    if (digitado==3){
        printf("Digite a base: ");
        scanf(" %d", &base_digitado_3);
        printf("Digite o posicao: ");
        scanf(" %d", &posicao3);

        if (base_digitado_3==10){
            printf("Para a base 10, temos 10 elevado a n posições, que dara a quantia de numeros gerados.\n");
            numero_gerado+=pow(10, posicao3);
            printf("%d posições na base 10, dará: %d numeros", posicao3, numero_gerado);
        }
/*
        if (base_digitado_3==2){
            printf("Para a base 10, temos 10 elevado a n posições, que dara a quantia de numeros gerados.\n");
            numero_gerado+=pow(10, n);
            printf("%d posições na base 10, dará: %d numeros", posicao3, numero_gerado);


        if (base_digitado_3==16){
            printf("Para a base 10, temos 10 elevado a n posições, que dara a quantia de numeros gerados.\n");
            numero_gerado+=pow(10, n);
            printf("%d posições na base 10, dará: %d numeros", posicao3, numero_gerado);


    }

*/
    }
    return 0;
}
