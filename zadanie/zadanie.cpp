#include <stdio.h>
#define MAX 999
#define ABECEDA 'Z' - 'A' + 1
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
	*velkepismena=upravenypocetznakov;
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
void h(int upravenytext[], int velkepismena)
{
	int histogram[ABECEDA], zaciatok, znak, pismeno, tridsatpercentaViac, tridsatpercent, dvadsatpercent, desatpercent, raz;
	for (zaciatok=0; zaciatok<ABECEDA; zaciatok++)
	{
	  histogram[zaciatok] = 0;
	}
    for (znak = 0; znak < velkepismena; znak++) 
	{
      	if((upravenytext[znak] >= 'A') && (upravenytext[znak] <= 'Z'))
      	{
			histogram[upravenytext[znak] - 'A']++;
		}
	}
	pismeno = 100 / velkepismena;
	for (tridsatpercentaViac = 0; tridsatpercentaViac < ABECEDA; tridsatpercentaViac++)
	{
		if (((histogram[tridsatpercentaViac])*pismeno) > 30) //ak sa pismeno nachadza viac ako 30% v poli
		{
			putchar('*');
		}
		else
		{
			putchar(' ');
		}
	}
	putchar('\n');
	for (tridsatpercent = 0; tridsatpercent < ABECEDA; tridsatpercent++)
	{
		if (((histogram[tridsatpercent])*pismeno) > 20) //ak sa pismeno nachadza do 30%
		{
			putchar('*');
		}
		else
		{
			putchar(' ');
	 }	
	}
	putchar('\n');
	for (dvadsatpercent = 0; dvadsatpercent < ABECEDA; dvadsatpercent++)
	{
		if (((histogram[dvadsatpercent])*pismeno) > 10) //ak sa pismeno nachadza do 20%
		{
			putchar('*');
		}
		else
		{
			putchar(' ');
		}
	}
	putchar('\n');
	for (desatpercent = 0; desatpercent < ABECEDA; desatpercent++)
	{
		if (((histogram[desatpercent])*pismeno) > 0) //ak sa pismeno nachadza do 10%
		{
			putchar('*');
		}
		else
		{
			putchar(' ');
		}
	}
	putchar('\n');
	for (raz = 0; raz < ABECEDA; raz++)
	{
	putchar('A'+ raz); //ak sa to nachadza raz
	}
	putchar ('\n');
}
void c(int upravenytext[], int velkepismena)
{
	int iteracia,posun,sifra,cezarka,velke;
	scanf("%d", &posun);
	if ((posun >= 1) && (posun <=25))
	{
		for (iteracia=0; iteracia < velkepismena; iteracia++)
		{
			sifra = upravenytext[iteracia] - posun;
			if (sifra < 'A')
			{
				cezarka = sifra + 32;
				printf("%c",cezarka);
			}
			else 
			{
				printf("%c",sifra);	
			}	
		}
		putchar('\n');
	}
}
int main() //telo
{
	int znak, dlzkasuboru=MAX,velkepismena=MAX; 
	int povodnytext[MAX]={0},upravenytext[MAX]={0};
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
			case 'h': h(upravenytext,velkepismena);
				break;
			case 'c': c(upravenytext, velkepismena);
				break;
			case 'k':  return 0;
		}
	}
	return 0;
}








