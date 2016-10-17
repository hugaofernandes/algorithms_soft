



#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

int busca(int[], int, int);


int main(){

	//criando uma estrutura para medir o tempo de execução
	struct timeval t1, t2;
	int tamanho, contador, contador2, contador3;
	FILE *arq;
	arq = fopen("b.txt", "wt");

	for (contador = 100; contador < 10000; contador += 100){
	
		tamanho = contador;
		int lista[tamanho];

		//criando um vetor aleatório
		for(contador2 = 0; contador2 < tamanho; contador2++){

			lista[contador2] = contador2;
			
		}

		float media = 0.0;
		for (contador3 = 0; contador3 < 100; contador3++){

			//medindo o tempo da função
			gettimeofday(&t1, NULL);

			busca(lista, tamanho, 0);
			//busca(lista, tamanho, tamanho * 2);
			//busca(lista, tamanho, rand() % tamanho);

			gettimeofday(&t2, NULL);

			media += (float)(((t2.tv_sec * 1000000.0 + t2.tv_usec) - (t1.tv_sec * 1000000.0 + t1.tv_usec)) / 1000000.0);
		
	
	}
	
		fprintf(arq, "%.20lf%s", media / 100.0, "\n");

	}

	fclose(arq);
	return 0;


}



int busca(int lista[], int tamanho, int elemento){

	int i;
	for (i = 0; i < tamanho; i++){

		if (lista[i] == elemento){
			return 1;

		}
		
	}
	return 0;

}





