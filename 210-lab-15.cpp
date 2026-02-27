// COMSC-210 | Lab 15 | Noel Mier-Luna
#include <iostream>
#include <iomanip>
#include <vector> // Using vector for storing movie objects.
#include <fstream>
using namespace std;

const int WIDTH = 10; // Constant for formatting output width.

class Movie
{
    string title;
    int year;
    string screenWriter;
    // Getters and setters for the Movie class member variables.
public:
    string getTitle() const { return title; }
    void setTitle(string t) { title = t; }
    int getYear() const { return year; }
    void setYear(int y) { year = y; }
    string getWriter() const { return screenWriter; }
    void setWriter(string w) { screenWriter = w; }

    void print() const
    {
        cout << "Movie: " << setw(WIDTH) << getTitle()
             << "Year: " << setw(WIDTH) << getYear()
             << "Screenwriter: " << setw(WIDTH) << getWriter() << endl;
    }
};

    int main()
    {
        vector<Movie> movies; // Vector to store Movie objects.
        string temp_title;
        int temp_year; // Temporary variables for reading movie data from the file.
        string temp_writer;
        ifstream inFile("input.txt"); // Opens the input file for reading movie data.
        if (!inFile)
        {
            cerr << "Error opening file!" << endl;
        }
        while (inFile >> temp_year)
        {
            inFile.ignore();              // Ignores newline character after reading year to prevent issues with getline.
            getline(inFile, temp_title);  // Reads movie title from the file.
            getline(inFile, temp_writer); // Reads screenwriter name from the file.
            Movie temp_movie;             // Creates a temporary Movie object to store read data.
            temp_movie.setYear(temp_year);
            temp_movie.setTitle(temp_title);
            temp_movie.setWriter(temp_writer);
            movies.push_back(temp_movie); // Adds the temporary Movie object to the movies vector.
        }
        {
            Movie temp_movie; // Creates a temporary Movie object to store read data.
        }
        inFile.close(); // Closes the input file after reading is done.
        // Test for printing the movies to verify that they were read correctly.
        for (const Movie movie : movies)
        {
            movie.print();
        }
        return 0;
    }