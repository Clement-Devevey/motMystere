#include "fonctions.h"

using namespace std;

int main()
{
    /* Variables */
    string mot_mystere;
    string shuffledMotMystere;
    vector<int> score;
    char tryAgain = 'y';
    size_t nbLignes;
    int rand_line;
    
    /* Compte ligne du fichier */
    nbLignes = count_line("dico.txt");

    /* Random pour prendre un mot au pif dans le dico */
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(1, nbLignes);


    /* boucle pour rejouer */
    do
    {
        /* 1) Récupération du mot mystère */
        /*
        askMotMystere(mot_mystere);
        cout << "Mot à trouver : " << mot_mystere << endl << endl;
        */
        rand_line = distrib(gen);

        ifstream f_file("dico.txt");  //Ouverture d'un fichier en lecture
        GotoLine(f_file, rand_line); // On se déplace à la ligne précédemment randomisée
        f_file >> mot_mystere; // On récupère ce mot

        /* 2) Suffle du mot */
        shuffleMot(mot_mystere, shuffledMotMystere);

        /* 3) clear console : https://www.delftstack.com/fr/howto/cpp/how-to-clear-console-cpp/ */
        cout << "\x1B[2J\x1B[H";

        /* 4) User 2 has to find the correct word : */
        userTry(mot_mystere, shuffledMotMystere, score);

        cout << "Souhaitez-vous refaire une partie ? y/n : ";
        cin >> tryAgain;
        SautDeLigne();

    } while(tryAgain == 'y');

    return 0;
}