/* INFO450PIG.cpp - This program takes in sentences 500 characters long and 
 *                  translates them to Pig Latin
 * updated: 11 Oct
 */

#include <cstring>
#include <iostream>
#include <regex>


using namespace std;


void disectSentence (char *sentence);
void getSentence    (char *sentence);
void translateToPigLatin      (char *word);
bool verifyWord     (char *sentence);


void disectSentence(char *sentence)
/* parses a sentence looking for words, verifies the ones found, then translates
 * them as needed
 * called in main
 */
{
    char *word;
    
    // split on white space or NULL
    word = strtok(sentence, " \n\r\0\t");   

    cout << "\nTranslated:\n " << endl;

    // while one or more tokens exits verify -> translate each
    while(word != NULL)
    {
        if(verifyWord(word))
        {     
            translateToPigLatin(word);
        }
        // print invalid words as is and move on
        else
        {
            cout << word << " ";
        }

        word = strtok(NULL, " \n\r\0\t");
    }
}


void getSentence(char *sentence)
// handles user input
// called in main
{
    char input[500]; 
    cout << "\n\nWhat is the sentence you would like to translaten "
         << "(max 500 characters)? Enter '0' to quit." << "\n\nOriginal:\n" <<endl;
    fgets(input, 500, stdin);
    strcpy(sentence, input);
    return;
}


void translateToPigLatin(char *word)
// translates a word to Pig Latin and keeps the appropriate punctuation
// called in disectSentence
{
    regex startsWithVowel("[aeiouAEIOU]+\\w+[!.,:;?]?");
    int length = strlen(word);

    if(regex_match(word, startsWithVowel))
    {
        switch(word[length-1])
        {
            case ',':
            case '.':
            case '?':
            case '!':
            case ';':
            case ':':
                // starts with a vowel, ends with punctuation
                for(int i = 0; i < length - 1; i++)
                    cout << word[i];
                cout << "ay" << word[length-1] << " ";
                break;
            default:
                // starts with a vowel, no punctuation
                for(int i = 0; i < length; i++)
                    cout << word[i];
                cout << "ay ";
                break;
        }
    }
    else
    {
        switch(word[length-1])
        {
            case ',':
            case '.':
            case '?':
            case '!':
            case ';':
            case ':':
                // doesn't start with a vowel, has punctuation
                for(int i = 1; i < length - 1; i++)
                    cout << word[i];
                cout << word[0] << "ay" << word[length-1] << " ";
                break;
            default:
                // doesn't start with a vowel, no punctuation
                for(int i = 1; i < length; i++)
                    cout << word[i];
                cout << word[0] << "ay ";
                break;
        }
    }
}


bool verifyWord(char *word)
// determins if a word needs to be translated or not
// called in disectSentence
{
    // regex that matches words with typical punctuation
    regex wordRegex("^[a-zA-Z]{2}\\w+[,.!?;:]?$");
    
    // regex that matches articles, conjunctions, and banned words
    regex blackList("the|and|but|for|nor|yet|\\w+[-']{1}\\w+");

    // if word is syntasticlly valid and not blacklisted then true, otherwise false
    bool match = (regex_match(word, wordRegex) && !(regex_match(word, blackList))) ? true : false; 

    return match;
}


int main()
{
    char sentence[500];

    do
    {
        // handle user input
        getSentence(sentence);

        // if getSentence fails exit with error
        if(sentence == NULL)
        {
            cout << "\n\n**ERROR: User input was invalid, exiting!" << endl;
            return -1;
        }

        // check exit condition
        if(sentence[0] == '0')
            break;

        // parse sentence and translate as needed
        disectSentence(sentence);

    } while(true);

    cout << "\nExiting!" << endl;
    return 0;
}
