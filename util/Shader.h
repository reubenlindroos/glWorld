#pragma once

#include <glad/glad.h> // include glad to get the required OpenGL headers
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "filesystem.hpp"

/**
 * Encapsulates the shader program setup and checks for bugs on compiling.
 */
class Shader
{
public:
	// the program ID
	unsigned int ID;
	// constructor reads and builds the shader
	Shader(const char* vertexPath, const char* fragmentPath);
};

