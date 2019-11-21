#include <stdio.h>
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
	putchar('\n');
}
void u(int povodnytext[],int upravenytext[],int dlzkasuboru,int *velkepismena)
{
	int velke, pismeno, pocetznakov;
	int upravenypocetznakov=0;

	for(pocetznakov=0; pocetznakov<=dlzkasuboru; pocetznakov++)
	{	
		
		pismeno = povodnytext[pocetznakov];
		if ((pismeno >= 'a' && pismeno <= 'z') || (pismeno >= 'A' && pismeno <= 'Z'))
		{
				if(pismeno >= 'a' && pismeno <= 'z')
				{
					velke = pismeno-32;
					upravenytext[upravenypocetznakov] = velke;
				}
				else 
				{
					upravenytext[upravenypocetznakov] = povodnytext[pocetznakov];
				}
				upravenypocetznakov++;
		}
	
		}
	*velkepismena=velke;
}
void s(int upravenytext[], int velkepismena)
{
	int pocetznakov;
	for (pocetznakov=0;pocetznakov<=velkepismena;pocetznakov++)
	{
		printf("%c",upravenytext[pocetznakov]);
	}
	putchar('\n'); 	
}
void d(int povodnytext[], int dlzkasuboru)
{
	int dlzkaslova,drzac=0,pocetznakov,zaciatok=0,medzera=0;
	scanf("%d",&dlzkaslova);
	if (dlzkaslova >=1 && dlzkaslova <= 100)
	{
		
		for (pocetznakov = 0; pocetznakov < dlzkasuboru; pocetznakov++)
		{
			if (povodnytext[pocetznakov] != ' ')
			{
				drzac++;
			}
			if (povodnytext[pocetznakov] == ' ')
			{
				if (drzac == dlzkaslova)
				{
					while(zaciatok < drzac + medzera)
					{
					printf("%c",povodnytext[zaciatok]);
          			zaciatok++;
          			}
          			putchar('\n');
          			zaciatok = pocetznakov+1;
          			medzera = zaciatok;
          			drzac=0;	
				}
				else
				{
					zaciatok=pocetznakov+1;
					medzera = zaciatok;
					drzac = 0;
				}
			}
		}
	}
}


int main() //telo
{
	int znak, dlzkasuboru=MAX,velkepismena=MAX; 
	int povodnytext[MAX],upravenytext[MAX];
	while ((znak =getchar()) !='k')
	{
		switch (znak)
		{
			case 'n': n(povodnytext, &dlzkasuboru);
				break;
			case 'v': v(povodnytext, dlzkasuboru);
				break;
			case 'u': u(povodnytext,upravenytext,dlzkasuboru, &velkepismena);
				break;
			case 's': s(upravenytext, velkepismena);
				break;
			case 'd': d(povodnytext, dlzkasuboru);
				break;
			/*case 'h': h();
				break;
			case 'c': c();
				break;*/
			case 'k':  return 0;
		}
	}
	return 0;
}








