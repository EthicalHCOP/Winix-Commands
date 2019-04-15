#include <iostream>
#include <string>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
    string cmd = "";
    string com = argv[1];
    cmd = "";
    string p = argv[1];
    if(p=="-r"){
    	cmd = cmd+"xcopy /e /i /c"+" "+argv[2]+"  "+argv[3];
	}else{
		cmd = cmd+"type"+" "+argv[1]+" > "+argv[2];
	}
	
	system(cmd.c_str());
	return 0;
}
