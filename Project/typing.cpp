// WRITTEN BY:  Keenan Mayuga and Margarita Bautista
// SECTION: EQ1       
//                
// FOR COURSE:    LBYEC2B
//
// PURPOSE:
// This program assess the typing speed and accuracy of the user.
//
// OVERALL METHOD/ALGORITHM:
// The list of general tasks is:
// 1. Display a main menu and ask the user to select.
// 2. Execute the menu item.
//    2-1. If selected menu item is '1', perform register
//         2-1-1. Asks the user to enter first name, last name, username, and password
//         2-1-2. If the registration is successful, the main menu will be shown again. 
//         2-1-3. If the the user attempts to register with the same username and password, 
//                a message will appear telling the user that the user already exists and is ask 
//                whether to go back to the main menu or try again
//                2-1-3-1. If selected menu item is 'x' or 'X', display main menu
//                2-1-3-2. If selected menu item is 'y' or 'Y', asks for a username again.
//    2-2. If selected menu item is '2', perform login
//         2-2-1. If the login is successful, display usermenu to select.
//                2-2-1-1. If selected menu item is '1', display text selection menu and ask the user to select
//                         2-2-1-1-1. Display the chosen text
//                         2-2-1-1-2. Ask the user the number of lines to be typed
//                         2-2-1-1-3. Ask the user to start typing
//                         2-2-1-1-4. Display the results (number of words correct, number of words incorrect, 
//                                    accuracy, typing time, and speed)
//                2-2-1-2. If selected menu item is '2', display the profile of the user
//                2-2-1-3. If selected menu item is '3', display the statistics of mistyped words
//                2-2-1-4. If selected menu item is '4', logout and display main menu
//                2-2-1-5. If selected menu item is '5', exit the program
//         2-2-2. If the username is not verified, a message will appear
//                telling the user that the user does not exists and is asked whether to go back to main menu
//                or try again
//                2-2-2-1. If selected menu item is 'x' or 'X', display main menu
//                2-2-2-2. If selected menu item is 'y' or 'Y', asks for a username again 
//         2-2-3. If the password is incorrect, a message will appear telling the user that the password is incorrect 
//                is asked whether to go back to main menu or try again
//                2-2-3-1. If selected menu item is 'x' or 'X', display main menu
//                2-2-3-2. If selected menu item is 'y' or 'Y', asks for a password again 
//         
//    2-3. If selected menu item is '3', exit the program
//
// CREDITS:
//     https://github.com/iamsahil1910/Typing-Test
// 
// FUNCTIONS:
//
// main_menu
//    display the menu
//
// reg
//    ask user to register
//
// login
//    ask user to login
//
// usermenu
//    display the menu for the game
//
// myprofile
//    displays the past records of the user
// 
// listTest
//    display menu for text selection
//
// Test
//    executes the typing game and shows the result
//
// Statistics
//    displays statistics of mistyped words
//
// INCLUDED FILES:
//    typing.h
//
// DATA FILES:
//    username.txt
//    check.txt
//    mistake.txt
#include "typing.h"

Type game;

Type *start = NULL, *last = NULL;

// FUNCTION NAME: main_menu
// CREDITS:
//           
// PARAMETERS: None
//
// RETURN VALUE: None          
//
// CALLS TO: none
//
// CALLED FROM: main()
//
// METHOD:
//
// This function displays the main menu
void main_menu()
{
	int choice;//menu key variable
	do
	{
		system("cls");
		printf("\t      __    _____ _____    _____ _____ \n");
		printf("\t     |  |  |     |   __|  |     |   | |\n");
		printf("\t     |  |__|  |  |  |  |  |-   -| | | |\n");
		printf("\t     |_____|_____|_____|  |_____|_|___|\n");
		printf("\n*************************** TYPING TEST ******************************\n");	
		printf("=========================== LOG IN ==================================\n");
		printf("(1) Register\n");
		printf("(2) Log In\n");
		printf("(3) Exit\n");
		printf("Enter Choice: ");
		choice = getch() - 48;
	
		switch(choice)
		{
			case 1:
				{
					game.reg();
					break;
				}
			case 2:
				{
					game.login();
					break;
				}
			case 3:
				{
					exit(0);
				}
			default:
				{
					printf("\n Invalid input.");
				}
		}
	}
	while (choice != '3'); //if the choice is not 3, redisplay the menu
}

