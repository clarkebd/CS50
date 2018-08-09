/************************/
/* Brian Clarke         */
/* CS50 - Assignment 2  */
/************************/

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
        printf("Usage: ./caesar k\n");
        exit(1);
    }

    // OK, arguments are good, let's show them to user
    // argv[1] is a string initially. Need to convert to interger

    int shiftamount = atoi(argv[1]); // use atoi function to do this

    //Ask user for plaintext that they want to encrypt
    string userstring = "";
    userstring = get_string("plaintext: ");

    //determine length of entered string
    int slen = strlen(userstring);

    printf("ciphertext: ");

    for (int i = 0; i < slen; i++)
    {

        if (isalpha(userstring[i]))
        {
            if (isupper(userstring[i]))
            {
                char converted = ((userstring[i] - 'A' + shiftamount) % 26) + 65;
                printf("%c", converted);
            } // end isUpper

            else

                if (islower(userstring[i]))
                {
                    char converted = ((userstring[i] - 'a' + shiftamount) % 26) + 97;
                    printf("%c", converted);
                }//end isLower
        } // end if

        else
        {
            printf("%c", userstring[i]);
        } // end else
    } // end for
    printf("\n");
}; // end main
