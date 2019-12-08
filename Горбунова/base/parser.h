#pragma once
#include <string>
#include "polynomial.h"
#include "exponent.h"

class parser
{
public:
	bool try_parse(std::string str, polynomial &result);
};