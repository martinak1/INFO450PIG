# INFO450PIG
An INFO450 project 

https://travis-ci.org/martinak1/INFO450PIG.svg?branch=master

Topics Covered:  Arrays, C-Strings, functions, loops, conditional statements

Functional Requirements:
    Write a program that will translate English words into Pig Latin 
    Rules  for translating English to Pig Latin**:
        If the word starts with a consonant, the first character is removed and added to the end of the word.  An “ay” is appended to the end of the word.
            pig = igpay
            latin = atinlay
            job = objay
            school = choolsay
        If the word begins with a vowel then the word is simply appended with and “ay”
            every = everyay
            out = outay
            apple = appleay
        If the word has only two characters, the work remains the same
            of = of
            to = to
        If the word is an article (e.g. the, a, an) OR a conjunction:  (and, but, for, nor, so, yet, or), the word remains the same
        Any word that starts with a number should not be translated and user provided with an error message.
    The user should be allowed to continue to enter words for translation until they opt to quit the program
    For each work provided, the translated Pig Latin is displayed to the console

Extra credit:
Allow the user to enter a sentence and translate the entire sentence to pig Latin using the above rules

** rules represent a variation to the standard Pig Latin translation



psudo code:


    while( exit != true)
        
        prompt for sentance
        parse string for words
        translate qualifying words
        print the words
        check if user wants to exit
    
    cleanup 
