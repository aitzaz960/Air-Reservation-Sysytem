
// Group Memebers
//
// Humayun Afzal		18I-0738
// Aitzaz Ahmad			18I-0589

#ifndef PROJECT_H
#define PROJECT_H

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;





// T I M E		C L A S S

class Time
{

private:
	int hour;																		//variable to store number of hours											
	int minutes;																	//variable to store no of minutes
	string time_;																	//string to display and maintain proper representation of the time

public:

	// Constructor
	Time()																			//default constructor
	{
		hour = 0;
		minutes = 0;
		time_ = "";
	}

	// Set Time Function
	void set_time(string t)
	{
		if (t[1] == ':')															//if number of hours are less than 10
		{
			// hour
			hour = t[0] - 48;														//hours will be equal to ascii of 1st character minus 48
			// minutes
			minutes = t[2] - 48;													//minutes will be calculated from the asciis of 3rd and 4th character of string
			minutes *= 10;
			minutes += t[3] - 48;
			time_ = t;																//simply equate the strings
		}
		else                                                                        //else hours will be doubly digit
		{
			// hour
			hour = t[0] - 48;														//hours will be calculated from ascii of 1st two characters of string
			hour *= 10;
			hour += t[1] - 48;
			// minutes
			minutes = t[3] - 48;													//minutes will be calculated from the asci of 4th and 5th charater of string
			minutes *= 10;
			minutes += t[4] - 48;
			time_ = t;																//simply equate the time strings
		}
	}

	// Check Time Function
	// Compares the time returns
	// 1 if same 
	// 2 if less
	// 3 if greater
	int check_time(const Time& obj)
	{
		if (hour < obj.hour)															//if number of hours are smaller means time is lesser
			return 2;
		else if (hour > obj.hour)														//if number of hours is greater means time is greater
			return 3;
		else if (hour == obj.hour)														//if hours are same than check the minutes
		{
			if (minutes == obj.minutes)													//if minutes are also same then it means both the times are equal
				return 1;
			else if (minutes < obj.minutes)
				return 2;
			else if (minutes > obj.minutes)
				return 3;
		}
	}

	// Add Time Function
	void add_time(const Time obj)														//function to add time
	{
		hour += obj.hour;																//add the hours of both objects
		minutes += obj.minutes;															//add the minutes of both objects
		if (minutes >= 60)																//if minutes are greater than 60 increment hours and retain the minutes
		{
			minutes -= 60;
			hour++;
		}
		update_time_str();																//function to update the string of time
	}

	// Sub Time Function
	void sub_time(const Time obj)														//function to subtratct time
	{
		hour -= obj.hour;																//subtracting the hours
		minutes -= obj.minutes;															//subtracting the minutes
		if (minutes < 0)																//if minutes are less than zero decrement in hours and retain the minutes		
		{
			minutes += 60;
			hour--;
		}
		update_time_str();																//update the string of time
	}

	// Update Time String Function
	void update_time_str()																//function to update the string of time
	{
		stringstream hh, mm;
		hh << hour;
		string temp_h = hh.str();														//converting the hours from integer to string
		temp_h.append(":");																//appending : afetr hours
		string temp_m;
		if (minutes < 10)																//if minutes are less than 10
		{
			if (minutes == 0)															//if minutes are 0 repalce space of minutes by 00
				temp_m = "00";
			else
			{
				mm << minutes;
				temp_m = mm.str();
				temp_m.append("0");														//else they will be in range of 1-9 so left most bit will be 0
			}
		}
		else
		{
			mm << minutes;
			temp_m = mm.str();															//else convert the minutes from integre tostrings
		}
		temp_h.append(temp_m);															//now appending minutes in the time
		time_ = temp_h;
	}

	// Add 24 Hours Function
	// add 24 hours to the time
	void add_24Hours()
	{
		hour += 24;
		update_time_str();																//adjusting the time after adding 24 hours
	}

	// Sub From 24 Hour Function
	// subtracts time from 24 hours
	void sub_from_24Hour()
	{
		Time temp;
		temp.set_time("24:00");
		sub_time(temp);																	//subtracting the time from 24:00
	}

	// Get Hours Function
	int get_hours()
	{
		return hour;																	//returning no of hours
	}

	// Get Minutes Function
	int get_minutes()
	{
		return minutes;																	//returning number of minutes
	}

	// Time To Str Function
	string time_to_str()
	{
		return time_;																	//returning string of time
	}

};





//	D A T E		C L A S S

class Date
{

private:
	int day;																			//variable to store the day
	int month;																			//variable to store current number of month
	int year;																			//variable to store current year
	string date_;																		//string to hold proper representation of the date

public:

	// Constructor
	Date()																				//default constructor
	{
		day = 0;
		month = 0;
		year = 0;
		date_ = "";
	}

