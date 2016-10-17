

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>


int busca(int[], int, int, int);

int main(){

	//criando uma estrutura para medir o tempo de execução
	struct timeval t1, t2;
	int tamanho, contador, contador2, contador3;
	FILE *arq;
	arq = fopen("a.txt", "wt");


	for(contador = 200; contador < 10000; contador += 200){

		tamanho = contador;
		int lista[tamanho];

		//criando um vetor aleatório
		for(contador2 = 0; contador2 < tamanho; contador2++){
	
			//lista[contador2] = rand() % tamanho;
			lista[contador2] = contador2 + 1;
			//lista[contador2] = (tamanho - 1) - contador2;
		}


		//medindo o tempo da função
		int aleatorio = rand() % tamanho, metade = tamanho / 2, nulo = tamanho * 2;
		float media = 0.0;
		for(contador3 = 0; contador3 < 100; contador3++){
			
			gettimeofday(&t1, NULL);

			//pior caso
			//busca(lista, 0, tamanho - 1, nulo);
	
			//melhor caso
			//busca(lista, 0, tamanho - 1, metade);

			//medio caso
			busca(lista, 0, tamanho - 1, aleatorio);
	
			gettimeofday(&t2, NULL);

			media += (float)(((t2.tv_sec * 1000000.0 + t2.tv_usec) - (t1.tv_sec * 1000000.0 + t1.tv_usec)) / 1000000.0);
	
		}	

		fprintf(arq, "%.20lf%s", media / 100.0, "\n");
	
	}

	fclose(arq);
	return 0;

	
}



int busca(int lista[], int inicio, int fim, int elemento){

	int i = (inicio + fim)/2;
	if (lista[i] == elemento){

		return i;

	}

	if (inicio >= fim){
		return 0;
	}

	if (lista[i] < elemento){
		busca(lista, i + 1, fim, elemento);

	}

	else{
		busca(lista, inicio, i - 1, elemento);

	}

}


