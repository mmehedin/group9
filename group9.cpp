
/*
*@Title: Homework 2
*@Authors: Camlin Ard, Mihai Meheding, Sterling Beckham
*@Date: 02/2015
*@Description:  implement a command-line program launcher.
*Parse the string entered by the user.....
*/

#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string.h>
#include <unistd.h>
#include<stdio.h>
//using namespace std;
bool rep = true, stop_rep = false;

bool *r = &rep;
int end_pointer = 0;
int start_pointer =0;
int *i, *st;

void parseS (char* cmd, char** tokens);
void launch (char** tokens);

int * nextWordIndex(char * cmd){

	std::cout << std::endl <<  "start nextWord: "<< start_pointer << "  end: " << end_pointer << "   cmd: " << (&cmd[start_pointer]) << std::endl;
	if (cmd[end_pointer]==' '){
		++*i;
	}
	*st=end_pointer;
	while(cmd[end_pointer]!=' ' && cmd[end_pointer]!='\0'){
		++*i;
	}
	usleep(5);
	return i;
}

void parseS (char* cmd, char** tokens){
	int index = 0;
	int *index_pointer = &index;
	while (cmd[end_pointer]!='\0'){
		nextWordIndex(cmd);
		//std::cout << std::endl <<  "start: "<< start_pointer << "  end: " << end_pointer << "   cmd: " << *(&cmd[start_pointer]) << std::endl;
		//strncpy(tokens[index], (&cmd[start_pointer]), end_pointer - start_pointer);
		int t, k;
		for (k = start_pointer, t = 0; k!=(end_pointer); k++, t++){
			//std::cout << std::endl << "blah: "<<*(&tokens[index])[t] << std::endl;
			//std::cout << std::endl << (*(&cmd))[k] << std::endl;
			tokens[index][t] = *(&cmd[k]);
			//std::cout <<"cmd[k]: "<< cmd[k] << "  with k: " << k << "   t: " << t << std::endl;
		}
		tokens[index][t] = '\0';
		//tokens[index][0]=*(&cmd[start_pointer]) ;
		std::cout << "token "<< index << " is:  "<< tokens[index] << "   "<< std::endl;
		++*index_pointer;
	}
	*(&tokens[index+1])[0] = '\0';
	std::cout << "token last: " << *(&tokens[index+1]) << "   "<< std::endl;
}


void launch (char ** tokens){
	pid_t id;
	//int child_s;
	std::cout << "Attempting to spawn new process...\n";
	id = fork();

	if(id == -1) {
		std::cout << "Oops...process creation failed\n";
	} else if (id != 0) {
		std::cout << "I am now a proud parent! My child's ID is " << id << std::endl;

		//wait for the child to finish must improve
		// do {
		//       pid_t tpid = wait(&child_s);
		 //      if(tpid != id) process_terminated(tpid);
		 //    } while(tpid != id);
	} else {
		std::cout << "Value of id in child is: " << id << std::endl;
		execvp(tokens[0], tokens);
		printf("Unknown command\n");
		exit(0);
	}

}

/*
*The main driver
*/
int main(){
	i = &end_pointer;
	st = &start_pointer;
	std::cout << std::endl << "Group 9 Homework 2" << std::endl;
	std::cout << "Authors: Camlin, Mihai, Sterling" << std::endl;
	std::cout << "_________________________________"<< std::endl << std::endl;

	while (*r){
		std::cout << "Please enter a command string in the following format: " <<std::endl;
		std::cout << "command [<param-1> <param-2> <[param-2>] or Enter to exit:" << std::endl <<std::endl;
		std::string com;//this is stores the command in the com string

		getline(std::cin, com);
		//std::cin.ignore();
		if (!com.empty()){
			char *cmd; //the pointer to char array
			char **tokens = new char * [com.size()]; //the pointer to array of pointers

			//gets(cmd);

			//this stores the com string in the cmd char array
			cmd =  new char[com.size()+1];
			cmd[com.size()]='\0';
			memcpy(cmd, com.c_str(), com.size());

			//initialize tokens
			char empt = {'0'}; //used to initialize tokens
			for (int l=0;l<com.size();l++)
				tokens[l]=&empt;
			//std::cout << cmd[0]<<cmd[(com.size()-1)]<<std::endl<<com.size()<<std::endl<<cmd<<std::endl;


			//spawn a child process

			//parse the string
			parseS(cmd, tokens);

			//launch
			launch(tokens);
		}else{
			*r = &stop_rep;
		}
 }

	std::cout << std::endl << "Exiting...Bye!"<< std::endl;
	std::cout << "________________________________" << std::endl;

	//delete[] tokens;
	//pthread_exit(0);
	return 0;

}//end of main
