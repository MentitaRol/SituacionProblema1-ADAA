#ifndef SUFFIXARRAY_H
#define SUFFIXARRAY_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

void quickSort(vector<int>& suffixArray, int low, int high, const string& text) {
if (low < high) {
int indexPivot = partition(suffixArray, low, high, text);
quickSort(suffixArray, low, indexPivot - 1, text);
quickSort(suffixArray, indexPivot + 1, high, text);
}
}

// Construye y devuelve el Suffix Array para el texto dado.
vector<int> suffixArray(const string& text) {
int longitud_text = static_cast<int>(text.length());
vector<int> suffixArray;

for (int i = 0; i < longitud_text; ++i) {
suffixArray.push_back(i);
}
if (!suffixArray.empty())
quickSort(suffixArray, 0, longitud_text - 1, text);
return suffixArray;
}

// Muestra los sufijos ordenados (útil para depuración)
void showSuffixArray(const vector<int>& suffixArray, const string& text) {
for (int indexSuffix : suffixArray) {
cout << text.substr(indexSuffix) << endl;
}
}

#endif // SUFFIXARRAY_H