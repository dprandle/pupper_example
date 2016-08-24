#ifndef PUPPER_H
#define PUPPER_H

#define PUP_OUT 1
#define PUP_IN 2

#include <string>
#include <fstream>
#include <inttypes.h>

struct var_info
{
	var_info(const std::string & name_):
		name(name_)
	{}

	virtual ~var_info() {}

	std::string name;
};

struct pupper
{
    pupper(int32_t io_):
        io(io_)
    {}

	virtual void pup(char & val_, const var_info & info_) = 0;
	virtual void pup(wchar_t & val_, const var_info & info_) = 0;
	virtual void pup(int8_t & val_, const var_info & info_) = 0;
	virtual void pup(int16_t & val_, const var_info & info_) = 0;
	virtual void pup(int32_t & val_, const var_info & info_) = 0;
	virtual void pup(int64_t & val_, const var_info & info_) = 0;
	virtual void pup(uint8_t & val_, const var_info & info_) = 0;
	virtual void pup(uint16_t & val_, const var_info & info_) = 0;
	virtual void pup(uint32_t & val_, const var_info & info_) = 0;
	virtual void pup(uint64_t & val_, const var_info & info_) = 0;
	virtual void pup(float & val_, const var_info & info_) = 0;
	virtual void pup(double & val_, const var_info & info_) = 0;
	virtual void pup(long double & val_, const var_info & info_) = 0;
	virtual void pup(bool & val_, const var_info & info_) = 0;

	int32_t io;
};

void pup(pupper * p, char & val_, const var_info & info_);
void pup(pupper * p, wchar_t & val_, const var_info & info_);
void pup(pupper * p, int8_t & val_, const var_info & info_);
void pup(pupper * p, int16_t & val_, const var_info & info_);
void pup(pupper * p, int32_t & val_, const var_info & info_);
void pup(pupper * p, int64_t & val_, const var_info & info_);
void pup(pupper * p, uint8_t & val_, const var_info & info_);
void pup(pupper * p, uint16_t & val_, const var_info & info_);
void pup(pupper * p, uint32_t & val_, const var_info & info_);
void pup(pupper * p, uint64_t & val_, const var_info & info_);
void pup(pupper * p, float & val_, const var_info & info_);
void pup(pupper * p, double & val_, const var_info & info_);
void pup(pupper * p, long double & val_, const var_info & info_);
void pup(pupper * p, bool & val_, const var_info & info_);

#endif
