#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void registration();
void forgot();

int main()
{
	int choice;
	
	cout <<"\t\t\t____________________________________________\n\n\n";
	cout <<"\t\t\t          Welcome to the login page          \n\n\n";
	cout <<"\t\t\t__________________    Menu      ______________\n\n\n";
	cout <<"                                                     \n\n";
	cout <<"\t| Press 1 to LOGIN                                  |" << endl;
	cout <<"\t| Press 2 to REGISTER                               |" << endl;
	cout <<"\t| Press 3 if you forgot your PASSWORD               |" << endl;
	cout <<"\t| Press 4 to EXIT                                   |" << endl;
	
	cout << "\t please enter your choice : ";
	cin >> choice;
	
	switch(choice)
	{
		case 1:
					login();
					break;
					
		case 2 :
					registration();
					break;
					
		case 3 :
					forgot();
					break;
		case 4 :
						cout << "\t\t\t thank you for using the registration system" <<endl;
		
		default :
			system("cls");
			cout << "\t\t\t please choose a valid option from the menue"<<endl;
			main();
			
	}
}

void login()
{
	bool valid = false;
	string username, password,userNameRecord,passwordRecord;
	system("cls");
	cout << " \t\t\t please enter the username and password : " <<endl;
	cout << "\t\t\t USERNAME : ";
	cin >> username;
	cout << "\t\t\t PASSWORD : ";
	cin>> password; 
	
	ifstream input("records.txt");
	while (input>>userNameRecord>>passwordRecord)
	{
		if (userNameRecord==username && passwordRecord==password)
		{
			valid = true;
			system("cls");
		}
	}
	input.close();
	if (valid ==true)
	{
		cout << username <<endl;
		cout << "your login is sucsessfull!";
		cout << " thank you for logging in";
		main();
	}
	else 
	{
		cout<< " your login was unsucessfull, please try a"; 
		cout <<"diffferent username or password";
		main();
	}
}

void registration ()
{
	string username =" ";
	string password =" ";
	string password2 = " ";
	
	cout << " "<<endl;
	cout << " Thank you for choosing to register with our system"<<endl;
	cout << " "<<endl;
	cout << " \t\t\t please enter your username and password : " <<endl;
	cout << "\t\t\t USERNAME : ";
	cin >> username;
	cout << "\t\t\t PASSWORD : ";
	cin>> password; 
	cout << " \t\t\t please confirm your password"<<endl;
	cout << "\t\t\t PASSWORD : ";
	cin >> password2;
	
	while (password!=password2)
	{
		cout << " your passwords do not match please try again";
		cout << "\t\t\t PASSWORD : ";
		cin>> password; 
		cout << " please confirm your password";
		cout << "\t\t\t PASSWORD : ";
		cin >> password2;	
	}
	
	ofstream output ("records.txt", ios::app);
	output<<username <<" "<<password <<endl;
	system("cls");
	cout << " your registation is sucsessful" <<endl;
	main();
}

void forgot()
{
	int option;
	system("cls");
	cout << " ypu forgot the passoword? no worries" <<endl;
	cout << " press 1 to search your id by username" <<endl;
	cout << " press 2 to go back to the main menu" <<endl;
	cout << " Enter your choice :" <<endl;
	cin >> option;
	switch (option)
		{
			case 1 :
			{
					bool exists=false;
					string userId, Id, password;
					cout << " Enter your username : ";
					cin >> userId;
					ifstream input2 ("records.txt");
					while (input2>> Id >> password)
					{
						if (Id==userId)
						{
							exists = true;
						}
					}
					input2.close();
					
					if (exists == true)
					{
						cout << " your account is found"<<endl;
						cout << " your password is : " <<password <<endl;
						main();
					}
					else 
					{
						cout << "sorry your account is not found"<<endl;
						main();
					}
			
			}
			break;
			
			case 2 :
			{
				main();
			}
			
			default :
			cout << " wrong choice, please select a valid opotion";
			forgot(); 	
		}

}
