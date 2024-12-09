#include <iostream>
#include <map>
#include <string>

// Kelas untuk menyimpan data mahasiswa
class Mahasiswa {
public:
    std::string idMahasiswa;       // ID Mahasiswa
    std::string namaMahasiswa;     // Nama Mahasiswa
    double nilaiAkhir;             // Nilai Akhir

    // Konstruktor
    Mahasiswa(const std::string &id, const std::string &nama, double nilai)
        : idMahasiswa(id), namaMahasiswa(nama), nilaiAkhir(nilai) {}

    // Fungsi untuk menampilkan data mahasiswa
    void tampilkan() const {
        std::cout << "ID Mahasiswa: " << idMahasiswa << "\nNama Mahasiswa: " << namaMahasiswa
                  << "\nNilai Akhir: " << nilaiAkhir << "\n";
    }
};

int main() {
    std::map<std::string, Mahasiswa> mahasiswa;
    int jumlahMahasiswa;
    std::string detailKursus;

    // Meminta detail kursus sekali
    std::cout << "Masukkan Detail Kursus: ";
    std::cin >> detailKursus;

    // Meminta jumlah mahasiswa yang akan diinput
    std::cout << "Masukkan jumlah mahasiswa: ";
    std::cin >> jumlahMahasiswa;

    double totalNilai = 0;

    // Loop untuk mengumpulkan data mahasiswa
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        std::string idMahasiswa, namaMahasiswa;
        int nilaiTugas, nilaiUjian;

        // Mengumpulkan data mahasiswa
        std::cout << "Masukkan ID Mahasiswa: ";
        std::cin >> idMahasiswa;

        std::cout << "Masukkan Nama Mahasiswa: ";
        std::cin >> namaMahasiswa;

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
        mahasiswa.emplace(idMahasiswa, Mahasiswa(idMahasiswa, namaMahasiswa, nilaiAkhir));
        totalNilai += nilaiAkhir;
    }

    // Menampilkan data semua mahasiswa
    for (const auto &entry : mahasiswa) {
        entry.second.tampilkan();
    }

    // Menghitung rata-rata nilai
    double rataRataNilai = totalNilai / jumlahMahasiswa;

    // Menampilkan hasil
    std::cout << "Rata-rata Nilai: " << rataRataNilai << "\n";
    if (rataRataNilai > 70) {
        std::cout << "Semua mahasiswa lulus.\n";
    } else {
        std::cout << "Semua siswa gagal mengikuti kelas.\n";
    }

    return 0;
}