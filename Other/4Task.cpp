/*
A date may be specified by three numbers denoting year, month and day of month.
If we don’t need dates from a deep past, we can specify years relative to the year
2000 (e.g., year 2032 as 32). Assuming that we will not consider the future past the
year 2127, we can use numbers from the interval [0, 127] for year; such numbers can
be written on 7 bits. Month number can occupy 4 bits, as it belongs to the interval
[0, 15], and for the day we can spend 5 bits (which is enough to store any number from
the interval [0, 31]). Therefore, full date can be packed in 16 bits and we can store
two such dates (e.g., beginning and end of a period) in one, usually 32-bit, variable
of type int (to be safe, you can use int32_t from the cstdint header).
Write
• a function which, given two dates (each specified by three numbers of type int
— year, month and day), creates and returns one value of type int with both
dates packed in it;
• a function which, given one int, prints the information on two dates which has
been packed into this number.

year 7 bits
month 4 bits
day 5 bits
two times = 32 bits
*/



#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

void showPeriod(int period)
{
    cout << ((period & 0b11111110000000000000000000000000) >> 25) + 2000 << "/" << 
        ((period & 0b00000001111000000000000000000000) >> 21) << "/" <<
        ((period & 0b00000000000111110000000000000000) >> 16) << "-" <<
        ((period & 0b00000000000000001111111000000000) >> 9) + 2000 << "/" <<
        ((period & 0b00000000000000000000000111100000) >> 5) << "/" <<
        ((period & 0b00000000000000000000000000011111));
}
int pack(int fromy, int fromm, int fromd,
int toy, int tom, int tod)
{
    fromy = fromy - 2000;
    toy = toy - 2000;
    int result = (fromy << 25) | (fromm << 21) | (fromd << 16) | (toy << 9) | (tom << 5) | tod;
    //cout << bitset<32>(result) << endl;
    return result;
}
int main() {
// y m d y m d
int period = pack(2000, 2, 3, 2127, 11, 29);
showPeriod(period);
}
