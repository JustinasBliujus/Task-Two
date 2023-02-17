#include "Mylib.h"

struct studentas
{
    string vardas = "", pavarde = "";
    int * paz;
    int egz = 0;
};
void pild(studentas &temp,int paz_size);
void spausd(studentas &temp, char atsakymas,int paz_size);
void galutinis(studentas &temp, int paz_size);
void galutinisMediana(studentas &temp, int paz_sk);
void randomVal(studentas &temp,int paz_size,int j);
int main()                                                                                                                              
{
    studentas *grupe = nullptr;
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
    cout << "Kiek yra studentu? ";
    int studentusk;
    while (true) {
        if (cin >> studentusk && studentusk > 0) {
            break;
        }
        else{
            cout << "Ivestas netinkamas skaicius. Iveskite dar karta" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    grupe = new studentas[studentusk];
    int k = 0;
    while (true) {
        pild(grupe[k], paz_size);
        if (grupe[k].vardas == "baigti" && grupe[k].pavarde == "darba") {
            break;
        }
        else{
           k++; 
        }
        if(k == studentusk){
            break;
        }
    }
    cout << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis(vid)" << setw(20) << "Galutinis(med)" << endl;
    for (int i = 0; i < k; i++)
    {
        spausd(grupe[i], atsakymas,paz_size);
        delete [] grupe[i].paz;
    }
    delete [] grupe;
    return 0;
}
void pild(studentas &temp, int paz_size)
{
    cout << "Iveskite varda ir pavarde. Noredami baigti darba, iveskite \"baigti darba\". ";
    cin >> temp.vardas >> temp.pavarde;
    if(temp.vardas == "baigti" && temp.pavarde == "darba"){
        return;
    }
    temp.paz = new int[paz_size];
    int pazymys = -1;
    int j = -1;
    cout << "Iveskite pazymius. Noredami sustabdyti pazymiu ivedima, iveskite \"-1\": ";
    cout << "Noredami generuoti atsitiktinius pazymius ir egzamina, iveskite \"-2\": ";
    while (true)
    {
        cin >> pazymys;
        if (pazymys == -1){
            break;
        }
        if (pazymys == -2){
            randomVal(temp,paz_size,j);
            return;
        }
        else if (0 < pazymys && pazymys <= 10){
            j++;
            temp.paz[j]=pazymys;
            if (j == paz_size-1)
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
    if (j+1 != paz_size){
        while(j+1 != paz_size){
            j++;
            temp.paz[j]=0;
        }
    }
    while (true){ 
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
void spausd(studentas &temp, char atsakymas, int paz_size)
{
    cout << setw(15) << temp.vardas << setw(15) << temp.pavarde;
    if (atsakymas == 'v')
    {
        galutinis(temp,paz_size);
    }
    else if (atsakymas == 'm')
    {
        galutinisMediana(temp,paz_size);
    }
}
void galutinis(studentas &temp,int paz_size)
{
    double suma = 0;
    for (int i = 0; i < paz_size; i++){
        suma += temp.paz[i];
    }
    double vid;
    vid = suma / (paz_size+1);
    cout << setw(10) << setprecision(2) << fixed << vid * 0.4 + 0.6 * temp.egz << endl;
}
void galutinisMediana(studentas &temp, int paz_size)
{
    double suma = 0;
    double mediana;
    for(int i = 0; i < paz_size - 1; i++){
         for (int j = 0; j < paz_size - i - 1; j++){
            if (temp.paz[j]> temp.paz[j+1])
                swap(temp.paz[j],temp.paz[j+1]);
         }
    }
    if (paz_size % 2 != 0){
        mediana = temp.paz[paz_size / 2];
    }
    else if (paz_size % 2 == 0){
        mediana = ((temp.paz[paz_size / 2 - 1] + temp.paz[paz_size / 2]) * 1.0) / 2;
    }
    cout << setw(30) << setprecision(2) << fixed << mediana * 0.4 + 0.6 * temp.egz << endl;
}
void randomVal(studentas &temp,int paz_size,int j){
    srand(time(0));
    int a = j;
    while(a+1 != paz_size){
            a++; 
            temp.paz[a] = rand() % 11;
        }
        temp.egz = rand() % 11;
        cout <<"Duomenys irasyti."<<endl;
}