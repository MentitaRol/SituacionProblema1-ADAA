#ifndef SUFFIXARRAY_H
#define SUFFIXARRAY_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief 
 * 
 * @brief Función de partición para QuickSort. Toma el último elemento como pivote.
 * @param suffixArray El arreglo de índices de sufijos.
 * @param low El índice inicial del subarreglo.
 * @param high El índice final del subarreglo.
 * @param text La cadena original para comparar los sufijos.
 * @return La nueva posición del pivote.
 */
int partition(vector<int>& suffixArray, int low, int high, const string& text) {
    string suffixPivot = text.substr(suffixArray[high]);
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (text.substr(suffixArray[j]) < suffixPivot) {
            i++;
            swap(suffixArray[i], suffixArray[j]);
        }
    }
    swap(suffixArray[i + 1], suffixArray[high]);
    return (i + 1);
}

/**
 * @brief Ordena el arreglo de sufijos utilizando el algoritmo QuickSort de forma recursiva.
 * @param suffixArray El arreglo de índices de sufijos a ordenar.
 * @param low El índice inicial del subarreglo a ordenar.
 * @param high El índice final del subarreglo a ordenar.
 * @param text La cadena original para realizar las comparaciones.
 */
void quickSort(vector<int>& suffixArray, int low, int high, const string& text) {
    if (low < high) {
        int indexPivot = partition(suffixArray, low, high, text);
        quickSort(suffixArray, low, indexPivot - 1, text);
        quickSort(suffixArray, indexPivot + 1, high, text);
    }
}

/**
 * @brief Construye el Suffix Array para un texto dado.
 * @param text La cadena de caracteres original.
 * @return Un vector de enteros (Suffix Array) con los índices de los sufijos ordenados alfabéticamente.
 */
vector<int> suffixArray(const string& text) {
    int longitud_text = text.length();
    vector<int> suffixArray;
    for (int i = 0; i < longitud_text; ++i) {
        suffixArray.push_back(i);
    }
    if (!suffixArray.empty()) quickSort(suffixArray, 0, longitud_text - 1, text);
    return suffixArray;
}

/**
 * @brief Muestra el contenido del Suffix Array de forma legible.
 * @param suffixArray El arreglo de sufijos ya ordenado.
 * @param text La cadena de caracteres original.
 */
void showSuffixArray(const vector<int>& suffixArray, const string& text) {
    for (int indexSuffix : suffixArray) {
        cout << text.substr(indexSuffix) << endl;
    }
}

#endif // SUFFIXARRAY_H