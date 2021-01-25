/**
Definicja elementów klasy QueuingSystem potrzebnych do policzenia wartośći
potrzebnych do opisu systemu kolejkowego.
*/

#include "QueuingSystem.h"
#include <cmath>

/**
Definicja jednynego kostruktora który przyjmuje wszystkie potrzebny parametry
czyli: lambda, my, c1, c2 i m. Poczym wykorzystując pozostałe metody klasy oblicza
wszystkie parametry.

lambda - ilośc zgłoszeń na jednostek czasu.
my - intesywnośc obsługi.
c1 i c2 to parametry zależne od systemu koljekowego.
m - liczba kanałów obsługi.
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

/**
Początek bloku getter'ów wszystkich parametrów stworzonego systemu kolejkowego
*/

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

/**
Koniec bloku getter'ów wszystkich parametrów stworzonego systemu kolejkowego
*/

/**
Metoda licząca średnią liczbę zajętych kanałów obsługi czyli rho
z ilości zgłoszeń w jednostce czasu (lamba) i parametru intesywnośći obsługi (my).
*/

double QueuingSystem::calcRho() const {
    return lambda / my;
}

/**
Metoda licząca średni czas oczekiwania zgloszenia w kolejce
z średniej liczy zgłoszeń w kolejce (averageV) i ilości zgłoszeń w jednostce czasu (lambda)
*/

double QueuingSystem::calcAverageTf() const {
    return averageV / lambda;
}

/**
Metoda licząca srednia liczba zgloszen w systemie w kolejce
z średniego czasu oczekiwania zgloszenia (averageV) i średniej liczby zajętych kanałów obsługi (rho).
*/

double QueuingSystem::calcAverageN() const {
    return averageV + rho;
}

/**
Metoda licząca sredni czas przebywania zgloszenia w kolejce
z sredniej liczby zgloszen w systemie (averageN) i średniej liczy zgłoszeń w jednostce czasu (lambda).
*/

double QueuingSystem::calcAverageTs() const {
    return averageN / lambda;
}

/**
Metoda licząca srednią liczbe niezajetych kanalow oblsugi
z liczy kanałów obsługi (m) i średniej liczby zajętych kanałów obsługi (rho).
*/

double QueuingSystem::calcAverageMnz() const {
    return m - rho;
}

/**
Funkcja licząca silnię która wykorzystuje się w obliczeniach innych metod.
Zwraca silnie z podanego parametru w argumecie funkcji.
*/

int QueuingSystem::factorial(int k) {
    int j = 1;
    for (int i = 1; i < k; i++) {
        j *= i;
    }
    return j;
}

/**
Metoda licząca srednia liczba zgloszen w kolejce.
Wkorzustuje rho, m i metode liczącą silnie.
*/

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

/**
Metoda licząca szanse na zaistnienie zdarzenia w którym system kolejkowy jest pusty
i nie obsługuje żadnego klienta/nie pracuje na żadnym produkcie.
*/

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

/**
Metody sprawdzające czy podane parametry m i Lamba są prawidłowe.
*/

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

