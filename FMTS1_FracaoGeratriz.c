#include <stdio.h>
#include <stdlib.h>

int main(){
    char *end;
    char inteiro[10], periodo[10], inteiroperiodo[15], denominador[15];
    int inteiro_int, inteiroperiodo_int, numerador, i;
    char loopCheck = 'S';

    //Apresentacao do programa
    printf("FRACAO GERATRIZ\n\n");
    printf("Insira uma dizima periodica simples nesse formato: INTEIRO PERIODO\n");
    printf("Exemplo 1: 1,444... = 1 4\n");
    printf("Exemplo 2: 17,898989... = 17 89\n");

    //Loop
    while((loopCheck == 'S') || (loopCheck == 's')){
        //Entrada de dizima periodica
        printf("\n--> ");
        scanf("%s", inteiro);
        scanf("%s", periodo);
        inteiro_int = strtol(inteiro, &end, 10); //Conversao do valor inteiro de char para int
        sprintf(inteiroperiodo, "%s%s", inteiro, periodo); //Juncao do valor inteiro e do periodo em um unico string
        inteiroperiodo_int = strtol(inteiroperiodo, &end, 10); //Conversao da juncao criada acima de char para int

        //Contagem de quantos 9 deverao compor o denominador
        for(i = 0; i < strlen(periodo); i++){
            sprintf(denominador, "%s%s", denominador, "9");
        }

        //Calculo do numerador
        numerador = inteiro_int;
        if(numerador != 0){
            numerador = inteiroperiodo_int - inteiro_int; // 3,5 -> 35 - 3 = 32/9
        }

        //Saida da fracao geratriz
        if(numerador != 0){
            printf("\n%s,%s%s... = %d/%s \n\n", inteiro, periodo, periodo, numerador, denominador);
        }else{
            printf("\n%s,%s%s... = %s/%s \n\n", inteiro, periodo, periodo, periodo, denominador);
        }

        //Reiniciando o string denominador
        memset(denominador, 0, sizeof(denominador));

        //Opcao de rodar novamente ou encerrar o programa
        getchar();
        printf("Realizar a conversao de outra dizima periodica simples (S/N)? ");
        scanf("%c", &loopCheck);
        while((loopCheck != 'S') && (loopCheck != 's') && (loopCheck != 'N') && (loopCheck != 'n')){
            getchar();
            printf("Entrada invalida. Insira apenas S para converter outra dizima ou N para encerrar o programa: ");
            scanf("%c", &loopCheck);
        }
    }

    printf("\nEncerrando o programa . . .\n");
    system("PAUSE");
    return 0;
}
