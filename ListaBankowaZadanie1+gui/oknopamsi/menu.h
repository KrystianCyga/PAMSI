

#pragma once
#include <stdlib.h>
#include <iostream>
#include "pamsi.h"
#include <cstdlib>

bool menu() {

	kolejka nowa_kolejka;
	int max=0;

	while (true)
	{

		std::cout << "\n	************************************\n";
		std::cout << "	******* Witaj w naszym banku *******\n";
		std::cout << "	1 - Pobierz bilet\n";
		std::cout << "	2 - Sprawdz ile jest osob w kolejce \n";
		std::cout << "	3 - Obsluz pierwsza osobe\n";
		std::cout << "	4 - Sprawdz wielkosc struktury\n";
		std::cout << "	5 - Wyczysc kolejke\n";
		std::cout << "	6 - Wyjdz z programu \n";
		std::cout << "	************************************\n";
		nowa_kolejka.wypisz_kolejke();

		int wybor = 1;
		
		std::cout << "\n	Twoj wybor: ";

		std::cin >> wybor;

		
		


		switch (wybor)
		{
		case 1:
		{
			max ++ ;
			int liczba = nowa_kolejka.daj_wielkosc();
			
			if (liczba > max) { max = liczba; }
			else if (liczba == max) { max++; }
			nowa_kolejka.zakolejkuj(max);
			system("cls");

		}break;
		case 2:
		{
			system("cls");
			std::cout << "	Dlugosc kolejki: " << nowa_kolejka.daj_wielkosc() << "\n";
		}break;
		case 3:
		{
			
			if (nowa_kolejka.daj_wielkosc() > 0) {
				system("cls");
				ilosc--;

				std::cout << "	Obsluzony numer: " << nowa_kolejka.zdejmij() << "\n";
				
			}
			else
			{   
				system("cls");
				std::cout << "	Brak ludzi w kolejce !!! \n";
			}
			
		}break;
		case 4:
		{
			system("cls");
			std::cout <<"	Wielkosc struktury to: " << (ilosc*16+24) << " bajtow.\n";
		}break;
		case 5:
		{
			system("cls");
			
			nowa_kolejka.wyczysc();
		}break;
		case 6:
		{
			nowa_kolejka.wyczysc();
			return true;
		}break;

		default:
			std::cout << "	NIE MA TAKIEJ OPCJI!!!\n";
			std::cout << "	Mozliwe to 1-6";
			break;
		}
		
	} 
	

}