	// Set Date Function
	void set_Date(string dt)
	{
		date_ = dt;																		//simply equate the string
		if (dt[1] == '/')																//if days are singly digit
		{
			day = dt[0] - 48;															//day canbe found by subtracting 48 from ascii of 1st character

			month = dt[2] - 48;															//month canbe get from ascii of 3rd and 4th charcters of string
			month *= 10;
			month += dt[3] - 48;

			year = dt[5] - 48;															//hours will be calculated from the asiis of 6-9th chaacters of string
			year *= 10;
			year += dt[6] - 48;
			year *= 10;
			year += dt[7] - 48;
			year *= 10;
			year = dt[8] - 48;
			year *= 10;
		}
		else if (dt[2] == '/')															//else if day is doubly digit
		{
			day = dt[0] - 48;															//calculate mon th ascii of 1st 2 characters of string
			day *= 10;
			day += dt[1] - 48;

			month = dt[3] - 48;															//month canbe get from ascii of 3rd and 4th charcters of string
			month *= 10;
			month += dt[4] - 48;

			year = dt[6] - 48; 															// hours will be calculated from the asiis of 6 - 9th chaacters of string
			year *= 10;
			year += dt[7] - 48;
			year *= 10;
			year += dt[8] - 48;
			year *= 10;
			year = dt[9] - 48;
			year *= 10;
		}
	}

	// Compare Date Function
	int compare_date(const Date& obj)
	{
		if (year < obj.year)
			return 2;													//current year is less so the date is lesser
		else if (year > obj.year)
			return 3;													//current year is greater so the date is greater
		else if (year == obj.year)										//if yerars are equal check the minutes
		{
			if (month < obj.month)										//if month is less means date is less
				return 2;
			else if (month > obj.month)									//if month is greater means the date is greater
				return 3;
			else if (month == obj.month)								//if months are equal then check the day
			{
				if (day < obj.day)										//if days are less means day is less
					return 2;
				else if (day > obj.day)									//if days are greater than day is greater
					return 3;
				else if (day == obj.day)								//else date will be same
					return 1;
			}
		}
	}

	// Get Day Function
	int get_Day() {
		return day;														//returning the day
	}

	// Get Month Function
	int get_Month() {
		return month;													//returning month
	}

	// Get Year Function
	int get_Year() {
		return year;													//returning year
	}

	// Compare Date Function
	// returns
	// 1 if equal
	// 2 if less
	// 3 if greater
	int compare_date(const Date& obj, int val)							//function to add the value in day and compare the dates
	{
		val += day;														//adding the value in day
		if (year < obj.year)											//current year is less so the date is lesser
			return 2;
		else if (year > obj.year)										//current year is greater so the date is greater
			return 3;
		else if (year == obj.year)										//if yerars are equal check the minutes
		{
			if (month < obj.month)										//if month is less means date is less
				return 2;
			else if (month > obj.month)									//if month is greater means the date is greater
				return 3;
			else if (month == obj.month)								//if months are equal then check the day
			{
				if (val < obj.day)										//if days are less then date is smaller
					return 2;
				else if (val > obj.day)									//if days are greater than date is greater
					return 3;
				else if (val == obj.day)								//else date will be same
					return 1;
			}
		}
	}

	// To Str Function
	string to_str()
	{
		return date_;															//returning string of dat
	}

};





//  V E C T O R		C L A S S

template <class T>
class Vector
{
	T* ptr;																				//array of T type
	int size;																			//variable to store size of array
	int index;																			//variable to store current index of array
public:

	// Constructor
	Vector()																			//default constructor
	{
		ptr = NULL;
		size = 0;
		index = -1;
	}

	// Parametrized Constructor
	Vector(int n)																			//parametrized constructor
	{
		ptr = new T[n];																		//allocating memory for n values
		size = n;																			//adjusting the size
		index = -1;																			//initially setting the index to -1
	}


	// Is Empty Function
	bool isEmpty()
	{
		if (index <= -1)											// returns true if vector is empty
			return true;
		else
			return false;
	}

	// Clear Function
	void clear()															// clears the vector
	{
		index = -1;
	}

	// Push Function
	void push(T data)
	{
		index++;
		if (ptr == NULL)												//if ptr is null allocate memory to 2 cells and insert the data at the required index
		{
			ptr = new T[2];
			ptr[index] = data;
			size = 2;
		}
		else
		{
			if (index >= size)														//if the array is already filled
			{
				T* temp = new T[size * 2];											//make a new array twice in size than the original
				for (int i = 0; i < size; i++)										//copy all elemets of previous array
					temp[i] = ptr[i];
				delete[]ptr;														//delete previous array to save memory
				size *= 2;															//adjust the size
				ptr = new T[size];													//now again allocate memory to the original pointer
				for (int i = 0; i < size; i++)										//copy all elements which were saved as a backup
					ptr[i] = temp[i];
				//	delete[]temp;
			}
			ptr[index] = data;														//insert data
		}
	}

