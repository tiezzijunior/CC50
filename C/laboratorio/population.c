#include <cs50.h>
#include <stdio.h>

int controle(int start, int end);

int main(void)
{
    int start;
    int end;

    // Continua perguntando enquanto o valor for menor que 9
    do
    {
        start = get_int("Start Size: ");
    } while (start < 9);

    // Continua perguntando enquanto o valor for menor que start
    do
    {
        end = get_int("End Size: ");
    } while (end < start);

    // Calcula quantos anos demora para atingir a populacao esperada
    int years = controle(start, end);

    printf("Years: %i\n", years);
}

// Calcula o crescimento populacional
int controle(int population, int end)
{
    int years = 0;

    while (population < end)
    {
        population += (population / 3) - (population / 4);

        years++;
    }

    return years;
}
