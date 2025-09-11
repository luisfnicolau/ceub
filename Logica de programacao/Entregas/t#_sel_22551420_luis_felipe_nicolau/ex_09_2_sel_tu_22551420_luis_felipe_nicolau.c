/*
 * Descrição: Calcula as raizes reais de uma equação do 2o grau.
 * Autor: Luis Felipe Nicolau
 * Data: 11/09/2025
 */

#include <stdio.h>
#include <locale.h>
#include <math.h>

void main(void) {
    setlocale(LC_ALL, "Portuguese");
    
    float x1, x2, delta;
    int a, b, c;
    
    
    printf("\nEntre com o valor do coeficiente a: ");
    scanf("%i", &a);
    printf("\nEntre com o valor do coeficiente b: ");
    scanf("%i", &b);
    printf("\nEntre com o valor do coeficiente c: ");
    scanf("%i", &c);
        
    delta = pow(b, 2) - (4*a*c);
    x1 = (-b + sqrt(delta)) / (2 * a);
	x2 = (-b - sqrt(delta)) / (2 * a);    
    
    printf("\nAs raizes s�o: %.4f e %.4f", x1, x2);
}
