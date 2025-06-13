#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define TF 100

int main() {
    
    // Variáveis
    int opcaoMenuPrincipal, opcaoCadastro,vCod[TF],vQtde[TF],TLP = 0,vRG[TF],TLC = 0,opcaoRelatorio ;
    int cod, qtde, achou, i, j, rg, vendaExiste,TLV = 0,vQtdeV[TF],vCodV[TF],vRGV[TF], op ;
    char vProdServ[TF][50],produto[50], cliente[50],vCliente[TF][50] ;
    float vPreco[TF],vPrecoV[TF];
    printf("\n === MENU PRINCIPAL ===\n");
        printf("|   1-   Cadastrar     |\n");
        printf("|   2-   Excluir       |\n");
        printf("|   3-   venda         |\n");
        printf("|   4-   Relatorios    |\n");
        printf("|   5-   Finalizar     |\n");
        printf("|----------------------|\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoMenuPrincipal);
    while (op != 5) {
        switch (opcaoMenuPrincipal) {
            system("cls");
            case 1: // Cadastro
                printf("\n -------- Cadastro --------\n");
                printf("|   1 - Produtos/Servicos  |\n");
                printf("|   2 - Clientes           |\n");
                printf("|   3 - Retornar           |\n");
                printf("|--------------------------|\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &opcaoCadastro);

                switch (opcaoCadastro) {
                    case 1: // Produto
                        printf("Digite o codigo do produto: ");
                        scanf("%d", &cod);
                        printf("Digite o nome do Produto: ");
                        fflush(stdin);
                        gets(produto);
                        achou = 0;
                        i = 0;
                        while(i < TLP && achou == 0){
                        	if(stricmp(vProdServ[i],produto) == 0 || cod == vCod[i]){
                        		achou = 1;
                        	}
                        	i++;
                        }
                        
                        
                        if (achou == 1) {
                            printf("Produto ja cadastrado.\n");
                        } else {
                            vCod[TLP] = cod;
                            strcpy(vProdServ[TLP],produto);
                            printf("Digite a quantidade: ");
                            scanf("%d", &vQtde[TLP]);
                            printf("Digite o preco: ");
                            scanf("%f", &vPreco[TLP]);
                            TLP++;
                            printf("Produto cadastrado com sucesso.\n");
                        }
                        break;

                    case 2: // Cliente
                        printf("Digite o RG do cliente: ");
                        scanf("%d", &rg);
                        printf("Nome do cliente: ");
                        fflush(stdin);
                        gets(cliente);
                        achou = 0;
                        i = 0;
                        while(i < TLC && achou == 0){
                        	if(stricmp(vCliente[i],cliente) == 0 || rg == vRG[i] ){
                        		achou = 1;
                        	}
                        	i++;
                        }
                        if (achou == 1) {
                            printf("Cliente ja cadastrado.\n");
                        } else {
                            vRG[TLC] = rg;
                            strcpy(vCliente[TLC],cliente);
                            TLC++;
                            printf("Cliente cadastrado com sucesso.\n");
                        }
                        break;

                    case 3:
                        break;
                }
                break;

            case 2: // Exclusão
                printf("\n -------- Exclusao --------\n");
                printf("|       1 - Produto        |\n");
                printf("|       2 - Cliente        |\n");
                printf("|       3 - Venda          |\n");
                printf("|       4 - Retornar       |\n");
                printf("|--------------------------|\n");
                printf("Escolha uma das opcoes: ");
                scanf("%d", &opcaoCadastro);

                switch (opcaoCadastro) {
                    case 1: // Produto
                        printf("\nDigite o codigo do produto: ");
                        scanf("%d", &cod);
                        achou = 0;
                        i = 0;
                        while (i < TLP && achou == 0) {
                            if (vCod[i] == cod) achou = 1;
                            else i++;
                        }
                        if (achou == 0) {
                            printf("Produto nao encontrado.\n");
                        } else {
                            vendaExiste = 0;
                            j = 0;
                            while (j < TLV && vendaExiste == 0) {
                                if (vCodV[j] == cod) vendaExiste = 1;
                                j++;
                            }
                            if (vendaExiste == 1) {
                                printf("Produto nao pode ser excluido (ha vendas).\n");
                            } else {
                                for (j = i; j < TLP - 1; j++) {
                                    vCod[j] = vCod[j + 1];
                                    strcpy(vProdServ[j], vProdServ[j + 1]);
                                    vQtde[j] = vQtde[j + 1];
                                    vPreco[j] = vPreco[j + 1];
                                }
                                TLP--;
                                printf("Produto excluido.\n");
                            }
                        }
                        break;

                    case 2: // Cliente
                        printf("Digite o RG do cliente: ");
                        scanf("%d", &rg);
                        achou = 0;
                        i = 0;
                        while (i < TLC && achou == 0) {
                            if (vRG[i] == rg) achou = 1;
                            else i++;
                        }
                        if (achou == 0) {
                            printf("Cliente nao encontrado.\n");
                        } else {
                            vendaExiste = 0;
                            j = 0;
                            while (j < TLV && vendaExiste == 0) {
                                if (vRGV[j] == rg) vendaExiste = 1;
                                j++;
                            }
                            if (vendaExiste == 1) {
                                printf("Cliente nao pode ser excluido (ha vendas).\n");
                            } else {
                                for (j = i; j < TLC - 1; j++) {
                                    vRG[j] = vRG[j + 1];
                                    strcpy(vCliente[j], vCliente[j + 1]);
                                }
                                TLC--;
                                printf("Cliente excluido.\n");
                            }
                        }
                        break;

                    case 3: // Venda
                    	for (i = 0; i < TLV; i++) {
    						printf("Venda %d: Cliente RG %d - Produto %d - Qtde %d - Total %.2f\n",
          						 i, vRGV[i], vCodV[i], vQtdeV[i], vPrecoV[i]);
						}		
                        printf("Digite o indice da venda para excluir (0 a %d): ", TLV - 1);
                        scanf("%d", &i);
                        if (i >= 0 && i < TLV) {
                            for (j = i; j < TLV - 1; j++) {
                                vRGV[j] = vRGV[j + 1];
                                vCodV[j] = vCodV[j + 1];
                                vQtdeV[j] = vQtdeV[j + 1];
                                vPrecoV[j] = vPrecoV[j + 1];
                            }
                            TLV--;
                            printf("Venda excluida.\n");
                        } else {
                            printf("Indice invalido.\n");
                        }
                        break;

                    case 4:
                        break;
                }
                break;

            case 3: // Venda
                printf("Digite o RG do cliente: ");
                scanf("%d", &rg);
                achou = 0;
                i = 0;
                while (i < TLC && achou == 0) {
                    if (vRG[i] == rg) achou = 1;
                    else i++;
                }
                if (achou == 0) {
                    printf("Cliente nao cadastrado.\n");

                }

                printf("Digite o codigo do produto: ");
                scanf("%d", &cod);
                achou = 0;
                i = 0;
                while (i < TLP && achou == 0) {
                    if (vCod[i] == cod) achou = 1;
                    else i++;
                }
                if (achou == 0) {
                    printf("Produto nao cadastrado.\n");
                }

                printf("Digite a quantidade desejada: ");
                scanf("%d", &qtde);
                if (qtde <= vQtde[i]) {
                    vRGV[TLV] = rg;
                    vCodV[TLV] = cod;
                    vQtdeV[TLV] = qtde;
                    vPrecoV[TLV] = qtde * vPreco[i];
                    vQtde[i] -= qtde;
                    TLV++;
                    printf("Venda realizada com sucesso.\n");
                } else {
                    printf("Estoque insuficiente.\n");
                }
                break;

            case 4: // Relatórios
                printf("\n----Qual relatorio voce deseja:----");
                printf("\n|    1 - Produtos  |");
                printf("\n|    2 - Clientes  |");
                printf("\n|    3 - vendas    |");
                printf("\n|    4 - Todos     |");
                printf("\n|    5 - Voltar    |");
                printf("\n");
                scanf("%d",&opcaoRelatorio);
                while (opcaoRelatorio != 5)
                {
                    switch (opcaoRelatorio)
                    {
                    case 1:
                    printf("\n--- RELATORIOS ---\n");
                    printf("Produtos:\n");
                    for (i=0;i < TLP;i++) {
                        printf("%d - %s | Estoque: %d | Preco: %.2f\n", vCod[i], vProdServ[i], vQtde[i], vPreco[i]);
                    }
                        break;
                    case 2:
                        printf("\n--- RELATORIOS ---\n");
                        printf("\nClientes:\n");
                        for (i=0;i < TLC;i++) {
                            printf("%d - %s\n", vRG[i], vCliente[i]);
                        }
                        break;
                    case 3:
                        printf("\n--- RELATORIO ---\n");
                        printf("\nVendas:\n");
                        for (i=0;i < TLV;i++) {
                            printf("Cliente RG: %d | Produto: %d | Qtde: %d | Total: %.2f\n",
                            vRGV[i], vCodV[i], vQtdeV[i], vPrecoV[i]);
                        }
                        break;
                    case 4:
                        printf("\n--- RELATORIOS ---\n");
                        printf("Produtos:\n");
                        for (i=0;i < TLP;i++) {
                            printf("%d - %s | Estoque: %d | Preco: %.2f\n", vCod[i], vProdServ[i], vQtde[i], vPreco[i]);
                        }

                        printf("\nClientes:\n");
                        for (i=0;i < TLC;i++) {
                            printf("%d - %s\n", vRG[i], vCliente[i]);
                        }

                        printf("\nVendas:\n");
                        for (i=0;i < TLV;i++) {
                            printf("Cliente RG: %d | Produto: %d | Qtde: %d | Total: %.2f\n",
                            vRGV[i], vCodV[i], vQtdeV[i], vPrecoV[i]);
                        }
                        break;
                    case 5:
                        printf("\nRetornando...");
                        break;
                    default:
                        printf("\nOpcao invalida");
                        break;
                    }



                printf("\n----Qual relatorio voce deseja:----");
                printf("\n|    1 - Produtos  |");
                printf("\n|    2 - Clientes  |");
                printf("\n|    3 - vendas    |");
                printf("\n|    4 - Todos     |");
                printf("\n|    5 - Voltar    |");
                printf("\n");
                scanf("%d",&opcaoRelatorio);
                }
            case 5:
                printf("Finalizando programa.\n");

            default:
                printf("Opção invalida.\n");
                break;
        }
        printf("\n === MENU PRINCIPAL ===\n");
        printf("|   1-   Cadastrar     |\n");
        printf("|   2-   Excluir       |\n");
        printf("|   3-   venda         |\n");
        printf("|   4-   Relatorios    |\n");
        printf("|   5-   Finalizar     |\n");
        printf("|----------------------|\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoMenuPrincipal);
    }

    return 0;
}
