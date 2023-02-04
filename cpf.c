
//estefanio miko 21.2.9997
#include <stdio.h>

int validadorCpf(long long int cpf){
    long long int d1, d2, v1, v2, soma1 = 0, soma2 = 0, cpf2;
    d2 = cpf % 10;
    d1 = (cpf-d2)/10%10;
    cpf /= 100;
    cpf2 = cpf;

    // primeiro digito
    for (int i= 2; i <= 10; i++)
    {
        int x = cpf2 % 10;
        cpf2 = (cpf2 - x)/10;
        soma1 += i*x;
    }
    cpf = cpf*10 + d1;
    // segundo digito
    for (int i= 2; i <= 11; i++)
    {
        int x = cpf % 10;
        cpf = (cpf - x)/10;
        soma2 += i*x;
    }
    // verificaçao dos digitos
    v1 = (soma1 * 10)%11;
    v2 = (soma2 * 10)%11;
    if (v1 == 10)
        v1 = 0;
    if (v2 == 10)
        v2 = 0;
    if (v1 == d1 && v2 == d2)
        return 1;
    else
        return 0;
}
int main()
{
    int v;
    long long int cpf;
    printf("Digite o CPF: ");
    scanf("%lld", &cpf);

    v = validadorCpf(cpf);
    if (v)
        printf("\nVálido!");
    else
        printf("\nInválido!");
        
    return 0;
}