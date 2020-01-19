#include <bits/stdc++.h>
using namespace std;
int n;
int str[305], num[305], sp[305][305];
int p[305][305];
int a[5][5], c[5];
long long sum;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        str[num[i]]++;
        p[i][1] = str[num[i]] - 1;
        p[i][2] = i - 1 - p[i][1];
    }
    //cout<<"qqqq"<<endl;
    for (int i = n; i >= 1; i--)
    {
        p[i][3] = str[num[i]] - 1 - p[i][1];
        p[i][4] = n - 1 - p[i][1] - p[i][2] - p[i][3];
    }
    //for(int i=1;i<=n;i++)	cout<<p[i][3]<<"   "<<p[i][4]<<endl;
    //cout<<"qqqq"<<endl;
    for (int i = 1; i <= 4; i++)
        cin >> c[i];
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if (c[i] == c[j])
                a[i][j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (num[i] == num[j])
                sp[i][j] = 1;
    for (int i = 1; i <= n - 3; i++)
    {
        for (int j = i + 1; j <= n - 2; j++)
        {
            for (int s = j + 1; s <= n - 1; s++)
            {
                if (a[1][2] == sp[i][j] && a[1][3] == sp[i][s] && a[2][3] == sp[j][s])
                {
                    if (a[3][4])
                        sum += p[s][3];
                    else
                    {

                        //cout<<"aaa"<<sum<<endl;
                        if (a[2][4])
                        {
                            for (int w = s + 1; w <= n; w++)
                            {
                                if (sp[w][j])
                                {
                                    sum += p[w][3] + 1;
                                    break;
                                }
                            }
                            //cout<<"bbb"<<sum<<endl;
                        }
                        else
                        {
                            if (a[1][4])
                            {

                                for (int w = s + 1; w <= n; w++)
                                {
                                    if (sp[w][i])
                                    {
                                        sum += p[w][3] + 1;
                                        break;
                                    }
                                }
                                //cout<<"ccc"<<sum<<endl;
                            }
                            else
                            {
                                for (int w = s + 1; w <= n; w++)
                                {
                                    if (num[i] != num[w] && num[j] != num[w] && num[s] != num[w])
                                        sum++;
                                }
                                //cout<<"ddd"<<sum<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}