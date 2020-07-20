#pragma once
struct phone_query;
struct phone_data;

namespace finders
{

class query_finder_base
{
public:
	virtual bool is_included(const phone_query& query, const phone_data& data) = 0;
	virtual ~query_finder_base() = default;
};

class name_query_finder : public query_finder_base
{
public:
	bool is_included(const phone_query& query, const phone_data& data);
};


class last_name_query_finder : public query_finder_base
{
public:
	bool is_included(const phone_query& query, const phone_data& data);
};

}

