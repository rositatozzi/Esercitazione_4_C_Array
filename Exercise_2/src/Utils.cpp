#include <cmath>
#include "Utils.hpp"


double dotProduct(double* ptr1, double * ptr2, int n){
    double p = 0;
    for(int i = 0; i<n; i++){
        double a = ptr1[i];
        double b = ptr2[i];
        p = p + (a*b);
    }
    return p;

}
