#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <string.h>

//colocar uma funcao de resto pro cont pra colocar um \n quando nao houver resto numa divisão por tres.
int ler_alterar_geral(FILE *arq, char nomearq[]){
	int posatu=0, posant=0, cont=1, i=0, j=0;
	float nota; //i=linhas, j=colunas;
	char resposta[10], novanota[10], registro[50];
	arq=fopen(nomearq, "r+");
	if (!arq) return 0;
	while (fscanf(arq, "%f", &nota) != EOF){
			printf("Nota %d: %.1f;\n\n", cont, nota);
			printf("Deseja alterar esta nota?\n(responda sim, nao ou fora*\n *-- para quando nao quiser mais alterar--)\n");
			scanf("%s", resposta);
			posant = posatu;		
			posatu = ftell(arq); // retorna a posição do arquivo em bytes
			if(resposta[0] == 's'){
				fseek(arq, posant, SEEK_SET);
				printf("Digite a nova nota:\n");
				scanf("%f", &nota);
				//if rest cont 3
				sprintf(novanota, "%.1f", nota); //transforma float em string
				fprintf(arq, "%s", novanota);
			}
			else if(resposta[0] == 'f'){
				break;
			}
		cont++;	
	}
	rewind(arq);
	cont=1;
	while (fscanf(arq, "%f", &nota) != EOF){
		printf("Nota %d: %.1f;\n", cont, nota);
		cont++;
	}
	fclose(arq);
	return 1;
}

#endif