#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int length; //length of input
int n;		//key1	(a random number between 1 to length) every n elements gets shuffled)
int k;		//key2	(a random number between 1 - 10 for encrypting)
int t;		//key3	(just to make the encryption look complex)

char swap(char a[], char k, int l)	//idhellam edhuku nu solla maaten...tholil ragasiyam
{
	char temp = a[l];
	a[l] = k;
	return temp;
}
						
void display(char ch[])		//idhuvum dhaan....chitti oda nural code ku samam
{
	printf("%s\n", ch);
	//	printf("%s",ar);
}

void encrypt(char ch[])							//char * to void aakiten....epdiyum ch la change aagirum la ......same for decrpyt
{
	//STEP 1:Shuffle    		nee nenaikura shuffling illa...idhu punidhamanadhu
	int i;		//chumma loop kaaga
	for (i = 0; i < length; i = i +	 n)		//idha ellam explain panna theva illa...unakku edha la modify pannanumo adha mattum explain panren....
	{
		int l = i; //lowerbound
		int u = i + n - 1;
		if (i + n > length)
		{
			u = length - 1;
		} //upperbound
		char k = ch[l];
		while (l != u)
		{
			k = swap(ch, k, u);
			int t = u;
			if (u < l)
				u = l - 1;
			else
				u = l + 1;
			l = t;
		}
		ch[i] = k;
	}
	display(ch);
	//doneh

	//STEP 2:Encrypt

	k = rand() % 10;					//indha rendu values kandipa namakku theva for encrypt and decrypt ...so tholachuradha
	t = (126 / k) + 2;
	for (i = 0; i < length; i++)		//
	{

		int x = t * k + (126 - ch[i]);
		ch[i] = (char)(x - 2 * k + 2);
	}
	//doneh
	
	display(ch);
	return ch;
}

//decryption
void decrypt(char ch[])
{

	//STEP 1:Decrypt
	int i;
	for (i = 0; i < length; i++)
	{
		int x = ch[i] - 2 + 2 * k;
		ch[i] = (char)(t * k + 126 - x);
	}
	//STEP 2:Unshuffle			idhuvum nee nenaikuradhu illa
	for (i = 0; i < length; i = i + n)
	{
		int l = i;			 //lowerbound
		int u = i + n - 1; //upperbound

		if (i + n > length)
		{
			u = length - 1;
		}
		int mid;
		if (u - l % 2 == 0)
			mid = (u + l) / 2;

		else
		{
			mid = ((u + l) / 2) + 1;
		}

		char temp = ch[l];
		while (l != u)
		{
			char k = swap(ch, ch[u], l);
			int t = u;
			if (l < u)
				u = l + 1;
			else
				u = l - 1;
			l = t;
		}
		ch[mid] = temp;
	}

	ch[length] = '\0';				//nandri for this idea

	display(ch);
	return ch;
}

int random(int lower, int upper)
{
	srand(time(0));					//extrava add pannen....so that every time u run the code different random value varum so different encryption
	int num = (rand() % (upper - lower + 1)) + lower;

	return num;
}

void main()
{
	//input
	char ch[] = "my name is what!! otha gommale vaya vechitupi vaya!!!!";			
	length = strlen(ch);							//length of string

	//assigning key
	n = random(1, length);							//idhuvum one of the key

	//	printf("%d\n", n);			key work aagutha enne nu paaka dhaan print pannen...remove panradhu better i think
	//done
	//Encryption
	//printf("\n%s\n", ch);		//nama orginal string a display panrom.....theva illadha naai polapu
	char chr[length];			//idhu edhuku nu sathyama enakku therila both ch and chr has same values la....
	//strcpy(chr, encrypt(ch));	ipdi irundhuchu ..am changing this
	encrypt(ch);	
	decrypt(ch);

	//display
}

//perfectly working.....any doubt..contact 8903477989
