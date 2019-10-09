#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;;

int main(int argc, char** argv) {

	if(argc > 3){
		return 0;
	}
	
	bool decode = false ;
	int itemdecode = 1;
	string cmd = "";
		
	for(int i = 1; i < argc; i++){
		string arg = argv[i];
		if(arg == "-d"){
			decode = true;
			break;
		}
		itemdecode = itemdecode +1;
	}
	
	ofstream file;
	ifstream inFile;
	
	if(decode == true){
		if(argc != 3){
			return 0;
		}
		file.open("todecode.b64");
		if(itemdecode == 1){
			file << argv[2];
		}else{
			file << argv[1];
		}
		file.close();
		cmd = "certutil -decode todecode.b64 decoded.txt > nul: && type decoded.txt && del /f decoded.txt todecode.b64 \n";
		cout << "\n";
		system(cmd.c_str());
		cout << "\n";
	}else{
		if(argc != 2){
			return 0;
		}
		file.open("toencode.txt");
		file << argv[1];
		file.close();
		cmd = "certutil -encode toencode.txt encoded.b64 > nul:";
		system(cmd.c_str());
		inFile.open("encoded.b64");
		string x ;
		int lines = 0;
		while (inFile >> x) {
			if(lines == 2){
				cout << "\n";
				cout << x;
				cout << "\n";
			}
		    lines = lines + 1;
		}
		inFile.close();
		cmd = "del /f encoded.b64 toencode.txt";
		system(cmd.c_str());
	}
}
