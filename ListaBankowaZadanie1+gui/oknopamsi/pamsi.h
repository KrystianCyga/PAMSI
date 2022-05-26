
#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
static int ilosc;

class kolejka {
	struct element_kolejki {

		int numer;
		element_kolejki* next;


		element_kolejki() {

			ilosc++;
		}
	};

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
	
	int* wypisz_kolejke() {
		element_kolejki *pom;
		std::string ss;
		pom = glowa;
		int* tab = new int[100];
		int i=0;
		
		if (pom != NULL) {
			ss = "	Kolejka ->";
			while (pom->next != NULL) {
				tab[i] = pom->numer;
				pom = pom->next;
				i++;
			}
			if (pom->next == NULL) {
				tab[i] = pom->numer;
				
			}
			
		}
		else {
			tab[0] = 0;
			
		}
		
		
		return tab;
	}

	void wyczysc() {
		ilosc = 0;
		licznik = 0;
		pom = glowa;
		while (pom != NULL)
			pop();
	}
};



