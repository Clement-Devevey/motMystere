#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <string>
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <vector>
#include <fstream>
#include <random>
#include <limits>

std::size_t count_line(std::string const & filename);
std::ifstream& GotoLine(std::ifstream& file, const int& num);
void SautDeLigne();
void askMotMystere(std::string& mot);
void shuffleMot(const std::string& mot, std::string& shuffledMot);
void gestionScore(std::vector<int> &score, int& nbTentative);
void userTry(const std::string& mot_mystere,  std::string& shuffledMot, std::vector<int> &score);


#endif // CALC_MOY_H_INCLUDED
