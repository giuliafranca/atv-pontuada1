#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <string.h>

//colocar uma funcao de resto pro cont pra colocar um \n quando nao houver resto numa divisão por tres.
int medias(FILE *arq, char nomearq[]){
	int posinicial;
	float nota[3], media, maior_media=0.0, menor_media=1000000.0;
	char registro[50], pessoamaiormedia[20], pessoamenormedia[20], pessoa[20];
	arq=fopen(nomearq, "r+");
	if (!arq) return 0;

	while(fscanf(arq, " %s", registro) != EOF){
		if (strcmp(registro, "Nota3") == 0){
			posinicial = ftell(arq);
			break;
		}
	}
	
	fseek(arq, posinicial, SEEK_SET);

    while(fscanf(arq, " %s %f %f %f", &pessoa, &nota[0], &nota[1], &nota[2]) != EOF){
        media = (nota[0] + nota[1] + nota[2]) / 3;
		if (media > maior_media){
			maior_media = media;
			strcpy(pessoamaiormedia, pessoa);
			}
		if (media < menor_media){
			menor_media = media;
			strcpy(pessoamenormedia, pessoa);
		}
    }


	rewind(arq);
	fprintf(arq, "				Caderneta com as notas dos alunos\nO aluno que apresenta o maior desempenho eh: %s com a media igual a %.1f\nO aluno que apresenta o menor desempenho eh: %s com media igual a %.1f\n\n", pessoamaiormedia, maior_media, pessoamenormedia, menor_media);
	
	rewind(arq);
	while (fgets(registro, sizeof(registro), arq)){
	printf("%s", registro);	
	}
	
	fclose(arq);
	return 1;
}

#endif
