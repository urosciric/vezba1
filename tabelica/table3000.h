#pragma once
#include "term_header.h"

namespace urke
{


	class table3000
	{

		typedef std::vector <table_header> headers_type;

		headers_type headers_;


		term_table_options options_;

	private:

		// udje u podatke prodje i vidi koliki trebaju da budu hederi i da ih vrati nazad

	public:

		void set_options(const term_table_options& o);
		void display(const rx_table_type& table, std::ostream& out);
	};

} //urke

