#include <iostream>
#include<cmath>
#include <math.h>
//se llama el metodo
void ecuacion (float s, float d, float Ctiempo, float Cespacio, float deltaT, float deltaX, double ce, double ce_prim);

//ejecuta el codigo
int main (){
    //variables
    float phi_1 = 0.0;
    float phi_2 = 0.0;
    float deltaX = 2.0/30.0;
    float deltaT = 0.01;
    float tiempo = 1;
    float D = 1;
    float s = 1;
    float CTiempo = tiempo / deltaT;
    float CEspacio = 30;
    double ce = deltaT/deltaX;
    double ce_prim = ce;
    ecuacion(s, D, CTiempo, CEspacio, deltaT, deltaX, ce, ce_prim);
   
 return 0;
}




//metodos
void ecuacion (float s, float d, float Ctiempo, float Cespacio, float deltaT, float deltaX, double ce, double ce_prim){
    float anterior[30];
    float actual[30];
 for ( int l = 0; l < Cespacio; l++){
            anterior[l] = 0;
        }
    for (int i = 0; i < Ctiempo; i ++){
        std::cout<<std::endl;
        for (int k = 0; k < Cespacio; k++){
            std::cout << anterior[k]<< "\t";
        }
        std::cout<<std::endl;
        for (int j = 0; j < Cespacio; j ++)
        {
            if (j == 0 || j == Cespacio-1){
                actual[j] = 0;
            }
            else{
                actual [j] = 2*anterior[j] - anterior[j-1] + ((ce*ce)/(ce_prim*ce_prim)) * (anterior[j+1] + anterior[j-1] - (2* anterior[j]));        
            }
           
        }
        for ( int l = 0; l < Cespacio; l++){
            anterior[l] = actual[l];
        }
         
    }
}