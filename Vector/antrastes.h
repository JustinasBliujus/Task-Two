#ifndef ANTRASTES_H
#define ANTRASTES_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include <sstream>
#include <random>
#include <stdexcept>
#include <chrono>
using std::begin;
using std::cin;
using std::copy;
using std::cout;
using std::end;
using std::endl;
using std::fixed;
using std::ifstream;
using std::istringstream;
using std::left;
using std::numeric_limits;
using std::right;
using std::setprecision;
using std::setw;
using std::sort;
using std::streamsize;
using std::string;
using std::stringstream;
using std::swap;
using std::vector;
using namespace std::chrono;
struct studentas
{
    string vardas = "", pavarde = "";
    vector<int> paz;
    int egz = 0;
    double baigiamasis = 0;
};

void pild(studentas &temp, int paz_size);
void spausd(studentas &temp, char atsakymas);
double galutinis(studentas &temp);
void galutinisMediana(studentas &temp);
void randomVal(studentas &temp, int paz_size);
void Is_Failo(vector<studentas> &grupe, string read_vardas);
bool compareStudentas(const studentas &a, const studentas &b);
void analize(vector<studentas> &grupe, int kiek);
bool compare_by_baigiamasis(const studentas &a, const studentas &b);
string generator();
#endif