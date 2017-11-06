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
    Student();
    //constructor
    Student(string, int);
    //copy constructor
    Student(const Student& source);
    //Overloaded assignment
    Student& operator= (const Student &source);
    //deconstructor
    ~Student();
    //add a course
    void insert(const string& courseName);
    void addCourses();

    //getters and setters
    const string &getName() const;

    void setName(const string &name);

    int getNumCourses() const;

    void setNumCourses(int numCourses);

    string *getCourseList() const;

    void setCourseList(string *courseList);

};



#endif //COURSES_STUDENT_H
