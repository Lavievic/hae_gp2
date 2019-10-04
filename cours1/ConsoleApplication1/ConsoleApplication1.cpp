// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include "Rec.hpp"
#include <iostream>
#include <cstring>
#include <cstdio>

static void TestRec();

int StrChr(char * grange, char chat) {
	int length = strlen(grange);
	for ( int i = 0; i < length;++i) {
		if (grange[i] == chat)
			return i;
	}
	return -1;
}

int StrChr2(char * grange, char chat) {
	char * oldGrange = grange;
	while( *grange ) {
		if (*grange == chat) {
			return (int)(grange - oldGrange);
		}
		grange++;
	}
	return -1;
}


int StrChr3(char * grange, char chat) {
	int counter = 0;
	while (grange[counter] != 0) {
		if (grange[counter] == chat) {
			return counter;
		}
		counter++;
	}
	return -1;
}

int Max(int a, int b) {
	return (a < b) ? b : a;
}

int Min(int a, int b) {
	return (a < b) ? a : b;
}

void Strcpy(char*dst, char*src) {
	while (*dst++ = *src++);
}

int Strcmp( char * meule, char * aiguille ) {
	//return -1 si meule est inférieur lexicographiquement
	//return 1 si meule est supérieur lexicographiquement
	//return 0 si meule est egale a l'aiguille lexicographiquement
	int lenMeule = strlen(meule);
	int lenAiguille = strlen(aiguille);

	int maxLen = Max(lenMeule, lenAiguille);
	int minLen = Min(lenMeule, lenAiguille);

	for (int i = 0; i < minLen; i++) {
		if (meule[i] < aiguille[i]) 
			return -1;
		else if (meule[i] > aiguille[i]) 
			return 1;
		//if equal continue;
	}

	//une des deux chaines est plus courte que l'autre
	if (minLen == maxLen) return 0;
	if (maxLen == lenMeule) return 1;
	return -1;
}

char * StrStr(char * meuleDeFoin, char * aiguille) {
	int lenMeule = strlen(meuleDeFoin);
	int lenAiguille = strlen(aiguille);

	for (int i = 0; i < lenMeule; ++i) {
		bool found = true;
		for (int j = 0; j < lenAiguille; ++j) {
			if (meuleDeFoin[j] != aiguille[j]) {
				found = false;
				break;
			}
		}
		if (found)
			return meuleDeFoin;
		meuleDeFoin++;
	}
	return nullptr;
}

char * StrStr2(char * meuleDeFoin, char * aiguille) {
	int lenMeule = strlen(meuleDeFoin);
	for (int i = 0; i < lenMeule; ++i) {
		char contenuTemporaire[256];
		strncpy_s(contenuTemporaire, meuleDeFoin + i, strlen(aiguille) );
		if (Strcmp(contenuTemporaire, aiguille) == 0) {
			return (meuleDeFoin + i);
		}
	}
	return nullptr;
}



//todo montrer que 'a' est un entier

void Memcpy(char * dest, char * src, int size) {
	//copier size
	
	for (int i = 0; i < size; i++)
	{
		dest[i] = src[i];
	}

	//	copier src[size] dans dest[size];
	//	size--;

	//for( i ... 0 ... size )
	// copier src dans dest

	//remplir
}

void Memcpy2(char * dest, char * src, int size) 
{
	while(size--) // --size et size-- pile ?
	{
		dest[size] = src[size];
		size--;
	}
}


int main()
{
    std::cout << "Hello World!\n"; 

	char licorne[32] = "licorne";
	char vomi[32] = "vomit";

	printf("contenu de licorne %s\n", licorne);

	Memcpy2( licorne, vomi,strlen(licorne)+1 );

	printf("contenu de licorne %s\n", licorne);

	char chateau[32] = "chateau";
	char soldat = 'e';

	int posSoldat = StrChr3(chateau, soldat);
	printf("le soldat est en position %d\n", posSoldat);

	
	char text[1024] = "Lorem ipsum dolor sit amet";
	char token[1024] = "dolor";
	char * tokenInText = StrStr(text, token);
	char * tokenInText2 = StrStr2(text, token);
	int pos = (int)(tokenInText - text);
	printf("le token est en position %d\n", pos);
	
	//environ 11

	//ecrire un cas de test ou Strcmp renvoie 1
	// licorne > lico //1
	char text0[] = "licorne";
	char text1[] = "licor";
	//ecrire le test de Strcmp entre licorne et lico 
	{
		int cmp0 = strcmp(text0, text1);
		int cmp = Strcmp(text0, text1);
	}

	{
		int cmp0 = strcmp(text1, text0);
		int cmp = Strcmp(text1, text0);

		int a = 0;
	}

	{
		int cmp0 = strcmp(text1, text1);
		int cmp = Strcmp(text1, text1);

		int a = 0;
	}
	

	//ecrire un cas de test ou Strcmp renvoie -1
	// poney < 'poney noir' //1
	//ecrire un cas de test ou Strcmp renvoie 0
	// arcenciel == arcenciel // strcmp parce que == va comparer des pointer
	// verifier que  arcenciel == arcenciel , char [160]
	int a = 0;

	TestRec();
}

