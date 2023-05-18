/****************************************
creer par nicolas
debut: 1-04-2023
but: avoir ma propre console
****************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include <cstring>
#include <git2.h>

using namespace std;


/********************************
fonction qui prend le path en entre
et imprime: ~/${PATH}
********************************/
void printPath(string path, string mode) {
	if (path != " ") {
		cout << mode << " ~" << path;
	}
	else {
		cout << mode << " ~";
	}
	cout << ":";
	
}

/*********************************
fonction qui imprime la liste des commandes
ne prend rien en entre
*********************************/
void printHelp() {
	string listCommande[10] = { "mkdir", "echo", "ls", "touch", "cat", "cd", "changeFile", "quit", "fs", "q"};
	for (int i = 0; i < 10; i++) {
		cout << listCommande[i];
		cout << "\n";
	}
}

/************************************
fonction qui prend le nom du fichier en argument
et creer un fichier texte
************************************/
void creatFile(string fileName) {
	string fileNAME = fileName;
	fstream monFichier;
	monFichier.open(fileNAME, ios::app);
	monFichier.close();
	cout << "file creat\n";
}


/************************************
fonction qui prend le nom du fichier et le texte a ajouter en argument
et creer un fichier texte et ajoute du texte dedans
************************************/
void modifieFile(string fileName, string text) {
	string fileNAME = fileName;
	fstream monFichier;
	monFichier.open(fileNAME, ios::app);
	monFichier << text;
	monFichier.close();
	cout << "file modifie\n";
}

/*************************************************************
fonction qui prend le nom du derctory en argument et creer un folder
et retourne le path en argument
*************************************************************/
void makeDir(string directoryName, string chemin) {
	const char* str = directoryName.c_str();
	// Creating a directory
	if (mkdir(str, 0777) == -1)
		cerr << "Error :  " << strerror(errno) << endl;

	else
		cout << "Directory created\n";
}

/**************************************
fonction qui prend le nom du chemin present et le -> dir 
et retourne un path updater
**************************************/
string direct;
string cd(string currentDyrectory, string movingToDirectory) {
	const char* dir = movingToDirectory.c_str();
	chdir(dir);
	direct = currentDyrectory + movingToDirectory;
	return direct;
}

/**************************************
fonction qui prend le fichier en entre et retourne le contenu du fichier
**************************************/
void cat(string fileName) {
	string nomFichier = fileName;
	fstream mon_ficher;
	mon_ficher.open(fileName, ios::in);
	string text;
	string line;
	while (getline(mon_ficher, line)) {
		text = line;
		cout << text;
	}
}

/**********************************************************
fonction qui prend le curent dir et retourne la liste de fichier du dirertory
**********************************************************/
void ls(string DIR) {
	std::filesystem::path path_to_dir = DIR ;
	for (const auto& entry : std::filesystem::directory_iterator(path_to_dir)) {
		cout << entry.path() << endl;
	}
}

/**********************************************
 fontion qui prend le message en arguent et le print.
 **********************************************/
void echo(string message){
	cout << message << "\n";
}

void boucle(string list, string dir){
	if (list == "touch") {
		string file;
		cout << "the file name";
		cin >> file;
		if (file != " ") {
			creatFile(file);
		}
		else {
			cout << "invalid file name\n";
		}
	}
	if (list == "changeFile") {	
		string file;
		cout << "the file name";
		cin >> file;
		string text;
		cout << "the text you to add:";
		cin >> text;
		modifieFile(file, text);
	}
	if (list == "mkdir"){
		string file;
		cout << "the file name";
		cin >> file;
		
		makeDir(file, directory);
	}
	if (list == "cd") {
		string directory;
		cout << "the moving to dir:";
		cin >> directory;
		cd(directory, dir);
		directory = directory + dir;
		
	}
	if (list == "cat") {
		string file;
		cout << "the file name";
		cin >> file;
		cat(file);
	}
}

void update(){
	git_repository *repo = NULL;
	git_clone_options options = GIT_CLONE_OPTIONS_INIT;
	const char *url = "https://github.com/username/repo.git";
	const char *path = "repo";
	int error = git_pull(&repo, url, path, &options);
	if (error < 0) {
		cerr << "Error pulling repository: " << giterr_last()->message << endl;
		return 1;
	}
	git_repository_free(repo);
}


int main(void) {
	bool run = true;
	string directory = "/";
	string command = " ";
	//enter the console directory
	chdir("sda/user");
	string user;
	cout << "choose an user:";
	cin >> user;
	const char* userName = user.c_str();
	chdir(userName);

	while (run) {
		printPath(directory, "[normal mode]");
		cin >> command;
		if (command == "help") {
			printHelp();
		}
		if (command == "ls") {
			string direct;
			direct = "~/my-console/sda/user/" + user + directory;
			ls(direct);
		}

		if (command == "Syu"){

		}
		if (command == "quit") {
			break;
		}
		if (command == "fs") {
			bool changedDirec = false;
			while (true) {
				printPath(directory, "[file systeme mode]");
				string file = " ";
				string text = " ";
				cin >> command >> file >> text;
				if (command == "touch") {
					if (file != " ") {
						creatFile(file);
					}
					else {
						cout << "invalid file name\n";
					}
				}
				if (command == "changeFile") {	
					modifieFile(file, text);
				}
				if (command == "mkdir"){
					makeDir(file, directory);
				}
				if (command == "cd") {
					changedDirec = true;
					cd(directory, file);
					directory = directory + direct;
					
				}
				if (command == "cat") {
					cat(file);
				}
				if (command == "help") {
					printHelp();
				}
				if (command == "q") {
					break;
				}
			}
		}
		else if (command == "code"){
			while (true){
				printPath(directory, "[code mode]");
				string text = " ";
				cin >> command >> text;

				if (command == "echo"){
					echo(text);
				}
				if (command == "for"){
					int repete;
					cout << "repette number:";
					cin >> repete;
					string operation[repete]; 
					for (int i = 0; i<repete; i++){
						cout << "the operation:";
						string comande;
						cin >> comande;
						operation[i] = comande; 
					}
					for (int i = 0; i<repete; i++){
						boucle(operation[i],directory);
					}
				}
				else if (command == "quit"){
					break;
				}
			}
		}
	}
	return 0;
}