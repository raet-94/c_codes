#include <stdio.h>
int main ()
{
    //definimos nuestras variables
    //podemos fijar n pero en este caso se le pide al usuario
  int n;
  long double sum;
  int i;
  //Generamos el archivo con los datos
  FILE *f=fopen("quad.dat","w");
  //Pedimos el N máximo
  printf("Cuantos terminos de la serie de la suma de los cuadrados quieres calcular? \n" );
  scanf("%i", &n);
  //generamos un for para hacer la serie
  for (i=1; i<=n; i++)
      {
  //sumamos en este caso no funciona el usar sólo la división, pusimos el (float) al ver que funcionaba se dejo
      sum= sum + 1/((float)i*i) ;
      printf("%i %Lf \n",i,sum);
      }
  //Imprimimos el resultado para ver que se hizo correctamente
      fprintf(f,"%i %0.0Lf\n", i,sum);
      printf(" %Lf\n", sum);
    
  
return 0;
}