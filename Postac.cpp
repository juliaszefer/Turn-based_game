//
// Created by Julia Szefer on 11/06/2022.
//

#include "Postac.h"
#include <iostream>
#include <vector>

/**
 * klasa zawierajaca wszystkie metody dla postaci gry
 */

/**
 * konstruktor
 * @param idAlt
 * @param nazwaAlt
 * @param silaAlt
 * @param HPalt
 * @param zrecznoscAlt
 * @param mocSpecjalnaOFAlt
 * @param mocSpecjalnaDEFAlt
 * @param EXPalt
 * @param typAlt
 * @param czyZyjeAlt
 * @param czyWybranyAlt
 */
Postac::Postac(int idAlt, string nazwaAlt, double silaAlt, double HPalt, double zrecznoscAlt, string mocSpecjalnaOFAlt,
               string mocSpecjalnaDEFAlt, double EXPalt, string typAlt, bool czyZyjeAlt, bool czyWybranyAlt) {
    id = idAlt;
    nazwa = nazwaAlt;
    sila = silaAlt;
    HP = HPalt;
    zrecznosc = zrecznoscAlt;
    mocSpecjalnaOF = mocSpecjalnaOFAlt;
    mocSpecjalnaDEF = mocSpecjalnaDEFAlt;
    EXP = EXPalt;
    typ = typAlt;
    czyZyje = czyZyjeAlt;
    czyWybrany = czyWybranyAlt;
}

/**
 * wypisanie informacji o postaci
 */
void Postac::info() {
    cout << "\nid: " << id << "\nStworzenie: " << nazwa << "\nHealth points: " << HP << "\nzręczność: " << zrecznosc
         << "\nmoc specjalna ofensywa: " << mocSpecjalnaOF << "\nmoc specjalna defensywa: " << mocSpecjalnaDEF
         << "\ntyp: " << typ;
}

Postac::Postac() {

}

/**
 * metoda zmieniająca punkty życia
 * @param newHP
 * @return
 */
Postac &Postac::setHP(double newHP) {
    HP = newHP;
    return *this;
}

/**
 * metoda zmieniająca siłę
 * @param newSila
 * @return
 */
Postac &Postac::setSila(double newSila) {
    sila = newSila;
    return *this;
}

/**
 * metoda zmieniająca status czyZyje
 * @param newCzyZyje
 * @return
 */
Postac &Postac::setCzyZyje(bool newCzyZyje) {
    czyZyje = newCzyZyje;
    return *this;
}

/**
 * metoda zmieniajaca zrecznosc
 * @param newZrecznosc
 * @return
 */
Postac &Postac::setZrecznosc(double newZrecznosc) {
    zrecznosc = newZrecznosc;
    return *this;
}

/**
 * metoda naliczająca punkty za wygrana
 * @param newEXP
 * @return
 */
Postac &Postac::setEXP(double newEXP) {
    EXP = newEXP;
    return *this;
}

/**
 * metoda sprawdzająca czy dane stworzenie zostało już wybrane
 * @param newCzyWybrany
 * @return
 */
Postac &Postac::setCzyWybrany(bool newCzyWybrany) {
    czyWybrany = newCzyWybrany;
    return *this;
}









