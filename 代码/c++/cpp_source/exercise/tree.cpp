#include<iostream>
using namespace std;
typedef struct BiTNode {
	struct BiTNode* lchild;
	struct BiTNode* rchild;
	int data;
}BiTNode, * BiTree;

BiTree creatTree(int* in, int* post, int n) {
	if (n <= 0)
		return NULL;
	else {
		BiTree T = new BiTNode;
		T->data = post[n - 1];
		int i;
		for (i = 0; i < n; i++) {
			if (post[n - 1] == in[i])
				break;
		}
		T->lchild = creatTree(in, post, i);
		T->rchild = creatTree(in + i + 1, post + i, n - i - 1);
		return T;
	}
}
void preorderTraversal(BiTree BT) {
	if (BT) {
		cout << " " << BT->data;
		preorderTraversal(BT->lchild);
		preorderTraversal(BT->rchild);
	}
}
int main() {
	int n;
	cin >> n;
	int in[32];
	int post[32];
	BiTree T;
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	T = creatTree(in, post, n);
	cout << "Preorder:";
	preorderTraversal(T);
	return 0;
}