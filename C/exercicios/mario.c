#include <cs50.h>
#include <stdio.h>

// Funcoes
int get_height(void);
void make_tower(int n);

int main(void)
{
    // Prompt the height fo the tower
    int height = get_height();

    // Create the tower
    make_tower(height);
}

int get_height(void)
{
    int height;

    // Check if the heigth is greater than 0 and less than 9
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    return height;
}

void make_tower(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Defines the floor
        int andar = n - i;

        for (int j = 1; j < andar; j++)
        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
