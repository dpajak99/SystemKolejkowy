#include "QueuingSystem.h"
#include <cmath>

QueuingSystem::QueuingSystem() {
    lambda = 1;
    my = 1;
    c1 = 1;
    c2 = 1;
    m = 1;
    rho = getRho();
}

QueuingSystem::QueuingSystem(double _lambda, double _my, double _c1, double _c2, int _m) {
    if (_m >= 1) {
        if (_lambda < (_m * _my)) {
            if (((_lambda/_my) / _m) < 1) {
                lambda = _lambda;
                my = _my;
                c1 = _c1;
                c2 = _c2;
                m = _m;
                rho = getRho();
            }
        }
    }
}

QueuingSystem::~QueuingSystem() {
    lambda = NULL;
    my = NULL;
    c1 = NULL;
    c2 = NULL;
    m = NULL;
}

double QueuingSystem::getLambda() const {
    return lambda;
}

double QueuingSystem::getMy() const {
    return my;
}

double QueuingSystem::getC1() const {
    return c1;
}

double QueuingSystem::getC2() const {
    return c2;
}

double QueuingSystem::getM() const {
    return m;
}

int QueuingSystem::factorial(int k) {
    int j = 1;
    for (int i = 1; i < k; i++) {
        j *= i;
    }
    return j;
}

double QueuingSystem::getRho() const {
    return lambda/my;
}

double QueuingSystem::getAverageV() const {
    double numeral = (pow(rho, (m+1))/pow((m-rho), 2)*factorial(m-1));
    double sum = 0;
    for (int i = 0; i <= (m-1); i++) {
        sum += pow(rho, i)/factorial(i);
    }
    double nominative = sum + (pow(rho, m)/(factorial(m-1)*(m-rho)));
    double result = numeral/nominative;

    return result;
}

double QueuingSystem::getAverageTf() const {
    return getAverageV()/lambda;
}

double QueuingSystem::getAverageN() const {
    return getAverageV()+rho;
}

double QueuingSystem::getAverageTs() const {
    return getAverageN()/lambda;
}

double QueuingSystem::getAverageMnz() const {
    return m - rho;
}

double QueuingSystem::getProbability(int j) {
    if (j == 0) {
        double nominal = m - rho;
        double sum = 0;
        for (int i = 0; i <= (m-1); i++) {
            sum += (m-j)*pow(rho, j)/factorial(j);
        }
        double result = nominal/sum;

        return result;
    } else if (j >= 1 && j <= m) {
        return pow(getRho(), j)/factorial(j)*getProbability(0);
    }
    return NULL;
}
