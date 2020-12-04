#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
vector<int> digit;
hash<string> hashe;
set<size_t> used;

template <class T>
T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

int flag = 0;
void dfs(int len, string &s)
{
    puts("Yeeee");
    if (flag) return;
    if (used.size() >= k)
    {
        printf("%s\n", s.c_str());
        flag = 1;
        return;
    }

    for (int i = 0; i < m; i++)
    {
        string news = s + (char)('0' + digit[i]);
        int slen = static_cast<int>(news.size());
        if (slen >= n)
        {
            size_t shash = hashe(news);
            if (!used.count(shash))
            {
                used.insert(shash);
                dfs(len + 1, news);
            }
        }

    }
}

int main()
{
    n = read<int>(), m = read<int>(), k = read<int>();
    digit = vector<int>(m);
    for (int i = 0; i < m; i++)
    {
        digit[i] = read<int>();
    }
    sort(digit.begin(), digit.end());

    string ans;
    dfs(0, ans);

    return 0;
}
