#pragma once
struct phone_query;
class query_finder_base;

struct phone_data
{
    string_type first_name;
    string_type last_name;
    string_type street;
    unsigned int number = 2;
    bool male = true;
    string_type phone;
};

class phone_book
{
    
    std::vector<query_finder_base*> finders_;
    string_type create_key(string_type ime, string_type prezime);
    bool check_data(const phone_data& data);
public:

   

    typedef std::map<string_type, phone_data> data_type;
    // ako hocu hash:
    //typedef std::unordered_map<string_type, phone_data> data_type;

    data_type data_;

    // dodani konstruktor i destruktor OBAVEZNO POGLEDAJ!!!
    phone_book();
    ~phone_book();

    void add(phone_data data);
    void save(std::ostream& out);
    void load(std::istream& out);
    std::vector<phone_data> find(const phone_query& query) const;

private:
    bool compare_and(const phone_data& data, const phone_query& query) const;
    bool compare_or(const phone_data& data, const phone_query& query) const;
};

