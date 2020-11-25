#include <iostream>
#include <cmath>

int factorial(int);
double average_v (double, double);
double probability0 (double, double);
void probabilityj (double, double, double, int);

int main() {
    double lambda, my, m, C1, C2, rho;
    lambda = 3.0;
    my = 3.0;
    m = 3.0;
    C1 = 4.5;
    C2 = 5.1;
    if (m >= 1) {
        if (lambda < (m * my)) {
            rho = lambda / my;
            if ((rho/m) > 1) {
                std::cout << "rho/m = " << rho/m << " < 1" << std::endl;
                return 0;
            }
            std::cout << "Srednia liczba zajetych kanalow obslugi: " << rho << std::endl;
            std::cout << "Srednia liczba zgloszen w kolejce: " << average_v(rho, m) << std::endl;
            double average_t_f = average_v(rho, m)/lambda;
            std::cout << "Sredni czas oczekiwania zgloszenia w kolejce: " << average_t_f << std::endl;
            double average_n = average_v(rho, m)/rho;
            std::cout << "Srednia liczba zgloszen w systemie: " << average_n << std::endl;
            double average_t_s = average_n/lambda;
            std::cout << "Sredni czas przebywania zgloszenia w systemie: " << average_t_s << std::endl;
            double average_m_nz = m - rho;
            std::cout << "Sredni liczba niezajetych kanalow oblsugi: " << average_m_nz << std::endl;
            std::cout << "f(m) = " << C1 << " * " << average_v(rho, m) << " + " << C2 << " * " << average_m_nz << std::endl;
            std::cout << "Prawdopodbienstwo, ze system jest pusty: " << probability0(rho, m) << std::endl;
            probabilityj(rho, probability0(rho, m), m, 3);
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

double average_v (double rho, double m) {
    double counter = (pow(rho, (m+1))/pow((m-rho), 2)*factorial(m-1));
    double sum = 0;
    for (int j = 0; j <= (m-1); j++) {
        sum += pow(rho, j)/factorial(j);
    }
    double denominator = sum + (pow(rho, m)/(factorial(m-1)*(m-rho)));
    double result = counter / denominator;

    return result;
}

double probability0 (double rho, double m) {
    double counter = m - rho;
    double sum = 0;
    for (int j = 0; j <= (m-1); j++) {
        sum += (m-j)*(pow(rho, 2)/factorial(j));
    }
    double result = counter/sum;

    return result;
}

void probabilityj (double rho, double p0, double m, int j) {
    for (int i = 0; i < j; i++) {
        if (i <= m) {
            std::cout << "p" << i << " = " << (pow(rho, i)/factorial(i))*p0 << std::endl;
        }
    }
}