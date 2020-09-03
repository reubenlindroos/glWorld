#pragma once 
#include <string>
#include "filesystem.hpp"
namespace io
{
	inline std::string getProjectSrcDir()
	{	
		namespace fs = ghc::filesystem;
		std::string file_path = __FILE__;

		// Using forward slashes consistently
		file_path = fs::absolute(fs::path(__FILE__).remove_filename() / "..");

		return file_path;
	}
}
