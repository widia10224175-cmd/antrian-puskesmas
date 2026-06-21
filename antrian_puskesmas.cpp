#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Pasien {
    string nama;
    string keluhan;
};

int main() {
    queue<Pasien> antrian;
    int pilihan;

    do {
        cout << "\n=====================================" << endl;
        cout << " SISTEM ANTRIAN PUSKESMAS DIGITAL " << endl;
        cout << "=====================================" << endl;
        cout << "1. Tambah Pasien" << endl;
        cout << "2. Panggil Pasien" << endl;
        cout << "3. Lihat Antrian Terdepan" << endl;
        cout << "4. Tampilkan Semua Antrian" << endl;
        cout << "5. Jumlah Pasien dalam Antrian" << endl;
        cout << "6. Keluar" << endl;
        cout << "=====================================" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {

        case 1: {
            Pasien p;

            cout << "\nMasukkan Nama Pasien : ";
            getline(cin, p.nama);

            cout << "Masukkan Keluhan      : ";
            getline(cin, p.keluhan);

            antrian.push(p);

            cout << "\nPasien berhasil ditambahkan!" << endl;
            cout << "Nomor Antrian Anda : " << antrian.size() << endl;
            break;
        }

        case 2:
            if (!antrian.empty()) {
                cout << "\nPasien yang dipanggil :" << endl;
                cout << "Nama     : " << antrian.front().nama << endl;
                cout << "Keluhan  : " << antrian.front().keluhan << endl;

                antrian.pop();
            } else {
                cout << "\nAntrian masih kosong!" << endl;
            }
            break;

        case 3:
            if (!antrian.empty()) {
                cout << "\nPasien Selanjutnya :" << endl;
                cout << "Nama     : " << antrian.front().nama << endl;
                cout << "Keluhan  : " << antrian.front().keluhan << endl;
            } else {
                cout << "\nAntrian kosong!" << endl;
            }
            break;

        case 4:
            if (antrian.empty()) {
                cout << "\nAntrian kosong!" << endl;
            } else {
                queue<Pasien> temp = antrian;
                int nomor = 1;

                cout << "\n===== DAFTAR ANTRIAN PASIEN =====" << endl;

                while (!temp.empty()) {
                    cout << nomor << ". "
                         << temp.front().nama
                         << " - " << temp.front().keluhan << endl;

                    temp.pop();
                    nomor++;
                }
            }
            break;

        case 5:
            cout << "\nJumlah Pasien Dalam Antrian : "
                 << antrian.size() << endl;
            break;

        case 6:
            cout << "\nProgram selesai. Terima kasih." << endl;
            break;

        default:
            cout << "\nPilihan tidak tersedia!" << endl;
        }

    } while (pilihan != 6);

    return 0;
}