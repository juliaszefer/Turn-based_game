//
// Created by Julia Szefer on 12/06/2022.
//

/**
 * klasa implementująca rozgrywkę
 */

#include "MocSpecjalna.h"
#include "MockMocSpecjalna.h"
#include "Rozgrywka.h"
#include "Postac.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <ostream>

using namespace std;
string directoryPath = "./data/statystyki.txt";
Postac gracz;
Postac przeciwnik;
vector<MockMocSpecjalna> moceOF;
vector<MockMocSpecjalna> moceDEF;
MocSpecjalna mocSpecjalna;


Rozgrywka::Rozgrywka(vector<Postac> &przeciwnicy, vector<Postac> &druzyna, vector<Postac> &postacie) {
    przeciwnicyR = przeciwnicy;
    druzynaR = druzyna;
    postacieR = postacie;
}

/**
 * wypisywanie wybranych wektorów
 * @tparam T
 * @param element
 */
template<typename T>
void Rozgrywka::showElement(vector<T> &element) {
    for (auto &i: element) {
        if (i.HP > 0) {
            i.info();
            cout << "\n";
        }
    }
}

/**
 * bitwa
 */
void Rozgrywka::battle(vector<Postac> &przeciwnicy, vector<Postac> &druzyna, vector<Postac> &postacie) {
    mocSpecjalna.addToOf(moceOF);
    mocSpecjalna.addToDef(moceDEF);
    cout << "Twoja drużyna: " << endl;
    showElement(druzyna);
    cout << "Wybierz stworzenie z drużyny, którym chcesz zagrać wpisując jego id: " << endl;

    int wybraneId = 0;
    bool czyIstniejeId = false;

    choosePlayer(czyIstniejeId, wybraneId, gracz, druzyna);

    srand(time(NULL));
    int idPrzeciwnik = rand() % 3;
    bool czyMoznaWybrac = true;
    while (czyMoznaWybrac) {
        if (przeciwnicy.at(idPrzeciwnik).czyZyje) {
            przeciwnik = przeciwnicy.at(idPrzeciwnik);
            czyMoznaWybrac = false;
        }
    }

    cout << "----- " << gracz.nazwa << " vs " << przeciwnik.nazwa << " -----" << endl;

    while (gracz.HP > 0 && przeciwnik.HP > 0) {
        choices:
        cout << "Co chcesz zrobić?" << endl;
        cout << "1. Użycie umiejętności specjalnej\n2. Wymiana stworzenia\n3. Ewolucja stworzenia\n4. Nic" << endl;
        int wybranaOpcja;
        cin >> wybranaOpcja;
        if (wybranaOpcja == 1) {
            cout << "Czy chcesz użyć umiejętności specjalnej w ofensywie - 1 czy defensywie - 2?" << endl;
            int OFczyDEF;
            cin >> OFczyDEF;

            if (OFczyDEF == 1) {
                if (moceOF.at(gracz.id - 1).iloscUzycM > 0) {
                    double newSila = gracz.sila + moceOF.at(gracz.id - 1).mocM;
                    int newIloscUyzc = moceOF.at(gracz.id - 1).iloscUzycM - 1;
                    moceOF.at(gracz.id - 1).iloscUzycM = newIloscUyzc;
                    gracz.setSila(newSila);
                } else {
                    cout << "Nie możesz już używać mocy specjalnych w ofensywie" << endl;
                    goto choices;
                }
            } else if (OFczyDEF == 2) {
                if (moceDEF.at(gracz.id - 1).iloscUzycM > 0) {
                    double newSila = przeciwnik.sila - moceDEF.at(przeciwnik.id - 1).mocM;
                    int newIloscUzyc = moceDEF.at(gracz.id - 1).iloscUzycM - 1;
                    moceDEF.at(gracz.id - 1).iloscUzycM = newIloscUzyc;
                    gracz.setSila(newSila);
                } else {
                    cout << "Nie możesz już używać mocy specjalnych w defensywie" << endl;
                    goto choices;
                }
            } else {
                cout << "Nie poprawnia wybrana opcja" << endl;
                goto choices;
            }

        } else if (wybranaOpcja == 2) {

            czyIstniejeId = false;
            wybraneId = 0;
            cout << "Wybierz stworzenie z drużyny, którym chcesz zagrać wpisując jego id: " << endl;
            choosePlayer(czyIstniejeId, wybraneId, gracz, druzyna);

        } else if (wybranaOpcja == 3) {

            if (gracz.EXP > 20) {
                double newSila = gracz.sila + 5;
                gracz.setSila(newSila);
                double newEXP = gracz.EXP - 20;
                gracz.setEXP(newEXP);
            } else {
                cout << "masz za mało puntków by twoja postać mogła przejść ewolucje" << endl;
                goto choices;
            }

        } else if (wybranaOpcja == 4) {
            cout << "Gotowi? Start!" << endl;
        } else {
            cout << "niepoprawnie wybrana opcja" << endl;
            goto choices;
        }

        string typ1 = gracz.typ;
        string typ2 = przeciwnik.typ;
        double zrecznosc1 = gracz.zrecznosc;
        double zrecznosc2 = przeciwnik.zrecznosc;
        boostZrecznosc(typ1, typ2);

        double prawdopodobienstwoGracz = 10 * gracz.zrecznosc;
        double prawdopodobienstwoPrzeciwnik = 10 * przeciwnik.zrecznosc;
        int tabPrawGracz[10];
        int tabPrawPrzeciwnik[10];
        for (int i = 0; i <= prawdopodobienstwoGracz; i++) {
            tabPrawGracz[i] = 1;
        }
        for (int i = (int) prawdopodobienstwoGracz + 1; i < 10; i++) {
            tabPrawGracz[i] = 0;
        }
        for (int i = 0; i <= prawdopodobienstwoPrzeciwnik; i++) {
            tabPrawPrzeciwnik[i] = 1;
        }
        for (int i = (int) prawdopodobienstwoPrzeciwnik + 1; i < 10; i++) {
            tabPrawPrzeciwnik[i] = 0;
        }
        int losowyIndeksGracz = rand() % 9;
        int losowyIndeksPrzeciw = rand() % 9;

        cout << "Gracz przed: " << gracz.HP << "HP" << endl;
        cout << "Przeciwnik przed: " << przeciwnik.HP << "HP" << endl;

        if (tabPrawGracz[losowyIndeksGracz] == 1 && tabPrawPrzeciwnik[losowyIndeksPrzeciw] == 0) {
            double newHPP = przeciwnik.HP - gracz.sila;
            przeciwnik.setHP(newHPP);
        } else if (tabPrawGracz[losowyIndeksGracz] == 0 && tabPrawPrzeciwnik[losowyIndeksPrzeciw] == 1) {
            double newHPG = gracz.HP - przeciwnik.sila;
            gracz.setHP(newHPG);
        } else if (tabPrawGracz[losowyIndeksGracz] == 0 && tabPrawPrzeciwnik[losowyIndeksPrzeciw] == 0) {
            double newHPG = gracz.HP - przeciwnik.sila;
            double newHPP = przeciwnik.HP - gracz.sila;
            gracz.setHP(newHPG);
            przeciwnik.setHP(newHPP);
        }
        cout << "Gracz po: " << gracz.HP << "HP" << endl;
        cout << "Przeciwnik po: " << przeciwnik.HP << "HP" << endl;

        double newHPG = gracz.HP;

        for (auto &i: druzyna) {
            if (i.id == gracz.id) {
                i.setHP(newHPG);
            }
        }

        double newHPP = przeciwnik.HP;

        for (auto &i: przeciwnicy) {
            if (i.id == przeciwnik.id) {
                i.setHP(newHPP);
            }
        }

        gracz.setZrecznosc(zrecznosc1);
        przeciwnik.setZrecznosc(zrecznosc2);

        if (gracz.HP <= 0) {
            postacie.at(gracz.id - 1).setCzyZyje(false);
            for (auto &i: druzyna) {
                if (i.id == gracz.id) {
                    i.setCzyZyje(false);
                }
            }
        } else if (przeciwnik.HP <= 0) {
            postacie.at(przeciwnik.id - 1).setCzyZyje(false);
            for (auto &i: przeciwnicy) {
                if (i.id == przeciwnik.id) {
                    i.setCzyZyje(false);
                }
            }
            double newEXP = przeciwnik.EXP + gracz.EXP;
            postacie.at(gracz.id - 1).setEXP(newEXP);
            for (auto &i: druzyna) {
                if (i.id == gracz.id) {
                    i.setEXP(newEXP);
                }
            }
        }
    }

}

