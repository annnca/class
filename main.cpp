#include <iostream>
#include "CDice.h"
using namespace std;

int main()
{
    int NO_ROLLS = 9000, i, j;
    int pairs[7][7];

    srand(time(NULL));

    CDice dice1, dice2;

    for(i = 1; i <= 6; i++){
        for(j = 1; j <= 6; j++){
           pairs[i][j] = 0;
        }
    }
    int consec = 1, Mconsec = 1;

    int a = dice1.roll();
    int b = dice2.roll();
    pairs[a][b]++;

    int c, d;
    int Mconsecroll1,Mconsecroll2;
    for(i = 1; i < NO_ROLLS; i++){
        c = dice1.roll();
        d = dice2.roll();
        pairs[c][d]++;
        if(a == c && b == d){
            consec++;
            if(consec > Mconsec){
                Mconsec = consec;
                Mconsecroll1 = c;
                Mconsecroll2 = d;
            }
        } else {
            consec = 1;
            a = c;
            b = d;
        }
    }
    int M = 0, m = 9000, Mi, Mj, mi, mj;
    for(i = 1; i <= 6; i++){
        for(j = 1; j <= 6; j++){
           cout<<pairs[i][j]<<" ";
           if(pairs[i][j] > M) {
                M = pairs[i][j];
                Mi = i;
                Mj = j;
           } else {
               if(pairs[i][j] < m) {
                   m = pairs[i][j];
                   mi = i;
                   mj = j;
               }
           }
        }
        cout<<endl;
    }

    cout<<"\nCele mai multe aparitii:"<<M<<": zarul1 "<<Mi<<", zarul2 "<<Mj;
    cout<<"\nCele mai putine aparitii:"<<m<<": zarul1 "<<mi<<", zarul2 "<<mj;
    cout<<"\nCele mai multe aparitii consecutive: "<<Mconsec<<" :zarul1 "<<Mconsecroll1<<", zarul2 "<<Mconsecroll2;

    return 0;
}
