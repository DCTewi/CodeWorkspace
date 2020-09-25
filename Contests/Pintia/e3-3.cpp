#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> T read()
{
    T x = 0; int ch = getchar(), w = 0;
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

int main()
{
    string str;
    cin >> str;

    sort(str.begin(), str.end());

    do
    {
        printf("%s\n", str.c_str());
    }
    while (next_permutation(str.begin(), str.end()));
}