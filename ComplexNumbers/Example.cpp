#include <iostream>
#include <sstream>
#include <conio.h>
using namespace std;

class ComplexNumber
{
private:
	double real;
	double imaginary;

public:
	ComplexNumber()//default
		:real(), imaginary(){}
	ComplexNumber(double real, double imaginary)//const with args
		:real(real), imaginary(imaginary){}
	ComplexNumber(string s)//const with arg for string like "a+bi"
	{
		//parse routine goes here
		this->real = 3; //hard coded stub for testing
		this->imaginary = 8; //hard coded stub for testing
	}

	ComplexNumber operator+ (ComplexNumber &rightObj)
	{
		return ComplexNumber(this->real + rightObj.real,
			this->imaginary + rightObj.imaginary);
	}
	//code other operators here

	void print()// dont do it this way - dirty ie touches the UI
	{
		cout << this->real << " + " << this->imaginary << "i";
		_getch();
	}

	string toString()//clean
	{
		stringstream strStream;
		string x, y;
		//next 5 lines used to do conversions for double to str
		strStream << this->real;//place prop in stream
		strStream >> x;//rec it back converted to a string
		strStream.clear();
		strStream << this->imaginary;
		strStream >> y;

		//return a string representing the 
		//current value of this obj in a+bi format
		return (x + "+" + y + "i");

	}//end toString

	friend void operator>> (istream &input, ComplexNumber &num);
	friend ostream& operator<<(ostream &output, ComplexNumber &num);

};//end class ComplexNumber

//implementation of friend function

void operator>> (istream &input, ComplexNumber &num)
{
	string str;
	getline(input, str);//assign input to string var
	num = ComplexNumber(str);//call to string constructor for "a+bi"
}

ostream& operator<<(ostream &output, ComplexNumber &num)
{
	output << num.real << " + " << num.imaginary << "i";
	return output; //returns an ostream obj
}

int main()
{
	////test default constructor, dirty print, tostring
	//ComplexNumber cn;//instances a CN using default constructor
	//cn.print();
	//cout << cn.toString() << endl;//use of toString
	//_getch();

	cout << "Press any key to begin ComplexNumber testing" <<endl;
	_getch();
	ComplexNumber cn;//default constructor
	cout << cn << endl;//use of << override
	_getch();

	//test of the + operator
	cout << "Test of + operator and toString method" << endl;
	ComplexNumber cn1(8, 8);//instanced using const with args
	ComplexNumber cn2(2, 2);
	ComplexNumber cn3 = cn1 + cn2;
	cout << cn1.toString() << " + " << cn2.toString() << " = " << cn3.toString() << endl;
	_getch();

	//test of string constructor (note: stubs in place)
	ComplexNumber cnd;
	cout << "Enter your complex number as a string: " << endl;
	cin >> cnd; //use of input friend function
	//note: have the overloaded input call a validation method and
	//execute a cin.fail if the string is not valid - loop and ask again
	cout << cnd << endl;//use of output friend function STUBBED!
	cout << "\n Test complete" << endl;
	_getch();


	return 0;
}