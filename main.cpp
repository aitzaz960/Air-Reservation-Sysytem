

// Group Memebers
//
// Humayun Afzal		18I-0738
// Aitzaz Ahmad			18I-0589


#include<iostream>
#include "Project.h"
using namespace std;

int main()
{
	// making an object of ARS
	ARS ars_("Flights.txt", "HotelCharges_perday.txt");

	// variables to store details of flights specified by user
	string	Origin_,				// city of origin
		Destination_,			// destination
		DateOfTravel_,			// date of travel
		transit_location,		// transit location
		Airline_;				// airline name

	string	transit_min,
		transit_max;

	// some boolean variables as checks
	bool transit_location_b = 0;
	bool transit_hours_b = 0;

	bool c_t = 0;
	bool cost_travel = -1;
	bool airline_b = 0;

	bool direct_flight = 0;

	// selection varaibles
	int choice = 0;
	char select = 'a';

	// arrays containing city names, dates, airlines from graph
	int		Loc_Num = ars_.Num_Cities();
	string* Loc_Names = ars_.CityNames();
	string* dt = ars_.Dates_A();
	string* airl = ars_.Airlines_Names();
	int n_dt = ars_.Numb_Dates();
	int n_airl = ars_.Numb_Airline();





	// Splash screen
	//system("CLS");
	cout << endl << endl << endl;

	cout << "					" << " _____   _____   _____          _____           ____" << endl;
	cout << "					" << "|     |    |    |     |  |        |    |\\    | |    " << endl;
	cout << "					" << "|_____|    |    |_____|  |        |    | \\   | |____" << endl;
	cout << "					" << "|     |    |    |    \\   |        |    |   \\ | |    " << endl;
	cout << "					" << "|     |  __|__  |     \\  |_____ __|__  |    \\| |____" << endl;

	cout << "		" << " _____    ____   _____   ____    _____            _____    _______  _____   _____          " << endl;
	cout << "		" << "|     |  |      |       |       |     | \\      \/ |     |  |   |   |   |    |     |  |\\    |" << endl;
	cout << "		" << "|_____|  |____  |____   |____   |_____|  \\    \/  |_____|      |       |    |     |  | \\   |" << endl;
	cout << "		" << "|    \\   |           |  |       |    \\    \\  \/   |     |      |       |    |     |  |   \\ |" << endl;
	cout << "		" << "|     \\  |____  _____|  |____   |     \\    \\\/    |     |      |     __|__  |_____|  |    \\|" << endl;

	cout << "					" << " ____            ____   _______   _____            " << endl;
	cout << "					" << "|      \\     \/  |      |   |   | |       |\\      \/|" << endl;
	cout << "					" << "|____   \\   \/   |____      |     |____   | \\    \/ |" << endl;
	cout << "					" << "     |    |          |     |     |       |  \\  \/  |" << endl;
	cout << "					" << "_____|    |     _____|     |     |_____  |   \\\/   |" << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "					Enter any character to continue.. ";
	cin >> select;





	while (choice < 1 || choice > Loc_Num)
	{
		system("CLS");
		cout << endl << "						Welcome To Flight Reservation System" << endl << endl;

		// Select City Of Origin
		cout << "	" << "Select your current city: " << endl << endl;

		for (int i = 0; i < Loc_Num; i++)				// displaying cities
			cout << "	" << i + 1 << ". " << Loc_Names[i] << endl;
		cout << endl << "	";

		cin >> choice;
	}
	Origin_ = Loc_Names[choice - 1];





	// Select City Of Destination
	choice = 0;
	while (choice < 1 || choice > Loc_Num || Loc_Names[choice - 1] == Origin_)
	{
		system("CLS");

		cout << endl << endl << endl << "	" << "Select your destination city: " << endl << endl;

		for (int i = 0; i < Loc_Num; i++)		// display cities
		{
			cout << "	" << i + 1 << ". " << Loc_Names[i];
			if (Loc_Names[i] == Origin_)		// if city as used as origin place a X in front of it
				cout << "	X";
			cout << endl;
		}
		cout << endl << "	";

		cin >> choice;
	}
	Destination_ = Loc_Names[choice - 1];		// save selected city in Destination_





	// Select Date For Flight
	choice = 0;
	while (choice < 1 || choice > n_dt)
	{
		system("CLS");

		cout << endl << endl << endl << "	" << "Select date of flight:" << endl << endl;

		for (int i = 0; i < n_dt; i++)		// display dates
			cout << "	" << i + 1 << ". " << dt[i] << endl;
		cout << endl << "	";

		cin >> choice;
	}
	DateOfTravel_ = dt[choice - 1];		// save select date as DateOfTravel





	// Select Transit
	system("CLS");

	// asking user if they want to specify a transit location
	cout << endl << endl << endl << "	" << "Do You want to have a transit(Y/N): ";
	cin >> select;

	if (select == 'y' || select == 'Y')
		transit_location_b = 1;

	// if user wants to specify a transit location
	if (transit_location_b)
	{
		choice = 0;
		while (choice < 1 || choice > Loc_Num || Loc_Names[choice - 1] == Origin_ || Loc_Names[choice - 1] == Destination_)
		{
			system("CLS");

			// Getting a Transit Location
			choice = 0;

			cout << endl << endl;
			cout << endl << "	" << "Select a transit location: " << endl << endl;

			for (int i = 0; i < Loc_Num; i++)		// display a transit location
			{
				cout << "	" << i + 1 << ". " << Loc_Names[i];
				if (Loc_Names[i] == Origin_ || Loc_Names[i] == Destination_)	// put a X if location was used as origin and destination
					cout << "	X";
				cout << endl;
			}
			cout << endl << "	";

			cin >> choice;
		}
		transit_location = Loc_Names[choice - 1];	// saving selected city as transit location


		// Getting transit hours
		cout << endl << "	" << "Do You want to specify transit hours(Y/N): ";

		cin >> select;

		if (select == 'y' || select == 'Y')
		{
			transit_hours_b = 1;
			cout << endl;
			//	cin.ignore();
				// get minimum transit hours
			cout << "	" << "Enter hours minimum transit duration (00:00):	";
			cin >> transit_min;
			//cin.ignore();
			// get maximum transit hours
			cout << "	" << "Enter hours maximum transit duration (00:00):	";
			cin >> transit_max;
		}
	}




	// Select Airline
	system("CLS");

	cout << endl << endl << endl << "	" << "Do You want to specify Airline(Y/N): ";
	cin >> select;

	if (select == 'y' || select == 'Y')
	{
		airline_b = 1;
		cout << endl << "	" << "Select An Airline For Flight:" << endl << endl;

		for (int i = 0; i < n_airl; i++)		// displaying all the airlines
			cout << "	" << i + 1 << ". " << airl[i] << endl;
		cout << endl << "	";

		cin >> choice;
		Airline_ = airl[choice - 1];		// Saving selected Airline as Airline_
	}




	// Select Cost or Travel Time
	system("CLS");
	cout << endl << endl << endl << "	" << "Do You want to mention cost or travel time(Y/N): ";
	cin >> select;

	if (select == 'y' || select == 'Y')
	{
		cout << endl;
		cout << "	1. Cost\n	2. Travel Time" << endl;
		cout << endl << "	";
		cin >> cost_travel;
	}


	// if transit location is not specified ask if used wants a direct flight
	if (transit_location_b != 1)
	{
		system("CLS");
		cout << endl << endl << endl << "	" << "Do you want to have a direct flight(Y/N): ";
		cin >> select;

		if (select == 'y' || select == 'Y')
			direct_flight = 1;
		else
			direct_flight = 0;
	}


	// display paths according to user query
	ars_.Show_Routes(Origin_, Destination_, DateOfTravel_,
		transit_location_b, transit_location,
		transit_hours_b, transit_min, transit_max,
		airline_b, Airline_,
		direct_flight, cost_travel, 1);


	// end
	cout << "Enter any character to exit...";
	int stop;
	cin >> stop;
	return 0;

}
