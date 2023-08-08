//
// Created by Julia Szefer on 12/06/2022.
//

#ifndef INC_2122_PJC_18C_PL_S24690_ROZGRYWKA_H
#define INC_2122_PJC_18C_PL_S24690_ROZGRYWKA_H

#include "Postac.h"
#include <vector>
#include <string>
#include <ostream>

using namespace std;

class Rozgrywka {
    vector<Postac> przeciwnicyR;
    vector<Postac> druzynaR;
    vector<Postac> postacieR;

public:
    Rozgrywka(vector<Postac> &przeciwnicy, vector<Postac> &druzyna, vector<Postac> &postacie);

    void battle(vector<Postac> &przeciwnicy, vector<Postac> &druzyna, vector<Postac> &postacie);

    template<typename T>
    void showElement(vector<T> &element);

    void choosePlayer(bool czyIstniejeId, int wybraneId, Postac &gracz, vector<Postac> &druzyna);

    static void boostZrecznosc(const string &typ1, const string &typ2);

    void saveGame();

    void readGame();

//    static void writePostacie(ostream& o, const vector<Postac>& postacie);

//    static void writePostacie(ostream&& o, const vector<Postac>& postacie);

//    static auto readPostacie(istream& i) -> vector<Postac>;
};


#endif //INC_2122_PJC_18C_PL_S24690_ROZGRYWKA_H
