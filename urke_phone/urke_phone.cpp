#include "pch.h"
#include "storage.h"
#include "phone_book.h"
#include "commands.h"
#include "commands_manager.h"
#include "list_command.h"

void register_commands()
{
    // add commands
    commands_manager::instance().register_command(new help_command());
    commands_manager::instance().register_command(new list_command());

}

int main(int argc, char* argv[])
{
    storage fajl("data");
    phone_book dbase;

    register_commands();

    // handle arguments
    string_type command_name;
    if (argc < 2)
        command_name = "help";
    else
        command_name = argv[1];

    string_type arguments;
    for (int i = 2; i < argc; i++)
    {
        arguments += argv[i];
        arguments += " ";
    }

    std::istringstream in_stream(arguments);
    // get command
    auto command = commands_manager::instance().get_command(command_name);
    if (command == nullptr)
    {
        std::cout << "E jebi ga!!!\r\n";
        return -1;
    }

    if (fajl.load(dbase))
    {
        std::cout << "Ucitani podaci\r\n";
        command->do_command(in_stream, dbase);

        if (!fajl.save(dbase))
            std::cout << "Greska pri snimanju u fajl!\r\n";
        else
            std::cout << "Snumljeni podaci podaci\r\n";
    }
    else
    {
        std::cout << "Greska ucitavanju iz fajla!\r\n";
    }
}