// FUNCTION NAME: reg
// CREDITS:
//    Ken Camacho
//    https://www.crazyengineers.com/threads/user-login-and-registration-using-files-in-c.55378
//           
// PARAMETERS: None
//
// RETURN VALUE: None          
//
// CALLS TO: none
//
// CALLED FROM: main_menu()
//
// METHOD:
//
// This function asks the user to register

void Type :: reg()
{	
	FILE *file;
	system("cls");
	printf("\t     _____ _____ _____ _____ _____ _____ _____ _____ \n");
	printf("\t    | __  |   __|   __|     |   __|_   _|   __| __  |\n");
	printf("\t    |    -|   __|  |  |-   -|__   | | | |   __|    -|\n");
	printf("\t    |__|__|_____|_____|_____|_____| |_| |_____|__|__|\n");
	
	printf("\n*************************** TYPING TEST ******************************\n");
	
	//asks user for the necessary information for the registration
	printf("\nEnter First name: ");
	gets(fname);
	printf("\nEnter last name: ");
	gets(lname);
	username:
	printf("\nEnter Username: ");
	gets(username);

	strcat(username,".txt"); //creates a text file with the username as the filename

	if (file = fopen(username,"r"))//reads the text file and checks if the username inputted already exist
	{
		printf("\n User Already Exist\n");
		char opt;
		printf("\n Press X to return to main menu or Y to try again: ");
		scanf("%c",&opt);
		if (opt == 'x' || opt == 'X')// if user presses x or X, display main menu again
		{
			main_menu();
		}
		
		else if(opt == 'y' || opt == 'Y')//if user presses y, ask the user 
		{
			goto username;
		}
		system("pause");

		fclose(file);
		reg();
	}
	
	file = fopen(username,"a+");
	fprintf(file,fname);//displays the first name of the user in the text file
	fprintf(file,"\n");
	fprintf(file,lname);//displays the last name of the user in the text file
	printf("\nEnter password : ");
	gets(password);
	fprintf(file,"\n");
	fprintf(file, password);//displays the password of the user in the text file
	fclose(file);
	

	if(!(file = fopen(username,"r")))
	{
		printf("\nUser Not created\n");//if not opened this message will appear
		reg();
	}

	fclose(file);

	printf("\n*************************** TYPING TEST ******************************\n");
		system("pause");
}

// FUNCTION NAME: login
// CREDITS:
//     Ken Camacho
//     https://www.crazyengineers.com/threads/user-login-and-registration-using-files-in-c.55378
//           
// PARAMETERS: none
//
// RETURN VALUE: none         
//
// CALLS TO: none
//
// CALLED FROM: main_menu()
//
// METHOD:
// This function asks the user to login

void Type :: login()
{	
	FILE *file;
	char tmp[20];	
	system("cls");
	printf("\t      __    _____ _____    _____ _____ \n");
	printf("\t     |  |  |     |   __|  |     |   | |\n");
	printf("\t     |  |__|  |  |  |  |  |-   -| | | |\n");
	printf("\t     |_____|_____|_____|  |_____|_|___|\n");
	printf("\n*************************** TYPING TEST ******************************\n");
	char user[20], pass[20];
	user:
	printf("\nEnter Username : ");
	gets(user);

	strcat(user,".txt");

	
	if (!(file = fopen(user,"r")))
	{
		printf("\n User does not exist!\n");//if the username inputted is not a filename of any text file this message will appear
		char opt;
		printf("\n Press X to return to main menu or Y to try again: ");
		scanf("%c",&opt);
		if (opt == 'x' || opt == 'X')
		{
			main_menu();
		}
		
		else if(opt == 'y' || opt == 'Y')
		{
			goto user;
		}
		system("pause");

		fclose(file);
		login();
	}
	
	pw:
	printf("\nEnter Password : ");
	gets(pass);

	file = fopen(user,"r");
	while(!feof(file)){
		fgets(tmp,20,file);
	}

	if (strcmp(pass, tmp) == 0)//for correct password
	{
		printf("\n Log In Successful!\n");
		system("pause");
		usermenu(user);
	}
	else//for incorrect password
	{
		char opt;
		printf("\n Wrong Password\n");
		printf("\n Press X to return to main menu or Y to try again: ");
		scanf("%c", &opt);
		if (opt == 'x' || opt == 'X')
		{
			main_menu();
		}
		
		else
		{
			goto pw;
		}
		system("pause");
		login();
	}

	printf("\n*************************** TYPING TEST ******************************\n");
	system("pause");
}

