#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <deque>
#include <bitset>
using namespace std;
typedef long long ll;

int solve()
{
    set<string> s;
    int n; scanf("%d", &n);
    string a, b, ab;
    string res;
    cin >> a >> b >> res;
    int step (0);
    while (true)
    {
        step++;
        for (int i = 0; i < n; i++) ab += b[i], ab+= a[i];
        if (s.find(ab) != s.end()) return -1;
        else
        {
            if (ab == res) return step;
            else
            {
                a = ab.substr(0, n);
                b = ab.substr(n, n);
                s.insert(ab);
                ab.clear();
            }
        }
        
    }
}

int main()
{
    int _T; scanf("%d", &_T);
    for (int T = 1; T <= _T; T++)
    {
        printf("%d %d\n", T, solve());
    }
    return 0;
}