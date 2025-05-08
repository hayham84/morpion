#include <iostream>
#include "tictactoe.h"

using namespace std;

int main() {
    int bestMove;
    TicTacToe partie;
    srand(time(0));

    int piece = rand() % 2; // Déterminer qui commence
    cout << "Tirage au sort : ";
    if (piece == 0) cout << "L'ordinateur commence.\n";
    else cout << "L'humain commence.\n";

    partie.affichage();

    while (partie.arbitre() == -2) 
    {
        int res;
        if (piece == 0) 
        {
            partie.JeuOrdi(bestMove);
            partie.jouer(bestMove,1);
            cout << "Ordinateur joue à la position : " << bestMove << endl;
        } 
        else 
        {
            cout << "Entrez votre coup (0-8) : ";
            cin >> bestMove;
            while (!partie.vide(bestMove)) 
            {
                cout << "Case déjà occupée. Essayez une autre case : ";
                cin >> bestMove;
            }
            partie.jouer(bestMove, -1);
        }

        partie.affichage();
        piece = 1 - piece; // Alterner les tours
    }

    switch (partie.arbitre())
    {
    case 1 :
        cout << "L'ordinateur a gagné !" << endl;
        break;
    case -1 :
        cout << "Vous avez gagné !" << endl;
        break;
    case 0 :
        cout << "Match nul !" << endl;
        break;
    }

    return 0;
}