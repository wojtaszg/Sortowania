#ifndef ALGORYTMY_HH
#define ALGORYTMY_HH

#include <iostream>


void merge(int *wsk, int lewy, int srodek, int prawy);

void mergeSort(int *wsk,int pocz, int kon);

void quickSort(int *wsk,int left, int right);

void wypelnijLosowo(int **wsk,int Rozmiar);

void wypelnijPosortowanymi (int **wsk,double Procent,int Rozmiar);

void wypelnijMalejaco(int **wsk, int Rozmiar);

bool sprawdzSortowanie (int **wsk,int Rozmiar);

void wyswietlTablice (int **wsk,int nr,int Rozmiar);

int partycjonowanie(int *tab, int lewy, int prawy);

void wstawianie(int *tab, int n);

void tworzenie_kopca(int *tab, int index, int rozmiar);

void kopcowanie(int *tab, int rozmiar);

void Introspektywne(int *tab, int rozmiar, int M);

void hybrydowe(int *tab, int rozmiar);


#endif
