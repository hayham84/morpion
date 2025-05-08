#include <iostream>
#include <random>   
#include "tictactoe.h"
using namespace std;


void TicTacToe::affichage()
{
   /*  cout << "  ---------" << endl;
    cout << "  " << T[0][0] << " | " << T[0][1] << " | " << T[0][2] << endl;
    cout << "  ---------" << endl;
    cout << "  " << T[1][0] << " | " << T[1][1] << " | " << T[1][2] << endl;
    cout << "  ---------" << endl;
    cout << "  " << T[2][0] << " | " << T[2][1] << " | " << T[2][2] << endl;
    cout << "  ---------" << endl; */
    cout << "  ---------" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "  ";
        for (int j = 0; j < 3; ++j)
        {
            if (T[i][j] == -1)
                cout << "X";
            else if (T[i][j] == 1)
                cout << "O";
            else
                cout << " "; // Case vide
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "  ---------" << endl;
    }
    cout << "  ---------" << endl;
}

bool TicTacToe::plein()
{
    for (int i = 0; i < 3; i++)
    {
         for ( int j = 0; j < 3; j++ )
        {
            if ( T[i][j] == 0 )
            {
                return false;
            }
        }
    }
    return true;
}

int TicTacToe::arbitre()
{
    for (int i = 0; i < 3; i++) 
    {
        // vérification de chaque ligne si elle sont remplie et si elle ont les même valeur alors on retourne la valeur de l'une d'entre elle
        if ( T[i][0] != 0  and T[i][0] ==  T[i][1] and T[i][1] ==  T[i][2] ) return T[i][2];
    }
    for (int i = 0; i < 3; i++) 
    {
        // vérification de chaque colonne si elle sont remplie et si elle ont les même valeur alors on retourne la valeur de l'une d'entre elle
        if ( T[0][i] != 0  and T[0][i] ==  T[1][i] and T[1][i] ==  T[2][i] ) return T[2][i];
    }
    // vérification des 2 diagonales 
    if ( T[0][0] != 0  and T[0][0] ==  T[1][1] and T[1][1] ==  T[2][2] ) return T[2][2];
    if ( T[0][2] != 0  and T[0][2] ==  T[1][1] and T[1][1] ==  T[2][0] ) return T[2][0];
    if (!plein()) return -2;
    return 0;
}

bool TicTacToe::coupgagnant(int joueur, int &bestMove) 
{
    // Parcourir toutes les cases de la grille
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (T[i][j] == 0) // Vérifier si la case est vide
            { 
                int cas = i * 3 + j; // Convertir les indices en un seul entier

                // Simuler le coup
                jouer(cas,joueur);

                // Vérifier si ce coup permet au joueur de gagner
                if (arbitre() == joueur) 
                {
                    bestMove = cas; // Calculer la position linéaire
                    déjouer(cas); // Réinitialiser la case
                    return true; // Coup gagnant trouvé
                }

                // Réinitialiser la case
               déjouer(cas);
            }
        }
    }
    return false; // Aucun coup gagnant trouvé
}

bool TicTacToe::vide(int i)
{
    int ligne = i/3;
    int colonne = i%3;
    if ( T[ligne][colonne] == 0 ) return true;
    return false;
}

void TicTacToe::jouer(int i, int joueur)
{
    int ligne = i/3;
    int colonne = i%3;
    T[ligne][colonne] = joueur;

}

void TicTacToe::déjouer(int i) 
{
    int ligne = i/3;
    int colonne = i%3;
    T[ligne][colonne] = 0;
}

int TicTacToe::JeuOrdi(int & bestMove) 
{
    if (plein())
    {
        return(0);
    }
    if (coupgagnant(ORDI,bestMove))
    {
        return VORDI;
    }
    int val = HUMAIN;
    for ( int i = 0; i < 9; i++ )
    {
        if (vide(i))
        {
            jouer(i,ORDI);
            res = JeuHumain(bestMove);
            if ( res > val )
            {
                val = res;
                bestMove = i;
            }
            déjouer(i);
        }
    }
    return val;
}

int TicTacToe::JeuHumain(int & bestMove)
{
    if (plein())
    {
        return(0);
    }
    if (coupgagnant(HUMAIN,bestMove))
    {
        return VHUMAIN;
    }
    val = ORDI;
    for ( int i = 0; i < 9; i++ )
    {
        if (vide(i))
        {
            jouer(i,HUMAIN);
            res = JeuOrdi(bestMove);
            if ( res < val )
            {
                val = res;
                bestMove = i;
            }
            déjouer(i);
        }
    }
    return val;
}
