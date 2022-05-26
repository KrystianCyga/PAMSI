
#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


class filmy {
	std::string nazwy;
	int oceny;

	int ilosc_danych = 0;

public:
	void ustaw_ilosc_danych(int ilosc) {
		ilosc_danych = ilosc;
	}
	void dodajFilm(std::string nazwa, int ocena, int pozycja, filmy* tablica) {
		tablica[pozycja].nazwy = nazwa;
		tablica[pozycja].oceny = ocena;
	}
	void zmien_natxt(std::string nazwaPliku, std::string nazwaPlikuWyj) {
		std::string pom;
		std::ifstream csv(nazwaPliku);
		std::ofstream txt(nazwaPlikuWyj);

		while (getline(csv, pom))
		{
			if (pom[pom.length() - 1] == '0')
			{
				txt << pom << std::endl;
			}
		}
		csv.close();
		txt.close();
	}
	filmy* wczytajPlik(std::string nazwaPliku)
	{

		std::ifstream file;
		file.open(nazwaPliku);
		filmy* tablica = new filmy[ilosc_danych];
		if (file)
		{
			int i = 0;
			while (i < ilosc_danych)
			{
				std::string liniaPom;

				char pom[100];
				getline(file, liniaPom);

				int dlugosc = liniaPom.length();
				int ilosc = liniaPom.copy(pom, 4, dlugosc - 4);
				pom[dlugosc] = '\0';

				liniaPom.erase(dlugosc - 4, dlugosc);



				if (pom[0] == ',')
				{
					char pom3[4];
					for (int i = 0; i < 3; i++)
					{
						pom3[i] = pom[i + 1];
					}
					pom3[3] = '\0';
					int rate = atoi(pom3);
					dodajFilm(liniaPom, rate, i, tablica);
				}

				else
				{
					int rate1 = atoi(pom);
					dodajFilm(liniaPom, rate1, i, tablica);
				}

				i++;
			}
			file.close();

		}
		else {
			std::cout << "Nie można otworzyc pliku\n";
			delete tablica;
		}
		return tablica;
	}

	void wyswietlod(int od, int to, filmy* tablica) {

		for (int i = od;i < to;i++)
		{
			std::cout << tablica[i].nazwy;

			if (tablica[i].oceny != 10) { std::cout << ','; }
			std::cout << " ";
			std::cout << std::to_string(tablica[i].oceny) << "\n";
		}
	}
	void wyswietl(int nr, filmy* tablica) {

		std::cout << tablica[nr].nazwy;

		std::cout << std::to_string(tablica[nr].oceny) << "\n";

	}
	void wyswietlnazwe(int nr, filmy* tablica) {

		std::cout << tablica[nr].nazwy;

	}
	void wyswietlocene(int nr, filmy* tablica) {

		std::cout << std::to_string(tablica[nr].oceny) << "\n";

	}



	void merge(int l, int m, int r, filmy* tablica) {
		int lewy = 0, prawy = 0, k = 0, nl = 0, nr = 0;



		nl = m - l + 1; nr = r - m;
		filmy* ltab = new filmy[nl];
		filmy* rtab = new filmy[nr];



		for (lewy = 0; lewy < nl; lewy++)
		{
			ltab[lewy].oceny = tablica[l + lewy].oceny;
			ltab[lewy].nazwy = tablica[l + lewy].nazwy;
		}
		for (prawy = 0; prawy < nr; prawy++)
		{
			rtab[prawy].oceny = tablica[m + 1 + prawy].oceny;
			rtab[prawy].nazwy = tablica[m + 1 + prawy].nazwy;

		}
		lewy = 0; prawy = 0; k = l;

		while (lewy < nl && prawy < nr) {
			if (ltab[lewy].oceny <= rtab[prawy].oceny) {
				tablica[k].oceny = ltab[lewy].oceny;
				tablica[k].nazwy = ltab[lewy].nazwy;
				lewy++;
			}
			else {
				tablica[k].oceny = rtab[prawy].oceny;
				tablica[k].nazwy = rtab[prawy].nazwy;
				prawy++;
			}
			k++;
		}
		while (lewy < nl) {
			tablica[k].oceny = ltab[lewy].oceny;
			tablica[k].nazwy = ltab[lewy].nazwy;
			lewy++; k++;
		}
		while (prawy < nr) {
			tablica[k].oceny = rtab[prawy].oceny;
			tablica[k].nazwy = rtab[prawy].nazwy;
			prawy++; k++;
		}

	}
	void mergeSort(int l, int r, filmy* tablica) {
		if (l < r) {
			int m = l + (r - l) / 2;
			mergeSort(l, m, tablica);
			mergeSort(m + 1, r, tablica);
			merge(l, m, r, tablica);
		}
	}



