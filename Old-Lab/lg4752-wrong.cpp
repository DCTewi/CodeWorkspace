#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 5;
int n, m;
ll a[MAX], b[MAX];
bool erased_a[MAX], erased_b[MAX];

bool isPrime(ll n)
{
	if (n < 2) return false;
	for (int i = 2; i < sqrt(n); i++)
	{
		if (! (n % i)) return false;
	}
	return true;
}

bool greaterr(ll a, ll b)
{
	return a < b;
}

long long int readll()
{
	ll n = 0;
	char ch = getchar();
	bool neg = false;
	while (!isdigit(ch))
	{
		neg = (ch == '-' || neg)? 1: 0;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		n = (n << 3) + (n << 1) + (ch - '0');
		ch = getchar();
	}
	return neg? -n: n;
}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T--)
	{
		//Initialization
		memset(erased_a, 0, sizeof(erased_a));
		memset(erased_b, 0, sizeof(erased_b));

		//PreCalculation
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			a[i] = readll();
		}
		for (int i = 0; i < m; i++)
		{
			b[i] = readll();
		}
		#ifdef TEWILOCAL
			cout<<"\nBefore sort:\n";
			for (int i = 0; i < n; i++)
			{
				cout<<a[i]<<" ";
			}cout<<endl;
			for (int i =0; i < m; i++)
			{
				cout<<b[i]<<" ";
			}cout<<endl<<endl;
		#endif
		sort(a, a + n - 1, greaterr);
		sort(b, b + m - 1, greaterr);

		#ifdef TEWILOCAL
			cout<<"After sort:\n";
			for (int i = 0; i < n; i++)
			{
				cout<<a[i]<<" ";
			}cout<<endl;
			for (int i =0; i < m; i++)
			{
				cout<<b[i]<<" ";
			}cout<<endl<<endl;
		#endif

		//Calculation - Check common numbers
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (erased_b[j]) continue;
				if (a[i] < b[j]) break;
				if (a[i] == b[i])
				{
					erased_b[j] = 1;
					erased_a[i] = 1;
					#ifdef TEWILOCAL
						cout<<a[i]<<"is kicked\n";
					#endif
					break;
				}
			}
		}

		//Calculation - Wonder every number left is a prime number
		int left_a = 0;
		bool printNO = false;
		for (int i = 0; i < n; i++)
		{
			if (erased_a[i])//Next if this number've been kicked
			{
				#ifdef TEWILOCAL
					cout<<a[i]<<"is kicked, so skip it\n";
				#endif
				continue;
			} 
			if (a[i] != 1)//Number the number of left numbers
			{
				 left_a++;
				 #ifdef TEWILOCAL
				 	cout<<a[i]<<"is added\n";
				 #endif
			}
			if (left_a > 1)
			{
				#ifdef TEWILOCAL
					cout<<a[i]<<"is the 2nd number\n";
				#endif
				printNO = true;
				break;
			} //If the number of left numbes is bigger than 1 then print NO
			if (!isPrime(a[i])) //If the number left isn't a prime number then print NO
			{
				#ifdef TEWILOCAL
					cout<<a[i]<<"isn't a prime number\n";
				#endif
				printNO = true;
				break;
			}
		}
		if (printNO)
		{
			puts("NO");
		}
		else 
		{
			puts("YES");
		}
	}
	return 0;
}