#include "antrastes.h"

int main(int argc, char *argv[])
{
    char tipas;
    cout << "Bus naudojamas duomenu failas (f), komandine eilute (k), ar atliekama analize(a)?" << endl;
    while (true)
    {
        if (cin >> tipas && (tipas == 'f' || tipas == 'k' || tipas == 'a'))
        {
            break;
        }
        else
        {
            cout << "Netinkamas namu darbu skaicius. Bandykite dar karta." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    vector<studentas> grupe;
    int paz_size;
    if (tipas == 'k')
    {
        while (true)
        {
            cout << "Kiek isviso buvo namu darbu? ";
            if (cin >> paz_size && paz_size > 0)
            {
                break;
            }
            else
            {
                cout << "Netinkamas namu darbu skaicius. Bandykite dar karta." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        char atsakymas;
        cout << "Naudosime vidurki (v) ar mediana (m) ? Irasykite pasirinkta raide: ";
        while (true)
        {
            if (cin >> atsakymas && (atsakymas == 'v' || atsakymas == 'm'))
            {
                break;
            }
            else
            {
                cout << "Ivesta netinkama raide. Iveskite dar karta" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        while (true)
        {
            studentas temp;
            pild(temp, paz_size);
            if (temp.getVardas() == "baigti" && temp.getPavarde() == "darba")
            {
                break;
            }
            grupe.push_back(temp);
        }
        cout << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis(vid)" << setw(20) << "Galutinis(med)" << endl;
        for (int i = 0; i < grupe.size(); i++)
        {
            spausd(grupe[i], atsakymas);
            cout << endl;
        }
    }
    else if (tipas == 'f')
    {
        Is_Failo(grupe, "");
    }
    else if (tipas == 'a')
    {
        int kiek;
        cout << "Kiek failu bus testuojama?" << endl;
        while (true)
        {
            if (!(cin >> kiek) || floor(kiek) != kiek)
            {
                cout << "Netinkamas skaicius." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                analize(grupe, kiek);
                break;
            }
        }
    }
    return 0;
}
