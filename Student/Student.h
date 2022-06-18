#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class student
{
	char *name;			//////////////////////////////
	int rollNo;				//////////////////////////////
	double cgpa;			////ATTRIBUTES//OF//STUDENT///
	int semester;			//////////////////////////////
	int age;				//////////////////////////////
public:
	student();
	student(const char* n, int r, double cgpa, int s, int a);
	~student();
	void setName(const char* n);
	void setRollNo(int r);
	void setCGPA(double cgpa);
	void setSemester(int s);
	void setAge(int a);
	char* getName() const;
	int getRollNo() const;
	double getCGPA() const;
	int getSemester() const;
	int getAge() const;
};
void addStudent(student listOfStudents[], int& currSize);
void searchStudent(student listOfStudents[], int& currSize);
void updateStudent(student listOfStudents[], int& currSize);
void deleteStudent(student listOfStudents[], int& currSize);
void displayStudent(student s);
void displayFile(student listOfStudents[], int& currSize);
void systemMenu(string filename, student listOfStudents[], int& currSize);
