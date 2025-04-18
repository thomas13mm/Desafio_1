#ifndef VALIDACIONES_H
#define VALIDACIONES_H
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

#endif // VALIDACIONES_H
