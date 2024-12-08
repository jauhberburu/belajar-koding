#include "../include/Mahasiswa.hpp"
#include <iostream>

Mahasiswa::Mahasiswa(const std::string &id, const std::string &nama, const std::string &kursus, double nilai)
    : idMahasiswa(id), namaMahasiswa(nama), detailKursus(kursus), nilaiAkhir(nilai) {}

void Mahasiswa::tampilkan() const {
    std::cout << "ID Mahasiswa: " << idMahasiswa << "\nNama Mahasiswa: " << namaMahasiswa
              << "\nDetail Kursus: " << detailKursus << "\nNilai Akhir: " << nilaiAkhir << "\n";
}

double Mahasiswa::getNilaiAkhir() const {
    return nilaiAkhir;
}

void Mahasiswa::setNilaiAkhir(double nilai) {
    nilaiAkhir = nilai;
}
