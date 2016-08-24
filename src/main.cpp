#include <iostream>
#include "binary_file_pupper.h"
#include "text_file_pupper.h"
#include "obj_a.h"
#include "obj_a_container.h"
#include "derived_obj_a.h"
#include "math_structs.h"


/*
This will populate the obj a container with data based on the offset - every subsequent velocity
will be incresed by offset, and the tform uses it too - not really important - you should just
see a pattern in the data. cnt is how many obj a's to make and cnt_d is how many derived obj a's
to make
*/
void populate_data(obj_a_container * a_cont, const fvec4 & offset, int cnt, int cnt_d);

/*
Utility for making string out of fvec4
*/
std::string fvec4_to_string(const fvec4 & vc);

/*
Display the data in obj_a to std::cout - displays the extended derived_obj_a health
for derived_obj_a objects
*/
void display_data(obj_a_container * a_cont);

/*
For both read and write functions...
a_cont: The obj a container
fname: file name for data file
save_mode: 0 for text and 1 for binary
*/
void read_data_from_file(obj_a_container * a_cont, const std::string & fname, int save_mode);
void write_data_to_file(obj_a_container * a_cont, const std::string & fname, int save_mode);

int main()
{
	obj_a_container a_cont;
	bool running = true;
	std::string bin_fname = "obj_data.dat";
	std::string txt_fname = "obj_data.txt";
	std::string fname = txt_fname;
	int save_mode = 0;
	int cnt = 0, cnt_d = 0;
	fvec4 offset;

	while (running)
	{
		std::cout << "\nWhat would you like to do?...\n(p) populate the data\n(d) display the data\n(b) set to binary file io mode\n(t) set to text file io mode\n(r) read data from file\n(w) write data to file\n(q) quit" << std::endl;
		char c;
		std::cin >> c;
		switch (c)
		{
			case ('p'):
				std::cout << "How many obj a's? (between 0 and 1000 please): ";
				std::cin >> cnt;
				if (cnt < 0)
					cnt = 0;
				if (cnt > 1000)
					cnt = 1000;
				std::cout << "How many derived obj a's? (between 0 and 1000 please): ";
				std::cin >> cnt_d;
				if (cnt_d < 0)
					cnt_d = 0;
				if (cnt_d > 1000)
					cnt_d = 1000;
				std::cout << "\nEnter data offset (x y z w) - this is used to fill data with different values:";
				std::cin >> offset.x >> offset.y >> offset.z >> offset.w;
				std::cout << std::endl;
				populate_data(&a_cont, offset, cnt, cnt_d);
				break;
			case ('d'):
				display_data(&a_cont);
				break;
			case ('r'):
				read_data_from_file(&a_cont, fname, save_mode);
				break;
			case ('w'):
				write_data_to_file(&a_cont, fname, save_mode);
				break;
			case ('q'):
				running = false;
				break;
			case ('t'):
				fname = txt_fname;
				save_mode = 0;
				std::cout << "file io set to text mode" << std::endl;
				break;
			case ('b'):
				fname = bin_fname;
				save_mode = 1;
				std::cout << "file io set to binary mode" << std::endl;
				break;
			default:
                std::cout << "invalid selection - enter either d, p, r, w, or q" << std::endl;
		}
	}
}

