#include <iostream>
#include <string>

using namespace std;

string class_name[4];
int class_options[4], class_amount, loop = 1, class_day_amount[4][4];
char class_days[4][4][4];

void classNumber()
{
	cout << "Number of classes to be taken: ";
	cin >> class_amount; // Amout of classes to be taken
	while (loop == 1) // Error checking
	{
		if (class_amount > 5 || class_amount < 2)
		{
			cout << "The amount you have entered is invalid. Input from 2 to 5 classes." << endl;
			cin, class_amount;
		}
		else
		{
			loop = 0;
		}
	}

	loop = 1; // Resets while loop.
}

void className()
{
	for (int m = 0; m < class_amount; m++)
	{
		cout << "Name of Class #" << m + 1 << ": ";
		cin >> class_name[m];
	}

	cout << endl;
}

void lessonsPerClass()
{

	for (int m = 0; m < class_amount; m++) // Number of lessons per class
	{
		cout << "How many lectures and labs(combined) does " << class_name[m] << " have a week?: ";
		cin >> class_options[m];
		while (class_options[m] < 0)
		{
			cout << "The amount you have entered is invalid, try again: ";
			cin >> class_options[m];
		}
	}
}

void lecturesLabs()
{

	for (int x = 0; x < class_amount; x++) // Retrieves number of days per week for each class.
	{
		cout << endl << "Class #" << x + 1 << " has " << class_options[x] << " options." << endl;

		cout << "\n(Please enter the value for lectures first and then labs." << endl;
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

void dayForClass()
{
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
			}
		}
	}

	loop = 1; // Reset loop.
}

void getData()
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

void timetableWeek()
{
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
		timetableWeek();
	}

	return 0;
}