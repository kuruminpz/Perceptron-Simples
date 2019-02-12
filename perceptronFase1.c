/*
começarei com W sendo(0,0) e testar os valores a partir disse valor

a formula do erro é e = y - y1
y = resultado esperado
y1 = resultado obtido

modificar o valor de W: w = w + ex
[tem que fazer um vetor para definir o w1 e w2, assim como o x, se não dará erro com os pesos]

*/

#include <stdio.h>


float _w1=0,_w2=0;

void perceptron(float a,float b, int c);

int main(){

int i;
float x1[10]={-0.43,-0.07,0.16,-0.27,0.26,-0.45,-0.06,0.18,0.14,-0.17};
float x2[10]={0.23,0.07,0.17,0.46,-0.23,-0.08,0.32,0.46,-0.01,0.13};
float y[10]={0,0,0,0,1,1,0,0,0,0};


float wi1=1;
float wi2=1;

while(wi1 != _w1 && wi2 != _w2){
	printf("Antes: wi1 = %.2f wi2 = %.2f\n",wi1,wi2);
	for(i=0;i<=9;i++){
		perceptron(x1[i],x2[i],y[i]);
	}

	wi1 = _w1;
	wi2 = _w2;

	printf("Depois: wi1 = %.2f wi2 = %.2f\n",wi1,wi2);

	for(i=0;i<=9;i++){
		perceptron(x1[i],x2[i],y[i]);
	}

	printf("Final: wi1 = %.2f wi2 = %.2f\n",wi1,wi2);
}

}



void perceptron(float a,float b, int c){

float u, e,n=1;

int i,y1;

printf("comeca: x1 = %.2f e x2 = %.2f\n",a,b);
printf("comeca: W1 = %.2f e W2 = %.2f\n",_w1,_w2);

do{

	u = (a*_w1) + (b*_w2);


	if(u >= 0){
		y1 = 1;
	}else{
		y1 = 0;
	}

	e = c - y1;
	printf("ERRO: %.2f\n",e);

	if(e != 0){
		_w1 = _w1 + n*e*a;
		_w2 = _w2 + n*e*b;
		break;
	}else{
		_w1 = _w1 + n*e*a;
		_w2 = _w2 + n*e*b;
	}
	

	printf("termina: W1 = %.2f e W2 = %.2f\n",_w1,_w2);
}while(e != 0);

}