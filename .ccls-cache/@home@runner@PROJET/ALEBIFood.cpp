#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct Makanan {
    int Id;
    string namaMakan;
    int harga;
};

struct Pilihan {
    string pilEntry, pilTambahan;
};

struct Contains {
    int makanan;
};

class SoalUjian {
public:
    void MenuEntry() {
        Pilihan pilAwal;
        string namaPemesan;


      cout << "||     AlebiFood      ||" <<
endl;
      cout << "||     MENU ENTRY     ||" << endl;
      cout << "===========================" << endl;
        cout << "\nApakah Anda ingin melihat menu? (y/n) ";
        cin >> pilAwal.pilEntry;

        if (pilAwal.pilEntry == "y" || pilAwal.pilEntry == "Y") {
            cout << "\nMasukkan nama Anda \t: ";
            cin >> namaPemesan;

            TampilkanMenu(namaPemesan);
        } else if (pilAwal.pilEntry == "n" || pilAwal.pilEntry == "N") {
            cout << "TERIMAKASIH SUDAH BERKUNJUNG KE ALEBI FOOD! " << endl;
        }
    }

    void MenuMakan(vector<Makanan>& daftarMakanan) {
        daftarMakanan.push_back({1, "BBQ BEEF RUSHER", 650000});
        daftarMakanan.push_back({2, "CHEESE BURGER", 500000});
        daftarMakanan.push_back({3, "DOUBLE CHEESEBURGER", 70000});
        daftarMakanan.push_back({4, "CHICKEN BURGER", 40000});
        daftarMakanan.push_back({5, "MOZZARELLA CHEESEBURGER", 75000});

        // Menambahkan opsi pizza ke dalam vektor daftarMakanan
        daftarMakanan.push_back({6, "MARGHERITA", 80000});
        daftarMakanan.push_back({7, "PEPPERONI", 90000});
        daftarMakanan.push_back({8, "VEGETARIAN", 85000});
        daftarMakanan.push_back({9, "HAWAIIAN", 95000});
        daftarMakanan.push_back({10, "SEAFOOD SUPREME", 100000});
    }

    void TampilkanMenu(string namaPemesan) {
        vector<Makanan> daftarMakanan;
        Pilihan pengguna;
        Contains isiMenu;
        MenuMakan(daftarMakanan);

        cout << "||             SELAMAT DATANG             ||" << endl;
        cout << "|| ========= ||" << namaPemesan << "|| ========= ||" << endl;

        do {
            cout << "\nKami memberikan opsi pada hidangan Anda [BURGER] dan [PIZZA] ketika [EXIT] jika ingin keluar : ";
            cin >> pengguna.pilEntry;

            if (pengguna.pilEntry == "BURGER" || pengguna.pilEntry == "burger") {
                TampilkanMakanan(daftarMakanan);
                cout << "|| PILIH MENU KODE : ";
                cin >> isiMenu.makanan;

                if (isiMenu.makanan >= 1 && isiMenu.makanan <= 5) {
                    PesanMakan(daftarMakanan[isiMenu.makanan - 1]);
                } else {
                    cout << "Menu tidak dikenali." << endl;
                }
            } else if (pengguna.pilEntry == "PIZZA" || pengguna.pilEntry == "pizza") {
                TampilkanMakanan(daftarMakanan, 6);
                cout << "|| PILIH MENU KODE : ";
                cin >> isiMenu.makanan;

                if (isiMenu.makanan >= 6 && isiMenu.makanan <= 10) {
                    PesanMakan(daftarMakanan[isiMenu.makanan - 1]);
                } else {
                    cout << "Menu tidak dikenali." << endl;
                }
            } else if (pengguna.pilEntry == "EXIT" || pengguna.pilEntry == "exit") {
                cout << "|| TERIMA KASIH TELAH BERKUNJUNG ||" << endl;
               cout << " ||          made by Azhar :))           ||" << endl; 
              exit(0);
            }  else {
                cout << "Opsi tidak valid. Silakan pilih [BURGER] atau [PIZZA]." << endl;
            }

        } while (pengguna.pilEntry != "KELUAR" && pengguna.pilEntry != "keluar");
    }

    void TampilkanMakanan(const vector<Makanan>& daftarMakanan, int startIdx = 1) {
        cout << "\n||          ANDA MEMILIH HIDANGAN           ||" << endl;
        cout << "|| ====================================== ||" << endl;

        for (int i = startIdx; i < startIdx + 5; ++i) {
            const auto& makanan = daftarMakanan[i - 1];
            cout << "|| ID : " << makanan.Id <<
                " || NAMA : " << makanan.namaMakan <<
                " || HARGA : " << makanan.harga << " ||" << endl;
            cout << "|| ====================================== ||" << endl;
        }
    }

    void PesanMakan(const Makanan& menu) {
        Pilihan pengguna;
        int jumlahPesanan = 1;

        cout << "\nAnda memesan " << menu.namaMakan << " seharga " << menu.harga << endl;

        cout << "\njumlah pesanan tambahan : ";
        cin >> jumlahPesanan;

        int totalHarga = menu.harga * jumlahPesanan;
        cout << "\ntotal harga untuk " << jumlahPesanan << " porsi adalah : " << totalHarga << endl;

        int jumlahBayar;
        cout << "jumlah uang yang akan dibayarkan : Rp";
        cin >> jumlahBayar;

      cout << "\n || =============== STRUK PEMBELIAN =============== || " << endl;
      cout << " || NAMA MAKANAN : " << menu.namaMakan << endl;
      cout << " || JUMLAH PESANAN :" << jumlahPesanan << "porsi" << endl;
      cout << " || HARGA SATUAN :" << menu.harga << endl;
      cout << " -----------------------------------------------------"<< endl;
      cout << " || TOTAL HARGA : Rp" << totalHarga << endl;
      cout << " || JUMLAH BAYAR : Rp" << jumlahBayar << endl;
        if (jumlahBayar >= totalHarga) {
          cout << "||PEMBAYARAN BERHASIL ! " << endl;
          cout << "|| KEMBALIAN : Rp " << (jumlahBayar - totalHarga) << endl;
          cout << "|| TERIMAKASIH TELAH MEMESAN : " << menu.namaMakan << " ||" << endl;
        } else {
            cout << "|| MAAF UANG ANDA TIDAK MENCUKUPI! " << endl;
          cout << "|| PEMBAYARAN GAGAL! " << endl;
           
        }
    }
};

int main() {
    SoalUjian ujian;
    ujian.MenuEntry();

    return 0;
}