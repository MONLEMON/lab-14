#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double src[],int n,double dest[]){
    double sum,max = src[0],min = src[0];
    double mean,stand,gm,HM,sumgm = 1,sumstand = 0,sumHM = 0;
    for(int i=0; i<n ;i++){
        sum += src[i];
        sumgm *= src[i];
        sumHM += 1/src[i];
        if(src[i]>max) max=src[i];
        if(src[i]<min) min=src[i];
    }
    mean = sum/n;
    gm = pow(sumgm,(float)1 / n);
    HM = n/sumHM;
    for(int i=0; i<n ;i++){
        sumstand += pow((src[i]-mean),2);
    }
    stand = sqrt((sumstand/(n)));
   dest[0] = mean;
   dest[1] = stand;
   dest[2] = gm;
   dest[3] = HM;
   dest[4] = max;
   dest[5] = min;
}