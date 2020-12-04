#include<bits/stdc++.h>
using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b;
    if (!a && !b) {
        cout << "Not a moose";
        return 0;
    }
    if (a!=b) {
        c=max(a,b)*2;
        cout << "Odd ";
    } else {
        c = a+b;
        cout << "Even ";
    }
    cout << c;

}
