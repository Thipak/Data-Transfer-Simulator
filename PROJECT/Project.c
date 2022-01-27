#include<stdio.h>
#include<stdlib.h>

int length;		//length of input
int n;			//key
int k;
int t;

int ASCII(char ch)
{
	return ch;
}

char ASCIInot(int z)
{
	return (char)(z);
}



int swap(int* a,int k)
{
	int temp=*a;
	*a=k;
	return temp;
}

void display(char* ch)
{
	printf("%s\n",ch);
	//	printf("%s",ar);
	
}
//encryption done




char* encrypt(char ch[])
{
	//STEP 1:Convert to equivalent ASCII code
	int *av=(int *)malloc(sizeof(int)*length);
	if(av==NULL)		exit(0);
	
	int i;
	for(i=0;i<length;i++)
	{
		*(av+i)=ASCII(ch[i]);
	}
	
	//STEP 2:Shuffle
	for(i=0;i<length;i=i+n)
	{
		int l=i;	//lowerbound
		int u=i+n-1;//upperbound
		int k=*(av+l);
		while(l!=u)
		{
			k=swap(av+u,k);
			int t=u;
			if(u<l)
				u=l-1;
			else
				u=l+1;
			l=t;		
		}
		*(av+i)=k;
	}
	//doneh
	
	//STEP 3:Encrypt

	k=rand()%10;
	t=(126/k)+2;
	for(i=0;i<length;i++)
	{
		
		
		int x=t*k+(126-*(av+i));
		*(av+i)=x-2*k+2;
	}
	//doneh
	
	//STEP 4:Convert back to character
	
	for(i=0;i<length;i++)
	{
		ch[i]=ASCIInot(*(av+i));
	}

	display(ch);
	return ch;
}



//decryption
char* decrypt(char* ch)
{
	//STEP 1:Convert to equivalent number
	int *av=(int *)malloc(sizeof(int)*length);
	if(av==NULL)
	{
		printf("Malloc failed");
		exit(0);
	}
	int i;
	for(i=0;i<length;i++)
	{
		*(av+i)=ASCII(ch[i]);
	}
	
	//STEP 2:Decrypt
	for(i=0;i<length;i++)
	{
		int x=*(av+i)-2+2*k;
		*(av+i)=t*k+126-x;
	}
	//STEP 3:Unshuffle
	//STEP 2:Shuffle
	for(i=0;i<length;i=i+n)
	{
		int l=i;	//lowerbound
		int u=i+n-1;//upperbound
		int k=*(av+u);
		while(l!=u)
		{
			k=swap(av+l,k);
			int t=l;
			if(l<u)
				l=u-1;
			else
				l=u+1;
			u=t;		
		}
		*(av+i+n-1)=k;
	}
	
	//STEP 4:Convert to characters
		for(i=0;i<length;i++)
	{
		ch[i]=ASCIInot(*(av+i));
	}
	display(ch);
	return ch;
}


void main()
{
	//input
	char ch[]="THIPAK";
	length=sizeof(ch)/sizeof(char)-1;
	
	//assigning key
	while(1)
	{
	srand(time(0));
	n=rand()%length;
	if(length%n==0&&n>=1)
		break;
	printf("%d",n);
	}
	
	printf("%d\n",n);
		//done
	//Encryption
	char chr[length];
	*chr=encrypt(ch);
	display(ch);
	
	*ch=decrypt(ch);
	
	//display
	
}


