//
// Created by Julia Szefer on 12/06/2022.
//

/**
 * klasa służąca jako arena do gry
 */

#include "Arena.h"
#include "Help.h"
#include "Postac.h"
#include "Rozgrywka.h"
#include <iostream>
#include <ctime>

using namespace std;

Postac omen(1, "Omen", 25, 100, 0.3, "rzut ognistą kulą", "płomienna tarcza", 20, "ogien", true, false);
Postac terror(2, "Terror", 20, 100, 0.4, "zianie ogniem", "pancerz z lawy", 25, "ogien", true, false);
Postac vision(3, "Vision", 20, 100, 0.4, "ogniste oczy", "ognista zasłona", 25, "ogien", true, false);
Postac leaf(4, "Leaf", 25, 100, 0.2, "rzut kamieniem", "tarcza z ziemi", 20, "ziemia", true, false);
Postac stone(5, "Stone", 20, 100, 0.3, "kamienne tornado", "kamienna garda", 20, "ziemia", true, false);
Postac root(6, "Root", 20, 100, 0.4, "zabójcze korzenie", "liściasta kula", 20, "ziemia", true, false);
Postac air(7, "Air", 25, 100, 0.6, "tornado", "powietrzne odepchnięcie", 20, "powietrze", true, false);
Postac sky(8, "Sky", 20, 100, 0.2, "pioruny", "pochmurna zasłona", 20, "powietrze", true, false);
Postac wind(9, "Wind", 20, 100, 0.4, "powietrzny shuriken", "silny podmuch wiatru", 20, "powietrze", true, false);
Postac drop(10, "Drop", 25, 100, 0.5, "wodne igły", "wodna tarcza", 20, "woda", true, false);
Postac waterfall(11, "Waterfall", 20, 100, 0.3, "tsunami", "zalanie wodą", 20, "woda", true, false);
Postac frog(12, "Frog", 20, 100, 0.7, "uderzenie językiem", "toksyczny kwas", 20, "woda", true, false);
Postac ice(13, "Ice", 25, 100, 0.6, "zamrożenie", "lodowa tarcza", 20, "lód", true, false);
Postac icicle(14, "Icicle", 20, 100, 0.4, "atak soplami lodu", "lodowy podmuch", 20, "lód", true, false);
Postac steel(15, "Steel", 25, 100, 0.3, "stalowy młot", "stalowa tarcza", 20, "stal", true, false);

Help help;
vector<Postac> postacie;
vector<Postac> przeciwnicy;
static vector<Postac> druzyna;


/**
 * metoda implementująca rozgrywkę
 */
