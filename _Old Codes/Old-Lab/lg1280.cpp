#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
int n, k, num = 1;
int cnt[MAXN], dp[MAXN];

class Task
{
public:
    Task(){}
    Task(int p, int t)
    {
        this->p = p;
        this->t = t;
    }

    int p, t;

    bool operator<(const Task& other) const
    {
        return this->p > other.p;
    }
} task[MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        int p, t;
        scanf("%d%d", &p, &t);

        task[i] = Task(p, t);
        cnt[task[i].p]++;
    }

    sort(task + 1, task + k + 1, [](Task a, Task b)->bool {return a < b;});

    for (int i = n; i > 0; i--)
    {
        if (!cnt[i])
        {
            dp[i] = dp[i + 1] + 1;
        }
        else
        {
            for (int j = 0; j < cnt[i]; j++)
            {
                dp[i] = max(dp[i], dp[i + task[num].t]);
                num++;
            }
        }
    }

    printf("%d\n", dp[1]);

    return 0;
}
