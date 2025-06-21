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

	/*
		@brief Returns the string course number.
	*/
	string GetCourseNumber() {
		return courseNumber;
	}

	/*
		@brief Prints the course number.
	*/
	void PrintCourseNumber() {
		cout << courseNumber;
	}

	/*
		@brief Prints the course name.
	*/
	void PrintCourseName() {
		cout << courseName;
	}

	/*
		@brief Prints a list of the prerequisites.
	*/
	void PrintPreReqs() {
		int size = preReqs.size();

		for (int i = 0; i < size; i++) {
			cout << preReqs[i];
			if (i != size - 1) // If the preReq is not the last one a comma is printed
				cout << ", ";
		}
	}

	// Default constructor
	Course() {
		courseNumber = "unknown";
		courseName = "unknown";
	}
};

class BST {
private:
	/*
		@brief Node is an object that stores a course object and a left and right pointer reference.
	*/
	struct Node {
		Course course;
		Node* left;
		Node* right;

		// Default constructor
		Node() {
			left = nullptr;
			right = nullptr;
		}

		// Overloaded constructor adding course to Node
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

/*
	@brief Adds Node to BST using standard ordering procedure for BST
	@param node should be root of tree so that the new course will be added in the correct spot on the tree
	@param course is the Course object to be added to the tree.
*/
BST::Node* BST::addNode(Node* node, Course course) {

	if (node == nullptr) // If the node is null then a new node is added to tree in current place
		return new Node(course);
	
	// If course number is smaller than the current nodes course number traversal is to the left otherwise to the right
	if (course.GetCourseNumber().compare(node->course.GetCourseNumber()) < 0)
		node->left = addNode(node->left, course);
	else
		node->right = addNode(node->right, course);

	return node;
}

/*
	@brief Prints all courses in the tree using in order traversal.
	@param node should be root of tree so all nodes will be printed.
*/
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

/*
	@brief Searches Course objects to find a matching course number, if found course details will be printed.
	@param node should be root of tree so a correct check of nodes is conducted.
	@param courseNumber is the Course to be searched
*/
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

// Default constructor
BST::BST() {
	root = nullptr;
}

/*
	@brief Adds Course to BST
	@param course is the Course object to be added.
*/
void BST::Add(Course course) {
	if (root == nullptr) {
		root = new Node(course);
		return;
	}

	addNode(root, course);
}

/*
	@brief Prints a list of all courses.
*/
void BST::PrintList() {
	inOrder(root);
}

/*
	@brief Searches for course with matching course number, if found courses details will be printed.
	@param courseNumber is the field that will be searched.
*/
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

