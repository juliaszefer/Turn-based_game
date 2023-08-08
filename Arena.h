//
// Created by Julia Szefer on 12/06/2022.
//

#ifndef INC_2122_PJC_18C_PL_S24690_ARENA_H
#define INC_2122_PJC_18C_PL_S24690_ARENA_H

#include <vector>
#include "Postac.h"

using namespace std;

class Arena {

public:
    void game();

    template<typename T>
    void showElement(vector<T> &element);

    static void randomTeam(int ID1, int ID2, int ID3, int ID4, int ID5, int ID6);

    void doYouNeedHelp();

};


#endif //INC_2122_PJC_18C_PL_S24690_ARENA_H
