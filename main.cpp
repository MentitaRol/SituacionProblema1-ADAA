#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

        getline(file, text);

        file.close();

        cout << "Archivo: " << fileName << "\n";
        cout << text << "\n\n";
    }
}

int main (){

    readfiles();

    return 0;
    
}