#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int idade;
    char nome[50];
    float altura;
}Pessoa;

int main() {
    Pessoa pessoas[10];
    
    for(int i=0; i<10; i++){
        printf("\n==Pessoa %d==\n", i+1);
        
        printf("Nome: ");
        fgets(pessoas[i].nome, 50, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")]='\0';
        
        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
        
        printf("Altura: ");
        scanf("%f", &pessoas[i].altura);
        
        getchar(); //limpar o enter (obrigado gepeteco)
    }
    printf("\n==Lista de Pessoas==\n");
    for(int j=0; j<10; j++){
        printf("Pessoa: %d\n", j+1);
        printf("  Nome: %s\n", pessoas[j].nome);
        printf("  Idade: %d\n", pessoas[j].idade);
        printf("  Altura: %.2f\n", pessoas[j].altura);
        printf("=========================================\n");
    }
    return 0;
}