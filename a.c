#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<locale.h>

int main()
{	
	int i;
	int n;//quantidade de pontos
	float x[n];//vetor dos valores de x
	float f[n];//vetor dos valores de f(x)
	float soma1 = 0, soma2 = 0, soma3 = 0, soma4 = 0;
	float tensao;
	//F(x) = z + k*(1/sqrt(d))
	//d = x
	//g1(x) = 1
	//g2(x) = 1/sqrt(x)
	//soma1-> <g1,g2>; ; soma2-> <g2,g2>; soma3-> <g1,f> soma4-> <g2,f>
	//<g1,g1> = 1 = n; <g1,g2> = <g2,g1> = 1/sqrt(xi); <g2,g2> = 1/xi; <g1,f> = f(xi); <g2,f> = f(xi)/sqrt(xi)
	//a1 = z
	//a2 = k
	
	//Como estamos fazendo matrizes para resolução de um sistema de equações pela regra de Cramer+
    //então, temos que fazer A1 e A2 e calcular suas determinantes.
   
    // [ <g1,fx>   <g1,g2> ]  
    // [ <g2,fx>   <g2,g2> ]  // Matriz A1.
   
    // [ <g1,g1>   <g1,fx> ]  
    // [ <g2,g1>   <g2,fx> ]  // Matriz A2.
   
    // [ <g1,g1>   <g1,g2> ]  
    // [ <g2,g1>   <g2,g2> ]  // Matriz A.
   
    //a1 = Det(A1)/Det(A)
    //a2 = Det(A2)/Det(A)
   
	float a1, a2;
	float numa1;// -> Det(A1)
	float numa2;// -> Det(A2)
	float denom;// -> Det(A)
	
	printf("Digite a quantidade de pontos: ");
	scanf("%d", &n);
	if(n <= 0){
		printf("Não é possível com essa quantidade de pontos");
	}
	
	else{
	printf("Quais são os %d valores de x?\n ", n);
	for(i=0; i<n; i++){
		printf("x%d = ", i);	
		scanf("%f", &x[i]);
	}
	printf("\n");
	
	printf("Quais são os %d valores de f(x)?\n ", n);
	for(i=0; i<n; i++){
		printf("f(x%d) = ", i);	
		scanf("%f", &f[i]);
	}
	printf("\n");
	
	for(i = 0; i<n; i++){
		soma1 = soma1 + (1/sqrt(x[i]));
		soma2 = soma2 + (1/x[i]);
		soma3 = soma3 + (f[i]);
		soma4 = soma4 + ((f[i])/sqrt(x[i]));
	}
	
	numa1 = ((soma3*soma2) - (soma1*soma4));
	numa2 = ((n*soma4) - (soma3*soma1));
	denom = ((n*soma2) - (soma1*soma1));
	
	a1 = numa1/denom;
	a2 = numa2/denom;
	
	printf("g(x) = %.4f + %.4f(1/sqrt(x))", a1, a2); 
	
	tensao = a1 + a2*(1/sqrt(0.05));		
	
	printf("\n");
	printf("A tensão com Grão de 0,05 equivale em: %.4f",tensao);
	}
	
	return 0;
	
}