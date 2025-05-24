#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    /*
    int x, y, potencia;

    printf("insira o primeiro numero: ");
    scanf("%d", &x);
    printf("insira o segundo numero: ");
    scanf("%d", &y);
    potencia = pow(x,y);
    printf("o resultado de %d elevado a %d e: %d", x, y, potencia);
    */

    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade >= 18){
        printf("Pode entrar você é de maior idade");
    } else{
        printf("Não pode entrar você é de menor idade");
    }
}
