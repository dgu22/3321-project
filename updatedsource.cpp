#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <windows.h>
#include <limits>

void menu();
void pascode();
void cpascode();

using namespace std;

// Hashing function
string hashPassword(const string& password)
{
	//TODO: insert hashing function here 
	return password;
}

class one
{

public:
	virtual void get() = 0;
	virtual void show() = 0;

};

//==========Patient information==========

class info : public one
{
public:
	char name[50], time[50];
	int num, age;

	void get()
	{
		system("cls");
		cin.sync();
		cout << "\n Enter the patient name: ";
		cin.getline(name, 50);

		cin.ignore(); 

		cout << "\n Enter the Appointment Time: ";
		cin.getline(time, 50);

		cin.ignore(); 

		cout << "\n Enter Age: ";
		cin >> age;

		cin.ignore(); 

		cout << "\n Enter Appointment No: ";
		cin >> num;

	}

	void show()
	{
		cout << "\nName: " << name;
		cout << "\nAge: " << age;
		cout << "\nNo: " << num;
		cout << "\nTime: " << time;
	}

};

//========== Class for Dr. Taylor's information ==========

class Taylor :public info
{
public:
	info a1;
	void get()
	{
		system("cls");
		ofstream out("Taylor.txt", ios::app | ios::binary);
		if (!out)
		{
			cout << "Error opening file for writing." << endl;
			cin.get();
			menu();
		}

		a1.get();
		out.write((char*)&a1, sizeof(info));
		if (!out)
		{
			cout << "Error writing to file." << endl;
		}
		out.close();

		cout << "Your Entry Has been saved ";
		cin.get();
		menu();
	}


	void show()
	{
		ifstream in("Taylor.txt", ios::binary);
		if (!in)
		{
			cout << "\n\n No Data In the File ";
			cout << "\n\n\t Press Any Key To Continue : ";
			cin.get();
			menu();
		}
		else
		{
			while (in.read((char*)&a1, sizeof(a1)))
			{
				if (in)
				{
					a1.show();
				}
				else if (!in.eof())
				{
					cout << "\n\n Error reading data from the file.";
					cin.get();
					menu();
				}
			}
			in.close();
		}
		cin.get();
		menu();
	}
};

//========== Class for Dr. Jackson's information ==========

class Jackson :public info
{
public:
	info a1;
	void get()
	{
		system("cls");
		ofstream out("Jackson.txt", ios::app | ios::binary);
		a1.get();
		out.write((char*)&a1, sizeof(info));
		out.close();
		cout << "Your Entry Has been saved ";
		cin.get();
		menu();

	}
	void show()
	{

		ifstream in("Taylor.txt");
		if (!in)
		{
			cout << "\n\n No Data In the File ";
			cout << "\n\n\t Press Any Key To Continue : ";
			cin.get();
			menu();
		}

		else
		{
			while (!in.eof())
			{
				in.read((char*)&a1, sizeof(a1));
				a1.show();
			}
			in.close();
		}
		in.close();
		cout << "Press Enter To Continue ";
		cin.get();
		menu();
	}

};

//========== Class for Dr. Williams' information ==========

class Williams :public info
{
public:
	info a1;
	void get()
	{
		system("cls");
		ofstream out("Williams.txt", ios::app | ios::binary);
		a1.get();
		out.write((char*)&a1, sizeof(info));
		out.close();
		cout << "Your Entry Has been saved ";
		cin.get();
		menu();

	}
	void show()
	{

		ifstream in("Williams.txt");
		if (!in)
		{
			cout << "\n\n No Data In the File ";
			cout << "\n\n\t Press Any Key To Continue : ";
			cin.get();
			menu();
		}

		else
		{
			while (!in.eof())
			{
				in.read((char*)&a1, sizeof(a1));
				a1.show();
			}
			in.close();
		}

	}


};

//========== Staff info ==========

class staff : public one
{
public:
	char all[999];
	char name[50], age[20], sal[30], pos[20];

	void get()
	{
		ofstream out("staff.txt", ios::app);
		{
			system("cls");
			cin.sync();
			cout << "\n Enter name: ";
			cin.getline(name, 50);

			cin.ignore(); 

			cout << "\n Enter Age: ";
			cin.getline(age, 20);
			cin.ignore(); 

			cout << "\n Enter Salary: ";
			cin.getline(sal, 30);
			cin.ignore(); 

			cout << "\n Enter Working Position: ";
			cin.getline(pos, 20);
			cin.ignore();

		}

		out << "\n Name: " << name << "\n Age: " << age << "\n Sallary: " << sal << "\n Working Position: " << pos;
		out.close();
		cout << "\n Your information has been saved.\n\t Press any key to continue ";
		cin.get();
		menu();
	}

	void show()
	{
		ifstream in("staff.txt");
		if (!in)
		{
			cout << "File open error";
		}
		while (!(in.eof()))
		{
			in.getline(all, 999);
			cout << all << endl;
		}

		in.close();
		cout << "\n\t\t Press any key to continue ";
		cin.get();
		menu();
	}
};

