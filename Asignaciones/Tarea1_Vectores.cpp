#include <stdio.h>

void modificar_array(int miArray[15],int n){
	for(int i=0; i<n;i++){
		printf("Ingrese el valor # %d: ",i+1);
		scanf("%d",&miArray[i]);
	}
}

void imprimir_array(int miArray[15], int n){
	for(int i= 0; i<n; i++){			
		printf("El numero es miArray[%d]=%d\n",i+1,miArray[i]);
	}
}

int main(){
	int miArray[15],n,p;
	printf("Indica el numero de elementos: ");
	scanf("%d",&n);	
	while(n<=0||n>15){
		printf("El valor ingresado es mayor a 15 o menor a 0\n");
		printf("Ingrese otro valor: ");
		scanf("%d",&n);
	}
	modificar_array(miArray,n);
	imprimir_array(miArray,n);
return 0;
}


