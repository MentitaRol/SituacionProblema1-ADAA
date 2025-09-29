/**
 * @file manacher.h
 * @author Luisa Fernanda Valdez Guillén – A01711870
 * @brief Implementación del algoritmo de Manacher para encontrar el palíndromo más largo en una cadena.
 * 
 */

#ifndef MANACHER_H_INCLUDED
#define MANACHER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Encuentra el palíndromo más largo en un texto utilizando el algoritmo de Manacher.
 *
 * Dada una cadena `text`, esta función:
 * - Convierte la cadena en un formato extendido para manejar de forma uniforme 
 *   palíndromos de longitud par e impar.
 * - Calcula la longitud máxima de palíndromos centrados en cada posición.
 * - Determina el palíndromo más largo y calcula su posición inicial y final
 *   en la cadena original (índices 0-based).
 * - Imprime en consola la posición inicial y final.
 *
 * @param text Cadena de entrada sobre la que se busca el palíndromo más largo.
 * 
 * @note Complejidad O(n), donde n es el tamaño del texto original.
 */

void manacher(const string &text){
    int N = text.size();
    N = 2 * N + 1;

    vector<int> palArray(N, 0);
    palArray[0] = 0;
    palArray[1] = 1;
    int middle = 1;
    int middleRightPos = 2;
    int iMirror;
    int sizePal = 0;
    int maxPivo = 0;
    int difference = -1;
    int res = -1;
    int end = -1;

    for (int i = 2; i < N; i++){
        iMirror = 2 * middle - i;
        palArray[i] = 0;
        difference = middleRightPos - i;

        if(difference > 0){
            int min = palArray[iMirror];
            if(difference < palArray[iMirror]){
                min = difference;
                palArray[i] = min;
            }
        }

        while (((i + palArray[i]) < N && (i - palArray[i]) > 0) && (((i + palArray[i] + 1) % 2 == 0) ||
            (text[(i + palArray[i] + 1) / 2] == text[(i - palArray[i] - 1) / 2]))){

            palArray[i]++;

        }

        if (palArray[i] > sizePal) {
            sizePal = palArray[i];
            maxPivo = i;
        }

        if (i + palArray[i] > middleRightPos) {
            middle = i;
            middleRightPos = i + palArray[i];
        }
    }

    res = (maxPivo - sizePal) / 2;
    end = res + sizePal - 1;

    cout << res << " " << end << endl;
}

#endif


