#include <iostream>
#include <string>
#include <fstream>

using namespace std;


string class_name[4];
int class_options[4], class_amount, loop = 1, class_day_amount[4][4];
char class_days[4][4][4];
ofstream outFile ("timetable.txt");


void studentName() //Prompts student name
{
	string sName;

	cout << "Enter the name of the student: ";
	cin >> sName;

	if (outFile.is_open())
	{
		outFile << "Name of student: " << sName << endl;
		outFile << "\n";
	}
	else cout << "not open" << endl;
}


void classNumber() //Prompts number of classes
{
	cout << "Number of classes to be taken: ";
	cin >> class_amount; // Amout of classes to be taken
	while (loop == 1) // Error checking
	{
		if (class_amount > 5 || class_amount < 2)
		{
			cout << "The amount you have entered is invalid. Input from 2 to 5 classes." << endl;
			cin >> class_amount;
		}
		else
		{			
			loop = 0;
		}
	}
	if (outFile.is_open())
	{
		outFile << "Number of Classes: " << class_amount << endl;
	}
	else cout << "not open" << endl;

	loop = 1; // Resets while loop.
}

void className() //Prompts name of classes
{
	outFile << "\n";
	for (int m = 0; m < class_amount; m++)
	{
		cout << "Name of Class #" << m + 1 << ": ";
		cin >> class_name[m];
		outFile << "Name of Class #" << m + 1 << ": " << class_name[m] << endl;		
	}

	cout << endl;
}

void lessonsPerClass() //Prompts how many lectures and labs a class has per week
{

	outFile << "\n";
	for (int m = 0; m < class_amount; m++) // Number of lessons per class
	{
		cout << "How many lectures and labs(combined) does " << class_name[m] << " have a week?: ";
		cin >> class_options[m];
		while (class_options[m] < 0)
		{
			cout << "The amount you have entered is invalid, try again: ";
			cin >> class_options[m];
		}
		outFile << "Lectures and labs per week for " <<class_name[m] <<": " << class_options[m] << endl;
	}
}

void lecturesLabs() //Prompts for how many days a class has lectures and how many days a class has labs
{

	for (int x = 0; x < class_amount; x++) // Retrieves number of days per week for each class.
	{
		cout << endl << "Class #" << x + 1 << " has " << class_options[x] << " options." << endl;

		cout << "\n(Please enter the value for lectures first and then labs)" << endl;
		for (int y = 0; y < class_options[x]; y++)
		{
			cout << "How many days a week does class #" << x + 1 << " (" << class_name[x] << ") Option #" << y + 1 << " have: ";
			cin >> class_day_amount[x][y];
			while (loop == 1) // Checks for incorrect input.
			{
				if (class_day_amount[x][y] < 1)
				{
					cout << "The amount you entered was not operable, try again: ";
					cin >> class_day_amount[x][y];
				}
				else
				{
					loop = 0;
				}

			}
			
		}
	}


	loop = 1; // Resets while loop.
}

void dayForClass() //Prompts for the day of each class
{
	outFile << "\n";
	cout << endl << "Monday = M. Tuesday = T. Wednesday = W. Thursday = H. Friday = F." << endl;

	for (int x = 0; x < class_amount; x++) // Retrieves the specific days per week for each class.
	{
		cout << endl << "Prompting for information on class #" << x + 1 << " (" << class_name[x] << ").";

		for (int y = 0; y < class_options[x]; y++)
		{
			cout << endl << "Prompting for information on Option #" << y + 1 << " of the above class.";

			for (int z = 0; z < class_day_amount[x][y]; z++)
			{
				cout << endl << "Type the hot key for Day #" << z + 1 << " and press <Enter>: ";
				cin >> class_days[x][y][z];
				while (loop == 1) // Checks for incorrect input.
				{
					switch (toupper(class_days[x][y][z]))
					{
					case 'M':
						loop = 0;
						break;
					case 'T':
						loop = 0;
						break;
					case 'W':
						loop = 0;
						break;
					case 'H':
						loop = 0;
						break;
					case 'F':
						loop = 0;
						break;
					default:
						cout << "The character you entered was not correct, try again: ";
						cin >> class_days[x][y][z];
						break;
					}

				}
				outFile << "Lectures and Labs for " << class_name[x] << " on: "<< class_days[x][y][z] << endl;
			}
		}
	}
	loop = 1; // Reset loop.
}

void getData() //Displays the days for each class
{

	for (int x = 0; x < class_amount; x++) // Retrieves the specific times for each day per week for each class.
	{
		cout << endl << "Prompting for information on class #" << x + 1 << " (" << class_name[x] << ").";

		for (int y = 0; y < class_options[x]; y++)
		{
			cout << endl << "Prompting for information on Option #" << y + 1 << " of the above class.";

			for (int z = 0; z < class_day_amount[x][y]; z++)
			{
				switch (toupper(class_days[x][y][z]))
				{
				case 'M':
					cout << "Monday of the above option and class.";
					break;
				case 'T':
					cout << "Tuesday of the above option and class.";
					break;
				case 'W':
					cout << "Wednesday of the above option and class.";
					break;
				case 'H':
					cout << "Thursday of the above option and class.";
					break;
				case 'F':
					cout << "Friday of the above option and class.";
					break;
				default:
					break;
				}
				for (int v = 0; v < class_days[x][y][z]; v++)
				{
					// Retrieval of time.
				}
			}
		}
	}
	cout << "\n\n" << endl;
}

void printTimeTable()
{

}

void readFile() //Reads from the file and displays the current stored data to the user
{
	string text;
	ifstream inFile("timetable.txt");
	if (inFile.is_open())
	{
		while (getline(inFile, text))
		{
			cout << text << '\n';
		}
		inFile.close();
	}

	else
	{
		cout << "File cannot be opened.";
	}

}

void timetableWeek() //all the functions called here to avoid messy main
{
	cout << "-------------------------------------------------------------------------------" << endl;
	studentName();
	cout << "-------------------------------------------------------------------------------" << endl;
	classNumber();
	cout << "-------------------------------------------------------------------------------" << endl;
	className();
	cout << "-------------------------------------------------------------------------------" << endl;
	lessonsPerClass();
	cout << "-------------------------------------------------------------------------------" << endl;
	lecturesLabs();
	cout << "-------------------------------------------------------------------------------" << endl;
	dayForClass();
	cout << "-------------------------------------------------------------------------------" << endl;
	getData();
}

int main()
{
	char add;

	timetableWeek();

	cout << "-------------------------------------------------------------------------------" << endl;
	readFile();
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Would you like to input another week(Y/N)? " << endl;
	cin >> add;
	add = toupper(add);

	while (add != 'Y' && add != 'N')
	{
		std::cout << "Please enter either 'Y' or 'N'!" << std::endl;
		std::cout << "Would you like to input another week(Y/N)?  ";
		std::cin >> add;
		add = toupper(add);
	}
	if (add == 'Y')
	{
		outFile << "\n";
		outFile << "----------------";
		outFile << "\n";
		main(); //Recursion to allow for the addition of multiple weeks
	}
	else {
		outFile.close();
	}

	return 0;
}