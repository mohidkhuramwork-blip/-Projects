#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask user for change amount (0 or more)
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Count quarters needed
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

    // Count dimes needed
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    // Count nickels needed
    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);

    // Count pennies needed
    int pennies = calculate_pennies(cents);
    cents = cents - (pennies * 1);

    // Calculate and output minimum coin total
    int total_coins = quarters + dimes + nickels + pennies;
    printf("%i\n", total_coins);
}

// Calculate the number of quarters owed
int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

// Calculate the number of dimes owed
int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}

// Calculate the number of nickels owed
int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}

// Calculate the number of pennies owed
int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}
