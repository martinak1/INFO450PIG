/* INFO450PIG.cpp - This program takes in sentences and translates them to
 * piglatin
 * updated: 27 sep
 */

#include <iostream>
#include <regex>


using namespace std;


void bisectSentence (char *sentence);
void getSentence    (char *sentence);
void translate      (char *word);


void bisectSentence(char *sentence)
{
    regex wordRegex("\\w{2}\\w+");
    cmatch matches;

    regex_search(sentence, matches, wordRegex);

    for(size_t i = 0; i < matches.size(); i++)
    {
        cout << i << " word found: " << matches[i] << " translated: " << endl;
    }

}


void getSentence(char *sentence)
// this funciton takes in user input and assign a pointer to it
{

    char input[500]; 
    cout << "What is the sentence you would like to translate "
         << "(max 500 characters)? Enter 'exit' to quit." << endl;
    cin.getline(input, 500);


    strcpy(sentence, input);
    //debug
    //cout << "DEBUG: sentence = " << sentence << " *sentence = " << *sentence
    //  << endl;
    //cout << "DEBUG: input = " << input << " *input = " << *input << endl;
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
        // debug
        //cout << "SENTENCE = " << sentence << endl;
        //cout << "&SENTENCE = " << &sentence << endl;
        //cout << "*SENTENCE = " << *sentence << endl;

        cout << "\nEntering bisectWords" << endl;
        bisectSentence(sentence);

    } while( exit == false);
}
