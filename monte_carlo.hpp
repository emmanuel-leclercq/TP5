#include <random>

class RNG {
public:
    virtual std::mt19937 operator()() = 0;
};

class RandomVariable {
public:
    virtual double operator()(std::mt19937 &G) = 0;
};

class Measurement {
public:
    virtual double operator()(double x) = 0;
};

class Statistique {
public:
    virtual void operator()(double x) = 0;
    virtual double result() = 0;
};


template <class Statistique, class RandomVariable, class Measurement, class RNG>
void MonteCarlo(Statistique &res, RandomVariable &X, const Measurement &f, RNG &G, long unsigned int n);