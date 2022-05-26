
#include "Sortowanie.h"

#include <windows.h>
using namespace std;

filmy ListaFilmow;
filmy* lista = new filmy;

string nazwaPlikuWyj = "wyjsciowy.txt";
int wybor = 0;
int iloscDanych = 0, pom = 1;

int main()
{
	while (1) {
		cout << "\n**** Witam w programie sortowania			" << "\n";
		cout << "**** MENU PROGRAMU:						" << "\n";
		cout << "**** 1-Ustaw ilosc danych do operacji		" << "\n";
		cout << "**** 2-Wczytaj dane z pliku				" << "\n";
		cout << "**** 3-Sortuj metoda MERGE Sort			" << "\n";
		cout << "**** 4-Sortuj metoda QUICK Sort			" << "\n";
		cout << "**** 5-Sortuj metoda BUCKET Sort			" << "\n";
		cout << "**** 6-Wyswietl dane						" << "\n";
		cout << "**** 7-Zresetuj dane						" << "\n";
		cout << "**** 8-WYJSCIE							    " << "\n\n";
		cout << "**** Twoj wybor -> ";
		cin >> wybor;


		switch (wybor) {
		case(1):
		{

			cout << "Podaj ilosc danych do wczytania : ";
			cin >> iloscDanych;
			ListaFilmow.ustaw_ilosc_danych(iloscDanych);
			break;
		}
		case(2):
		{
			string nazwa;
			cout << "Podaj nazwe pliku wejsciowego .csv: ";
			cin >> nazwa;
			ListaFilmow.zmien_natxt(nazwa, nazwaPlikuWyj);
			lista = ListaFilmow.wczytajPlik(nazwaPlikuWyj);
			break;
		}
		case(3):
		{
			pom = iloscDanych - 1;
			ListaFilmow.mergeSort(0, pom, lista);
			break;
		}
		case(4):
		{
			pom = iloscDanych - 1;
			ListaFilmow.quickSort(0, pom, lista);
			break;
		}
		case(5):
		{
			pom = iloscDanych - 1;
			ListaFilmow.bucketSort(0, pom, lista);
			break;
		}
		case(6):
		{
			pom = iloscDanych;
			if (iloscDanych > 100) { pom = 100; }
			ListaFilmow.wyswietlod(0, pom, lista);
			break;
		}
		case(7):
		{
			lista = ListaFilmow.wczytajPlik(nazwaPlikuWyj);
			break;

		}
		case(8):
		{
			return 0;
			break;

		}
		default:
			cout << "Nie ma takiej opcji ";
			break;
		}
	}
}