//========== Available doctors ==========
class information
{
public:
	void drinfo()
	{
		system("cls");
		cout << "\n===========================================================\n";
		cout << "\n\n\t\t(Three Doctors Available) \n\n \t\t [Information and Timing Are Given Below]\n";
		cout << "-------------------------------------------------------------\n";
		cout << "\t\t Dr Available: \n";
		cout << "\t\t Dr Taylor (skin specialist)\n\n";
		cout << "\t\t\t [[Timing]]: \n\n";
		cout << "\tMonday To Friday\t\t9AM to 5PM\n";
		cout << "\tSaturday         \t\t9AM to 1PM\n";
		cout << "\tSunday            \t\tOff\n";
		cout << "\n===========================================================\n";
		cout << "\t\t Dr Jackson (child specialist)\n\n";
		cout << "\t\t\t [[Timing]]: \n\n";
		cout << "\tMonday To Friday\t\t2pm to 10PM\n";
		cout << "\tSaturday         \t\t8AM to 10PM\n";
		cout << "\tSunday            \t\t12PM to 9PM\n";
		cout << "\n===========================================================\n";
		cout << "\t\t Dr Williams (DVM)\n\n";
		cout << "\t\t\t [[Timing]]: \n\n";
		cout << "\tMonday To Friday\t\t8AM to 5PM\n";
		cout << "\tSaturday         \t\t10AM to 1PM\n";
		cout << "\tSunday            \t\tOff\n";
		cout << "\n===========================================================\n";
		cout << "\nPress Any Key For Continue: ";
		cin.get();

	}
};

//========== Function to initiate a doctor's appointment ==========

void call_dr()
{
	system("cls");
	int choice;
	cout << "\n\n\n\t\tPress 1 for Dr Taylor \n\n\t\t Press 2 for Dr Jackson \n\n\t\t Press 3 for Dr Williams";
	cin >> choice;

	one* ptr;
	Taylor s3;
	Jackson s4;
	Williams s5;
	if (choice == 1)
	{
		ptr = &s3;
		ptr->get();
	}
	if (choice == 2)
	{
		ptr = &s4;
		ptr->get();
	}
	if (choice == 3)
	{
		ptr = &s5;
		ptr->get();
	}
	else
	{
		cout << "Sorry Invalid Choice";
	}

}
//========== Function to display patient information for a selected doctor ==========
void pinfoshow()
{
	system("cls");
	int choice;
	cout << "\n\n\t\tPress 1 for Dr Taylor \n\n\t\tPress 2 for Dr Jackson \n\n\t\tPress 3 for Dr Williams";
	cout << "Please Enter Your Choice : ";
	cin >> choice;
	one* ptr;
	Taylor s3;
	Jackson s4;
	Williams s5;
	if (choice == 1)
	{
		ptr = &s3;
		ptr->show();
	}
	else if (choice == 2)
	{
		ptr = &s4;
		ptr->show();
	}
	else if (choice == 3)
	{
		ptr = &s5;
		ptr->show();
	}
	else
	{
		cout << "Sorry Invalid choice : ";
		cin.get();
		menu();
	}
}

//========== Function to validate the password from a file ==========
void pascode()
{
	system("cls");
	char p1[50], p2[50];

	system("color Fc");

	ifstream in("password.txt");
	{
		cin.sync();
		cout << "\n\n\n\n\t\tEnter The password: ";
		cin.getline(p1, 50);
		in.getline(p2, 50);
		if (strcmp(p2, p1) == 0)
		{
			menu();
		}
		else
		{
			cout << "\n\n\t\t\tIncorrect Passcode Please Try Again\n";
			Sleep(999);
			pascode();
		}
	}
	in.close();

}

//========== Function providing the main menu for the clinic management system ==========

void menu()
{
	system("cls");
	system("color FC");

	cout << "\n";
	cout << "\n";

	cout << "\t\t                |  ++++++++ Main Menu ++++++++++++   | \n";
	cout << "\t\t                |      Houston Clinic System Menu    |\n";
	cout << "\t\t                |====================================|    \n";

	cout << "\n------------------------------------------------------------------------------------\n ";
	cout << "\t\t                  Please Select Any Option               \n   ";


	cout << "\n\n\t1-\t\tPress 1 for Available Doctor Information\n\n";
	cout << "\n\n\t2-\t\tPress 2 for making a Doctor Appointment\n\n";
	cout << "\n\n\t3-\t\tPress 3 for Saving Staff Information\n\n";
	cout << "\n\n\t4-\t\tPress 4 for Checking Patient Appointment Menu:\n\n";
	cout << "\n\n\t5-\t\tPress 5 for Checking Staff Information Menu:\n\n";
	cout << "\n\n\t6-\t\tPress 6 for Change Password or Create password :\n\n";
	cout << "\n\n\t7-\t\t[     Press 7 for Logout       ]\n";

	cout << "\n=================================================================================================\n";
	cout << "\n\n\tPlease Enter Your Choice : ";
	information a1;
	one* ptr;
	staff a2;
	int a;
	cin >> a;
	if (a == 1)
	{
		a1.drinfo();
		cin.get();     // Wait for the user to press Enter before returning to the menu
		menu();        // Return to the menu
	}

	else if (a == 2)
	{
		call_dr();
	}
	else if (a == 3)
	{
		ptr = &a2;
		ptr->get();
	}
	else if (a == 4)
	{
		pinfoshow();
	}
	else if (a == 5)
	{
		ptr = &a2;
		ptr->show();
	}
	else if (a == 6)
	{
		cpascode();
	}
	else if (a == 7)
	{
		pascode();
	}
	else
	{
		cout << "Sorry Invalid Choice : ";
	}
}

// ========== Function to change the password ==========

void cpascode()
{
	char n[50];
	system("cls");
	ofstream out("password.txt");
	{
		cin.sync();
		cout << "\n\n\n\n\t\tEnter The New Password ";
		cin.getline(n, 50);
		out << n;
	}
	out.close();
	cout << "\n\nYour Password has been saved : ";
	cin.get();
	menu();
}

//========== Main function ==========
// initiating the password validation process
int main()
{
	pascode();
	system("pause");
}
