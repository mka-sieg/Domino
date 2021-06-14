#ifndef LIBRARIES_H_INCLUDED
#define LIBRARIES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "func.cpp"
#include "func_game.cpp"
#include "func_rand.cpp"
const int liczba=5;
const int liczba_max=7;
const int liczba_wszystkich=28;
void niewylosowane(int gg[],int talon[],int liczba,int ilosc_graczy,int liczba_wszystkich);
bool czyBylaWylosowana( int iLiczba, int tab[], int ile );
int rozpoczecie_gry(int liczba,int **gracze_losowanie,int pierwszy_gracz,int kolejka[],int **tab,int kostka,int liczba_elem);
int rozpoczecie_gry_komputer(int liczba,int **gracze_losowanie,int pierwszy_gracz,int kolejka[],int **tab,int kostka,int liczba_elem);
void ustawienie_kolejnosci(int ilosc_graczy,int pierwszy_gracz, int kolejnosc_graczy[]);
int dokladanie_kostki_komputer(int kolejka[],int **gracz_kostki,int ostatnia,int **tab,int liczba,int talon[],int liczba_talon,int **do_dodania, int ii,int liczba_do_dodania[]);
int dokladanie_kostki(int kolejka[],int **gracz_kostki,int ostatnia,int **tab,int talon[],int liczba_talon,int **do_dodania,int ii,int liczba_do_dodania[]);
void koniec_ruchu();
void losowanie(int liczba,int liczba_wszystkich, int tab[],int gg[],int ii);
void rysuj_linia_start(int ile_razy);
void rysuj_linia_0(int side);
void rysuj_linia_1(int side);
void rysuj_linia_2(int side);
void rysuj_linia_3(int side);
void rysuj_linia_stop(int ile_razy);
void rysuj_cala_linia1(int ile_razy, int **tab);
void rysuj_cala_linia2(int ile_razy, int **tab);
void rysuj_kostka(int ile_razy,int **tab);


#endif // LIBRARIES_H_INCLUDED
