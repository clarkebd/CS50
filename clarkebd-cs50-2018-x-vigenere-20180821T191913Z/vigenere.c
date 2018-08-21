/*********************************/
/* Brian Clarke                  */
/* CS50 - Assignment 2 - Part 2  */
/*********************************/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int k = argc; // We only use 'k' once-to check that user entered the appropriate amount of command line arguments.

    // check to make sure just the right number of arguments have been entered
    if (k != 2)
    {
        printf("Usage: ./vigenere k\n");
        exit(1);
    }

    for (int x = 0; x < strlen(argv[1]); x++)
    {
        if (! isalpha(argv[1][x]))
        {
            printf("Keyword must be alpha only.\n");
            exit(1);
        }
    }


    // OK, arguments are good, let's assign it to a varible that's easier to use
    string keyword = argv[1];
    int keyWordLength = strlen(keyword); // length of user entered cipher string

    //Ask user for plaintext that they want to encrypt
    string userstring = "";
    userstring = get_string("plaintext: ");

    printf("ciphertext: ");


    for (int i = 0, j = 0; i < strlen(userstring); i++)
    {
        // if letter in plaintext is UPPER CASE
        if (isupper(userstring[i]))
        {
            //
            int shiftamount = tolower(keyword[j % keyWordLength]) - 'a';
            printf("%c", ((userstring[i] - 'A' + shiftamount) % 26) + 65);
            j = j + 1;
        }

        else if (islower(userstring[i]))
        {
            int shiftamount = tolower(keyword[j % keyWordLength]) - 'a';
            printf("%c", ((userstring[i] - 'a' + shiftamount) % 26) + 97);
            j = j + 1;
        }


        else
        {
            printf("%c", userstring[i]);
        } // end ELSE
    } // end FOR

    printf("\n");


}; // end main
