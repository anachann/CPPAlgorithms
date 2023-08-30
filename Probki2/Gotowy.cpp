#include <iostream>

using namespace std;

struct sample
{
    int value;
    string descript;
};


bool ifEquals(const string& a, const string& b)
{
    unsigned int size = a.size();
    if (b.size() != size)
        return false;
    for (unsigned int i = 0; i < size; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

void selectionSortValue(sample samples[], int n, int k)  
{  
    int max;  
    for (int i = k; i < n-1; i++)  
    {    
        max = i;
        for (int j = i+1; j < n; j++)  
            if (samples[j].value > samples[max].value)  
                max = j;  

        sample additional;
        additional = samples[max];
        samples[max] = samples[i];
        samples[i] = additional;
    }  
}  


void selectionSortString(sample samples[], int n, int k)  
{  
    int max;  
    for (int i = k; i < n-1; i++)  
    {    
        max = i;
        for (int j = i+1; j < n; j++)  
            if (samples[j].descript < samples[max].descript)  
                max = j;  

        sample additional;
        additional = samples[max];
        samples[max] = samples[i];
        samples[i] = additional;
    }  
}  



int main()
{
    ios_base::sync_with_stdio(false); 



    //variables declaration
    int t, n, begin;
    bool sortByValue;
    cin >> t;


    //loop - amount of groups for sort
    for (int k=0; k<t; k++)
    {
        cin >> n;
        sample* samples = new sample[n];

        //loop - amount of samples for sort in groups
        for (int i=0; i<n; i++)
        {
            cin >> samples[i].descript;
            cin >> samples[i].value;
        }


        //which segments to refer to while sorting
        cin >> sortByValue;

        //if for values
        if(sortByValue)
        {
            selectionSortValue(samples, n, 0);

            for (int i=1; i<n; i++)
            {
                if(samples[i-1].value == samples[i].value) 
                {
                    begin=i-1;

                while(samples[i-1].value == samples[i].value) 
                {
                    i++;
                }
                selectionSortString(samples, i, begin);
                }
            }
        }


        //if for strings
        else
        {
            selectionSortString(samples, n, 0);
            for (int i=1; i<n; i++)
            {
                if(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    begin=i-1;
                
                while(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    i++;
                }
                selectionSortValue(samples, i, begin);
                }
            }
        }
        


        //result
        for (int i=0; i<n; i++)
        {
            cout << samples[i].descript << "-";
            cout << samples[i].value << " ";
        }
        if(k != t-1) cout << "\n";
        delete [] samples;
    }



    return 0;
}
