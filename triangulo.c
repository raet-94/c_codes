#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
 {
   //definimos las variables a utilizar
   double a;
   double b;
   double c;
   double p=0;
   double A=0;
   //Pedimos y escaneamos los lados del triangulo
   printf("Ingrese el lado a del triangulo: \n");
   scanf("%d", &a);
   printf("Ingrese el lado b del triangulo: \n");
   scanf("%d",&b);
   printf("Ingrese el lado c del trianngulo: \n");
   scanf("%d",&c);
   //Verificamos las condiciones para que sea un triangulo
	//a+b>c y a-b<c
    if(a+b<c)
     { 
	   printf(" Estos lados no forman un triangulo.\n");
		       
     }
    if(a+c<b)
     { 
	   printf(" Estos lados no forman un triangulo.\n");
		      
     }
    if(c+b<a)
     { 
	   printf(" Estos lados no forman un triangulo.\n");		 
       
     }
    if(a-b>c)
     { 
	   printf(" Estos lados no forman un triangulo.\n");
        
     }
    if(a-c>b)
     { 
	   printf(" Estos lados no forman un triangulo.\n");
        
     }
	if(b-a>c)
     { 
	   printf(" Estos lados no forman un triangulo.\n");
        
     }
	if(b-c>a)
     { 
	   printf(" Estos lados no forman un triangulo.\n");
        
     }
    if(c-b>a)
     { 
	   printf(" Estos lados no forman un triangulo.\n");
        
     }
    if(c-a>b)
     { 
	   printf(" Estos lados no forman un triangulo.\n");
        
     }
	//Si cumple las condiciones calculamos el area 
	//dada por el semiperimetro p
    else
	{
		p=(a+b+c)*0.5;
		A=sqrt((p*(p-a)*(p-b)*(p-c)));
		printf("El area del triangulo es A= %d",A);
	}


   
   
  return 0;
 } 
