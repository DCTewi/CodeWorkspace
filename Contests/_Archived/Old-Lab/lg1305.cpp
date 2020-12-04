#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node(){}
	Node(char lc, char rc)
	{
		this->lchild = lc;
		this->rchild = rc;

	}

	char lchild, rchild;
};

map<char, Node> tree;
int have_father[30];

void preOrd(char root)
{
	printf("%c", root);

	if (tree[root].lchild != 0)
	{
		//printf("'s lchild is %c\n", tree[root].lchild);
		preOrd(tree[root].lchild);
	}
	if (tree[root].rchild != 0)
	{
		//printf("'s rchild is %c\n", tree[root].rchild);
		preOrd(tree[root].rchild);
	}
	return;
}

int main(int argc, char const *argv[])
{
	memset(have_father, 0, sizeof(have_father));
	int n; cin>>n;
	for (int i = 0; i < n; i++)
	{
		string data; cin>>data;
		tree[data[0]] = Node((data[1] != '*')? data[1]: 0, (data[2] != '*')? data[2]: 0);
		if (data[1] != '*') have_father[data[1] - 'a'] = 1;
		if (data[2] != '*') have_father[data[2] - 'a'] = 1;
	}

	char root = 0;
	for (int i = 0; i < 27; i++)
	{
		if (tree.count((char)(i + 'a')) && have_father[i] == 0)
		{
			root = i +'a';
			break;
		}
	}

	preOrd(root);

	return 0;
}
