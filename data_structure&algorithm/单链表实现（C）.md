```c
#include<stdio.h>
#include<stdlib.h>

struct link *AppendNode(struct link *head);		//整链表节点数据
void DisplyNode(struct link *head);		//显示链表数据
void DeleteMemory(struct link *head);		//删除链表
struct link *DeleteNode(struct link *head, int nodeData);		//删除某个节点


struct link
{
	int data;
	struct link *next;
};

int main()
{
	int i = 0,j=0;
	char c;
	struct link *head = NULL;		//创建一个表头指针head
	
	
	printf("Do you want to append a new node(Y/N)?");
	scanf(" %c", &c);
	while (c == 'y' || c == 'Y')
	{
		head = AppendNode(head);
		DisplyNode(head);
		printf("Do you want to append a new node(Y/N)?");
		scanf(" %c", &c);
		i++;
	}

	
	printf("Do you want to deleted a new node(Y/N)?");
	scanf(" %c", &c);
	while (c == 'y' || c == 'Y')
	{
		int n;
		printf("Please input data:");		//用户输入要删除的节点数据
		scanf("%d", &n);
		j++;
		head = DeleteNode(head,n);		//返回已经删除节点的链表头节点
		DisplyNode(head);
		printf("Do you want to continue deleted a new node(Y/N)?");		//让用户觉得是否继续删除
		scanf(" %c", &c);		
	}
	printf("%d new nodes have been apended!\n", i-j);
	DeleteMemory(head);
	return 0;
}

struct link *AppendNode(struct link *head)
{
	struct link *p = NULL, *pr = head;
	int data;

	p = (struct link*)malloc(sizeof(struct link));		//指针p指向新建节点内存块
	if (p == NULL)		//如果没有成功申请内存空间，结束程序
	{
		printf("No enough memory to allocate!\n");
		exit(0);
	}
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		while (pr->next != NULL)
		{
			pr = pr->next;
		}
		pr->next = p;
	}
	printf("Input node data:");
	scanf("%d", &data);
	p->data = data;
	p->next = NULL;
	return head;		//返回链表头指针
}

void DisplyNode(struct link *head)
{
	struct link *p = head;
	int j = 1;
	while (p != NULL)
	{
		printf("%5d%10d\n", j, p->data);
		p = p->next;		//让节点指针等于节点next指针，即指向下一个节点
		j++;
	}
}

void DeleteMemory(struct link *head)
{
	struct link *p = head, *pr = NULL;
	while (p != NULL)		//逐个释放节点内存
	{
		pr = p;		//pr指向当前节点
		p = p->next;	//p指向下一个节点
		free(pr);		//释放当前节点内存

	}
}

struct link *DeleteNode(struct link *head, int nodeData)
{
	struct link *p = head, *pr = head;
	if (head == NULL)		//如果是空链表就退出程序
	{
		printf("Linked Table is empty!\n");
		return(head);
	}
	while (nodeData!=p->data&&p->next!=NULL)
	{
		pr = p;
		p = p->next;
	}		//这个循环的pr指向对应数据nodeData==p->data的节点的前一节点
	if (nodeData == p->data)
	{
		if (p == head)		//如果删除的是头节点，头指针head指向删除节点的后驱节点
		{
			head = p->next;
		}
		else
		{
			pr->next = p->next;			//当前节点的前驱节点的next指针指向后驱节点
		}
		free(p);		//释放删除节点的内存
	}
	else
	{
		printf("This Node has not been found!\n");
	}
	
	return head;
}
```