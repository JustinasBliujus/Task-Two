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

class Zmogus
{
protected:
    string Vardas_;
    string Pavarde_;

    Zmogus() : Vardas_(""), Pavarde_("") {}
    // constructor
    Zmogus(const string &vardas, const string &pavarde)
        : Vardas_(vardas), Pavarde_(pavarde) {}

public:
    // getters
    string getVardas() const { return Vardas_; }
    string getPavarde() const { return Pavarde_; }

    // setters
    virtual void setVardas(const string &vardas) { Vardas_ = vardas; }
    virtual void setPavarde(const string &pavarde) { Pavarde_ = pavarde; }

    // destructor
    virtual ~Zmogus() {}
};
class studentas : public Zmogus
{
private:
    double GalVid_;
    double GalMed_;

public:
    // constructor
    studentas() : GalVid_(0), GalMed_(0) {}
    studentas(string vardas, string pavarde, vector<int> &paz, int egz)
        : Zmogus(vardas, pavarde)
    {
        GalVid_ = galutinisVidurkis(paz, egz);
        GalMed_ = galutinisMediana(paz, egz);
        paz.clear();
    }
    // copy constructor
    studentas(const studentas &other)
        : Zmogus(other), GalVid_(other.GalVid_), GalMed_(other.GalMed_) {}

    // copy assignment operator
    studentas &operator=(const studentas &other)
    {
        if (this != &other)
        {
            Zmogus::operator=(other); // Invoke base class copy assignment operator
            GalVid_ = other.GalVid_;
            GalMed_ = other.GalMed_;
        }
        return *this;
    }

    // move constructor
    studentas(studentas &&other) noexcept
        : Zmogus(std::move(other)), GalVid_(std::move(other.GalVid_)), GalMed_(std::move(other.GalMed_)) {}

    studentas &operator=(studentas &&other) noexcept
    {
        if (this != &other)
        {
            Zmogus::operator=(std::move(other)); // Invoke base class move assignment operator
            GalVid_ = std::move(other.GalVid_);
            GalMed_ = std::move(other.GalMed_);
        }
        return *this;
    }

    // destructor
    ~studentas() {}

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
        output << left << setw(15) << stud.getVardas() << setw(21) << stud.getPavarde()
               << setw(19) << fixed << setprecision(2) << stud.GalVid_
               << setw(20) << fixed << setprecision(2) << stud.GalMed_ << "\n";
        return output;
    }
    bool operator<(const studentas &other) const
    {
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
string generator();
#endif
