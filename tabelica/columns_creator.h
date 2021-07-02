#pragma once
#include "table3000.h"
namespace urke
{

	class columns_creator
	{

	public:

		std::vector<table_header> create_headers(const rx_table_type& table, const term_table_options& o);

	};

} // urke