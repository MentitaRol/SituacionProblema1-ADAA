#ifndef LCS_H
#define LCS_H

#include <string>
#include <vector>

using namespace std;

// Devuelve un vector<int> con dos enteros 1-based: {inicio, fin} en s1
// del substring común más largo que aparece también en s2.
// Si no existe substring común, devuelve {0,0}.
// En caso de empate por longitud, devuelve la primera aparición en s1.

/**
 * @brief Calcula el *longest common substring* (subcadena común más larga) entre s1 y s2.
 *        Devuelve las posiciones 1-based de inicio y fin en s1 de la subcadena encontrada.
 * @param s1 Cadena donde se busca la subcadena común.
 * @param s2 Cadena con la que se compara s1 para encontrar la subcadena común más larga.
 * @return vector<int> Vector de dos enteros {inicio, fin} 1-based en s1. Si no hay subcadena común devuelve {0,0}.
 */
vector<int> longestCommonSubstring(const string& s1, const string& s2) {
    int n = s1.size();
    int m = s2.size();
    if (n == 0 || m == 0) return {0,0};

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int maxLen = 0;
    int endPosS1 = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endPosS1 = i;
                }
            }
        }
    }

    if (maxLen == 0) return {0,0};
    int start = endPosS1 - maxLen + 1; // índice 1-based de inicio en s1
    int end = endPosS1; // índice 1-based de fin en s1
    return {start, end};
}

#endif // LCS_H