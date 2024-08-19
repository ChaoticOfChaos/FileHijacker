// BlackList.hpp

#ifndef BLACKLIST_HPP
#define BLACKLIST_HPP

#include <string>
#include <vector>

bool ends_with(const std::string& value, const std::string& ending) {
	if (ending.size() > value.size()) return false;
	return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

bool BlackList(std::string value, std::vector<std::string> blacklist) {
	for (std::string v : blacklist) {
		if (ends_with(value, v) == true) {
			return true;
		}
	}
	return false;
}

#endif