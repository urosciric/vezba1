#pragma once
class command_base;

class commands_manager
{
	typedef std::map<string_type, command_base*> commands_type;
	commands_type commands_;

	commands_manager();
	~commands_manager();

public:
	static commands_manager& instance();
	void register_command(command_base* command);
	command_base* get_command(const string_type& name);
	std::vector<command_base*> get_commands_list();
};

