//Includes b�sicos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

//Principais defines
//Principais
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21

//Aritm�ticos
#define ADD 30
#define SUBSTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define MODULUS 34
#define POW 35

//Saltos
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

//Variaveis global

//Mem�ria em vetor
int memoria[100];
//Acumulador
int acumulador = 0;


//Fun��o de exibi��o
void dump(int contadorInstrucao, int registroInstrucao, int codigoOperacao, int operando){
    printf("Execu��o do programa \n");
    printf("*********************************************************************************************************\n ");
    printf("\n");
    printf("REGISTROS \n\n");
    printf("Acumulador: %d \n", acumulador);
    printf("Contador de intru��o: %d \n", contadorInstrucao);
    printf("Registro de Intru��o: %d \n", registroInstrucao);
    printf("Codigo de opera��o: %d \n", codigoOperacao);
    printf("Operando: %d \n\n\n\n", operando);
    printf("MEMORIA \n\n\n");

    //Contador2 auxiliar
    int contador2;

    //Coluna
    while(contador2 <= 9){
        printf("%11.2d", contador2);
        contador2++;
    }

    //Linha
    contador2 = 0;
    while(contador2 < 100){
        if(contador2 % 10==0){
            printf("\n%0.2d", contador2);
        }
        printf(" %10.4d", memoria[contador2]);
        contador2++;

    }

printf("\n");
system("pause");
}


//Fun��o de execu��o
void execucao(){


    //Comandos de imprimir
    //Contador
    int contador = 0;
    //Auxiliar
    int aux;
    //Contador i para iniciar o do while
    int i = 1;
    //Operando
    int operando = 0;
    //Codigo
    int codigo = 0;
    //Contador instru��o
    int contadorInstrucao = 0;
    //Codigo de opera��o
    int codigoOperacao = 0;
    //Registro de Instru��o
    int registroInstrucao = 0;
    //Auxiliar 2
    int aux2 = 0;

    //La�o de repeti��o enquanto i = 1
    do{
        //Auxiliar 2
        aux2 = 0;
        //Verifica o comando a direita e a esquerda do c�digo
        contadorInstrucao = contador;
        codigo = *(memoria+contador)/100;
        operando = *(memoria+contador)%100;

        //Corela��o de variaveis
        codigoOperacao = operando;
        registroInstrucao = codigo;


        //Estrutura condicional de casos
        switch(codigo){
            //Caso de Leitura
            case READ:
               while(aux2 == 0){
                printf("\nIntroduza o valor: ");
               scanf("%d", &aux);
               //Verifica se aux possui valor entre -9999 e 9999
               if( (aux >= -9999) && ( aux <= 9999) ){
                    *(memoria+operando) = aux;
                    contador++;
                    aux2 = 1;
               }
               else{
                    printf("Valor inv�lido! digite um valor v�lido");
               }
               }
               break;

            //Caso de escrita
            case WRITE:
                printf("\n\nWrite: %d\n", *(memoria+operando));
                contador++;
                break;

            //Caso de carregamento
            case LOAD:

                acumulador = *(memoria+operando);
                contador++;
                break;

            //Caso de armazenamento
            case STORE:
                *(memoria+operando) = acumulador;
                contador++;
                break;

            //Caso de adi��o
            case ADD:
                acumulador += *(memoria+operando);
                //Verifica se o acumulador possui valor entre -9999 e 9999
                if( !((acumulador >= -9999) && (acumulador <= 9999)) ){
                    printf("Erro fatal: Overflow no acumulador\n\n");
                    i = 0;
                }
                contador++;
                break;

            //Caso de subtra��o
            case SUBSTRACT:
                acumulador -= *(memoria + operando);
                //Verifica se o acumulador possui valor entre -9999 e 9999
                if( !((acumulador >= -9999) && (acumulador <= 9999)) ){
                    printf("Erro fatal: Overflow no acumulador\n\n");
                    i = 0;
                }
                contador++;
                break;

            //Caso divis�o
            case DIVIDE:
                //Ver se h� divis�o por zero
                if(*(memoria+operando) == 0){
                    printf("N�o pode fazer divis�o por 0");
                }
                acumulador /= *(memoria+operando);
                //Verifica se o acumulador possui valor entre -9999 e 9999
                if( !((acumulador >= -9999) && (acumulador <= 9999)) ){
                    printf("Erro fatal: Overflow no acumulador\n\n");
                    i = 0;
                }
                contador++;
                break;

            //Caso de multiplica��o
            case MULTIPLY:
                acumulador *= *(memoria+operando);
                //Verifica se o acumulador possui valor entre -9999 e 9999
                if( !((acumulador >= -9999) && (acumulador <= 9999)) ){
                    printf("Erro fatal: Overflow no acumulador\n\n");
                    i = 0;
                }
                contador++;
                break;

            //Caso m�dulo
            case MODULUS:
                if((acumulador<0) )
                {
                    acumulador *= (-1);
                     contador++;
                }
                else{
                    contador++;
                }

                break;

            //Caso potencia��o
            case POW:
                acumulador = pow(acumulador,*(memoria+operando)) ;
                //Verifica se o acumulador possui valor entre -9999 e 9999
                if( !((acumulador >= -9999) && (acumulador <= 9999)) ){
                    printf("Erro fatal: Overflow no acumulador\n\n");
                    i = 0;
                }
                contador++;
                break;

            //Caso de Branch, jump
            case BRANCH:
                 contador = operando;
                break;

            //Caso de Branch negativo, jump se negativo
            case BRANCHNEG:
                if(acumulador < 0){
                    contador = operando;
                } else contador++;
                break;

            //Caso de branch igual a zero, jump se igual a zero
            case BRANCHZERO:
                if(acumulador == 0){
                    contador = operando;
                } else contador++;
                break;

            //Caso fim
            case HALT:
                printf("Processo do simpletron finalizado \n\n");
                i = 0;
                break;

            //Caso fim sem sucesso
            default:
                printf("Operando inv�lido \n\n");
                i = 0;
                break;
        }
    }while (i == 1);
    //Chamar a fun��o de exibi��o
     dump(contadorInstrucao, registroInstrucao, codigoOperacao, operando);
}

//Fun��o principal
int main(){

        //Deixar o idioma em portugu�s
        setlocale(LC_ALL, "Portuguese");

        //Limpar memoria
        for(int i = 0; i < 100; i++){
        memoria[i] = 0;}

        //Tela de inicializa��o
        printf("*********************************************************************************************************\n ");
        printf("Bem vindo ao Simpletron! \n\n");
        printf("Por favor entre com um programa com dados a partir do arquivo:  \n");
        printf("Lembrando que -99999 encerra a leitura do seu programa, n�o lendo instru��es posteriores a ela\n\n");
        //Abre arquivo
        FILE *arquivo;
        arquivo = fopen("arquivo.txt", "r");

      /*Estrutura condicional verifica se o arquivo est� vazio ou n�o*/
        if(arquivo == NULL){
            printf("\n\nERRO: Sem texto para leitura\n\n");
        }
        //int contador auxiliar
        int contador = 0;
        while( fscanf(arquivo, "%d\n", &memoria[contador]) != EOF){
            printf("%d \n", memoria[contador] );
            //Quando instru��o � igual -99999 ele para de ler as posteriores
            if(memoria[contador] == -99999){
                    break;
            }
            contador++;

        }
        printf("\nCarregamento concluido, executando o programa...\n");
        printf("*********************************************************************************************************\n ");
        //Imprimi uma linha em branco
        printf("\n");

        //fechar arquivo
        fclose(arquivo);

        //Chama fun��o execu��o
        execucao();
}
