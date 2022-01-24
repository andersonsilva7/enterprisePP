#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>
#include <windows.h>
#define MAX 10

//  Anderson Silva

struct Funcionario {
    char nome[30];
    char cpf[11];
    int idade;
    float salario;
};
typedef struct Funcionario F;

int salFunc=0;

int menu () {
    int op;

    printf("\n=====Seja bem vindo à Empresa PP=====\n\n");
    printf("-----------Sistema Principal----------\n");
    printf("1-Novo funcionário\n2-Listar todos os funcionários\n");
    printf("3-Pesquisar um funcionário pelo CPF\n4-Excluir um funcionário \n");
    printf("5-Média dos salários dos funcionários\n6-Sair do sistema\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);

    return op;
}

void novoFuncionario (F funcionario[], int *cont) { 
    if ((*cont) == MAX) {
        printf("\nO banco de dados está cheio.\n");
    }
    else { 
        printf("Informe o nome: ");
        fflush(stdin);
        fgets(funcionario[*cont].nome, 30, stdin);

        printf("CPF: ");
        fflush(stdin);
        fgets(funcionario[*cont].cpf, 30, stdin);

        printf("Informe a idade: ");
        scanf("%d", &funcionario[*cont].idade);

        printf("Informe o salário: ");
        scanf("%f", &funcionario[*cont].salario);
        salFunc++;

        printf("\nFuncionário registrado com sucesso.\n");
            (*cont)++;
    }
}

void listarFuncionarios (F funcionario[], int cont) {
    int i;

    if (cont==0){
        printf("\nNão há nenhum funcionário registrado!\n");
    }   
    else {
        printf("Lista de todos os funcionários cadastrados:\n\n");
        for (i=0;i<cont;i++){
            printf("Nome: %s", funcionario[i].nome);
            printf("CPF: %s", funcionario[i].cpf);
            printf("Idade: %d\n", funcionario[i].idade);
            printf("Salário: %.2f\n", funcionario[i].salario);
        }        
    }
}

void pesquisarFuncionario (F funcionario[], int *cont) {
    int i,naotem=0;     
    char cpfBusca[11];

    if (*cont == 0) {
        printf("\nNão há nenhum funcionário registrado!\n");
    } 
    else {
    printf("Informe o CPF do Funcionário:");
    fflush(stdin);
    fgets(cpfBusca, 11, stdin);
        for(i=0;i<MAX;i++) {
            if (strcmp(cpfBusca, funcionario[i].cpf) == 0) {
                printf("\nFuncionário encontrado!\n");
                printf("\nNome: %s", funcionario[i].nome);
                printf("CPF: %s", funcionario[i].cpf);
                printf("Idade: %d\n", funcionario[i].idade);
                printf("Salário: %.2f\n", funcionario[i].salario);
                naotem = 1;
            }
        }
        if (naotem == 0)  {
            printf("\nO CPF não foi encontrado.\n");
        }
    } 
}

void excluirFuncionario(F funcionarios[], int *cont) {
    char cpf[11];
    int i, j, naotem=0;

    if ((*cont) == 0) {
        printf("\nNão há nenhum funcionário registrado!\n");
    } else {
        printf("Insira o CPF do funcionário que deseja excluir: ");
        fflush(stdin);
        fgets(cpf, 11, stdin);

        for(i=0; i < (*cont); i++) {
            if (strcmp(cpf, funcionarios[i].cpf) == 0) {
                for(j=i; j < (*cont)-1; j++) {
                    funcionarios[j] = funcionarios[j+1];
                }
                (*cont)--;
                printf("O funcionário foi excluido.\n");
                naotem=1;
                break;                   
            }            
        }
    }
}

float mediaSalario(F funcionarios[]) {
   float media=0, somaSalario=0;
   int i;

    if (salFunc==0){
        printf("\nNão há nenhum funcionário registrado!\n");
    }else {
        for(i=0; i < salFunc; i++) {
            somaSalario+=funcionarios[i].salario;
        }
    media=somaSalario/salFunc;               
    printf("A média dos salários dos funcionários é R$ %.2f", media,"\n");
    }
    return media;
}

main() {

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    F func[MAX];
    int opc, qtde=0;
    float media;

    do {
        opc = menu();

        switch (opc) {
        case 1:
            novoFuncionario(func, &qtde);
            break;

        case 2:
           listarFuncionarios(func, qtde);
            break;

         case 3 :
           pesquisarFuncionario(func, &qtde);
            break;

        case 4:
            excluirFuncionario(func, &qtde);
            break;

         case 5:            
            media=mediaSalario(func);
            break;

        case 6:
            printf("Saindo...\n\n");
            break;
        
        default:
             printf("Opção inválida !\n");
            break;
        }

    }while(opc!=6);    

}
