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
using std::cout;
using std::cin;
using std::right;
using std::left;
using std::setprecision;
using std::string;
using std::setw;
using std::endl;
using std::copy;
using std::fixed;
using std::swap;
using std::vector;
using std::sort;
using std::begin;
using std::end;
using std::numeric_limits;
using std::streamsize;
using std::ifstream;
using std::stringstream;
using std::istringstream;

struct studentas
{
    string vardas = "", pavarde = "";
    vector<int> paz;
    int egz = 0;
};

void pild(studentas &temp,int paz_size);
void spausd(studentas &temp, char atsakymas);
void galutinis(studentas &temp);
void galutinisMediana(studentas &temp);
void randomVal(studentas &temp,int paz_size);
void Is_Failo(vector<studentas> &grupe);
bool compareStudentas(const studentas& a, const studentas& b);
#endif