// FUNCTION NAME: usermenu
// CREDITS:
//           
// PARAMETERS: 
//   user
//
// RETURN VALUE: none        
//
// CALLS TO: none
//
// CALLED FROM: login()
//
// METHOD:
//    Displays the menu for the game 
void Type :: usermenu(char *user)
{
	system("cls");
	fstream f; //iniate file
	f.open(user, ios::app|ios::in);
	int choice;
		do
	{
		system("cls");
		printf("\t       _ _ _ _____ __    _____ _____ _____ _____ \n");
		printf("\t      | | | |   __|  |  |     |     |     |   __|\n");
		printf("\t      | | | |   __|  |__|   --|  |  | | | |   __|\n");
		printf("\t      |_____|_____|_____|_____|_____|_|_|_|_____|\n");
		printf("\n\n*************************** TYPING TEST ******************************\n");	
		printf("============================= MENU ====================================\n");
		printf("(1) Start\n");
		printf("(2) My Profile\n");
		printf("(3) Statistics\n");
		printf("(4) Logout\n");
		printf("(5) Exit\n");
		printf("Enter Choice: ");
		choice = getch() - 48;//key menu variable 
	
		switch(choice)
		{
			case 1:
				{
					game.listTest(user); 
					break;
				}
			case 2:
				{
					game.myprofile(user);
					break;
				}
			case 3:
				{
      				game.Statistics(user);
      				break;
				}
			case 4:
				{
					main_menu();
					break;
				}
			case 5:
				{
					exit(0);
				}
			default:
				{
					printf("\n Wrong Input");
				}
		}
	}
	while (choice != '4');

}

// FUNCTION NAME: myprofile
// CREDITS:
//           
// PARAMETERS: 
//   user
//
//
// RETURN VALUE: none         
//
// CALLS TO: none
//
// CALLED FROM: usermenu()
//
// METHOD:
//   displays the records of the user
void Type :: myprofile(char *user)
{
	system("cls");
	printf("\t       _____ _____ _____ _____ _____ __    _____ \n");
	printf("\t      |  _  | __  |     |   __|     |  |  |   __|\n");
	printf("\t      |   __|    -|  |  |   __|-   -|  |__|   __|\n");
	printf("\t      |__|  |__|__|_____|__|  |_____|_____|_____|\n");
	printf("\n\n*************************** TYPING TEST ******************************\n");
	ifstream f; //iniate file
	f.open(user);
	f.read((char*)&game, sizeof(game));
	printf("\n Name : %s Last Name: %s", fname,lname);
	printf("\n User name : %s", username);
	char ch;
	f.get(ch);
	printf("\n Your Record \n");
	while (!f.eof()) //displays user's records from file f
	{
		cout<<ch;
		f.get(ch);
		
	}
	printf("\n Press any key to exit ");
	system("pause");
}

// FUNCTION NAME: listTest
// CREDITS:
//           
// PARAMETERS: 
//   user
//
// RETURN VALUE: none          
//
// CALLS TO: none
//
// CALLED FROM: usermenu()
//
// METHOD:
//   displays text selection
void Type :: listTest(char *user)
{
	system("cls");
	printf("\t _____ _____ _____ _____ _____    _____ _____ _____ _____ \n");
	printf("\t|   __|_   _|  _  | __  |_   _|  |_   _|   __|   __|_   _|\n");
	printf("\t|__   | | | |     |    -| | |      | | |   __|__   | | |  \n");
	printf("\t|_____| |_| |__|__|__|__| |_|      |_| |_____|_____| |_|  \n");
	printf("\n*************************** TYPING TEST ******************************\n");	
	fstream f; //iniate file
	f.open("test.txt", ios::in);
	
	char ch;
	f.get(ch);
	int count = 0;
	
	start = NULL;
	while (!f.eof())
	{
		Type *newnode = new Type;
		int i = 0;
		while (ch != '\n')
		{
			newnode->tests[i] = ch;
			f.get(ch);
			i++;
		}
		newnode->num = count;
		newnode->next = NULL;
		
		if (start == NULL)
		{
			start = newnode;
			last = newnode;
		}
		else
		{
			last->next = newnode;
			last = newnode;
		}
		count++;
		f.get(ch);
	}
	f.close();
	
	Type *ptr;
	ptr = start;
	printf("\n");
	while(ptr != NULL)
	{
		printf("(%d)",ptr->num);
		printf("%s",ptr->tests);
		ptr = ptr->next;
		printf("\n");
	}
	char choose[2];
	printf("\n Choose Selection ");
	scanf("%s",&choose);
	Test(choose, user);
	usermenu(user);
	system("pause");
	printf("\n*************************** TYPING TEST ******************************\n");
}

