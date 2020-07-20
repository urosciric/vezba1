#include "pch.h"
#include "phone_query.h"
#include "phone_book.h"
#include "query_finder_base.h"



bool name_query_finder::is_included(const phone_query& query, const phone_data& data)
{
	if (query.first_name.empty())
		return true;
	else
		return query.first_name == data.first_name;
}


bool last_name_query_finder::is_included(const phone_query& query, const phone_data& data)
{
	if (query.first_name.empty())
		return true;
	else
		return query.first_name == data.first_name;
}
