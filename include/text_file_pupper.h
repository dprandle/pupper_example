#ifndef TEXT_FILE_PUPPER_H
#define TEXT_FILE_PUPPER_H

#include "pupper.h"

struct text_file_pupper : public pupper
{
    text_file_pupper(std::fstream & fstrm, int mode);
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

template<class T>
void pup_text(text_file_pupper * p, T & val, const var_info & info, std::string & line)
{
    std::string begtag, endtag;
	begtag = "<" + info.name + ">"; endtag = "</" + info.name + ">";

    if (p->io == PUP_OUT)
	{
        p->fs << begtag << static_cast<T>(val) << endtag << "\n";
	}
	else
	{
        std::getline(p->fs, line);
		size_t beg = begtag.size(); size_t loc = line.find(endtag);
		line = line.substr(beg, loc - beg);
	}
}

#endif
