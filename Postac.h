//
// Created by Julia Szefer on 11/06/2022.
//

#ifndef INC_2122_PJC_18C_PL_S24690_POSTAC_H
#define INC_2122_PJC_18C_PL_S24690_POSTAC_H

#include <string>
#include <vector>

using namespace std;

class Postac {
public:
    int id;
    string nazwa;
    double sila;
    double HP;
    double zrecznosc;
    string mocSpecjalnaOF;
    string mocSpecjalnaDEF;
    double EXP;
    string typ;
    bool czyZyje;
    bool czyWybrany;

    Postac();

    Postac(int idAlt, string nazwaAlt, double silaAlt, double HPalt, double zrecznoscAlt, string mocSpecjalnaOFAlt,
           string mocSpecjalnaDEFAlt, double EXPalt, string typAlt, bool czyZyjeAlt, bool czyWybranyAlt);

    void info();

    Postac &setHP(double newHP);

    Postac &setSila(double newSila);

    Postac &setCzyZyje(bool newCzyZyje);

    Postac &setZrecznosc(double newZrecznosc);

    Postac &setEXP(double newEXP);

    Postac &setCzyWybrany(bool newCzyWybrany);

};


#endif //INC_2122_PJC_18C_PL_S24690_POSTAC_H
