#include "antrastes.h"
void Is_Failo(deque<studentas> &grupe, string read_vardas)
{
    ifstream input_file;
    int spausdinimo_tipas;
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
                    spausdinimo_tipas = 1;
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
                    spausdinimo_tipas = 2;
                    break;
                }
            }
            catch (string error)
            {
                cout << error << endl;
            }
        } while (true);
    }

    string line;
    int paz_sk = 0;
    int line_position = 0;

    while (std::getline(input_file, line))
    {
        studentas temp;
        istringstream each(line);
        string word;
        int word_position = 0;
        bool error = false;
        while (each >> word)
        {
            if (line_position == 0)
            {
                paz_sk++;
                if (each.peek() == EOF)
                {
                    line_position++;
                    paz_sk -= 3;
                }
            }
            else
            {
                if (word_position == 0)
                {
                    temp.vardas = word;
                }
                else if (word_position == 1)
                {
                    temp.pavarde = word;
                }
                else if (each.peek() == EOF)
                {
                    try
                    {
                        temp.egz = std::stoi(word);
                    }
                    catch (std::invalid_argument const &e)
                    {
                        error = true;
                        cout << line_position - 1 << " studento egzamino ivestis netinkama."
                             << "(" << e.what() << ")" << endl;
                        continue;
                    }
                }
                else
                {
                    if (!error)
                    {
                        try
                        {
                            temp.paz.push_back(std::stoi(word));
                        }
                        catch (std::invalid_argument const &e)
                        {
                            error = true;
                            cout << line_position - 1 << " studento pazymiu ivestis netinkama."
                                 << "(" << e.what() << ")" << endl;
                            continue;
                        }
                    }
                }
                word_position++;
            }
        }
        if (line_position != 1 && !error)
        {
            grupe.push_back(temp);
        }
        line_position++;
    }
    input_file.close();

    if (spausdinimo_tipas == 1)
    {
        std::sort(grupe.begin(), grupe.end(), compareStudentas);
        cout << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis(vid)" << setw(20) << "Galutinis(med)" << endl;
        for (int i = 0; i < grupe.size(); i++)
        {
            cout << setw(15) << grupe[i].vardas << setw(15) << grupe[i].pavarde;
            cout << setw(10) << setprecision(2) << fixed << galutinis(grupe[i]);
            galutinisMediana(grupe[i]);
        }
    }
}
bool compareStudentas(const studentas &a, const studentas &b)
{
    if (a.vardas != b.vardas)
    {
        return a.vardas < b.vardas;
    }
    else
    {
        return a.pavarde < b.pavarde;
    }
}

void pild(studentas &temp, int paz_size)
{
    cout << "Iveskite varda ir pavarde. Noredami baigti darba, iveskite \"baigti darba\". ";
    cin >> temp.vardas >> temp.pavarde;
    if (temp.vardas == "baigti" && temp.pavarde == "darba")
    {
        return;
    }
    double paz = -1;
    int pazymys;
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
                randomVal(temp, paz_size);
                return;
            }
            else if (0 < pazymys && pazymys <= 10)
            {
                temp.paz.push_back(pazymys);
                if (temp.paz.size() == paz_size)
                {
                    break;
                }
            }
        }
    }
    if (temp.paz.size() != paz_size - 1)
    {
        while (temp.paz.size() != paz_size)
        {
            temp.paz.push_back(0);
        }
    }

    while (true)
    {
        cout << "Iveskite egzamino paz: ";
        if (cin >> temp.egz && temp.egz >= 0 && temp.egz <= 10)
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

void spausd(studentas &temp, char atsakymas)
{
    cout << setw(15) << temp.vardas << setw(15) << temp.pavarde;
    if (atsakymas == 'v')
    {
        cout << setw(10) << setprecision(2) << fixed << galutinis(temp);
    }
    else if (atsakymas == 'm')
    {
        cout << "\t\t";
        galutinisMediana(temp);
    }
}

double galutinis(studentas &temp)
{
    double suma = 0;
    int paz_sk = temp.paz.size();
    for (int i = 0; i < paz_sk; i++)
    {
        suma += temp.paz[i];
    }
    double vid;
    vid = suma / paz_sk;
    //  cout << setw(10) << setprecision(2) << fixed << vid * 0.4 + 0.6 * temp.egz;
    return vid * 0.4 + 0.6 * temp.egz;
}

void galutinisMediana(studentas &temp)
{
    double suma = 0;
    int paz_sk = temp.paz.size();
    double mediana;
    sort(temp.paz.begin(), temp.paz.end());
    if (paz_sk % 2 != 0)
    {
        mediana = temp.paz[paz_sk / 2];
    }
    else if (paz_sk % 2 == 0)
    {
        mediana = ((temp.paz[paz_sk / 2 - 1] + temp.paz[paz_sk / 2]) * 1.0) / 2;
    }
    cout << setw(20) << setprecision(2) << fixed << mediana * 0.4 + 0.6 * temp.egz << endl;
}

void randomVal(studentas &temp, int paz_size)
{
    std::random_device rd;
    std::mt19937_64 mt(static_cast<long unsigned int>(rd()));
    std::uniform_int_distribution<int> dist(0, 10);
    while (temp.paz.size() != paz_size - 1)
    {
        temp.paz.push_back(dist(mt));
    }
    temp.egz = dist(mt);
    cout << "Duomenys irasyti." << endl;
}