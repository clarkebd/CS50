/************************/
/* Brian Clarke         */
/* CS50 - Assignment 1  */
/************************/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;

//Prompt user for height of half-pyramid
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

//Figure out the MAX width of pyramid (spaces+bricks combined)
    int originalwidth = height + 1;

//Start building the pyramid
    while (height > 0)
    {
        int width = (height + 1);
        int spaces = (width - 2);

        //Print Spaces First
        for (int loops = (width - 2); loops > 0; loops--)
        {
            printf(" ");
        } //endfor
        //Print Bricks for remainder of row
        for (int bricks = (originalwidth - spaces); bricks > 0; bricks--)
        {
            printf("#");
        } //endfor bricks
        //Start a new row
        printf("\n");

        height--;
    } // end while
}
