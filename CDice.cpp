#include "CDice.h"
using namespace std;
CDice::CDice() {
    for(int i = 1; i <= NUM_FACES ; i++){
        faceRolled[i] = 0;
    }
}
int CDice::roll() {
    int n = rand()%NUM_FACES + 1;
    faceRolled[n]++;
    return n;
}

void CDice::afisare() {
    for (int i = 1; i <= NUM_FACES; i++){
        cout<<"\n"<<faceRolled[i]<<" ";
    }
}

CDice::~CDice() {
    delete[] faceRolled;//dtor
    cout<<"Deleted dice";
}
