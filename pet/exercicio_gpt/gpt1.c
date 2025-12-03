#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    float nota;
}aluno;

int main(){
    aluno aluno1;
    printf("Nome do Aluno: ");
    fgets(aluno1.nome, 50, stdin);
    aluno1.nome[strcspn(aluno1.nome, "\n")]='\0';

    printf("Idade do Aluno: ");
    scanf("%d", &aluno1.idade);

    printf("Nota do Aluno: ");
    scanf("%f", &aluno1.nota);

    printf("\n==Dados do Aluno==\n");
    printf("Nome: %s\n", aluno1.nome);          
    printf("Idade: %d\n", aluno1.idade);
    printf("Nota: %.2f\n", aluno1.nota);

    return 0;
}