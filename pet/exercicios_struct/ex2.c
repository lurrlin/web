#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    char endereco[100];
}pessoa;

void mostrardados(pessoa p){
    printf("\n==Dados Informados==\n");
    printf("Nome: %s\nIdade: %d\nEndereco: %s\n", p.nome, p.idade, p.endereco);
}

int main(){
    pessoa pessoa1;
    printf("Digite seu Nome: ");
    fgets(pessoa1.nome, 50, stdin);
    pessoa1.nome[strcspn(pessoa1.nome, "\n")]='\0';
    
    getchar();
    
    printf("Digite sua idade:");
    scanf("%d", &pessoa1.idade);
    
    getchar();
    
    printf("Digite seu Endereco: ");
    fgets(pessoa1.endereco, 100, stdin);
    pessoa1.endereco[strcspn(pessoa1.endereco, "\n")]='\0';
    
    mostrardados(pessoa1);
}