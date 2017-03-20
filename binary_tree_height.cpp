#include<iostream>
#include<queue>
using namespace std;
struct BTNode{
	int val;
	BTNode* left;
	BTNode* right;
	BTNode (int a):val(a),left(NULL),right(NULL){}
};
int Depth(BTNode *root)
{
	if(root == NULL)
		return 0;

	int visitNum = 0;   //
	int popNum = 0;    //
	int levels[100];

	queue<BTNode*> q;
	levels[1] = 1;
	visitNum += 1;
	q.push(root);
	while(!q.empty())
	{
	
		int pre = popNum +1;            // 当前出队列的序号
		BTNode* Node = q.front();
		if(Node->left != NULL)
			{
				int posL = ++visitNum;
				q.push(Node->left); 
				levels[posL] = levels[pre] + 1;        //  上一层高度 + 1
		}
		if(Node->right != NULL)
			{
				int posR = ++visitNum;
				q.push(Node->right);
				levels[posR] = levels[pre] + 1;       //   上一层高度 + 1
		}
		q.pop();
		popNum +=1;
	}
	
	return levels[visitNum];
}
int main()
{
	BTNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(4);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t3.right = &t5;
	t2.right = &t6;
	int Dp = Depth(&t1);
	cout<<"Depth = "<<Dp<<endl;
	system("pause");
	return Dp;
	
}