	int partition(int l, int r, int pivot, filmy* tablica) {
		int i = l;
		int j = l;
		while (i <= r) {
			if (tablica[i].oceny > pivot) {
				i++;
			}
			else {
				std::swap(tablica[i].nazwy, tablica[j].nazwy);
				std::swap(tablica[i].oceny, tablica[j].oceny);
				i++;
				j++;
			}
		}
		return j - 1;
	}

	void quickSort(int l, int r, filmy* tablica) {
		if (l < r) {
			int pivot = tablica[r].oceny;
			int pos = partition(l, r, pivot, tablica);

			quickSort(l, pos - 1, tablica);
			quickSort(pos + 1, r, tablica);
		}
	}

	void bucketSort(int od, int to, filmy* tablica) {



		int licznik[5];
		for (int i = 0; i < 5; i++)
		{

			licznik[i] = 0;
		}

		for (int i = 0; i < ilosc_danych; i++)
		{
			if (tablica[i].oceny == 1 || tablica[i].oceny == 2) {
				licznik[0]++;
			}
			if (tablica[i].oceny == 3 || tablica[i].oceny == 4) {
				licznik[1]++;
			}
			if (tablica[i].oceny == 5 || tablica[i].oceny == 6) {
				licznik[2]++;
			}
			if (tablica[i].oceny == 7 || tablica[i].oceny == 8) {
				licznik[3]++;
			}
			if (tablica[i].oceny == 9 || tablica[i].oceny == 10) {
				licznik[4]++;
			}

		}
		filmy** buckets = new filmy * [5];


		for (int i = 0; i < 5; i++)
		{
			buckets[i] = new filmy[licznik[i]];
			licznik[i] = 0;
		}

		for (int k = 0; k < ilosc_danych; k++)
		{
			if (tablica[k].oceny == 1 || tablica[k].oceny == 2)
			{
				buckets[0][licznik[0]].oceny = tablica[k].oceny;
				buckets[0][licznik[0]].nazwy = tablica[k].nazwy;
				licznik[0]++;

			}
			if (tablica[k].oceny == 3 || tablica[k].oceny == 4)
			{
				buckets[1][licznik[1]].oceny = tablica[k].oceny;
				buckets[1][licznik[1]].nazwy = tablica[k].nazwy;
				licznik[1]++;
			}
			if (tablica[k].oceny == 5 || tablica[k].oceny == 6)
			{
				buckets[2][licznik[2]].oceny = tablica[k].oceny;
				buckets[2][licznik[2]].nazwy = tablica[k].nazwy;
				licznik[2]++;
			}
			if (tablica[k].oceny == 7 || tablica[k].oceny == 8)
			{
				buckets[3][licznik[3]].oceny = tablica[k].oceny;
				buckets[3][licznik[3]].nazwy = tablica[k].nazwy;
				licznik[3]++;
			}
			if (tablica[k].oceny == 9 || tablica[k].oceny == 10)
			{
				buckets[4][licznik[4]].oceny = tablica[k].oceny;
				buckets[4][licznik[4]].nazwy = tablica[k].nazwy;
				licznik[4]++;
			}
		}


		for (int i = 0; i < 5; i++)
		{
			quickSort(0, licznik[i] - 1, buckets[i]);
		}

		for (int last = 0;last < ilosc_danych;last++)
		{
			for (int i = 0; i < 5; i++)
			{

				int k = 0;
				while (licznik[i] > 0)
				{
					tablica[last].oceny = buckets[i][k].oceny;
					tablica[last].nazwy = buckets[i][k].nazwy;
					last++;
					k++;
					licznik[i]--;
				}

			}

			delete[] buckets[0];
			delete[] buckets[1];
			delete[] buckets[2];
			delete[] buckets[3];
			delete[] buckets[4];
			delete[] buckets;


		}


	}
	void sprawdz(filmy* tablica)
	{
		for (int i = 0; i < ilosc_danych - 1; i++)
		{
			if (tablica[i].oceny > tablica[i + 1].oceny)
			{
				std::cout << "SORTOWANIE NIE UDANE" << std::endl;
			}
			else {
				std::cout << "Z sortowaniem wszystko spoko" << std::endl;
			}
		}
	}

	int dajMediane(filmy* tablica) {
		return tablica[ilosc_danych / 2 - 1].oceny;
	}

	double dajSrednia(filmy* tablica) {
		int suma = 0;
		for (int i = 0; i < ilosc_danych; i++)
		{
			suma = suma + tablica[i].oceny;
		}
		return suma / ilosc_danych;
	}

};