//
//  main.cpp
//  projeto LB
//
//  Created by Lorena Barreto on 28/01/25.
//

#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

void registro() //função responsável por cadastrar os usuários no sistema
{
    //início da criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //responsável por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,"%s", cpf); //salvo o valor da variável
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //atualização e não criação
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,"%s", sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);
    
    system( "read -n 1 -s -p \"Pressione qualquer tecla para continuar...\"" ); //Responsável por pausar o sistema "pause" no windows
}

void consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo, não localizado! \n");
    }
    
    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    system( "read -n 1 -s -p \"Pressione qualquer tecla para continuar...\"" );
    
}

void deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL)
    {
        printf("O usuário não se encontra no sistema! \n");
        system( "read -n 1 -s -p \"Pressione qualquer tecla para continuar...\"" );
    }
}

int main(void)
{
    int opcao=0; //Definindo variáveis
    int laco=1;
    char senhadigitada[10]= "a";
    int comparacao;
    
    printf("### Cartório da EBAC ###\n\n");
    printf("Login de Administrador\n\nDigite a sua senha:");
    scanf("%s", senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");
    
    if (comparacao == 0)
    {
        system("clear");
        for (laco=1;(laco=1);)
        {
            
            system("clear");
            
            setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
            
            printf("### Cartório da EBAC ###\n\n"); //Início do menu
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n");
            printf("\t4 - Sair do sistema\n\n");
            printf("Opção: ");//Fim do menu
            
            scanf("%d", &opcao); //Armazenando a escolha do usuário
            
            system("clear"); //responsável por limpar a tela "cls" no windows
            
            switch (opcao) //Início da seleção
            {
                case 1:
                    registro(); //chamada de funções
                    break;
                    
                case 2:
                    consulta();
                    break;
                    
                case 3:
                    deletar();
                    break;
                    
                case 4:
                    printf("Obrigado por utilizar o sistema!\n");
                    return 0;
                    break;
                    
                default:
                    printf("Essa opção não está disponível!");
                    system( "read -n 1 -s -p \"Pressione qualquer tecla para continuar...\"" );
                    break;
            } //Fim da seleção
        }
    }
    
    else
        printf("Senha incorreta!\n\n");
        system( "read -n 1 -s -p \"Pressione qualquer tecla para continuar...\"" );
        system("clear");
        main();
}
