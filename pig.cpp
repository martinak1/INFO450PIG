/* INFO450PIG.cpp - This program takes in sentences and translates them to
*  piglatin
*  updated: 27 sep
*/

#include <iostream>
#include <regex>


using namespace std;

void getSentence (char *sentence);
void translate (char *sentence);


void getSentence(char *sentence)
{

    char input[500]; 
    cout << "What is the sentence you would like to translate "
         << "(max 500 characters)? Enter 'exit' to quit." << endl;
    cin.getline(input, 500);


    strcpy(sentence, input);
    //debug
    cout << "DEBUG: sentence = " << sentence << " *sentence = " << *sentence
        << endl;
    cout << "DEBUG: input = " << input << " *input = " << *input << endl;
}


void translate(char *sentence)
{
    
}

int main ( )
{
    bool exit = false;
    char *sentence;

    do
    {
        getSentence(sentence);
        // debug
        cout << "SENTENCE = " << sentence << endl;
        cout << "&SENTENCE = " << &sentence << endl;
        cout << "*SENTENCE = " << *sentence << endl;
    } while( exit == false);
}
