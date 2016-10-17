

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>


//declaração da função
int partition(int[], int, int);
void quickSort(int[], int, int);




int main(){

	//criando uma estrutura para medir o tempo de execução
	struct timeval t1, t2;
	int tamanho, contador, contador2, contador3;
	FILE *arq;
	arq = fopen("w.txt", "wt");
	
	for(contador = 100; contador < 10000; contador += 100){

		tamanho = contador;
		int lista[tamanho];

		//criando um vetor aleatório
		for(contador2 = 0; contador2 < tamanho; contador2++){
		
		
			//lista[contador2] = rand() % tamanho;
			lista[contador2] = contador2;
			//lista[contador2] = (tamanho - 1) - contador2;
		}


		float media = 0.0;
		for (contador3 = 0; contador3 < 100; contador3++){

			//medindo o tempo da função
			gettimeofday(&t1, NULL);

			quickSort(lista, 0, tamanho - 1);

			gettimeofday(&t2, NULL);

	
			media += (float)(((t2.tv_sec * 1000000.0 + t2.tv_usec) - (t1.tv_sec * 1000000.0 + t1.tv_usec)) / 1000000.0);	

		}

		//escrevendo no arquivo
		fprintf(arq, "%.20lf%s", media / 100.0, "\n");

	}

	fclose(arq);
	return 0;

}



int partition(int lista[], int esquerda, int direita){
	
	//pior caso
	int p = esquerda;

	//melhor caso
	//int p = (direita + esquerda)/2;

	//medio caso
	//int p = rand() % direita;

	int j = esquerda + 1;
	int i, aux;
	for (i = esquerda + 1; i <= direita; i++){

		if (lista[p] > lista[i]){
			j = j + 1;
			aux = lista[j - 1];
			lista[j - 1] = lista[i];
			lista[i] = aux;
	
		}
	}
	aux = lista[p];
	lista[p] = lista[j - 1];
	lista[j - 1] = aux;
	return j - 1;

}



void quickSort(int lista[], int esquerda, int direita)
{

	if (direita > esquerda){
		int p = partition(lista, esquerda, direita);
		quickSort(lista, esquerda, p - 1);
		quickSort(lista, p + 1, direita);	


	}    

}


