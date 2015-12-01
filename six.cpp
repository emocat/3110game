#include <iostream>
#include <string>
#include "six.h"

void Six::queryUser(Question q)
    {
        char userAnswer[100];
        char lowerCase[100];
        int length;
        q.attemptsLeft--;
        cout << q.question << endl;
        cout << "The six-letter word is: " << q.sixLetterWord << endl;
        cout << "Please enter your answer: " << endl;
        cin.clear(); //flushing cin
        cin.getline(userAnswer, 100);
        cout << "The user answer is: " << userAnswer << endl;
       // length = strlen(userAnswer);
        //for (int i=0;i<length;i++)
            //userAnswer[i] = tolower(userAnswer[i]);
        while (q.solved == false && q.attemptsLeft >0)
        {
            if (strcmp(userAnswer,q.answer)==0)
            //if (8)
            {
                cout << "Correct! Moving on to the next question!" << endl;
                cin.clear();
                score++;
                q.solved = true;
                cout << "Your current score has been increased to: " << score << endl;
            }
            else
            {
                cout << "Incorrect! You have " << q.attemptsLeft << " attempts remaining!" << endl;
                cout << "the answer you need to type is: " << q.answer << endl;
                cout << "You typed: " << userAnswer << endl;
                int test = (strcmp(userAnswer,q.answer));
                cout << test << endl;
                q.attemptsLeft--;
                cout << q.question << endl;
                cin.clear();
                cin.getline(userAnswer, 100);
                cout << endl;
            }
        }

        if (q.attemptsLeft == 0)
        {
            cout << "Incorrect! You have failed your three attempts at this question :(" << endl;
            cout << "Moving on to the next question..." << endl;
        }
    }

void Six::printDirections()
    {
        cout << "Welcome to Six Packs! There are ten questions which you must answer. You will have three " << endl;
        cout << "attempts to answer each question. Each answer will be comprised of two words. If you take " << endl;
        cout << "the first three letters of each word and combine them, you will end up with another word. For example " << endl;
        //blah blah blah
    }

void Six::loadQuestions(Question qarray[])
    {
        const int LENGTH = 200;
        char input[LENGTH];
        cout << "loadQuestions array started" << endl;
        fstream inFile;
        inFile.open("3110questions.txt",ios::in);
        for (int i=0;i<4;i++)
        {
            inFile.getline(input,LENGTH);
            qarray[i].question=input;
            inFile.getline(input,LENGTH);
            qarray[i].stringAnswer = input;
            // convert string to a c-string
            char * cstr = new char[qarray[i].stringAnswer.length()+3];
            strcpy(cstr,qarray[i].stringAnswer.c_str());
            strcpy(qarray[i].answer,cstr);
            //qarray[i].answer = cstr;
            //qarray[i].answer = cstr;
            cout << "Answer cstring was set to: " << qarray[i].answer << endl;
            inFile.getline(input,LENGTH);
            qarray[i].sixLetterWord=input;
        }
            cout << "loadQuestions array ended" << endl;
    }
