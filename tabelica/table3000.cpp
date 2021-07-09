#include "table3000.h"
#include "columns_creator.h"
#include "term_drawer.h"

namespace urke
{

	void table3000::set_options(const term_table_options& o)
	{
		options_ = o;
	}
	void table3000::display(const rx_table_type& table, std::ostream& out)
	{
		columns_creator cc;
		table_drawer td;
		term_table_options tto;
		
		headers_ = cc.create_headers(table, options_);
		td.drawer(options_, table, headers_, std::cout);
	}

} //urke