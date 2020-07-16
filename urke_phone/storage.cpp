#include "pch.h"
#include "storage.h"
#include "phone_book.h"


storage::storage(const string_type& name)
{
	char buff[MAX_PATH];
	DWORD size = sizeof(buff);
	if (GetEnvironmentVariableA("LocalAppData", buff, sizeof(buff)))
	{
		if (buff[0] == '"')
			file_path = &buff[1];
		else
			file_path = buff;

		file_path += "\\";
		file_path += name;
	}
	else
		file_path = name;
}
bool storage::save(phone_book& what)
{
	std::ofstream file(file_path);

	if (!file.bad())
	{
		what.save(file);
		file.flush();
		file.close();
		return true;
	}
	return false;
}
bool storage::load(phone_book& what)
{
	// check if file exists, if not simply return
	if (_access(file_path.c_str(), 0) != 0)
		return true;

	std::ifstream file(file_path);

	if (!file.bad())
	{
		what.load(file);
		file.close();
		return true;
	}
	return false;
}
