//============================================================================
// Name        : ABCU Advising Program.cpp
// Author      : Michael Foster
// Version     : 1.0
// Description : CS 300 Project Two
//============================================================================

#include <iostream>
#include<vector>

using namespace std;

/*
	@brief Course is an object that holds a record of a course.
	@details Course object contains courseNumber, courseName, and prerequisites required to take the course.
*/
struct Course {
private:
	string courseNumber;
	string courseName;
	vector<string> preReqs;
public:
	/*
		@brief Set the course number for a course object.
		@param courseNumber A string to be stored as the course objects course number.
	*/
	void SetCourseNumber(string courseNumber) {
		this->courseNumber = courseNumber;
	}

	/*
		@brief Set the course name for a course object.
		@param courseName A string to be stored as the course objects course name.
	*/
	void SetCourseName(string courseName) {
		this->courseName = courseName;
	}

	/*
		@brief Set the prerequisite for a course object. Parameter passed is added to the course objects preReqs vector.
		@param courseNumber A string to be stored as the course objects course number.
	*/
	void SetPreReq(string courseName) {
		this->preReqs.push_back(courseName);
	}

	Course() {
		courseNumber = "unknown";
		courseName = "unknown";
	}
};

int main()
{
	bool exit = false;
	int userInput = 0;

	do
	{
		cout << "1. Load Data Structure." << endl;
		cout << "2. Print Course List." << endl;
		cout << "3. Print Course." << endl;
		cout << "9. Exit.\n" << endl;
		cout << "What would you like to do? ";
		cin >> userInput;

		switch (userInput) {
		case 1:
			// FIXME: Add Method to add data
			break;
		case 2:
			// FIXME: Add Method To Print Course List
			break;
		case 3:
			// FIXME: Add Method To Print Course
			break;
		case 9:
			exit = true;
			cout << "Thank you for using the course planner!" << endl;
			break;
		default:
			cout << userInput << " is not a valid option.\n" << endl;
		}

	} while (!exit);
}

