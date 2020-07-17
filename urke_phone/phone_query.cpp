#include "pch.h"
#include "phone_query.h"


phone_query::phone_query()
{
	all = true;
}

bool phone_query::is_empty() const
{
	return first_name.empty() && last_name.empty();
}