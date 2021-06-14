#include "libraries.h"
using namespace std;
//ponizej funkcje rysujace elementy kostek
void rysuj_linia_start(int ile_razy){
    for (int i=0;i<ile_razy;i++){
        cout<<"_____________";
    }
    cout<<endl;
    for (int i=0;i<ile_razy;i++){
        cout<<"|     |     |";
    }
    cout<<endl;
}
void rysuj_linia_0(int side){
    if (side==0){
        cout<<"|     ";
    }else if (side==1){
        cout<<"|     |";
    }
}
void rysuj_linia_1(int side){
    if (side==0){
        cout<<"|  *  ";
    }else if (side==1){
        cout<<"|  *  |";
    }
}
void rysuj_linia_2(int side){
    if (side==0){
        cout<<"|*   *";
        }else if (side==1){
            cout<<"|*   *|";
        }
}
void rysuj_linia_3(int side){
    if (side==0){
        cout<<"|* * *";
        }else if (side==1){
            cout<<"|* * *|";
        }
}
void rysuj_linia_stop(int ile_razy){
    for (int i=0;i<ile_razy;i++){
        cout<<"|_____|_____|";
    }
    cout<<endl;
}
// rysuje linie 1 i 3 w kostce z kropkami, moze rysowac caly ciag fragmentow kostek
void rysuj_cala_linia1(int ile_razy, int **tab){
    int dots;
    for (int i=0;i<ile_razy;i++){
        for(int j=0;j<2;j++){
            dots=tab[i][j];
            if (dots==2 or dots==3){
                rysuj_linia_1(j);
                }else if (dots==4 or dots==5){
                    rysuj_linia_2(j);
                    }else if (dots==6){
                        rysuj_linia_3(j);
                        }else{
                            rysuj_linia_0(j);
                            }
        }
    }
    cout<<endl;
}
// rysuje linie 2 w kostce z kropkami, moze rysowac caly ciag fragmentow kostek
void rysuj_cala_linia2(int ile_razy, int **tab){
    int dots;
    for (int i=0;i<ile_razy;i++){
        for(int j=0;j<2;j++){
            dots=tab[i][j];
            if (dots==1 or dots==3 or dots==5){
                rysuj_linia_1(j);
                }else{
                    rysuj_linia_0(j);
                }
        }
    }
    cout<<endl;
}
//rysuje cala kostke, po podaniu tablicy z iloscia kropek w obydwu czesciach kostki, moze rysowac caly ciag kostek
void rysuj_kostka(int ile_razy,int **tab){
    rysuj_linia_start(ile_razy);
    rysuj_cala_linia1(ile_razy,tab);
    rysuj_cala_linia2(ile_razy,tab);
    rysuj_cala_linia1(ile_razy,tab);
    rysuj_linia_stop(ile_razy);
}
