#include<stdio.h>
#include<conio.h>
#include<iostream>
long int fib(int n) { 
    // casos bases 
    if (n==0) { 
        return 0; 
    } 
    else 
    if (n==1){
        return 1;
    }
    else{
    	//Caso recursivo
        return fib(n-2)+fib(n-1); 
    }
}

int MCD( int A, int B) { 
 
	if (A < B) {
 		return MCD(B, A); //Caso base principal, ya que solo funciona colocando el mayor y luego el menor
	}
	else if (B == 0) {// Caso base
 		return A; 
 	}
	else {// Caso recursivo
 		return MCD(B, A % B); //En caso de que no sea B=0 ni A menor que B, se saca el modulo del mayor A con el menor B
        // Y eso se vuelve a calcuar el maximo de esos dos numeros
	}
} 

int ackermann(int m, int n) {
  if (m == 0) {
    return n + 1;//Caso base
  }
  else if(n == 0&&m>0) {
    return ackermann(m - 1, 1);
  }
  else{ //Condicion donde m>0 y n>0
    return ackermann(m - 1, ackermann(m, n - 1));
  }
}

int fact(int n) { 
  if (n == 0) { 
    // caso base 
    return 1; 
  } 
  else { 
    // caso recursivo 
    return n * fact(n-1); 
   } 
}



long morris(int n,int m){
	//solo funciona con diferencias pares
  if (n==m)
  {
    return (m+1);
  }
  // Solo funciona para n>m
  // la ultima condicion es buscar que n y m sean iguales

  else {
    return morris(n,morris(n-1,m+1));
  }
}

int impar(int m);

int par(int m) {
  if (m == 0) {
    return 1;
  }
  else {
    return impar(m - 1);
  }
}

int impar(int m) {
  if (m == 0) {
    return 0;
  }
  else {
    return par(m - 1);
  }
}

int Q(int A, int B) {
    if (A < B) {
        return 0;
    } else {
        return Q(A - B, B) + 1;
    }
}

int BusBin(int A[], int x, int i, int j) {
  // i , j son los límites inferior y superior del arreglo 
    int medio;
    medio = (i + j) / 2;
    if (A[medio] == x){
        return medio;
	}
	else if ((x < A[medio]) && (i < medio)){
        return BusBin(A, x, i, medio - 1);
	}
    else if (medio < j){
        return BusBin(A, x, medio + 1, j);
	}
	else{
        return -1;
	}
}

int Maximo(int A[], int i, int j) {
    int medio, max1, max2;

    if (i == j){
        return A[i];
	}
    else {
        medio = (i + j) / 2;
        max1 = Maximo(A, i, medio);
        max2 = Maximo(A, medio + 1, j);
        if (max1 > max2) {
			return max1;
		}
        else {
        	return max2;
		}
    }
}

int main (){
    printf("\nPosicion 10 de la serie de Fibonacci=%i",fib(10));
    printf("\nMaximo comun divisor de %d y %d :=%i",6,15,MCD(6,15));
    printf("\nValor de ackerman para 1 y 1:=%i",ackermann(1,1));
    printf("\nValor de ackerman para 2 y 3:=%i",ackermann(2,3));
    printf("\nEl factorial de %d es:%d",5,fact(5));
    printf("\nMorris 4 y 2:%d",morris(4,2));
    printf("\n¿Es par el 5?=%d",par(5));
    printf("\n¿Es impar el 5?=%d",impar(5));
    printf("\nQ de los numeros 2 y 3=%d",Q(2,3));//Indica si el primer numero es mayor al segundo
    printf("\nQ de los numeros 14 y 3=%d",Q(14,3));//Indica si el primer numero es mayor al segundo
   
    int A[] = {1, 3, 4, 6, 8, 9, 11};
    int n = sizeof(A) / sizeof(A[0]);
    int x = 4;
    int result = BusBin(A, x, 0, n-1);
    if (result != -1) {
        printf("\nEl valor %d esta en el indice %d\n",x, result);
    } else {
        printf("\nEl valor %d no fue encontrado en el indice %d",x, result);
    }


    n = sizeof(A) / sizeof(A[0]);
    result = Maximo(A, 0, n-1);
    printf("\nEl maximo valor es %d",result);

    return 0;
}


