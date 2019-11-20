#include <stdio.h>
#include <string.h>
#define MAX 999
void n(char povodnytext[]);
void v(char povodnytext[]);
//int u();
//int s();
//int d();
//int h();
//int c();
int k();

void n(char povodnytext[])
{   
	int pismeno,pocetznakov;
	FILE *fr;
	pocetznakov=0;
	if ((fr = fopen("sifra.txt","r"))==NULL)
	{
		printf("Spravu sa nepodarilo nacitat\n");
	}
	while (pismeno !=EOF)
	{
		povodnytext[pocetznakov]=pismeno;
		pismeno=getc(fr);
		pocetznakov++;
	}
	fclose(fr);

}
void v(char povodnytext[])
{
	int obsah,iteracia;
	obsah=0;
	for (iteracia=0;iteracia<MAX;iteracia++)
	{
		obsah = povodnytext[iteracia];
		putchar(obsah);
	}
}
int k()
{
	return 0;
}

int main() //telo
{
	int znak; 
	char povodnytext[MAX],upravenytext[MAX];
	znak = getchar();
	while (getchar()!='k')
	{
		switch (znak)
		{
			case 'n': n(povodnytext);
				break;
			case 'v': v(povodnytext);
				break;
			/*case 'u': u();
				break;
			case 's': s();
				break;
			case 'd': d();
				break;
			case 'h': h();
				break;
			case 'c': c();
				break;*/
			case 'k': k();
				break; 
		}
	}
	return 0;
}








