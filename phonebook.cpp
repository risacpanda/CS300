/*Phonebook source file
 *
 * This program reads a text file and stores contact information from the file into
 * a linked list. The user can then add, search, delete, or list contacts to or from the
 * phonebook.
 *
 * April 28, 2017
 * 
 */

#include <fstream>
#include <iostream>
#include "phonebook.h"
using namespace std;

 int main()
 {
 	Phonebook<string> mylist;
 	string name;
 	string surname;
 	string phone;

 	//read in data from text file into the phonebook
 	mylist.readData(name, surname, phone);
    cout<<"***MY PHONEBOOK APPLICATION***"<<endl;
 	cout<<"Please choose an operation:";
 	cout << "A(ADD) | S(Search) |D(Delete) |L(List) |Q(Quit): " << endl;
 	char userInput;
 	cin >> userInput;

 	//keep prompting user for operations until the user has chosen to quit
 	while (userInput != 'Q')
 	{
 		//add a new contact
 		if (userInput =='A')
 		{
 			cout << "Enter first name: "<< endl;
 			cin >> name;
 			cout << "Enter last name: "<< endl;
 			cin >> surname;
 			cout << "Enter phone: "<<endl;
 			cin >> phone;
 			mylist.insert(name, surname, phone);
 		}

 		//search for a contact, return phone number
 		else if (userInput =='S')
 		{
 			cout<< "Enter first name: " << endl;
 			cin >> name;
 			cout << "Enter last name: " << endl;
 			cin >> surname;
 			mylist.search(name, surname);
 		}

 		//list all contacts
 		else if (userInput =='L')
 		{
 			mylist.list();
 		}

 		//Delete an existing contact
 		else if (userInput =='D')
 		{
 			cout <<"Enter first name: " << endl;
 			cin >> name;
 			cout <<"Enter last name: " << endl;
 			cin >> surname;
 			mylist.remove(name, surname);
 		}

 		//prompt user again
 		cout << "A(ADD) | S(Search) |D(Delete) |L(List) |Q(Quit): " << endl;
 		cin  >> userInput;
 	}
 	return 0;
}

