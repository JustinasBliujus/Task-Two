#include "Mylib.h"

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
int main()                                                                                                                              
{
    vector<studentas> grupe;
    int paz_size;

    while (true) { 
    cout << "Kiek isviso buvo namu darbu? ";
    if (cin >> paz_size && paz_size > 0) {
        break;
    } else {
        cout << "Netinkamas namu darbu skaicius. Bandykite dar karta." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    }
    char atsakymas;
    cout << "Naudosime vidurki (v) ar mediana (m) ? Irasykite pasirinkta raide: ";

    while (true) {
        if (cin >> atsakymas && (atsakymas == 'v' || atsakymas == 'm')) {
            break;
        }
        else{
            cout << "Ivesta netinkama raide. Iveskite dar karta" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        studentas temp;
        pild(temp, paz_size);
        if (temp.vardas == "baigti" && temp.pavarde == "darba") {
            break;
        }
        grupe.push_back(temp);
    }
    cout << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis(vid)" << setw(20) << "Galutinis(med)" << endl;
    for (int i = 0; i < grupe.size(); i++)
    {
        spausd(grupe[i], atsakymas);
    }

    for(auto &i:grupe) i.paz.clear();
    grupe.clear();
    return 0;
}

void pild(studentas &temp, int paz_size)
{
    cout << "Iveskite varda ir pavarde. Noredami baigti darba, iveskite \"baigti darba\". ";
    cin >> temp.vardas >> temp.pavarde;
    if(temp.vardas == "baigti" && temp.pavarde == "darba"){
        return;
    }
    int pazymys = -1;
    cout << "Iveskite pazymius. Noredami sustabdyti pazymiu ivedima, iveskite \"-1\": ";
    cout << "Noredami generuoti atsitiktinius pazymius ir egzamina, iveskite \"-2\": ";
    while (true)
    {
        cin >> pazymys;
        if (pazymys == -1)
        {
            break;
        }
        if (pazymys == -2)
        {
            randomVal(temp,paz_size);
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
        else{
            cout << "Ivestas netinkamas pazymys. Iveskite dar karta" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    if (temp.paz.size() != paz_size-1)
    {
        while(temp.paz.size() != paz_size){
            temp.paz.push_back(0);
        }
    }

    while (true) { 
    cout << "Iveskite egzamino paz: ";
    if (cin >> temp.egz && temp.egz >= 0 && temp.egz <= 10) {
        cout << "Duomenys irasyti. " << endl;
        break;
    } else {
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
        galutinis(temp);
    }
    else if (atsakymas == 'm')
    {
        galutinisMediana(temp);
    }
}

void galutinis(studentas &temp)
{
    double suma = 0;
    int paz_sk = temp.paz.size();
    for (int i = 0; i < paz_sk; i++)
    {
        suma += temp.paz[i]; 
    }
    double vid;
    vid = suma / (paz_sk+1);
    cout << setw(10) << setprecision(2) << fixed << vid * 0.4 + 0.6 * temp.egz << endl;
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
    cout << setw(30) << setprecision(2) << fixed << mediana * 0.4 + 0.6 * temp.egz << endl;
}

void randomVal(studentas &temp,int paz_size){
    srand(time(0));
    while(temp.paz.size() != paz_size-1){
            temp.paz.push_back(rand() % 11);  
        }
        temp.egz = rand() % 11;
        cout <<"Duomenys irasyti."<<endl;
}