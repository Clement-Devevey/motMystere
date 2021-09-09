#include "fonctions.h"
using namespace std;

size_t count_line(string const & filename)
{
    ifstream f_file(filename);  //Ouverture d'un fichier en lecture
    size_t nbLignes = 0;
    if(f_file)
    {
      string ligne; //Une variable pour stocker les lignes lues

      while(f_file.ignore(numeric_limits<streamsize>::max() ,'\n')) // Compte les retours à la ligne, sans restriction de longueur entre 2 items. Plus opti que getline()
      {
        nbLignes++;
      }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return nbLignes-1; // On compte une ligne en trop
}

ifstream& GotoLine(ifstream& file, const int& num)
{
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i)
    {
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}

void SautDeLigne()
{
    cout <<  endl <<  endl;
}

void askMotMystere( string& mot)
{
    cout << "Mot mystere : ";
    cin >> mot;
    SautDeLigne();
}

void shuffleMot(const  string& mot,  string& shuffledMot)
{
    // Stock le mot à trouver dans la variable qui contiendra le mot randomisé
    shuffledMot = mot;

/* Randomise le mot, sans le seed on obtient tjrs le même mot .. */
  // get a time-based seed
    unsigned seed =  chrono::system_clock::now()
                        .time_since_epoch()
                        .count();

    shuffle (shuffledMot.begin(), shuffledMot.end(),  default_random_engine(seed));

    cout << "Shuffled word : " << shuffledMot;
    SautDeLigne();
}

void gestionScore(std::vector<int> &score, int& nbTentative)
{
    float score_moyen = 0.0;

    score.push_back(nbTentative);

    for (size_t i = 0; i < score.size() ; i++)
    {
        score_moyen = score_moyen + score[i];
    }
    score_moyen /= (float) score.size();
    cout << ">>>>  Score moyen == nombre de tentatives moyen : " << score_moyen << "  <<<<";
    SautDeLigne();
}

void userTry(const string& mot_mystere,  string& shuffledMot, vector<int>& score)
{
    int nbTentative = 1;
    int nbEssaiRestant = 5;
    bool motTrouve = false;
    string tentative;

    cout << "Le mot à remettre en ordre est : " << shuffledMot <<  endl;
    cout << nbEssaiRestant << " essai restant : ";
    cin>>tentative;

    if(tentative == mot_mystere)
    {
        motTrouve = true;
    }

    nbEssaiRestant--;
    SautDeLigne();


    while(tentative != mot_mystere && nbEssaiRestant > 0)
    {
        nbTentative++;

        cout << "Erreur, le mot à remettre en ordre est : " << shuffledMot <<  endl;
        cout << nbEssaiRestant << " essai restant : ";
        cin>>tentative;
        SautDeLigne();
        if(tentative == mot_mystere)
        {
            motTrouve = true;
        }
        nbEssaiRestant--;
    }

    if (motTrouve) 
    {
        cout << "Félicitations ! Vous avez utilisé " << nbTentative << " essai" << endl;
    }
    else
    {
        cout << "Vous n'avez plus de tentatives. Le mot " <<  shuffledMot << " correspond à " << mot_mystere << endl;   
    }

    gestionScore(score, nbTentative);


}