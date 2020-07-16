#include "pch.h"
#include "phone_book.h"


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
phone_data phone_book::find(const string_type& name, const string_type& last_name)
{
    auto it = data_.find(create_key(name, last_name));
    if (it != data_.end())
        return it->second;
    else
        return phone_data();
}

