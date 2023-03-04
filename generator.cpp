#include "antrastes.h"
string generator(){
  int sk_studentu,pz_sk;
  cout << "Kiek studentu generuojama? ";
  while(true){
        if(!(cin >> sk_studentu) || floor(sk_studentu) != sk_studentu){
            cout << "Netinkamas skaicius." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
         }
    }
  
  cout << "Kiek pazymiu tures studentai? ";
  while(true){
        if(!(cin >> pz_sk) || floor(pz_sk) != pz_sk){
            cout << "Netinkamas skaicius." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
         }
    }

  std::random_device rd;
  std::mt19937_64 mt(static_cast<long unsigned int> (rd()));
  std::uniform_int_distribution<int> dist(0,10);
  string file_name = "studentai" + std::to_string(sk_studentu) + ".txt";
  std::ofstream file(file_name);
  
  if (!file.is_open()) {
    std::cerr << "Failed to create file!" << endl;
  }
  file <<setw(15)<<"Vardas"<<setw(15)<<"Pavarde";
  for(int i = 0; i < pz_sk; i++){
    file<<setw(5)<<"nd"+ std::to_string(i+1)<<" ";
  }
  file<<setw(10)<<"egzaminas"<<endl;

  for (int i = 1; i <= sk_studentu; i++) {
    string first_name = "Vardas" + std::to_string(i);
    string last_name = "Pavarde" + std::to_string(i);
    
    file <<setw(15)<< first_name << setw(15) << last_name;
    for (int j = 0; j < pz_sk; j++) {
      file <<setw(5)<< (dist(mt))<<" ";
    }
    
    file << setw(7) << (dist(mt)) << endl;
  }
  
  file.close();
  return file_name;
}