#pragma once

enum class sex_query_type
{
	none = 0,
	male=1,
	female=2
};

struct phone_query
{
	bool all;

	string_type first_name = "";
	string_type last_name = "";
	int number = -1;
	int sex_temp = -1;
	bool sex = true;

	sex_query_type sex_query;

	phone_query();
	
	bool is_empty() const;

};

