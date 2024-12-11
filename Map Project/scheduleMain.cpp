#include "schedule.h"



int main()
{
	ifstream scheduleFile("STEM - Summer 2022 Schedule of Classes as of 05-02-22-2.csv");
	schedule test;
	string subject;
	string catalog;
	string lastName;
	test.initSchedule(&scheduleFile);
	//test.print();
	//test.findByInstructor("Cruz");
	//test.findBySubject("MTH");
	//test.findBySubjectCatalog("MTH", "154");
	int a = 0;
	do {
		cout << endl
			<< "1: Print the whole catalog" << endl
			<< "2. Find courses by the subject" << endl
			<< "3. Find courses by the subject and catalog number" << endl
			<< "4. Find courses by Instructor's last name" << endl
			<< "5. Quit" << endl;
		cin >> a;
		switch (a)
		{
		case 1: //Print the whole catalog
			test.print();
			break;
		case 2: //print by subject
			cout << "What is the subject? ";
			getline(cin >> ws, subject);
			//cin >> subject;
			test.findBySubject(subject);
			break;
		case 3: //print by subject and catalog number
			cout << "What is the subject? ";
			getline(cin >> ws, subject);
			//cin >> subject;
			cout << "What is the catalog number? ";
			getline(cin >> ws, catalog);
			//cin >> catalog;
			test.findBySubjectCatalog(subject, catalog);
			break;
		case 4: //print by last name
			cout << "What is the instructor's last name? ";
			getline(cin >> ws, lastName);
			//cin >> lastName;
			test.findByInstructor(lastName);
			break;
		case 5: //quit
			exit(0);
		default: 
			cout << "Invalid Choice";
		}
	} while (a != 5);
}

