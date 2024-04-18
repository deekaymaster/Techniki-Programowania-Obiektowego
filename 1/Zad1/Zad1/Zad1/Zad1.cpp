#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dom {
protected:
    double powierzchnia;
    double cena;
    int liczbaPokoi;

public:
    Dom(double powierzchnia, double cena, int liczbaPokoi) : powierzchnia(powierzchnia), cena(cena), liczbaPokoi(liczbaPokoi) {}

    double getPowierzchnia() const { return powierzchnia; }
    double getCena() const { return cena; }
    int getLiczbaPokoi() const { return liczbaPokoi; }

    void setPowierzchnia(double powierzchnia) { this->powierzchnia = powierzchnia; }
    void setCena(double cena) { this->cena = cena; }
    void setLiczbaPokoi(int liczbaPokoi) { this->liczbaPokoi = liczbaPokoi; }

    void promocja(double procent) { cena -= cena * procent / 100; }
};

class DomOsiedlowy : public Dom {
private:
    int liczbaMiejscParkingowych;

public:
    DomOsiedlowy(double powierzchnia, double cena, int liczbaPokoi, int liczbaMiejscParkingowych) : Dom(powierzchnia, cena, liczbaPokoi), liczbaMiejscParkingowych(liczbaMiejscParkingowych) {}

    int getLiczbaMiejscParkingowych() const { return liczbaMiejscParkingowych; }
    void setLiczbaMiejscParkingowych(int liczbaMiejscParkingowych) { this->liczbaMiejscParkingowych = liczbaMiejscParkingowych; }

    void wyswietlInformacje() const {
        cout << "Powierzchnia: " << powierzchnia << " m2\n";
        cout << "Cena: " << cena << " PLN\n";
        cout << "Liczba pokoi: " << liczbaPokoi << "\n";
        cout << "Liczba miejsc parkingowych: " << liczbaMiejscParkingowych << "\n\n";
    }
};

void porownajCeny(const Dom& dom1, const Dom& dom2) {
    if (dom1.getCena() > dom2.getCena()) {
        cout << "Dom 1 kosztuje " << dom1.getCena() << " PLN, a wiec jest drozszy od domu 2, ktory kosztuje " << dom2.getCena() << " PLN.\n";
    }
    else if (dom1.getCena() < dom2.getCena()) {
        cout << "Dom 2 kosztuje " << dom2.getCena() << " PLN, a wiec jest drozszy od domu 1, ktory kosztuje " << dom1.getCena() << " PLN.\n";
    }
    else {
        cout << "Oba domy maja taka sama cene wynoszaca " << dom2.getCena() << " PLN.\n";
    }
}

void clearScreen() {
    system("cls");
}

