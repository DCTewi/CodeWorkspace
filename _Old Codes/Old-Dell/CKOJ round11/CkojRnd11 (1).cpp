#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
const int MAX = 2e5 + 5;
string str;
char ch[MAX];
int px, py;

void getBorder();

int main()
{
    cin>>str;

    for (unsigned int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'x') px = i + 1;
        if (str[i] == 'y') py = i + 1;

        ch[i + 1] = str[i];
    }

    getBorder();

    return 0;
}

void getBorder()
{
    int lx, rx;
    for (lx = px - 1, rx = px + 1; ch[lx] == '(' && ch[rx] == ')'; lx--, rx++);
    int ly, ry;
    for (ly = py - 1, ry = py + 1; ch[ly] == '(' && ch[ry] == ')'; ly--, ry++);

    //cout<<"1234567890\n";
    //printf("lx=%d, rx=%d, ly=%d, ry=%d\n", lx, rx, ly, ry);

    if (ch[lx] == '(' && ch[rx] == 'y')
    {
        cout<<"YES"<<endl;
        return;
    }
    if (ch[lx] == '(' && rx == ly + 1 && lx != 0)
    {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
    return;
}
