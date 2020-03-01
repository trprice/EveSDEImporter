#include <ryml.hpp>
#include<iostream>
 
#include <boost/program_options.hpp>
namespace po = boost::program_options;

struct Options
{
	std::string sde_path;
};

void on_sde_path(std::string sde_path)
{
	std::cout << "Running with SDE data located at: " << sde_path << std::endl;
}

bool setup_options(int argc, char* argv[])
{
	po::options_description desc("Allowed Options");

	Options opts;
	desc.add_options()
		("help", "Display help message")
		("sde-path", po::value<std::string>(&opts.sde_path)->required()->notifier(&on_sde_path), "SDE Data File");
	;
	
	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);

	if (vm.count("help"))
	{
		std::cout << desc << std::endl;
		return false;
	}

	try {
		po::notify(vm);
	}
	catch (boost::program_options::required_option& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		return false;
	}

	return true;
}

int main(int argc, char *argv[])
{
	if (!setup_options(argc, argv))
		return -1;

	return 1;
}
