//
// Created by prog2100 on 05/11/17.
//

#ifndef COURSES_STUDENT_H
#define COURSES_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {

    friend ostream& operator<< (ostream& os, const Student& stu);
private:
    string name;
    int numCourses;
    string* courseList;

public:
    //default constructor
    Student(string name = "Stue", int numCourses = 1);
    //copy constructor
    Student(const Student& source);
    //Overloaded assignment
    Student& operator= (const Student& source);
    //deconstructor
    ~Student();
    //a function to add courses to a students @courseList
    void addCourses();
    //a function to clear a students @numCourses, @courseList
    void clearCourses();
    //get a student name
    string getNameInput();

    //getters and setters
    const string &getName() const;
    void setName(const string &name);
    int getNumCourses() const;
    void setNumCourses(int numCourses);
    string *getCourseList() const;

};



#endif //COURSES_STUDENT_H
