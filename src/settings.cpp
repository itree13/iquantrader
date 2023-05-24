#include "settings.h"
#include <boost/property_tree/ini_parser.hpp>

Settings& Settings::instance() {
	static Settings s_settigs;
	return s_settigs;
}

bool Settings::load(const string& file_path) {
	ptree_.clear();
	try {
		boost::property_tree::ini_parser::read_ini(file_path, ptree_);
		return true;
	} catch (...) {
	}
	return false;
}