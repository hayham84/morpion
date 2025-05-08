#include <iostream>
#include "tictactoe.h"

extern "C" {
    TicTacToe partie;

    // Initialisation du jeu
    void initPartie(int firstPlayer) {
        partie = TicTacToe();
        partie.jouer(firstPlayer == 0 ? 0 : -1, 0); // Initialiser juste pour exemple
    }

    // Mouvement de l'humain
    int jouerHumain(int position) {
        if (!partie.vide(position)) return -1; // case occupée
        partie.jouer(position, -1);
        return partie.arbitre(); // -2 si en cours, -1 si humain gagne, 0 égalité, 1 ordi gagne
    }

    // Mouvement de l'ordinateur
    int jouerOrdi() {
        int bestMove;
        partie.JeuOrdi(bestMove);
        partie.jouer(bestMove, 1);
        return bestMove;
    }

    // Accéder à la case du plateau
    int getCase(int i, int j) {
        return partie.getCase(i, j);
    }
}
