//2 igraca
//prvi zadaje rec
//drugi pogadja slovo ili celu rec
//ima prava na 10 pokusaja

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<ctype.h>
#include<string.h>
void maska();

int main()
{

    char rec[12];
    char pokusaj;
    int brojPokusaja = 0;
    char rec1[12]; 
    int provera=-1;
    int netacneReci=0;
    int p;
    
    
    

    printf("\nUnesi rec: ");
    scanf("%s", &rec);
    maska();
    int duzinaReci = strlen(rec);


    printf("\nZadata rec ima %d slova\n", duzinaReci);
    //printujem zvezdice za svako slovo reci
    for (int i = 0; i < duzinaReci; i++)
    {
        //ne stavljam da je rec[i]=* jer je to onda nova vrednost reci
        printf("*");
    }

    //definisao sam rec na kojoj ce user moci da vidi slova koja je pogodio izmedju *
    for (int i = 0; i <= duzinaReci; i++)
    {
        rec1[i] = '*';
        if (i == duzinaReci)
            rec1[i] = '\0';
    }
   
    do
    {
        p = 0;
        netacneReci = 0;
        printf("\nPogodi slovo: ");
        //kliruje mi bafer jer nece raditi suprotno lol
        scanf("\n");
        scanf("%c", &pokusaj);

        for (int i = 0; i < duzinaReci; i++)
        {
            if (pokusaj == rec[i])
            {
                p = 1;
                rec1[i] = pokusaj;
                //poredimo ova 2 stringa kako bi smo imali exit
                provera = strcmp(rec1, rec);
   
            }
      
        }
        if(!p) brojPokusaja++;
        
        if (!provera)
        {
            printf("\nBravo! Trazena rec je bila: %s", rec);
            break;
        }

        else
        {
            printf("\nOtkrio si: %s", rec1);
        }
        

        
        printf("\nOstalo ti je jos %d pokusaja", 10 - brojPokusaja);

    } while (brojPokusaja < 10);

    if (provera)
        printf("\nTrazena rec je bila %s", rec);

}

void maska()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}