#include <stdio.h>

int velocidade_ms_kh(int velo_ms){
    return velo_ms*3.6;
}

int horas_e_minutos(int horas, int minutos){
    return (horas*60) + minutos;
}

double conversao_dolar(double cotacao, double valor){
    return cotacao*valor;
}

int area_triangulo(int base, int altura){
    return (base*altura)/2;
}

int area_tringulo(int lado){
    return lado*lado;
}

int area_retangulo(int base, int altura){
    return base*altura;
}

double comprimento_circuferencia(int raio){
    return 2*3.14159*raio;
}

double volume_circuferencia(int raio){
    return(4*3.14*(raio*raio*raio))/3;
}

int celsius_para_fahrenheit(int celsius){
    return (9*celsius) + 160;
}

int fahrenheit_para_celsius(int fh){
    return (5*fh) - 160;
}

int fatorial(int num){
    if (num > 0){
        return num * fatorial(num-1);   
    } else{
        return 1;
    }
}

int primo(int num){
    // 0 - false
    // 1 - true
    int raiz, i;
    raiz = num*(0.5);
    for (i=2;i<raiz;i++){
        if (num%i==0){
            return 0;
        }
    }
    return 1;
}

int mmc(int num1, int num2){
    int i, menor;
    if (num1 > num2){
        menor = num2;
    } else{
        menor = num1;
    }
    for (i=2;i<=menor;i++){
        if (num1%i==0 && num2%i==0){
            return i;
        }
    }
}

int mdc(int num1, int num2){
    int i, menor;
    if (num1 > num2){
        menor = num2;
    } else{
        menor = num1;
    }
    for (i=menor;i>1;i--){
        if (num1%i==0 && num2%i==0){
            return i;
        }
    }
}
/*
int main(){
    int num;
    num = mdc(15, 30);
    printf("%d\n", num);
    return 0;
}*/
