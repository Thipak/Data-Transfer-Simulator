#include<stdio.h>
#include<math.h>

int length;

int* ASCII(char ch[])
{
	int av[length];		//stores the ASCII equivalent of each number
	int i=0;
	for(;i<length;i++)
		av[i]=ch[i];
	return av;
}


void encrypt(char ch[])
{
	//STEP 1:Convert to equivalent ASCII code
	int *av=(int *)malloc(sizeof(int)*length);
	av=ASCII(ch);
	
	//encrypting number by number
	char *en=(char *)malloc(sizeof(char)*3*length);	store each ascii
	int i=0;
	for(;i<length;i++)
	{
		

}
void main()
{
	//input
	char ch[]="THIPAK";
	length=sizeof(ch)/sizeof(char);
	
	//Encryption
	encrypt(ch);
}
