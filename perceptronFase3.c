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

float n=0.01;
int count = 0, i,h=0;
char linha[100];

FILE *arqPtr;

float x1[30],x2[30],y[30];
arqPtr = fopen("A_l.txt","r");


if(arqPtr == NULL){
    printf("Nao pode abrir arquivo\n");
    return -1;
}



while((fgets(linha,sizeof(linha),arqPtr) != NULL)){
    fscanf(arqPtr,"%f %f %f",&x1[h],&x2[h],&y[h]);
    h++;
   
}

    for(i=0;i<30;i++){
       printf("%5.2f\t%5.2f\t%5.2f\n", x1[i], x2[i], y[i]);
    }


	while(count < 30){
			count = 0;


		for(i=0;i< 30;i++){
			_saida = perceptron(x1[i],x2[i]);
			_e = erro(y[i], _saida);


			if(_e != 0){
				_w1 = _w1 + n * _e * x1[i];
				_w2 = _w2 + n * _e * x2[i];

			}else{
				count++;

			}

		}



	}
printf("W1 eh %.2f || W2 eh %.2f\n",_w1,_w2);
printf("taxa de acertos Final: %d%%\n",((count/30)*100));
}


//função perceptron 
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
