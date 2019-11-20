#include <stdio.h>
#include <ctype.h>
#define MAX 999
void n(int povodnytext[],int *dlzkasuboru) 
{   	
	FILE *fr;	
	if ((fr = fopen("sifra.txt","r"))!=NULL)
	{ 
		int pismeno,pocetznakov;
		pocetznakov=0;
		while ((pismeno=getc(fr))!=EOF)
		{
			povodnytext[pocetznakov]=pismeno;
			pocetznakov++;
		}
		*dlzkasuboru = pocetznakov;
		if (fclose(fr)==EOF)
		{
			printf("Subor sa nepodarilo zatvorit\n");	
		}
	}
	else
	{
		printf("Spravu sa nepodarilo nacitat\n");
	}
	
}
void v(int povodnytext[], int dlzkasuboru)
{
	int iteracia;
	for (iteracia=0;iteracia< dlzkasuboru;iteracia++)
	{
		printf("%c",povodnytext[iteracia]);
	}
}
void u(int povodnytext[],int upravenytext[],int dlzkasuboru)
{
	int iteracia,i=0;
	if ((dlzkasuboru < '0') && (dlzkasuboru > '9'))
	{
	for(iteracia=0; iteracia=dlzkasuboru;iteracia++)
	{
			toupper(povodnytext[iteracia]);
			povodnytext[iteracia]=upravenytext[i];
			iteracia++;
	}

}
}

int main() //telo
{
	int znak, dlzkasuboru=MAX; 
	int povodnytext[MAX],upravenytext[MAX];
	while ((znak =getchar()) !='k')
	{
		switch (znak)
		{
			case 'n': n(povodnytext, &dlzkasuboru);
				break;
			case 'v': v(povodnytext, dlzkasuboru);
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
			case 'k':  return 0;
		}
	}
	return 0;
}








