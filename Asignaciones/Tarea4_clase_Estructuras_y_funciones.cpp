#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


// Realizar un programa que cree una estructura de un producto, y que pueda modificarse y imprimir dicho producto
// Realizar las funciones con parametros tipo estructura
struct producto
{
    int codigo;
    char descripcion[40];
    float precio;
    float descuento;
    char fechadevencimiento[30];
    int existencia;
};
void imprimirProducto(struct producto P);
void Pedirdatos(struct producto &P);// Aqui es necesario un apuntador, para indicar que los valores se almacenaran
// En la direccion de memoria introducida

int main()
{  
	int p=4;// Modificando este valor puede aumentar o disminuirse la cantidad de productos
	struct producto pro[4];
	
	for(int i=0;i<p;i++){
		printf("\nProducto %i",i+1);
		Pedirdatos(pro[i]);
	}		

	for(int i=0;i<p;i++){
		printf("\nProducto %i",i+1);
		imprimirProducto(pro[i]);
	}
	getch();
    return 0;
}

void imprimirProducto(struct producto P)   
{
    printf("\nCodigo del producto: %i \n",P.codigo);    
    printf("Descripcion del producto: %s \n",P.descripcion);    
    printf("Precio del producto: %.2f \n",P.precio);    
    printf("Descuento del producto: %.2f% \n",P.descuento);
    printf("Precio nuevo del producto con descuento: %.2f \n",P.precio*P.descuento/100);       
    printf("Fecha de vencimiento dd/mm/aa: %s \n",P.fechadevencimiento);   	  
    printf("Existencia del producto: %i \n",P.existencia);   
};

void Pedirdatos(struct producto &P)   
{
    printf("\nCodigo del producto: ");
	scanf("%i",&P.codigo);    
    printf("Descripcion del producto: ");    
    scanf("%s",P.descripcion);
    printf("Precio del producto: ");
	scanf("%f",&P.precio);
	printf("Descuento del producto en %: ");
	scanf("%f",&P.descuento);    
    printf("Fecha de vencimiento dd/mm/aa: ");    
    scanf("%s",P.fechadevencimiento);
    printf("Existencia del producto: ");
	scanf("%i",&P.existencia);
};

