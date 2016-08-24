#include "text_file_pupper.h"

text_file_pupper::text_file_pupper(std::fstream & fstrm, int mode):
    pupper(mode),
    fs(fstrm)
{

}

void text_file_pupper::pup(char & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = line[0];
}


void text_file_pupper::pup(wchar_t & val, const var_info & info)
{
    std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = line[0];
}


void text_file_pupper::pup(int8_t & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = static_cast<int8_t>(std::stoi(line));
}

void text_file_pupper::pup(int16_t & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = static_cast<int16_t>(std::stoi(line));
}

void text_file_pupper::pup(int32_t & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = std::stoi(line);
}

void text_file_pupper::pup(int64_t & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = std::stoll(line);
}


void text_file_pupper::pup(uint8_t & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = static_cast<uint8_t>(std::stoul(line));
}

void text_file_pupper::pup(uint16_t & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = static_cast<uint16_t>(std::stoul(line));
}

void text_file_pupper::pup(uint32_t & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = std::stoul(line);
}

void text_file_pupper::pup(uint64_t & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = std::stoull(line);
}

void text_file_pupper::pup(float & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = std::stof(line);
}

void text_file_pupper::pup(double & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = std::stod(line);
}

void text_file_pupper::pup(long double & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = std::stold(line);
}

void text_file_pupper::pup(bool & val, const var_info & info)
{
	std::string line;
    pup_text(this, val, info, line);
	if (!line.empty())
		val = (line == "true" || line == "TRUE");
}
