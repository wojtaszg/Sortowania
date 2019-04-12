#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include "algorytmy.hh"

using namespace std;


const int Rozmiar = 1000000;



int main()
{
	int **wsk = new int *[100];
	for (int i = 0; i < 100; i++)
		wsk[i] = new int[Rozmiar];
	
	//wypelnijPosortowanymi (wsk,99.7,Rozmiar);
	//wypelnijLosowo(wsk,Rozmiar);
	wypelnijMalejaco(wsk,Rozmiar);

	cout<<"\n\nU³o¿enie przed sortowaniem = "<<sprawdzSortowanie(wsk, Rozmiar);
	//wyswietlTablice(wsk,0,Rozmiar);
	
	double start = clock();

	
	cout << "\n\nsortowanie ... " << endl;
	for (int i = 0; i < 100; i++)
	{
		quickSort(wsk[i] ,0, Rozmiar - 1);
		//mergeSort(wsk[i],0, Rozmiar - 1);
		//hybrydowe(wsk[i],Rozmiar);
	}
	double czas = (clock() - start) / CLOCKS_PER_SEC;
	cout<<"\nU³o¿enie po sortowaniu = "<< sprawdzSortowanie(wsk, Rozmiar);
	//wyswietlTablice(wsk,0,Rozmiar);
	cout << "\n\n" << "Czas sortowania 100 tablic: " << czas <<" sec" <<endl;
	cout<<"Œredni czas sortowania 1 tablicy: "<<czas/100<<" sec"<<endl;
	for(int i=0; i<100; i++)
	delete [] wsk[i];
	delete [] wsk;	

}
