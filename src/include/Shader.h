#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
public:
	unsigned int ID;

	void use();
	Shader(const char* vertexPath, const char* fragmentPath);
	void setInt(std::string, int value);
	void setBool(std::string, bool value);
	void setFloat(std::string, float value);

private:
	void checkCompileErrors(unsigned int shader, std::string type);
};
#endif