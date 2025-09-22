#include <iostream>
using namespace std;

int main() {
    const int maxBarang = 5;
    string nama[maxBarang] = {"Pensil", "Buku", "Penghapus", "Bolpoin", "Penggaris"};
    int stok[maxBarang] = {10, 5, 7, 8, 6}; 

    char lanjut = 'y';

    while (lanjut == 'y' || lanjut == 'Y') {
        cout << "\n=== Daftar Barang ===\n";
        for (int i = 0; i < maxBarang; i++) {
            cout << i+1 << ". " << nama[i] << " (Stok: " << stok[i] << ")\n";
        }

        int pilihan;
        cout << "\nPilih barang yang anda cari (1-" << maxBarang << "): ";
        cin >> pilihan;

        if (pilihan < 1 || pilihan > maxBarang) {
            cout << "Pilihan barang tidak tersedia! Coba lagi.\n";
            continue; 
        }

        int beli;
        while (true) {
            cout << "Mau beli berapa " << nama[pilihan-1] << "? ";
            cin >> beli;

            if (beli <= 0) {
                cout << "Jumlah tidak valid!\n";
            }
            else if (beli > stok[pilihan-1]) {
                cout << "Stok " << nama[pilihan-1] << " tidak mencukupi! Stok tersedia: " 
                     << stok[pilihan-1] << endl;
            }
            else {
                break; 
            }
        }

        stok[pilihan-1] -= beli;
        cout << "Pembelian berhasil! Sisa stok " << nama[pilihan-1] 
             << ": " << stok[pilihan-1] << endl;

        cout << "\nMasih ada yang mau dibeli? (y/n): ";
        cin >> lanjut;
    }

    cout << "\n=== Sisa Stok Barang ===\n";
    for (int i = 0; i < maxBarang; i++) {
        cout << nama[i] << " : " << stok[i] << endl;
    }

    cout << "\nTerimakasih telah berbelanja. Sampai Jumpa kembali!\n";
    return 0;
}