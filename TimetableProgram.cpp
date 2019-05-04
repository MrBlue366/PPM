#include <iostream>
#include <string>
#include <fstream>

using namespace std;


string class_name[5];
int class_options[5], class_amount, loop = 1, class_day_amount[5][4], class_days_time[5][4][5][2];
char class_days[5][4][5];
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

void lessonsPerClass() //Prompts how many unique sessions a class has per week
{

	outFile << "\n";
	for (int m = 0; m < class_amount; m++) // Number of lessons per class
	{
		cout << "How many unique sessions (lecture, lab, tutor session, ect.) does " << class_name[m] << " have a week?: ";
		cin >> class_options[m];
		while (class_options[m] < 0 || class_options[m] > 4) // Checks for incorrect input.
		{
			cout << "The amount you have entered is invalid. Input from 0 to 4 unique sessions, try again: ";
			cin >> class_options[m];
		}
		outFile << "Unique sessions per week for " <<class_name[m] <<": " << class_options[m] << endl;
	}
}

void lecturesLabs() //Prompts for how many days a class has for each unique session
{

	for (int x = 0; x < class_amount; x++) // Retrieves number of days per week for each class.
	{
		cout << endl << "Class #" << x + 1 << " has " << class_options[x] << " options." << endl;

		cout << "\n(Please enter the value for lectures first, then labs and then other sessions )" << endl;
		for (int y = 0; y < class_options[x]; y++)
		{
			cout << "How many days a week does class #" << x + 1 << " (" << class_name[x] << ") session #" << y + 1 << " have: ";
			cin >> class_day_amount[x][y]; //max 5 for the class_days
			while (loop == 1) // Checks for incorrect input.
			{
				if (class_day_amount[x][y] < 1 || class_day_amount[x][y] > 5)
				{
					cout << "The amount you have entered is invalid. Input from 1 to 5 day(s) a week per unique session, try again: ";
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

void dayForClass() //Prompts for the day+time of each class
{
	outFile << "\n";
	cout << endl << "Monday = M. Tuesday = T. Wednesday = W. Thursday = H. Friday = F." << endl;

	for (int x = 0; x < class_amount; x++) // Retrieves the specific days per week for each class.
	{
		cout << endl << "Prompting for information on class #" << x + 1 << " (" << class_name[x] << ").";
		cout << "\n(Please enter the days for lectures first, then labs and then other sessions )" << endl;
		for (int y = 0; y < class_options[x]; y++)
		{
			cout << endl << "Prompting for information on session #" << y + 1 << " of the above class.";
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
				loop = 1; // Reset loop.

				cout << endl << "Type the time this session starts and press <Enter>: (24-hr standard)";
				cin >> class_days_time[x][y][z][0];
				while (loop == 1)
				{
					if (class_days_time[x][y][z][0] < 9 || class_days_time[x][y][z][0]>17)
					{
						cout << "The amount you have entered is invalid. Input from 9 to 17 (24-hr standard), try again: ";
						cin >> class_days_time[x][y][z][0];
					}
					else loop = 0;
				}
				loop = 1; // Reset loop.

				cout << endl << "Type the time this session ends and press <Enter>: (24-hr standard)";
				cin >> class_days_time[x][y][z][1];
				while (loop == 1)
				{
					if (class_days_time[x][y][z][1] < 10 || class_days_time[x][y][z][1]>18 || class_days_time[x][y][z][0] >= class_days_time[x][y][z][1])
					{
						cout << "The amount you have entered is invalid. Input from 10 to 18 (24-hr standard) and must be after the session starts, try again: ";
						cin >> class_days_time[x][y][z][1];
					}
					else loop = 0;
				}
				loop = 1; // Reset loop.

				outFile << "Session #" << class_options[x] << " for " << class_name[x] << " on: " << class_days[x][y][z] << " from " << class_days_time[x][y][z][0] << " to " << class_days_time[x][y][z][1] << endl;
			}
		}
	}
}

void getData() //Displays the days for each class
{

	for (int x = 0; x < class_amount; x++) // Retrieves the specific times for each day per week for each class.
	{
		cout << endl << "Prompting for information on class #" << x + 1 << " (" << class_name[x] << ").";

		for (int y = 0; y < class_options[x]; y++)
		{
			cout << endl << "Prompting for information on session #" << y + 1 << " of the above class.";
			cout << endl << "Days for above session and class: ";
			for (int z = 0; z < class_day_amount[x][y]; z++)
			{
				switch (toupper(class_days[x][y][z]))
				{
				case 'M':
					cout << "Monday ";
					break;
				case 'T':
					cout << "Tuesday ";
					break;
				case 'W':
					cout << "Wednesday ";
					break;
				case 'H':
					cout << "Thursday ";
					break;
				case 'F':
					cout << "Friday ";
					break;
				default:
					break;
				}
				// Retrieval of time.
				cout << "[" << class_days_time[x][y][z][0] << "-" << class_days_time[x][y][z][1] << "]";

				if ((z + 1) == class_day_amount[x][y])
				{
					cout << ".";
				}
				else
					cout << ", ";
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