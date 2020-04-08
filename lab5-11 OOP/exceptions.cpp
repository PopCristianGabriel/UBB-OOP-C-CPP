#pragma once

#include <iostream>
#include <exception>

class MyException2 : public std::exception {
	const char* file;
	int line;
	const char* function;
	const char* information;

public:
	MyException2() {

	}
	MyException2(const char* mesage, const char* file_, int line_, const char* function_, const char* information_ ) : std::exception(mesage),
		file(file_),
		line(line_),
		function(function_),
		information(information_)
	{
	}

	const char* get_file() const { return file; }
	int get_line() const { return line; }
	const char* get_func() const { return function; }
	const char* get_info() const { return information; }

};
