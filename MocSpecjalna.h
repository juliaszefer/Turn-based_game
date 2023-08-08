//
// Created by Julia Szefer on 12/06/2022.
//

#ifndef INC_2122_PJC_18C_PL_S24690_MOCSPECJALNA_H
#define INC_2122_PJC_18C_PL_S24690_MOCSPECJALNA_H

#include <map>
#include <string>
#include "MockMocSpecjalna.h"

using namespace std;

class MocSpecjalna {
public:
    MocSpecjalna();

    void addToOf(vector<MockMocSpecjalna> &moceOF);

    void addToDef(vector<MockMocSpecjalna> &moceDEF);
};


#endif //INC_2122_PJC_18C_PL_S24690_MOCSPECJALNA_H
