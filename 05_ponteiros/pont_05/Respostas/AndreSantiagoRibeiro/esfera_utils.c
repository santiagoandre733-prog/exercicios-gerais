#include "esfera_utils.h"

void CalculaVolume (float R, float *volume){
    *volume = (4*R*R*R*PI)/3;
}

void CalculaArea (float R, float *area){
    *area = PI*R*R*4;
}