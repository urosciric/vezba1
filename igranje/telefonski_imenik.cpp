#include "telefonski_imenik.h"
#include "special_commands.h"
#include <ostream>
#include <istream>
#include <sstream>
#include "pch.h"


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

/// <summary>
/// ////////////////////////////////////////////////////////////////////////////////////
/// </summary>
/// <param name="in"></param>
/// <param name="zajedno"></param>
void telefonski_imenik::ucitaj1(std::istream& in)
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

void telefonski_imenik::ucitaj2(std::istream& in, string zajedno)
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
        if (kreiraj_kljuc(data.ime, data.prezime) == zajedno)
            std::cout << data.telefon << "\r\n";
        else if (zajedno == "muski")
        {
            if (data.musko == 1)
            {
                std::cout << data.ime << "\t"
                    << data.prezime << "\t"
                    << data.ulica << "\t"
                    << data.broj << "\t"
                    << data.musko << "\t"
                    << data.telefon << "\r\n";
            }
        }
        else if (zajedno == "zenski")
        {
            if (data.musko == 0)
            {
                std::cout << data.ime << "\t"
                    << data.prezime << "\t"
                    << data.ulica << "\t"
                    << data.broj << "\t"
                    << data.musko << "\t"
                    << data.telefon << "\r\n";
            }
        }
    }
}
/// <summary>
/// //////////////////////////////////////////////////////////////////////////////
/// </summary>

void telefonski_imenik::upisi()
{
    imenik_data data;
    std::cin >> data.ime;
    std::cin >> data.prezime;
    std::cin >> data.ulica;
    std::cin >> data.broj;
    std::cin >> data.musko;
    std::cin >> data.telefon;
    if (podaci_imaju_smisla(data))
        dodaj(data);
    
}

/*void telefonski_imenik::ispis_broja(string brtel,string ime,string prezime,string zajedno)
{
    if (kreiraj_kljuc(ime, prezime) == zajedno)
        std::cout << brtel << "\r\n";
}*/
