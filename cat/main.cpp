#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
    string cmd = "";
    string com = argv[1];
    cmd = "type";
    
    cmd = cmd +" "+argv[1];

	system(cmd.c_str());
	return 0;
}
