#include "pch.h"
#include "phone_book.h"
#include "phone_query.h"


string_type phone_book::create_key(string_type first, string_type last)
{
    return first + last;

}
bool phone_book::check_data(const phone_data& data)
{
    return !data.first_name.empty() && !data.last_name.empty() && !data.street.empty() && data.number > 0 && !data.phone.empty();
}
void phone_book::add(phone_data data)
{
    data_.emplace(create_key(data.first_name, data.last_name), data);
}

void phone_book::save(std::ostream& out)
{
    for (data_type::iterator it = data_.begin(); it != data_.end(); it++)
    {
        out
            << it->second.first_name << "\t"
            << it->second.last_name << "\t"
            << it->second.street << "\t"
            << it->second.number << "\t"
            << it->second.male << "\t"
            << it->second.phone << "\r\n";
    }
}
void phone_book::load(std::istream& in)
{
    while (!in.eof())
    {
        phone_data data;
        in >> data.first_name;
        in >> data.last_name;
        in >> data.street;
        in >> data.number;
        in >> data.male;
        in >> data.phone;
        if (check_data(data))
            add(data);

    }
}
std::vector<phone_data> phone_book::find(const phone_query& query) const
{
    std::vector<phone_data> result;
    for (auto& one : data_)
    {
        auto& one_data = one.second;
        if (query.is_empty())
            result.push_back(one_data);
        else if(query.all && compare_and(one_data, query))
            result.push_back(one_data);
        else if (!query.all && compare_or(one_data, query))
            result.push_back(one_data);
    }
    return result;
}
bool phone_book::compare_and(const phone_data& data, const phone_query& query) const
{
    /////////////////////////////////////////////////////////////////////////////////
    if (!query.first_name.empty() && query.last_name.empty() && query.number == -1 && query.sex_temp == -1)
    {
        if (data.first_name == query.first_name)
            return true;
    }
    //samo ime
    else if (!query.last_name.empty() && query.first_name.empty() && query.number == -1 && query.sex_temp == -1)
    {
        if (data.last_name == query.last_name)
            return true;
    }
    //samo prezime
    else if (query.last_name.empty() && query.first_name.empty() && query.number != -1 && query.sex_temp == -1)
    {
        if (data.number == query.number)
            return true;
    }
    //samo broj
    else if (query.last_name.empty() && query.first_name.empty() && query.number == -1 && query.sex_temp != -1)
    {
        if (data.male == query.sex)
            return true;
    }
    //samo pol
    else if (!query.last_name.empty() && !query.first_name.empty() && query.number == -1 && query.sex_temp == -1)
    {
        if (data.male == query.sex)
            return true;
    }
    //ime i prezime
    else if (query.last_name.empty() && !query.first_name.empty() && query.number != -1 && query.sex_temp == -1)
    {
        if (data.male == query.sex)
            return true;
    }
    //ime i broj
    else if (query.last_name.empty() && !query.first_name.empty() && query.number == -1 && query.sex_temp != -1)
    {
        if (data.male == query.sex)
            return true;
    }
    //ime i pol
    else if (!query.last_name.empty() && query.first_name.empty() && query.number != -1 && query.sex_temp == -1)
    {
        if (data.male == query.sex)
            return true;
    }
    //prezime i broj
    else if (!query.last_name.empty() && query.first_name.empty() && query.number == -1 && query.sex_temp != -1)
    {
        if (data.male == query.sex)
            return true;
    }
    //prezime i pol
    else if (query.last_name.empty() && query.first_name.empty() && query.number != -1 && query.sex_temp != -1)
    {
        if (data.male == query.sex)
            return true;
    }
    //broj i pol
    else if (query.last_name.empty() && query.first_name.empty() && query.number == -1 && query.sex_temp != -1)
    {
        if (data.male == query.sex)
            return true;
    }
    //prezime, ime i broj
    else if (!query.last_name.empty() && !query.first_name.empty() && query.number != -1 && query.sex_temp == -1)
    {
        if (data.male == query.sex)
            return true;
    }
    //prezime, ime i pol
    else if (!query.last_name.empty() && !query.first_name.empty() && query.number == -1 && query.sex_temp != -1)
    {
        if (data.male == query.sex)
            return true;
    }
    //ime, pol i broj
    else if (!query.last_name.empty() && !query.first_name.empty() && query.number!=-1 && query.sex_temp != -1)
    {
        if (data.first_name == query.first_name && data.last_name == query.last_name && data.number == query.number && data.male == query.sex)
            return true;
    }
    //sve
    return false;
}
//////////////////////////////////////////////////////////////////////////////////////////////
bool phone_book::compare_or(const phone_data& data, const phone_query& query) const
{
    if (!query.first_name.empty() && query.last_name.empty())
    {
        if (data.first_name == query.first_name)
            return true;
    }
    else if (!query.last_name.empty() && query.first_name.empty())
    {
        if (data.last_name == query.last_name)
            return true;
    }
    else if(!query.last_name.empty() && !query.first_name.empty())
    {
        if (data.first_name == query.first_name || data.last_name == query.last_name)
            return true;
    }
    if (query.number != -1)
    {
        if (data.number == query.number)
            return true;
    }
    if (query.sex_temp != -1 && data.male == query.sex)
        return true;
    return false;
}

