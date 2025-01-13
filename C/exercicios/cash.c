#include <cs50.h>
#include <math.h>
#include <stdio.h>

int cont_moedas(int centavo);

int main(void)
{
    float troco;

    do
    {
        // Recebe o troco
        troco = get_float("Qual o troco? ");
    } while (troco < 0);

    // Converte o troco para centavos
    int centavo = round(troco * 100);

    int moeda = cont_moedas(centavo);

    printf("Quantidade de moedas necessárias para o troco: %i\n", moeda);
}

// Conta a quantidade de moedas para o troco
int cont_moedas(int centavo)
{
    int moeda = 0;

    while (centavo > 0)
    {
        if (centavo >= 25) // Se troco maior ou igual a $0.25
        {
            moeda++;
            centavo -= 25;
        }
        else if (centavo >= 10) // Se troco maior ou igual a $0.10
        {
            moeda++;
            centavo -= 10;
        }
        else if (centavo >= 5) // Se troco maior ou igual a $0.05
        {
            moeda++;
            centavo -= 5;
        }
        else // Se troco maior ou igual a $0.01
        {
            moeda++;
            centavo -= 1;
        }
    }

    // Retorna quantidade de moedas para o troco
    return moeda;
}