double addDoubleTypeValue(string polecenie) {
    double value;

    do {
        cout << polecenie;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cout << "Wprowadzona wartosc jest nie prawidlowa. Sprobuj ponownie." << endl;

            // Czyszczenie stanu błędu i bufora strumienia wejścia
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (cin.fail() || value <= 0);

    return value;
}

int addIntTypeValue(string polecenie) {
    int value;
    do {
        cout << polecenie;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cout << "Wprowadzona wartosc jest nie prawidlowa. Sprobuj ponownie." << endl;

            // Czyszczenie stanu błędu i bufora strumienia wejścia
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (cin.fail() || value <= 0);

    return value;
}

ostream& operator<<(ostream& os, const Dom& dom) {
    os << "Powierzchnia: " << dom.getPowierzchnia() << " m2\n";
    os << "Cena: " << dom.getCena() << " PLN\n";
    os << "Liczba pokoi: " << dom.getLiczbaPokoi() << "\n";
    return os;
}

ostream& operator<<(ostream& os, const DomOsiedlowy& dom) {
    os << static_cast<const Dom&>(dom); //wywolanie przeciazenia operatora << dla klasy Dom
    os << "Liczba miejsc parkingowych: " << dom.getLiczbaMiejscParkingowych() << "\n";
    return os;
}

int main() {
    // Tablica dynamiczna przechowująca obiekty klasy Dom
    vector<Dom> domy;
    // Tablica dynamiczna przechowująca obiekty klasy DomOsiedlowy
    vector<DomOsiedlowy> domyOsiedlowe;

    // Kilka domów na start
    domy.push_back(Dom(120, 250000, 4));
    domy.push_back(Dom(150, 300000, 5));
    domy.push_back(Dom(200, 400000, 6));


    int wybor;
    do {
        cout << "Menu:\n";
        cout << "1. Dodaj dom\n";
        cout << "2. Dodaj dom osiedlowy\n";
        cout << "3. Wyswietl wszystkie domy\n";
        cout << "4. Wyswietl wszystkie domy osiedlowe\n";
        cout << "5. Usun dom\n";
        cout << "6. Usun dom osiedlowy\n";
        cout << "7. Edytuj dom\n";
        cout << "8. Edytuj dom osiedlowy\n";
        cout << "0. Wyjscie\n\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;
        clearScreen();
        switch (wybor) {
        case 1: {
            // Dodawanie nowego domu
            double powierzchnia, cena;
            int liczbaPokoi;
            powierzchnia = addDoubleTypeValue("Podaj powierzchnie domu: ");
            cena = addDoubleTypeValue("Podaj cene domu: ");
            liczbaPokoi = addIntTypeValue("Podaj liczbe pokoi: ");

            // Tworzenie i dodawanie domu do tablicy
            domy.push_back(Dom(powierzchnia, cena, liczbaPokoi));
            break;
        }
        case 2: {
            // Dodawanie nowego domu osiedlowego
            double powierzchnia, cena;
            int liczbaPokoi, liczbaMiejscParkingowych;
            powierzchnia = addDoubleTypeValue("Podaj powierzchnie domu osiedlowego: ");
            cena = addDoubleTypeValue("Podaj cene domu osiedlowego: ");
            liczbaPokoi = addIntTypeValue("Podaj liczbe pokoi domu osiedlowego: ");
            liczbaMiejscParkingowych = addIntTypeValue("Podaj liczbe miejsc parkingowych: ");

            // Tworzenie i dodawanie domu osiedlowego do tablicy
            domyOsiedlowe.push_back(DomOsiedlowy(powierzchnia, cena, liczbaPokoi, liczbaMiejscParkingowych));
            break;
        }
        case 3: {
            // Wyświetlanie wszystkich domów
            cout << "Domy:\n\n";
            for (size_t i = 0; i < domy.size(); ++i) {
                cout << "ID: " << i << endl;
                cout << domy[i] << endl;
            }
            break;
        }
        case 4: {
            // Wyświetlanie wszystkich domów osiedlowych
            cout << "Domy osiedlowe:\n\n";
            for (size_t i = 0; i < domyOsiedlowe.size(); ++i) {
                cout << "ID: " << i << endl;
                cout << domyOsiedlowe[i] << endl;
            }
            break;
        }
        case 5: {
            // Usuwanie domu
            int index= addIntTypeValue("Podaj indeks domu do usuniecia: ");

            if (index >= 0 && index < domy.size()) {
                domy.erase(domy.begin() + index);
                cout << "Dom zostal usuniety.\n";
            }
            else {
                cout << "Nieprawidlowy indeks.\n";
            }
            break;
        }
        case 6: {
            // Usuwanie domu osiedlowego
            int index = addIntTypeValue("Podaj indeks domu osiedlowego do usuniecia: ");

            if (index >= 0 && index < domyOsiedlowe.size()) {
                domyOsiedlowe.erase(domyOsiedlowe.begin() + index);
                cout << "Dom osiedlowy zostal usuniety.\n";
            }
            else {
                cout << "Nieprawidlowy indeks.\n";
            }
            break;
        }
        case 7: {
            // Edycja domu
            int index= addIntTypeValue("Podaj indeks domu do edycji: ");

            if (index >= 0 && index < domy.size()) {
                double powierzchnia, cena;
                int liczbaPokoi;
                powierzchnia = addDoubleTypeValue("Nowa powierzchnia: ");
                cena = addDoubleTypeValue("Nowa cena: ");
                liczbaPokoi = addIntTypeValue("Nowa liczba pokoi: ");

                domy[index].setPowierzchnia(powierzchnia);
                domy[index].setCena(cena);
                domy[index].setLiczbaPokoi(liczbaPokoi);

                cout << "Dane domu zostaly zaktualizowane.\n";
            }
            else {
                cout << "Nieprawidlowy indeks.\n";
            }
            break;
        }
        case 8: {
            // Edycja domu osiedlowego
            int index = addIntTypeValue("Podaj indeks domu osiedlowego do edycji: ");

            if (index >= 0 && index < domyOsiedlowe.size()) {
                double powierzchnia, cena;
                int liczbaPokoi, liczbaMiejscParkingowych;
                powierzchnia = addDoubleTypeValue("Nowa powierzchnia: ");
                cena = addDoubleTypeValue("Nowa cena: ");
                liczbaPokoi = addIntTypeValue("Nowa liczba pokoi: ");
                liczbaMiejscParkingowych = addIntTypeValue("Nowa liczba miejsc parkingowych: ");

                domyOsiedlowe[index].setPowierzchnia(powierzchnia);
                domyOsiedlowe[index].setCena(cena);
                domyOsiedlowe[index].setLiczbaPokoi(liczbaPokoi);
                domyOsiedlowe[index].setLiczbaMiejscParkingowych(liczbaMiejscParkingowych);

                cout << "Dane domu osiedlowego zostaly zaktualizowane.\n";
            }
            else {
                cout << "Nieprawidlowy indeks.\n";
            }
            break;
        }
        case 0:
            cout << "Wyjscie z programu.\n";
            break;
        default:
            cout << "Nieprawidlowa opcja. Sprobuj ponownie.\n";
        }
    } while (wybor != 0);

    return 0;
}
