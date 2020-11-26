#include <iostream>
#include <cmath>

int factorial (int);
double calculateRho (void);
double calculateAverageV (void);
double calculateAverageTf (void);
double calculateAverageN (void);
double calculateAverageTs (void);
double calculateAverageMnz (void);
double probability0 (void);
void probabilityj (int);

double lambda, my, m, C1, C2, rho;

int main() {
    lambda = 3.0;
    my = 3.0;
    m = 3.0;
    C1 = 4.5;
    C2 = 5.1;
    if (m >= 1) {
        if (lambda < (m * my)) {
            rho = calculateRho();
            if ((rho/m) > 1) {
                std::cout << "rho/m = " << rho/m << " < 1" << std::endl;
                return 0;
            }
            std::cout << "Srednia liczba zajetych kanalow obslugi: " << rho << std::endl;
            std::cout << "Srednia liczba zgloszen w kolejce: " << calculateAverageV() << std::endl;
            std::cout << "Sredni czas oczekiwania zgloszenia w kolejce: " << calculateAverageTf() << std::endl;
            std::cout << "Srednia liczba zgloszen w systemie: " << calculateAverageN()<< std::endl;
            std::cout << "Sredni czas przebywania zgloszenia w systemie: " << calculateAverageTs() << std::endl;
            std::cout << "Sredni liczba niezajetych kanalow oblsugi: " << calculateAverageMnz() << std::endl;
            std::cout << "f(m) = " << C1 << " * " << calculateAverageV() << " + " << C2 << " * " << calculateAverageMnz() << std::endl;
            std::cout << "Prawdopodbienstwo, ze system jest pusty: " << probability0() << std::endl;
            probabilityj(3);
        } else {
            std::cout << "lambda > m*my " << lambda << " > " << (m * my) << std::endl;
        }
    } else {
        std::cout << m << "< 1" << std::endl;
    }

    return 0;
}

int factorial (int i) {
    int j = 1;
    for (int k = 1; k < i; k++) {
        j *= k;
    }
    return j;
}

double calculateRho () {
    return (double)lambda/my;
}

double calculateAverageV () {
    double counter = (pow(rho, (m+1))/pow((m-rho), 2)*factorial(m-1));
    double sum = 0;
    for (int i = 0; i <= (m-1); i++) {
        sum += pow(rho, i)/factorial(i);
    }
    double denominator = sum + (pow(rho, m)/(factorial(m-1)*(m-rho)));
    double result = counter / denominator;

    return result;
}

double calculateAverageTf () {
    return calculateAverageV()/lambda;
}

double calculateAverageN () {
    return calculateAverageV()/rho;
}

double calculateAverageTs () {
    return calculateAverageN()/lambda;
}

double calculateAverageMnz () {
    return m - rho;
}

double probability0 () {
    double counter = m - rho;
    double sum = 0;
    for (int j = 0; j <= (m-1); j++) {
        sum += (m-j)*(pow(rho, 2)/factorial(j));
    }
    double result = counter/sum;

    return result;
}

void probabilityj (int j) {
    for (int i = 0; i < j; i++) {
        if (i <= m) {
            std::cout << "p" << i << " = " << (pow(rho, i)/factorial(i))*probability0() << std::endl;
        }
    }
}