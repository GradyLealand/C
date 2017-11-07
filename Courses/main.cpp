
#include "Student.h"
#include <iostream>

using namespace std;

int main()
{
    //create a studnet
    Student stu1;
    stu1.setName(stu1.getNameInput());
    stu1.addCourses();

    //clear cin for second entry
    cin.clear();
    cin.ignore();

    //display the first students information
    cout << "\nStudnet 1's information: " << endl << stu1 << endl;

    //copy studnet one into student two
    Student stu2 = stu1;//this is a deep copy
    cout << "Please enter the name of a second studnet: " << endl;
    stu2.setName(stu2.getNameInput());

    //clear the first student
    stu1.clearCourses();
    cout<<"\nThe results of Student one after it has been cleared are: " <<endl;
    cout << stu1 << endl;

    //proves that student 2 was a deep copy becuase its array is populated and student ones is not
    cout << "Studnet 2's information: " << endl;
    cout << stu2 << endl;

    //make a third student and show his information
    Student stu3;
    stu3.setName(stu3.getNameInput());
    stu3.addCourses();
    cout << "Student 3's information: " << endl;
    cout << stu3 << endl;

    //use the overlaoaded assignment operator to make him the same as student 2
    stu3 = stu2;
    cout << "\n used overloaded assignment operator to set student three to student one:" << endl;
    cout << stu3 << endl;

    return 0;
}