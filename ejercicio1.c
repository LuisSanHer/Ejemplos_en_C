/*
    Ejercicio 1: Intermedio
    Este programa es una calculadora de raices, solo funciona para funciones lineales, cuadráticas
    y cúbicas. Mostrará un menú indicando las posibilidades, según sea seleccionado, pedirá los datos
    necesarios para calcular las raices.

    @author: Luis Angel Sánchez Hernández
    @date: 22 agosto 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void recta(int m, int b);
void cuadratica(int a, int b, int c);
void cubica(int a, int b, int c, int d);

int main(){

    char op[10], r[10];
    int a,b,c,d,m;
/* Mientras el usuario no ingrese la opción 4, el ciclo se repetirá, permitiendo
hacer más cálculos antes de cerrar el programa */
    do{
        printf("¿Que te gustaría hacer?\n");
        printf("\t1) Calcular las raices de una recta\n");
        printf("\t2) Calcular las raices de una función cuadrática\n");
        printf("\t3) Calcular las raices de una función cúbica\n");
        printf("\t4) Salir\n");
        scanf("%s", op);

        switch(atoi(op)){
            case 1:
                printf("Ingrese los coeficientes m y b de la función lineal (m,b)\n");
                scanf("%d,%d", &m,&b);

                recta(m,b);

                break;
            case 2:
/* En las siguientes lineas se leen los coeficientes y se verifica que a sea diferente de 0
para asegurar una función cuadrática */
                do{
                    printf("Ingrese los coeficientes a b y c de la función cuadrática (a,b,c)\n");
                    scanf("%d,%d,%d", &a,&b,&c);
                    if (a == 0){
                        printf("El coeficiente 'a' debe ser diferente de 0\n");
                    }
                }while (a == 0);

                cuadratica(a,b,c);

                break;
            case 3:
/* En las siguientes lineas se leen los coeficientes y se verifica que a sea diferente de 0
para asegurar una función cúbica */
                do{
                    printf("Ingrese los coeficientes a b c y d de la función cúbica (a,b,c,d)\n");
                    scanf("%d,%d,%d,%d", &a,&b,&c,&d);
                    if (a == 0){
                        printf("El coeficiente 'a' debe ser diferente de 0\n");
                    }
                }while (a == 0);

                cubica(a,b,c,d);

                break;
        }
        do{
            if(atoi(op) != 4){
                printf("¿Deseas realizar otra operación? (1.Si / 2.No) ");
                scanf("%s", r);
                if (atoi(r) != 1){
                    op[0] = '4';
                }   
            }else{
                r[0] = '2';
            }           
        }while( (atoi(r)<1 || atoi(r)>2) );
    }while( atoi(op)!=4 );

    printf("Ok! Nos vemos :)\n");

    return 0;
}

void recta(int m, int b){
    /*  función lineal
        y = m*x + b
        0 = m*x + b
        x = -b/m      */
    float res=0.0;
    res = (-b)/(float)m;

    printf("\tx: %.2f\n", res);
}

void cuadratica(int a, int b, int c){
    /*  función cuadrática
    y = ax^2 + bx + c

    disc = (pow(b,2) - 4*a*c);
        
    x1 = ( -b+sqrt(disc) ) / (2*a);
    x2 = ( -b-sqrt(disc) ) / (2*a);
    */
    float disc=0.0;
/*Se calcula el discriminante*/
    disc = (pow(b,2.0) - (4*a*c));
/*si el discriminante es >= 0 entonces las raices están
dentro de los reales*/
    if ( disc>=0.0 ){
        float x;
//Si el discriminante es 0, entonces solo tiene 1 raiz
        if (disc == 0.0){
        x = (-b)/(2.0*a);
        printf("\tx: %.2f\n", x);
//Caso contrario, es necesario resolver toda la formula general.
        }else{
            float x1, x2;
            x1 = ( -b+sqrt(disc) ) / (2.0*a);
            x2 = ( -b-sqrt(disc) ) / (2.0*a);
            printf("\tx1: %.2f\n", x1);
            printf("\tx2: %.2f\n", x2);
        } 
/*Caso contario, el discriminante es negativo, por lo tanto
las raices están en el campo de los imaginarios.*/       
    }else{
        float real, imag;
        disc = fabs(disc);
        real = (-b)/(2.0*a);
        imag = sqrt(disc)/(2.0*a);
        printf("\tx1: %.2f + %.2f*i\n", real, imag);
        printf("\tx2: %.2f - %.2f*i\n", real, imag);
    }
}

void cubica(int a, int b, int c, int d){
    /*  función cúbica
    y = ax^3 + bx^2 + cx + d

    Para facilitar el trabajo, la función cúbica se va a factorizar una X y luego se resolverá
    el resto como una función cuadrática.
    */
    float disc=0.0;
    if ( d==0 ){
        cuadratica(a,b,c);
        printf("\tx3: 0\n");
    }else{

    }
}