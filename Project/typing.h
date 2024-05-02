#ifndef TYPING_H
#define TYPING_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <time.h>

using namespace std;

class Type
{
	char fname[20], lname[20], username[20], password[20];
	
	public:
		char tests[30];
	 	int num;
		Type *next;
		void usermenu(char*);
		void reg();
		void login();
		void listTest(char*);
		void myprofile(char*);
		void Test(char*, char*);
		void Statistics(char*);
		
};

void main_menu();






#endif
