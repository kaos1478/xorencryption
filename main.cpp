#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    int op = 1;//Operador para escolha
    char arquivo1[20],arquivo2[20],key[100]; //declaracao dos arquivos e chave
    char *chave; //declara ponteiro chave
    int c; //inteiro que ira indexar a chave
    while (op != 0){
        //Apresentacao do MENU
        system("cls");
        system("color 02");
        printf("\n\n\tBem vindo(a) ao aplicativo PANDORA de CRIPTOGRAFIA\n\n\tOque deseja fazer?\n\n\t\t1 - Criptografar e Descriptografar\n\t\t2 - Ler Manual de instrucoes\n\t\t0 - Sair\n\n\tInforme a opcao desejada --> ");
        scanf("%d",&op);
        setbuf(stdin,NULL);
        //Fim Apresentacao do MENU
        //Inicio do tratamendo da opcao desejada
        switch (op){
        case 1:
            system("cls");
            printf("\n\n\t\t\t\t\t\tMENU DE CRIPTOGRAFIA PANDORA\n\n\n");
            printf("\tInforme o arquivo PRIMARIO e sua extensao!\n\n\tCaso o arquivo ja esteja criptografado e a senha seja a mesma\n\tque a utilizada para criptografar o processo sera revertido!\n\n\tExemplo: teste.txt (Arquivo que sera criptografado ou descriptografado!)\n\n\t --> ");
            gets(arquivo1);
            system("cls");
            printf("\n\n\t\t\t\t\t\tMENU DE CRIPTOGRAFIA PANDORA\n\n\n");
            printf("\tInforme o arquivo SECUNDARIO e sua extensao!\n\n\t(Arquivo resultante da criptografia ou descriptografia do arquivo PRIMARIO)\n\n\tExemplo: testedescriptografado.txt\n\n\t --> ");
            gets(arquivo2);
            system("cls");
            printf("\n\n\t\t\t\t\t\tMENU DE CRIPTOGRAFIA PANDORA\n\n\n");
            printf("\tInforme a senha para criptografar ou descriptografar\n\n\tExemplo: abcde \n\n\t --> ");
            gets(key);
            system("cls");
            //Fim do tratamendo
            //Inicio do codigo de Criptografia/Descriptografia
            chave = key; // chave recebendo a key
            if (*chave != '\0'){//certifica que o ponteiro nao esta nulo
                FILE *arq1 = fopen(arquivo1,"rb");//abre o arquivo primario no modo de leitura binario
                if (arq1 != NULL){//verifica se o arquivo existe
                    FILE *arq2 = fopen(arquivo2,"wb");//abre o arquivo secundario no modo de gravacao binaria
                    if (arq2 != NULL) { //se o argumento do arquivo secundario for digitado
                        while ((c=getc(arq1))!=EOF){//obtem char ate o fim do arquivo
                            if(!*chave) chave=key;//referenciou o ponteiro da chave usando key
                            c ^= *(chave++);//usa a operacao xor nos caracteres do arquivo 1 e da chave
                            putc(c,arq2);//inclui o caracter no arquivo criptografado
                        }
                        fclose(arq2);//fecha o arquivo secundario
                    }
                    fclose(arq1);//fecha o arquivo primario
                    printf("\n\n##################");
                    printf("\n##\tSUCESSO\t##");
                    printf("\n##################\n\n");
                    system("pause");
                }else{
                    printf("\n\n##################################################");
                    printf("\n##\tArquivo primario nao encontrado!\t##");
                    printf("\n##################################################\n\n");
                    system("pause");
                }
            }
            break;
            //Fim do codigo de criptografia
            //Inicio da apresentacao das intrucoes
        case 2:
            system("cls");
            printf("\n\n\t\t\t\t\tInstrucoes, Como utilizar o aplicativo:\n\n\n\n\tPrimeiramente coloque o arquivo que deseja criptografar ou descriptografar na mesma pasta que o aplicativo.");
            printf("\n\n\tCaso o arquivo primario seja o criptografado e a chave seja a mesma que fora utilizada na hora da criptografia o programa ira reverter o processo(descriptografar).");
            printf("\n\n\t Arquivo Primario = Arquivo de ENTRADA (Arquivo que deseja criptografar ou descriptografar!)");
            printf("\n\t Arquivo Secundario = Arquivo de SAIDA (Arquivo resultante da criptografia ou descriptografia!)");
            printf("\n\n\n\n\t\t\t\t1 - Voltar ao menu principal\t\t0 - Sair");
            printf("\n\n\n\n\n\n\tInforme a opcao desejada --> ");
            scanf("%d",&op);
            setbuf(stdin,NULL);
            break;
            //Fim do apresentacao das intrucoes
        case 0:
            break;
        }
    }
return 1;
}
