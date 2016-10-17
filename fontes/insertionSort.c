


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>




//declaração da funcão
void insertionSort(int[], int);



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
		
			//casos!!!!
			//lista[contador2] = rand() % tamanho;
			//lista[contador2] = contador2;
			lista[contador2] = (tamanho - 1) - contador2;
		}

		float media = 0.0;
		for (contador3 = 0; contador3 < 100; contador3++){

			//medindo o tempo da função
			gettimeofday(&t1, NULL);
	
			insertionSort(lista, tamanho);

			gettimeofday(&t2, NULL);


			media += (float)(((t2.tv_sec * 1000000.0 + t2.tv_usec) - (t1.tv_sec * 1000000.0 + t1.tv_usec)) / 1000000.0);
			
		}

		//escrevendo no arquivo
		fprintf(arq, "%.20lf%s", media / 100.0, "\n");
	
	}

	fclose(arq);
	return 0;

}




//função insertion Sort
void insertionSort(int lista[], int tamanho){

	int contador, j, eleito;

	for(contador = 1; contador < tamanho; contador++){

		eleito = lista[contador];
		j = contador - 1;
		
		while((j >= 0) && (eleito < lista[j])){

			lista[j + 1] = lista[j];
			j = j - 1;

		}

		lista[j + 1] = eleito;

	}

}



