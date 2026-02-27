//COMSC-210 | Lab 15 | Noel Mier-Luna
#include <iostream>
#include <iomanip>
#include <vector> // Using vector for storing movie objects.
#include <fstream>
using namespace std;

const int WIDTH = 10; // Constant for formatting output width.

class Movie {
    string title;
    int year; 
    string screenWriter;
    // Getters and setters for the Movie class member variables.
    public:
    string getTitle() const { return title; }
    void setTitle(string t) { title = t; }
    int getYear() const { return year; }
    void setYear(int y) { year = y;}
    string getWriter() const { return screenWriter; }
    void setWriter(string w) { screenWriter = w; }

    void print() const {
        cout << "Movie: " << setw(WIDTH) << getTitle()
             << "Year: " << setw(WIDTH)

    }

};