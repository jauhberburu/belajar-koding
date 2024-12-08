#include <iostream>
#include <map>
#include <string>

// Kelas untuk menyimpan data mahasiswa
class Mahasiswa {
public:
    std::string idMahasiswa;       // ID Mahasiswa
    std::string namaMahasiswa;     // Nama Mahasiswa
    std::string detailKursus;      // Detail Kursus
    double nilaiAkhir;             // Nilai Akhir

    // Konstruktor
    Mahasiswa(const std::string &id, const std::string &nama, const std::string &kursus, double nilai)
        : idMahasiswa(id), namaMahasiswa(nama), detailKursus(kursus), nilaiAkhir(nilai) {}

    // Fungsi untuk menampilkan data mahasiswa
    void tampilkan() const {
        std::cout << "ID Mahasiswa: " << idMahasiswa << "\nNama Mahasiswa: " << namaMahasiswa
                  << "\nDetail Kursus: " << detailKursus << "\nNilai Akhir: " << nilaiAkhir << "\n";
    }
};

int main() {
    std::map<std::string, Mahasiswa> mahasiswa;
    int jumlahMahasiswa;

    // Meminta jumlah mahasiswa yang akan diinput
    std::cout << "Masukkan jumlah mahasiswa: ";
    std::cin >> jumlahMahasiswa;

    // Loop untuk mengumpulkan data mahasiswa
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        std::string idMahasiswa, namaMahasiswa, detailKursus;
        int nilaiTugas, nilaiUjian;

        // Mengumpulkan data mahasiswa
        std::cout << "Masukkan ID Mahasiswa: ";
        std::cin >> idMahasiswa;

        std::cout << "Masukkan Nama Mahasiswa: ";
        std::cin >> namaMahasiswa;

        std::cout << "Masukkan Detail Kursus: ";
        std::cin >> detailKursus;

        std::cout << "Masukkan Nilai Tugas: ";
        std::cin >> nilaiTugas;

        std::cout << "Masukkan Nilai Ujian: ";
        std::cin >> nilaiUjian;

        // Menghitung nilai akhir
        double nilaiAkhir = (nilaiTugas * 0.4) + (nilaiUjian * 0.6);

        // Mengecek kesalahan (nilai negatif tidak diperbolehkan)
        if (nilaiTugas < 0 || nilaiUjian < 0) {
            std::cout << "Error: Nilai negatif tidak diperbolehkan.\n";
            --i; // Ulangi iterasi saat ini
            continue;
        }

        // Menyimpan data mahasiswa ke dalam map
        mahasiswa.emplace(idMahasiswa, Mahasiswa(idMahasiswa, namaMahasiswa, detailKursus, nilaiAkhir));
    }

    // Menampilkan data semua mahasiswa
    for (const auto &entry : mahasiswa) {
        entry.second.tampilkan();
    }

    return 0;
}
