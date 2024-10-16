/*Write a program reading integers until zero is entered and printing the length of the
longest sequence of consecutive numbers of the same value (and this value).
For example, for
22 22 22 22 3 3 3 2 -6 -6 -6 0
the result should be
Longest sequence: 4 times 22
for
-2 -2 -2 31 31 31 31 31 17 6 6 6 0
the result should be
Longest sequence: 5 times 31
and for
-3 2 -3 -3 2 -3 61 61 61 0
it should be
Longest sequence: 3 times 61
Do not use arrays, strings or any other kind of collections.
*/
#include <iostream>

using namespace std;

int main()
{
    int number, count = 1, maxAmount = 0, maxNumber = 0, number2;
    cin >> number;
    while (number != 0)
    {
        if (number == 0) break;
        if (number2 == number)
        {
            count++;
            if (count > maxAmount) 
            {
                maxAmount = count;
                maxNumber = number;
            }
        }
        else count = 1;
        number2 = number;
        cin >> number;
    }
    cout << "Longest sequence: " << maxAmount << " times " << maxNumber;
    return 0;
}