void populate_data(obj_a_container * a_cont, const fvec4 & offset, int cnt, int cnt_d)
{

	a_cont->release();
	fvec4 init(offset);
    fvec4 neg_init(-init.x, -init.y, -init.z, -init.w);

	// Now fill up the data with some stuff based on that offset
	std::cout << "Creating " << cnt + cnt_d << " total objects..." << std::endl;
    a_cont->obj_a_vec.resize(cnt+cnt_d);
	float cur_health = 100.0f;
	float max_health = 100.0f;
	for (int i = 0; i < a_cont->obj_a_vec.size(); ++i)
	{
		if (i < cnt)
		{
			std::cout << "Creating obj_a and index " << i << std::endl;
			a_cont->obj_a_vec[i].type = 1;
			a_cont->obj_a_vec[i].ptr = new obj_a();
		}
		else
		{
			std::cout << "Creating derived_obj_a and index " << i << std::endl;
			a_cont->obj_a_vec[i].type = 2;
			a_cont->obj_a_vec[i].ptr = new derived_obj_a(cur_health);
			cur_health -= max_health / cnt_d;
		}

		std::cout << "filling in object data..." << std::endl;
		fmat4 tform;
		for (uint j = 0; j < 4; ++j)
		{
			tform.rows[j] = neg_init;
			neg_init.x -= offset.x/4; neg_init.y -= offset.y/4; neg_init.z -= offset.z/4; neg_init.w -= offset.w/4;
		}
		a_cont->obj_a_vec[i].ptr->set_transform(tform);
		a_cont->obj_a_vec[i].ptr->set_velocity(init);
		init.x += offset.x; init.y += offset.y; init.z += offset.z; init.w += offset.w;
	}
	std::cout << "Data sucessfully populated" << std::endl;
}

std::string fvec4_to_string(const fvec4 & vc)
{
	return "[" + std::to_string(vc.x) + " " + std::to_string(vc.y) + " " + std::to_string(vc.z) + " " + std::to_string(vc.w) + "]";
}

void display_data(obj_a_container * a_cont)
{
	if (a_cont->obj_a_vec.empty())
		std::cout << "Data empty" << std::endl;
	
	for (int i = 0; i < a_cont->obj_a_vec.size(); ++i)
	{
		std::string type = " (obj_a)";
		if (a_cont->obj_a_vec[i].type == 2)
			type = " (derived_obj_a)";
		
        std::cout << "\nObject " << i+1 << type << " properties..." << std::endl;
		std::cout << "Transform:\n";
		fmat4 tform = a_cont->obj_a_vec[i].ptr->get_transform();
		for (uint j = 0; j < 4; ++j)
		{
			std::cout << fvec4_to_string(tform.rows[j]) << "\n";
		}
		std::cout << "Velocity: " << fvec4_to_string(a_cont->obj_a_vec[i].ptr->get_velocity()) << std::endl;
		if (a_cont->obj_a_vec[i].type == 2)
		{
			derived_obj_a * da = static_cast<derived_obj_a*>(a_cont->obj_a_vec[i].ptr);
			std::cout << "Current Health: " << da->health << std::endl;
			std::cout << "Max Health: " << da->max_health << std::endl;
		}
	}
}

void read_data_from_file(obj_a_container * a_cont, const std::string & fname, int save_mode)
{
	std::fstream file;
    pupper * p = nullptr;
    std::ios_base::openmode flags = std::fstream::in;

	if (save_mode)
	{
        flags |= std::fstream::binary;
		p = new binary_file_pupper(file, PUP_IN);

	}
	else
	{
		p = new text_file_pupper(file, PUP_IN);
	}

    file.open(fname, flags);
	if (!file.is_open())
	{
		std::cout << "Error opening file " << fname << std::endl;
		delete p;
		return;
	}

	a_cont->release();
	pup(p, *a_cont, var_info(""));
	std::cout << "Finished reading data from file " << fname << std::endl;
}

void write_data_to_file(obj_a_container * a_cont, const std::string & fname, int save_mode)
{
	std::fstream file;
	pupper * p;
    std::ios_base::openmode flags = std::fstream::out;

	if (save_mode) // if save mode is one then write in binary mode
	{
        flags |= std::fstream::binary;
		p = new binary_file_pupper(file, PUP_OUT);

	}
	else
	{
		p = new text_file_pupper(file, PUP_OUT);
	}

	file.open(fname, flags);
	if (!file.is_open())
	{
		std::cout << "Error opening file " << fname << std::endl;
		delete p;
		return;
	}

	pup(p, *a_cont, var_info(""));
	std::cout << "Finished writing data to file" << fname << std::endl;
}
