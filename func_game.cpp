#include "libraries.h"
void koniec_ruchu(){
    string next;
    while(next!="n"){
        cout<<"By zakonczyc ruch wpisz litere n"<<endl;
        cin>>next;
        if(next=="n"){
            break;
        }
    }
        system("cls");

}
int dokladanie_kostki(int kolejka[],int **gracz_kostki,int ostatnia,int **tab,int talon[],int liczba_talon,int **do_dodania,int ii,int liczba_do_dodania[]){
    int aa=0;
    int jjj=0;
    int kostka;
    int **nowa_kostka;
    nowa_kostka = new int *[1];
    for(int i=0;i<1;i++){
        nowa_kostka[i] = new int[1];
    }
    int temp[liczba_talon];
    int losowa_liczba;
    while(aa!=1){
        cin>>kostka;
        if (kostka==-1){
            do{
                cout<<"Dobieram kostke z talonu!"<<endl;
                losowa_liczba=rand()%liczba_talon;
                do_dodania[ii][jjj]=talon[losowa_liczba];

                for(int t=0;t<liczba_talon;t++){
                    if(t!=losowa_liczba){
                        temp[jjj]=talon[t];
                        jjj++;
                    }
                }
                nowa_kostka[0][0]=gracz_kostki[talon[0]][0];
                nowa_kostka[0][1]=gracz_kostki[talon[0]][1];
                rysuj_kostka(1,nowa_kostka);
            }while(gracz_kostki[kostka][0]!=tab[kolejka[ostatnia]][1]);
            aa=1;
            liczba_talon--;
            for (int iiii=0;iiii<liczba_talon;iiii++){
                talon[iiii]=temp[iiii];
            }
            liczba_do_dodania[ii]=jjj;
        }else{
            if(gracz_kostki[kostka][0]!=tab[kolejka[ostatnia]][1]){
                cout<<"Wybierz inna kostke!"<<endl;
            }else{
                aa=1;
            }
            }

    }
    cout<<"Wybrano kostke nr "<<kostka<<endl;
//sprawdzenie czy koniec

    return kostka;
}
int dokladanie_kostki_komputer(int kolejka[],int **gracz_kostki,int ostatnia,int **tab,int liczba,int talon[],int liczba_talon,int **do_dodania, int ii,int liczba_do_dodania[]){
    int kostka=0;
    int jjj=0;
    int **nowa_kostka;
    nowa_kostka = new int *[1];
    for(int i=0;i<1;i++){
        nowa_kostka[i] = new int[1];
    }
    int temp[liczba_talon];
    int losowa_liczba;
    for(int i=0;i<liczba;i++){
        if(gracz_kostki[i][0]==tab[kolejka[ostatnia]][1]){
             kostka=kolejka[ostatnia];
        }else{
            do{
                cout<<"Dobieram kostke z talonu!"<<endl;
                losowa_liczba=rand()%liczba_talon;
                do_dodania[ii][jjj]=talon[losowa_liczba];
                for(int t=0;t<liczba_talon;t++){
                    if(t!=losowa_liczba){
                        temp[jjj]=talon[t];
                        jjj++;
                    }
                }
                nowa_kostka[0][0]=gracz_kostki[talon[0]][0];
                nowa_kostka[0][1]=gracz_kostki[talon[0]][1];
                rysuj_kostka(1,nowa_kostka);
            }while(gracz_kostki[kostka][0]!=tab[kolejka[ostatnia]][1]);
            liczba_talon--;
            for (int iiii=0;iiii<liczba_talon;iiii++){
                talon[iiii]=temp[iiii];
            }

        }

    }
    liczba_do_dodania[ii]=jjj;
//sprawdzenie czy koniec
    return kostka;
}
void ustawienie_kolejnosci(int ilosc_graczy,int pierwszy_gracz, int kolejnosc_graczy[]){
    int kolejnosc_04[]={0,1,2,3};
    int kolejnosc_14[]={1,2,3,0};
    int kolejnosc_24[]={2,3,0,1};
    int kolejnosc_34[]={3,0,1,2};
    int kolejnosc_03[]={0,1,2};
    int kolejnosc_13[]={1,2,0};
    int kolejnosc_23[]={2,0,1};
    int kolejnosc_02[]={0,1};
    int kolejnosc_12[]={1,0};
    if(ilosc_graczy==2){
        for (int i=0;i<ilosc_graczy;i++){
                if (pierwszy_gracz==0){
                    kolejnosc_graczy[i]=kolejnosc_02[i];
                }if (pierwszy_gracz==1){
                    kolejnosc_graczy[i]=kolejnosc_12[i];
                }
        }
    }else if(ilosc_graczy==3){
        for (int i=0;i<ilosc_graczy;i++){
                if (pierwszy_gracz==0){
                    kolejnosc_graczy[i]=kolejnosc_03[i];
                }if (pierwszy_gracz==1){
                    kolejnosc_graczy[i]=kolejnosc_13[i];
                }if (pierwszy_gracz==2){
                    kolejnosc_graczy[i]=kolejnosc_23[i];
                }
        }
    }else{
        for (int i=0;i<ilosc_graczy;i++){
                if (pierwszy_gracz==0){
                    kolejnosc_graczy[i]=kolejnosc_04[i];
                }if (pierwszy_gracz==1){
                    kolejnosc_graczy[i]=kolejnosc_14[i];
                }if (pierwszy_gracz==2){
                    kolejnosc_graczy[i]=kolejnosc_24[i];
                }if (pierwszy_gracz==3){
                    kolejnosc_graczy[i]=kolejnosc_34[i];
                }
            }
    }


}
int rozpoczecie_gry(int liczba,int **gracze_losowanie,int pierwszy_gracz,int kolejka[],int **tab,int kostka,int liczba_elem){
    int **gracz_kostki;
    gracz_kostki = new int *[liczba];
    for(int i=0;i<liczba;i++){
        gracz_kostki[i] = new int[1];
    }
    for (int j=0;j<liczba;j++){
        gracz_kostki[j][0]=tab[gracze_losowanie[pierwszy_gracz][j]][0];
        gracz_kostki[j][1]=tab[gracze_losowanie[pierwszy_gracz][j]][1];
    }
    rysuj_kostka(liczba,gracz_kostki);
    cin>>kostka;
    cout<<"Wybrano kostke nr "<<kostka<<endl;
    koniec_ruchu();
    kolejka[liczba_elem]=gracze_losowanie[pierwszy_gracz][kostka];
    liczba_elem+=1;
    int **kolejka_rys;
    kolejka_rys = new int *[liczba_elem];
    for(int i=0;i<liczba_elem;i++){
        kolejka_rys[i] = new int[1];
    }
    for(int l=0;l<liczba_elem;l++){
        kolejka_rys[l][0]=tab[kolejka[l]][0];
        kolejka_rys[l][1]=tab[kolejka[l]][1];
    }
    rysuj_kostka(liczba_elem,kolejka_rys);

    delete [] kolejka_rys;

    delete [] gracz_kostki;
    return kostka;
}
int rozpoczecie_gry_komputer(int liczba,int **gracze_losowanie,int pierwszy_gracz,int kolejka[],int **tab,int kostka,int liczba_elem){
    int **gracz_kostki;
    gracz_kostki = new int *[liczba];
    for(int i=0;i<liczba;i++){
        gracz_kostki[i] = new int[1];
    }

    for (int j=0;j<liczba;j++){
        gracz_kostki[j][0]=tab[gracze_losowanie[pierwszy_gracz][j]][0];
        gracz_kostki[j][1]=tab[gracze_losowanie[pierwszy_gracz][j]][1];
    }
    kostka=rand()%liczba;
    kolejka[liczba_elem]=gracze_losowanie[pierwszy_gracz][kostka];;
    liczba_elem+=1;
    int **kolejka_rys;
    kolejka_rys = new int *[liczba_elem];
    for(int i=0;i<liczba_elem;i++){
        kolejka_rys[i] = new int[1];
    }
    for(int l=0;l<liczba_elem;l++){
        kolejka_rys[l][0]=tab[kolejka[l]][0];
        kolejka_rys[l][1]=tab[kolejka[l]][1];
    }
    rysuj_kostka(liczba_elem,kolejka_rys);

    delete [] kolejka_rys;

    delete [] gracz_kostki;
    return kostka;
}
