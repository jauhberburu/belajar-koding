#include "../include/Mahasiswa.hpp"
#include "../include/Sistemnilai.hpp"
#include <iostream>

int main() {
    SistemNilai sistemNilai;
    int jumlahMahasiswa;

    std::cout << "Masukkan jumlah mahasiswa: ";
    std::cin >> jumlahMahasiswa;

    sistemNilai.prosesInputMahasiswa(jumlahMahasiswa);
    sistemNilai.tampilkanSemuaMahasiswa();

    return 0;
}
