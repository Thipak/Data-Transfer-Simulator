#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int a[2];
}node;

void main()
{
	node *ab=(node *)malloc(sizeof(node)*3);
	*(ab+1)=1;
	printf("%d%d",*(ab+1),*(++ab));
}
