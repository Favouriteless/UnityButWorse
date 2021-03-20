#include "Shader.h"
#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


void Shader::use()
{
	glUseProgram(Shader::ID);
}

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	// Output strings
	std::string vShaderSource;
	std::string fShaderSource;

	// Input file streams
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	// Ensure file streams can throw exceptions
	vShaderFile.exceptions(std::fstream::failbit | std::fstream::badbit);
	fShaderFile.exceptions(std::fstream::failbit | std::fstream::badbit);

	// READ VERTEX SHADER
	try
	{
		vShaderFile.open(vertexPath);

		// Copy file to string stream
		std::stringstream vShaderStream;
		vShaderStream << vShaderFile.rdbuf();

		vShaderFile.close();

		vShaderSource = vShaderStream.str();
	}
	catch(std::ifstream::failure& e)
	{
		std::cout << "VERTEX SHADER COULD NOT BE READ" << std::endl;
	}

	// READ FRAGMENT SHADER
	try
	{
		fShaderFile.open(vertexPath);

		// Copy file to string stream
		std::stringstream fShaderStream;
		fShaderStream << fShaderFile.rdbuf();

		fShaderFile.close();

		fShaderSource = fShaderStream.str();
	}
	catch (std::ifstream::failure& e)
	{
		std::cout << "FRAGMENT SHADER COULD NOT BE READ" << std::endl;
	}

	// Get file contents as c strings
	const char* vShaderString = vShaderSource.c_str();
	const char* fShaderString = fShaderSource.c_str();

	// Shader IDs
	unsigned int vShader, fShader;

	// Compile vertex shader
	vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vShaderString, NULL);
	glCompileShader(vShader);

	// Compile fragment shader
	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &fShaderString, NULL);
	glCompileShader(fShader);

	// Create shader program
	ID = glCreateProgram();
	glAttachShader(ID, vShader);
	glAttachShader(ID, fShader);
	glLinkProgram(ID);

	glDeleteShader(vShader);
	glDeleteShader(fShader);
}