#include "antrastes.h"
void Is_Failo(vector<studentas> &grupe, string read_vardas)
{
    bool reikia_spausdinti = false;
    ifstream input_file;
    if (read_vardas.empty())
    {
        cout << "Iveskite failo pavadinima: " << endl;
        do
        {
            try
            {
                cin >> read_vardas;
                input_file.open(read_vardas);
                if (!input_file)
                {
                    string error = "Tokio failo nera";
                    throw error;
                }
                else
                {
                    reikia_spausdinti = true;
                    break;
                }
            }
            catch (string error)
            {
                cout << error << endl;
            }
        } while (true);
    }
    else
    {
        do
        {
            try
            {
                input_file.open(read_vardas);
                if (!input_file)
                {
                    string error = "Failas nebuvo atidarytas";
                    throw error;
                }
                else
                {
                    break;
                }
            }
            catch (string error)
            {
                cout << error << endl;
            }
        } while (true);
    }
    while (input_file >> grupe)
    {
    }

    input_file.close();
    sort(grupe.begin(), grupe.end(), [](const studentas &a, const studentas &b)
         { return a < b; });
    if (reikia_spausdinti)
    {
        cout << left << setw(15) << "Vardas" << setw(21) << "Pavarde" << setw(19) << "Galutinis(vid)" << setw(20) << "Galutinis(med)" << endl;
        for (int i = 0; i < grupe.size(); i++)
        {
            cout << grupe[i] << endl;
        }
    }
}

void pild(studentas &temp, int paz_size)
{
    string v, p;
    cout << "Iveskite varda ir pavarde. Noredami baigti darba, iveskite \"baigti darba\". ";
    cin >> v >> p;
    temp.setVardas(v);
    temp.setPavarde(p);
    if (v == "baigti" && p == "darba")
    {
        return;
    }
    double paz = -1;
    int pazymys;
    int egz;
    vector<int> pazymiai;
    cout << "Iveskite pazymius. Noredami sustabdyti pazymiu ivedima, iveskite \"-1\": ";
    cout << "Noredami generuoti atsitiktinius pazymius ir egzamina, iveskite \"-2\": ";
    bool validInput;
    while (true)
    {
        validInput = true;
        if (!(cin >> paz) || floor(paz) != paz)
        {
            cout << "Ivestas netinkamas pazymys. Iveskite dar karta" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
        }
        if (validInput)
        {
            pazymys = paz;
            if (pazymys == -1)
            {
                break;
            }
            if (pazymys == -2)
            {
                randomVal(pazymiai, paz_size, egz);
                break;
            }
            else if (0 < pazymys && pazymys <= 10)
            {
                pazymiai.push_back(pazymys);
                if (pazymiai.size() == paz_size)
                {
                    break;
                }
            }
        }
    }
    if (pazymiai.size() != paz_size - 1)
    {
        while (pazymiai.size() != paz_size)
        {
            pazymiai.push_back(0);
        }
    }
    if (pazymys != -2)
    {
        while (true)
        {
            cout << "Iveskite egzamino paz: ";
            if (cin >> egz && egz >= 0 && egz <= 10)
            {
                cout << "Duomenys irasyti. " << endl;
                break;
            }
            else
            {
                cout << "Netinkama ivestis. Bandykite dar karta." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    temp.setGalutinisVid(temp.galutinisVidurkis(pazymiai, egz));
    temp.setGalutinisMed(temp.galutinisMediana(pazymiai, egz));
}

void spausd(studentas &temp, char atsakymas)
{
    cout << setw(15) << temp.getVardas() << setw(15) << temp.getPavarde();
    if (atsakymas == 'v')
    {
        cout << setw(10) << setprecision(2) << fixed << temp.getGalVid();
    }
    else if (atsakymas == 'm')
    {
        cout << "\t\t";
        cout << setw(10) << setprecision(2) << setw(20) << setprecision(2) << fixed << temp.getGalMed();
    }
}

void randomVal(vector<int> &pazymiai, int paz_size, int &egz)
{
    std::random_device rd;
    std::mt19937_64 mt(static_cast<long unsigned int>(rd()));
    std::uniform_int_distribution<int> dist(0, 10);
    while (pazymiai.size() != paz_size - 1)
    {
        pazymiai.push_back(dist(mt));
    }
    egz = dist(mt);
    cout << "Duomenys irasyti." << endl;
}
