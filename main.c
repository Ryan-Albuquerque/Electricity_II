#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

#define a2 23.1

//2AE//
//Ryan da Silva Albuquerque//
//Leonard Euler Valente Feitosa//
//Victoria Souza Ramos//

int main()

{

    float r, x, v, p, i, b, a1, cossenoa1, P, Q, N, fp1, Q2, N2, cossenoa2, tangentea2, Qc, Xc, Cap;
    char correcao[3];
    int z, op;
    system("color 1F");
    while( z = 1)
    {
    printf("\n");
    printf("******ANALISE DE POTENCIA******\n");

    printf("    \n   |----------------------|");
    printf("    \n   |                      |");
    printf("    \n   |                      |");
    printf("    \n   |                      |");
    printf("  \n  Fonte                ZEQ=R+jX");
    printf("    \n   |                      |");
    printf("    \n   |                      |");
    printf("    \n   |                      |");
    printf("    \n   |----------------------| \n \n");

    printf("\nInforme o valor da resistencia em ohm(R):\n");
    scanf("%f", &r);

    printf("\nInforme o valor da reatancia em ohm(X):\n");
    scanf("%f", &x);

    printf("\nInforme o valor da tesao em volts(V):\n");
    scanf("%f", &v);

    //CALCULOS://


    //MODULO DA IMPEDANCIA//
    p = sqrt( pow(r,2)+ pow(x,2));

    //MODULO DA CORRENTE//
    i = v / p;

    //POTENCIA ATIVA//
    P = r * pow(i,2);

    //POTENCIA REATIVA OU IMAGINARIA//
    Q = x * pow(i,2) ;

    //POTENCIA APARENTE//
    N = sqrt( pow(P,2) + pow(Q,2) );

    //ARCO-TANGENTE DO ANGULO//
    b = x/r;

    //ANGULO DA IMPEDANCIA//
    a1 = atan(b) * 180 / 3.1415;

    //COSSENO DO ANGULO DA IMPEDANCIA//
    cossenoa1 = cos( a1 * 3.1415 / 180) ;

    //FATOR DE POTENCIA ANTES DA CORRECAO//
    fp1 = cossenoa1;


    printf("\n\n1) A Potencia Ativa e: %.2f W\n ",P);
    printf("\n2) A Potencia Reativa e: %.2f VAR\n ",Q);
    printf("\n3) A Potencia Aparente e: %.2f VA\n ",N);
    printf("\n4) O Fator de Potencia e: %.2f\n",fp1);

    printf("\n");
    printf("Lembre-se que a Agencia Nacional de Energia Eletrica(ANEEL) \ndetermina que o valor minimo do fator de potencia tem que ser de 0,92 \npara garantir a eficiencia energetica do circuito.\n\n");
    printf(" \nDeseja corrigir:(sim ou nao)\n\n");
    scanf("%s", &correcao);

    if(!strcmp(correcao, "sim") || !strcmp(correcao, "SIM") || !strcmp(correcao, "ss") || !strcmp(correcao, "s"))
    {
        //CALCULOS://

        //FATOR DE POTENCIA APOS A CORRECAO//
        cossenoa2 = cos( a2 * 3.1415 / 180) ;

        //TANGENTE DO ANGULO APOS A CORRECAO
        tangentea2 = tan( a2 * 3.1415 / 180) ;

        //POTENCIA REATIVA APOS A CORRECAO//
        Q2 = P * tangentea2;

        //POTENCIA APARENTE APOS A CORRECAO
        N2 = P / cossenoa2;

        // POTENCIA REATIVA EM CIMA DO CAPACITOR//
        Qc = Q - Q2;

        // VALOR DO CAPACITOR EM OHMS//
        Xc = pow(v,2) / Qc;

        //VALOR NOMINAL DO CAPACITOR//
        Cap = pow(2 * 3.1415 * 60 * Xc, -1);

    printf("    \n   |-----------|-------------|");
    printf("    \n   |           |             |");
    printf("    \n   |           |             |");
    printf("    \n   |           |             |");
    printf("  \n  Fonte       Capacitor    ZEQ=R+jX");
    printf("    \n   |           |             |");
    printf("    \n   |           |             |");
    printf("    \n   |           |             |");
    printf("    \n   |-----------|-------------| \n \n");

        printf("\n\n1) A Potencia Ativa apos a correcao  e: %.2f W\n",P);
        printf("\n2) A Potencia Reativa apos a correcao e: %.2f VAR\n",Q2);
        printf("\n3) A Potencia Aparente apos a correcao e: %.2f VA\n",N2);
        printf("\n4) O Fator de Potencia apos a correcao e: %.2f\n",cossenoa2);
        printf("\n5) O Capacitor necessario para a correcao sera de: %.3e F\n", Cap);

    }

     if(!strcmp(correcao, "nao") || !strcmp(correcao, "NAO") || !strcmp(correcao, "nn") || !strcmp(correcao, "n"))
    {
       printf(" \nAte a proxima :)");
       printf("\n");
       printf("\n");
    }
    printf("\n");
    printf("\n");
    system("pause");
    system("cls");

    printf("\nDigite 1 para fazer outra simulacao: \n\nDigite 2 para sair:\n");
    scanf("%d", &op);

    if(op==1)
    {
        z == 1;
    }
    if(op==2)
    {
        printf("\nObrigado!\nTchau!\n");
        return 0;
    }
     system("cls");
    }
}
