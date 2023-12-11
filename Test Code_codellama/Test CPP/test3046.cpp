#include <iostream>

class Lek {
public:
    Lek() : jkl(0), naziv(""), jedinicnaCena(0), kolicina(0) {}
    Lek(int jkl, std::string naziv, double jedinicnaCena, int kolicina) : jkl(jkl), naziv(naziv), jedinicnaCena(jedinicnaCena), kolicina(kolicina) {}
    Lek(const Lek& other) : jkl(other.jkl), naziv(other.naziv), jedinicnaCena(other.jedinicnaCena), kolicina(other.kolicina) {}
    ~Lek() {}

    double getVrednost() const { return kolicina * jedinicnaCena; }

private:
    int jkl;
    std::string naziv;
    double jedinicnaCena;
    int kolicina;
};
