#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>



void mergeSort(int* , int , int );
void merge(int* , int , int , int );



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
			lista[contador2] = rand() % tamanho;
			//lista[contador2] = contador2;
			//lista[contador2] = (tamanho - 1) - contador2;
		
		}
		

		float media = 0.0;;
		for (contador3 = 0; contador3 < 100; contador3++){	

			//medindo o tempo da função
			gettimeofday(&t1, NULL);

			mergeSort(lista, 0, tamanho - 1);

			gettimeofday(&t2, NULL);

			media += (float)(((t2.tv_sec * 1000000.0 + t2.tv_usec) - (t1.tv_sec * 1000000.0 + t1.tv_usec)) / 1000000.0);

			
		}	

		//escrevendo no arquivo
		fprintf(arq, "%.20lf%s", media / 100.0, "\n");
	
	
	}

	fclose(arq);
	return 0;

}




void mergeSort(int* V, int s, int e)
{
	int m;
	
	if(s < e)
	{
		m = (s + e)/2;
		mergeSort(V, s, m);
		mergeSort(V, m + 1, e);
		merge(V, s, m, e);
		
	}
}



void merge(int* A, int s, int m, int e)
{
	int i, j, k, B[e - s + 1];
	
	i = s;
	j = m + 1;
	
	for(k = 0; k <= (e - s); k++)
	{
		if(((A[i] < A[j]) && (i <= m)) || (j > e))
		{
			B[k] = A[i];
			i += 1;
		}
		else
		{
			B[k] = A[j];
			j += 1;
		}
	}
	for(k = 0; k <= (e - s); k++)
	{
		A[s + k] = B[k];
	}
	
}




