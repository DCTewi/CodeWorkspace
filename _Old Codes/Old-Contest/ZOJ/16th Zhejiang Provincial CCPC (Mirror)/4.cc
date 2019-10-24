// k
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e6 + 5;
ll nxt[MAXN];

void getNext(string s/*, int *nxt */)
{
	nxt[0] = -1; // -1 表示前后缀不存在
	int k = -1; // 模式串的匹配游标
	for (int i = 1; i < s.size(); i++)
	{
		while (k != -1 && s[k + 1] != s[i]) k = nxt[k];
		//下一个数失配则更新本位的失配指针，k == -1则触顶
		if (s[k + 1] == s[i]) k++;
		nxt[i] = k;
	}
}


int main()
{
    ios::sync_with_stdio(false);

    int T; cin >> T;
    while (T--)
    {
        string a, b; cin >> a >> b;
        getNext(a + b);
        for (int i = 0; i < (a + b).size(); i++)
        {
            cout<<nxt[i]<<" ";
        }
        cout<<"\n";
        getNext(b + a);
        for (int i = 0; i < (a + b).size(); i++)
        {
            cout<<nxt[i]<<" ";
        }
        cout<<"\n";
    }

	return 0;
}