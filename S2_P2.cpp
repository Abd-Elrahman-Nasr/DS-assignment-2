#include <bits/stdc++.h>
using namespace std;

#define rep0(i,sz)   for(int i=0;i<sz;++i)

/*
If User enter any string word ,will return true ,because stack not store any of them.(empty stack)
*/

bool check(char open ,char close)
{
    return (open=='('&&close==')')  ? true  : ( (open=='{'&& close=='}') ?  true :((open=='['&&close==']') ? true :  false) ) ;
}

/*Balanced String*/
bool S2P2(string exp)
{
    stack<char>S;
    rep0(i,exp.length())
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        {
              S.push(exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
        {
            if( (S.empty()) || !( check(S.top(),exp[i]) ))
            {
               return false;
            }
            else
            {
                S.pop();
            }
        }
    }


    return S.empty();
}

int main()
{
string exp;
while(cin>>exp){(S2P2(exp)) ? cout << "True\n" : cout << "False\n";}
    return 0;
}










