/*
começarei com W sendo(0,0) e testar os valores a partir disse valor

a formula do erro é e = y - y1
y = resultado esperado
y1 = resultado obtido

modificar o valor de W: w = w + ex
[tem que fazer um vetor para definir o w1 e w2, assim como o x, se não dará erro com os pesos]

*/

#include <stdio.h>

void perceptron(float a,float b, int c);

int main(){

float x1[10]={-0.43,-0.07,0.16,-0.27,0.26,-0.45,-0.06,0.18,0.14,-0.17};
float x2[10]={0.23,0.07,0.17,0.46,-0.23,-0.08,0.32,0.46,-0.01,0.13};
float y[10]={0,0,0,0,1,1,0,0,0,0};

perceptron(x1[0],x2[0],y[0]);

}



void perceptron(float a,float b, int c){

float u, e,n=0.01;
float w1=0,w2=0;
int i,y1;

printf("comeca: x1 = %f e x2 = %f\n",a,b);
printf("comeca: W1 = %f e W2 = %f\n",w1,w2);

while(e != 0){

	u = (a*w1) + (b*w2);
printf("valor u = %f\n",u);

	if(u >= 0){
		y1 = 1;
	}else{
		y1 = 0;
	}

	e = c - y1;

	w1 = w1 + n*e*a;
	w2 = w2 + n*e*b;

	printf("termina: W1 = %f e W2 = %f\n",w1,w2);
}

}