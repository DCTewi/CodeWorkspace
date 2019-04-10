#include <bits/stdc++.h>
using namespace std;

const int MAX = 20 + 5;
string word[MAX], head;
int used[MAX];
int ans = 0, n = 0;

bool check(string a, string b, int k)
{
    int len = a.size();
    for (int i = 0; i < k; i++)
    {
        if (a[len - k + i] != b[i]) return false;
    }
    return true;
}

void add(string &a, string b, int k)
{
    int len = b.size();
    for (int i = k; i < len; i++)
    {
        a += b[i];
    }
    return ;
}

void dfs(string now)
{
    ans = max(ans, (int)now.size());
    
    for (int i = 1; i <= n; i++)
    {
        if(used[i] < 2)
        {
            int len = word[i].size();
            for (int k = 1; k <= len; k++)
            {
                if (check(now, word[i], k))
                {
                    string temp = now;
                    add(temp, word[i], k);
                    if (temp != now)
                    {
                        used[i]++;
                        dfs(temp);
                        used[i]--;
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin>>word[i];
    }
    cin>>head;
    
    dfs(head);
    
    printf("%d\n", ans);
    
    return 0;
}

