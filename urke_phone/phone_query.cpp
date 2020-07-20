#include "pch.h"
#include "phone_query.h"


phone_query::phone_query()
{
	all = true;
	sex_query = sex_query_type::none;
}

bool phone_query::is_empty() const
{
	bool temp1 = true;
	if (number != -1)
		temp1 = false;
	bool temp2 = true;
	if (sex_temp != -1)
		temp2 = false;
	return first_name.empty() && last_name.empty() && temp1 && temp2;
}