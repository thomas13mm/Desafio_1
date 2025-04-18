#include <iostream>
#include "Transformaciones.h"
#include "Validaciones.h"
#include "Data.h"
#include <string>


using namespace std;

int main(){
    //Aqui van declaraciones "generales"
    unsigned short int txtcont=3;
    unsigned int h=0;
    unsigned int w=0;
    unsigned int seed=0;
    unsigned int cantpixelseed=0;
    const int* ptrIM=loadPixels("I_M.bmp",NULL,NULL);
    char* ptrID=nullptr;
    int* ptrtxt=nullptr;

    //Aqui Primer ciclo (for que itera sobre la cantidad de txt que hay para comparar)
    for(txtcont; txtcont>=0; txtcont--){
        ptrID=loadPixels("I_D.bmp",w, h);
        ptrtxt=loadSeedMasking("M" + string(txtcont) + ".txt", seed, cantpixelseed);
        unsigned short operacion=5;
        bool ban = true;
        //Segundo ciclo (mientras que ID sea diferente de txt)
        do{
            switch(operacion){
            case 1://intentar desplazamiento a la izquierda
                for(){

                }
            case 2://intentar desplazamiento a la derecha
                for(){

                }
            case 3://intentar rotacion a la izquierd
                for(){

                }
            case 4://intentar rotacion a la derecha
                for (){

                }
            case 5: //intentar xor
                for (unsigned int i=0; i<(w*h); i++){
                    XOR(int(ptrID[i]), );
                }
            }

            //hacer enmascaramiento y comparar con el arreglo de enteros del txt aqui y cambiar el valor de ban si es necesario
            ban=false;

        }
        while(ban);
        //Aqui seteamos las variables a su punto "Inicial"
        delete[] ptrID;
        delete[] ptrtxt;
        ptrtxt=nullptr;
        ptrID=nullptr;
        h, w, seed, cantpixelseed = 0;
    }

    return 0;
}
