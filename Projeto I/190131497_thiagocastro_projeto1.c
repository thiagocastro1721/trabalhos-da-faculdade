/*
Algoritmos e Programação de Computadores - 2/2019
Aluno(a): Thiago Pereira de Castro
Matricula: 190131497
Turma: B
Versão do compilador:  gcc 7.4.0
Descricao: O programa converte numeros das bases 2, 8 e 16 para a base 10.
*/
#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    /*Declaracao de variaveis.*/
    int base = 1;
    char ParteInteira[16];
    char ParteFracionaria[6];
    char ParteInteiraSemVirgula[10];
    int TamanhoParteInteira = 0;
    int TamanhoParteInteiraSemVirgula = 0;
    int TamanhoParteFracionaria = 0;
    float dec_int = 0;
    float dec_int_sv = 0;
    float dec_frac = 0;
    int temp_int = 0;
    int temp_int_sv = 0;
    int temp_frac = 0;
    int i = 0;
    int j = 0;
    int num = 0;
    int aux = 0;
    int expoente = 0;
    int indice_da_virgula = 0;
    int numero_com_vigula = 0;
    int erro = 0;

    /*Orientacoes para o usuario.*/
    printf("Digite um numero para ser convertido para a base 10.\n\n");
    printf("O numero deve ser na forma NUMERO_BASE.\n\n");
    printf("A base devera ser 2, 8 ou 16.\n\n");
    printf("Digite _0 para encerrar o programa.\n\n");

    /*Se a base for zero o programa encerra.*/
    while(base!=0)
    {
        /*Zerando variaveis antes de cada loop*/
        erro = 0;
        dec_int = 0;
        dec_int_sv = 0;
        dec_frac = 0;
        numero_com_vigula = 0;

        printf("\n");

        /*Leitura da parte interira e da base*/
        scanf("%[^_]", ParteInteira);
        getchar();
        scanf("%d", &base);

        /*Mais uma condicional para garantir que os calculos nao sejam feitos com a base zero.*/
        if(base != 0)
        {

            /*testando se a base eh 2, 8 ou 16.*/
            if(base != 2 && base != 8 && base != 16)
            {
                printf("Erro. Base = %d. A base deve ser 2, 8 ou 16.\n", base);
                erro++;
            }


            /*Se houver virgula na parte inteira, entao o vetor ParteInteira sera dividido em dois outros: ParteInteiraSemVirgula e ParteFracionaria*/
            i = 0;
            j = 0;
            while(i < strlen(ParteInteira))
            {
                /*se a parte interira tiver vigula entao comecar separar a parte fracionaria.*/
                if(ParteInteira[i] == ',')
                {

                    /* for para separar a parte fracionaria.*/
                    numero_com_vigula = 1;
                    indice_da_virgula = i;
                    for(j = 0; j < 6; j++)
                    {
                        ParteFracionaria[j] = ParteInteira[i+1];
                        i++;
                    }

                    /*for para tirar parte fracionaria da inteira.*/
                    j = 0;
                    for(i = 0;i <= indice_da_virgula; i++)
                    {
                        ParteInteiraSemVirgula[j] = ParteInteira[i];
                        j++;
                        if(i >= indice_da_virgula)
                        {
                            ParteInteiraSemVirgula[i] = '\0';
                        }
                    }
                }
                    i++;
            }

            /*se numero nao tem vigula, entao calcular somente parte inteira.*/
            if(numero_com_vigula == 0)
            {
                /*inverter parte interia.*/
                TamanhoParteInteira = strlen(ParteInteira);
                temp_int = TamanhoParteInteira - 1;
                j = temp_int;
                for(i = 0; i < j; i++)
                {
                    aux = ParteInteira[i];
                    ParteInteira[i] = ParteInteira[j];
                    ParteInteira[j] = aux;
                    j--;
                }

                /*calcular parte inteira.*/
                for(i = 0; i <= temp_int; i++)
                {

                    /*regra para converter caracteres para numero inteiro.*/
                    num = 0;
                    if(ParteInteira[i] >= '0' && ParteInteira[i] <= '9')
                    {
                        num = ParteInteira[i] - 48;
                    }
                    else if (ParteInteira[i] >= 'A' && ParteInteira[i] <= 'Z')
                    {
                        num = ParteInteira[i] - 55;
                    }

                    if(num < base)
                    {
                        dec_int = dec_int + num * (pow(base,i));
                    }
                    else
                    {
                        printf("Erro. O caractere %c nao pertence a base %d.\n", ParteInteira[i], base);
                        erro++;
                    }

                }
                if(erro == 0)
                {
                    printf("dec = %f\n", dec_int);
                }

            }
            /*parte inteira com virgula.*/
            if(numero_com_vigula == 1)
            {
                /*inverter parte interia.*/
                TamanhoParteInteiraSemVirgula = strlen(ParteInteiraSemVirgula);
                temp_int_sv = TamanhoParteInteiraSemVirgula - 1;
                j = temp_int_sv;
                for(i = 0; i < j; i++)
                {
                    aux = ParteInteiraSemVirgula[i];
                    ParteInteiraSemVirgula[i] = ParteInteiraSemVirgula[j];
                    ParteInteiraSemVirgula[j] = aux;
                    j--;
                }

                /*calcular parte inteira.*/
                TamanhoParteInteiraSemVirgula = strlen(ParteInteiraSemVirgula);
                temp_int_sv = TamanhoParteInteiraSemVirgula - 1;
                for(i = 0; i < TamanhoParteInteiraSemVirgula; i++)
                {

                    /*regra para converter caracteres para numero inteiro.*/
                    num = 0;
                    if(ParteInteiraSemVirgula[i] >= '0' && ParteInteiraSemVirgula[i] <= '9')
                    {
                        num = ParteInteiraSemVirgula[i] - 48;
                    }
                    else if (ParteInteiraSemVirgula[i] >= 'A' && ParteInteiraSemVirgula[i] <= 'Z')
                    {
                        num = ParteInteiraSemVirgula[i] - 55;
                    }

                    if(ParteInteira[1] == ',' && ParteInteira[0] == '0')
                    {
                        dec_int_sv = 0;
                    }
                    else
                    {
                        if(num < base)
                        {
                            dec_int_sv = dec_int_sv + num * (pow(base,i));
                        }
                        else
                        {
                            printf("Erro. O caractere %c nao pertence a base %d.\n", ParteInteiraSemVirgula[i], base);
                            erro++;
                        }
                    }
                }


                /*calcular parte fracionaria.*/
                TamanhoParteFracionaria = strlen(ParteFracionaria);
                temp_frac = TamanhoParteFracionaria - 1;
                for(i = 0; i < TamanhoParteFracionaria; i++)
                {

                    /*regra para converter caracteres para numero inteiro.*/
                    num = 0;
                    if(ParteFracionaria[i] >= '0' && ParteFracionaria[i] <= '9')
                    {
                        num = ParteFracionaria[i] - 48;
                    }
                    else if (ParteFracionaria[i] >= 'A' && ParteFracionaria[i] <= 'Z')
                    {
                        num = ParteFracionaria[i] - 55;
                    }

                    expoente = (i + 1) * (-1);

                    if(num < base)
                    {
                        if(ParteInteira[indice_da_virgula] == ',' && ParteFracionaria[0] == '0')
                        {
                            dec_frac = 0;
                        }
                        else
                        {
                            dec_frac = dec_frac + num * (pow(base,expoente));
                        }

                    }
                    else
                    {
                        printf("Erro. O caractere %c nao pertence a base %d.\n", ParteFracionaria[i], base);
                        erro++;
                    }


                }

                if(erro == 0)
                {
                    dec_frac = dec_frac + dec_int_sv;
                    printf("dec = %f\n", dec_frac);
                }

            }

        }

    }
    return 0;
}
