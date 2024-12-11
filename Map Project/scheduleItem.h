#pragma once
#ifndef H_scheduleItem 
#define H_scheduleItem

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <iterator>
#include <utility>


using namespace std;

class scheduleItem
{
public:
	bool operator==(const scheduleItem);
	bool operator!=(const scheduleItem);
	bool operator>=(const scheduleItem);



	// Reads in lines from csv file
	// Calls addEntry

	void addEntry();
	// Stores csv line in the Map
	// 

	string getSubject();

	string getCatalog();

	string getSection();

	string getComponent();

	string getSession();

	int getUnits();

	int getTotEnrl();

	int getCapEnrl();

	string getInstructor();

	

	//Override !=

	//Override >=

	void print();

	scheduleItem()
	{
		//Constructor
		subject = "";
		catalog = "";
		section = "";
		component = "";
		session = "";
		units = 0;
		totEnrl = 0;
		capEnrl = 0;
		instructor = "";
		key = "";
	}


	string subject;
	string catalog;
	string section;
	string component;
	string session;
	int units;
	int totEnrl;
	int capEnrl;
	string instructor;
	string key;

private:

};

bool scheduleItem::operator==(const scheduleItem item)
{
	if (key == item.key) { return true; };
}

bool scheduleItem::operator!=(const scheduleItem item)
{
	if (key != item.key) { return true; };
}

bool scheduleItem::operator>=(const scheduleItem item)
{
	if (key >= item.key) { return true; };
}

#endif
