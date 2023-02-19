// Realizado por Alexander Sarmiento 29646755 Uru
#include<stdio.h>
#include<stdlib.h>
#define N 20
//Realice un programa con funciones:
//permita leer los datos de la matriz
//permita escribir estos datos digitados por el usuario por consola
//permita multiplicar_array estos valores

// Nota aunque se confunda la sintaxis, matriz es diferente de X.matriz, ya que uno hace referencia al tipo de estructura matriz
// Mientras que el otro es una array tipo int que almacena un conjunto de datos en memoria contigua
// Declaracion de estructura de matriz
struct matriz
{
    int matriz[N][N];							//Almacena los enteros de la matriz
    int filas; 									// Numero de filas
	int columnas;								// == == columnas
	int id;										// Para identificar en consola cual matriz se imprime 
};

// Declaracion de funciones 
void leer_matriz(struct matriz &X,int id);		// Permite modificar la estructura matriz
												//editando su size, se debe colocar un numero para identificar la matriz creada
												// En esta primera funcion es necesario usar un apuntador para que la funcion almacene los datos modificados en la variable tipo
//Estructura X
void escribir_estructura(struct matriz X);		//Permite imprimir en consola los valores de la variable X.matriz
												// Haciendo referencia a la variable de la estructura, el tama�o del bucle esta dado por // X.filas y X.columnas
void multiplicar_array(struct matriz A, struct matriz B,struct matriz &C);
												// Crea un apuntador a una tercera estructura llamada C, para almacenar el resultado
main(){
	struct matriz matriz_A,matriz_B,matriz_C; 	// Declara las variables tipo estructura matriz
	//Aplicacion de las funciones de la Matriz A
	leer_matriz(matriz_A,1); 					//1 es para modificar el matriz_A.id=1 para asi ser la matriz 1
	escribir_estructura(matriz_A);				// Imprime en consola
	//Matriz B
	leer_matriz(matriz_B,2);
	escribir_estructura(matriz_B);
	//Resultado
	multiplicar_array(matriz_A,matriz_B,matriz_C);//Calcula la multiplicacion entre dos matrices 
	escribir_estructura(matriz_C);				// Imprime en consola
	return 0;
}



void leer_matriz(struct matriz &X,int identificador){
	X.id=identificador;							// Guarda en la memoria de la estructura X, el identificador, siendo X la estructura ingresada en el parametro 1
												//Siendo este el identificador de 
	printf("Ingrse el numero de filas de la matriz %d= ",X.id);
	scanf("%d",&X.filas);						// Almacena el numero de filas en la estructura X, el numero de filas
	printf("Ingrse el numero de columnas de la matriz %d= ",X.id);
	scanf("%d",&X.columnas);					// En caso de ser flotante modificar con %f
	for (int i=0;i<X.filas;i++){
		for(int j=0;j<X.columnas;j++){
																				// Modifica de uno en uno el elemento de cada matriz, dicho parametro se encuentra en el array X.matriz
			printf("Ingrse el valor de Matriz_%d[%d][%d]=",X.id,i+1,j+1);		// Sirve para ver en consola que ya se pueden ingresar los datos
			scanf("%d",&X.matriz[i][j]);	
		}
	}
}

void escribir_estructura(struct matriz X){
	printf("\nMatriz_%d\n",X.id);
	for(int i=0; i<X.filas;i++){ 					//Recorre los elementos ij de la matriz
		for(int j=0; j<X.columnas; j++){
			printf("[%d] \t",X.matriz[i][j]);		//Imprime el valor almacenado en la matriz de la estructura X
		}											// Con el tabulador permite mostrar en forma de matriz
		printf("\n");								//Salto de linea al pasar de fila
	}
	printf("\n");									//Salto de linea luego de imprimir matriz
}

void multiplicar_array(struct matriz A, struct matriz B,struct matriz &C){// Hay un apuntador de la matriz C para almacenar los datos en la estructura insertada en la funcion como parametro
    int i, j, k,modificar;
    //La matriz resultado tiene tama�o A.filas x B.columnas
    C.filas=A.filas; 
    C.columnas=B.columnas;
    C.id=3;								//Se le asigna un valor al id de la matriz resultado
	while (not(A.columnas==B.filas)) 	//En caso de que NO sean iguales las columnas con las filas
	{
		system("cls");
		printf("\nColumnas A no son iguales a filas B\ncolumnas_A=%d =!filas_B=%d",A.columnas,B.filas);
		printf("\nIngrese 1 para modificar A, o 2 para modificar B: ");
		scanf("%d",&modificar);
		switch (modificar)
		{
			case 1:
				leer_matriz(A,1);
				break;
		
			case 2:
				leer_matriz(B,2);
				break;
			default:
				break;
		}
		escribir_estructura(A);
		escribir_estructura(B);
		C.filas=A.filas;			//Modifica el tamano de C al haberse modificado A o B
   		C.columnas=B.columnas;
	}
	
    for (i = 0; i < A.filas; i++) {
        for (j = 0; j < B.columnas; j++) {
            C.matriz[i][j] = 0; 			//Este primer elemento permite vaciar cualquier numero aleatoreo almacenado en el array para i j
            for (k = 0; k < A.columnas; k++){
            	//Calcula el resultado manteniendo constante la fila de A y la columna de B, i y j respectivamente
            	// Pero variando las columnas de A y variando las filas de B
            	// Esta suma se acumula en el elemento i e j de la matriz C
                C.matriz[i][j] += A.matriz[i][k] * B.matriz[k][j];
			}
        }
    }
}

