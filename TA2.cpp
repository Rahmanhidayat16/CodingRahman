#include <iostream>
using namespace std;

struct Mahasiswa {
    char nama[100]; 
    int nilai;
};

int main() {
    int n;
    Mahasiswa mhs[100];

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin.getline(mhs[i].nama, 100);  
        cout << "Nilai : ";
        cin >> mhs[i].nilai;
        cin.ignore(); 
    }

    for (int i = 1; i < n; i++) {
        Mahasiswa temp = mhs[i];
        int j = i - 1;
        while (j >= 0 && mhs[j].nilai < temp.nilai) {
            mhs[j + 1] = mhs[j];
            j--;
        }
        mhs[j + 1] = temp;
    }

    cout << "\nDaftar mahasiswa setelah diurutkan (nilai tertinggi ke terendah):\n";
    for (int i = 0; i < n; i++) {
        cout << mhs[i].nama << " - " << mhs[i].nilai << endl;
    }

    return 0;
}