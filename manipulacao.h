#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <string.h>

//colocar uma funcao de resto pro cont pra colocar um \n quando nao houver resto numa divisão por tres.
int medias(FILE *arq, char nomearq[]){
	int cont=1, cont2=0, posinicial=0;
	float nota, acumulador, media, maior_media=0.0, menor_media=1000000.0;
	char registro[50], pessoamaiormedia[20], pessoamenormedia[20], pessoa[20];
	arq=fopen(nomearq, "r+");
	if (!arq) return 0;
	// while (fgets(registro, sizeof(registro), arq)){
	// 	if (cont2 == 6){
	// 		posinicial = ftell(arq);
	// 		break;
	// 	}
	// cont2++;
	// }
	fseek(arq, posinicial, SEEK_SET);
	while (fscanf(arq, "%s", &pessoa[]) != EOF){
		fscanf(arq, "%f", &nota);
		acumulador += nota;
		if (cont % 3 == 0){
			media = acumulador / 3;
			if (media > maior_media){
				maior_media = media;
				strcpy(pessoamaiormedia, pessoa);
			}
			if (media < menor_media){
				menor_media = media;
				strcpy(pessoamenormedia, pessoa);
			}
		acumulador = 0;
		}
		cont++;
	}
	fprintf(arq, "O aluno que apresenta o maior desempenho eh: %s com a media igual a %.1f\nO aluno que apresenta o menor desempenho eh: %s com media igual a %.1f", pessoamaiormedia, maior_media, pessoamenormedia, menor_media);
	while (fgets(registro, sizeof(registro), arq)){
	printf("%s", registro);	
	}
	fclose(arq);
	return 1;
}

#endif