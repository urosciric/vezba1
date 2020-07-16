#pragma once

struct phone_data
{
    string_type first_name;
    string_type last_name;
    string_type street;
    unsigned int number = 2;
    bool male = 0;
    string_type phone;
};

class phone_book
{
    typedef std::map<string_type, phone_data> data_type;
    // ako hocu hash:
    //typedef std::unordered_map<string_type, phone_data> data_type;

    data_type data_;

    string_type create_key(string_type ime, string_type prezime);
    bool check_data(const phone_data& data);
public:
    void add(phone_data data);
    void save(std::ostream& out);
    void load(std::istream& out);
};

