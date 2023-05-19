#include <iostream>
#include <fstream>

using namespace std;

int main(){
    fstream monFichier;
    monFichier.open("sda/bin/pkgs/pkgs.txt", ios::in);
	string text;
	string line;
	while (getline(monFichier, line)) {
		text = line;
		cout << text;
		cout << line;
	}
}