/**
 * próba zapisania wyników do pliku
 */
void Rozgrywka::saveGame() {
//    fstream fileOut;
//    fileOut.open(directoryPath, ios::out);
//    if (fileOut.is_open()) {
//        for (auto &i: postacieR) {
//            fileOut << i.id << ";" << i.nazwa << ";" << i.sila << ";" << i.HP << ";" << i.zrecznosc << ";"
//                    << i.mocSpecjalnaOF << ";" << i.mocSpecjalnaDEF << ";" << i.EXP << ";" << i.typ << ";" << i.czyZyje << "\n";
//            fileOut.close();
//        }
//    }
//    writePostacie(ofstream{directoryPath}, postacieR);
}

/**
 * próba odczytania wyników z pliku
 */
void Rozgrywka::readGame() {
//    fstream fileIn;
//    fileIn.open(directoryPath, ios::in);
//    if (fileIn.is_open()) {
//
//        string line;
//        while (getline(fileIn, line)) {
//                postacieR.push_back(line);
//        }
//    }

}

/**
 * wybór postaci na dana rundę
 * @param czyIstniejeId
 * @param wybraneId
 * @param gracz
 */
void Rozgrywka::choosePlayer(bool czyIstniejeId, int wybraneId, Postac &gracz, vector<Postac> &druzyna) {
    while (!czyIstniejeId) {
        cin >> wybraneId;
        int counter = 0;

        for (auto &i: druzyna) {
            if (i.id == wybraneId && i.HP > 0) {
                gracz = i;
                counter++;
                czyIstniejeId = true;
            }
        }
        if (counter == 0) {
            cout << "Wybranego stworzenia nie ma w twojej drużynie" << endl;
        }
    }
}

