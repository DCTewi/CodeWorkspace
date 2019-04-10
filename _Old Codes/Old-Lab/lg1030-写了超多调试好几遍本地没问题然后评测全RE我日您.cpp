#include <bits/stdc++.h>
using namespace std;

string inn, post;
int size = 0, top = 0;
char rooted[10];

bool isRooted(char ch)
{
	for (int i = 0; i < top; i++)
	{
		if (rooted[i] == ch)
		{
			return true;
		}
	}
	return false;
}

void getPre(int rootnow)
{
	printf("%c", post[rootnow]);
	rooted[top++] = post[rootnow];
	int inplc = inn.find(post[rootnow]);

	int l = -1, r = -1;
	for (int i = inplc + 1; ; i++)
	{
		if (isRooted(inn[i]))
		{
			r = i - 1;
			break;
		}
	}
	for (int i = inplc - 1; ; i--)
	{
		if (isRooted(inn[i]))
		{
			l = i + 1;
			break;
		}
	}

	if (r - l == 0) return ;

	string left, right;
	for (int i = l; i < inplc; i++)
	{
		left += inn[i];
	}
	for (int i = post.size() - 1; i >= 0; i--)
	{
		if (!isRooted(post[i]) && left.find(post[i]) != string::npos)
		{
			getPre(i);
			break;
		}
	}

	for (int i = inplc + 1; i <= r; i++)
	{
		right += inn[i];
	}
	for (int i = post.size() - 1; i >= 0; i--)
	{
		if (!isRooted(post[i]) && right.find(post[i]) != string::npos)
		{
			getPre(i);
			break;
		}
	}

	return;
}

int main(int argc, char const *argv[])
{
	
	cin>>inn>>post;

	getPre(post.size() - 1);

	printf("\n");

	return 0;
}