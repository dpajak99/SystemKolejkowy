#ifndef SYSTEMKOLEJKOWY_QUEUINGSYSTEM_H
#define SYSTEMKOLEJKOWY_QUEUINGSYSTEM_H

class QueuingSystem {
private:
    double lambda, my, c1, c2;
    int m;
    double rho, averageV, averageTf, averageN, averageTs, averageMnz;
public:
    QueuingSystem ();
    QueuingSystem (double, double, double, double, int);
    ~QueuingSystem();

    double getLambda () const;
    double getMy () const;
    double getC1 () const;
    double getC2 () const;
    double getM () const;
    double getRho () const;
    double getAverageV () const;
    double getAverageTf () const;
    double getAverageN () const;
    double getAverageTs () const;
    double getAverageMnz () const;

    static int factorial (int);
    double calcRho () const;
    double calcAverageV () const;
    double calcAverageTf () const;
    double calcAverageN () const;
    double calcAverageTs () const;
    double calcAverageMnz () const;
    double getProbability (int);
};

#endif //SYSTEMKOLEJKOWY_QUEUINGSYSTEM_H
