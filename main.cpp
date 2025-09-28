/**
 * @file main.cpp
 * @authors
 *          Mauricio Olguín Sánchez - A01711522
 *          Luisa Fernanda Valdez Guillén – A01711870
 * @brief Programa principal que utiliza Suffix Array, Manacher y LCS para procesar transmisiones y códigos.
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "SuffixArray.h"
#include "manacher.h"
#include "LCS.h"

using namespace std;

/**
 * @brief Lee el archivo y concatena todas las líneas (eliminando saltos de línea).
 * 
 * @param filename el nombre del archivo a leer
 * @return string el contenido del archivo concatenado
 */
string readFileConcat(const string& filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        return string();
    }
    string line, content;
    while (getline(f, line)) content += line;
    return content;
}

/**
 * @brief Compara pattern con text empezando en index 'start'
 * 
 * @param text el texto donde se busca
 * @param start el índice inicial en text
 * @param pattern el patrón a buscar
 * @return true cuando pattern coincide con la subcadena de text que inicia en start
 * @return false cuando no coincide
 */
bool compareAt(const string& text, int start, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    if (start < 0 || start + m > n) return false;
    for (int i = 0; i < m; ++i) {
        if (text[start + i] != pattern[i]) return false;
    }
    return true;
}

/**
 * @brief Busca pattern en text usando el suffix array provisto en SuffixArray.h
 * 
 * @param text el texto donde se busca
 * @param pattern el patrón a buscar
 * @return int la posición 1-based donde se encontró el patrón, o 0 si no se encontró
 */
int findUsingSuffixArray(const string& text, const string& pattern) {
    if (pattern.empty()) return 1;
    if (text.size() < pattern.size()) return 0;
    vector<int> sa = suffixArray(text);
    for (int idx : sa) {
        if (compareAt(text, idx, pattern)) {
            return idx;
        }
    }
    return 0;
}

int main() {
    vector<string> transmissionFiles = {
        "transmission01.txt",
        "transmission02.txt"
    };

    vector<string> mcodeFiles = {
        "mcode01.txt",
        "mcode02.txt",
        "mcode03.txt"
    };

    // Leer transmisiones
    vector<string> transmissions;
    for (const auto& tf : transmissionFiles) {
        transmissions.push_back(readFileConcat(tf));
    }

    // PARTE 1: para cada transmisión y cada mcode -> true pos | false
    for (size_t t = 0; t < transmissions.size(); ++t) {
        const string& transmission = transmissions[t];
        cout << "----------------------------\n";
        cout << "Transmisión " << (t+1) << ":\n";
        for (const auto& mfile : mcodeFiles) {
            cout << "mcode " << mfile << ": ";
            string mcode = readFileConcat(mfile);
            int pos = findUsingSuffixArray(transmission, mcode);
            if (pos > 0) cout << "true " << pos << "\n";
            else cout << "false\n";
        }
        cout << "----------------------------\n";
    }

    // PARTE 2: palíndromo más largo en cada transmisión (start end)
    cout << "-----------------------------\n";
    cout << "Palíndromos más largos en cada transmisión:\n";
    for (const auto& transmission : transmissions) {
        cout << "Palíndromo más largo en la transmisión: " << transmission << " -> ";
        manacher(transmission);
    }
    cout << "-----------------------------\n";

    // PARTE 3: substring común más largo entre transmission01 y transmission02
    cout << "-----------------------------\n";
    if (transmissions.size() >= 2) {
        cout << "Subcadena común más larga entre transmisión 1 y 2: ";
        vector<int> lcsRes0 = longestCommonSubstring(transmissions[0], transmissions[1]);
        if (lcsRes0.size() != 2 || lcsRes0[0] == -1) {
            cout << "No se ha encontrado ninguna subcadena común.\n";
        } else {
            cout << (lcsRes0[0]) << " " << (lcsRes0[1]) << "\n";
        }
    } else {
        cout << "No hay suficientes transmisiones para comparar.\n";
    }
    cout << "-----------------------------\n";

    return 0;
}
