#include<stdio.h>
#include<stdlib.h>

void size_matriz(int miArray[15],int &n,int &m,int matriz){
	printf("Ingrse el numero de filas de la matriz %d= ",matriz);
	scanf("%d",&n);
	printf("Ingrse el numero de columnas de la matriz %d= ",matriz);
	scanf("%d",&m);
}
void modificar_array(int miArray[15][15],int n,int m,int matriz){
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("Ingrse el valor de Array_%d[%d][%d]=",matriz,i+1,j+1,miArray[i][j]);
			scanf("%d",&miArray[i][j]);
		}
	}
}
void imprimir_array(int miArray[15][15],int n,int m){
	for(int i=0; i<n; i++){ //Mostrando la matriz 1 en pantalla
		for(int j=0; j<m; j++){
			printf("[%d] \t", miArray[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int matriz_A[15][15],matriz_B[15][15], n_A,m_A,n_B,m_B,selector,matriz[15][15];
	
	size_matriz(matriz_A[15],n_A,m_A,1);
	size_matriz(matriz_B[15],n_B,m_B,2);
	
	
	while(n_A!=n_B||m_A!=m_B){
		printf("El tamaño de las matrices es diferente\nIngrese 1 para modificar el tamaño de A, o 2 para modificar el tamaño de B:=");
		scanf("%d",&selector);
		
		if(selector==1){
			size_matriz(matriz_A[15],n_A,m_A,1);
			modificar_array(matriz_A,n_A,m_A,1);
		}
		if(selector==2){
			size_matriz(matriz_B[15],n_B,m_B,2);
			modificar_array(matriz_B,n_B,m_B,2);
		}
		printf("El tamano de la matriz A(%d,%d) = B(%d,%d)\n",n_A,m_A,n_B,m_B);
	}
	
	printf("El tamano de la matriz A(%d,%d) = B(%d,%d)\n",n_A,m_A,n_B,m_B);
	modificar_array(matriz_A,n_A,m_A,1);
	modificar_array(matriz_B,n_B,m_B,2);
	
	printf("Matriz 1:\n");
	imprimir_array(matriz_A,n_A,m_A);

	printf("Matriz 2:\n");
	imprimir_array(matriz_B,n_B,m_B);
	
	//Imprime y suma las dos matrices, sum matriz
	printf("Matriz con las sumas:\n");
	for (int i=0;i<n_A;i++){
		for(int j=0;j<m_A;j++){
			matriz[i][j]=matriz_A[i][j]+matriz_B[i][j];
			printf("Array[%d][%d]=%d\t",i+1,j+1,matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}
