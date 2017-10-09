/* INFO450PIG.cpp - This program takes in sentences 500 characters long and 
 *                  translates them to piglatin
 * updated: 9 Oct
 */

#include <cstring>
#include <cstdio>
#include <iostream>
#include <regex>


using namespace std;


void disectSentence (char *sentence);
void getSentence    (char *sentence);
void translate      (char *word);
bool verifyWord     (char *sentence);


void disectSentence(char *sentence)
// parses a sentence looking for words, verifies the ones found, then translates
// them as need
{
    char *word;
    word = strtok(sentence, " ");   

    cout << "\nTranslated:\n " << endl;

    while(word != NULL)
    {
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
// determins if a word needs to be translated or not
// called in disectSentence
{
    // regex that matches words without non-standard punctuation
    regex wordRegex("[a-zA-Z]{2}\\w+[,.!?;:]?");
    regex blackList("the|and|but|for|nor|yet|\\w+\\'\\w+");

    bool match = false; 

    if(regex_match(word, wordRegex) && !(regex_match(word, blackList)))
        match = true;

    return match;
}


void getSentence(char *sentence)
// handels user input
{

    char input[501]; 
    cout << "\n\nWhat is the sentence you would like to translate "
         << "(max 500 characters)? Enter '0' to quit." << "\n\nOriginal:\n" <<endl;

    fgets(input, 501, stdin);
    strcpy(sentence, input);
    return;
}


void translate(char *word)
// translates words to piglatin and keeps the appropriate punctuation
// called in disectSentence
{
    regex startsWithVowel("[aeiouAEIOU]+\\w+[!.,:;?]?");

    if(regex_match(word, startsWithVowel))
    // true if word starts with a-zA-Z
    {
        switch(word[strlen(word)-1])
        {
            case ',':
            case '.':
            case '?':
            case '!':
            case ';':
            case ':':
                for(int i = 0; i < strlen(word) - 1; i++)
                    cout << word[i];
                cout << "ay" << word[strlen(word)-1] << " ";
                break;
            default:
                for(int i = 0; i < strlen(word); i++)
                    cout << word[i];
                cout << "ay ";
                break;
        }
    }
    else
    {
        switch(word[strlen(word)-1])
        {
            case ',':
            case '.':
            case '?':
            case '!':
            case ';':
            case ':':
                for(int i = 1; i < strlen(word) - 1; i++)
                    cout << word[i];
                cout << word[0] << "ay" << word[strlen(word)-1] << " ";
                break;
            default:
                for(int i = 1; i < strlen(word); i++)
                    cout << word[i];
                cout << word[0] << "ay ";
                break;
        }
    }
}


int main ()
{
    bool exit = false;
    char *sentence;

    do
    {
        // handle user input
        getSentence(sentence);

       if(sentence == NULL)
            return -1;

        // exit condition
        if(sentence[0] == '0')
            break;

        // parse sentence and translate as needed
        disectSentence(sentence);

    } while(true);

    cout << "\nExiting!" << endl;
    return 0;
}
