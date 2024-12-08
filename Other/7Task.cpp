#include <iostream>
#include <string.h>

using namespace std;


enum Banks {PKO, BGZ, BRE, BPH};


struct Account 
{
    Banks bank;
    int balance;
};


struct Person 
{
    char name[20];
    Account account;
};


struct Couple 
{
    Person he;
    Person she;
};


const Couple* bestClient(const Couple* cpls,
int size, Banks bank) 
{
    int *balance = nullptr;
    int *balance2 = new int;
    Couple *result = new Couple;
    for (int i=0; i<size; i++)
    {
        if(bank == cpls[i].he.account.bank or bank == cpls[i].she.account.bank)
        {
            *balance2 = cpls[i].he.account.balance + cpls[i].she.account.balance;
            if(balance == nullptr)
            {
                balance = new int;
                *balance = cpls[i].he.account.balance + cpls[i].she.account.balance;
                *result = cpls[i];
            }
            if(*balance2 > *balance) 
            {
                *balance = *balance2;
                *result = cpls[i];
            }
        }
    }
    if (balance == nullptr) return nullptr;
    else return result;
}

// No He She
// Name Bank Balance Name Bank Balance
// 0 Johny PKO 1200 Mary BGZ 1400
// 1 Peter BGZ 1400 Suzy BRE -1500
// 2 Kevin PKO 1600 Katy BPH 1500
// 3 Kenny BPH 200 Lucy BRE -201

int main() 
{
    Account aJohny, aMary, aPeter, aSuzy, aKevin, aKaty, aKenny, aLucy;
    aJohny.balance = 1200;
    aJohny.bank = Banks(0);
    aMary.balance = 1400;
    aMary.bank = Banks(1);
    aPeter.balance = 1400;
    aPeter.bank = Banks(1);
    aSuzy.balance = -1500;
    aSuzy.bank = Banks(2);
    aKevin.balance = 1600;
    aKevin.bank = Banks(0);
    aKaty.balance = 1500;
    aKaty.bank = Banks(3);
    aKenny.balance = 200;
    aKenny.bank = Banks(3);
    aLucy.balance = -201;
    aLucy.bank = Banks(2);

    Person Johny, Mary, Peter, Suzy, Kevin, Katy, Kenny, Lucy;
    strcpy(Johny.name, "Johny");
    Johny.account = aJohny;
    strcpy(Mary.name, "Mary");
    Mary.account = aMary;
    strcpy(Peter.name, "Peter");
    Peter.account = aPeter;
    strcpy(Suzy.name, "Suzy");
    Suzy.account = aSuzy;
    strcpy(Kevin.name, "Kevin");
    Kevin.account = aKevin;
    strcpy(Katy.name, "Katy");
    Katy.account = aKaty;
    strcpy(Kenny.name, "Kenny");
    Kenny.account = aKenny;
    strcpy(Lucy.name, "Lucy");
    Lucy.account = aLucy;

    Couple JohnyMary, PeterSuzy, KevinKaty, KennyLucy;
    JohnyMary.he = Johny;
    JohnyMary.she = Mary;
    PeterSuzy.he = Peter;
    PeterSuzy.she = Suzy;
    KevinKaty.he = Kevin;
    KevinKaty.she = Katy;
    KennyLucy.he = Kenny;
    KennyLucy.she = Lucy;



    Couple cpls[] = {JohnyMary, PeterSuzy, KevinKaty, KennyLucy};

    const Couple* p = bestClient(cpls, 4, BRE);

    if (p)
        cout << p->he.name << " and " << p->she.name
        << ": " << p->he.account.balance +
        p->she.account.balance << endl;
    else
        cout << "No such couple...\n";
}