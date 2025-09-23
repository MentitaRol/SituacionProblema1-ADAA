#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> files = {
    "transmission01.txt",
    "transmission21.txt",
    "mcode01.txt",
    "mcode02.txt",
    "mcode03.txt"
};

void readfiles(){

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

    readfiles();

    return 0;
    
}