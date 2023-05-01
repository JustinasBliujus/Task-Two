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
using std::partition_copy;
using std::remove_if;
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
class studentas
{
private:
    string Vardas_;
    string Pavarde_;
    double GalVid_;
    double GalMed_;

public:
    // constructor
    studentas() : Vardas_(""), Pavarde_(""), GalVid_(0), GalMed_(0) {}
    studentas(string vardas, string pavarde, vector<int> &paz, int egz)
    {
        Vardas_ = vardas;
        Pavarde_ = pavarde;
        GalVid_ = galutinisVidurkis(paz, egz);
        GalMed_ = galutinisMediana(paz, egz);
        paz.clear();
    }

    // getters
    string getVardas() const { return Vardas_; }
    string getPavarde() const { return Pavarde_; }
    double getGalVid() const { return GalVid_; }
    double getGalMed() const { return GalMed_; }

    // setters
    void setVardas(const string &vardas) { Vardas_ = vardas; }
    void setPavarde(const string &pavarde) { Pavarde_ = pavarde; }
    void setGalutinisVid(const double &galutinisVid) { GalVid_ = galutinisVid; }
    void setGalutinisMed(const double &galutinisMed) { GalMed_ = galutinisMed; }

    // member functions
    double galutinisVidurkis(vector<int> &paz, int &egz)
    {
        double suma = 0;
        int paz_sk = paz.size();
        for (int i = 0; i < paz_sk; i++)
        {
            suma += paz[i];
        }
        double vid;
        vid = suma / paz_sk;
        return vid * 0.4 + 0.6 * egz;
    }

    double galutinisMediana(vector<int> &paz, int &egz)
    {
        int paz_sk = paz.size();
        double galutinisMed = 0.0;

        sort(paz.begin(), paz.end());

        if (paz_sk % 2 == 0)
            galutinisMed = (0.4 * (double)((paz[paz_sk / 2 - 1] + paz[paz_sk / 2]) / 2) + 0.6 * egz);
        else
            galutinisMed = (0.4 * paz[paz_sk / 2]) + (0.6 * egz);

        return galutinisMed;
    }

    friend std::istream &operator>>(std::istream &input, vector<studentas> &stud)
    {

        string vardas, pavarde, line;
        vector<int> paz;
        int pazymys;

        getline(input, line);
        if (input.fail())
        {
            return input;
        }
        stringstream fin(line);

        fin >> vardas >> pavarde;

        while (fin >> pazymys)
        {
            paz.push_back(pazymys);
        }

        int egz = paz.back();
        paz.pop_back();
        stud.push_back(studentas(vardas, pavarde, paz, egz));
        return input;
    }

    friend std::ostream &operator<<(std::ostream &output, const studentas &stud)
    {
        output << left << setw(15) << stud.Vardas_ << setw(21) << stud.Pavarde_
               << setw(19) << fixed << setprecision(2) << stud.GalVid_
               << setw(20) << fixed << setprecision(2) << stud.GalMed_ << "\n";
        return output;
    }
    bool operator<(const studentas &other) const
    {
        // Compare the names lexicographically
        if (Vardas_ != other.Vardas_)
        {
            return Vardas_ < other.Vardas_;
        }
        else
        {
            return Pavarde_ < other.Pavarde_;
        }
    }
};

void pild(studentas &temp, int paz_size);
void spausd(studentas &temp, char atsakymas);
void randomVal(vector<int> &pazymiai, int paz_size, int &egz);
void Is_Failo(vector<studentas> &grupe, string read_vardas);
bool compareStudentas(const studentas &a, const studentas &b);
void analize(vector<studentas> &grupe, int kiek);
bool compare_by_baigiamasis(const studentas &a, const studentas &b);
string generator();
#endif