	// Get Size Function
	int getSize()
	{
		return index + 1;														//returning no of elements
		//return size;
	}

	// Get No Of Elements Function
	int getNoOfElements()
	{
		return index + 1;														//returning no of elements
	}

	// Display Function
	void display()
	{
		for (int i = 0; i <= index; i++)										//displaying contents of array
			cout << ptr[i] << "\t";
		cout << endl;
	}

	// Get At Function
	T getAt(int ind)
	{
		return ptr[ind];															//getting content of specific index
	}

	// [ ] Operator Overloaded
	T& operator[](int ind)															//overloaded the []operator
	{
		return ptr[ind];
	}

	// Destructor
	~Vector() {
		for (int i = size - 1; i = 0; i--)
			delete (ptr + i);														//deallocating memory in destructor
	}
};





// Search String Function
// searches a string in a string vector and returns true or false
bool search_string(Vector<string>& t, string str)										//function to verify presence of string in a vector
{
	bool found = 0;
	for (int a = 0; a < t.getSize(); a++)
		if (t[a] == str)
			found = 1;
	return found;
}





// N O D E		C L A S S
class Node											//class of node
{
public:
	// Data members
	string Origin;					//ciy of origin
	Node* Destination;				//a pointer pointing to the city of destination

	int TicketPrice;				// ticket Price for flight
	string Airline;					// name of Airline
	int Hotel_Charg;				// hotel charges of that country
	Date DateOfTravel;				// date of travel of flight
	Time FlyingTime;				// flying time of flight
	Time LandingTime;				// landing time of flight
	Time Travel_Time;				//	total time of the flight
	Time Transit_Time;				//  transit time between this flight and the next flight

	bool p_check;					// if path is valid p_check is true else false

	// Constructor
	Node()																				//default constructor
	{
		Origin = "";
		Destination = NULL;
		TicketPrice = 0;
		Airline = "";
		Hotel_Charg = 0;
		p_check = 1;
	}

	// Show Data Function
	void show_data()															//function to display contents of node
	{
		cout << "Destination: " << Origin << endl;
		cout << "Date of Travel: " << DateOfTravel.to_str() << endl;
		cout << "Flying Time: " << FlyingTime.time_to_str() << endl;
		cout << "Landing Time: " << LandingTime.time_to_str() << endl;
		cout << "Ticket Price: " << TicketPrice << endl;
		cout << "AirLine: " << Airline << endl;
		cout << "Hotel Charges: " << Hotel_Charg << endl;
	}

};




// Find Value Function
// Finds a string in the array of strings and returns its index
int find_value(string arr[], string value, int size)											//function to return the index of string in string array
{
	int index = -1;							// intial index set to -1
	bool go = true;
	for (int a = 0; go && a < size; a++)
	{
		if (arr[a] == value)			// if value was found then stop the loop and save the index
		{
			index = a;
			go = false;
		}
	}
	return index;
}





// A D J L I S T		C L A S S

class AdjList																						//class of adjoincy list
{

public:
	Node* head;																						//pointer of head

	// Constructor
	AdjList()																						//default constructor
	{
		head = NULL;
	}

	// Insert Function
	void insert(Node* newDataItem)																	//prametrized constructor
	{
		if (head == NULL) {																			//if head is null insert data at head
			head = newDataItem;
		}
		else
		{
			Node* temp = head;
			while (temp->Destination != NULL) {														//else keep on going till we reach to null
				temp = temp->Destination;
			}
			temp->Destination = newDataItem;														//now insert data at null
		}
	}

	// Display Function
	void display()
	{																			//displaying contents of adjoincy list
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->Origin << "|" << temp->Travel_Time.time_to_str() << " ";
			temp = temp->Destination;
		}
		cout << endl;
	}

	// Search
	bool search(string value)															//verify whether the value exits in list or not
	{
		bool found = false;
		Node* temp = head;
		while (temp)
		{
			if (temp->Origin == value)
				found = true;
			temp = temp->Destination;
		}
		return found;
	}

};





// A R S		C L A S S 

class ARS																				//main calss of air reservation system
{
private:
	AdjList* array;																		//array of adjoincy list
	int num_vertex;																		//variable to store num of vertices
	int NoOfCities;																		//variable to store no of cities
	int number;


	string* cities;																			//array of city names
	string* dates;																			//array of dates
	string* airlines;																		//array of airlines
	int* hotel_charges;																		//array of hotel charges

	int num_dates;																			//total no of dates available
	int num_airlines;																		//total no of airlines

public:

