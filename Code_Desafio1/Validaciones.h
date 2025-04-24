#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <iostream>
#include <cstring> // Para strcmp, strlen, strcat

bool compararArreglos(unsigned char* arr1, unsigned int* arr2, size_t size, unsigned int lines, int seed) {


    // Verificar parámetros válidos
    if (arr1 == nullptr || arr2 == nullptr || size == 0 || lines == 0) {
        return false;
    }

    // Verificar que seed esté dentro de los límites
    if (seed < 0 || (seed + lines * 3) > size) {
        return false;
    }

    // Comparar cada componente (R, G, B) de los píxeles especificados
    for (unsigned int i = 0, m = 0; i < lines * 3; ++i, ++m) {
        // Asegurar que el valor del TXT esté en rango 0-255
        unsigned int valorTxt = arr2[m] % 256;

        // Comparar con el valor de la imagen (teniendo en cuenta la seed)
        if (arr1[seed + i] != valorTxt) {
            return false;
        }
    }

    return true;
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
