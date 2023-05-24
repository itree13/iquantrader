#pragma once

#include "type.h"
#include <boost/property_tree/ptree.hpp>

class Settings {
	typedef boost::property_tree::ptree ptree_t;
public:
	static Settings& instance();

	bool load(const string& file_path);

public:
	template<class T>
	T value(const string& path, const T& def_value) const {
		return ptree_.get(path, def_value);
	}

	bool exist(const string& path) const {
		return !!ptree_.get_child_optional(path);
	}

private:
	ptree_t ptree_;
};
