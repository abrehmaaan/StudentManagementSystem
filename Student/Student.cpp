#include"Student.h"
student::student() {
	name = nullptr;
}
student::student(const char* n, int r, double cgpa, int s, int a) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	rollNo = r;
	cgpa = cgpa;
	semester = s;
	age = a;
}
student::~student() {
	delete[]name;
}
void student::setName(const char* n) {
	delete[]name;
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}
void student::setRollNo(int r) {
	rollNo = r;
}
void student::setCGPA(double cgpa){
	cgpa = cgpa;
}
void student::setSemester(int s) {
	semester = s;
}
void student::setAge(int a) {
	age = a;
}
char* student::getName() const {
	return name;
}
int student::getRollNo() const {
	return rollNo;
}
double student::getCGPA() const {
	return cgpa;
}
int student::getSemester() const {
	return semester;
}
int student::getAge() const {
	return age;
}
void systemMenu(string filename, student listOfStudents[], int& currSize) {
	char choice;
	while (1) {

		cout << endl << "\tF U N C T I O N S \t M E N U :" << endl << endl;
		cout << "\t[A] : Add  a new Student" << endl;
		cout << "\t[S] : Search a Student" << endl;
		cout << "\t[U] : Update a Student" << endl;
		cout << "\t[D] : Delete a Student" << endl;
		cout << "\t[L] : Display all Students" << endl;
		cout << "\t[Q] : Exit" << endl;
		cout << endl << "Please enter a relevant character: ";
		cin >> choice;
		switch (choice)
		{
		case 'A':
		case'a':addStudent(listOfStudents, currSize); break;

		case'S':
		case's':searchStudent(listOfStudents, currSize); break;

		case'U':
		case'u':updateStudent(listOfStudents, currSize); break;

		case'D':
		case'd':deleteStudent(listOfStudents, currSize); break;

		case'L':
		case'l':displayFile(listOfStudents, currSize); break;

		case'Q':
		case'q': {
			ofstream thefile(filename, ios::binary);
			if (thefile.is_open()) {
				for (int i = 0; i < currSize; i++) {
					thefile.write((const char*)&listOfStudents[i], sizeof(student));
				}
				thefile.close();
				delete[]listOfStudents;
			}
			exit(0);
		}
			   break;

		default:cout << endl << "PLEASE ENTER THE CORRECT OPTION [A/S/U/D/F/Q]" << endl << endl; break;

		}
	}
}

void addStudent(student listOfStudents[], int& currSize) {

	cout << endl;
	char name[50];
	int rollNo, age, semester;
	double cgpa;
	cout << "Enter Student Name: ";
	cin.ignore(30, '\n');
	cin.getline(name, 30);
	cout << "Enter Roll No: ";
	cin >> rollNo;
	cout << "Enter Age: ";
	cin >> age;
	cout << "Enter CGPA: ";
	cin >> cgpa;
	cout << "Enter Semester: ";
	cin >> semester;
	student s(name, rollNo, cgpa, semester, age);
	listOfStudents[currSize++] = s;
	cout << endl << "Record Entered!" << endl;
	displayStudent(listOfStudents[currSize - 1]);
}

void searchStudent(student listOfStudents[], int& currSize) {
	cout << endl;
	int rollNo;
	cout << "Enter the roll number of Student you want to search: ";
	cin >> rollNo;
	int i = 0;
	for (i = 0; i < currSize; i++) {
		if (listOfStudents[i].getRollNo() == rollNo) {
			cout << endl << "Record Found:";
			displayStudent(listOfStudents[i]);
		}
	}
	if (i == 0) {
		cout << endl << "Sorry! No such record found!" << endl;
	}
}


void displayStudent(const student s) {
	cout << endl;
	cout << "\tName: " << s.getName() << endl;
	cout << "\tRoll No: " << s.getRollNo() << endl;
	cout << "\tAge:	" << s.getAge() << endl;
	cout << "\tSemester: " << s.getSemester() << endl;
	cout << "\tCGPA: " << s.getCGPA() << endl;
}

void updateStudent(student listOfStudents[], int& currSize) {
	cout << endl;
	char name[50];
	int rollNo, age, semester;
	double cgpa;
	cout << "Enter the roll number of Student you want to update: ";
	cin >> rollNo;
	int i = 0;
	for (i = 0; i < currSize; i++) {
		if (listOfStudents[i].getRollNo() == rollNo) {
			cout << endl << "Old Details";
			displayStudent(listOfStudents[i]);
			cout << endl << "Enter New Details";
			cout << "Enter Student Name: ";
			cin.ignore(30, '\n');
			cin.getline(name, 30);
			cout << "Enter Roll No: ";
			cin >> rollNo;
			cout << "Enter Age: ";
			cin >> age;
			cout << "Enter CGPA: ";
			cin >> cgpa;
			cout << "Enter Semester: ";
			cin >> semester;
			listOfStudents[i].setName(name);
			listOfStudents[i].setRollNo(rollNo);
			listOfStudents[i].setAge(age);
			listOfStudents[i].setCGPA(cgpa);
			listOfStudents[i].setSemester(semester);
			cout << endl << "Record Updated!" << endl;
			displayStudent(listOfStudents[i]);
		}
	}
	if (i == 0) {
		cout << endl << "Sorry! No such record found!" << endl;
	}
}

void deleteStudent(student listOfStudents[], int& currSize) {
	cout << endl;
	int rollNo;
	cout << "Enter the roll number of Student you want to delete: ";
	cin >> rollNo;
	int i = 0;
	for (i = 0; i < currSize; i++) {
		if (listOfStudents[i].getRollNo() == rollNo) {
			cout << endl << "Student Found!";
			displayStudent(listOfStudents[i]);
			int loc = i;
			for (int j = loc; j < currSize; j++)
			{
				listOfStudents[j] = listOfStudents[j + 1];
			}
			currSize--;
			cout << endl << "Record Deleted!" << endl;
		}
	}
	if (i == 0) {
		cout << endl << "Sorry! No such record found!" << endl;
	}
}

void displayFile(student listOfStudents[], int& currSize) {
	cout << endl;
	for (int i = 0; i < currSize; i++) {
		displayStudent(listOfStudents[i]);
	}
}
