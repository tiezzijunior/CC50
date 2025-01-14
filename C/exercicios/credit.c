#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool validar_credito(long credito);
int count_caracteres(long n);
string valid_amex(long credit);
string valid_mastercard(long credit);
string valid_visa(long credit, int leng);

int main(void)
{
    string tipo_credit;

    // Recebe o numero do Cartão
    long credito = get_long("Qual o número do Cartão? ");

    bool valid = validar_credito(credito);

    // Verifia se o numero do cartao é valido
    if (valid)
    {
        int num_char = count_caracteres(credito);

        if (num_char == 15) // Verifica se tem os numeros para o cartao American Express
        {
            tipo_credit = valid_amex(credito);
        }
        else if (num_char == 16) // Verifica se tem os numeros para o cartao MasterCard ou Visa
        {
            tipo_credit = valid_mastercard(credito);

            if (strcmp(tipo_credit, "INVALID") ==
                0) // Se nao for um MasterCard verificar se e um Visa
            {
                tipo_credit = valid_visa(credito, num_char);
            }
        }
        else if (num_char == 13) // Verifica se tem os numeros para o cartao Visa
        {
            tipo_credit = valid_visa(credito, num_char);
        }
        else // Se a quantidade de caracteres nao bate com nenhum cartao, retorna INVALID
        {
            tipo_credit = "INVALID";
        }
    }
    else
    {
        tipo_credit = "INVALID";
    }

    printf("%s\n", tipo_credit);
}

// Valida se é um cartão valido
bool validar_credito(long credito)
{
    int count_multi = 0;
    int count = 0;

    do
    {
        count += credito % 10;

        int num_count = ((credito % 100) / 10) * 2;

        if (num_count >= 10)
        {
            count_multi += num_count % 10;
            count_multi += num_count / 10;
        }
        else
        {
            count_multi += num_count;
        }

        credito = credito / 100;
    } while (credito != 0);

    int soma = count_multi + count;

    if (soma % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Conta a quantidade de caracteres do cartão
int count_caracteres(long n)
{

    int count = 0;

    do
    {
        count++;

        n = n / 10;
    } while (n != 0);

    return count;
}

// Valida se é um cartão American Express
string valid_amex(long credit)
{
    int inicio = credit / 10000000000000;

    if (inicio == 34 || inicio == 37)
    {
        return "AMEX";
    }
    else
    {
        return "INVALID";
    }
}

// Valida se é um cartão MasterCard
string valid_mastercard(long credit)
{
    int inicio = credit / 100000000000000;

    if (inicio == 51 || inicio == 52 || inicio == 53 || inicio == 54 || inicio == 55)
    {
        return "MASTERCARD";
    }
    else
    {
        return "INVALID";
    }
}

// Valida se é um cartão Visa
string valid_visa(long credit, int leng)
{
    int inicio;

    if (leng == 13)
    {
        inicio = credit / 1000000000000;
    }
    else
    {
        inicio = credit / 1000000000000000;
    }

    if (inicio == 4)
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}