/**
 * metoda zmieniajaca zrecznosc w zaleznosci od typu postaci
 * @param typ1
 * @param typ2
 */
void Rozgrywka::boostZrecznosc(const string &typ1, const string &typ2) {
    if (typ1 == "woda" && typ2 == "woda" || typ1 == "woda" && typ2 == "ogien" || typ1 == "woda" && typ2 == "lód" ||
        typ1 == "ziemia" && typ2 == "powietrze" || typ1 == "ziemia" && typ2 == "ogien" ||
        typ1 == "powietrze" && typ2 == "ziemia" || typ1 == "ogien" && typ2 == "lód" ||
        typ1 == "ogien" && typ2 == "stal" || typ1 == "lód" && typ2 == "lód" || typ1 == "stal" && typ2 == "powietrze" ||
        typ1 == "stal" && typ2 == "stal") {
        double newZrecznosc = gracz.zrecznosc - 0.1;
        gracz.setZrecznosc(newZrecznosc);
    } else if (typ1 == "woda" && typ2 == "stal" || typ1 == "ziemia" && typ2 == "woda" ||
               typ1 == "ziemia" && typ2 == "lód" || typ1 == "powietrze" && typ2 == "stal" ||
               typ1 == "ogien" && typ2 == "woda" || typ1 == "ogien" && typ2 == "ziemia" ||
               typ1 == "lód" && typ2 == "ziemia" || typ1 == "lód" && typ2 == "powietrze" ||
               typ1 == "lód" && typ2 == "ogien" || typ1 == "stal" && typ2 == "ziemia" ||
               typ1 == "stal" && typ2 == "ogien") {
        double newZrecznosc = gracz.zrecznosc + 0.1;
        gracz.setZrecznosc(newZrecznosc);
    }
}

/**
 * ciag dalszy prob zapisania i odczytania z pliku
 */
//void Rozgrywka::writePostacie(ostream &o, const vector<Postac> &postacie) {
//    for (auto &i: postacie) {
//        o << i.id << ";" << i.nazwa << ";" << i.sila << ";" << i.HP << ";" << i.zrecznosc << ";"
//          << i.mocSpecjalnaOF << ";" << i.mocSpecjalnaDEF << ";" << i.EXP << ";" << i.typ << ";" << i.czyZyje << ";"
//          << i.czyWybrany << "\n";
//    }
//}

//void Rozgrywka::writePostacie(ostream &&o, const vector<Postac> &postacie) {
//    writePostacie(o, postacie);
//}

//auto Rozgrywka::readPostacie(istream &i) -> vector<Postac> {
//    vector<Postac> postacie;
//    auto line = string{};
//
//    while(getline(i, line)){
//        auto pos = line.find_first_of(';');
//        postacie.push_back(new Postac{string{line, 0, pos}, string{line, pos + 1}, string{line, 0, pos}, string{line, 0, pos}, string{line, 0, pos}, string{line, 0, pos}, string{line, 0, pos}, string{line, 0, pos}, string{line, 0, pos}, string{line, 0, pos}, string{line, 0, pos}});
//    }
//}