// FUNCTION NAME: Test
// CREDITS:
//           
// PARAMETERS: 
//   value
//   user
//
// RETURN VALUE: none        
//
// CALLS TO: none
//
// CALLED FROM: listTest()
//
// METHOD:
//    executes the game and displays result

void Type :: Test(char *value, char* user)
{
	system("cls");
	printf("\n*************************** TYPING TEST ******************************\n");
	fstream f,f1;
	int count = 0, wrong = 0, line;
	f.open(value, ios::in);
	if (!f)
	{
		printf("\n Nope");
		return;
	}
	char ch;
	f.get(ch);
	while (!f.eof())
	{
		cout<<ch;
		f.get(ch);
	}
	printf("\n\nHow many lines do you want to write of above selection: ");
	scanf("%d",&line);
	
	printf("\nStart Writing\n");
	f.close();
	f.open("check.txt",ios::out);
	char text[2000];
	printf("\n");
	system("pause");
	clock_t tStart = clock();
	while (count != line + 1)
	{
		gets(text);
		f<<text;
		f<<"\n";
		count++;
	}
	clock_t tend = clock();
	count = 0;
	f.close();
	
	
	ifstream f10, f20;
	string s1,s2, file1, file2, wrongwords;
	FILE *wrongfile;
	file1 = "check.txt";
	file2 = value;
	f10.open(file1.c_str());
	f20.open(file2.c_str());

	

	char buf[2000];
	while (f10>>s2)
	{
		f20>>s1;
		if (s1 == s2)
		{
			count++;
		}
		else
		{
			wrong++;
			
		}
	}
	printf("\n No of words correct : %d",count);
	printf("\n No of words Incorrect : %d", wrong);
	float c1 = count;
	float accuracy = c1/(count + wrong) * 100;
	printf("\n Accuracy is : %d percent",accuracy);
	f.close();
	f1.close();
	

	
	f.open(user, ios::app);
	f<<"\n";
	f<<"This test result correct words : "<<count<<" Wrong words : "<<wrong<<" Accuracy : "<<accuracy;
	float time = (tend - tStart)/1000;
	float exact = time/60;
	int speed = count/exact;
	printf("\n Typing Time : %f",time);
	f<<" Test Time : "<<time;
	printf("\n Speed : %d WPM",speed);
	f<<" Speed : "<<speed<<" WPM";
	printf("\n*************************** TYPING TEST ******************************\n");
	system("pause");
}

// FUNCTION NAME: Statistics
// CREDITS:
//           
// PARAMETERS: 
//	user
//   
//
// RETURN VALUE: none         
//
// CALLS TO: none
//
// CALLED FROM: usermenu()
//
// METHOD:
void Type :: Statistics(char* user){
	system("cls");
	printf("\t _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ \n");
	printf("\t|   __|_   _|  _  |_   _|     |   __|_   _|     |     |   __|\n");
	printf("\t|__   | | | |     | | | |-   -|__   | | | |-   -|   --|__   |\n");
	printf("\t|_____| |_| |__|__| |_| |_____|_____| |_| |_____|_____|_____|\n");
	printf("\n\n*************************** TYPING TEST ******************************\n");	
		
	FILE *stats; //iniate file
	int count=0, index=0, SIZE=100;
	char word[SIZE];
	char c, *ctr;
	printf("\tMISTYPED WORDS\n");	
	stats = fopen("wrong.txt", "r");
	c = fgetc(stats); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(stats); 
    } 
    fclose(stats); 
	printf("\nEnter one of the words above to see how many times it is mistyped: ");
	scanf("%s", &word);
	
	
	stats = fopen("wrong.txt", "r");	
	while ((fgets(word, SIZE, stats))!= NULL)
	{
		while ((ctr = strstr(word + index, word))!= NULL)
		{
		index = (ctr-word) + 1;
		count++;
		}
	}
	printf("The word %s is mistyped %d times", &word, &count);

	fclose(stats); 
	system("pause");
	}
		
