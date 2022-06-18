#include"Student.h"
int main(int argc, char* argv[]) {
	student* listOfStudents;
	int currSize, maxSize;
	ifstream thefile(argv[1], ios::binary | ios::ate);
	if (thefile.is_open()) {
		int nbytes = thefile.tellg();
		currSize = nbytes / sizeof(student);
		maxSize = currSize + 5;
		listOfStudents = new student[maxSize];
		thefile.seekg(0, ios::beg);
		thefile.read((char*)listOfStudents, nbytes);
		thefile.close();
	}
	else {
		currSize = 0;
		maxSize = currSize + 5;
		listOfStudents = new student[maxSize];
		ofstream thefile(argv[1], ios::binary);
		thefile.close();
	}
	cout << "\tS T U D E N T \t D A T A" << endl;
	systemMenu(argv[1], listOfStudents, currSize); //we pass the name of file taken as a command line argument to this function so that all the functions called inside this function can use it and evaluate it in their own way wether to open in read or write, app, truncate or in or out mode
	return 0;
}
