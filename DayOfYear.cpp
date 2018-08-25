//File: dayofyear.cpp

#include "DayOfYear.hpp"
#include <vector>
#include <string>
using namespace std;

//Constructors
DayOfYear::DayOfYear(int monthValue, int dayValue) : month(monthValue), day(dayValue)
{
    //left empty, constructor
}

DayOfYear::DayOfYear(int monthVal) : month(monthVal), day(1)
{
    //left empty, constructor
}

DayOfYear::DayOfYear() : month(1), day(1)
{
    //left empty, null constructor
}

//Additions
DayOfYear operator+(const DayOfYear& one, const DayOfYear& two) {
    //object + object
    int finMonth, finDays;
    int oneDays = one.day + one.month * 30;
    int twoDays = two.day + two.month * 30;
    int sumDays = oneDays + twoDays;
    finMonth = sumDays / 30 % 12;

    if (finMonth == 0)
        finMonth = 12;

    finDays = sumDays % 30;

    if (finDays == 0)
        finDays = 30;

    return DayOfYear(finMonth, finDays);
}

DayOfYear operator+(const DayOfYear& one, const int& two) {
    //object + days
    int finMonth, finDays;
    int oneDays = one.day + one.month * 30;
    int sumDays = oneDays + two;
    finMonth = sumDays / 30 % 12;

    if (finMonth == 0)
        finMonth = 12;

    finDays = sumDays % 30;

    if (finDays == 0)
        finDays = 30;

    return DayOfYear(finMonth, finDays);
}

DayOfYear operator+(const int& one, const DayOfYear& two) {
    //days + object
    int finMonth, finDays;
    int twoDays = two.day + two.month * 30;
    int sumDays = one + twoDays;
    finMonth = sumDays / 30 % 12;

    if (finMonth == 0)
        finMonth = 12;

    finDays = sumDays % 30;

    if (finDays == 0)
        finDays = 30;

    return DayOfYear(finMonth, finDays);
}

//Subtraction & Negation
DayOfYear operator-(const DayOfYear& one, const DayOfYear& two) {
    //object - object
	int finMonth, finDays;
    int oneDays = one.day + one.month * 30;
    int twoDays = two.day + two.month * 30;

    if (oneDays < twoDays) {
        int temp = twoDays - oneDays;
        int total = 12 * 30 + 30; //max days in year w/12 mo 30 day
        int fin = total - temp;
        finMonth = fin / 30 % 12;

        if (finMonth == 0)
            finMonth = 12;

        finDays = fin % 30;    
    } else {
        int fin = oneDays - twoDays;
        finMonth = fin / 30 % 12;

        if (finMonth == 0)
            finMonth = 12;

        finDays = fin % 30;  

        if (finDays == 0)
            finDays = 30;
    }
    return DayOfYear(finMonth, finDays);
}

DayOfYear DayOfYear::operator -() const {
    //negation
    DayOfYear test;
    int finMonth, finDays, numDays;
    numDays = test.day + (test.month * 30);        
    numDays = 360 - numDays;
    finMonth = (numDays / 30);
    finDays = numDays % 30;

    if (finDays == 0)
        finDays = 30;
    
    return DayOfYear(finMonth, finDays);
}

//Comparisons
bool operator ==(const DayOfYear& one, const DayOfYear& two) {
    int oneDays = one.day + one.month * 30;
    int twoDays = two.day + two.month * 30;

	if (oneDays == twoDays)
		return(true);
	else
		return(false);
}

bool operator !=(const DayOfYear& one, const DayOfYear& two) {
    int oneDays = one.day + one.month * 30;
    int twoDays = two.day + two.month * 30;

	if (oneDays != twoDays)
		return(true);
	else
		return(false);
}

bool operator <(const DayOfYear& one, const DayOfYear& two) {
    int oneDays = one.day + one.month * 30;
    int twoDays = two.day + two.month * 30;

	if (oneDays < twoDays)
		return(true);
	else
		return(false);
}

bool operator >(const DayOfYear& one, const DayOfYear& two) {
    int oneDays = one.day + one.month * 30;
    int twoDays = two.day + two.month * 30;

	if (oneDays > twoDays)
		return(true);
	else
		return(false);
}

//Increments
//Pre
DayOfYear& DayOfYear::operator ++() {
    ++day;
    return *this;
}

DayOfYear& DayOfYear::operator --() {
    --day;
    return *this;
}

//Post
const DayOfYear DayOfYear::operator ++(int) {
    int temp = day;
    ++(*this);

    return DayOfYear(month, temp);
}

const DayOfYear DayOfYear::operator --(int) {
    int temp = day;
    --(*this);

    return DayOfYear(month, temp);
}

//[]
int DayOfYear::operator [](int index) const {
    if (index == 1) {
        return month;
    } else if (index == 2) {
        return day;
    } else if (index == 3) {
        return (month * 30 + day);
    } else {
		return (-1);
    }
}

//Filestreams
ostream& operator <<(ostream& out, const DayOfYear& temp) {
    out << temp.month << "/" << temp.day;
	return out;
}

istream& operator >>(istream& in, DayOfYear& amount) {
    vector<string> tokens; //finished pieces
    string str, frag; //for parsing

	string splitBy = "/"; //parse character

    //auto typing
    size_t splitAt;
    size_t splitLen = splitBy.size();
    size_t sz;

    //takes in a string, puts string into tokens
    in >> str;
    tokens.push_back(str);

    //splits things up and puts the finished bits into tokens
    while(true) {
        frag = tokens.back();
        splitAt = frag.find(splitBy);

        if (splitAt == string::npos) {
            break;
        }

        tokens.back() = frag.substr(0, splitAt);
		tokens.push_back(frag.substr(splitAt + splitLen, frag.size() - (splitAt + splitLen)));        
    }


    if (tokens.size() < 2) {
        amount.month = 1;
        amount.day = 1;
        return in;
    }

    int mo = stoi(tokens[0],&sz);
    int da = stoi(tokens[1],&sz);

    if ((mo < 1) || (mo > 12)) {
        amount.month = 1;
        amount.day = 1;
        return in;
    }

    if ((da < 1) || (da > 30)) {
        amount.month = 1;
        amount.day = 1;
        return in;
    }

    //Converts string tokens into integer & stores
    amount.month = mo;
    amount.day = da;
    return in;
}