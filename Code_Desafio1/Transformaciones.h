#ifndef TRANSFORMACIONES_H
#define TRANSFORMACIONES_H
#include "Data.h"
/*
 Modulo de operaciones para aplicar operaciones de transformacion */

unsigned int XOR(int a, int b){
    /*
Sinopsis:
    Funcion encargada de aplicar la operacion logica XOR a nivel de bits entre un numero a y un numero b
Parametros:
    -(int)a: Numero entero
    -(int)b: Numero entero
Returns:
    -(unsigned int)c: Valor decimal del numero binario resultante entre aplicar XOR entre a y b binarios
*/
    return a ^ b;
}

unsigned int Left(unsigned int bin, unsigned short pos){
    /*
Sinopsis:
    Funcion que reliza desplazamientos de bits hacia la izquierda
Parametros:
    -(unsigned int)bin: Binario que se va a desplazar (pos) posiciones
    -(unsiged short)pos: Cantidad de posiciones a desplzar el binario
Returns:
    -(unsigned int)k: Nuevo binario post desplazamiento
*/
    return bin<<pos;
}

unsigned int Right(unsigned int bin, unsigned short pos){
    /*
Sinopsis:
    Funcion que reliza desplazamientos de bits hacia la derecha
Parametros:
    -(unsigned int)bin: Binario que se va a desplazar (pos) posiciones
    -(unsiged short)pos: Cantidad de posiciones a desplzar el binario
Returns:
    -(unsigned int)k: Nuevo binario post desplazamiento
*/
    return bin>>pos;
}

unsigned int rtRight(unsigned int bin, unsigned short int r){
    /*
Sinopsis:
    Funcion que realiza rotaciones de bits hacia la derecha (right)
Parametros:
    -(unsigned int)bin: Binario que se va a rotar r posiciones a la derecha
    -(unsigned short int)r: Cantidad de posiciones que se va a desplzar el bin
Returns:
    -Nuevo binario
*/
    r %= 8;
    unsigned short int mask =8 - r; //mascara para bits de (8-0)
    return (((bin & 255) >> r) | ((bin & 255) << mask)) & 255;
}

unsigned int rtLeft(unsigned int bin, unsigned short int r){
    /*
Sinopsis:
    Funcion que realiza rotaciones de bits hacia la izquiera (izquierda)
Parametros:
    -(unsigned int)bin: Binario que se va a rotar r posiciones a la izquierda
    -(unsigned short int)r: Cantidad de posiciones que se va a desplazar el bin
Returns:
    -Nuevo binario
*/
    r %= 8;
    unsigned short int mask = 8 - r; //Para solo tomar 8 primeos bits
    return (((bin & 255) << r) | ((bin & 255) >> mask)) & 255;

}

void mask(unsigned char* mascara, unsigned int* I, unsigned int w, unsigned int h, int seed){
    /*
Sinopsis:
    Funcion encargada de enmascarar bits
Parametros:
    -(unsigned int )mascara:Variable que guarda la direccion de memoria de un arreglo dimanico con la mascara
    -(unsigned int )I: Variablr que guarda la direccion de memoria de un arreglo dinamico con la imagen a enmascarar
    -(unsigned int) h, w: altura y ancho de la mascara
    -(int) seed: pixel a partir del cual se aplica la mascara
*/
    unsigned int total_pixels = w * h *3;
    for (unsigned int k = 0 ; k < total_pixels;k++) {
        I[k+seed] = mascara[k] + I[k+seed];  // Modifica I directamente
    }
}

void unmask(unsigned char* mascara, unsigned int* I, unsigned int w, unsigned int h, int seed) {
    unsigned int total_pixels = w * h * 3;
    for (unsigned int k = 0; k < total_pixels; k++) {

        I[k+seed] = I[seed+k] - fromChartoInt(k,mascara);  ;  // Mismo XOR para deshacer
    }
}

#endif // TRANSFORMACIONES_H
