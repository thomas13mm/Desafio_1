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
    char* ptrID=loadPixels("I_D.bmp",w, h);;
    int* ptrtxt=nullptr;

    //Aqui Primer ciclo (for que itera sobre la cantidad de txt que hay para comparar)
    for(txtcont; txtcont>=0; txtcont--){
        ptrtxt=loadSeedMasking("M" + string(txtcont) + ".txt", seed, cantpixelseed);
        unsigned int* ptrIk=new unsigned int [h*w];//apuntador a arreglo dinamico que va guardar la imagen despues de enmascarar y transformar
        unsigned short operacion=5;
        unsigned short int new cont=1;
        bool ban = true;
        //Segundo ciclo (mientras que ID sea diferente de txt)
        do{
            switch(operacion){
            case 1://intentar desplazamiento a la izquierda
                while(cont<=8 && ban){
                    for(unsigned int i =0; i<=(h*k); i++){

                        ptrIk[i]=Left(*ptrID[i],cont);
                    }
                    //enmascarar Ik
                    if(compararArreglos(ptrIk, ptrtxt, h*w)){
                        delete[] ptrID;
                        ptrID=ptrIk;
                        ptrIk=nullptr;
                        ban=false;
                    }
                    cont++;
                }


            case 2://intentar desplazamiento a la derecha
                while(cont<=8 && ban){
                    for(unsigned int i =0; i<=(h*k); i++){
                        ptrIk[i]=Right(*ptrID[i], cont);
                    }
                    //enmascarar Ik

                    if(compararArreglos(ptrIk, ptrtxt, h*w)){
                        delete[] ptrID;
                        ptrID=ptrIk;
                        ptrIk=nullptr;
                        ban=false;
                    }
                    cont++;
                }


            case 3://intentar rotacion a la izquierd
                while(cont<=8 && ban){
                    for(unsigned int i=0; i<=(w*h);i++){
                        ptrIk[i]=rtLeft(*ptr[i], cont);
                    }
                    //enmascarar Ik

                    if(compararArreglos(ptrIk, ptrtxt, h*w)){
                        delete[] ptrID;
                        ptrID=ptrIk;
                        ptrIk=nullptr;
                        ban=false;
                    }
                    cont++;
                }

            case 4://intentar rotacion a la derecha
                while(cont<=8 && ban){
                    for (unsigned int i=0; i<=(w*h); i++){
                        ptrIk[i]=rtRight(*ptrID[i],cont);
                    }
                    //enmascarar Ik

                    if(compararArreglos(ptrIk, ptrtxt, h*w)){ //Cada i de i=1 hasta i=8 se verifica si la rotacion es valida o no
                        delete[] ptrID;
                        ptrID=ptrIk;
                        ptrIk=nullptr;
                        ban=false;
                    }
                    cont++;
                }


            case 5: //intentar xor
                for (unsigned int i=0; i<=(w*h); i++){
                    ptrIk[i]=XOR(int(ptrID[i]),ptrIM[i]);
                }
                //enmascarar Ik

                if(compararArreglos(ptrIk, ptrtxt, h*w)){
                    delete[] ptrID;
                    ptrID=ptrIk;
                    ptrIk=nullptr;
                    ban=false;
                }
            }

            cont=1;
        }
        while(ban);
        //Aqui seteamos las variables a su punto "Inicial"
        delete cont;
        delete[] ptrtxt;
        ptrtxt=nullptr;
        h, w, seed, cantpixelseed = 0;
    }
    delete[] ptrIM;
    ptrIM=nullptr;

    return 0;
}
