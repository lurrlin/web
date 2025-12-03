#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{    //nesse formato agiliza na hora de declarar variaveis.
    char nome[50];
    int cod;
    int quantidade;
}Produto;

Produto CadastroEstoque(Produto p){
    getchar();

    printf("\nDigite o nome do produto: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")]='\0';

    printf("\nDigite o codigo do produto: ");
    scanf(" %d", &p.cod);

    getchar();

    printf("\nDigite a Quantidade em Estoque: ");
    scanf(" %d", &p.quantidade);

    printf("\nCadastro Completo!\n");

    return p;
}

Produto AtualizarEstoque(Produto p, int a, int q){
    if(a==1){
        p.quantidade=p.quantidade+q;
        printf("\nEstoque Atualizado!\n");
        printf("\n=============\n\n");
        return p;
    }
    else if(a==2){
        p.quantidade=p.quantidade-q;
        if(p.quantidade==0){
            printf("\nEstoque zerado!\n");
            printf("=============\n\n");
        }else if(p.quantidade<0){
            printf("\nErro! Estoque nao pode ser menos que 0!\n");
            printf("\n=============\n\n");
            p.quantidade=p.quantidade+q;
        }else{
            printf("\nEstoque Atualizado!\n");
            printf("\n=============\n\n");
        }
        return p;
    }
}

int main(){
    int n=0, op;
    int ad=0, escolha, qtt;
    Produto produtos[100];
    printf("Digite a Sua Opcao: \n");
    printf("=============\n\n");
    printf("[0] Sair \n");
    printf("SEM ESTOQUE\n");
    printf("[2] Cadastrar Produto \n");
    printf("SEM ESTOQUE\n");
    scanf(" %d", &op);
    while(op==1 || op==3 || op<0 || op>3){
        printf("OPCAO INVALIDA!\n");
        printf("Selecione novamente: \n");
        printf("[0] Sair \n");
        printf("SEM ESTOQUE\n");
        printf("[2] Cadastrar Produto \n");
        printf("SEM ESTOQUE\n");
        scanf(" %d", &op);
    }
    while(op!=0){
        switch(op){
            case 1:
                for(int i=0;i<n;i++){
                    printf("\nProduto: %d\n", i+1);
                    printf("\nNome: %s\n", produtos[i].nome);
                    printf("Codigo: %d\n", produtos[i].cod);
                    printf("Em Estoque: %d\n", produtos[i].quantidade);
                    printf("\n=============\n\n");
                }break;
            case 2:
                n++;
                printf("\n== Cadastre um produto ==\n");
                produtos[n-1]=CadastroEstoque(produtos[n-1]);
                printf("=============\n");
                break;
            case 3:
                printf("Selecione o Produto que deseja atualizar\n");
                for(int j=0;j<n;j++){
                    printf("Produto: %d\n", j+1);
                    printf("Nome: %s\n", produtos[j].nome);
                    printf("Em Estoque: %d\n", produtos[j].quantidade);
                    printf("=============\n");
                }
                printf("\nProduto: ");
                getchar();
                scanf(" %d", &escolha);
                while(escolha>n || escolha<=0){
                    printf("\nESCOLHA INVALIDA!\n");
                    scanf(" %d", &escolha);
                }
                printf("\n\n%s\n", produtos[escolha-1].nome);
                printf("Em Estoque: %d\n", produtos[escolha-1].quantidade);
                printf("\nQual e a acao desejada\n");
                printf("\n1-Adicionar Itens || 2-Remover Itens\n");
                scanf(" %d", &ad);
                while(ad<1 || ad>2){
                    printf("\nESCOLHA INVALIDA!\n");
                    scanf(" %d", &ad);
                }
                printf("\nDigite a quantidade\n");
                scanf(" %d", &qtt);
                produtos[escolha-1]=AtualizarEstoque(produtos[escolha-1], ad, qtt);
        }
        printf("Digite a Sua Proxima Operacao: \n");
        printf("[0] Sair \n");
        printf("[1] Consultar Estoque \n");
        printf("[2] Cadastrar Produto \n");
        printf("[3] Atualizar Produto \n");
        scanf(" %d", &op);
        while(op<0 || op>3){
            printf("OPCAO INVALIDA!\n");
            printf("Selecione novamente: \n");
            printf("[0] Sair \n");
            printf("[1] Consultar Estoque \n");
            printf("[2] Cadastrar Produto \n");
            printf("[3] Atualizar Produto \n");
            scanf(" %d", &op);
        }
    }
    printf("\n==== Programa Encerrando ====\n");
    return 0;
}
