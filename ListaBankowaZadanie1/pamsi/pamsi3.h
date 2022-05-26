
#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
static int ilosc;
struct element_kolejki {

		int numer;
		element_kolejki* next;


		element_kolejki() {
			
			ilosc++;
		}
	};

class kolejka {
private:
	

	element_kolejki* glowa, * pom;
	int licznik = 0;


	void push() {
		licznik++;
		element_kolejki* temp;
		temp = glowa;
		if (temp != NULL)
		{
			while (temp->next != NULL)
				temp = temp->next;

			temp->next = pom;
		}
		else
			glowa = pom;
	}

	void pop() {
		pom = glowa;
		

		if (glowa!=NULL) {
			glowa = glowa->next;
		}
		delete (pom);
		
		
	}
public:
	kolejka() {
		glowa = NULL;
	}
	~kolejka() {
		delete (glowa);
		delete (pom);

	}

	void zakolejkuj(int wartosc) {
		pom = new element_kolejki;
		pom->numer = wartosc;
		pom->next = NULL;
		push();
	}

	int zdejmij() {
		licznik--;
		int wartosc = glowa->numer;
		pop();
		return wartosc;

	}

	int daj_wielkosc() {
		return licznik;
	}
	
	const char* wypisz_kolejke() {
		element_kolejki *pom;
		std::string ss;
		pom = glowa;
		
		if (pom != NULL) {
			ss = "	Kolejka ->";
			while (pom->next != NULL) {
				ss = ss + std::to_string(pom->numer) + "\t";
				pom = pom->next;
			}
			if (pom->next == NULL) {
				ss = ss + std::to_string(pom->numer) + "\n";
			}
			
		}
		else {
			ss = "	Nie ma ludzi w kolejce!!!\n";
			
		}
		
		const char* elo = ss.c_str();
		return elo;
	}

	void wyczysc() {
		ilosc = 0;
		pom = glowa;
		while (pom != NULL)
			pop();
	}
};



