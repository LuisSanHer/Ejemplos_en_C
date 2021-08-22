/*
    Ejercicio 2.2: Intermedio
    Este programa va a solicitar al usuario 20 puntos aleatorios y posteriormente los
    almacenará en un archivo de texto, de esta manera se puede utilizar gnuplot para
    graficar los datos.

    @author: Luis Angel Sánchez Hernández
    @date: 22 agosto 2021
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_PUNTOS 20
#define NUM_COMANDOS 6

int main(){
    
    int i=0;
    float x,y;
/*Semilla para valores aleatorios*/
    srand(time(NULL));
/*Crear el puntero al archivo (fichero), contendrá los valores x,y a graficar*/
    FILE * f_puntos = fopen("ArchivosTxt/points_read.txt", "w");
/*Generar y guardar los puntos x,y (aleatorios) en el archivo de texto*/
    for (i=0 ; i<NUM_PUNTOS ; i++){
        printf("Ingrese el punto %d (x,y): \n", i+1);
        scanf("%f,%f",&x,&y);
        fprintf(f_puntos, "%f %f\n", x,y);
    }
 
/*Intrucciones para generar la gráfica
    ->Añade título
    ->Pone cuadrícula
    ->Según los datos, hace un autoescalado de la gráfica
    ->Nombres de etiquetas en los ejes x,y
    ->Instrucción de gráficar el archivo usando columnas 1 y 2 como (x,y)
    uniendo los puntos con lineas.
 */
    char* instructions[] = {"set title 'Puntos aleatorios'",
                            "set grid",
                            "set autoscale",
                            "set xlabel 'Valor X'",
                            "set ylabel 'Valor X'",
                            "plot 'ArchivosTxt/points_read.txt' u 1:2 w lp lt 2 lw 3 t 'Points (x,y)'"
                           };

/*Se usa popen (funciona con tuberías o pipes), con la cual podemos ejecutar gnuplot
  el cual es un programa externo para graficar*/
    FILE* gnuplot = popen ("gnuplot -persist", "w");
/*Enviando y ejecutando las instrucciones de gnuplot por la tubería*/
    for (i=0 ; i<NUM_COMANDOS ; i++){
        fprintf(gnuplot, "%s \n", instructions[i]);
    }
/*Cerrar el puntero al fichero creado*/
    fclose(f_puntos);
/*Cerrar la tubería popen que abrió gnuplot*/
    fclose(gnuplot);
    return 0;
}