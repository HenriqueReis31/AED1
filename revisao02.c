/*Faca uma funcao que receba a data atual (dia, mes e ano em inteiro) e exiba-a na tela no formato textual por extenso.*/
#include <stdio.h>
int validarData(int *dia, int *mes, int *ano);
void exibirDataPorExtenso(int *dia, int *mes, int *ano);

int main() {
    int dia, mes, ano;
    int resultado;
    
    printf("=== SISTEMA DE VALIDACAO E EXIBICAO DE DATAS ===\n");
    
    resultado = validarData(&dia, &mes, &ano);
    
    if (resultado == 1) {
        printf("\n=== RESULTADO ===\n");
        printf("Data no formato numerico: %02d/%02d/%04d\n", dia, mes, ano);
        printf("Data por extenso: ");
        exibirDataPorExtenso(&dia, &mes, &ano);
    } else {
        printf("\nData invalida! Programa encerrado.\n");
    }
    
    return 0;
}

int validarData(int *dia, int *mes, int *ano) {
    printf("\nDigite o dia (1 - 31): ");
    scanf("%d", dia);
    
    if (*dia < 1 || *dia > 31) {
        printf("Erro: Digite um dia valido (1-31)\n");
        return 0; 
    }

    printf("Digite o mes (1-12): ");
    scanf("%d", mes);

    if(*mes < 1 || *mes > 12){
        printf("Erro: Digite um mes valido (1-12)\n");
        return 0;
    }

    printf("Digite o ano: ");
    scanf("%d", ano);
    
    if (*ano < 0) {
        printf("Erro: Digite um ano valido (nao negativo)\n");
        return 0; 
    }

    // Validação de meses com 30 dias
    if((*mes == 4 || *mes == 6 || *mes == 9 || *mes == 11) && *dia > 30){
        printf("Erro: Este mes so tem 30 dias!\n");
        return 0;
    }

    // Validação de fevereiro
    if (*mes == 2) {
        // Verificação de ano bissexto
        int bissexto = 0;
        if (*ano % 4 == 0) {
            if (*ano % 100 == 0) {
                if (*ano % 400 == 0) {
                    bissexto = 1;
                }
            } else {
                bissexto = 1;
            }
        }
        
        if (bissexto) {
            if (*dia > 29) {
                printf("Erro: Fevereiro so tem 29 dias em anos bissextos!\n");
                return 0;
            }
        } else {
            if (*dia > 28) {
                printf("Erro: Fevereiro so tem 28 dias!\n");
                return 0;
            }
        }
    }

    return 1;  
}


void exibirDataPorExtenso(int *dia, int *mes, int *ano) {
    const char *meses[] = {
        "janeiro", "fevereiro", "março", "abril", "maio", "junho",
        "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"
 };
    
    printf("%d de %s de %d\n", *dia, meses[*mes - 1], *ano);
}