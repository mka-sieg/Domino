#include "libraries.h"
using namespace std;

    int main()
{
    srand (time(0));
    string choice;
    while (choice!="kk"){
        cout<<"Gra Domino"<<endl;
        cout<<"s - Rozpocznij gre"<<endl;
        cout<<"k - Wyjdz z gry"<<endl;
        cin>>choice;
        if (choice=="s" ){
            int kk=1;
            int usun=0;
            int poczatek=0;
            int dodaj=0;
            int kolejka[100];
            int liczba_elem=0;
            int pierwszy_gracz,ilosc_graczy,komp,norm,wygrana,kostka;
            int k=0;
            int **gracze_losowanie;
            int **tab;
            int gracz[liczba];

            tab = new int *[liczba_wszystkich];
            for(int i=0;i<liczba_wszystkich;i++){
            tab[i] = new int[kk];
            }
            for (int i=0; i!=liczba_max;i++){
                for(int j=i;j!=liczba_max;j++){
                    tab[k][0]=i;
                    tab[k][1]=j;
                    //cout<<tab[k][0]<<" "<<tab[k][1]<<endl;
                    k++;
                }
            }
            cout<<"Wybierz ilosc graczy 2,3 lub 4"<<endl;
            cin>>ilosc_graczy;
            int gracz_komp[ilosc_graczy];
            int liczba_do_dodania[ilosc_graczy];
            int kolejnosc_graczy[ilosc_graczy];
            int do_usuniecia[ilosc_graczy];
            int liczba_talon=liczba_wszystkich-(liczba*ilosc_graczy);
            int **do_dodania;
                    do_dodania = new int *[ilosc_graczy];
                    for(int iii=0;iii<ilosc_graczy;iii++){
                        do_dodania[iii] = new int[liczba_talon];
                    }
            int talon[liczba_wszystkich-(liczba*ilosc_graczy)];

            int gg[liczba*ilosc_graczy];
            if (ilosc_graczy==2){
                gracz_komp[0]=0;
                gracz_komp[1]=1;
            }else{
                while(komp>ilosc_graczy-1 or komp<1){
                    cout<<"Ile graczy komputerowych?"<<endl;
                    cin>>komp;
                    if(komp<ilosc_graczy-1 and komp>1){
                        break;
                    }
                }
                norm=ilosc_graczy-komp;
                for  (int j=0;j<norm;j++){
                    gracz_komp[j]=0;
                }
                for(int i=norm;i<ilosc_graczy;i++){
                    gracz_komp[i]=1;
                }
            }
            gracze_losowanie = new int *[ilosc_graczy];
            for(int i=0;i<ilosc_graczy;i++){
                gracze_losowanie[i] = new int[liczba];
            }

            for (int i=0;i<ilosc_graczy;i++){

                losowanie(liczba,liczba_wszystkich,gracz,gg,i);

                for (int j=0;j<liczba;j++){
                    gracze_losowanie[i][j]=gracz[j];
                }
            }

            for(int i=0;i<ilosc_graczy;i++){
                for(int j=0;j<liczba;j++){
                    cout<<gracze_losowanie[i][j]<<" ";
                }
                cout<<endl;
            }
            niewylosowane(gg,talon,liczba,ilosc_graczy,liczba_wszystkich);
            pierwszy_gracz=(rand()%int(ilosc_graczy));

            cout<<"Zaczyna gracz nr "<<pierwszy_gracz+1<<endl;
            ustawienie_kolejnosci(ilosc_graczy,pierwszy_gracz, kolejnosc_graczy);
            for (int i=0;i<ilosc_graczy;i++){
                if (gracz_komp[kolejnosc_graczy[i]]==0){
                    cout<<"Gracz "<<kolejnosc_graczy[i]+1<<" wylosowano kostki"<<endl;
                    int **gracz_kostki;
                    gracz_kostki = new int *[liczba];
                    for(int iii=0;iii<liczba;iii++){
                        gracz_kostki[iii] = new int[1];
                    }
                    for (int j=0;j<liczba;j++){
                        gracz_kostki[j][0]=tab[gracze_losowanie[i][j]][0];
                        gracz_kostki[j][1]=tab[gracze_losowanie[i][j]][1];
                    }
                    rysuj_kostka(liczba,gracz_kostki);
                    koniec_ruchu();

                    delete [] gracz_kostki;
                }else{
                    cout<<"Gracz "<<kolejnosc_graczy[i]+1<<" - komputer"<<endl;
                    }
            }
            //cout<<liczba_elem<<"e"<<endl;
            while(wygrana!=1){
                for (int i=0;i<ilosc_graczy;i++){
                        if(poczatek==0){
                            cout<<"Rozpoczynamy gre..."<<endl;

                            if (gracz_komp[pierwszy_gracz]==0){
                                cout<<"Gracz "<<pierwszy_gracz+1<<" wybierz kostke i wpisujac jej numer kolejnosci (pierwsza kostka to 0)"<<endl;

                                kostka=rozpoczecie_gry(liczba,gracze_losowanie,pierwszy_gracz,kolejka,tab,kostka,liczba_elem);

                            }else if(gracz_komp[pierwszy_gracz]==1){
                                cout<<"Gracz "<<pierwszy_gracz+1<<" Rozpoczyna komputer"<<endl;
                                kostka=rozpoczecie_gry_komputer(liczba,gracze_losowanie,pierwszy_gracz,kolejka,tab,kostka,liczba_elem);
                            }
                            poczatek=1;
                        }else{
                            int **gracz_kostki;
                            gracz_kostki = new int *[liczba-usun+dodaj];
                            for(int iii=0;iii<liczba-usun+dodaj;iii++){
                                gracz_kostki[iii] = new int[1];
                            }
                            for (int j=0;j<liczba-usun+dodaj;j++){
                                if(do_usuniecia[kolejnosc_graczy[i]]!=j){
                                    gracz_kostki[j][0]=tab[gracze_losowanie[kolejnosc_graczy[i]][j]][0];
                                    gracz_kostki[j][1]=tab[gracze_losowanie[kolejnosc_graczy[i]][j]][1];
                                }
                            }
                            for (int j=liczba-usun;j<liczba-usun+dodaj;j++){
                                for (int dd=0;dd<liczba_do_dodania[kolejnosc_graczy[i]];dd++){
                                    gracz_kostki[j][0]=tab[gracze_losowanie[kolejnosc_graczy[i]][kostka]][0];
                                    gracz_kostki[j][1]=tab[gracze_losowanie[kolejnosc_graczy[i]][kostka]][1];
                                }
                            }
                            if (gracz_komp[kolejnosc_graczy[i]]==0){
                                cout<<"Gracz "<<kolejnosc_graczy[i]+1<<" - Dobierz kolejna kostke wpisujac jej numer kolejnosci (pierwsza kostka to 0)"<<endl;
                                cout<<"Jezeli nie masz odpowiedniej kostki - wpisz -1"<<endl;

                                rysuj_kostka(liczba,gracz_kostki);
                                kostka=dokladanie_kostki(kolejka,gracz_kostki,liczba_elem,tab, talon,liczba_talon,do_dodania,i,liczba_do_dodania);
                                do_usuniecia[i]=kostka;
                                usun=1;
                                dodaj=1;
                                koniec_ruchu();
                                liczba_elem+=1;
                                kolejka[liczba_elem]=gracze_losowanie[kolejnosc_graczy[i]][kostka];
                                cout<<liczba_elem<<"ee"<<endl;
                                int **kolejka_rys;
                                kolejka_rys = new int *[liczba_elem+1];
                                for(int l=0;l<liczba_elem+1;l++){
                                    kolejka_rys[l] = new int[1];
                                }
                                for(int l=0;l<liczba_elem+1;l++){
                                    kolejka_rys[l][0]=tab[kolejka[l]][0];
                                    kolejka_rys[l][1]=tab[kolejka[l]][1];
                                }
                                for(int iiii=0;iiii<liczba_elem+1;iiii++){
                                    cout<<kolejka[iiii]<<" ";
                                }
                                cout<<endl;
                                rysuj_kostka(liczba_elem+1,kolejka_rys);

                                delete [] kolejka_rys;
                            }else if(gracz_komp[kolejnosc_graczy[i]]==1){
                                cout<<"Gracz "<<kolejnosc_graczy[i]+1<<"- komputer"<<endl;
                                kostka=dokladanie_kostki_komputer(kolejka,gracz_kostki,liczba_elem,tab,liczba,talon,liczba_talon,do_dodania,i,liczba_do_dodania);
                                do_usuniecia[i]=kostka;
                                usun=1;
                                dodaj=1;
                                liczba_elem+=1;
                                kolejka[liczba_elem]=gracze_losowanie[kolejnosc_graczy[i]][kostka];

                                int **kolejka_rys;
                                kolejka_rys = new int *[liczba_elem+1];
                                for(int l=0;l<liczba_elem+1;l++){
                                    kolejka_rys[i] = new int[1];
                                }
                                for(int l=0;l<liczba_elem+1;l++){
                                    kolejka_rys[l][0]=tab[kolejka[l]][0];
                                    kolejka_rys[l][1]=tab[kolejka[l]][1];
                                }
                                for(int iiii=0;iiii<liczba_elem+1;iiii++){
                                    cout<<kolejka[iiii]<<" ";
                                }
                                cout<<endl;
                                rysuj_kostka(liczba_elem+1,kolejka_rys);

                                delete [] kolejka_rys;
                            }
                            delete [] gracz_kostki;
                        }
                }
            }
            delete [] tab;
            break;

        }else if (choice=="k"){
            std::cout << "Koniec gry" << std::endl;
            break;

        }else{
            std::cout << "wybierz" << std::endl;
        }
    }
    return 0;
}
