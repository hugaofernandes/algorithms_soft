



#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>


int fibo(int);

int main(){

	//criando uma estrutura para medir o tempo de execução
	struct timeval t1, t2;
	int tamanho, contador, contador2, numero;
	FILE *arq;
	arq = fopen("tempoRecusivo.txt", "wt");

	for (contador = 1; contador < 40; contador++){
	
		float media = 0.0;
		for (contador2 = 0; contador2 < 100; contador2++){

			//medindo o tempo da função
			gettimeofday(&t1, NULL);
	
			numero = fibo(contador);
	
			gettimeofday(&t2, NULL);
	

			media += (float)(((t2.tv_sec * 1000000.0 + t2.tv_usec) - (t1.tv_sec * 1000000.0 + t1.tv_usec)) / 1000000.0);

			
		}
		
		//escrevendo no arquivo
		fprintf(arq, "%.20lf%s", media / 100.0, "\n");

	}

	fclose(arq);
	return 0;

	
}



int fibo(int tamanho){

	if (tamanho < 3){
		return tamanho - 1;
	}

	else{
		return fibo(tamanho - 1) + fibo(tamanho - 2);
	}

}


