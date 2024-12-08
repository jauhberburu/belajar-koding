#include "../include/Sistemnilai.hpp"
#include <iostream>

void SistemNilai::tambahMahasiswa(const std::string &id, const std::string &nama, const std::string &kursus, double nilai) {
    Mahasiswa mahasiswaBaru(id, nama, kursus, nilai);
    daftarMahasiswa[id] = mahasiswaBaru;
}

void SistemNilai::tampilkanSemuaMahasiswa() const {
    for (const auto &pair : daftarMahasiswa) {
        pair.second.tampilkan();
    }
}

double SistemNilai::hitungNilaiAkhir(int nilaiTugas, int nilaiUjian) const {
    return (nilaiTugas * 0.4) + (nilaiUjian * 0.6);
}

void SistemNilai::prosesInputMahasiswa(int jumlahMahasiswa) {
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        std::string idMahasiswa, namaMahasiswa, detailKursus;
        int nilaiTugas, nilaiUjian;

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

        if (nilaiTugas < 0 || nilaiUjian < 0) {
            std::cout << "Error: Nilai negatif tidak diperbolehkan.\n";
            --i;
            continue;
        }

        double nilaiAkhir = hitungNilaiAkhir(nilaiTugas, nilaiUjian);
        tambahMahasiswa(idMahasiswa, namaMahasiswa, detailKursus, nilaiAkhir);
    }
}
