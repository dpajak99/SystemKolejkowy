#include <iostream>
#include <cmath>

//TODO DOMINIK - Poniżej jest opisane, że każda funkcja z osobna ma przyjmować odpowiednie wartości
int factorial (int);
double calculateRho (void);
double calculateAverageV (void);
double calculateAverageTf (void);
double calculateAverageN (void);
double calculateAverageTs (void);
double calculateAverageMnz (void);
double probability0 (void);
void probabilityj (int);

//TODO DOMINIK - Wszystkie metody wyodrębniłbym do osobnej klasy QueuingSystem.
// Łatwiejsza i bardziej przejrzysta integracja z frontendem. Lepsze nazewnictwo.
// (wtedy zamiast calc cośtam byłoby getRho, getProbability(int fromInteger, int toInteger).. itd )
// Dodatkowo wpłynie to na optymalizację programu, gdzyż w konstruktorze możemy wywołać metody obliczające
// powtarzające się wartości.

//TODO DOMINIK - Zmienna 'm' jest zawsze intem!
double lambda, my, m, C1, C2, rho;

int main() {
    lambda = 0.244;
    my = 0.300;
    m = 2;
    C1 = 4.5;
    C2 = 5.1;
    //TODO DOMINIK - do przemyslenia jak zrefaktoryzowac, poniewaz mamy tutaj Arrow Anti Pattern: http://wiki.c2.com/?ArrowAntiPattern
    if (m >= 1) {
        if (lambda < (m * my)) {
            rho = calculateRho();
            if ((rho/m) > 1) {
                //TODO DOMINIK - Oznaczyłbym to bardziej zrozumiałym błędem, bo z tego fragmentu kodu nic nie wynika.
                // (Może być tekstowym, bo pewnie później i tak będzie do zmiany)
                std::cout << "rho/m = " << rho/m << " < 1" << std::endl;
                return 0;
            }
            std::cout << "m_śr - Srednia liczba zajetych kanalow obslugi: " << rho << std::endl;
            std::cout << "v_śr - Srednia liczba zgloszen w kolejce: " << calculateAverageV() << std::endl;
            std::cout << "tf_śr - Sredni czas oczekiwania zgloszenia w kolejce: " << calculateAverageTf() << std::endl;
            std::cout << "n_śr - Srednia liczba zgloszen w systemie: " << calculateAverageN()<< std::endl;
            std::cout << "ts_sr - Sredni czas przebywania zgloszenia w systemie: " << calculateAverageTs() << std::endl;
            std::cout << "mnz_sr - Sredni liczba niezajetych kanalow oblsugi: " << calculateAverageMnz() << std::endl;
            //TODO DOMINIK - Wartość funkcji celu należy poza wypisaniem - obiczyć i wypisać wynik
            std::cout << "f(m) = " << C1 << " * " << calculateAverageV() << " + " << C2 << " * " << calculateAverageMnz() << std::endl;
            std::cout << "p0 - Prawdopodbienstwo, ze system jest pusty: " << probability0() << std::endl;
            probabilityj(3);
        } else {
            std::cout << "lambda > m*my " << lambda << " > " << (m * my) << std::endl;
        }
    } else {
        std::cout << m << "< 1" << std::endl;
    }

    return 0;
}

//Tests passed
int factorial (int i) {
    int j = 1;
    //TODO DOMINIK - Zwyczajowo przyjęło się, aby w pętlach używać zmiennej 'i'.
    // Wnoszę o refraktoryzację
    for (int k = 1; k < i; k++) {
        j *= k;
    }
    return j;
}

//Tests passed
double calculateRho () {
    //TODO DOMINIK - Lambda jest już zmienną typu double, więc po co powtarzać deklarację?
    return (double)lambda/my;
}

//Tests passed
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

//Tests passed
double calculateAverageTf () {
    return calculateAverageV()/lambda;
}

//********TESTS FAILED
//TODO DOMINIK - zły wzór, ma być:       n_śr = v_śr + m_śr
double calculateAverageN () {
    return calculateAverageV()/rho;
}

//********TESTS FAILED
// NOTE: po poprawce wzoru na n_śr, powinno być dobrze
double calculateAverageTs () {
    return calculateAverageN()/lambda;
}
//Tests passed
double calculateAverageMnz () {
    return m - rho;
}

//TODO DOMINIK - propability0 i propabilityJ wrzuciłbym do jednego getPropability z ifem w środku
//********TESTS FAILED
double probability0 () {
    //TODO DOMINIK - nazwy zmieniłbym na numeral i nominative, ale to już taka pierdoła XD
    // Dobrą praktyką jest poprawne nazywanie kodu i naeży zwracać na to uwagę
    double counter = m - rho;
    double sum = 0;
    //TODO DOMINIK - Przyjęło się używać zmienną 'i' w pętlach for, aczkolwiek we wzorze mamy zmienną 'k'
    // Wnoszę o zmianę na dowolnie wybraną zmienną z powyższych zmiennych (z czego preferuje chyba standardowe i)
    for (int j = 0; j <= (m-1); j++) {
        //TODO DOMINIK - Zły wzór na p_0 - Ma być:
        // (m-j)*pow(rho, j)/fractorial(j)
        sum += (m-j)*(pow(rho, 2)/factorial(j));
    }
    double result = counter/sum;

    return result;
}
//********TESTS FAILED
void probabilityj (int j) {
    //TODO DOMINIK - For do wywalenia / przeniesienia gdzie indziej ale o tym w następnej refraktorzacji.
    // Możemy obliczać prawdopodobieństwo od np 2 do np 4. I musimy ZWRACAĆ wartości a nie je wypisywać
    // Jak pisałem wcześniej - getPropability( int j )
    for (int i = 0; i < j; i++) {
        if (i <= m) {
            std::cout << "p" << i << " = " << (pow(rho, i) / factorial(i)) * probability0() << std::endl;
        }
    }
}