	// Constructor
	ARS(string flights, string hotels)
	{
		number = 0;

		fstream flights_file(flights.c_str());													//opening file of flights
		fstream hotels_file(hotels.c_str());													//opening file of hotel charges

		string str;			// a temp string used while reading file
		bool cont = true;	// a bool variable used to control while loop
		string temp_str;	// a temp string used in reading file

		Vector<string> temp_city;																//vector for holding name of cities
		Vector<string> temp_dates;																//vector for holding the available dates
		Vector<string> temp_airlines;															//vector for holding name of airlines

		while (cont)
		{
			// Origin
			flights_file >> temp_str;															//getting city of origin from file
			if (search_string(temp_city, temp_str) == 0)										//if city isn't present in temp city vector push it
				temp_city.push(temp_str);

			// Destination	
			flights_file >> temp_str;															//getting city of destination from file
			if (search_string(temp_city, temp_str) == 0)										//if city isn't present in temp city vector push it
				temp_city.push(temp_str);

			// Date of travel
			flights_file >> temp_str;															//getting date of travel from file
			if (search_string(temp_dates, temp_str) == 0)										//if date isn't present in temp dates vector push it
				temp_dates.push(temp_str);

			// Flying Time																		//getting flying time from file
			flights_file >> str;
			// Landing Time
			flights_file >> str;																//getting landing time from file
			// Ticket Price
			flights_file >> str;																//getting ticket price from file

			// Airline
			flights_file >> temp_str;															//getting the name of airline from file
			if (search_string(temp_airlines, temp_str) == 0)									//if the airline is not present in vector then insert it
				temp_airlines.push(temp_str);

			// check if file is ended
			if (flights_file.eof())																//if the file has ended exit from loop
				cont = false;
		}

		NoOfCities = temp_city.getSize();														//getting no of cities

		cities = new string[NoOfCities];														//allocating memory to cities
		dates = new string[temp_dates.getSize()];												//allocating memory to dates
		num_dates = temp_dates.getSize();														//getting no of dates

		airlines = new string[temp_airlines.getSize()];											//allocating memory to airlines
		num_airlines = temp_airlines.getSize();													//getting no of airlines
		hotel_charges = new int[NoOfCities];													//allocating memory for hotel charges
		for (int i = 0; i < NoOfCities; i++)
			hotel_charges[i] = 0;
		array = new AdjList[NoOfCities];														//allocating memory to adjoincy list

		// making array of city names from temp_city vector
		for (int i = 0; i < NoOfCities; i++)
			cities[i] = temp_city[i];

		// making array of dates from temp_dates vector
		for (int i = 0; i < temp_dates.getSize(); i++)
			dates[i] = temp_dates[i];

		// making array of airlines names from temp_airlines vector
		for (int i = 0; i < temp_airlines.getSize(); i++)
			airlines[i] = temp_airlines[i];

		// saving hotel charges in hotel charges variable
		cont = true;
		string str1;
		int charges;
		int i = 0;
		while (cont)
		{
			// city name
			hotels_file >> str1;

			// getting index of city
			bool c = 1;
			for (i = 0; i < NoOfCities && c; i++)
			{
				if (cities[i] == str1)
					c = 0;
			}

			// hotel charges
			hotels_file >> charges;													//converting hotel charges from string to integer
//			stringstream hc(str);
//			hc >> hotel_charges[i];
			hotel_charges[i] = charges;

			if (hotels_file.eof())												//if file ended exit from loop
				cont = false;
		}

		// creating head nodes for adjancy list
		for (int i = 0; i < NoOfCities; i++)
		{
			Node* new_node = new Node;
			new_node->Origin = cities[i];														//inserting the city of origin
			new_node->Hotel_Charg = hotel_charges[i];											//inserting hotel charges 
			array[i].insert(new_node);
		}


		// go to the start of file
		flights_file.clear();
		flights_file.seekg(0, ios::beg);

		cont = true;
		while (cont)
		{
			string s_origin;
			Node* new_node = new Node;

			// origin
			flights_file >> s_origin;

			// Destination as Origin
			flights_file >> new_node->Origin;												//inserting city of origin in node

			// Date of travel
			flights_file >> str;
			new_node->DateOfTravel.set_Date(str);											//inserting date of travel in node

			// Flying Time
			flights_file >> str;
			new_node->FlyingTime.set_time(str);												//inserting flying time in node

			// Landing Time
			flights_file >> str;
			new_node->LandingTime.set_time(str);											//inserting landing time in node


			// if landing time > flying time
			if (new_node->LandingTime.check_time(new_node->FlyingTime) == 3)
			{
				// travel time = landing time - flying time
				new_node->Travel_Time = new_node->LandingTime;
				new_node->Travel_Time.sub_time(new_node->FlyingTime);						//total time of flight will be landing time - flying time
			}
			// if flying time > landing time
			else
			{
				// travel time = ( landing time + 24 hours ) - flying time
				new_node->Travel_Time = new_node->LandingTime;
				new_node->Travel_Time.add_24Hours();
				new_node->Travel_Time.sub_time(new_node->FlyingTime);
			}

			// Ticket Price
			flights_file >> str;
			stringstream s(str);
			s >> new_node->TicketPrice;															//inserting ticket price as integer in new node

			// Airline
			flights_file >> new_node->Airline;


			int index = find_value(cities, s_origin, NoOfCities);									//searching the index of city in array
			if (index != -1)																		//if city is present
			{
				new_node->Hotel_Charg = hotel_charges[index];										//inserting hotel charges of that specific city

				Node* temp = array[index].head;
				temp = temp->Destination;

				// Checking for duplicate entry
				bool dupliacte = 0;
				while (temp)
				{
					if (temp->Origin == new_node->Origin)
					{
						if (temp->Airline.compare(new_node->Airline) == 0 &&
							temp->FlyingTime.check_time(new_node->FlyingTime) == 1 &&
							temp->LandingTime.check_time(new_node->LandingTime) == 1 &&
							temp->DateOfTravel.compare_date(new_node->DateOfTravel) == 1 &&
							temp->TicketPrice == new_node->TicketPrice)
							dupliacte = 1;					//if another city with all same characteristics is present means dupicate found
					}
					temp = temp->Destination;										//check next city in that list
				}
				if (dupliacte == 0)															//if no duplicate found then insert the city
					array[index].insert(new_node);
			}

			// check if file is ended
			if (flights_file.eof())															//if file ended exit from loop
				cont = false;

		}

		// Constructor End
	}





