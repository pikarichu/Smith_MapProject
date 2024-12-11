#pragma once

#ifndef H_schedule 
#define H_schedule

#include "scheduleItem.h"
#include <sstream>
#include <fstream>
#include <map>
#include <iterator>
#include <utility>
#include <typeinfo>
#include <string>

using namespace std;

class schedule : public scheduleItem
{
public:
	void initSchedule(ifstream* file)
	{
		//ifstream scheduleFile("STEM - Summer 2022 Schedule of Classes as of 05-02-22.csv");
		string line;
		string itemValue;

		if (file->is_open())
		{
			getline(*file, line); // Throw away the Header line
			while (getline(*file, line)) // Then step through the CSV, line by line
			{

				//do stuff
				stringstream strStr(line);
				int count = 0; // count == CSV column
				while (getline(strStr, itemValue, ';') && count < 11) // Only items from the first 11 columns
				{
					if (count == 0)
					{
						subject = itemValue;
						cout << "subject: " << subject << endl;
					}
					else if (count == 1)
					{
						catalog = itemValue;
						cout << "catalog: " << catalog << endl;
					}
					else if (count == 2)
					{
						section = itemValue;
						cout << "section: " << section << endl;
					}
					else if (count == 3)
					{
						component = itemValue;
						cout << "component: " << component << endl;
					}
					else if (count == 4)
					{
						session = itemValue;
						cout << "session: " << session << endl;
					}
					else if (count == 6)
					{
						//cout << typeid(units).name() << endl;
						units = stoi(itemValue);
						cout << "units: " << units << endl;
					}
					else if (count == 7)
					{
						totEnrl = stoi(itemValue);
						cout << "totEnrl: " << totEnrl << endl;
					}
					else if (count == 8)
					{
						capEnrl = stoi(itemValue);
						cout << "capEnrl: " << capEnrl << endl;
					}
					else if (count == 10)
					{
						instructor = itemValue;
						cout << "instructor: " << instructor << endl;
					}
					else
					{
						if (count != 5 && count != 9)
						{
							break;

						}
					}

					count++;
				}
				key = (subject + "_" + catalog + "_" + section);
				myMap[key] = *this;

				cout << endl;

			}
		}
		else
		{
			cout << "Unable to open file!" << endl;
		}
		file->close();
	}

	void print()
	{
		map<string, scheduleItem>::iterator iter = myMap.begin();
		cout << "Subject\t\tCatalog\tSection\tComponent\tSession\t\tUnits\ttotEnrl\tcapEnrl\tInstructor" << endl;

		while (iter != myMap.end())
		{
			//cout << iter->first << endl;
			cout << iter->second.subject << "\t\t";
			cout << iter->second.catalog << "  \t";
			cout << iter->second.section << "\t";
			cout << iter->second.component << "\t\t";
			cout << iter->second.session << "\t\t";
			cout << iter->second.units << "\t";
			cout << iter->second.totEnrl << "\t";
			cout << iter->second.capEnrl << "\t";
			cout << iter->second.instructor << endl;


			++iter;
		}
	}

	void findBySubject(string sub)
	{
		map<string, scheduleItem>::iterator iter = myMap.begin();
		cout << "Subject\t\tCatalog\tSection\tComponent\tSession\t\tUnits\ttotEnrl\tcapEnrl\tInstructor" << endl;
		while (iter != myMap.end())
		{
			if (sub == iter->second.subject)
			{
				cout << iter->second.subject << "\t\t";
				cout << iter->second.catalog << "  \t";
				cout << iter->second.section << "\t";
				cout << iter->second.component << "\t\t";
				cout << iter->second.session << "\t\t";
				cout << iter->second.units << "\t";
				cout << iter->second.totEnrl << "\t";
				cout << iter->second.capEnrl << "\t";
				cout << iter->second.instructor << endl;
			}
			iter++;
		}
	}

	void findBySubjectCatalog(string sub, string cat)
	{
		map<string, scheduleItem>::iterator iter = myMap.begin();
		cout << "Subject\t\tCatalog\tSection\tComponent\tSession\t\tUnits\ttotEnrl\tcapEnrl\tInstructor" << endl;
		while (iter != myMap.end())
		{
			if (sub == iter->second.subject && cat == iter->second.catalog)
			{
				cout << iter->second.subject << "\t\t";
				cout << iter->second.catalog << "  \t";
				cout << iter->second.section << "\t";
				cout << iter->second.component << "\t\t";
				cout << iter->second.session << "\t\t";
				cout << iter->second.units << "\t";
				cout << iter->second.totEnrl << "\t";
				cout << iter->second.capEnrl << "\t";
				cout << iter->second.instructor << endl;
			}
			iter++;
		}
	}

	void findByInstructor(string instructorLast)
	{
		map<string, scheduleItem>::iterator iter = myMap.begin();
		cout << "Subject\t\tCatalog\tSection\tComponent\tSession\t\tUnits\ttotEnrl\tcapEnrl\tInstructor" << endl;
		while (iter != myMap.end())
		{
			size_t comma = iter->second.instructor.find(',');
			string last = iter->second.instructor.substr(0, comma);
			//cout << "Last: " << last << endl;
			if (last == instructorLast)
			{
				cout << iter->second.subject << "\t\t";
				cout << iter->second.catalog << "  \t";
				cout << iter->second.section << "\t";
				cout << iter->second.component << "\t\t";
				cout << iter->second.session << "\t\t";
				cout << iter->second.units << "\t";
				cout << iter->second.totEnrl << "\t";
				cout << iter->second.capEnrl << "\t";
				cout << iter->second.instructor << endl;
			}
			iter++;
		}
	}

	schedule() 
	{

	};

private:
	string key;
	map<string, scheduleItem> myMap;

};

#endif;