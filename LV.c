#include<stdio.h>
#include<math.h>

//declaramos las funciones de depredador presa

long double f1(long double x, long double y, long double a, long double r );
long double f2(long double x, long double y, long double b, long double m );
long double V(long double x, long double y, long double b, long double m, long double a, long double r );


int main ()
{
  //definimos las variables
 
  int i,N,j,M;
  long double t0=0 ;
  long double tn,x0, x,x1,y0,kx;
  long double y,y1,ky,v,h;
  

  //Definimos constantes de LV
  long double alpha, beta, delta,gamma,w,k1;
  N=10000;
  M=10;
  t0=0.00;
  x0=0.9;
  y0=1.8;
  alpha= 1.1;
  beta=0.9;
  gamma=1.0;
  delta=2.0;
  w=sqrt(alpha*gamma);
  h=(3.151592)/(long double)N;
  k1=(delta/beta)*sqrt(alpha/gamma);
  //definimos nuestro dx
 
  //condiciones iniciales
  x=x0;
  y=y0;
  FILE * f = fopen("LV2.dat", "w");
  

  //Hacemos la "integral"
  // printf("h=%0.5Lf x[%d]=%0.5Lf y[%d]=%0.5Lf \n", h , 0 ,a, 1, yn);
  for(j=0; j<M; j++)
    {
      x = x0 + (double)j;
      y = y0 + (double) j;
      
       for (i=0;i<4*N;i++)
           {
	    tn= t0 + i;
	    //kx=f1(x,y,alpha,beta);
	    //ky=f2(x,y,delta,gamma);
	   
	    //x1 = x +kx;
	    //y1 = y +ky;

	
	     x1= x*cos(w*(double)i/h) + k1*sin(w*(double )i/h);
	     y1= y*cos(w*(double)i/h) - (1.0/k1)*sin(w*(double)i/h);
	      v= V(x1,y1,delta,gamma,alpha,beta);
	     printf(" t[%d]=%0.1Lf H[%d]=%0.5Lf P[%d]=%0.5Lf %0.5Lf \n" , i ,tn, i, x1,i, y1, V);
	     fprintf(f, " %0.5Lf %0.5Lf %0.5Lf \n" , x1, y1, V);
	
	    }
    } 
  return 0;
   
  
}

long double f1(long double x, long double y, long double alpha, long double beta )
{
  //definimos la funcion a utilizar dH/dt= aH - rHP 
  return (alpha*x-beta*x*y);   
    
	    
}
long double f2(long double x, long double y, long double delta, long double gamma )
{
  //definimos la funcion a utilizar dH/dt= bHP - mP 
  return (delta*x*y-gamma*y);   
    
	    
}
long double V(long double x, long double y, long double delta, long double gamma, long double alpha, long double beta )
{
  return(-delta*x + gamma*(long double)log((double)x)-beta*y + alpha*(long double)log((double)y));
}

