#ifndef CDICE_H
#define CDICE_H
#include <iostream>
#include <cstdlib>
#include <ctime>

class CDice
{
    public:
        static const int NUM_FACES = 6;
        int roll();
        void afisare();
        CDice();
        ~CDice();
    private:
        int faceRolled[NUM_FACES + 1];
};
#endif // CDICE_H
