#include <iostream>
#include <fstream>

using namespace std;

int main(){
  int passed = 0;
  fstream monFicher;
  passed ++;
  cout << "allo" << passed << "\n";
  monFicher.open("sda/bin/pkgs/pkgs.txt", ios::app);
  passed ++;
  cout << "allo" << passed << "\n";
  string pkgsList[2] = {"cmatrix", "neofetch"};
  for (int i = 0; i<2; i++){
    monFicher << pkgsList[i] << "\n";
    passed ++;
  }
  passed ++;
  monFicher.close();
  return 0;
}