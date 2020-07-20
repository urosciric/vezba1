#include "pch.h"
#include "phone_book.h"
#include "phone_query.h"
#include "query_finder_base.h"

phone_book::phone_book()
{
    // dodaj razne finder-e
    finders_.push_back(new finders::name_query_finder());
    finders_.push_back(new finders::last_name_query_finder());
    finders_.push_back(new finders::number_query_finder());
    finders_.push_back(new finders::sex_query_finder());
    // tako dodas i ostale
}
phone_book::~phone_book()
{
    //!!! obrisi findere kreirane sa new!!!
    for (auto one : finders_)
        delete one;
}

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
    bool result = true; // neutrali element za and
    for (auto one : finders_)
        result = result & one->is_included(query, data);
    return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////
bool phone_book::compare_or(const phone_data& data, const phone_query& query) const
{
    bool result = false; // neutrali element za or
    for (auto one : finders_)
        result = result | one->is_included(query, data);
    return result;
}

