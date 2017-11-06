//
// Created by prog2100 on 05/11/17.
//

#include "Student.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>

using namespace std;
//default constructor
Student::Student()
{
    name = "Tim";
    numCourses = 0;
    courseList = new string[numCourses];
}

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

    name = source.name;
    numCourses = source.numCourses;
    courseList = new string[numCourses];

    copy(source.courseList, source.courseList + numCourses, courseList);

    for(int i = 0; i < source.numCourses; ++i){
        courseList[i] = source.courseList[i];
    }
}

//overloaded assignment operator
Student&::Student::operator= (const Student& source)
{
    cout << "Overloaded Assignment called" << endl;

    //check for self assignment IE gc1 = gc1
    if(this == &source)
    {
        return *this;
    }

    name = source.name;
    numCourses= source.numCourses;

    copy(source.courseList, source.courseList + numCourses, courseList);

    return *this;
}

//deconstructor
Student::~Student()
{
    delete[] courseList;
}

//insert statment
void Student::insert(const string &courseName)
{
    courseList[numCourses] = courseName;
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
    int count = 0;
    while (true) {
        cout << "Enter a course (exit to stop entering): ";
        cin >> courseList[count];
        if (courseList[count] != "exit") {
            count++;

            if (count >= numCourses) {
                numCourses++;
                string *tempArray = new string[numCourses];

                for (int i = 0; i < count; i++) {
                    tempArray[i] = courseList[i];
                }

                delete[] courseList;
                courseList = tempArray;
                continue;
            }
        }else{
            break;
        }
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

void Student::setCourseList(string *courseList) {
    Student::courseList = courseList;
}

