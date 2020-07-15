#include "telefonski_imenik.h"
#include <ostream>
#include <istream>
#include <sstream>


string telefonski_imenik::kreiraj_kljuc(string ime, string prezime)
{
    return ime + prezime;
}
bool telefonski_imenik::podaci_imaju_smisla(const imenik_data& data)
{
    return !data.ime.empty() && !data.prezime.empty() && !data.ulica.empty() && data.broj > 0 && !data.telefon.empty();
}

void telefonski_imenik::dodaj(imenik_data data)
{
    podaci.emplace(kreiraj_kljuc(data.ime, data.prezime), data);
}
string telefonski_imenik::nadji_broj_telefona(string ime, string prezime)
{
    kontejner_tip::iterator it = podaci.find(kreiraj_kljuc(ime, prezime));
    if (it != podaci.end())
        return it->second.telefon;
    else
        return "";

}
string telefonski_imenik::nadji_adresu(string ime, string prezime)
{
    kontejner_tip::iterator it = podaci.find(kreiraj_kljuc(ime, prezime));
    if (it != podaci.end())
    {
        std::ostringstream ss;
        ss
            << it->second.ulica
            << " "
            << it->second.broj;

        return ss.str();
    }
    else
        return "";
}
bool telefonski_imenik::jel_musko(string ime, string prezime)
{
    kontejner_tip::iterator it = podaci.find(kreiraj_kljuc(ime, prezime));
    if (it != podaci.end())
        return it->second.musko;
    else
        return false;
}
bool telefonski_imenik::ima_li_ga(string ime, string prezime)
{
    return podaci.find(kreiraj_kljuc(ime, prezime)) != podaci.end();
}
void telefonski_imenik::snimi(std::ostream& out)
{
    for (kontejner_tip::iterator it = podaci.begin(); it != podaci.end(); it++)
    {
        out
            << it->second.ime << "\t"
            << it->second.prezime << "\t"
            << it->second.ulica << "\t"
            << it->second.broj << "\t"
            << it->second.musko << "\t"
            << it->second.telefon << "\r\n";
    }
}
void telefonski_imenik::ucitaj(std::istream& in)
{
    while (!in.eof())
    {
        imenik_data data;
        in >> data.ime;
        in >> data.prezime;
        in >> data.ulica;
        in >> data.broj;
        in >> data.musko;
        in >> data.telefon;
        if(podaci_imaju_smisla(data))
            dodaj(data);
    }
}
