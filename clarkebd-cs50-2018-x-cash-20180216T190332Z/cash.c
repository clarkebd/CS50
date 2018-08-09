/************************/
/* Brian Clarke         */
/* CS50 - Assignment 2  */
/* "cash"               */
/************************/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float input = 0.00;
    int coins = 0;
    float newinput = 0.00;
    int roundedinput = 0;

    do
    {
        input = get_float("Change owed: ");
    }
    while (input < 0.0);

    //Take input get rid of decimals we care about by multiplying by 100
    newinput = (input * 100.00);
    //printf("new input = %f\n", newinput);

    //Now take that double and make it an int which drops the decimals we don't need.
    roundedinput = round (newinput);
    //printf("rounded value = %i\n", roundedinput);

    //Figure out quarters owed
    int quarters = (roundedinput / 25);
    int quarterchange = (roundedinput % 25);
    coins = coins + quarters;

    //printf("quarters = %i\n", quarters);
    //printf("leftover change = %i\n", quarterchange);

    //Figure out dimes owed
    int dimes = (quarterchange / 10);
    int dimechange = (quarterchange % 10);
    coins = coins + dimes;

    //Figure out nickles owed
    int nickles = (dimechange / 5);
    int nicklechange = (dimechange % 5);
    coins = coins + nickles;

    //Figure out pennies owed
    int penny = (nicklechange / 1);
    coins = coins + penny;

    //Tell user total coins returned
    printf("%i\n", coins);
}
