#include <stdio.h>
#include <math.h>

int main ()
{
	//Se definen las variables a utilizar
  double x=0;
  double y=0;
  double t=0;
  double h=0;
  double h0=150;
	//se agregó el término h0 para que no hubiese problemas al llamar a h
  double theta=45;
  double v0=50;
  double g=9.80665;
  double i;

  double delta=0.01;
  double Pi=3.14159265;
	
  FILE *f= fopen("coordproy1.dat", "w");


  //printf("Dame la velocidad inicial[m/s] del proyectil: \n");
  //scanf("%lf",&v0);
  //printf("\n");
  //printf("Dame el angulo inicial (grados):\n");
  //scanf("%lf",&theta);
	
	//se usan las ecuaciones para tiro parabólico con h0

  t=((sqrt(v0*v0**sin(theta*(Pi/180))*sin(theta*(Pi/180)) + 4*g*h0)- v0*sin(theta*(Pi/180)))/g);

  h=(h0 + (v0*v0)*sin(theta*(Pi/180))*sin(theta*(Pi/180))/(2*g));

     printf ("El desplazamiento del proyectil, en x,y [metros]:\n");
	    // se corta el tiempo en pedazos delta t para poder graficar

     for (i=0; i<=t ;i=i + delta)
       
       {
	 x= v0 * cos(theta*Pi/180)*i;
	 y=-0.5 * g *(i*i)+ v0 * sin(theta*Pi/180)*i +h0;

	 fprintf(f,"%.5lf %.5lf \n",round(x),y);
	 printf("%.5lf %.5lf \n",x,y);
       }

     printf("El Tiempo de vuelo [segundos]:\n");
     printf("%.5lf \n",t);
     printf("La altura maxima alcanzada [m]: \n");
     printf("%.5lf \n",h);



  
  return 0;  
}
