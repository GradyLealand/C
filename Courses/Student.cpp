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
    numCourses = 2;
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
//Student& operator= (const Student &source)
//{
//    if (&source != this)
//    {
//        numCourses = source.numCourses;
//        name = source.name;
//        courseList = source.courseList;
//        copy(source.courseList, source.courseList + numCourses, courseList);
//    }
//    return *this;
//}

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
