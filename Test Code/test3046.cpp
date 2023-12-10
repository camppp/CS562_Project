#include <iostream>
#include <cstring>

class Artikal {
    // Define the Artikal class if not already defined
};

class DinString {
    // Define the DinString class if not already defined
};

class Lek : public Artikal {
private:
    long jkl;
    DinString naziv;
    double jedinicnaCena;
    int kolicina;

public:
    Lek() : jkl(0), naziv(""), jedinicnaCena(0), kolicina(0) {}

    Lek(long jkl1, const char naziv1[], double jedinicnaCena1, int kolicina1)
        : jkl(jkl1), naziv(naziv1), jedinicnaCena(jedinicnaCena1), kolicina(kolicina1) {}

    Lek(long jkl1, DinString& naziv1, double jedinicnaCena1, int kolicina1)
        : jkl(jkl1), naziv(naziv1), jedinicnaCena(jedinicnaCena1), kolicina(kolicina1) {}

    Lek(const Lek& lek)
        : jkl(lek.jkl), naziv(lek.naziv), jedinicnaCena(lek.jedinicnaCena), kolicina(lek.kolicina) {}

    double getVrednost() const { return kolicina * jedinicnaCena; }

    // Add any necessary member functions to complete the Lek class
};
