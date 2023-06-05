#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void login(string username, string password){
    fstream monFichier;
    string location = "sda/etc/passwd_" + username + ".txt";
    monFichier.open(location, ios::in);
    string line;
    int pos;
    getline(monFichier, line);

    monFichier.close();
    
    while (true){
        if (password == line){
            break;
        }
        else{
            cout << "enter the good password\n";
        }
    }
}

