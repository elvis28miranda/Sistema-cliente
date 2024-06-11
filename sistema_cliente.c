#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

typedef struct dados
{
    char nome[20];
    char sobrenome[15];
    char depto[20];
    float salario;
    int idade;
    int telefone;
} CLIENTE;


void Inserir()
{
    char numstr[10];
    char resp;

    setlocale(LC_ALL, "Portuguese");
    system("cls");

    // tratando Arquivo

    FILE *fptr;

    CLIENTE fatec;

    fptr = fopen("ARQUIVO","ab");

    if (fptr == NULL)
    {
        printf("\n Erro na Abertura do Arquivo");
        system("pause");

    }
    else
    {

        do
        {

            system("cls");
            printf("\n ***********************************************");
            printf("\n ************* FATEC AMERICANA *****************");
            printf("\n ***************   CADASTRO   ******************");
            printf("\n ***********************************************");

            fflush(stdin);
            printf("\n Informe o Nome do Cliente: ");
            gets(fatec.nome);
            fflush(stdin);

            printf("\n Informe o Sobrenome do Cliente: ");
            gets(fatec.sobrenome);
            fflush(stdin);

            printf("\n Informe o Depto do Cliente: ");
            gets(fatec.depto);
            fflush(stdin);

            printf("\n Informe o Salario do Cliente: ");
            gets(numstr);
            fatec.salario=atof(numstr);
            fflush(stdin);


            printf("\n Informe a Idade do Cliente: ");
            gets(numstr);
            fatec.idade = atoi(numstr);
            fflush(stdin);

            printf("\n Informe o Telefone do Cliente: ");
            gets(numstr);
            fatec.telefone=atoi(numstr);
            fflush(stdin);

            // linha de gravação de escrita de dados no Arquivo
            fwrite(&fatec,sizeof(fatec),1,fptr);

            printf("\n Deseja continuar o Cadastro [S]im ou [N]ão: ");
            resp=getchar();
            resp=toupper(resp);

        }
        while (resp == 'S');


    }

    fclose(fptr);

}



void exibir()
{
    float tsal;
    tsal=0;
    FILE *fptr;

    setlocale(LC_ALL, "Portuguese");
    CLIENTE fatec;

    fptr = fopen("ARQUIVO", "rb");

    if (fptr == NULL)
    {
        printf("\n Erro na Abertura do Arquivo");
        system("pause");

    }
    else{

    system("cls");
    printf("\n ******************************************************");
    printf("\n ************* FATEC AMERICANA ************************");
    printf("\n ***************   CADASTRO   *************************");
    printf("\n Nome         \t Sobrenome          \t Depto            \t  Salario             \t Fone ");
    printf("\n ******************************************************");

    while(fread(&fatec,sizeof(fatec),1,fptr))
    {
        tsal+=fatec.salario;
        printf("\n %s        \t %s            \t %s          \t %.2f            \t %d", fatec.nome,fatec.sobrenome,fatec.depto,fatec.salario,fatec.telefone);

    }
    printf("\n ******************************************************");
    printf("\n *******************   TOTAL DE SALARIOS ===> %.2f",tsal);
    printf("\n ******************************************************");
    }
    printf("\n\n");
    system("pause");
    fclose(fptr);



}

void main()
{
    int op;

    setlocale(LC_ALL, "Portuguese");
    do
    {

        system("cls");
        printf("\n **************  MENU PRINCIPAL ***************");
        printf("\n     [ 1 ] - CADASTRO DE CLIENTE.              ");
        printf("\n     [ 2 ] - RELATÓRIO                         ");
        printf("\n     [ 3 ] - PESQUISA PELO SOBRENOME           ");
        printf("\n     [ 4 ] - ALTERAÇÃO                         ");
        printf("\n     [ 5 ] - REMOÇÃO                           ");
        printf("\n **********************************************");
        printf("\n Escolha a opção: ");
        scanf("%d",&op);
        fflush(stdin);

        switch(op)
        {
        case 1:
            Inserir();
            break;

        case 2 :
            exibir();
            break;
        case 3 :
            printf("\n Função a ser Desenvolvida");
            break;
        case 4:
            printf("\n Função a ser Desenvolvida");
            break;
        case 5:
            printf("\n Função a ser Desenvolvida");
            break;
        case 6:
            exit(0);
        default :
            printf("\n opção Invalida ... Tente Novamente");
            system("pause");
        }
    }
    while (op != 6);

}

