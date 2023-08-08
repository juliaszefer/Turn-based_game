#include <iostream>
#include "Arena.h"

/**
 * gra turowa
 * @return
 */
int main() {
    Arena arena;
    int czyKoniec = 1;
    while (czyKoniec == 1) {
        arena.game();
        cout << "Dziękuję za grę! Jeśli chcesz ją powtórzyć wpisz - 1, jeśli chcesz zakończyć - 0" << endl;
        cin >> czyKoniec;
        if (czyKoniec == 0) {
            cout << "Do zobaczenia!" << endl;
        }
    }

}