#include <iostream>
#include "Transformaciones.h"
#include "Validaciones.h"
#include "Data.h"
#include <string>
#include <QString>

using namespace std;

int main(){
    //Aqui van declaraciones "generales"
    int h=0;
    int w=0;
    int hm=0;
    int wm=0;
    int seed=0;
    int cantpixelseed=0;
    unsigned char* ptrID=loadPixels(QString("I_D.bmp"),w, h);
    w=0, h =0;
    unsigned char* ptrM=loadPixels(QString("M.bmp"), wm, hm);
    unsigned char* ptrIM=loadPixels(QString("I_M.bmp"), w, h);

    //Aqui Primer ciclo (for que itera sobre la cantidad de txt que hay para comparar)
    for(short int txtcont=6; txtcont>=0; txtcont--){
        string filename = "M" + to_string(txtcont) + ".txt";
        const char* txt = filename.c_str();
        unsigned int* ptrtxt=loadSeedMasking(txt, seed, cantpixelseed);
        unsigned char* ptrIk=new unsigned char [h*w];//apuntador a arreglo dinamico que va guardar la imagen despues de enmascarar y transformar
        unsigned short operacion=5;
        unsigned short int cont=1;
        bool ban = true;
        //Segundo ciclo (mientras que ID sea diferente de txt)
        do{
            switch(operacion){
            case 1://intentar desplazamiento a la izquierda
                while(cont<=8 && ban){
                    for(int i =0; i<(h*w); i++){

                        ptrIk[i]=Left(ptrID[i],cont);
                    }

                    if(compararArreglos(ptrIk, ptrtxt,h*w,cantpixelseed, seed)){

                        //enmascarar Ik
                        mask(ptrM ,ptrIk, wm, hm, seed);

                        delete[] ptrID;
                        ptrID=ptrIk;
                        ptrIk=nullptr;
                        ban=false;
                    }
                    cont++;
                }
                operacion--;
                break;

            case 2://intentar desplazamiento a la derecha
                while(cont<=8 && ban){
                    for(int i =0; i<(h*w); i++){
                        ptrIk[i]=Right(ptrID[i], cont);
                    }

                    if(compararArreglos(ptrIk, ptrtxt,w*h,cantpixelseed,seed)){

                        //enmascarar Ik
                        mask(ptrM ,ptrIk, wm, hm, seed);

                        delete[] ptrID;
                        ptrID=ptrIk;
                        ptrIk=nullptr;
                        ban=false;
                    }
                    cont++;
                }
                operacion--;
                break;

            case 3://intentar rotacion a la izquierda
                while(cont<=8 && ban){
                    for(int i=0; i<(w*h);i++){
                        ptrIk[i]=rtLeft(ptrID[i], cont);  // Corregido *ptr[i] a ptrID[i]
                    }

                    if(compararArreglos(ptrIk, ptrtxt, h*w,cantpixelseed,seed)){

                        //enmascarar Ik
                        mask(ptrM ,ptrIk, wm, hm, seed);

                        delete[] ptrID;
                        ptrID=ptrIk;
                        ptrIk=nullptr;
                        ban=false;
                    }
                    cont++;
                }
                operacion--;
                break;

            case 4://intentar rotacion a la derecha
                while(cont<=8 && ban){
                    for (int i=0; i<(w*h); i++){
                        ptrIk[i]=rtRight(ptrID[i],cont);  // Corregido *ptrID[i] a ptrID[i]
                    }

                    if(compararArreglos(ptrIk, ptrtxt, h*w,cantpixelseed,seed)){ //Cada i de i=1 hasta i=8 se verifica si la rotacion es valida o no

                        //enmascarar Ik
                        mask(ptrM ,ptrIk, wm, hm, seed);

                        delete[] ptrID;
                        ptrID=ptrIk;
                        ptrIk=nullptr;
                        ban=false;
                    }
                    cont++;
                }
                operacion--;
                break;

            case 5: //intentar xor
                for (int i=0; i<(w*h); i++){
                    ptrIk[i]=XOR(int(ptrID[i]),int(ptrIM[i]));
                }

                if(compararArreglos(ptrIk, ptrtxt ,h*w , cantpixelseed, seed)){

                    //enmascarar Ik
                    mask(ptrM ,ptrIk, wm, hm, seed);
                    exportImage(ptrIk, w, h, QString("C:/Users/Thomas/Desktop/Original.bmp"));

                    delete[] ptrID;
                    ptrID=ptrIk;
                    ptrIk=nullptr;
                    ban=false;
                }
                operacion--;
                break;

            default:
                cout<<"Error al construir la imagen"<<endl;
                ban=false;
            }

            cont=1;
        } while(ban);
        //Aqui seteamos las variables a su punto "Inicial"
        delete[] ptrtxt;
        ptrtxt=nullptr;
        cantpixelseed = 0;
        seed=0;
    }
    delete[] ptrIM;
    delete[] ptrM;  // Corregido "M" a "ptrM"
    ptrIM=nullptr;
    ptrM=nullptr;  // Corregido "M" a "ptrM"
    //QString ruta= "C:\Usuarios\Thomas\Escritorio\I_D.bmp";  // Corregido las barras invertidas
    //QString ruta= 'C:\Users\Thomas\Desktop';
      // Corregido "k" a "h"
    cout<<"Ejecucion exitosa";
    delete[] ptrID;
    ptrID=nullptr;

    return 0;
}
