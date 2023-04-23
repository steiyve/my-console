#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include <cstring>


using namespace std;
int main(void){
	chdir("sda");
	const char* str = "user";
	// Creating a directory
	if (mkdir(str, 0777) == -1){
		cerr << "Error :  " << strerror(errno) << endl;
        return errno;
    }
	else{
		cout << "Directory created\n";
        chdir("user");
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
