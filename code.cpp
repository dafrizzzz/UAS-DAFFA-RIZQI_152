#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Kamar {
    int nomor;
    string tipe;
    bool tersedia;
};

class RumahSakit {
private:
    vector<Kamar> daftarKamar;

public:
    void tambahKamar(int nomor, const string& tipe) {
        Kamar kamarBaru = {nomor, tipe, true};
        daftarKamar.push_back(kamarBaru);
        cout << "Kamar " << nomor << " berhasil ditambahkan." << endl;
    }

    void tampilkanKamar() {
        cout << "Daftar Kamar Rumah Sakit:" << endl;
        for (const auto& kamar : daftarKamar) {
            cout << "Nomor Kamar: " << kamar.nomor 
                 << ", Tipe: " << kamar.tipe 
                 << ", Tersedia: " << (kamar.tersedia ? "Ya" : "Tidak") << endl;
        }
    }

    void hapusKamar(int nomor) {
        for (auto it = daftarKamar.begin(); it != daftarKamar.end(); ++it) {
            if (it->nomor == nomor) {
                daftarKamar.erase(it);
                cout << "Kamar " << nomor << " berhasil dihapus." << endl;
                return;
            }
        }
        cout << "Kamar " << nomor << " tidak ditemukan." << endl;
    }
};

int main() {
    RumahSakit rs;
    int pilihan;
    
    do {
        cout << "\nMenu Pengelolaan Kamar Rumah Sakit:" << endl;
        cout << "1. Tambah Kamar" << endl;
        cout << "2. Tampilkan Kamar" << endl;
        cout << "3. Hapus Kamar" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int nomor;
                string tipe;
                cout << "Masukkan nomor kamar: ";
                cin >> nomor;
                cout << "Masukkan tipe kamar: ";
                cin >> tipe;
                rs.tambahKamar(nomor, tipe);
                break;
            }
            case 2:
                rs.tampilkanKamar();
                break;
            case 3: {
                int nomor;
                cout << "Masukkan nomor kamar yang ingin dihapus: ";
                cin >> nomor;
                rs.hapusKamar(nomor);
                break;
            }
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}