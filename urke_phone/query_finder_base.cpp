#include "pch.h"
#include "phone_query.h"
#include "phone_book.h"
#include "query_finder_base.h"


namespace finders
{

bool name_query_finder::is_included(const phone_query& query, const phone_data& data)
{
	if (query.first_name.empty())
		return true;
	else
		return query.first_name == data.first_name;
}


bool last_name_query_finder::is_included(const phone_query& query, const phone_data& data)
{
	if (query.last_name.empty())
		return true;
	else
		return query.last_name == data.last_name;
}


bool number_query_finder::is_included(const phone_query& query, const phone_data& data)
{
	if (query.number==-1)
		return true;
	else
		return query.number == data.number;
}


bool sex_query_finder::is_included(const phone_query& query, const phone_data& data)
{
	if (query.sex_temp == -1)
		return true;
	else
		return query.sex == data.male;
}

} //  namespace finders (ovaj komentar je korisno pisati ako je fajl duzi da se lakse snadjes)
