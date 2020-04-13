#include <bits/stdc++.h>

using namespace std;

int bin2dec(string bin){
    stack<int> binStack;
    int dec=0;

    /// store in the stack as integers
    for(int i=0; i < bin.length(); i++)
        binStack.push(bin[i] - '0');

    /// convert to decimal
    for(int n=0; !binStack.empty(); n++){
        dec += binStack.top() * pow(2, n);
        binStack.pop();
    }

    return dec;
}

int main(){

    /// test cases
    cout << bin2dec("11000101") << endl;
    cout << bin2dec("10101010") << endl;
    cout << bin2dec("11111111") << endl;
    cout << bin2dec("10000000") << endl;
    cout << bin2dec("1111100000") << endl;

    return 0;
}
