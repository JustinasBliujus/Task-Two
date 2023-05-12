#ifndef ANTRASTES_H
#define ANTRASTES_H
#include "vector.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
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
using namespace std::chrono;

/**
 * @class Zmogus
 * @brief Represents a person.
 * The Zmogus class serves as a base class for representing a person. It provides
 * basic functionality for storing and retrieving information about a person's first
 * name and last name. The class also allows derived classes to override the name
 * setting methods to provide additional functionality or validation.
 */
class Zmogus
{
protected:
    /**
     * The first name of the person.
     */
    string Vardas_;
    /**
     * The last name of the person.
     */
    string Pavarde_;

public:
    /**
     * @brief Default constructor for Zmogus.
     */
    Zmogus() : Vardas_(""), Pavarde_("") {}

    /**
     * @brief Constructor for Zmogus with specified first and last name.
     * @param vardas The first name of the person.
     * @param pavarde The last name of the person.
     */
    Zmogus(const string &vardas, const string &pavarde)
        : Vardas_(vardas), Pavarde_(pavarde) {}

    /**
     * @brief Get the first name of the person.
     * @return The first name of the person.
     */
    string getVardas() const { return Vardas_; }

    /**
     * @brief Get the last name of the person.
     * @return The last name of the person.
     */
    string getPavarde() const { return Pavarde_; }

    /**
     * @brief Set the first name of the person.
     * @param vardas The first name of the person.
     */
    virtual void setVardas(const string &vardas) { Vardas_ = vardas; }

    /**
     * @brief Set the last name of the person.
     * @param pavarde The last name of the person.
     */
    virtual void setPavarde(const string &pavarde) { Pavarde_ = pavarde; }

    /**
     * @brief Virtual destructor for Zmogus.
     */
    virtual ~Zmogus() {}
};
/**
 * @class studentas
 * @brief Represents a student, derived from the Zmogus class. Has additional data like final grades.
 *
 * The studentas class extends the Zmogus class and represents a student. It
 * adds additional attributes for storing the average grade (GalVid_) and the
 * median grade (GalMed_) of the student.
 */
class studentas : public Zmogus
{
private:
    /**
     * The average grade of the person.
     */
    double GalVid_;
    /**
     * The median grade of the person.
     */
    double GalMed_;

public:
    /**
     * @brief Default constructor for studentas.
     *
     * Constructs a studentas object with the average and median grades set to 0.
     */
    studentas() : GalVid_(0), GalMed_(0) {}
    /**
     * @brief Constructor for studentas with specified parameters.
     *
     * @param vardas The first name of the student.
     * @param pavarde The last name of the student.
     * @param paz The vector of grades.
     * @param egz The final exam grade.
     */
    studentas(string vardas, string pavarde, CustomVector<int> &paz, int egz)
        : Zmogus(vardas, pavarde)
    {
        GalVid_ = galutinisVidurkis(paz, egz);
        GalMed_ = galutinisMediana(paz, egz);
        paz.clear();
    }
    /**
     * @brief Copy constructor for studentas.
     *
     * Constructs a studentas object by copying the data from another studentas object.
     *
     * @param other The studentas object to be copied.
     */
    studentas(const studentas &other)
        : Zmogus(other), GalVid_(other.GalVid_), GalMed_(other.GalMed_) {}

    /**
     * @brief Copy assignment operator for studentas.
     *
     * Assigns the values of the attributes from another studentas object to this object.
     * @param other The studentas object to be copied.
     * @return A reference to this object after the assignment.
     */
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

    /**
     * @brief Move constructor for studentas.
     *
     * Constructs a studentas object by moving the data from another studentas object.
     *
     * @param other The studentas object to be moved.
     */
    studentas(studentas &&other) noexcept
        : Zmogus(std::move(other)), GalVid_(std::move(other.GalVid_)), GalMed_(std::move(other.GalMed_)) {}
    /**
     * @brief Move assignment operator for studentas.
     *
     * Assigns the values of the attributes from another studentas object to this object by moving them.
     * @param other The studentas object to be moved.
     * @return A reference to this object after the move assignment.
     */
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

    /**
     * @brief Destructor for studentas.
     * A virtual destructor to allow proper destruction of derived class objects
     */
    ~studentas() {}

