#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <iostream>
#include <cstring> // Para strcmp, strlen, strcat

bool compararArreglos(unsigned char* arr1, unsigned int* arr2, size_t size,unsigned int lines, int seed) {
    /**
 *  arr1 Puntero al primer arreglo de enteros
 *  arr2 Puntero al segundo arreglo de enteros
 * size Número de elementos a comparar en ambos arreglos.
 *  true Si todos los elementos son iguales en las mismas posiciones.
 *  false Si al menos un elemento difiere o si los arreglos tienen tamaños diferentes.
 */
    for(unsigned int k=0; k<(lines*3);k++){
        arr2[k]=arr2[k]%255;
    }
    // Compara cada elemento de los arreglos
    for (size_t i = 0, m=0 ; i < lines*3; ++i, m++) {
        //std::cout<<i<<' '<<int(arr1[i+seed])<<' '<<arr2[m]<<'\n';
        if (int(arr1[seed+i]) != arr2[m]) {
            return false; // Si algún elemento difiere, retorna false
        }
    }
    return true; // Si todos los elementos son iguales, retorna true
}

// Función que valida y ajusta el nombre del archivo usando memoria dinámica
char* validarNombreBMP(const char* nombreOriginal) {
    if (nombreOriginal == nullptr) return nullptr;

    // 1. Verificar si ya termina en .bmp
    int longitud = strlen(nombreOriginal);
    bool tieneBMP = false;

    if (longitud >= 4) {
        tieneBMP = (strcmp(nombreOriginal + longitud - 4, ".bmp") == 0);
    }

    // 2. Calcular el tamaño necesario para el nuevo nombre
    int nuevaLongitud = tieneBMP ? longitud : longitud + 4;
    char* nombreModificado = new char[nuevaLongitud + 1]; // +1 para el '\0'

    // 3. Copiar el nombre original
    strcpy(nombreModificado, nombreOriginal);

    // 4. Agregar .bmp si es necesario
    if (!tieneBMP) {
        strcat(nombreModificado, ".bmp");
    }

    return nombreModificado;
}


#endif // VALIDACIONES_H
