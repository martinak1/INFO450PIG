/* INFO450PIG.cpp - This program takes in sentences and translates them to
 * piglatin
 * updated: 27 sep
 */

#include <iostream>
#include <regex>
#include <cstring>


using namespace std;


void disectSentence (char *sentence);
void getSentence    (char *sentence);
void translate      (char *word);
bool verifyWord     (char *sentence);


void disectSentence(char *sentence)
// parses a sentence looking for words, verifies the ones found, then translates
// them as need
{
    cout << "DEBUG: sentence = " << sentence << endl;

    char * word;

    word = strtok(sentence, " ,.-");

    while(word != NULL)
    {
        cout << "DEBUG: word found --> " << word << endl;
        word = strtok(NULL, " ,.-");
    }
}

bool verifyWord(char *word)
{
    regex wordRegex("[^aeiou]\\w{2}\\w+");
    regex blackList("the|\\w+\\'\\w+");

    bool match = false; 

    if(regex_match(word, wordRegex) && regex_match(word, blackList))
        match = true;

    return match;
}


void getSentence(char *sentence)
// this funciton takes in user input and assign a pointer to it
{

    char input[500]; 
    cout << "What is the sentence you would like to translate "
         << "(max 500 characters)? Enter 'exit' to quit." << endl;
    cin.getline(input, 500);


    strcpy(sentence, input);
}


void translate(char *word)
{
    char* firstLetter;
    char ending[] = "ay";

    for(int i = 1; i < strlen(word); i++)
       cout << word[i];
    cout << word[0] << "ay";
}


int main ()
{
    bool exit = false;
    char *sentence;

    do
    {
        cout << "\nEntering getSentence" << endl;
        getSentence(sentence);

        cout << "\nEntering disectSentence" << endl;
        disectSentence(sentence);

    } while( exit == false);
}
