/* INFO450PIG.cpp - This program takes in sentences 500 characters long and 
 *                  translates them to piglatin
 * updated: 6 Oct
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
    //cout << "DEBUG: sentence = " << sentence << endl;

    char * word;

    word = strtok(sentence, " ");   //" ,.-!@#$%^&*()_+-={[]}|\\<>"

    while(word != NULL)
    {
        //cout << "DEBUG: word found --> " << word << endl;

        if(verifyWord(word))
        {     
            translate(word);
        }
        else
        {
            cout << word << " ";
        }

        word = strtok(NULL, " ");
    }
}

bool verifyWord(char *word)
{
    regex wordRegex("[^aeiou]\\w{2}\\w+[,.!\\?]?");
    regex blackList("the|\\w+\\'\\w+");

    bool match = false; 

    if(regex_match(word, wordRegex) && !(regex_match(word, blackList)))
    {
        match = true;
        //cout << "DEBUG: match = " << boolalpha << match << endl;
    }

    //cout << "DEBUG: returning match = " << boolalpha << match << endl;
    return match;
}


void getSentence(char *sentence)
// this funciton takes in user input and assign a pointer to it
{

    char input[500]; 
    cout << "\n\nWhat is the sentence you would like to translate "
         << "(max 500 characters)? Enter 'exit' to quit." << endl;
    cin.getline(input, 500);


    strcpy(sentence, input);
}


void translate(char *word)
{
    switch(word[strlen(word)-1])
    {
        case ',':
        case '.':
        case '?':
        case '!':
            {
                char ending[] = {word[strlen(word)-1]};

                for(int i = 1; i < strlen(word) - 1; i++)
                    cout << word[i];
                cout << word[0] << "ay" << ending << " ";
                break;
            }
        default:
            for(int i = 1; i < strlen(word); i++)
                cout << word[i];
            cout << word[0] << "ay ";
            break;
    }
}


int main ()
{
    bool exit = false;
    char *sentence;

    do
    {
        //cout << "\nEntering getSentence" << endl;
        getSentence(sentence);

        if(sentence == "exit")
            break;

        //cout << "\nEntering disectSentence" << endl;
        disectSentence(sentence);

        cout << '\n' << endl;

    } while( exit == false);

    cout << "\nExiting!" << endl;
}
