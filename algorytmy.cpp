#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>
#include "algorytmy.hh"

using namespace std;

int pom[1000000];


void merge(int *wsk, int lewy, int srodek, int prawy)
{
	
	for (int i = lewy; i <= prawy; i++)
		pom[i] = wsk[i];

	int i = lewy, j = srodek + 1, k = lewy;

	while (i <= srodek && j <= prawy)
	{
		if (pom[i] < pom[j])
			wsk[k++] = pom[i++];
		else
			wsk[k++] = pom[j++];
	}
	while (i <= srodek)
		wsk[k++] = pom[i++];
}


void mergeSort(int *wsk,int pocz, int kon)
{
	int srodek;
	if (pocz < kon)
	{
		srodek = (pocz + kon) / 2;
		mergeSort(wsk,pocz, srodek);
		mergeSort(wsk,srodek + 1, kon);
		merge(wsk,pocz, srodek, kon);
	}
}

void quickSort(int *wsk,int left, int right)
{
	int i = left;
	int j = right;
	int piwot = wsk[(left + right) / 2]; 
	do
	{
		while (wsk[i] < piwot)
			i++;

		while (wsk[j] > piwot)
			j--;

		if (i <= j)
		{
			swap(wsk[i], wsk[j]);

			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) quickSort(wsk,left, j);

	if (right > i) quickSort(wsk,i, right);

}


	
	
	void wypelnijPosortowanymi (int **wsk,double Procent,int Rozmiar)
	{
		int a = (Procent*Rozmiar) / 100;
		for(int j=0; j<100; j++)
		{
		for (int i = 0; i < a; i++)
			wsk[j][i] = i;

		for (int i = a; i < Rozmiar; i++)
			wsk[j][i] = rand() % 100000;
		}
	
	}
	
	bool sprawdzSortowanie (int **wsk,int Rozmiar)
	{
		for(int i=0; i<100; i++)
		{
			for(int j=0; j<Rozmiar-1; j++)
			{
				if(wsk[i][j] <= wsk[i][j+1])
				{
					;
				}
				else
				{
				return false;
				break;
				}
			}
		}
		return true;
	
	}

void wypelnijLosowo (int **wsk,int Rozmiar)
	{
		for(int i = 0; i<100; i++)
		{
		//wsk[i] = new int[Rozmiar];
		for (int j = 0; j < Rozmiar; j++)
			wsk[i][j] = rand() % 1000000;
		}
	}

void wypelnijMalejaco(int **wsk, int Rozmiar)
{
	for(int i = 0; i<100; i++)
		{
		int x =Rozmiar*(i+1);
		for (int j = 0; j < Rozmiar; j++)
			wsk[i][j] = x--;
		}

}

void wyswietlTablice (int **wsk,int nr,int Rozmiar)
{
	cout << "\n" << "Przed sortowaniem pierwszej: " << endl;
	for (int i = 0; i < Rozmiar; i++)
		cout << wsk[nr][i] << "\t";
	cout << endl;
}

int partycjonowanie(int *tab, int lewy, int prawy)
{
	int i = (lewy + prawy) / 2;
	int piwot = tab[i];
	int temp = 0;
	tab[i] = tab[prawy];
	int j = lewy;

	for (i = lewy; i<prawy; i++)
	{
		if (tab[i]<piwot)
		{
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
			j++;
		}
	}
	tab[prawy] = tab[j];
	tab[j] = piwot;

	return j;

}

void wstawianie(int *tab, int n)
{
	for (int i = 1; i<n; i++)
	{
		int j = i;

		while (j>0)
		{
			if (tab[j - 1]>tab[j])
			{
				tab[j - 1] ^= tab[j];
				tab[j] ^= tab[j - 1];
				tab[j - 1] ^= tab[j];
				--j;
			}
			else
			{
				break;
			}
		}
	}
}

void tworzenie_kopca(int *tab, int index, int rozmiar)
{
	int j;
	while (index <= rozmiar / 2)
	{
		j = 2 * index;
		if (j + 1 <= rozmiar && tab[j + 1]>tab[j])
			j = j + 1;
		if (tab[index]<tab[j])
		{
			int temp = tab[index];
			tab[index] = tab[j];
			tab[j] = temp;
		}
		else break;
		index = j;
	}
}

void kopcowanie(int *tab, int rozmiar)
{
	int i;

	for (i = rozmiar / 2; i>0; --i)
		tworzenie_kopca(tab - 1, i, rozmiar);
	for (i = rozmiar - 1; i>0; --i)
	{
		int temp = tab[0];
		tab[0] = tab[i];
		tab[i] = temp;
		tworzenie_kopca(tab - 1, 1, i);
	}

}

void Introspektywne(int *tab, int rozmiar, int M) // M - z³o¿ono¶æ obliczeniowa
{
	int i;
	if (M == 0)
	{
		kopcowanie(tab, rozmiar);
		return;
	}

	i = partycjonowanie(tab, 0, rozmiar - 1);
	if (i>9)
	{
		Introspektywne(tab, i, M - 1);
	}

	if (rozmiar - 1 - i>9)
	{
		Introspektywne(tab + i + 1, rozmiar - 1 - i, M - 1);
	}



}

void hybrydowe(int *tab, int rozmiar)
{
	Introspektywne(tab, rozmiar, (int)floor(2 * log2(rozmiar)) );
	wstawianie(tab, rozmiar);
}
