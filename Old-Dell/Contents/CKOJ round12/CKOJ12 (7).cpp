#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
long long mod=10000000;
long long pow4(long long a,long long b,long long c){
  	long long int r=1,base=a%c;
  	while(b!=0){
   		if(b&1){
		    long long x1=0,x2=base,x3=r;
		    while(x2!=0){
		   		x1+=x3*(x2%10);
		   		x1%=c;
		   		x2/=10;
		   		x3*=10;
		   		x3%=c;
		    }
		    r=x1;
		    r%=c;
		}
		long long x1=0,x2=base,x3=base;
		while(x2!=0){
		   	x1+=x3*(x2%10);
		   	x1%=c;
		   	x2/=10;
		   	x3*=10;
		   	x3%=c;
		}
   		base=x1;
   		base%=c;
   		b>>=1;
  	}
  return r%c;
}
int main(){
	int T;
	cin>>T;
	for(int q=0;q<T;q++){
		string s1,s2;
		long long a=0,c,ans=1;
		cin>>s1>>s2>>c;
		for(int x1=0;x1<s1.length();x1++){
			a*=10;
			a+=(s1[x1]-'0');
			a%=c;
		}
		for(int x1=0;x1<s2.length();x1++){
			long long ans1=pow4(a,s2[x1]-'0',c);
			ans=pow4(ans,10,c);
			long long xx1=0,xx2=ans1,xx3=ans;
		    while(xx2!=0){
		   		xx1+=xx3*(xx2%10);
		   		xx1%=c;
		   		xx2/=10;
		   		xx3*=10;
		   		xx3%=c;
		    }
		    ans=xx1;
		}
		cout<<ans<<endl;
	}
    return 0;
}

string&   replace_all_distinct(string&   str,const   string&   old_value,const   string&   new_value)
{
    for(string::size_type   pos(0);   pos!=string::npos;   pos+=new_value.length())   {
        if(   (pos=str.find(old_value,pos))!=string::npos   )
            str.replace(pos,old_value.length(),new_value);
        else   break;
    }
    return   str;
}
