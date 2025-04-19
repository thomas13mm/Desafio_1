#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <iostream>
#include <cstring> // Para strcmp, strlen, strcat

bool compararArreglos(const int* arr1, const int* arr2, size_t size) {
    /**
 *  arr1 Puntero al primer arreglo de enteros
 *  arr2 Puntero al segundo arreglo de enteros
 * size Número de elementos a comparar en ambos arreglos.
 *  true Si todos los elementos son iguales en las mismas posiciones.
 *  false Si al menos un elemento difiere o si los arreglos tienen tamaños diferentes.
 */
    // Compara cada elemento de los arreglos
    for (size_t i = 0; i < size; ++i) {
        if (arr1[i] != arr2[i]) {
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
