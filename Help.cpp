//
// Created by Julia Szefer on 17/06/2022.
//

#include "Help.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * metoda udzielająca pomocy
 */
void Help::help() {
    cout
            << "Jeżeli tu dotarłeś to najwyraźniej potrzebujesz pomocy:)\n"
               "Cała rozgrywka bazuje na dobrym doborze swojej\n"
               "drużyny i dobrym zarządzaniu mocami specjalnymi.\n"
               "Do wyboru opcji używana jest konsola.\n"
               "W trakcie gry możesz dokonoać wyboru między jej poziomem trudności\n"
               "oraz jakim stworzeniem zagrasz i co z nim przed rozgrywką zrobisz.\n"
               "Stworzenia mogą ewoluować, co w tym wypadku oznacza zwiększenie ich\n"
               "punktów życia. Ewolucja jest możliwa tylko w wypadku, gdy gracz uzbiera\n"
               "odpowiednią ilość EXP. Mogą one również używac umiejętności specjalnych, które\n"
               "zwiększają ich siłę. Ostatnią opcją jest wymiana stworzenia\n"
               "jeśli dokonało się złego wyboru. Miłej gry!"
            << endl;
    string exit;
    cout << "\nWpisz 'exit', aby powrócić do gry" << endl;
    cin >> exit;
    if (exit == "exit") {
        cout << "Powodzenia!" << endl;
    }
}
