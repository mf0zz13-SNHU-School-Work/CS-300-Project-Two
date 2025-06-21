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

	string GetCourseNumber() {
		return courseNumber;
	}

	string PrintCourseNumber() {
		cout << courseNumber;
	}

	string PrintCourseName() {
		cout << courseName;
	}

	vector<string> PrintPreReqs() {
		int size = preReqs.size();

		for (int i = 0; i < size; i++) {
			cout << preReqs[i];
			if (i != size - 1)
				cout << ", ";
		}
	}

	Course() {
		courseNumber = "unknown";
		courseName = "unknown";
	}
};

class BST {
private:
	struct Node {
		Course course;
		Node* left;
		Node* right;

		Node() {
			left = nullptr;
			right = nullptr;
		}

		Node(Course course) : Node() {
			this->course = course;
		}
	};

	Node* root;

	Node* addNode(Node* node, Course course);
	void inOrder(Node* node);
	void search(Node* node, string courseNumber);

public:
	BST();
	void Add(Course course);
	void PrintList();
	void Search(string courseNumber);
};

BST::Node* BST::addNode(Node* node, Course course) {

	if (node == nullptr)
		return new Node(course);
	
	if (course.GetCourseNumber().compare(node->course.GetCourseNumber()) < 0)
		node->left = addNode(node->left, course);
	else
		node->right = addNode(node->right, course);

	return node;
}

void BST::inOrder(Node* node) {
	if (node == nullptr)
		return;
	inOrder(node->left);

	Course course = node->course;
	course.PrintCourseNumber();
	cout << ", ";
	course.PrintCourseName();
	cout << endl;

	inOrder(node->right);
}

void BST::search(Node* node, string courseNumber) {
	if (node == nullptr)
		return;

	Course course = node->course;

	if (course.GetCourseNumber() == courseNumber) {
		course.PrintCourseNumber();
		cout << ", ";
		course.PrintCourseName();
		cout << "\nPrerequisites: ";
		course.PrintPreReqs();
		cout << endl;
	}
	else if (courseNumber.compare(course.GetCourseNumber()) < 0)
		search(node->left, courseNumber);
	else
		search(node->right, courseNumber);
}

BST::BST() {
	root = nullptr;
}

void BST::Add(Course course) {
	if (root == nullptr) {
		root = new Node(course);
		return;
	}

	addNode(root, course);
}

void BST::PrintList() {
	inOrder(root);
}

void BST::Search(string courseNumber) {
	search(root, courseNumber);
}



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