	// Get Array Function
	AdjList* get_array()
	{
		return array;				//returning Adjoincy list 
	}

	// Num Cities Function
	// returns the total number of cities
	int Num_Cities() const
	{
		return NoOfCities;			//returning number of cities
	}

	// City Names Function
	// Returns the names of cities in the form of an array of strings
	string* CityNames()
	{
		return cities;				//returning the array of cities
	}

	// Dates A Function
	string* Dates_A()
	{
		return dates;				//returning the array of dates
	}

	// Airlines Names Function
	string* Airlines_Names()
	{
		return airlines;			//returning array of airlines
	}

	// Numb Dates Function
	int Numb_Dates()
	{
		return num_dates;			//returning no of avaiable dates
	}

	// numb Airline Function
	int Numb_Airline()
	{
		return num_airlines;		//returning num of airlines
	}





	// Get Paths Function
	// Returns the Paths as vector of vector of nodes
	// a single path is avector of nodes
	Vector<Vector<Node>> Get_Paths(string source_, string destination_)
	{
		// Get the node of the source city
		int index_s = 0;
		bool stop_s = false;
		for (int a = 0; a < NoOfCities && stop_s == false; a++)						//searching the source city
		{
			if (array[a].head->Origin == source_)
			{
				stop_s = true;		index_s = a;									//if city found exit from loop and save index in index_s
			}
		}

		// Get the node of the destination city
		int index_d = 0;
		bool stop_d = false;
		for (int a = 0; a < NoOfCities && stop_d == false; a++)						//now searching city of destination
		{
			if (array[a].head->Origin == destination_)
			{
				stop_d = true;		index_d = a;									//if city found exit from loop and save index in index_d
			}
		}

		Node* s = array[index_s].head;			// s points to source
		Node* d = array[index_d].head;			// d points to destination

		// A bool array that is of the sie number of cities and keep track of nodes visted
		bool* visited = new bool[NoOfCities];
		// Array of Nodes for saving path nodes
		Node* path = new Node[NoOfCities];
		// Number of nodes in path array
		int path_index = 0;
		// Intializing all visited nodes as zero
		for (int i = 0; i < NoOfCities; i++)
			visited[i] = false;

		// vector that will save nodes of paths
		Vector<Vector<Node>> paths;

		All_Paths(s, d, visited, path, path_index, paths);
		return paths;			// return paths
	}

