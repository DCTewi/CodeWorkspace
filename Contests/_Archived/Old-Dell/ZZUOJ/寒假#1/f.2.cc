#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int t; cin>>t;
    while (t--)
    {
        map<int, int> list; //number->amount
        //in
        int n; cin>>n;
        for (int i = 0; i < n; i++)
        {
            int tmp; cin>>tmp;
            list[tmp]++;
        }
        //bianli
        int flag1 = 0, ans = 0;
        for (auto it = list.begin(); it != list.end(); it++)
        {
            int key = it->first;
            if (key == 1)
            {
                flag1 = 1;
                break;
            }

            int flagc = 0, part = 0;
            for (int i = 2; i * i <= key; i++) //every yinzi
            {
                if (key % i == 0)
                {
                    if (list.count(i))
                    {
                        list[i] += list[key];
                        it--; list.erase(key);
                        flagc = 1;
                        break;
                    }
                    else if (list.count(key / i))
                    {
                        part = key / i;
                    }
                }
            }
            if (!flagc)
            {
                if (part)
                {
                    list[part] += list[key];
                    it--; list.erase(key);
                }
            }
        }
        //end
        if (flag1) //full of 1
        {
            cout<<n<<endl;
        }
        else //other
        {
            int ans = 0;
            for (auto it : list)
            {
                ans += it.first * it.second;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}