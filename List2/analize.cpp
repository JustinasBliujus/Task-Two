#include "antrastes.h"

bool compare_by_baigiamasis(const studentas &a, const studentas &b)
{
    return a.baigiamasis < b.baigiamasis;
}
void analize(list<studentas> &grupe, int kiek)
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

        start = high_resolution_clock::now();
        for (auto it = grupe.begin(); it != grupe.end(); ++it)
        {
            it->baigiamasis = galutinis(*it);
        }
        grupe.sort(compare_by_baigiamasis);

        list<studentas> levekai;
        grupe.remove_if([&](const studentas &student)
                        {
        if (student.baigiamasis < 5) {
            levekai.push_back(student);
            return true;
        }
        return false; });

        end = high_resolution_clock::now();
        diff = end - start;
        cout << "Vektoriaus padalijimas i dvi dalis uztruko:  " << diff.count() << " s\n";
        total_diff += diff;
        start = high_resolution_clock::now();

        string file_name = "levekai" + std::to_string(i) + ".txt";
        std::ofstream file(file_name);

        for (const studentas &struktura : levekai)
        {
            file << setw(15) << struktura.vardas << setw(15) << struktura.pavarde;
            for (int pazymys : struktura.paz)
            {
                file << setw(5) << pazymys << " ";
            }
            file << setw(7) << struktura.egz;
            file << setw(10) << setprecision(2) << fixed << struktura.baigiamasis << endl;
        }

        file.close();

        end = high_resolution_clock::now();
        diff = end - start;
        cout << "Failo " << file_name << " isvedimas uztruko: " << diff.count() << " s\n";
        file_name = "ketekai" + std::to_string(i) + ".txt";
        std::ofstream anotherfile(file_name);
        total_diff += diff;
        start = high_resolution_clock::now();

        for (const studentas &struktura : grupe)
        {
            anotherfile << setw(15) << struktura.vardas << setw(15) << struktura.pavarde;
            for (int pazymys : struktura.paz)
            {
                file << setw(5) << pazymys << " ";
            }
            anotherfile << setw(7) << struktura.egz;
            anotherfile << setw(10) << setprecision(2) << fixed << struktura.baigiamasis << endl;
        }

        anotherfile.close();

        end = high_resolution_clock::now();
        diff = end - start;
        cout << "Failo " << file_name << " isvedimas uztruko: " << diff.count() << " s\n";
        total_diff += diff;
        cout << "Bendrai darbas su failu '" << failas << "' uztruko: " << total_diff.count() << " s\n";

        for (auto it = grupe.begin(); it != grupe.end(); ++it)
        {
            it->paz.clear();
        }
        for (auto it = grupe.begin(); it != grupe.end(); ++it)
        {
            it->paz.clear();
        }
        grupe.clear();
        levekai.clear();
    }
}
