
#pragma once

#include <string>

#include <SDL.h>

#include <filestore/file.h>

#define SQUARE(x) (x*x)

#ifdef _WIN32
	const char PATH_SEP = '\\';
#else
	const char PATH_SEP = '/';
#endif


//used when renaming the file for new tags
typedef struct {

    //  [                   dirs                   ][   name    ][ext]
    //  /home/brendan/dev/cpp/collector/src/display/displayobject.cpp

    std::string dirs;
    std::string name;
    std::string ext;
} Path_Parts;


void to_lower(std::string & s);
bool file_exists(const char* filename);
bool dir_exists(const char* path);
bool starts_with(std::string str, std::string partial);
bool is_number(const std::string& s);
Path_Parts get_path_parts(std::string path);
std::string join_path_parts(Path_Parts p);
std::string escape_file_name(std::string &path);
std::string double_to_str(double d, int p);
std::string pretty_print_file_size(size_t size);
std::string path_join(std::string a_str, std::string b_str);

/*
    Set Operations
*/

template<typename T>
void set_intersect(T & out, const T & in_A, const T & in_B)
{
    if(in_B.size() < in_A.size())
    {
        //swap the arguments so that we only iterate through the smaller set
        set_intersect<T>(out, in_B, in_A);
        return;
    }

    out.clear();

    for(auto it = in_A.begin(); it != in_A.end(); it++)
    {
        if(in_B.find(*it) != in_B.end())
            out.insert(*it);
    }
}

template<typename T>
void set_union(T & out, const T & in)
{
    out.insert(in.begin(), in.end());
}
