/**
 * @file LCS.h
 * @authors Mauricio Olguín Sánchez - A01711522
 * @brief Implementación de Longest Common Substring (LCS) utilizando programación dinámica.
 * 
 */

#ifndef LCS_H
#define LCS_H

#include <string>
#include <vector>

using namespace std;

/**
 * @brief Calcula el longest common substring (subcadena común más larga) entre s1 y s2.
 *        Devuelve las posiciones 1-based de inicio y fin en s1 de la subcadena encontrada.
 * @param s1 Cadena donde se busca la subcadena común.
 * @param s2 Cadena con la que se compara s1 para encontrar la subcadena común más larga.
 * @return vector<int> Vector de dos enteros {inicio, fin} en s1. Si no hay subcadena común devuelve {-1,-1}.
 * 
 * @note Complejidad: O(n*m), donde n = |s1| y m = |s2|.
 */
vector<int> longestCommonSubstring(const string& s1, const string& s2) {
    int n = s1.size();
    int m = s2.size();
    if (n == 0 || m == 0) return {-1,-1};

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

    if (maxLen == 0) return {-1,-1};
    int start = endPosS1 - maxLen; 
    int end = endPosS1 - 1;
    return {start, end};
}

#endif // LCS_H