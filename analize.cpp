#include "antrastes.h"

bool compare_by_baigiamasis(const studentas &a, const studentas &b)
{
    return a.baigiamasis < b.baigiamasis;
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

        start = high_resolution_clock::now();
        for (int i = 0; i < grupe.size(); i++)
        {
            grupe[i].baigiamasis = galutinis(grupe[i]);
        }
        std::sort(grupe.begin(), grupe.end(), compare_by_baigiamasis);

        int mid_index = grupe.size() / 2;
        double mid_element = grupe[mid_index].baigiamasis;
        int down_index = mid_index + 1;
        int up_index = mid_index - 1;
        double closest_element = mid_element;
        int split_index = 0;

        while (true)
        {
            if (down_index < grupe.size() && fabs(grupe[down_index].baigiamasis - 5) <= fabs(closest_element - 5) && (fabs(grupe[down_index].baigiamasis - 5) > 0.005))
            {
                closest_element = grupe[down_index].baigiamasis;
                down_index++;
                split_index = down_index - 1;
            }
            else if (up_index > 0 && fabs(grupe[up_index].baigiamasis - 5) <= fabs(closest_element - 5))
            {
                closest_element = grupe[up_index].baigiamasis;
                up_index--;
                split_index = up_index;
            }
            else
            {
                break;
            }
        }
        vector<studentas> levekai(grupe.begin(), grupe.begin() + split_index + 1);
        vector<studentas> ketekai(grupe.begin() + split_index + 1, grupe.end());

        grupe.clear();

        end = high_resolution_clock::now();
        diff = end - start;
        cout << "Vektoriaus padalijimas i dvi dalis uztruko:  " << diff.count() << " s\n";
        total_diff += diff;
        start = high_resolution_clock::now();

        string file_name = "levekai" + std::to_string(i) + ".txt";
        std::ofstream file(file_name);

        for (int i = 0; i < levekai.size(); i++)
        {
            file << setw(15) << levekai[i].vardas << setw(15) << levekai[i].pavarde;
            for (int j = 0; j < levekai[i].paz.size(); j++)
            {
                file << setw(5) << levekai[i].paz[j] << " ";
            }
            file << setw(7) << levekai[i].egz;
            file << setw(10) << setprecision(2) << fixed << levekai[i].baigiamasis << endl;
        }

        file.close();

        end = high_resolution_clock::now();
        diff = end - start;
        cout << "Failo " << file_name << " isvedimas uztruko: " << diff.count() << " s\n";
        file_name = "ketekai" + std::to_string(i) + ".txt";
        std::ofstream anotherfile(file_name);
        total_diff += diff;
        start = high_resolution_clock::now();
        for (int k = 0; k < ketekai.size(); k++)
        {
            anotherfile << setw(15) << ketekai[k].vardas << setw(15) << ketekai[k].pavarde;
            for (int l = 0; l < ketekai[k].paz.size(); l++)
            {
                anotherfile << setw(5) << ketekai[k].paz[l] << " ";
            }
            anotherfile << setw(7) << ketekai[k].egz;
            anotherfile << setw(10) << setprecision(2) << fixed << ketekai[k].baigiamasis << endl;
        }

        anotherfile.close();

        end = high_resolution_clock::now();
        diff = end - start;
        cout << "Failo " << file_name << " isvedimas uztruko: " << diff.count() << " s\n";
        total_diff += diff;
        cout << "Bendrai darbas su failu '" << failas << "' uztruko: " << total_diff.count() << " s\n";
    }
}
