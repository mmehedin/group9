
/*
*@Title: Homework 2
*@Authors: Camlin, Mihai Meheding, Sterling Beckham
*@Date: 02/2015
*@Description:  implement a command-line program launcher.
*Parse the string entered by the user.....
*/
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

void parse (char* cmd, char** tokens);
void launch (char* tokens);


void parse (char* cmd, char* tokens){
	//write code to parse the string here
}

void launch (char * tokens){
	//write code to launch here
}

/*
*The main driver
*/
int main(){
	cout << endl << "Group 9 Homework 2" << endl;
	cout << "Authors: Camlin, Mihai, Sterling" << endl << endl;
	cout << "Please enter a command string in the following format: " <<endl;
	cout << "group9 [<param-1> <param-2> <[param-2>]" << endl <<endl;
	string com;//this is stores the command in the com string
	getline(cin, com);
	
	//this stores the com string in the cmd char array	
	char *cmd =  new char[com.size()+1];
		cmd[com.size()]=0;
	memcpy(cmd, com.c_str(), com.size());
	
	char tokens[100][100];
	//spawn a child process
	
	//parse the string
	parse(cmd, tokens); 
	
	
	//launch
	launch(tokens);
	



	return 0;
}//end of main
