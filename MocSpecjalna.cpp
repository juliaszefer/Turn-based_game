//
// Created by Julia Szefer on 12/06/2022.
//

/**
 * tworzenie obiektów i wektorów dla mocy specjalnych
 */

#include "MocSpecjalna.h"
#include "MockMocSpecjalna.h"

MockMocSpecjalna mocSpecjalna1("rzut ognistą kulą", 10, 2);
MockMocSpecjalna mocSpecjalna2("zianie ogniem", 7, 2);
MockMocSpecjalna mocSpecjalna3("ogniste oczy", 5, 2);
MockMocSpecjalna mocSpecjalna4("rzut kamieniem", 10, 2);
MockMocSpecjalna mocSpecjalna5("kamienne tornado", 7, 2);
MockMocSpecjalna mocSpecjalna6("zabójcze korzenie", 5, 2);
MockMocSpecjalna mocSpecjalna7("tornado", 10, 2);
MockMocSpecjalna mocSpecjalna8("pioruny", 7, 2);
MockMocSpecjalna mocSpecjalna9("powietrzny shuriken", 5, 2);
MockMocSpecjalna mocSpecjalna10("wodne igły", 10, 2);
MockMocSpecjalna mocSpecjalna11("tsunami", 7, 2);
MockMocSpecjalna mocSpecjalna12("uderzenie językiem", 5, 2);
MockMocSpecjalna mocSpecjalna13("zamrożenie", 10, 2);
MockMocSpecjalna mocSpecjalna14("atak soplami lodu", 10, 2);
MockMocSpecjalna mocSpecjalna15("stalowy młot", 7, 2);
MockMocSpecjalna mocSpecjalna16("płomienna tarcza", 10, 2);
MockMocSpecjalna mocSpecjalna17("pancerz z lawy", 7, 2);
MockMocSpecjalna mocSpecjalna18("ognista zasłona", 5, 2);
MockMocSpecjalna mocSpecjalna19("tarcza z ziemi", 10, 2);
MockMocSpecjalna mocSpecjalna20("kamienna garda", 7, 2);
MockMocSpecjalna mocSpecjalna21("liściasta kula", 5, 2);
MockMocSpecjalna mocSpecjalna22("powietrzne odepchnięcie", 10, 2);
MockMocSpecjalna mocSpecjalna23("pochmurna zasłona", 7, 2);
MockMocSpecjalna mocSpecjalna24("silny podmuch wiatru", 5, 2);
MockMocSpecjalna mocSpecjalna25("wodna tarcza", 10, 2);
MockMocSpecjalna mocSpecjalna26("zalanie wodą", 7, 2);
MockMocSpecjalna mocSpecjalna27("toksyczny kwas", 5, 2);
MockMocSpecjalna mocSpecjalna28("lodowa tarcza", 10, 2);
MockMocSpecjalna mocSpecjalna29("lodowy podmuch", 10, 2);
MockMocSpecjalna mocSpecjalna30("stalowa tarcza", 7, 2);


MocSpecjalna::MocSpecjalna() {

}

/**
 * dodawanie mocy do wektora z mocami defensywy
 * @param moceDEF
 */
void MocSpecjalna::addToDef(vector<MockMocSpecjalna> &moceDEF) {
    moceDEF.push_back(mocSpecjalna16);
    moceDEF.push_back(mocSpecjalna17);
    moceDEF.push_back(mocSpecjalna18);
    moceDEF.push_back(mocSpecjalna19);
    moceDEF.push_back(mocSpecjalna20);
    moceDEF.push_back(mocSpecjalna21);
    moceDEF.push_back(mocSpecjalna22);
    moceDEF.push_back(mocSpecjalna23);
    moceDEF.push_back(mocSpecjalna24);
    moceDEF.push_back(mocSpecjalna25);
    moceDEF.push_back(mocSpecjalna26);
    moceDEF.push_back(mocSpecjalna27);
    moceDEF.push_back(mocSpecjalna28);
    moceDEF.push_back(mocSpecjalna29);
    moceDEF.push_back(mocSpecjalna30);
}

/**
 * dodawanie mocy do wektora ofensywy
 * @param moceOF
 */
void MocSpecjalna::addToOf(vector<MockMocSpecjalna> &moceOF) {
    moceOF.push_back(mocSpecjalna1);
    moceOF.push_back(mocSpecjalna2);
    moceOF.push_back(mocSpecjalna3);
    moceOF.push_back(mocSpecjalna4);
    moceOF.push_back(mocSpecjalna5);
    moceOF.push_back(mocSpecjalna6);
    moceOF.push_back(mocSpecjalna7);
    moceOF.push_back(mocSpecjalna8);
    moceOF.push_back(mocSpecjalna9);
    moceOF.push_back(mocSpecjalna10);
    moceOF.push_back(mocSpecjalna11);
    moceOF.push_back(mocSpecjalna12);
    moceOF.push_back(mocSpecjalna13);
    moceOF.push_back(mocSpecjalna14);
    moceOF.push_back(mocSpecjalna15);
}
