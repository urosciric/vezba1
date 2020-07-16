#include "pch.h"
#include "commands_manager.h"
#include "commands.h"

commands_manager::commands_manager()
{
}
commands_manager::~commands_manager()
{
	for (auto& one : commands_)
		delete one.second;
}

commands_manager& commands_manager::instance()
{
	static commands_manager g_obj;
	return g_obj;
}
void commands_manager::register_command(command_base* command)
{
	auto name = command->get_name();
	if(commands_.find(name)==commands_.end())
		commands_.emplace(name, command);
}
command_base* commands_manager::get_command(const string_type& name)
{
	auto it = commands_.find(name);
	if (it != commands_.end())
		return it->second;
	it = commands_.find("help");
	if (it != commands_.end())
		return it->second;
	return nullptr;
}
std::vector<command_base*> commands_manager::get_commands_list()
{
	std::vector<command_base*> ret;
	// rezervisi prostor u memoriji zbog brzine
	ret.reserve(commands_.size());
	for (auto one : commands_)
		ret.emplace_back(one.second);
	return ret;
}
