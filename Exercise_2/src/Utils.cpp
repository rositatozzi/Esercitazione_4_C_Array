#include <cmath>
#include "Utils.hpp"


double dotProduct(const double* const& ptr1, const double* const& ptr2, const unsigned int n){
    double p = 0;
    for(unsigned int i = 0; i<n; i++){
        double a = ptr1[i];
        double b = ptr2[i];
        p = p + (a*b);
    }
    return p;

}
