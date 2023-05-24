#pragma once

#include "type.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <vector>

class Settings {
	typedef boost::property_tree::ptree ptree_t;
public:
	static Settings& instance() {
		static Settings s_settigs;
		return s_settigs;
	}

	bool load(const string& file_path) {
		ptree_.clear();
		try {
			boost::property_tree::ini_parser::read_ini(file_path, ptree_);
			return true;
		} catch (...) {
		}
		return false;
	}

public:
	template<class T>
	T value(const string& path, const T& def_value) const {
		return ptree_.get(path, def_value);
	}

	template<class T>
	bool values(const string& path, std::vector<T>* s) const {
		std::pair<ptree_t::const_assoc_iterator, ptree_t::const_assoc_iterator> pr;
		size_t pos = path.rfind('.');
		if (pos != string::npos) {
			boost::optional<const ptree_t&> opt = ptree_.get_child_optional(
				path.substr(0, pos));
			if (!opt)
				return false;
			pr = opt->equal_range(path.substr(pos + 1));
		} else
			pr = ptree_.equal_range(path);

		for (ptree_t::const_assoc_iterator ai = pr.first; ai != pr.second;
			++ai) {
			boost::optional<T> opt = ai->second.get_value_optional<T>();
			if (opt)
				s->push_back(*opt);
		}
		return true;
	}

	bool exist(const string& path) const {
		return !!ptree_.get_child_optional(path);
	}

private:
	ptree_t ptree_;
};
