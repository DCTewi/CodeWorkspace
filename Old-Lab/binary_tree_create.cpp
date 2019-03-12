#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	Node():data(0), left_child(NULL), right_child(NULL) {}
	
	int data;
	Node *left_child, *right_child;
	
};

Node *root;

Node* newnode()
{
	return new Node();
}

void remove_tree(Node *u)
{
	if (!u) return ;
	remove_tree(u->left_child);
	remove_tree(u->right_child);

	delete u;
	return ;
}

bool bfs()
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* u = q.front();
		q.pop();

		if (u->left_child) q.push(u->left_child);
		if (u->right_child) q.push(u->right_child);
	}
}

int main(int argc, char const *argv[])
{
	return 0;
}