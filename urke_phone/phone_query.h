#pragma once
struct phone_query
{
	bool all;

	string_type first_name;
	string_type last_name;

	phone_query();
	
	bool is_empty() const;

};