	// Tota; Time And Charges Function
	void Total_Time_And_Charges(Vector<Vector<Node>>& paths)
	{
		// Total cost and total travel time
		for (int i = 0; i < paths.getSize(); i++)
		{
			for (int j = 0; j < paths[i].getSize(); j++)
			{
				// if node is not the first node then
				// Adding Travel Time and Ticket Price of Flight to first node
				if (j != 0)
				{
					paths[i][0].Travel_Time.add_time(paths[i][j].Travel_Time);
					paths[i][0].TicketPrice += paths[i][j].TicketPrice;
				}

				// Transit Time of Flights
				if (j != 0 && j <= (paths[i].getSize() - 2))
				{
					Time transit_time;
					// If landing time of flight 1 is greater than flying time
					if (paths[i][j].LandingTime.check_time(paths[i][j].FlyingTime) == 3)
					{
						// if both flights are on the same day
						if (paths[i][j].DateOfTravel.compare_date(paths[i][j + 1].DateOfTravel) == 1)
						{
							// transit time = flying time of flight 2 - landing time of flight 1
							transit_time = paths[i][j + 1].FlyingTime;
							transit_time.sub_time(paths[i][j].LandingTime);
						}
						else
						{
							// transit time = 24 hours in day - landing time of flight 1
							transit_time.set_time("24:00");
							transit_time.sub_time(paths[i][j].LandingTime);
							int v = 1;
							// add 24 hours for each day if date of flight 2 has not yet reached
							while (paths[i][j].DateOfTravel.compare_date(paths[i][j + 1].DateOfTravel, v) != 1)
							{
								transit_time.add_24Hours();
								v++;
							}
							// when both dates are equal then add the flying time of flight 2 to the transit time
							if (paths[i][j].DateOfTravel.compare_date(paths[i][j + 1].DateOfTravel, v) == 1)
								transit_time.add_time(paths[i][j + 1].FlyingTime);
						}
					}
					// If landing time of flight 1 is less than flying time
					// means flights goes in the next day
					else
					{
						int v = 1;
						// check is date of flight 1 + v == date of next flight
						while (paths[i][j].DateOfTravel.compare_date(paths[i][j + 1].DateOfTravel, v) != 1)
						{
							transit_time.add_24Hours();
							v++;
						}
						// if date of flight 1 + v  == date of next flight
						if (paths[i][j].DateOfTravel.compare_date(paths[i][j + 1].DateOfTravel, v) == 1)
							transit_time.add_time(paths[i][j + 1].FlyingTime);

						// transit = transit time - landing time of flight 1
						transit_time.sub_time(paths[i][j].LandingTime);
					}

					// save transit time in current node
					paths[i][j].Transit_Time = transit_time;
					// add transit time to total time 
					paths[i][0].Travel_Time.add_time(transit_time);

					// if transit hours > 12 
					// add hotel charges
					if (transit_time.get_hours() > 12)
					{
						// add hotel charges
						int index = 0;
						bool stop = false;
						for (int a = 0; a < NoOfCities && stop == false; a++)
						{
							if (array[a].head->Origin == paths[i][j].Origin)
							{
								stop = true;		index = a;
							}
						}
						paths[i][0].TicketPrice += hotel_charges[index];
					}

				}
			}
		}
	}





	// Print Paths Function
	// prints all the function
	void Print_Paths(Vector<Vector<Node>>& paths)
	{
		for (int i = 0; i < paths.getSize(); i++)
		{
			// if path is valid
			if (paths[i][0].p_check)
			{
				// print all nodes
				for (int j = 0; j < paths[i].getSize(); j++)
				{
					// if it is first node
					if (j == 0)
						cout << paths[i][j].Origin << " ";
					else
					{
						cout << "| ";
						cout << paths[i][j].DateOfTravel.to_str() << " "
							<< paths[i][j].FlyingTime.time_to_str() << " "
							<< paths[i][j].LandingTime.time_to_str() << " "
							<< paths[i][j].Transit_Time.time_to_str() << " "
							<< paths[i][j].Airline << "| "
							<< paths[i][j].Origin << " ";
					}
				}
				cout << endl;
				cout << "Total Cost: " << paths[i][0].TicketPrice << endl; // print total fare
				cout << "Total Time: " << paths[i][0].Travel_Time.time_to_str() << endl;	// print total time of flight
				cout << endl << endl;
			}
		}
	}





