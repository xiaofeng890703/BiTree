#include <stdio.h>
#include <stdlib.h> 
#include <stack>
#include <queue>
using namespace std;
typedef struct BiNode{
	char data;
	struct BiNode *lchild,*rchild;
}BiNode,*BiTree;
//struct BiNode *BiTree;
  
struct BiNode *Create_BiNode() 
{
 	char data;
 	struct BiNode *T;
 	scanf("%c",&data);
 	if(data == '#')/*#表示空树*/ 
 	{
	 	T = NULL;
	}
	else
	{
		T = (struct BiNode*)malloc(sizeof(struct BiNode));
		T->data = data;
		T->lchild = Create_BiNode();
		T->rchild = Create_BiNode();
	}
	return T;
}

void print_node(struct BiNode *T)
{
	char data;
	data = T->data;
	if(data != '#')
	{
		printf("%c ",data);
	}	
}

void PreOrder(struct BiNode *T)
{
	if (T != NULL)
	{
		print_node(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
	
}

void InOrder(struct BiNode *T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		print_node(T);		
		InOrder(T->rchild);
	}
}

void PostOrder(struct BiNode *T)
{
	if(T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		print_node(T);
	} 
}
void PreOrder2(struct BiNode *T) 
{
	stack<struct BiNode *> stack;
	struct BiNode *p = T;
	while(p || !stack.empty())
	{
		if(p != NULL)
		{
			stack.push(p);
			printf("%c ",p->data);
			p = p->lchild;
		}
		else
		{
			p = stack.top();
			stack.pop();
			p = p->rchild;
		}
	}
}
void InOrder2(struct BiNode *T)
{
	stack<struct BiNode *> stack;
	struct BiNode *p = T;
	while(p || !stack.empty())
	{
		if(p != NULL)
		{
			stack.push(p);
			p = p->lchild;
		}
		else
		{
			p = stack.top();
			printf("%c ",p->data);
			stack.pop();
			p = p->rchild;
		}
	}	
}
void LevelOrder(struct BiNode *T)
{
	struct BiNode *p = T;
	queue<struct BiNode *> queue;
	queue.push(p);
	while(!queue.empty())
	{
		p = queue.front();
		printf("%c ",p->data);
		queue.pop();
		if(p->lchild != NULL)
		{
			queue.push(p->lchild);
		}
		if(p->rchild != NULL)
		{
			queue.push(p->rchild);
		}
	}
}
int main()
{
	struct BiNode *T;
	T = Create_BiNode();
	printf("递归前序遍历\n"); 
	PreOrder(T);
	printf("\n");
	printf("递归中序遍历\n"); 
	InOrder(T);
	printf("\n");
	printf("递归后序遍历\n"); 
	PostOrder(T);
	printf("\n"); 
	printf("非递归前序遍历\n");
	PreOrder2(T); 
	printf("\n");
	printf("非递归中序遍历\n");
	InOrder2(T); 
	printf("\n");
	printf("层序遍历\n");
	LevelOrder(T); 
	printf("\n");
}
