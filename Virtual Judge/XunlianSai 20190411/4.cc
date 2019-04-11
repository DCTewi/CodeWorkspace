//C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;

vector<string> v; 
priority_queue<int> Q1;
priority_queue<int,vector<int>,greater<int>> Q2;
int Get(string &s){
    return stoi(s);
}
int cnt = 0;
void ju(){
    while(Q2.size() > (cnt+1)/2){
                    Q1.push(Q2.top());
                    Q2.pop();
                }
    while(Q2.size() < (cnt+1)/2){
            Q2.push(Q1.top());
            Q1.pop();
    }
    while(!Q1.empty()&&!Q2.empty()&&Q1.top() > Q2.top()){
        int x = Q1.top();Q1.pop();
        int y = Q2.top();Q2.pop();
        Q1.push(y);
        Q2.push(x);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    int flag = 0;
   
    while (cin>>s)
    {
        if (s != "#")
        {
            if (flag)
            {
                cout<<s<<endl;
                flag--;
            }
            else
            {
                int t = Get(s);
                Q2.push(t);
                cnt++;
                ju();
            }
        }
        else if (s == "#")
        {
            if (v.empty())
            {
                flag++;
            }
            else
            {
               if(!Q2.empty()){
                cout<<Q2.top()<<endl;
                cnt--;
                Q2.pop();
                ju();
               }
               
            }
        }
    }
    
    return 0;
}
