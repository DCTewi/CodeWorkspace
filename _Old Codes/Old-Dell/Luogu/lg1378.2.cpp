#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
const int PI = 3.1415926;
using namespace std;
int n; //n个油滴 
int X1,Y1,X2,Y2;//矩形区域 
double ans;//覆盖的最大面积 

int x[10],y[10];//编号为 [i] 的油滴的坐标 
double r[10];   //编号为 [i] 的油滴的半径 

bool b[10]; //记录此油滴是否已经扩展 

//三个函数，感觉这样写可能会比 C++ 自带的快一些 
inline double Max(double a,double b){
    return a > b ? a : b ;
}
inline double Min(double a,double b){
    return a < b ? a : b ;
}
inline int Abs(int a,int b){
    if(a>b)
        return a-b;
    return b-a;
}
void find(int now,double sum){//now 为将要搜第几个油滴 ,sum为现在已经扩展的面积 
    if(now==n+1){//都搜完了
        ans=Max(ans,sum);//更新答案。 
        return ;
    }

    for(int i=1;i<=n;i++)
        if(!b[i]){//若这个油滴还没被扩展 

            int flag = 0;
            for (int j = 0; j < n; j++)
            {
                if (b[j] && r[j] >= sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])))
                {
                    flag = 1;
                    b[i] = 1;
                    find(now + 1, sum);
                    b[i] = 0;
                }
            }
            if (flag)
            {
                continue;
            }

            b[i]=1;

            r[i] = Min(Abs(x[i], X1), Abs(x[i], X2));
            r[i] = Min(r[i], (double)Min(Abs(y[i], Y1), Abs(y[i], Y2)));

            for (int j = 1; j <= n; j++)
            {
                if (i != j && b[j])
                {
                    double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                    r[i] = min(r[i], d - r[j]);
                }
            }

            //find(now+1,sum+pi*r[i]*r[i]);//寻找下一个油滴
            find(now + 1, sum + PI * r[i] * r[i]);

            r[i]=0;//回溯 
            b[i]=0; 
        }

}
inline int read()
{
    int x = 0, w = 0; char ch = getchar();
    while (!isdigit(ch))
    {
        w |= ch == '-'; ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();
    }
    return (w? -x: x);
}
inline int readHigh()
{
    return read() + 1000;
}

int main()
{
    n = read();
    X1 = readHigh(); Y1 = readHigh();
    X2 = readHigh(); Y2 = readHigh();
    for (int i = 1; i <= n; i++)
    {
        x[i] = readHigh();
        y[i] = readHigh();
    }

    find(1, 0.0L);

    ans = Abs(X1, X2) * Abs(Y1, Y2) - ans;

    cout<<(int)(ans + 0.5)<<endl;

    return 0;
}