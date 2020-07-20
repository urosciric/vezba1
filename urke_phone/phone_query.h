#pragma once
struct phone_query
{
	bool all;

	string_type first_name;
	string_type last_name;
	int number = 0;
	int sex_temp = 0;
	bool sex = true;

	phone_query();
	
	bool is_empty() const;

};

