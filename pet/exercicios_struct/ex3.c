#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int matricula;
    char curso[50];
}aluno;

void imprimedados(aluno p){
    printf("Nome: %s\n", p.nome);
    printf("Matricula: %d\n", p.matricula);
    printf("Curso: %s\n", p.curso);
}

int main(){
    
    aluno alunos[5];
    
    for(int i=0;i<5;i++){
        
        printf("\n==Insira os dados do Aluno %d==\n", i+1);
        
        printf("Nome: ");
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")]='\0';
        
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        
        printf("Curso: ");
        fgets(alunos[i].curso, 50, stdin);
        alunos[i].curso[strcspn(alunos[i].curso, "\n")]='\0';
        
    }
    printf("\n==Finalizada a Insercao==\n");
    
    for(int j=0;j<5;j++){
        printf("\nDados do Aluno %d==\n", j+1);
        imprimedados(alunos[j]);
    }
}