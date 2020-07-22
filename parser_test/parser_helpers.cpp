#include "pch.h"
#include "parser_helpers.h"

bool do_parse(const string_type what, parser3000& parser, string_type& err)
{
	std::ostringstream serr;
	std::istringstream ss(what);
	if (parser.parse(ss, serr))
	{
		return true;
	}
	else
	{
		err = serr.str();
		return false;
	}
}