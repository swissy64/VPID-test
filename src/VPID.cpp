#include "VPID.h"
#include <algorithm>

void VPID::Set(double LA, double I_GAIN, double MAX, double MIN) {
    
    la = LA;
    ig = I_GAIN;
    max = MAX;
    min = MIN;
    pP = 0;
    pO = 0;

}

void VPID::paramtune(double LA, double I_GAIN){

    la = LA;
    ig = I_GAIN;

}

double VPID::Clamp(double value, double min_value, double max_value){
    
    if (value < min_value) {
        return min_value;
    } else if (value > max_value) {
        return max_value;
    } else {
        return value;
    }

}

double VPID::Cal(double target, double process){

    delta = process - pP;
    Output = Clamp(pO+ig*(target-(process+delta*la)),min,max);
    pO = Output;
    pP = process;

    return Output;
    
}