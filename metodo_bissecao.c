#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (x*x - x - 2);
}

int main () {

    float a=0, b=0, c=0, x0=0;
    int cont = 0, ni = 10;
    const float ampf = 0.001; //critério de parada (amplitude final)
    const float tol = 0.0001;

    printf("Digite o ponto A do intervalo: ");
    scanf("%f", &a);

    printf("Digite o ponto B do intervalo: ");
    scanf("%f", &b);

    c = b - a; //amplitude
    x0 = (a+b) / 2;  //faz aproximações

    while (c > ampf || fabs(f(x0)) > tol) {
        if(f(a)*f(x0) < 0){
            b = x0;
        }
        if(f(a)*f(x0) > 0){
            a = x0;
        }

        c = b - a;
        x0 = (a+b)/2;
        cont++;

        if(cont >= ni)
        {
            break;
        }
    }
    
    printf("\nRaiz: %f", x0);
    printf("\nf(%f) = %f", x0, f(x0));

    return 0;
}