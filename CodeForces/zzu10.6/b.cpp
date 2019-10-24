#include<bits/stdc++.h>
using namespace std;
struct node
{
    char ch;
    int id;
    bool qk;
}no[55];
int trans(char ch)
{
    if(ch>='a'&&ch<='z')return ch-'a';
    else    return ch-'A'+26;
}
int main()
{
   freopen("boolean.in","r",stdin);
   freopen("boolean.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<53;i++)
        no[i].id = -1;
    for(int i=0;i<s.length();i++)
    {
        int tmp;
        if(isalpha(s[i]))
        {
            tmp = trans(s[i]);
            if(i==0)
            {
                no[tmp].id++;
                no[tmp].qk = 1;
            }
            else
            {
                if(no[tmp].id<1)
                {
                    if(no[tmp].id==-1)
                    {
                        if(s[i-1]=='~')
                        {
                            no[tmp].qk=0;
                            no[tmp].id++;
                        }
                        else
                        {
                            no[tmp].qk=1;
                            no[tmp].id++;
                        }
                    }
                    if(no[tmp].id==0)
                    {
                         if(s[i-1]=='~'&&no[tmp].qk==1)
                        {
                            no[tmp].id++;
                        }
                        else if(s[i-1]=='|'&&no[tmp].qk==0)
                        {
                            no[tmp].id++;
                        }
                    }
                }
                else continue;
            }
        }
    }
    long long ans=0;
    int sum=0;bool flag=0;
    for(int i=0;i<52;i++)
    {
        if(no[i].id!=-1)
        {
            sum++;
        }
        if(no[i].id==1)
            flag=1;
    }
    if(flag)ans=pow(2,sum);
    else    ans=pow(2,sum)-1;
    cout<<ans<<endl;
}
