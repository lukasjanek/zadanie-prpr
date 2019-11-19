#include <stdio.h>
#define max 999
void n();
//void v();
//int u();
//int s();
//int d();
//int h();
//int c();
int k();

int main() //telo
{
	int znak;
	znak = getchar();
	
	switch (znak)
	{
		case 'n': n();
			break;
		/*case 'v': v();
			break;
		case 'u': u();
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
	return 0;
}

void n()
{   
	int povodnytext[max],pismeno,pocetznakov;
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
	}
	fclose(fr);
	if (fclose(fr)==EOF)
	{
		printf("Subor sa nepodarilo zatvorit\n");
	}
}
/*void v()
{
	if (n=)
}*/
int k()
{
	return 0;
}







