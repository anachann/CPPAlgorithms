/*Write a function with prototype
const double* aver(const double* arr,
size_t size, double& average);
which takes an array arr of doubles and its size, and also a variable average of type
double by reference. The task of the function is to put into variable average the
arithmetic average of all elements of the array, and to return the pointer to the
element of the array whose value is closest to this average.
For example, the following program*/



#include <iostream>
#include <cmath>

using namespace std;


const double* aver(const double* arr,
    size_t size, double& average) 
{
    double sum = 0;
    double arr2[size];
    double* result = new double;
    double number2 = arr[0];

    for (int i=0; i < size; i++)
    {
        if(arr[i] >= 0)  arr2[i] = arr[i];
        else arr2[i] = -arr[i];
    }

    for (int i=0; i<size; i++)
    {
        sum +=arr[i];
    }
    average = sum/size; 
    if((arr[0] - average) > 0) *result = arr[0] - average;
    else *result = -(arr[0] - average);
    double number = average - arr[0];
    for (int i=0; i<size; i++)
    {
        number2 = average - arr[i];
        if(number2<0) number2 = -number2;
        if(number2 < number) 
        {
            number = number2;
            *result = arr[i];
        }
    }
    return result;
}


int main()
{
    double average = 0;
    double arr[] = {1, 2, -1.5 , 3.25, 5.5, 7.75, -0.25, 5.75};
    size_t size = std::size(arr);
    const double* result;
    const double* p = aver(arr, size, average);
    cout << *p << " " << average << endl;
    return 0;
}