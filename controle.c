#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define numFunc 5

typedef struct{

    int codigo;
    char nome[30];
    float salario;
}tpdados;

void LerDados (tpdados cadfunc[]){
    int i;
    for(i=0;i<numFunc;i++){
        printf("\nDigite o nome do funcionario: ");
        scanf("%s",cadfunc[i].nome);
        fflush(stdin);
        printf("Digite o codigo do funcionario: ");
        scanf("%i",&cadfunc[i].codigo);
        fflush(stdin);
        printf("Digite o salario do funcionario: ");
        scanf("%f",&cadfunc[i].salario);
        fflush(stdin);
    }
}

void Mostrar (tpdados cadfunc[]){
    int i;
    for(i=0;i<numFunc;i++){
    printf("\nNOME:%s",cadfunc[i].nome);
    printf("\nCODIGO:%i",cadfunc[i].codigo);
    printf("\nSALARIO:R$%.2f\n",cadfunc[i].salario);
    }
}

void CalcMedia (tpdados cadfunc[]){
    float media = 0;
    int i;
    for(i=0;i<numFunc;i++)
        media= media + cadfunc[i].salario;
        media= media/numFunc;
        printf("\nA MEDIA ENTRE OS SALARIOS DOS FUNCIONARIOS E DE:R$%.2f\n",media);
}

float MaiorSalario (tpdados cadfunc[]){

    float maior = 0;
    for (int i=0;i<numFunc;i++){
    if (cadfunc[i].salario>maior)
        maior=cadfunc[i].salario;
    }
    return maior;
}

float MenorSalario (tpdados cadfunc[]){
    float menor = 99999;
    for ( int i=0;i<numFunc;i++){
        if (menor>cadfunc[i].salario)
            menor=cadfunc[i].salario;
    }
    return menor;
}

void MaiorMenor (tpdados cadfunc[]){
    float maior = 0,menor = 0;
    maior = MaiorSalario(cadfunc);
    menor = MenorSalario(cadfunc);
    printf("O MAIOR SALARIO E DE R$:%.2f\n",maior);
    printf("O MENOR SALARIO E DE R$:%.2f\n",menor);
}

void Ajuste (tpdados cadfunc[]){

int i;
float porc,n,novosalario;

printf("Digite a porcentagem a ser ajustada: ");
scanf("%f",&n);
porc = n/100.0;
if (n>100){
        printf("VALOR INVALIDO!!!\n\n");
        return Ajuste(cadfunc);
}
if (n<=100){
for (i=0;i<numFunc;i++){
    novosalario = cadfunc[i].salario*porc;
    cadfunc[i].salario = cadfunc[i].salario+novosalario;
    }
printf("O AJUSTE DE %.2f POR CENTO FOI FEITO!!!!!\n",n);
        }
    }


void Menu (tpdados cadfunc[]){
    int m; //Variavel de interação do menu
    printf("\n\n_____________________________________________________________________________________________________________\n\n");
    printf("                                                   MENU                                         \n\n");
    printf("DIGITE 1 PARA DIGITAR AS INFORMACOES DOS 5 USUARIOS\n");
    printf("DIGITE 2 PARA EXIBIR AS INFORMACOES NA TELA\n");
    printf("DIGITE 3 PARA MOSTRAR A MEDIA SALARIAL NA TELA\n");
    printf("DIGITE 4 PARA INFORMAR O MENOR E O MAIOR SALARIO\n");
    printf("DIGITE 5 PARA FAZER AJUSTE SALARIAL\n");
    printf("OU DIGITE 6 PARA SAIR\n");
    printf("\n\n_____________________________________________________________________________________________________________\n\n");
    scanf("%i",&m);
    fflush(stdin);

    if (m<6){
    switch (m){
    case 1:
        LerDados(cadfunc);
        return  Menu(cadfunc);
    case 2:
        Mostrar(cadfunc);
        return Menu(cadfunc);
    case 3:
        CalcMedia(cadfunc);
        return Menu(cadfunc);
    case 4 :
        MaiorMenor(cadfunc);
        return Menu(cadfunc);

    case 5 :
        Ajuste(cadfunc);
        return Menu(cadfunc);
        };
    }
    else if (m>6){
        printf("\nOPERACAO INVALIDA\n");
        return Menu(cadfunc);
    }
    else
        printf("                                                    ATE LOGO!!!!\n\n\n\n");
}

int main(){
    printf("                                    PROGRAMA PARA GERENCIAMENTO DE FUNCIONARIOS\n");
    tpdados cadfunc[numFunc];
    Menu(cadfunc);
}