#ifndef MAHASISWA_HPP
#define MAHASISWA_HPP

#include <string>

class Mahasiswa {
private:
    std::string idMahasiswa;
    std::string namaMahasiswa;
    std::string detailKursus;
    double nilaiAkhir;

public:
    Mahasiswa(const std::string &id, const std::string &nama, const std::string &kursus, double nilai);

    void tampilkan() const;
    double getNilaiAkhir() const;
    void setNilaiAkhir(double nilai);
};

#endif // MAHASISWA_HPP
