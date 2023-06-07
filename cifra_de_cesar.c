#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(void)
{
    int opcao = 3, i, codigo;
    char mensagem[100];

    while (opcao != 0)
    {
        opcao = 3;
        codigo = 27;
        while (opcao != 0 && opcao != 1 && opcao != 2)
        {
            printf("* Escolha uma opcao: *\n"
                   "[0] - Sair \n"
                   "[1] - Criptografar \n"
                   "[2] - Descriptografar \n");
            scanf("%d", &opcao);
            while ((getchar()) != '\n');
        }

        if (opcao != 0)
        {
            printf("Digite a frase: ");
            scanf("%[^\n]s", mensagem);
            while ((getchar()) != '\n');
            
            while (codigo < 0 || codigo > 26)
            {
                printf("Digite o codigo: ");
                scanf("%d", &codigo);
                while ((getchar()) != '\n');
            }

            if (opcao == 1)
            {
                for (i = 0; i <= strlen(mensagem); i++)
                {
                    if (mensagem[i] >= 'a' && mensagem[i] <= 'z')
                    {
                        if (mensagem[i] + codigo > 'z')
                        {
                            mensagem[i] = mensagem[i] - 26 + codigo;
                        }
                        else
                        {
                            mensagem[i] += codigo;
                        }
                    }
                    else if (mensagem[i] >= 'A' && mensagem[i] <= 'Z')
                    {
                        if (mensagem[i] + codigo > 'Z')
                        {
                            mensagem[i] = mensagem[i] - 26 + codigo;
                        }
                        else
                        {
                            mensagem[i] += codigo;
                        }
                    }
                }
                printf("A mensagem e: %s\n", mensagem);
            }
            else
            {
                for (i = 0; i <= strlen(mensagem); i++)
                {
                    if (mensagem[i] >= 'a' && mensagem[i] <= 'z')
                    {
                        if (mensagem[i] - codigo < 'a')
                        {
                            mensagem[i] = mensagem[i] + 26 - codigo;
                        }
                        else
                        {
                            mensagem[i] -= codigo;
                        }
                    }
                    else if (mensagem[i] >= 'A' && mensagem[i] <= 'Z')
                    {
                        if (mensagem[i] - codigo < 'A')
                        {
                            mensagem[i] = mensagem[i] + 26 - codigo;
                        }
                        else
                        {
                            mensagem[i] -= codigo;
                        }
                    }
                }
                printf("A mensagem e: %s\n", mensagem);
            }
            getch();
        }
        else
        {
            printf("Processo finalizado!");
        }
    }
    return 0;
}