#include <iostream>
#include <cmath>
#include "QueuingSystem.h"

int main() {
    QueuingSystem q1 = QueuingSystem(0.244, 0.300, 2, 4.5, 2);
            std::cout << "Lambda: " << q1.getLambda() << std::endl;
            std::cout << "My: " << q1.getMy() << std::endl;
            std::cout << "C1: " << q1.getC1() << std::endl;
            std::cout << "C2: " << q1.getC2() << std::endl;
            std::cout << "m: " << q1.getM() << std::endl;
            std::cout << "Srednia liczba zajetych kanalow obslugi: " << q1.getRho() << std::endl;
            std::cout << "Srednia liczba zgloszen w kolejce: " << q1.getAverageV() << std::endl;
            std::cout << "Sredni czas oczekiwania zgloszenia w kolejce: " << q1.getAverageTf() << std::endl;
            std::cout << "Srednia liczba zgloszen w systemie: " << q1.getAverageN()<< std::endl;
            std::cout << "Sredni czas przebywania zgloszenia w systemie: " << q1.getAverageTs() << std::endl;
            std::cout << "Sredni liczba niezajetych kanalow oblsugi: " << q1.getAverageMnz() << std::endl;
            std::cout << "f(m) = " << q1.getC1() << " * " << q1.getAverageV() << " + " << q1.getC2() << " * " << q1.getAverageMnz() << std::endl;
            std::cout << "Prawdopodbienstwo, ze system jest pusty: " << q1.getProbability(0) << std::endl;
            std::cout << "Prawdopodbienstwo, ze system jest pusty: " << q1.getProbability(1) << std::endl;

    return 0;
}