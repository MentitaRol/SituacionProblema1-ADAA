#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "manacher.h"

using namespace std;

void readfiles(){

    vector<string> files = {
        "transmission01.txt",
        "transmission02.txt",
        "mcode01.txt",
        "mcode02.txt",
        "mcode03.txt"
    };

    for(const auto& fileName : files){
        ifstream file(fileName);
        if(!file.is_open()){
            cout << "El archivo " << fileName << " no se pudo abrir" << endl;
            continue;
        }

        string text;

        cout << "Archivo: " << fileName << "\n";
        while(getline(file, text)){    
            cout << text << "\n";
        }

        cout << "\n";
        file.close();
    }
}

int main (){

    vector<string> transmissionFiles = {
        "transmission01.txt",
        "transmission21.txt",
    };

    for(int i = 0; i < transmissionFiles.size(); i++){
        cout << transmissionFiles[i];
    }

    readfiles();

    return 0;
    
}