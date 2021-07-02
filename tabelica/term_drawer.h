#pragma once
#include "term_table.h"
#include "table3000.h"
class term_table;

namespace urke
{

	class table_drawer
	{

		//headers_type headers_;

	public:

		void drawer(const rx_table_type& table, const std::vector<table_header> ret, std::ostream& out);

	};

} //urke