void Arena::game() {

    postacie.push_back(omen);
    postacie.push_back(terror);
    postacie.push_back(vision);
    postacie.push_back(leaf);
    postacie.push_back(stone);
    postacie.push_back(root);
    postacie.push_back(air);
    postacie.push_back(sky);
    postacie.push_back(wind);
    postacie.push_back(drop);
    postacie.push_back(waterfall);
    postacie.push_back(frog);
    postacie.push_back(ice);
    postacie.push_back(icicle);
    postacie.push_back(steel);

    cout << "-------------------" << endl;
    cout << " Gra Turowa s24690" << endl;
    cout << "-------------------" << endl;

    cout << "\nZaczynamy!" << endl;
    doYouNeedHelp();

    showElement(postacie);

    cout << "\nWybierz po id 6 postaci z listy, wpisuj je pojedynczo i po każdym id naciśnij enter" << endl;

    int wybraneId, wybraneId2, wybraneId3, wybraneId4, wybraneId5, wybraneId6;
    bool czyBylo = false, czyBylo2 = false, czyBylo3 = false, czyBylo4 = false, czyBylo5 = false;
    bool czyJestId = false;
    while (!czyJestId) {
        try {
            cin >> wybraneId;
            cout << "Wybrana została postać o id: " << wybraneId << endl;
            postacie.at(wybraneId - 1).setCzyWybrany(true);
            druzyna.push_back(postacie.at(wybraneId - 1));
            czyJestId = true;
        } catch (const exception &e) {
            cout << "Nie ma postaci o takim id, spróbuj ponownie" << endl;
        }
    }
    czyJestId = false;
    while (!czyJestId) {
        try {
            while (!czyBylo) {
                cin >> wybraneId2;
                if (wybraneId != wybraneId2) {
                    cout << "Wybrana została postać o id: " << wybraneId2 << endl;
                    druzyna.push_back(postacie.at(wybraneId2 - 1));
                    postacie.at(wybraneId2 - 1).setCzyWybrany(true);
                    czyBylo = true;
                } else {
                    cout << "Dana postać została wybrana wcześniej! Spróbuj ponownie" << endl;
                }
            }
            czyJestId = true;
        } catch (const exception &e) {
            cout << "Nie ma postaci o takim id, spróbuj ponownie" << endl;
        }
    }
    czyJestId = false;
    while (!czyJestId) {
        try {
            while (!czyBylo2) {
                cin >> wybraneId3;
                if (wybraneId != wybraneId3 && wybraneId2 != wybraneId3) {
                    cout << "Wybrana została postać o id: " << wybraneId3 << endl;
                    druzyna.push_back(postacie.at(wybraneId3 - 1));
                    postacie.at(wybraneId3 - 1).setCzyWybrany(true);
                    czyBylo2 = true;
                } else {
                    cout << "Dana postać została wybrana wcześniej! Spróbuj ponownie" << endl;
                }
            }
            czyJestId = true;
        } catch (const exception &e) {
            cout << "Nie ma postaci o takim id, spróbuj ponownie" << endl;
        }
    }
    czyJestId = false;
    while (!czyJestId) {
        try {
            while (!czyBylo3) {
                cin >> wybraneId4;
                if (wybraneId != wybraneId4 && wybraneId2 != wybraneId4 && wybraneId3 != wybraneId4) {
                    cout << "Wybrana została postać o id: " << wybraneId4 << endl;
                    druzyna.push_back(postacie.at(wybraneId4 - 1));
                    postacie.at(wybraneId4 - 1).setCzyWybrany(true);
                    czyBylo3 = true;
                } else {
                    cout << "Dana postać została wybrana wcześniej! Spróbuj ponownie" << endl;
                }
            }
            czyJestId = true;
        } catch (const exception &e) {
            cout << "Nie ma postaci o takim id, spróbuj ponownie" << endl;
        }
    }
    czyJestId = false;
    while (!czyJestId) {
        try {
            while (!czyBylo4) {
                cin >> wybraneId5;
                if (wybraneId != wybraneId5 && wybraneId2 != wybraneId5 && wybraneId3 != wybraneId5 &&
                    wybraneId4 != wybraneId5) {
                    cout << "Wybrana została postać o id: " << wybraneId5 << endl;
                    druzyna.push_back(postacie.at(wybraneId5 - 1));
                    postacie.at(wybraneId5 - 1).setCzyWybrany(true);
                    czyBylo4 = true;
                } else {
                    cout << "Dana postać została wybrana wcześniej! Spróbuj ponownie" << endl;
                }
            }
            czyJestId = true;
        } catch (const exception &e) {
            cout << "Nie ma postaci o takim id, spróbuj ponownie" << endl;
        }
    }
    czyJestId = false;
    while (!czyJestId) {
        try {
            while (!czyBylo5) {
                cin >> wybraneId6;
                if (wybraneId != wybraneId6 && wybraneId2 != wybraneId6 && wybraneId3 != wybraneId6 &&
                    wybraneId4 != wybraneId6 && wybraneId5 != wybraneId6) {
                    cout << "Wybrana została postać o id: " << wybraneId6 << endl;
                    druzyna.push_back(postacie.at(wybraneId6 - 1));
                    postacie.at(wybraneId6 - 1).setCzyWybrany(true);
                    czyBylo5 = true;
                } else {
                    cout << "Dana postać została wybrana wcześniej! Spróbuj ponownie" << endl;
                }
            }
            czyJestId = true;
        } catch (const exception &e) {
            cout << "Nie ma postaci o takim id, spróbuj ponownie" << endl;
        }
    }
    randomTeam(wybraneId, wybraneId2, wybraneId3, wybraneId4, wybraneId5, wybraneId6);

    cout << "\nWybrana drużyna: " << endl;
    showElement(druzyna);

    cout << "Czy chcesz poznać swoich przeciwników?" << endl;
    cout << "Tak - 1, Nie - 0" << endl;
    int czyChcesz;
    cin >> czyChcesz;
    if (czyChcesz == 1) {
        cout << "\nPrzeciwnicy: " << endl;
        showElement(przeciwnicy);
    }

    int nrRundy = 1;

    doYouNeedHelp();
    cout << "Wybierz trudność gry" << endl;
    cout << "0 - łatwy, 1 - średni, 2 - trudny" << endl;
    int trudnoscGry;
    cin >> trudnoscGry;
    if (trudnoscGry == 0) {
        for (auto &i: przeciwnicy) {
            double newSila = i.sila - 10;
            i.setSila(newSila);
        }
    } else if (trudnoscGry == 2) {
        for (auto &i: przeciwnicy) {
            double newSila = i.sila + 10;
            i.setSila(newSila);
        }
    }

    while (nrRundy != 5) {
        cout << "Runda " << nrRundy << endl;
        Rozgrywka rozgrywka(przeciwnicy, druzyna, postacie);
        rozgrywka.battle(przeciwnicy, druzyna, postacie);
        nrRundy++;
    }
}

