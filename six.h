#ifndef SIX_H
#define SIX_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Six
{
public:
    Six()
    {
        cout << "Get Ready to test your skills "<<endl<<endl;
        printDirections();
        score = 0;
        numFailed = 0;
        numRemaining = 10;
        loadQuestions(questionArray);
        for (int i=0;i<10;i++)
        {
            cout << "Question Number " << i+1 << endl;
            queryUser(questionArray[i]);
        }
    }
    struct Question
    {
       string question;
       string stringAnswer; //string, to be converted to cstring
       char answer[100]; //cstring
       int attemptsLeft; //starts with three attempts
       string sixLetterWord;
       bool solved; //flag changed to true if user answers correctly
       Question() //constructor
       {
        attemptsLeft = 3;
        solved = false;
       }
    };
    void queryUser(Question);
    void printDirections();
    void loadQuestions(Question []);

private:
    int score; //number of questions solved successfully
    int numFailed; //number questions failed
    int numRemaining; //number of questions left to solve
    Question questionArray [20]; 
};
#endif
