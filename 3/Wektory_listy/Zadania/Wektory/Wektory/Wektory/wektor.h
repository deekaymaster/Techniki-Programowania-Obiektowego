#ifndef WEKTOR_H
#define WEKTOR_H

#include <iostream>

using namespace std;

template <typename Twoj_typ>

class Wektor {
private:
	static const int MAX_ROZMIAR = 100;
	Twoj_typ tab[MAX_ROZMIAR];
	int ile_obiektow;

public:
	Wektor() : ile_obiektow(0) {};

	void wstaw(Twoj_typ& element) {
		if (ile_obiektow < MAX_ROZMIAR) {
			tab[ile_obiektow++] = element;
		}
	}

	void usun(int nr) {
		if (nr >= 0 && nr < ile_obiektow) {
			for (int i = nr; i < ile_obiektow - 1; ++i) {
				tab[i] = tab[i + 1];
			}
			ile_obiektow--;
		}
	};

	Twoj_typ& co_na(int pozycja) {
		return tab[pozycja];
	}

	void rozsun(int pozycja) {
		if (pozycja >= 0 && pozycja < ile_obiektow && ile_obiektow < MAX_ROZMIAR) {
			for (int i = ile_obiektow; i > pozycja; --i) tab[i] = tab[i - 1];
			ile_obiektow++;
		}
	}

	void zsun(int nr) {
		if (nr >= 0 && nr < ile_obiektow) {
			for (int i = nr; i < ile_obiektow - 1;++i) tab[i] = tab[i + 1];
			ile_obiektow--;
		}
	}

	int rozmiar() {
		return ile_obiektow;
	}

	friend ostream& operator<<(ostream& out, const Wektor<Twoj_typ>& wektor) {
		for (int i = 0; i < wektor.ile_obiektow; ++i)
			out << wektor.tab[i] << endl;
		return out;
	}

};

#endif
