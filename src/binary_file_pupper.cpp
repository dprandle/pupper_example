#include "binary_file_pupper.h"

binary_file_pupper::binary_file_pupper(std::fstream & fstrm, int mode):
    pupper(mode),
    fs(fstrm)
{

}

void binary_file_pupper::pup(char & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(wchar_t & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(int8_t & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(int16_t & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(int32_t & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(int64_t & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(uint8_t & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(uint16_t & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(uint32_t & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(uint64_t & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(float & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(double & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(long double & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}

void binary_file_pupper::pup(bool & val_, const var_info & info_)
{
    pup_bytes(this, val_);
}
