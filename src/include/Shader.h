#ifndef SHADER_H
#define SHADER_H

class Shader {
public:
	unsigned int ID;

	void use();
	Shader(const char* vertexPath, const char* fragmentPath);
	/*void setFloat(const char* name, float* value);
	void setInt(const char* name, int* value);
	void setBool(const char* name, bool* value);*/
};
#endif