#pragma once
class phone_book;

class storage
{
	string_type file_path;

public:
	storage(const string_type& name);
	bool save(phone_book& what);
	bool load(phone_book& what);
};