/**
 * metoda wypisujaca dane wektory
 * @tparam T
 * @param element
 */
template<typename T>
void Arena::showElement(vector<T> &element) {
    for (auto &i: element) {
        i.info();
        cout << "\n";
    }
}


/**
 * metoda losująca przeciwników
 */
void Arena::randomTeam(int ID1, int ID2, int ID3, int ID4, int ID5, int ID6) {
    srand(time(NULL));
    int id1;
    int id2;
    int id3;
    int id4;

    bool sprawdzenie = true;
    while (sprawdzenie) {
        id1 = (rand() % 15) + 1;
        if (!postacie.at(id1 - 1).czyWybrany && id1 != ID1 && id1 != ID2 && id1 != ID3 && id1 != ID4 && id1 != ID5 &&
            id1 != ID6) {
            przeciwnicy.push_back(postacie.at(id1 - 1));
            postacie.at(id1 - 1).setCzyWybrany(true);
            sprawdzenie = false;
        }
    }
    bool czyJuzBylo = true;
    while (czyJuzBylo) {
        id2 = (rand() % 15) + 1;
        if (id1 != id2 && !postacie.at(id2 - 1).czyWybrany && id2 != ID1 && id2 != ID2 && id2 != ID3 && id2 != ID4 &&
            id2 != ID5 && id2 != ID6) {
            przeciwnicy.push_back(postacie.at(id2 - 1));
            postacie.at(id2 - 1).setCzyWybrany(true);
            czyJuzBylo = false;
        }
    }
    czyJuzBylo = true;
    while (czyJuzBylo) {
        id3 = (rand() % 15) + 1;
        if (id1 != id3 && id2 != id3 && !postacie.at(id3 - 1).czyWybrany && id3 != ID1 && id3 != ID2 && id3 != ID3 &&
            id3 != ID4 && id3 != ID5 && id3 != ID6) {
            przeciwnicy.push_back(postacie.at(id3 - 1));
            postacie.at(id3 - 1).setCzyWybrany(true);
            czyJuzBylo = false;
        }
    }
    czyJuzBylo = true;
    while (czyJuzBylo) {
        id4 = (rand() % 15) + 1;
        if (id1 != id4 && id2 != id4 && id3 != id4 && !postacie.at(id4 - 1).czyWybrany && id4 != ID1 && id4 != ID2 &&
            id4 != ID3 && id4 != ID4 && id4 != ID5 && id4 != ID6) {
            postacie.at(id4 - 1).setCzyWybrany(true);
            przeciwnicy.push_back(postacie.at(id4 - 1));
            czyJuzBylo = false;
        }
    }
}

/**
 * metoda udzielająca pomocy graczowi
 */
void Arena::doYouNeedHelp() {
    cout << "czy potrzebujesz pomocy?" << endl;
    cout << "jeśli tak wpisz '--h', jeśli nie wpisz 'nie'" << endl;
    string pomoc;
    cin >> pomoc;
    if (pomoc == "--h") {
        help.help();
    } else {
        return;
    }
}

