#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <iostream>
#include <cstring> // Para strcmp, strlen, strcat

bool compararArreglos(unsigned int* arr1, unsigned int* arr2, size_t size, unsigned int lines, int seed) {


    // Verificar parámetros válidos
    if (arr1 == nullptr || arr2 == nullptr || size == 0 || lines == 0) {
        return false;
    }

    // Verificar que seed esté dentro de los límites
    //if (seed < 0 || (seed + lines * 3) > size) {
    //    return false;
    //}

    // Comparar cada componente (R, G, B) de los píxeles especificados
    for (unsigned int i = 0; i < lines * 3 && i<size; i++) {
        // Asegurar que el valor del TXT esté en rango 0-255

        std::cout<< i << ' '<< arr1[seed+i]<< ' '<< arr2[i]<<'\n';

        // Comparar con el valor de la imagen (teniendo en cuenta la seed)
        if (int(arr1[seed + i]) != arr2[i]) {
            return false;
        }
    }

    return true;
}



#endif // VALIDACIONES_H
