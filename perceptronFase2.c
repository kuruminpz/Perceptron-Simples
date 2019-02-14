/*
Programa que Simula uma rede Neural Simples;
O PERCEPTRON;
Aluno: Ednaldo Paes C. de Oliveira;
IFCE Campus Maracanaú;
Ciencia da Computação;
*/


#include <stdio.h>

//Variaveis Globais
float _w1=0.5,_w2=0.5,_saida = 0, _e;

//espelhos das funções
float perceptron(float a,float b);
float erro(float a, float b);


//função main
int main(){

int i;
float x1[10]={-0.43,-0.07,0.16,-0.27,0.26,-0.45,-0.06,0.18,0.14,-0.17};
float x2[10]={0.23,0.07,0.17,0.46,-0.23,-0.08,0.32,0.46,-0.01,0.13};
float y[10]={1,0,0,0,1,1,0,0,0,0};
float n=1;
int count=0;

	while(count < 10){
			count = 0;


		for(i=0;i<=9;i++){
			_saida = perceptron(x1[i],x2[i]);
			_e = erro(y[i], _saida);


			if(_e != 0){
				_w1 = _w1 + n * _e * x1[i];
				_w2 = _w2 + n * _e * x2[i];
					break;
			}else{
				count++;

			}

		}



	}
printf("W1 eh %.2f || W2 eh %.2f\n",_w1,_w2);
printf("taxa de acertos Final: %d%%\n",((count/10)*100));
}


//função perceptron e saída obtida
float perceptron(float a,float b){
float u;
int i,y1;

	u = (a*_w1) + (b*_w2);

	if(u >= 0){
		y1 = 1;
	}else{
		y1 = 0;
	}


return y1;
}

//função calcula erro
float erro(float a, float b){

float erro = a - b;

return erro;
}



//EDNALDO PAES CORDEIRO DE OLIVEIRA