int add_0(int a, int b) {
	int i = 0;
	for (i = 0; i < a + b; ++i);
	return i;
}

int add_1(int a, int b) {
	int val = a;
	for (int i = 0; i < b; ++i) 
		val++;
	return val;
}

// add_2( 7, 8 )
	// add_2( 6, 9 )
	// add_2( 5, 10 )
	//...
	// add_2( 0, 15 )
	// a + 0 => a
	// 

int add_2(int a, int b) {
	printf( "(a:%d,b:%d)\n",a,b );
	if (a == 0) return b;
	if (b == 0) return b;
	else 
		return add_2( a-1, b+1);
}

int add_3(int a, int b) {
	//printf( a b );
	if (a == 0)			return b;
	else if (b == 0)	return a;
	else {
		int inter = 1 + add_3(a - 1, b);
		return inter;
	}
}

int add_4(int a, int b) {
	if (a == 0)			return b;
	else if (b == 0)	return a;
	else {
		int inter = 1 + add_4(a + 1 , b);
		return inter;
	}
}


// 8 2 
// 8 1 ... -1
// (8 0) ... -1 ... -1
// (8 -1) -1
// (7 -1)
// 6 0 
int subrec2(int a, int b) 
{
	printf("(a:%d,b:%d)\n", a, b);
	if (b == 0) return a;
	else if (b > 0) 
		return subrec2(a, b - 1) - 1;
	else 
		return subrec2(a, b + 1) + 1;
}

int mul(int a, int b) {
	//on autorise a + b maintenant qu'on l'a écris

	// f(a,b) //multiply
	// a + f(a,b-1);

	// a * b 
	// = a * (b-1) + a;
	// 4 3
	// 4 * 2 + 4
	// 4 * 1 + 4 + 4
	// 4 + 4 + 4
	// 8 + 4
	// 12
	if (a == 0) return 0;
	if (b == 0) return 0;
	if (b < 0) return -mul(a, -b);
	return a + mul(a, b - 1);
}

int mul2(int a, int b) {
	if (a == 0 || b == 0)
		return a;
	else if (b < 0)
		return -a + mul2(a, b + 1);
	else
		return a + mul2(a, b - 1);
}


int sub(int a, int b) {

	printf("a:%d b:%d", a, b);
	//cas terminal
	if (b == 0)		return a;
	if (a == 0)		return -b;

	//cas general b inf
	// 3 - 2
	// 4 - 1
	// 5 - 0
	if (b < 0)		return sub(a + 1, b + 1);

	// 3 - -2
	// 4 - -1
	// 5 - 0
	//cas general b pos
	if (b > 0)		return sub(a - 1, b -1);
	// trouve un combinateur et un appel recursif sur des parametres ( n-1 )
}

int div_rec(int a, int b){
	if (a == 0 )			return 0;
	if (b < 0 && a < 0)		return -div_rec(a, b);
	if (a < 0)				return -div_rec(-a, b);
	if (b < 0)				return -div_rec(a, -b);
	if (a < b)				return 0;
	return 1 + div_rec(a - b, b);
}

int div_mod_rec(int a, int b, int * rest) {
	if (a == 0) {
		*rest = 0;
		return 0;
	}
	if (b < 0 && a < 0) {
		int subRest = 0;
		int divRem = -div_mod_rec(a, b, &subRest);
		*rest = -subRest;
		return divRem;
	}
	if (a < 0) {
		int subRest = 0;
		int divRem = -div_mod_rec(-a, b, &subRest);
		*rest = -subRest;
		return divRem;
	}
	if (b < 0) {
		int subRest = 0;
		int divRem = -div_mod_rec(a, -b, &subRest);
		*rest = -subRest;
		return divRem;
	}
	if (a < b) {
		*rest = a;
		return 0;
	}
	return 1 + div_mod_rec(a - b, b,rest);
}

int mod_rec(int a, int b) {
	//reste de la division euclidienne
	//mod(a,b) = a - mul(b, div(a,b) )
	return a - mul(b, div_rec(a, b));
}
int mod_rec2(int a, int b) {
	if (a < b && a>0) return a;
	if (a == 0) return 0;
	if (a < 0) return -mod_rec2(-a, b);
	if (b < 0) return -mod_rec2(a, -b);
	return mod_rec2(a - b, b);
}

void TestRec() {
	//int foo = add_4(2, 2);
	//int foo2 = add_3(3, -2);

	//int foo3 = sub(4, 6);
	//int foo3 = sub(6, 6);
	int foo3 = sub(6, 2);
	//int foo3 = subrec2(8, 2);
	int foo4 = mul(2, 4);
	int foo5 = mul(2, -5);
	int foo6 = mul2(2, -5);
	int foo7 = div_rec(2 , 5);
	int foo8 = div_rec(2, -5);
	int foo9 = div_rec(6, 2);
	int foo10 = div_rec(-6, 2);
	int foo11 = div_rec(6, -2);
	int foo12 = mod_rec2(23, 5);
	int foo13 = mod_rec2(-33, 10);
	int foo14 = mod_rec2(20, -3);

	int  i = 0;
}