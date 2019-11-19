#include <stdio.h>
#include <string.h>
#define MAX 999
void n();
void v();
//int u();
//int s();
//int d();
//int h();
//int c();
int k();

void n()
{   
	int povodnytext[MAX],pismeno,pocetznakov;
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
void v()
{
	int obsah;
	obsah=0;
	while (povodnytext[obsah] !=EOF)
	{
		putchar(obsah);
	}
}
int k()
{
	return 0;
}
int main() //telo
{
	int znak, povodnytext[MAX],upravenytext[MAX];
	znak = getchar();
	while (getchar()!='k')
	{
		switch (znak)
		{
			case 'n': n();
				break;
			case 'v':v();
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








