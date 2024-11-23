#include <iostream>

using namespace std;


string uniqueChars(string str) 
{
  string newStr = "";
  bool arr[128];
  for(int i = 0;i < 128; i++) 
  {
    arr[i] = false;
  }

  char c;

  for(int i = 0; i < str.length(); i++) 
  {
    c = str[i];
    if(c < 0 || c > 127) 
    {
      continue;
    }
    if(!arr[c]) 
    {
      arr[c] = true;
      newStr += c;
    }
  }
  return newStr;
}

bool checkpass(string pass)
{
    bool characters=false, charDiff=false, digit=false, charUp=false, charLow=false, nonAlphabetic=false;
    if (pass.length()>=8) characters=true;      //checking if there are 8 characters in string
    else characters=false;  


    if (uniqueChars(pass).length()>=6) charDiff=true;   //checking if there are at least 6 different characters

    for (int i=0; i<pass.length(); i++)     //checking if password contains a digit
    {
        if(pass[i]>=48 && pass[i]<=57) digit=true;
    }

    for (int i=0; i<pass.length(); i++)     //checking if password contains an uppercase character
    {
        if(pass[i]>=65 && pass[i]<=90) charUp=true;
    }

    for (int i=0; i<pass.length(); i++)     ////checking if password contains a lowercase character
    {
        if(pass[i]>=97 && pass[i]<=122) charLow=true;
    }

    for (int i=0; i<pass.length(); i++)     //checking if password contains a special character
    {
        if((pass[i]>=33 && pass[i]<=47) ||
        (pass[i]>=58 && pass[i]<=64) ||
        (pass[i]>=91 && pass[i]<=96) ||
        (pass[i]>=123 && pass[i]<=126)) nonAlphabetic=true;
    }

    if(characters==false) cout << "Too short" << endl;
    if(charDiff==false) cout << "Too few different Characters" << endl;
    if(digit==false) cout << "No digit" << endl;
    if(charUp==false) cout << "No uppercase character" << endl;
    if(charLow==false) cout << "No lowercase character" << endl;
    if(nonAlphabetic==false) cout << "No special character" << endl;

    if(characters==true && charDiff==true && digit==true &&
    charUp==true && charLow==true && nonAlphabetic==true)
    {
        return true;
    } 
    else return false;
}

int main() {
    const string passes[] =
    {
        "AbcDe93", "A1b:A1b>", "Ab:Acb<",
        "abc123><", "Zorro@123"
    };

    for (size_t i = 0; i < std::size(passes); ++i) 
    {
        cout << "checking " << passes[i] << endl;
        if (checkpass(passes[i])) cout << "OK" << endl;
        cout << endl;
    }
}