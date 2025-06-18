#include <stdio.h>

char *mes[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

struct funcionariosVendas{
    int codVendedor;
    int codVenda;
    float valorVenda;
    int mes;
};

typedef struct funcionariosVendas loja;

int main() {
    int opcao;
    int tamanho = 4;
    loja funcionariosVendas[4];
    int numeroVendedor;
    int encontrouVendedor;
    int numeroMes;
    float somaVendas = 0;
    float maiorValor;
    int vendeuMais;
    float vendasPorMes[12] = {0};
    int mesVenda;
    float maiorvenda;
    int mesMaiorVenda = 0;


    printf("###################################  MENU ################################### \n");
    printf("1. Cadastrar vendedor. \n");
    printf("2. Cadastrar venda. \n");
    printf("3. Consultar as vendas de um funcionario em determinado mes. \n");
    printf("4. Consultar o total das vendas de determinado vendedor. \n");
    printf("5. Mostrar o numero do vendedor que mais vendeu em determinado mes. \n");
    printf("6. Mostrar o numero do mes com mais vendas. \n");
    printf("7. Finalizar o programa. \n");
    printf("############################################################################ \n");

    printf("\n");

    printf("DIgite uma das opcoes para prosseguir: ");
    scanf("%d", &opcao);

    while(opcao != 7){

        if(opcao >= 1 && opcao <= 7) {

            switch (opcao) {
                case 1:
                    for (int i = 0; i < tamanho; i++) {
                        encontrouVendedor = 0;

                        printf("Digite o codigo do vendedor para cadastrar: ");
                        scanf("%d", &funcionariosVendas[i].codVendedor);


                        for (int j = 0; j < i; j++) {
                            if (funcionariosVendas[i].codVendedor == funcionariosVendas[j].codVendedor) {
                                encontrouVendedor = 1;
                            }
                        }

                        if (encontrouVendedor == 1) {
                            printf("Esse vendedor ja foi cadastrado!\n");
                            i--;
                        }
                    }
                    break;

                case 2:
                    for (int i = 0; i < tamanho; i++) {
                        printf("Digite o codigo do vendedor: ");
                        scanf("%d", &funcionariosVendas[i].codVendedor);

                        printf("\n");

                        printf("Digite o mes que voce quer cadastrar essa venda: ");
                        scanf("%d", &funcionariosVendas[i].mes);

                        printf("\n");

                        encontrouVendedor = 0;

                        for (int j = 0; j < i; j++) {
                            if (funcionariosVendas[i].codVendedor == funcionariosVendas[j].codVendedor &&
                                funcionariosVendas[i].mes == funcionariosVendas[j].mes) {
                                encontrouVendedor = 1;
                            }
                        }

                        if (encontrouVendedor == 1) {
                            printf("ERRO: Já existe venda cadatrada para esse vendedor neste mes. \n");
                            i--;
                        } else {
                            printf("Digite o codigo da venda para cadastrar: ");
                            scanf("%d", &funcionariosVendas[i].codVenda);

                            printf("\n");

                            printf("Digite o valor da venda: R$");
                            scanf("%f", &funcionariosVendas[i].valorVenda);
                        }
                    }
                    break;

                case 3:
                    printf("Digite o numero do vendedor: ");
                    scanf("%d", &numeroVendedor);

                    printf("\n");

                    printf("Digite o numero do mes que deseja consultar: ");
                    scanf("%d", &numeroMes);

                    for (int i = 0; i < tamanho; i++) {
                        if (numeroVendedor == funcionariosVendas[i].codVendedor &&
                            numeroMes == funcionariosVendas[i].mes) {
                            printf("O funcionario do codigo %d, vendeu R$%0.2f", funcionariosVendas[i].codVendedor,
                                   funcionariosVendas[i].valorVenda);
                        }
                    }
                    break;

                case 4:
                    printf("Digite o numero do vendedor: ");
                    scanf("%d", &numeroVendedor);

                    somaVendas = 0.0f;

                    for (int i = 0; i < tamanho; i++) {
                        if (numeroVendedor == funcionariosVendas[i].codVendedor) {
                            somaVendas = somaVendas + funcionariosVendas[i].valorVenda;
                        }
                    }

                    printf("O total vendido pelo funcionario do codigo %d foi R$%0.2f", numeroVendedor, somaVendas);
                    break;

                case 5:
                    maiorValor = 0.0f;
                    vendeuMais = -1;

                    printf("Digite o numero do mes que deseja pesquisar: ");
                    scanf("%d", &numeroMes);

                    for (int i = 0; i < tamanho; i++) {
                        if (numeroMes == funcionariosVendas[i].mes) {
                            if (funcionariosVendas[i].valorVenda > maiorValor) {
                                maiorValor = funcionariosVendas[i].valorVenda;
                                vendeuMais = funcionariosVendas[i].codVendedor;
                            }
                        }
                    }

                    printf("O vendedor que mais vendeu tem o codigo: %d", vendeuMais);

                    break;

                case 6:
                    for (int i = 0; i < 12; i++) {
                        vendasPorMes[i] = 0.0f;
                    }

                    for (int i = 0; i < tamanho; i++) {
                        mesVenda = funcionariosVendas[i].mes;
                        if (mesVenda >= 1 && mesVenda <= 12) {
                            vendasPorMes[mesVenda - 1] = vendasPorMes[mesVenda - 1] + funcionariosVendas[i].valorVenda;
                        }
                    }

                    maiorvenda = vendasPorMes[0];

                    for (int i = 0; i < 12; i++) {
                        if (vendasPorMes[i] > maiorvenda) {
                            maiorvenda = vendasPorMes[i];
                            mesMaiorVenda = i;
                        }
                    }

                    printf("O mes com maior venda foi %s \n", mes[mesMaiorVenda]);
                    break;

                case 7:
                    printf("O programa esta sendo encerrado...");
                    return 0;
            }
        }

        printf("###################################  MENU ################################### \n");
        printf("1. Cadastrar vendedor. \n");
        printf("2. Cadastrar venda. \n");
        printf("3. Consultar as vendas de um funcionario em determinado mes. \n");
        printf("4. Consultar o total das vendas de determinado vendedor. \n");
        printf("5. Mostrar o numero do vendedor que mais vendeu em determinado mes. \n");
        printf("6. Mostrar o numero do mes com mais vendas. \n");
        printf("7. Finalizar o programa. \n");
        printf("############################################################################ \n");

        printf("\n");

        printf("Digite uma opcao para continuar: ");
        scanf("%d", &opcao);
    }

    return 0;
}