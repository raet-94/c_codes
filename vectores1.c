#include <stdio.h>
int main ()
{
  int n=3;
  int i;
  int vector1[n];
  int vector2[n];
  int vector3[n];
  printf("Caputre las cooordenadas del vector 1 :\n");
  for (i=0;i<n; i++)
    {
      scanf("%d",&vector1[i]);
      // printf("La entrada del vector 1 [%d] es : %d \n",i+1, vector1[i]);
    }
  printf("\n Caputre las cooordenadas del vector 2 :\n");
     
  for (i=0;i<n; i++)
    {
      scanf("%d",&vector2[i]);
      //printf("La entrada del vector 2 [%d] es : %d \n",i+1, vector2[i]);
    }
  printf("\n");
  for (i=0;i<n; i++)
    {
      vector3[i]= vector1[i]+ vector2[i];
      printf("La entrada del vector 3 [%d] es : %d \n",i+1, vector3[i]);
    }
  
  
  
   
  
  return 0;
}  
