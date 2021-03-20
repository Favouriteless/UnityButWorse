#include <iostream>

#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Shader.h>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;
GLFWwindow* window;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInputs(GLFWwindow* window);
void initGLFW();
void initGLAD();

int main()
{
	// INITIALIZATION ---------------------------------------------------------------------

	initGLFW();
	initGLAD();

	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// MESH DATA --------------------------------------------------------------------------

	float vertices[] {
		-0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f,       0.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.0f,      0.0f, 0.0f, 1.0f
	};

	// RENDER INITIALIZATION --------------------------------------------------------------

	Shader shaderProgram("src/shaders/vertex.glsl", "src/shaders/fragment.glsl");
	shaderProgram.use();

	unsigned int VBO, VAO;

	glGenBuffers(1, &VBO);
	glGenBuffers(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// RENDER LOOP ------------------------------------------------------------------------

	while (!glfwWindowShouldClose(window))
	{
		processInputs(window);

		// Rendering stuff
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(54.0f / 255, 57.0f / 255, 63.0f / 255, 1.0f);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void initGLFW()
{
	if (glfwInit())
		std::cout << "GLFW Initialized" << std::endl;
	else
		std::cout << "Failed to initialize GLFW" << std::endl;

	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Unity but worse", NULL, NULL);

	if (window != NULL)
		std::cout << "GLFW Window Created" << std::endl;
	else
		std::cout << "Failed to create window" << std::endl;
	glfwMakeContextCurrent(window);
}

void initGLAD()
{
	if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		std::cout << "Initialized GLAD" << std::endl;
	else
		std::cout << "Failed to initialize glad" << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInputs(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		std::cout << "Exiting GLFW Window" << std::endl;
		glfwSetWindowShouldClose(window, true);
	}
}