    /**
     * @brief Get the first name of the student.
     * Retrieves the first name of the student.
     * @return The first name of the student.
     */
    string getVardas() const { return Vardas_; }

    /**
     * @brief Get the last name of the student.
     * Retrieves the last name of the student.
     * @return The last name of the student.
     */
    string getPavarde() const { return Pavarde_; }

    /**
     * @brief Get the average grade of the student.
     * Retrieves the average grade of the student.
     * @return The average grade of the student.
     */
    double getGalVid() const { return GalVid_; }

    /**
     * @brief Get the median grade of the student.
     * Retrieves the median grade of the student.
     * @return The median grade of the student.
     */
    double getGalMed() const { return GalMed_; }

    /**
     * @brief Set the first name of the student.
     * Sets the first name of the student to the specified value.
     * @param vardas The first name of the student.
     */
    void setVardas(const string &vardas) { Vardas_ = vardas; }

    /**
     * @brief Set the last name of the student.
     * Sets the last name of the student to the specified value.
     * @param pavarde The last name of the student.
     */
    void setPavarde(const string &pavarde) { Pavarde_ = pavarde; }

    /**
     * @brief Set the average grade of the student.
     * Sets the average grade of the student to the specified value.
     * @param galutinisVid The average grade of the student.
     */
    void setGalutinisVid(const double &galutinisVid) { GalVid_ = galutinisVid; }

    /**
     * @brief Set the median grade of the student.
     * Sets the median grade of the student to the specified value.
     * @param galutinisMed The median grade of the student.
     */
    void setGalutinisMed(const double &galutinisMed) { GalMed_ = galutinisMed; }

    /**
     * @brief Calculate the average final grade.
     *
     * Calculates the average final grade using the provided vector of grades (paz) and the final exam grade (egz).
     * @param paz The vector of grades.
     * @param egz The final exam grade.
     * @return The average final grade.
     */
    double galutinisVidurkis(CustomVector<int> &paz, int &egz)
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
    /**
     * @brief Calculate the median final grade.
     *
     * Calculates the median final grade using the provided vector of grades (paz) and the final exam grade (egz).
     * @param paz The vector of grades.
     * @param egz The final exam grade.
     * @return The median final grade.
     */
    double galutinisMediana(CustomVector<int> &paz, int &egz)
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
    /**
     * @brief Overloaded input stream operator for studentas vector.
     *
     * Reads student data from the input stream and constructs studentas objects based on the data.
     * The input format is assumed to be: "first_name last_name grade1 grade2 ... gradeN final_exam_grade".
     * @param input The input stream.
     * @param stud The vector of studentas objects.
     * @return The input stream after the operation.
     */
    friend std::istream &operator>>(std::istream &input, CustomVector<studentas> &stud)
    {

        string vardas, pavarde, line;
        CustomVector<int> paz;
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
    /**
     * @brief Overloaded output stream operator for studentas.
     *
     * Writes the data of a studentas object to the output stream in a formatted manner.
     * The output format is assumed to be: "first_name last_name average_grade median_grade".
     * @param output The output stream.
     * @param stud The studentas object to be written.
     * @return The output stream after the operation.
     */
    friend std::ostream &operator<<(std::ostream &output, const studentas &stud)
    {
        output << left << setw(15) << stud.getVardas() << setw(21) << stud.getPavarde()
               << setw(19) << fixed << setprecision(2) << stud.GalVid_
               << setw(20) << fixed << setprecision(2) << stud.GalMed_ << "\n";
        return output;
    }
    /**
     * @brief Less than operator for studentas.
     *
     * Compares two studentas objects based on their names (Vardas_ and Pavarde_).
     * If the first names are different, the comparison is based on the first name.
     * If the first names are the same, the comparison is based on the last name.
     *
     * @param other The studentas object to compare with.
     * @return True if this studentas object is less than the other, false otherwise.
     */
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
void randomVal(CustomVector<int> &pazymiai, int paz_size, int &egz);
void Is_Failo(CustomVector<studentas> &grupe, string read_vardas);
void analize(CustomVector<studentas> &grupe, int kiek);
string generator();
#endif
