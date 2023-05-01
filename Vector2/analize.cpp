#include "antrastes.h"
bool compareByGalVid(const studentas &s1, const studentas &s2)
{
    return s1.getGalVid() < s2.getGalVid();
}
void analize(vector<studentas> &grupe, int kiek)
{
    for (int i = 0; i < kiek; i++)
    {
        char tipas;
        string failas;
        cout << "Failas bus generuojamas (g) ar naudojamas jau sukurtas (s)?" << endl;
        while (true)
        {
            if (!(cin >> tipas) || (tipas != 'g' && tipas != 's'))
            {
                cout << "Netinkamas pasirinkimo tipas." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                break;
            }
        }
        if (tipas == 'g')
        {
            failas = generator();
        }
        else if (tipas == 's')
        {
            ifstream input_file;
            cout << "Iveskite failo pavadinima: " << endl;
            do
            {
                try
                {
                    cin >> failas;
                    input_file.open(failas);
                    if (!input_file)
                    {
                        string error = "Tokio failo nera";
                        throw error;
                    }
                    else
                    {
                        input_file.close();
                        break;
                    }
                }
                catch (string error)
                {
                    cout << error << endl;
                }
            } while (true);
        }
        auto start = high_resolution_clock::now();
        duration<double> total_diff(0);
        Is_Failo(grupe, failas);

        auto end = high_resolution_clock::now();
        duration<double> diff = end - start;
        cout << "Failo " << failas << " nuskaitymas i vektoriu uztruko:  " << diff.count() << " s\n";
        total_diff += diff;
        vector<double> baigiamasis;
        baigiamasis.reserve(grupe.size());
        start = high_resolution_clock::now();
        for (int i = 0; i < grupe.size(); i++)
        {
            baigiamasis[i] = grupe[i].getGalVid();
        }
        sort(grupe.begin(), grupe.end(), compareByGalVid);
        vector<studentas> levekai;
        levekai.reserve(grupe.size());

        auto it = std::remove_if(grupe.begin(), grupe.end(),
                                 [&](const studentas &student)
                                 {
                                     if (student.getGalVid() < 5)
                                     {
                                         levekai.push_back(student);
                                         return true;
                                     }
                                     return false;
                                 });

        grupe.erase(it, grupe.end());

        end = high_resolution_clock::now();
        diff = end - start;
        cout << "Vektoriaus padalijimas i dvi dalis uztruko:  " << diff.count() << " s\n";
        total_diff += diff;
        start = high_resolution_clock::now();

        string file_name = "levekai" + std::to_string(i) + ".txt";
        std::ofstream file(file_name);

        for (int i = 0; i < levekai.size(); i++)
        {
            file << setw(15) << levekai[i].getVardas() << setw(15) << levekai[i].getPavarde();
            file << setw(10) << setprecision(2) << fixed << levekai[i].getGalVid() << endl;
        }

        file.close();

        end = high_resolution_clock::now();
        diff = end - start;
        cout << "Failo " << file_name << " isvedimas uztruko: " << diff.count() << " s\n";
        file_name = "ketekai" + std::to_string(i) + ".txt";
        std::ofstream anotherfile(file_name);
        total_diff += diff;
        start = high_resolution_clock::now();
        for (int k = 0; k < grupe.size(); k++)
        {
            anotherfile << setw(15) << grupe[k].getVardas() << setw(15) << grupe[k].getPavarde();
            anotherfile << setw(10) << setprecision(2) << fixed << grupe[k].getGalVid() << endl;
        }

        anotherfile.close();

        end = high_resolution_clock::now();
        diff = end - start;
        cout << "Failo " << file_name << " isvedimas uztruko: " << diff.count() << " s\n";
        total_diff += diff;
        cout << "Bendrai darbas su failu '" << failas << "' uztruko: " << total_diff.count() << " s\n";
        levekai.clear();
    }
}