	// All Paths Function
	// This function add all the possible paths from source to the specified destination
	void All_Paths(Node* u, Node* d, bool visited[], Node path[], int& path_index, Vector<Vector<Node>>& paths)
	{
		// Getting the index of u ( source ) node in  Adjancy list
		int index1 = 0;
		bool stop1 = false;
		for (int a = 0; a < NoOfCities && stop1 == false; a++)
		{
			if (array[a].head->Origin == u->Origin)		// if found stop the for loop
			{
				stop1 = true;		index1 = a;
			}
		}

		// marking node as visited
		visited[index1] = true;
		// saving node in path
		path[path_index] = *u;
		// number of nodes in path updated
		path_index++;

		// if current node == destination node
		if (u->Origin == d->Origin)
		{

			bool time_check = true;			// if this variable is true then this path will be added into paths

			// check for each node the time and date of that node and the next node are correct
			for (int i = 0; i < path_index; i++)
			{
				// if node is not first or last node
				if (path[i].DateOfTravel.to_str() != "" && i + 1 < path_index)
				{
					// if date of flight of node 1 > date of flight of node 2
					// then path is not correct
					if (path[i].DateOfTravel.compare_date(path[i + 1].DateOfTravel) == 3)
						time_check = false;
					else
					{
						// check if date of flight of node 1 and date of flight of node 2 are on the same
						if (path[i].DateOfTravel.compare_date(path[i + 1].DateOfTravel) == 1)
						{
							// if flying time of node 1 > landing time of node 1
							// then path is not correct
							if (path[i].FlyingTime.check_time(path[i].LandingTime) == 3)
							{
								time_check = false;
							}
							// flying time of node 1 < landing time of node 1
							else
							{
								// if flying time of node 2 < landing time of node 1
								// then path is not correct
								if (path[i + 1].FlyingTime.check_time(path[i].LandingTime) == 2)
									time_check = false;
							}
						}

						// if date of flight of node 1    + 1  ==  date of flight of node 2
						if ((path[i].DateOfTravel.compare_date(path[i + 1].DateOfTravel, 1) == 1))
						{
							// if flying landing time > landing time
							if (path[i].FlyingTime.check_time(path[i].LandingTime) == 3)
								// if flying time of node 2 < landing time of node 1
								// then path is not correct
								if (path[i + 1].FlyingTime.check_time(path[i].LandingTime) == 2)
									time_check = false;
						}
					}
				}
			}
			// if time check == 1 then add path
			if (time_check == 1)
			{
				// add nodes to vector v
				Vector<Node> v;
				for (int i = 0; i < path_index; i++)
					v.push(path[i]);
				// v vector to paths
				paths.push(v);
				number++;
			}
		}
		// if node was not the destination node
		else
		{
			// temp points to head of linked list
			Node* temp = array[index1].head;
			// now temp points to its first child
			temp = temp->Destination;
			while (temp)
			{
				// check if node is visited
				int index2 = 0;
				bool stop2 = false;
				for (int a = 0; a < NoOfCities && stop2 == false; a++)
				{
					if (array[a].head->Origin == temp->Origin)		// if city was found end the loop and save value of i as index2
					{
						stop2 = true;		index2 = a;
					}
				}
				// if node was not visited insert it into queue
				if (visited[index2] == 0)
					All_Paths(temp, d, visited, path, path_index, paths);
				// temp points to next child of u
				temp = temp->Destination;
			}
		}
		// removing u node from path
		path_index--;
		// marking u as unvisited
		visited[index1] = false;
	}





	// Show Routes
	// Get all possible routes from souce to destination
	// and display them
	void Show_Routes(string origin, string destination, string date,
		bool transit_loc_b, string transit_loc,
		bool transit_hours_b, string min, string max,
		bool airline_b, string airline,
		bool direct_flight, int cost_or_time, bool again)
	{
		// if cost or time preference is not specified then take time as a preference
		if (cost_or_time == -1)
			cost_or_time = 2;

		// get all the paths
		Vector<Vector<Node>> paths = Get_Paths(origin, destination);
		// calculate thier total charges and time
		Total_Time_And_Charges(paths);
		// sort the paths according to time or cost
		Sort_Paths(paths, cost_or_time);
		// check if user date matched
		Check_Date(paths, date);

		// if transit location was specified
		if (transit_loc_b)
		{
			// check if transit location was found in paths
			Check_Transit_Location(paths, transit_loc);
			// if hours was specified then check paths with correct transit stay
			if (transit_hours_b)
				Check_Transit_Hours(paths, transit_loc, min, max);
		}

		// check paths for user airline preference if specified
		if (airline_b)
			Check_Airline(paths, airline);

		// check paths for direct flights if specified
		if (direct_flight)
			Check_Direct_Flights(paths);

		cout << endl;

		// displaying date
		cout << date << endl;

		// if number of paths found is 0
		if (Num_Paths(paths) == 0)
		{
			cout << "Sorry no Flights Avaliable on this date....";
			if (direct_flight != 1)
			{
				date[0] = date[0] - 1;
				// flights for previous day
				if (again && date[0] > 0)
					Show_Routes(origin, destination, date,
						transit_loc_b, transit_loc,
						transit_hours_b, min, max,
						airline_b, airline,
						direct_flight, cost_or_time, 0);

				// flights for next day
				date[0] = date[0] + 2;
				if (again && date[0] > 0)
					Show_Routes(origin, destination, date,
						transit_loc_b, transit_loc,
						transit_hours_b, min, max,
						airline_b, airline,
						direct_flight, cost_or_time, 0);
			}
			else
			{
				Show_Routes(origin, destination, date,
					transit_loc_b, transit_loc,
					transit_hours_b, min, max,
					airline_b, airline,
					0, cost_or_time, 0);
			}

		}
		else
			// print all the valid paths
			Print_Paths(paths);
	}





