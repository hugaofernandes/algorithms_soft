

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>


int distributionSort(int* , int );
int max(int* , int );
int min(int* , int );


int main(){

	//criando uma estrutura para medir o tempo de execução
	struct timeval t1, t2;
	int tamanho, contador, contador2, contador3;
	FILE *arq;
	arq = fopen("tempo.txt", "wt");

	for(contador = 1; contador < 10000; contador += 100){

		tamanho = contador;
		int lista[tamanho];

		//criando um vetor aleatório
		for(contador2 = 0; contador2 < tamanho; contador2++){
		
			//casos!!!!
			//lista[contador2] = rand() % tamanho;
			lista[contador2] = contador2;
			//lista[contador2] = (tamanho - 1) - contador2;
		
		}

		float media = 0.0;
		for (contador3 = 0; contador3 < 100; contador3++){

			//medindo o tempo da função
			gettimeofday(&t1, NULL);
	
			distributionSort(lista, tamanho);

			gettimeofday(&t2, NULL);


			media += (float)(((t2.tv_sec * 1000000.0 + t2.tv_usec) - (t1.tv_sec * 1000000.0 + t1.tv_usec)) / 1000000.0);
			
		}

		//escrevendo no arquivo
		fprintf(arq, "%.20lf%s", media / 100.0, "\n");
	
	
	}

	fclose(arq);
	return 0;
    
}







//Função ditributionsort
int distributionSort(int* V, int tamanho){


	int i, j;
	int *A, *S, MIN, MAX;
	
	A = ( int*) malloc(tamanho * sizeof(int));
    	S = ( int*) malloc(tamanho * sizeof(int));
	
	MIN = min(V, tamanho);
	MAX = max(V, tamanho);
	
	for(j = 0; j < (MAX - MIN); j++){

		A[j] = 0;
	}
	for(i = 0; i < (tamanho - 1); i++){

		A[V[i] - MIN] = A[V[i] - MIN] + 1;
	}
	for(j = 1; j < (MAX - MIN + 1); j++){

		A[j] += A[j - 1];
	}
	for(i = (tamanho - 1); i > 0; i--){

		j = V[i] - MIN;
		S[A[j]] = V[i];
		A[j] = A[j] - 1;
	}
	S[tamanho - 1] = V[tamanho - 1];

	return *S;
	
}


//Função que encontra o elemento de maior valor do vetor
int max(int* V, int tam){

	int i, maior = 0 ;
	
	for(i=0; i<tam; i++){

		if(V[i] > maior){

			maior = V[i];
		}
	}
	return maior;
}

//Função que encontra o elemento de menor valor do vetor
int min(int* V, int tam){

	int i, menor = V[1] ;
	
	for(i=1; i<tam; i++){

		if(V[i] < menor){

			menor = V[i];
		}
	}
	return menor;
}




