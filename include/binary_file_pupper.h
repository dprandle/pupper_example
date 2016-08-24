#ifndef BINARY_FILE_PUPPER_H
#define BINARY_FILE_PUPPER_H

#include "pupper.h"

struct binary_file_pupper : public pupper
{
    binary_file_pupper(std::fstream & fstrm, int mode);
	std::fstream & fs;
	void pup(char & val_, const var_info & info_);
	void pup(wchar_t & val_, const var_info & info_);
	void pup(int8_t & val_, const var_info & info_);
	void pup(int16_t & val_, const var_info & info_);
	void pup(int32_t & val_, const var_info & info_);
	void pup(int64_t & val_, const var_info & info_);
	void pup(uint8_t & val_, const var_info & info_);
	void pup(uint16_t & val_, const var_info & info_);
	void pup(uint32_t & val_, const var_info & info_);
	void pup(uint64_t & val_, const var_info & info_);
	void pup(float & val_, const var_info & info_);
	void pup(double & val_, const var_info & info_);
	void pup(long double & val_, const var_info & info_);
	void pup(bool & val_, const var_info & info_);
};

template <class T>
void pup_bytes(binary_file_pupper * p, T & val_)
{
    if (p->io == PUP_IN)
        p->fs.read((char*)&val_, sizeof(T));
	else
        p->fs.write((char*)&val_, sizeof(T));
}

#endif

