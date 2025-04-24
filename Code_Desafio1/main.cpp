
#include <iostream>
#include "Transformaciones.h"
#include "Validaciones.h"
#include "Data.h"
#include <string>
#include <QString>

using namespace std;

int main(){
    int h = 0, w = 0;
    int hm = 0, wm = 0;
    int seed = 0;
    int cantpixelseed = 0;

    unsigned char* ptrID = loadPixels(QString("I_D.bmp"), w, h);
    w = 0; h = 0;  // Reinicializar para IM
    unsigned char* ptrM = loadPixels(QString("M.bmp"), wm, hm);
    unsigned char* ptrIM = loadPixels(QString("I_M.bmp"), w, h);

    for (short int txtcont = 6; txtcont >= 0; txtcont--) {
        string filename = "M" + to_string(txtcont) + ".txt";
        const char* txt = filename.c_str();
        unsigned int* ptrtxt = loadSeedMasking(txt, seed, cantpixelseed);
        unsigned char* ptrIk = new unsigned char[h * w];

        unsigned short operacion = 5;
        unsigned short int cont = 1;
        bool ban = true;

        do {
            switch (operacion) {
            case 1:  // desplazamiento a la izquierda
                while (cont <= 8 && ban) {
                    for (int i = 0; i < h * w; i++)
                        ptrIk[i] = Left(ptrID[i], cont);

                    mask(ptrM, ptrIk, wm, hm, seed);

                    if (compararArreglos(ptrIk, ptrtxt, h * w, cantpixelseed, seed)) {
                        unmask(ptrM, ptrIk, wm, hm, seed);
                        exportImage(ptrIk, w, h, QString("C:/Users/Thomas/Desktop/Original.bmp"));
                        delete[] ptrID;
                        ptrID = ptrIk;
                        ptrIk = nullptr;
                        ban = false;
                    }
                    else
                        cont++;
                }
                operacion--;
                break;

            case 2:  // desplazamiento a la derecha
                cont = 1;
                while (cont <= 8 && ban) {
                    for (int i = 0; i < h * w; i++)
                        ptrIk[i] = Right(ptrID[i], cont);

                    mask(ptrM, ptrIk, wm, hm, seed);

                    if (compararArreglos(ptrIk, ptrtxt, h * w, cantpixelseed, seed)) {
                        unmask(ptrM, ptrIk, wm, hm, seed);
                        exportImage(ptrIk, w, h, QString("C:/Users/Thomas/Desktop/Original.bmp"));
                        delete[] ptrID;
                        ptrID = ptrIk;
                        ptrIk = nullptr;
                        ban = false;
                    }
                    else
                        cont++;
                }
                operacion--;
                break;

            case 3:  // rotación a la izquierda
                cont = 1;
                while (cont <= 8 && ban) {
                    for (int i = 0; i < h * w; i++)
                        ptrIk[i] = rtLeft(ptrID[i], cont);

                    mask(ptrM, ptrIk, wm, hm, seed);

                    if (compararArreglos(ptrIk, ptrtxt, h * w, cantpixelseed, seed)) {
                        unmask(ptrM, ptrIk, wm, hm, seed);
                        exportImage(ptrIk, w, h, QString("C:/Users/Thomas/Desktop/Original.bmp"));
                        delete[] ptrID;
                        ptrID = ptrIk;
                        ptrIk = nullptr;
                        ban = false;
                    }
                    else
                        cont++;
                }
                operacion--;
                break;

            case 4:  // rotación a la derecha
                cont = 1;
                while (cont <= 8 && ban) {
                    for (int i = 0; i < h * w; i++)
                        ptrIk[i] = rtRight(ptrID[i], cont);

                    mask(ptrM, ptrIk, wm, hm, seed);

                    if (compararArreglos(ptrIk, ptrtxt, h * w, cantpixelseed, seed)) {
                        unmask(ptrM, ptrIk, wm, hm, seed);
                        exportImage(ptrIk, w, h, QString("C:/Users/Thomas/Desktop/Original.bmp"));
                        delete[] ptrID;
                        ptrID = ptrIk;
                        ptrIk = nullptr;
                        ban = false;
                    }
                    else
                        cont++;
                }
                operacion--;
                break;

            case 5:  // XOR con imagen I_M
                for (int i = 0; i < h * w; i++)
                    ptrIk[i] = XOR(int(ptrID[i]), int(ptrIM[i]));

                mask(ptrM, ptrIk, wm, hm, seed);

                if (compararArreglos(ptrIk, ptrtxt, h * w, cantpixelseed, seed)) {
                    unmask(ptrM, ptrIk, wm, hm, seed);
                    exportImage(ptrIk, w, h, QString("C:/Users/Thomas/Desktop/Original.bmp"));
                    delete[] ptrID;
                    ptrID = ptrIk;
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

        // Reset
        delete[] ptrtxt;
        ptrtxt = nullptr;
        cantpixelseed = 0;
        seed = 0;
    }

    delete[] ptrIM;
    delete[] ptrM;
    delete[] ptrID;
    ptrIM = ptrM = ptrID = nullptr;

    cout << "Ejecucion exitosa" << endl;
    return 0;
}
