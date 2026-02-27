// COMSC-210 | Lab 15 | Noel Mier-Luna
#include <iostream>
#include <iomanip>
#include <vector> // Using vector for storing movie objects.
#include <fstream>
using namespace std;

const int WIDTH = 30; // Constant for formatting output width.

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
        cout << "Movie: " << left << setw(WIDTH) << getTitle()
             << "Year: " << left << setw(WIDTH) << getYear()
             << "Screenwriter: " << left << setw(WIDTH) << getWriter() << endl;
    }
};

int main()
{
    vector<Movie> movies; // Vector to store Movie objects.
    string temp_title;
    int temp_year; // Temporary variables for reading movie data from the file.
    string temp_writer;

    ifstream inFile ("input.txt"); // Opens the input file for reading movie data.
    if (!inFile)
    {
        cerr << "Error opening file!" << endl;
        return 1; // Exit with error code if file cannot be opened.
    }
    while (getline(inFile, temp_title)) // This fixes issue. Movie title had white spaces and wasn't read properly.
    {
        inFile >> temp_year;
        inFile.ignore();    // Used to ignore newline character after reading year so that the next getline reads the screenwriter name correctly.       
        getline(inFile, temp_writer); // Reads screenwriter name from the file.
        Movie temp_movie;             // Creates a temporary Movie object to store read data.
        temp_movie.setYear(temp_year);
        temp_movie.setTitle(temp_title);
        temp_movie.setWriter(temp_writer);
        movies.push_back(temp_movie); // Adds the temporary Movie object to the movies vector.
    }
    inFile.close(); // Closes the input file after reading is done.
    // Test for printing the movies to verify that they were read correctly.
    for (const auto& movie : movies)
    {
        movie.print();
    }
    return 0;
}