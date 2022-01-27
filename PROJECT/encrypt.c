#include<stdio.h> 
#include<math.h> 
  
// Returns gcd of a and b 
int gcd(int a, int h) 
{ 
    int temp; 
    while (1) 
    { 
        temp = a%h; 
        if (temp == 0) 
          return h; 
        a = h; 
        h = temp; 
    } 
} 
  
int* toEqNum(char ch[])
{
	int av[length];		//stores the ASCII equivalent of each number
	int i=0;
	for(;i<length;i++)
	{
		av[i]=ch[i];
		if(av[i]>=32&&av[i]<=126)
		{
			
		}		
	return av;
}

encrypt()
{
    // Encryption c = (msg ^ e) % n 
    double c = pow(msg, e); 
    c = fmod(c, n); 
    printf("\nEncrypted data = %lf", c); 
  
    // Decryption m = (c ^ d) % n 
    double m = pow(c, d); 
    m = fmod(m, n); 
    printf("\nOriginal Message Sent = %lf", m); 
}
  
void main() 
{ 	
	//two prime numbers
    int p = 3; 
    int q = 7; 
  		
    int n = p*q; 
  	
    int e = 2; 
    double phi = (p-1)*(q-1); 
    while (e < phi) 
    { 
        if (gcd(e, phi)==1) 
            break; 
        else
            e++; 
    } 
        
	
    int k = 2; 
    int d = (1 + (k*phi))/e; 
  	
    // Message to be encrypted 
    char ch[]="THIPAK";
	length=sizeof(ch)/sizeof(char);
    int *av=(int *)malloc(sizeof(int)*length);
	av=toEqNum(ch); 
  	
  	char *en=(char *)malloc(sizeof(char)*3*length);	store each ascii
	int i=0;
	for(;i<length;i++)
	{
		
	}

    return 0; 
} 
// This code 
