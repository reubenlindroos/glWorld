#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
//internal
#include "Shader.h"
#include "filesystem.hpp"
#include "IOTools.h"
namespace fs = ghc::filesystem;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //window resizing

	//Vertices. These are what describe the object in 3d space. 
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};
	std::string vShaderPath = fs::path(io::getProjectSrcDir()) / fs::path("src/part2/vertexShader.glsl");
	std::string fShaderPath = fs::path(io::getProjectSrcDir()) / fs::path("src/part2/fragmentShader.glsl");
	Shader * shaderProgram = new Shader(vShaderPath.c_str(), fShaderPath.c_str());

	//creating GL Objects
	unsigned int VAO; //object that groups all the VBOs
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO); //needs to be bound BEFORE the VBO is loaded, just like the VBO itself

	unsigned int VBO; 
	glGenBuffers(1, &VBO); //generate the buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO); //bind the newly created buffer object to the GL_ARRAY_BUFFER target
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //copy the data into the buffer's memory

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
		(void*)0);
	glEnableVertexAttribArray(0);

	

	// render loop
	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		// rendering commands here
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		//make gl use this program
		glUseProgram(shaderProgram->ID);
		//bind the vertex array object (need to do this every render cycle)
		glBindVertexArray(VAO);
		//draw 
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// check and call events and swap the buffers
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate(); //clean up
	return 0;
}

