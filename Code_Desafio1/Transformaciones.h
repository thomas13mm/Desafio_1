#ifndef TRANSFORMACIONES_H
#define TRANSFORMACIONES_H
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

#endif // TRANSFORMACIONES_H
