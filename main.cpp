#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "manacher.h"

using namespace std;

string readFiles(const string &fileName){
    ifstream file(fileName);
    if(!file.is_open()){
        cout << "El archivo " << fileName << " no se pudo abrir" << endl;
        return "";
    }

    string text, line;

    while(getline(file, line)){
        text += line;    
    }

    file.close();
    return text;
}


int main (){
    vector<string> transmissions = {"transmission01.txt", "transmission02.txt"};
    vector<string> mcodes = {"mcode01.txt", "mcode02.txt", "mcode03.txt"};

    vector<string> files = {
        "transmission01.txt",
        "transmission02.txt",
        "mcode01.txt",
        "mcode02.txt",
        "mcode03.txt"
    };

    // vector<string> targets;
    // for (const auto &mfile : mcodes)
    //     targets.push_back(readFiles(mfile));

    for (const auto &files : files) {
        string text = readFiles(files);
        if (text.empty()){
            cout << "No se encontró el archivo";
        }

        cout << "Archivo: " << files << endl;
        cout << text << endl;

        cout << endl;
    }  

    for (const auto &transmissions : transmissions){
        string textTransmission =  readFiles(transmissions);
        if (textTransmission.empty()){
            cout << "No se encontró el archivo";
        }

        cout << "Posicion palindromo mas largo encontrado en: " << transmissions << endl;
        manacher(textTransmission);

        cout << endl;
    }
    
    // printFiles();

    return 0;
    
}