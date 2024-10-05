/*Write a program which reads in a loop a sequence of integral numbers until the user
enters 0, which just signals the end of data and is not then taken into account. After
that, the program prints the value of the smallest and the largest element of the
sequence and the number of occurrences of these values in the whole sequence.
For example, for the sequence (7, 3, −24, 2, 7, −24, 7, 2, 0), the program should print:
Min = -24 2 times
Max = 7 3 times
Note: do not use arrays or any other collections!*/
#include <iostream>

using namespace std;

int main()
{
    int input = -1;
    int amountMin=1, amountMax=1, min = 0, max = 0;
    cin >> input;
    min = input;
    max = input;
    while (input != 0)
    {
        if (input == 0)
        {
            break;
        }
        else if(input<min)
        {
            min = input;
            amountMin = 1;
        }
        else if(input>max)
        {
            max = input;
            amountMax = 1;
        }
        else if(input == min)
        {
            amountMin += 1;
        }
        else if(input == max)
        {
            amountMax += 1;
        }
        cin >> input;
    }
    cout << "Min = " << min << " " << amountMin << " times" << endl << "Max = " << max << " " << amountMax << " times";
    return 0;
}