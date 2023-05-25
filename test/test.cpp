#include <iostream>
#include <fstream>

using namespace std;

int main(){
    fstream monFichier;
    int ligne = 0;
    monFichier.open("test.txt", ios::in);
    string word[0] = {};
	string text;
	string line;
	while (getline(monFichier, line)) {
		ligne++;
        text = line;
		word[ligne] = line;
        cout << text << "\n";
	}
    cout << ligne;
    for (int i=0; i<ligne; i++){
        cout << word[i] << "\n";
    }
}