#include <stdio.h>
#include "manipulacao.h"

int main(){
    FILE *arq;
    char nomearq [50];

    printf("Digite o nome do arquivo\n");
	gets(nomearq);

    medias(arq, nomearq);

    return 0;
}