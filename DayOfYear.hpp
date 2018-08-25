//File: dayofyear.hpp

#ifndef _DAYOFYEAR_HPP_
#define _DAYOFYEAR_HPP_

#include <iostream>
#include <cstdlib>
using namespace std;

class DayOfYear {
    public:
        //Constructors
        DayOfYear(int monthValue, int dayValue);
        DayOfYear(int monthValue);
        DayOfYear();

        //Additions
        friend DayOfYear operator+(const DayOfYear&, const DayOfYear&); 
		friend DayOfYear operator+(const DayOfYear&, const int&);
		friend DayOfYear operator+(const int&, const DayOfYear&);
        
        //Subtraction & Negation
        friend DayOfYear operator-(const DayOfYear&, const DayOfYear&);
        DayOfYear operator-() const;

        //Comparisons
		friend bool operator==(const DayOfYear&, const DayOfYear&);
		friend bool operator<(const DayOfYear&, const DayOfYear&);
		friend bool operator>(const DayOfYear&, const DayOfYear&);
		friend bool operator!=(const DayOfYear&, const DayOfYear&);

        //Increments
        DayOfYear& operator ++(); //pre
        DayOfYear& operator --();        
        const DayOfYear operator ++(int); //post
        const DayOfYear operator --(int);

        //[]
        int operator [](int) const;

        //Filestreams - cannot be member functions
        friend ostream& operator <<(ostream&, const DayOfYear&); //output
        friend istream& operator >>(istream&, DayOfYear&); //input
    
    private:
        int month;
        int day;
};

#endif