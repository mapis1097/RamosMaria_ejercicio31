#include <iostream>
#include<cmath>
#include <math.h>
//se llama el metodo
void ecuacion (float L, int Ctiempo, int Cespacio, float deltaT, float deltaX, double ce, double ce_prim);

//ejecuta el codigo
int main (){
    //variables
    
    float L = 1;
    float deltaX = 1.0/100.0;
    float deltaT = 0.0001;
    float tiempo = 0.1;
    int Cespacio = (int)((L/deltaX) + 1);
    int CTiempo = (int)(tiempo/deltaT);
    double ce = 63.24;
    double ce_prim = deltaX/deltaT;
    ecuacion(L, CTiempo, (int)Cespacio, deltaT, deltaX, ce, ce_prim);
   
 return 0;
}




//metodos
void ecuacion (float L, int Ctiempo, int Cespacio, float deltaT, float deltaX, double ce, double ce_prim){
    float anterior[Cespacio];
    float actual[Cespacio];
    float anterior_2[Cespacio];
    float pi = asin(1.0) * 2.0;
    for ( int l = 0; l < Cespacio; l++){
            anterior_2[l] = pow(10,-4)*sin((2*pi * deltaX * l)/L) ;
        }
    
     for ( int l = 0; l < Cespacio; l++){
         if (l == 0 || l == Cespacio-1){
            anterior[l] = 0;
         }
        else
            anterior[l] = anterior_2[l] + (ce*ce)/(2*ce_prim*ce_prim) * (anterior_2[l+1] + anterior_2[l-1] - (2* anterior_2[l]));
        }
    
     for (int i = 2; i < Ctiempo; i ++){
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
                actual [j] = 2*anterior[j] - anterior_2[j] + ((ce*ce)/(ce_prim*ce_prim)) * (anterior[j+1] + anterior[j-1] - (2* anterior[j]));        
            }
           
        }
        for ( int l = 0; l < Cespacio; l++){
            
            anterior_2[l] = anterior[l];
            anterior[l] = actual[l];
        }
         
    }
}