	// Check Transit Location
	// check for paths if they contain a specified transit location
	void Check_Transit_Location(Vector<Vector<Node>>& paths, string transit_loc)
	{
		for (int a = 0; a < paths.getSize(); a++)
		{
			bool transit_found = false;						// intially transit location found is set to 0
			for (int b = 0; b < paths[a].getSize(); b++)
			{
				if (b != 0 && b != paths[a].getSize() - 1)		// if node is not first node and not last node
				{
					if (paths[a][b].Origin == transit_loc)		// if transit location id found then set transit fount = 1
						transit_found = 1;
				}
			}
			if (transit_found == 0)		// if transit location was not found then path is not valid
				paths[a][0].p_check = 0;
		}
	}





	// Check Direct Flights
	// check paths for direct flights
	void Check_Direct_Flights(Vector<Vector<Node>>& paths)
	{
		for (int a = 0; a < paths.getSize(); a++)
		{
			if (paths[a].getSize() > 2)		// if path size is > 2 then path is not valid
				paths[a][0].p_check = 0;
		}
	}





	// Check Airline Function
	// check paths if they contain the spcified airline or not
	void Check_Airline(Vector<Vector<Node>>& paths, string airline)
	{
		for (int a = 0; a < paths.getSize(); a++)
		{
			bool airline_found = false;			// initally airline found set to 0
			for (int b = 0; b < paths[a].getSize(); b++)
			{
				if (b != 0)		// if node is not the first node
				{
					if (paths[a][b].Airline == airline)		// if airline found set airline found to 1
						airline_found = 1;
				}
			}
			// if airline found is zero path is not valid
			if (airline_found == 0)
				paths[a][0].p_check = 0;
		}
	}





	// Num Paths Function
	// turns the number of valid paths
	int Num_Paths(Vector<Vector<Node>>& paths)
	{
		int count = 0;
		for (int a = 0; a < paths.getSize(); a++)
		{
			if (paths[a][0].p_check)		// if path is valid, count = count + 1
				count++;
		}
		return count;
	}





	// Check Transit Hours Function
	// checks paths for correct transit stay
	void Check_Transit_Hours(Vector<Vector<Node>>& paths, string transit_loc, string min, string max)
	{
		for (int a = 0; a < paths.getSize(); a++)
		{
			bool transit_t = false;		// intiallially transit stay time is set to false
			for (int b = 0; b < paths[a].getSize(); b++)
			{
				// if node is not first and last nodes
				if (b != 0 && b != paths[a].getSize() - 1)
				{
					// if transit location was found
					if (paths[a][b].Origin == transit_loc)
					{
						Time temp1, temp2;
						temp1.set_time(min);	// minimun transit time
						temp2.set_time(max);	// maximum transit time
						// transit time >= min transit stay
						if (paths[a][b].Transit_Time.check_time(temp1) == 1 || paths[a][b].Transit_Time.check_time(temp1) == 3)
						{
							// max transit stay >= transit time
							if (temp2.check_time(paths[a][b].Transit_Time) == 1 || temp2.check_time(paths[a][b].Transit_Time) == 3)
								transit_t = 1;
						}
					}
				}
			}
			// if transit t == 0 not a valid path
			if (transit_t == 0)
				paths[a][0].p_check = 0;
		}
	}





	// Check Date
	// check paths for correct date
	void Check_Date(Vector<Vector<Node>>& paths, string date)
	{
		for (int a = 0; a < paths.getSize(); a++)
		{
			if (paths[a][1].DateOfTravel.to_str().compare(date) != 0)	// if dates were not equal not a valid path
				paths[a][0].p_check = 0;
		}
	}





	// Sort Path Function
	// sort paths according to travel time or price
	void Sort_Paths(Vector<Vector<Node>>& paths, int cost_or_travel)
	{
		for (int pass = 1; pass < paths.getSize(); pass++)
		{
			for (int i = 0; i < paths.getSize() - pass; i++)
			{
				// cost or travel == 1 , sort according to price
				if (cost_or_travel == 1)
				{
					// if cost of path 1 > cost of path 2
					if (paths[i][0].TicketPrice > paths[i + 1][0].TicketPrice)
					{
						// swap
						Vector<Node> temp;
						temp = paths[i];
						paths[i] = paths[i + 1];
						paths[i + 1] = temp;
					}
				}
				// cost or travel == 1 , sort according to travel time
				if (cost_or_travel == 2)
				{
					// if travel time of path 1 > travel time of path 2
					if (paths[i][0].Travel_Time.check_time(paths[i + 1][0].Travel_Time) == 3)
					{
						// swap
						Vector<Node> temp;
						temp = paths[i];
						paths[i] = paths[i + 1];
						paths[i + 1] = temp;
					}
				}
			}
		}
	}

};



#endif