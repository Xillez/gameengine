#include "./utils/List.hpp"
#include "./ecs/Scene.hpp"
#include "./ecs/Entity.hpp"
#include "./ecs/Component.hpp"
#include "./config/Config.hpp"
#include "./utils/Logging.hpp"

#include <stdio.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SDL2/SDL.h>

class TestComponent : public Component
{
public:
	TestComponent() : Component()
	{
		//
	};
};

class TestComponent2 : public Component
{
public:
	TestComponent2() : Component()
	{
		//
	};
};

void LogBuildInfo()
{
	#if defined(PROJECT_NAME)
		LOG_INFO(PROJECT_NAME);
	#endif
	#if defined(VERSION)
		LOG_INFO(VERSION);
	#endif
	#if defined(VERSION_NAME)
		LOG_INFO(VERSION_NAME);
	#endif
	#if defined(OS_NAME)
		LOG_INFO(OS_NAME)
	#endif
	#if LOGGING
		LOG_INFO("Logging enabled!")
	#endif
		#if DEBUG
		LOG_INFO("DEBUG BUILD!")
	#else
		LOG_INFO("RELEASE BUILD!")
	#endif
}

int main(int argc, char const *argv[])
{
	LogBuildInfo();

	// Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        SDL_Quit();
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello, GLFW!", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        SDL_Quit();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        SDL_Quit();
        return -1;
    }

	Scene scene;

	for (int i = 0; i < 5; i++)
	{
		Entity* entity = new Entity();
		entity->CreateComponent<TestComponent>();
		scene.Add(entity);
	}

	scene.Start();

	// Game/render loop
    while (!glfwWindowShouldClose(window)) {
		scene.Update();

        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

	// Clean up
	scene.Destroy();
    glfwDestroyWindow(window);
    glfwTerminate();
    SDL_Quit();
	
	return 0;
}