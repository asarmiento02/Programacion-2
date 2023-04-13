//Tema 6 Ordenamiento
#include<iostream>
#include<stdio.h>
using namespace std;

main() { 
	float t,a[]={10.0,8.0,5.5,3.4,3.2,2.5,2.2,1.5,3.5,4.4,9.8,3.5,9,15,19,16,18,21,23}; 
	int i,j,n; 
	n = sizeof(a)/sizeof (float); 
	cout<<"Sizeof(a)="<<sizeof(a)<<endl;
	cout<<"Sizeof(float)="<<sizeof(float)<<endl;
	
	for(i = 1; i < n; i++) { 
		j = i-1; 	
		t = a[i]; //Auxiliar o pivote, va a ir cambiando a medida que el tiempo va pasando, se le asigna en sgda 
		while (j >= 0 && t < a[j]) { 
			// cout<<"t="<<t<<endl;
			// cout<<"a["<<i<<"]="<<a[i]<<endl;
			// cout<<"a["<<j<<"]="<<a[j]<<endl;
			a[j+1] = a[j]; 
			j = j-1; 
		} 
		// cout<<"\ta["<<i<<"]="<<a[i]<<endl;
		// cout<<"\ta["<<j<<"]="<<a[j]<<endl;
		a[j+1] = t; 
	} 
	for(i = 0; i < n; i++) {
		printf("#%d=%0.2f \n",i,a[i]); 
	}
}
