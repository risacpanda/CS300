/*phonebook.h
 * Phonebook header file
 *
 * April 28, 2017
 * 
 */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_
#include <iostream>
#include <fstream>
using namespace std;

//a struct for each contact to hold contact's name and phone number
template <class T>
struct contact
{
	T firstName;
	T lastName;
	T phoneNum;
	contact<T>* next;
};

template <class T>
class Phonebook
{
protected:
	contact<T>* head; //points to the front of the phonebook list
public:
	Phonebook();
	void readData(T&, T&, T&);
	void list();
	void insert(T&, T&, T&);
	void search(T&, T&);
	void remove(T&, T&);
	friend ostream& operator <<(ostream& os, Phonebook<T>& list);
	void destroylist();
	virtual ~Phonebook();
};

//constructor
template<class T>
Phonebook<T>::Phonebook()
{
	head = NULL;
}

//to read a text file and store contact information into the phonebook
template<class T>
void Phonebook<T>::readData(T& name, T& surname, T& phone)
{
	fstream in("phonebook-1.txt", ios::in);
	contact<T>* p = new contact<T>;
	p = head;
	while(in >> name >> surname >> phone)
	{
		insert(name, surname, phone);
	}
}

//lists the contacts
template <class T>
void Phonebook<T>::list()
{
	contact<T>* p = head;
    while (p!= NULL)
    {
		cout << p->firstName << " " << p->lastName <<" " << p->phoneNum <<endl;
		p = p->next;
	}
}

//to insert a new contact
template <class T>
void Phonebook<T>::insert(T& name, T& surname, T& phone)
{
	contact<T>* temp = new contact<T>;
	temp->firstName = name;
	temp->lastName = surname;
	temp->phoneNum = phone;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

//to search for a contact
template <class T>
void Phonebook<T>::search(T& name, T& surname)
{
	contact<T>* p;
	p = head;
	while (p != NULL && p->firstName != name && p->lastName != surname)
	{
		p = p-> next;
	}
	if (p!=NULL)
	{
		cout << "Phone Number: " << p->phoneNum << endl;
	}
	if (p == NULL)
	{
		cout << "Not Found" << endl;
	}
}

//to remove a contact
template <class T>
void Phonebook<T>::remove(T& name, T& surname)
{
	contact<T>*p, *q;
	//empty list
	if (head == NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		//first contact or only contact
		if(head-> firstName == name & head->lastName == surname)
		{
			p  = head;
			head = head->next;
			delete p;
		}
		else
		{
			p = head;
			q = head->next;
			//traversing the list
			while(q!=NULL && q->firstName != name && q->lastName != surname)
			{
				p = q;
				q = q->next;
			}
			//reached end of list with no contact found
			if (q == NULL)
			{
				cout <<"Contact not found"<<endl;
			}
			//delete contact
			else
			{
				p->next = q->next;
				delete q;
			}
		}
	}
}

template <class T>
ostream& operator << (ostream& os, Phonebook<T>& list)
{
	contact<T>* temp = list.head;
	while (temp != NULL)
	{
		os << temp->firstName << " " << temp-> lastName << " " << temp-> phoneNum <<" ";
		temp = temp -> next;
	}
	return os;
}

template <class T>
void Phonebook<T>::destroylist(){
	contact<T>* p;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

//destructor
template <class T>
Phonebook<T>::~Phonebook()
{
	destroylist();
}

#endif /* PHONEBOOK_H_*/

