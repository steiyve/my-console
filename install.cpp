#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include <cstring>
#include <fstream>

using namespace std;
int main(void){
	chdir("sda");
	const char* str = "bin";
	// Creating a directory
	if (mkdir(str, 0777) == -1){
		cerr << "Error :  " << strerror(errno) << endl;
        return errno;
    }
	else{
		//make de sys info file in the bin dir
		cout << "Directory created\n";
        chdir(str);
		string sysType;
		while (true){
			cout << "wath is your installer you prefer:";
			cin >> sysType;
			if (sysType != "pacman" && sysType != "apt"){
				cout << "I am not avalable\n";
			}
			else{
				break;
			}
		}

		fstream monFichier;
		monFichier.open("sysInfo.txt", ios::app);
		monFichier << sysType;
		monFichier.close();
    }
	str = "home";
	chdir("..");
	cout << str;
	if (mkdir(str, 0777) == -1){
		cerr << "Error :  " << strerror(errno) << endl;
        return errno;
    }
	else{
		cout << "Directory created\n";
        chdir("home");
		string user;
		cout << "your name:";
		cin >> user;
		str = user.c_str();
		// Creating a directory
		if (mkdir(str, 0777) == -1){
			cerr << "Error :  " << strerror(errno) << endl;
			return errno;
		}
		else{
			cout << "Directory created\n";
			chdir(str);
		}
		return 0;
    }
}
