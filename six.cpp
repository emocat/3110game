#include <iostream>
#include <string>
#include <cstring>
#include "six.h"

void Six::queryUser(Question q)
    {
        char skip[5] = "skip";
        char giveup[8] = "give up";
        char userAnswer[100];
        char lowerCase[100];
        int length;
        cout << q.question << endl;
        cout << "The six-letter word is: " << q.sixLetterWord << endl;
        cout << "Please enter your answer: " << endl;
        cin.clear(); 
        cin.getline(userAnswer, 100);
        cout << "You typed: " << userAnswer << endl;

        while (q.solved == false && q.attemptsLeft >0)
        {
            for(int i = 0; i<25; i++){
                userAnswer[i] = tolower(userAnswer[i]);                 
                }
            if (strcmp(userAnswer,q.answer)==0)

            {
                cin.clear();
                score++;
                q.solved = true;
                cout << "Correct! Your current score has been increased to: " << score << endl;
            }
            else if (strcmp(userAnswer,skip) == 0)
            {
                cout << "You chose to skip this question. Moving on to next question..." << endl;
                break;
            }
            else if (strcmp(userAnswer,giveup) == 0)
            {
                cout << "You chose to give up. The answer is " << q.answer << ". Moving on to next question. "<< endl;
                break;
            }
            else
            {
                q.attemptsLeft--;
                cout << "Incorrect! You have " << q.attemptsLeft << " attempts remaining!" << endl;
                if (q.attemptsLeft>0){
                    cout << q.question << endl;  
                    cout << "The six-letter word is: " << q.sixLetterWord << endl;
                    cin.clear();
                    cin.getline(userAnswer, 100);
                    cout << endl;
                }
		
            }
        }

        if (q.attemptsLeft == 0)
        {  
            cout << "You have failed your three attempts at this question :(" << endl;
            cout << "Moving on to the next question..." << endl;
        }
    }

void Six::printDirections()
    {
        
        cout << "Welcome to Six Packs! There are ten questions which you must answer." << endl;
        cout << "You will have three attempts to answer each question. Each answer will be comprised of two words." << endl;
        cout << "If you take the first three letters of each word and combine them, you will end up with another word." << endl;
        cout << "For example..." << endl;
        cout << "The user will see a question or statment such as...."<<endl;
        cout << "(1)What some people believe Shakespeare wrote(7,6)"<<endl;
        cout << "Followed by the six letter word PERSON."<<endl;
        cout << "The numbers indicate that the first word of the answer has 7 letters and the second word has 6 letters."<<endl;
        cout << "The word person results from adding the first 3 letters of each word: \"Per\" for the first and \"son\"for the second."<<endl;
        cout <<"The answer would be perfect sonnet."<<endl<<endl<<"Now Let the games begin :D"<<endl<<endl;  
    

    }

void Six::loadQuestions(Question qarray[])
    {
        const int LENGTH = 200;
        char input[LENGTH];
        fstream inFile;
        inFile.open("3110questions.txt",ios::in);
        for (int i=0;i<10;i++)
        {
            inFile.getline(input,LENGTH); //skip over "QUESTION X"
            inFile.getline(input,LENGTH);
            qarray[i].question=input;
            inFile.getline(input,LENGTH);
            qarray[i].stringAnswer = input;
            char * cstr = new char[qarray[i].stringAnswer.length()+3];
            strcpy(cstr,qarray[i].stringAnswer.c_str());
            strcpy(qarray[i].answer,cstr);
            inFile.getline(input,LENGTH);
            qarray[i].sixLetterWord=input;
        }
    }
