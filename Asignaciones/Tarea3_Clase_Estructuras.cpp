#include<stdio.h>
#include<stdlib.h>
// Estructura anidada
typedef struct info_direccion{
    char direccion[30];
    char ciudad[20];
    char estado [20];
};
struct empleado
{
    char nombre[20];										
    struct info_direccion dir_empleado;	
    double salario;    
}empleados[2];

int main()
{   
    for (int i = 0; i < 2; i++){
        fflush(stdin);
		printf("%i. Digite su nombre: ",i+1);
        gets(empleados[i].nombre); 											
        printf("%i. Digite su direccion: ",i+1);
        gets(empleados[i].dir_empleado.direccion); 
        printf("%i. Digite su ciudad: ",i+1);
        gets(empleados[i].dir_empleado.ciudad); 
        printf("%i. Digite su estado: ",i+1);
        gets(empleados[i].dir_empleado.estado); 
        printf("%i. Digite su salario: ",i+1);
        scanf("%lf",&empleados[i].salario); 
        printf("\n");
    }
    
    for (int i = 0; i < 2; i++)
    {
        printf("\n\nDatos del empleado # %i",i+1);
        printf("\n\nNombre %s",empleados[i].nombre);
        printf("\n\nDireccion %s",empleados[i].dir_empleado.direccion);
        printf("\n\nCiudad %s",empleados[i].dir_empleado.ciudad);
        printf("\n\nEstado %s",empleados[i].dir_empleado.estado);
        printf("\n\nSalario %.2lf",empleados[i].salario);
    }
    return 0;
}






