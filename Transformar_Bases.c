#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void conversor_base(int base_entrada, int base_saida, int numero, char numeroB[]){
    int resto, a[40], i, posicao; //10 para 2
    int b[40], soma=0, g; //2 para 10
    int j=0, somador=0,f=0, tamanho_do_vetor; //16 para 10
    int restoC, p, contador=0;//10 para 16
    char c[400];//10 para 16

    //10 para 2
    if (base_entrada==10 && base_saida==2){
        posicao=0;
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
        posicao=0;
        while (numero>0){
            b[posicao]=numero%10;  //note que o numero vai ser colocado no vetor de forma ao contraria
            numero=numero/10; //110   011
            posicao++;
        }

        for(g=0; g<posicao; g++){
            if (b[g]==1){
                soma+=b[g]*pow(2,g);
            }
        }

        printf(" %d\n", soma);
    }


    //16 para 10
    if (base_entrada==16 && base_saida==10){  //356 base 16

        numeroB[strcspn(numeroB, "\n")] = '\0'; //para tirar o \n usamos esse comando, assim, vi contar 1 2 A, OU SEJA 3
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

        printf("%d\n", somador);

    }


    //10 para 16
    if(base_entrada==10 && base_saida==16){
        for(p=0;numero!=0;p++){
            restoC=numero%16;  //35/16= 2, resto 3   2/16=0, resto 2
            numero=numero/16;
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
            printf("%c\n", c[p]);
        }
    }
    

}


void peso(int base_digitado_2, char numeroC[]){//base:10, numeroC:12
    int tamanho_do_vetorB;  

    numeroC[strcspn(numeroC, "\n")] = '\0'; //para tirar o \n usamos esse comando, assim, vi contar 1 2 A, OU SEJA 3
    tamanho_do_vetorB = strlen(numeroC);

    printf("O digito de valor mais significativo é: %c\n", numeroC[0]);
    printf("O digito de valor menos significativo é: %c\n", numeroC[tamanho_do_vetorB-1]);
    
}



void quantia_num(int base_digitado_3, int posicao3){
    int numero_gerado=0;
         
    printf("Para a base %d, temos %d elevado a n posições, que dara a quantia de numeros gerados.\n", base_digitado_3, base_digitado_3);
    numero_gerado+=pow(base_digitado_3, posicao3);
    printf("%d posições na base 10, dará: %d numeros\n", posicao3, numero_gerado);

}



int main()
{
    //Variaveis para digitado 1
    int base_entrada, base_saida, numero, digitado;

    //Arrumar esses numeros
    char numeroB[400];//16 para 10
    

    //Variaveis para digitado 3
    int base_digitado_3, posicao3;


    //Variaveis para digitado 2
    int base_digitado_2;
    char numeroC[400];

    while(digitado!=4){
        printf("*************************************************************\n");
        printf("                     Bases Numericas                         \n");
        printf("*************************************************************\n");
        printf("\n");
        printf("                           Menu                              \n");
        printf("#Digite [1] para conversão de bases.............................\n");
        printf("#Digite [2] para encontrar o MSB (most significant bit) e LSD\n (least significant bit) do valor digitado...................\n");
        printf("#Digite [3] para saber a quantia de numeros formados por n\n posições.....................................................\n");
        printf("#Digite [4] para Sair.....................................\n");
        
        scanf(" %d", &digitado);

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

            if (base_entrada==16){
                // fgets ler string, substitui o scanf, ver no capitulo do livro que fala de string
                setbuf(stdin, NULL);                         //limpar o fgets
                fgets(numeroB, sizeof(numeroB), stdin);      //12A   1 2 A \n \0 assim tem 5 digitos, o strlen vai aparecer 4, contando o \n
                conversor_base(base_entrada, base_saida, 0, numeroB);
            }
            else{
                scanf(" %d", &numero);
                conversor_base(base_entrada, base_saida, numero, numeroB);
            }
        }


        if (digitado==2){
            //Base de entrada
            printf("Digite o numero: "); //17

            getchar();
            // fgets ler string, substitui o scanf, ver no capitulo do livro que fala de string
            setbuf(stdin, NULL);                         //limpar o fgets
            fgets(numeroC, sizeof(numeroC), stdin);      //12A   1 2 A \n \0 assim tem 5 digitos, o strlen vai aparecer 4, contando o \n
            peso(base_digitado_2, numeroC);
        }


        if(digitado==3){
            printf("Digite a base: ");
            scanf(" %d", &base_digitado_3);
            printf("Digite o posicao: ");
            scanf(" %d", &posicao3);
            quantia_num(base_digitado_3, posicao3);
        }
        printf("\n");
    }

    printf("FIM!");
   
    return 0;
}
