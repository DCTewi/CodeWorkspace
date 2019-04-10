// code is from http://blog.csdn.net/dark_scope/article/details/8880547
#include <cstdio>
using namespace std;

const int MAX = 1e4 + 5;
int line[MAX][MAX];
int used[MAX], girl[MAX];

bool find(int x){  
    int i,j;  
    for (j=1;j<=m;j++){    //扫描每个妹子  
        if (line[x][j]==true && used[j]==false)        
        //如果有暧昧并且还没有标记过(这里标记的意思是这次查找曾试图改变过该妹子的归属问题，但是没有成功，所以就不用瞎费工夫了）  
        {  
            used[j]=1;  
            if (girl[j]==0 || find(girl[j])) {   
                //名花无主或者能腾出个位置来，这里使用递归  
                girl[j]=x;  
                return true;  
            }  
        }  
    }  
    return false;  
} 

int main()
{
	for (i=1;i<=n;i++)  
{  
    memset(used,0,sizeof(used));    //这个在每一步中清空  
    if find(i) all+=1;  
} 
	return 0;
}
