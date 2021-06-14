#include "libraries.h"
//funkcja losuje kostki dla gracza
bool czyBylaWylosowana( int iLiczba, int tab[], int ile )
{
    if( ile <= 0 )
         return false;
    int i = 0;
    do{
        if( tab[ i ] == iLiczba )
             return true;
        i++;
    } while( i < ile );

    return false;
}
void losowanie(int liczba,int liczba_wszystkich, int tab[],int gg[],int ii){
    int i=0;
    int wylosowana;
    do{
        wylosowana=rand()%liczba_wszystkich;
        if( czyBylaWylosowana( wylosowana, gg, i+(ii*liczba) ) == false )
        {
            gg[ i+(ii*liczba) ] = wylosowana;
            tab[i]=wylosowana;
            i++;
        } //if
    } while( i < liczba );

    i = 0;
    /*
    do
    {
        std::cout << gg[ i+(ii*liczba)] << std::endl;
        i++;
    } while( i < liczba );*/
}
void niewylosowane(int gg[],int talon[],int liczba,int ilosc_graczy,int liczba_wszystkich){
    int j=0;
    int same=0;
    for (int i=0;i<liczba_wszystkich;i++){

        same=0;
        for (int jj=0;jj<(liczba*ilosc_graczy);jj++){
            //cout<<same<<endl;
            if (gg[jj]!=i){
                same++;
            }
        }
        if (same==liczba*ilosc_graczy){
            talon[j]=i;
            //cout<<talon[j]<<endl;
            j++;
        }
    }
}
