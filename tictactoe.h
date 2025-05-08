#include <iostream>
#include <random>   
#define tictactoe
using namespace std;

class TicTacToe
{
    int T[3][3]; //représentant la grille du jeu.
    int VORDI;
    int VHUMAIN;
    int ORDI;
    int HUMAIN;
    int res;
    int val;

    public :
        TicTacToe() //le constructeur de la classe permettant d’initialiser T à 0.
        {
            VORDI = 1;
            VHUMAIN = -1;
            ORDI = 1;
            HUMAIN = -1;
            for ( int i = 0; i < 3; i++ )
            {
                for ( int j = 0; j < 3; j++ )
                {
                    T[i][j] = 0;
                }
            }
        } 
        void affichage(); // méthode affichant le contenu de T.
        int JeuOrdi(int & bestMove); 
        int JeuHumain(int & bestMove);
        int arbitre();
        bool plein();
        bool coupgagnant(int joueur,int & bestMove);
        bool vide(int i);
        void jouer(int i, int joueur);
        void déjouer(int i);

};