#include "QueuingSystem.h"
#include <cmath>

/**
Próba generalna pusha!
*/

QueuingSystem::QueuingSystem(double _lambda, double _my, double _c1, double _c2, int _m) {
    if ( isMCorrect( _m ) && isLambdaCorrect(_lambda, _m, _my)) {
        lambda = _lambda;
        my = _my;
        c1 = _c1;
        c2 = _c2;
        m = _m;
        rho = calcRho();
        averageV = calcAverageV();
        averageTf = calcAverageTf();
        averageN = calcAverageN();
        averageTs = calcAverageTs();
        averageMnz = calcAverageMnz();
        p0 = getProbability(0);
    }
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

double QueuingSystem::getRho() const {
    return m;
}

double QueuingSystem::getAverageV() const {
    return averageV;
}

double QueuingSystem::getAverageTf() const {
    return averageTf;
}

double QueuingSystem::getAverageN() const {
    return averageN;
}

double QueuingSystem::getAverageTs() const {
    return averageTs;
}

double QueuingSystem::getAverageMnz() const {
    return averageMnz;
}

double QueuingSystem::calcRho() const {
    return lambda / my;
}

double QueuingSystem::calcAverageTf() const {
    return averageV / lambda;
}

double QueuingSystem::calcAverageN() const {
    return averageV + rho;
}

double QueuingSystem::calcAverageTs() const {
    return averageN / lambda;
}

double QueuingSystem::calcAverageMnz() const {
    return m - rho;
}

int QueuingSystem::factorial(int k) {
    int j = 1;
    for (int i = 1; i < k; i++) {
        j *= i;
    }
    return j;
}

double QueuingSystem::calcAverageV() const {
    double numeral = (pow(rho, (m + 1)) / pow((m - rho), 2) * factorial(m - 1));
    double sum = 0;
    for (int i = 0; i <= (m - 1); i++) {
        sum += pow(rho, i) / factorial(i);
    }
    double nominative = sum + (pow(rho, m) / (factorial(m - 1) * (m - rho)));
    double result = numeral / nominative;

    return result;
}

double QueuingSystem::getProbability(int j) const {
    if (j == 0) {
        double nominal = m - rho;
        double sum = 0;
        for (int i = 0; i <= (m - 1); i++) {
            sum += (m - i) * pow(rho, i) / factorial(i);
        }
        double result = nominal / sum;
        return result;
    } else if (j >= 1 && j <= m) {
        return pow(rho, j) / factorial(j) * p0;
    }
    return 0.0;
}

bool QueuingSystem::isMCorrect( int _m ) {
    if( _m >= 1 ) {
        return true;
    }
    return false;
}

bool QueuingSystem::isLambdaCorrect(double _lambda, int _m, double _my) {
    if(_lambda < (_m * _my) && ((_lambda / _my) / _m) < 1) {
        return true;
    }
    return false;
}

