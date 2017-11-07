//
// Created by prog2100 on 05/11/17.
//

#include "Student.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <regex>

using namespace std;

//constructor
Student::Student(string inName, int inCNum)
{
    name = inName;
    numCourses = inCNum;
    courseList = new string[inCNum];
}

//copy constructor
Student::Student(const Student& source)
{
    cout << "Copy Constructor called." << endl;

    //copy  object values to new object
    name = source.name;
    numCourses = source.numCourses;
    //deep copy
    courseList = new string[source.numCourses];

    //copy each item in the array
    for(int i = 0; i < source.numCourses; ++i){
        courseList[i] = source.courseList[i];
    }
}

//overloaded assignment operator
Student&::Student::operator= (const Student& source)
{
    cout << "Overloaded Assignment called" << endl;

    //check for self assignment
    if(this == &source)
    {
        return *this;
    }

    //copy  object values to new object
    name = source.name;
    numCourses= source.numCourses;
    courseList = new string[source.numCourses];

    //copy each item in the array
    for(int i = 0; i < source.numCourses; ++i){
        courseList[i] = source.courseList[i];
    }

    return *this;
}




// overloaded output operator
ostream& operator<< (ostream& os, const Student& stu)
{
    os << "Student: " << stu.name <<" is enroled in the following courses:" << endl << "| ";

    for (int i = 0; i < stu.numCourses; ++i)
    {
        os << stu.courseList[i] + " | ";
    }

    return  os << endl;
}

//add courses
void Student::addCourses()
{
    int count = 0; //start entering at index 0


    while (true) {
        string input;
        cout << "Enter a course (end to stop entering): ";
        cin >> input;//get a course name
        if (input != "end") //if not exit
        {
            courseList[count] = input;
            count++;

            if (count >= numCourses) {
                //make an array that is one larger then the current array
                auto *tempArray = new string[numCourses + 1];
                numCourses++;

                for (int i = 0; i < count; i++) {
                    //populate the new array with the objects formt eh old array
                    tempArray[i] = courseList[i];
                }
                //delete the original array
                delete[] courseList;
                // copy the new array into the students array
                courseList = tempArray;
                continue;
            }

        }
        else//if the user enters exit then stop adding to the array
        {
            break;
        }

    }
}



//get the studnets name formt he user
string Student::getNameInput()
{
    string nameIn;

    //regext to make sure the name is only letters
    regex exp("^[A-z]+$");

    //ask for a name, check it, then return the input
    cout << "Enter studnets name: ";
    do
    {
        cin >> nameIn;

        if(!(regex_match(nameIn, exp)))
        {
            cout <<"Enter a valid name: ";
            cin.clear(); // empty cin
            cin.ignore();
        }
    }while (!(regex_match(nameIn, exp)));

    return nameIn;
}

//reset student properties
void Student::clearCourses()
{
    numCourses = 0;
    memset(courseList, 0, sizeof(courseList));
}

//destructor
Student::~Student()
{
    cout << "Distructor Called for " << this->name << endl;
    if(courseList != nullptr){
        //delete buffered array
        delete[] courseList;
        //set the list to a null pointer
        courseList = nullptr;
    }

}

//----Getters & Setters----
const string &Student::getName() const {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

int Student::getNumCourses() const {
    return numCourses;
}

void Student::setNumCourses(int numCourses) {
    Student::numCourses = numCourses;
}

string *Student::getCourseList() const {
    return courseList;
}


