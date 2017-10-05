/* INFO450PIG.cpp - This program takes in sentences and translates them to
 * piglatin
 * updated: 27 sep
 */

#include <iostream>
#include <regex>


using namespace std;


void getSentence    (char *sentence);
void translate      (char *word);
void disectSentence (char *sentence);
bool verifyWord     (char *sentence);


void disectSentence(char *sentence)
// parses a sentence looking for words, verifies the ones found, then translates
// them as need
{
    int wordBeg, wordEnd = 0;
    

    while( wordBeg < strlen(sentence))
    {
        for( ; wordBeg++)
        {
            cout << "DEBUG: wordBeg at " << wordBeg << endl
        }

        wordEnd = wordBeg;

        for((wordEnd != ' ' || wordEnd != '\t'); wordEnd++)
        {
        
            cout << "DEBUG: wordEnd at " << wordEnd << endl;
        }

        cout << "DEBUG: word found between [" << wordBeg << ":" << wordEnd << "]: " sentence[wordBeg:wordEnd] << endl;
    }

bool verifyWord(char *word)
{
    regex wordRegex("[^aeiou]\\w{2}\\w+");
    regex blackList("the|")

    bool match = regex_match(word, wordRegex);

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

        cout << "\nEntering verifyWord" << endl;

    } while( exit == false);
}
