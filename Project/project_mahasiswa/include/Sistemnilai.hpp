#ifndef SISTEMNILAI_HPP
#define SISTEMNILAI_HPP

#include "Mahasiswa.hpp"
#include <unordered_map>
#include <string>

class SistemNilai {
private:
    std::unordered_map<std::string, Mahasiswa> daftarMahasiswa;

public:
    void tambahMahasiswa(const std::string &id, const std::string &nama, const std::string &kursus, double nilai);
    void tampilkanSemuaMahasiswa() const;
    double hitungNilaiAkhir(int nilaiTugas, int nilaiUjian) const;
    void prosesInputMahasiswa(int jumlahMahasiswa);
};

#endif // SISTEMNILAI_HPP
