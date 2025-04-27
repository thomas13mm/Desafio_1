#include <iostream>
#include "Transformaciones.h"
#include "Validaciones.h"
#include "Data.h"
#include <string>
#include <QString>

using namespace std;


int main() {
    int h = 0, w = 0;
    int hm = 0, wm = 0;
    int seed = 0;
    int cantpixelseed = 0;
    int numTxtFiles = 0;

    string operacionesRealizadas = "";  // <- Aquí guardamos las operaciones exitosas

    // Solicitar al usuario el número de archivos txt
    cout << "Ingrese el numero de archivos txt: ";
    cin >> numTxtFiles;

    // Validar que sea un número positivo
    if (numTxtFiles < 0) {
        cout << "Error: Debe ingresar un numero positivo." << endl;
        return 1;
    }

    unsigned char* ptrID = loadPixels(QString("I_D.bmp"), w, h);
    w = 0; h = 0;
    unsigned char* ptrM = loadPixels(QString("M.bmp"), wm, hm);
    unsigned char* ptrIM = loadPixels(QString("I_M.bmp"), w, h);

    for (short int txtcont = numTxtFiles; txtcont >= 0; txtcont--) {
        string filename = "M" + to_string(txtcont) + ".txt";
        const char* txt = filename.c_str();
        unsigned int* ptrtxt = loadSeedMasking(txt, seed, cantpixelseed);

        // Verificar si el archivo se cargó correctamente
        if (ptrtxt == nullptr) {
            cout << "Advertencia: No se pudo cargar el archivo " << filename << ". Continuando..." << endl;
            continue;  // Saltar a la siguiente iteración si el archivo no existe
        }

        unsigned int* ptrIk = new unsigned int[h * w * 3];
        unsigned short operacion = 5;
        unsigned short int cont = 1;
        bool ban = true;

        do {
            switch (operacion) {
            case 1:
                while (cont <= 8 && ban) {
                    for (int i = 0; i < h * w * 3; i++)
                        ptrIk[i] = Left(ptrID[i], cont);
                    mask(ptrM, ptrIk, wm, hm, seed);
                    if (compararArreglos(ptrIk, ptrtxt, h * w * 3, cantpixelseed, seed)) {
                        operacionesRealizadas += "- Desplazamiento a la izquierda con " + to_string(cont) + " bits\n";
                        unmask(ptrM, ptrIk, wm, hm, seed);
                        fromIntToChar(ptrIk, ptrID, h * w * 3);
                        delete[] ptrIk;
                        ptrIk = nullptr;
                        ban = false;
                    } else
                        cont++;
                }
                operacion--;
                break;

            case 2:
                cont = 1;
                while (cont <= 8 && ban) {
                    for (int i = 0; i < h * w * 3; i++)
                        ptrIk[i] = Right(ptrID[i], cont);
                    mask(ptrM, ptrIk, wm, hm, seed);
                    if (compararArreglos(ptrIk, ptrtxt, h * w * 3, cantpixelseed, seed)) {
                        operacionesRealizadas += "- Desplazamiento a la derecha con " + to_string(cont) + " bits\n";
                        unmask(ptrM, ptrIk, wm, hm, seed);
                        fromIntToChar(ptrIk, ptrID, h * w * 3);
                        delete[] ptrIk;
                        ptrIk = nullptr;
                        ban = false;
                    } else
                        cont++;
                }
                operacion--;
                break;

            case 3:
                cont = 1;
                while (cont <= 8 && ban) {
                    for (int i = 0; i < h * w * 3; i++)
                        ptrIk[i] = rtLeft(ptrID[i], cont);
                    mask(ptrM, ptrIk, wm, hm, seed);
                    if (compararArreglos(ptrIk, ptrtxt, h * w * 3, cantpixelseed, seed)) {
                        operacionesRealizadas += "- Rotacion a la izquierda con " + to_string(cont) + " bits\n";
                        unmask(ptrM, ptrIk, wm, hm, seed);
                        fromIntToChar(ptrIk, ptrID, h * w * 3);
                        delete[] ptrIk;
                        ptrIk = nullptr;
                        ban = false;
                    } else
                        cont++;
                }
                operacion--;
                break;

            case 4:
                cont = 1;
                while (cont <= 8 && ban) {
                    for (int i = 0; i < h * w * 3; i++)
                        ptrIk[i] = rtRight(ptrID[i], cont);
                    mask(ptrM, ptrIk, wm, hm, seed);
                    if (compararArreglos(ptrIk, ptrtxt, h * w * 3, cantpixelseed, seed)) {
                        operacionesRealizadas += "- Rotacion a la derecha con " + to_string(cont) + " bits\n";
                        unmask(ptrM, ptrIk, wm, hm, seed);
                        fromIntToChar(ptrIk, ptrID, h * w * 3);
                        delete[] ptrIk;
                        ptrIk = nullptr;
                        ban = false;
                    } else
                        cont++;
                }
                operacion--;
                break;

            case 5:
                for (int i = 0; i < h * w * 3; i++) {
                    ptrIk[i] = XOR(int(ptrID[i]), int(ptrIM[i]));
                }
                mask(ptrM, ptrIk, wm, hm, seed);
                if (compararArreglos(ptrIk, ptrtxt, h * w * 3, cantpixelseed, seed)) {
                    operacionesRealizadas += "- XOR con la imagen I_M\n";
                    unmask(ptrM, ptrIk, wm, hm, seed);
                    fromIntToChar(ptrIk, ptrID, h * w * 3);
                    delete[] ptrIk;
                    ptrIk = nullptr;
                    ban = false;
                }
                operacion--;
                break;

            default:
                cout << "Error al construir la imagen" << endl;
                ban = false;
                break;
            }

        } while (ban);

        if (ptrtxt != nullptr) {
            delete[] ptrtxt;
            ptrtxt = nullptr;
        }
        cantpixelseed = 0;
        seed = 0;
    }

    // Mostrar operaciones realizadas antes de exportar
    cout << "Operaciones realizadas:" << endl;
    cout << operacionesRealizadas << endl;

    exportImage(ptrID, w, h, QString("C:/Users/IVAN/Downloads/Original.bmp"));

    delete[] ptrIM;
    delete[] ptrM;
    delete[] ptrID;
    ptrIM = ptrM = ptrID = nullptr;

    cout << "Ejecucion exitosa" << endl;
    return 0;
}

