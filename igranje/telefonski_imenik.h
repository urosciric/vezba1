#pragma once

#include <string>
#include <map>
#include <unordered_map>

using std::string;

struct imenik_data
{
    string ime;
    string prezime;
    string ulica;
    unsigned int broj;
    bool musko;
    string telefon;
};

class telefonski_imenik
{
    // ako hocu mapu:
    typedef std::map<string, imenik_data> kontejner_tip;
    // ako hocu hash:
    //typedef std::unordered_map<string, imenik_data> kontejner_tip;

    kontejner_tip podaci;

    string kreiraj_kljuc(string ime, string prezime);
    bool podaci_imaju_smisla(const imenik_data& data);

public:
    void dodaj(imenik_data data);
    string nadji_broj_telefona(string ime, string prezime);
    string nadji_adresu(string ime, string prezime);
    bool jel_musko(string ime, string prezime);
    bool ima_li_ga(string ime, string prezime);
    void snimi(std::ostream& out);
    void ucitaj(std::istream& out);
};
