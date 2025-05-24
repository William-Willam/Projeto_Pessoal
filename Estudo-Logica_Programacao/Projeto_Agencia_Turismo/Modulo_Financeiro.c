#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // UTF-8
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif

    // Controle Geral
    int opcaoMenu, opcaoPagamento, opcaoControle, opcaoRelatorio, i;

    // Compras
    char nomeCompra[10][50];
    int qtdCompra[10];
    float valorCompra[10];
    int totalCompra = 0;
    float totalValorCompra = 0;

    // Pagamentos
    char nomePagamento[10][50];
    int qtdPagamento[10];
    float valorPagamento[10];
    int totalPagamento = 0;
    float totalValorPagamento = 0;

    // Caixa
    char nomeEntrada[10][50], nomeSaida[10][50];
    float entradasCaixa[10], saidasCaixa[10];
    int totalEntrada = 0, totalSaida = 0;

    do
    {
        system("cls || clear");
        printf("=============== Destino Certo ==================\n");
        printf("============ Menu Principal ====================\n");
        printf("1 - Área de Pagamento\n");
        printf("2 - Controle de Caixa\n");
        printf("3 - Relatórios Financeiros\n");
        printf("0 - Sair\n");
        printf("===============================================\n");
        printf("Escolha o índice: ");
        scanf("%d", &opcaoMenu);
        getchar();

        if (opcaoMenu == 1)
        {
            do
            {
                system("cls || clear");
                printf("============ Menu de Pagamento ==============\n");
                printf("1 - Registrar Compras\n");
                printf("2 - Listar Compras\n");
                printf("3 - Registrar Pagamentos\n");
                printf("4 - Listar Pagamentos\n");
                printf("5 - Movimentação de Compras e Pagamentos\n");
                printf("0 - Voltar ao Menu\n");
                printf("=============================================\n");
                printf("Escolha o índice: ");
                scanf("%d", &opcaoPagamento);
                getchar();

                if (opcaoPagamento == 1)
                {
                    system("cls || clear");
                    if (totalCompra < 10)
                    {
                        printf("Digite o nome da compra: ");
                        fgets(nomeCompra[totalCompra], sizeof(nomeCompra[totalCompra]), stdin);
                        nomeCompra[totalCompra][strcspn(nomeCompra[totalCompra], "\n")] = '\0';
                        printf("Digite a quantidade de unidades: ");
                        scanf("%d", &qtdCompra[totalCompra]);
                        printf("Digite o valor total da compra: ");
                        scanf("%f", &valorCompra[totalCompra]);
                        getchar();
                        totalValorCompra += valorCompra[totalCompra];
                        totalCompra++;
                        printf("Compra registrada com sucesso!\n");
                    }
                    else
                    {
                        printf("Limite de compras atingido.\n");
                    }
                    system("pause");
                }
                else if (opcaoPagamento == 2)
                {
                    system("cls || clear");
                    printf("=== Lista de Compras ===\n");
                    if (totalCompra == 0)
                    {
                        printf("Nenhuma compra registrada.\n");
                    }
                    else
                    {
                        for (i = 0; i < totalCompra; i++)
                        {
                            printf("%d. %s - Quantidade: %d - Valor: R$ %.2f\n", i + 1, nomeCompra[i], qtdCompra[i], valorCompra[i]);
                        }
                    }
                    system("pause");
                }
                else if (opcaoPagamento == 3)
                {
                    system("cls || clear");
                    if (totalPagamento < 10)
                    {
                        printf("Digite o nome do pagamento: ");
                        fgets(nomePagamento[totalPagamento], sizeof(nomePagamento[totalPagamento]), stdin);
                        nomePagamento[totalPagamento][strcspn(nomePagamento[totalPagamento], "\n")] = '\0';
                        printf("Digite a quantidade de unidades pagas: ");
                        scanf("%d", &qtdPagamento[totalPagamento]);
                        printf("Digite o valor do pagamento: ");
                        scanf("%f", &valorPagamento[totalPagamento]);
                        getchar();
                        totalValorPagamento += valorPagamento[totalPagamento];
                        totalPagamento++;
                        printf("Pagamento registrado com sucesso!\n");
                    }
                    else
                    {
                        printf("Limite de pagamentos atingido.\n");
                    }
                    system("pause");
                }
                else if (opcaoPagamento == 4)
                {
                    system("cls || clear");
                    printf("=== Lista de Pagamentos ===\n");
                    if (totalPagamento == 0)
                    {
                        printf("Nenhum pagamento registrado.\n");
                    }
                    else
                    {
                        for (i = 0; i < totalPagamento; i++)
                        {
                            printf("%d. %s - Quantidade: %d - Valor: R$ %.2f\n", i + 1, nomePagamento[i], qtdPagamento[i], valorPagamento[i]);
                        }
                    }
                    system("pause");
                }
                else if (opcaoPagamento == 5)
                {
                    system("cls || clear");
                    printf("======= MOVIMENTAÇÃO DE COMPRAS E PAGAMENTOS =======\n");
                    printf("-- Compras --\n");
                    for (i = 0; i < totalCompra; i++)
                    {
                        printf("%d.%s \n", i + 1, nomeCompra[i]);
                        printf("Quantidade: %d\n", qtdCompra[i]);
                        printf("Valor: R$ %.2f\n", valorCompra[i]);
                        //printf("%d. %s - Quantidade: %d - Valor: R$ %.2f\n", i + 1, nomeCompra[i], qtdCompra[i], valorCompra[i]);
                    }
                    printf("-- Pagamentos --\n");
                    for (i = 0; i < totalPagamento; i++)
                    {
                        printf("%d.%s \n", i + 1, nomePagamento[i]);
                        printf("Quantidade: %d\n", qtdPagamento[i]);
                        printf("Valor: R$ %.2f\n", valorPagamento[i]);
                        //printf("%d. %s - Quantidade: %d - Valor: R$ %.2f\n", i + 1, nomePagamento[i], qtdPagamento[i], valorPagamento[i]);
                    }
                    printf("Movimentação de Compras e Pagamento: R$ %.2f\n", totalValorPagamento - totalValorCompra);
                    system("pause");
                }
            } while (opcaoPagamento != 0);
        }
        else if (opcaoMenu == 2)
        {
            do
            {
                system("cls || clear");
                printf("=========== Menu de Controle de Caixa ===========\n");
                printf("1 - Registrar Entrada\n");
                printf("2 - Registrar Saída\n");
                printf("3 - Exibir Saldo do Caixa\n");
                printf("0 - Voltar ao Menu Principal\n");
                printf("=================================================\n");
                printf("Escolha o índice: ");
                scanf("%d", &opcaoControle);
                getchar();

                if (opcaoControle == 1)
                {
                    if (totalEntrada < 10)
                    {
                        printf("Digite o nome da entrada: ");
                        fgets(nomeEntrada[totalEntrada], sizeof(nomeEntrada[totalEntrada]), stdin);
                        nomeEntrada[totalEntrada][strcspn(nomeEntrada[totalEntrada], "\n")] = '\0';
                        printf("Digite o valor da entrada: ");
                        scanf("%f", &entradasCaixa[totalEntrada]);
                        getchar();
                        totalEntrada++;
                        printf("Entrada registrada com sucesso!\n");
                    }
                    else
                    {
                        printf("Limite de entradas atingido.\n");
                    }
                    system("pause");
                }
                else if (opcaoControle == 2)
                {
                    if (totalSaida < 10)
                    {
                        printf("Digite o nome da saída: ");
                        fgets(nomeSaida[totalSaida], sizeof(nomeSaida[totalSaida]), stdin);
                        nomeSaida[totalSaida][strcspn(nomeSaida[totalSaida], "\n")] = '\0';
                        printf("Digite o valor da saída: ");
                        scanf("%f", &saidasCaixa[totalSaida]);
                        getchar();
                        totalSaida++;
                        printf("Saída registrada com sucesso!\n");
                    }
                    else
                    {
                        printf("Limite de saídas atingido.\n");
                    }
                    system("pause");
                }
                else if (opcaoControle == 3)
                {
                    float saldo = 0;
                    printf("Saldo atual do Caixa: \n");
                    for (i = 0; i < totalEntrada; i++)
                    {
                        printf("Entrada: %s - R$ %.2f\n", nomeEntrada[i], entradasCaixa[i]);
                        saldo += entradasCaixa[i];
                    }
                    for (i = 0; i < totalSaida; i++)
                    {
                        printf("Saída: %s - R$ %.2f\n", nomeSaida[i], saidasCaixa[i]);
                        saldo -= saidasCaixa[i];
                    }
                    printf("Saldo final: R$ %.2f\n", saldo);
                    system("pause");
                }
            } while (opcaoControle != 0);
        }
        else if (opcaoMenu == 3)
        {
            do
            {
                system("cls || clear");
                printf("=========== Menu de Relatório Financeiro ===========\n");
                printf("1 - Total de Compras\n");
                printf("2 - Total de Pagamentos\n");
                printf("3 - Total Entradas no Caixa\n");
                printf("4 - Total Saídas do Caixa\n");
                printf("5 - Relatório Geral\n");
                printf("0 - Voltar ao Menu\n");
                printf("=====================================================\n");
                printf("Escolha o índice: ");
                scanf("%d", &opcaoRelatorio);
                getchar();

                if (opcaoRelatorio == 1)
                {
                    printf("Total de Compras: R$ %.2f\n", totalValorCompra);
                    system("pause");
                }
                else if (opcaoRelatorio == 2)
                {
                    printf("Total de Pagamentos: R$ %.2f\n", totalValorPagamento);
                    system("pause");
                }
                else if (opcaoRelatorio == 3)
                {
                    float total = 0;
                    for (i = 0; i < totalEntrada; i++)
                    {
                        total += entradasCaixa[i];
                    }
                    printf("Entradas no Caixa: R$ %.2f\n", total);
                    system("pause");
                }
                else if (opcaoRelatorio == 4)
                {
                    float total = 0;
                    for (i = 0; i < totalSaida; i++)
                    {
                        total += saidasCaixa[i];
                    }
                    printf("Saídas do Caixa: R$ %.2f\n", total);
                    system("pause");
                }
                else if (opcaoRelatorio == 5)
                {
                    float totalEntradas = 0, totalSaidas = 0;
                    for (i = 0; i < totalEntrada; i++)
                        totalEntradas += entradasCaixa[i];
                    for (i = 0; i < totalSaida; i++)
                        totalSaidas += saidasCaixa[i];

                    printf("=========== RELATÓRIO GERAL ===========\n");
                    printf("Compras: R$ %.2f\n", totalValorCompra);
                    printf("Pagamentos: R$ %.2f\n", totalValorPagamento);
                    printf("Saldo Financeiro: R$ %.2f\n", totalValorPagamento - totalValorCompra);
                    printf("Saldo em Caixa: R$ %.2f\n", totalEntradas - totalSaidas);
                    printf("Nota Fiscal Exemplo: #NF123456789\n");
                    printf("Emitido em: 21/05/2025\n");
                    printf("=======================================\n");
                    system("pause");
                }
            } while (opcaoRelatorio != 0);
        }
    } while (opcaoMenu != 0);

    return 0;
}
