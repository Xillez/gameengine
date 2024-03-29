#include <stdio.h>
#include <iostream>

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alc.h>
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

#include "./utils/List.hpp"
#include "./ecs/Scene.hpp"
#include "./ecs/Entity.hpp"
#include "./ecs/Component.hpp"
#include "./config/Config.hpp"
#include "./utils/Logging.hpp"
#include "./asset/Asset.hpp"
#include "./asset/model/ModelAsset.hpp"

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

bool initSDL()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    LogBuildInfo();

    // Failed to initialize SDL.
    if (!initSDL())
        return -1;

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4); // Set major version (e.g., 3)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6); // Set minor version (e.g., 3 for OpenGL 3.3)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); // Use core profile

    // Create a GLFW window
    SDL_Window* window = SDL_CreateWindow("SkyForge Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        std::cerr << "Could not create GL context. Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Initialize ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(window, glContext);
    ImGui_ImplOpenGL3_Init("#version 150"); // Replace 'glsl_version' with your OpenGL shader version, e.g., "#version 150"


    ModelAsset asset = ModelAsset("../assets/e-51dm-on-the-deck/source/e51dm deck.gltf");

    Scene scene;

    for (int i = 0; i < 1; i++)
    {
        Entity* entity = new Entity();
        entity->CreateComponent<TestComponent>();
        scene.Add(entity);
        for (int j = 0; j < 1; j++)
        {
            Entity* childEntity = new Entity();
            childEntity->CreateComponent<TestComponent>();
            entity->Add(childEntity);
        }
    }

    scene.Start();

    // Window quit flag.
    bool quit = false;    
    SDL_Event event;
    // Game/render loop
    while (!quit) {
        // Poll for and process events
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            // TODO: Handle other events like window close, keyboard, mouse, etc.
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                // TODO: Handle other events here
            }
        }

        scene.Update();

        std::cout << asset.model.scene->mNumAnimations << std::endl;
        std::cout << asset.model.scene->mNumCameras << std::endl;
        std::cout << asset.model.scene->mNumLights << std::endl;
        std::cout << asset.model.scene->mNumMaterials << std::endl;
        std::cout << asset.model.scene->mNumMeshes << std::endl;
        std::cout << asset.model.scene->mNumTextures << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;

        // Start the ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(window);
        ImGui::NewFrame();

        // Your ImGui UI code goes here
        // For example, ImGui::ShowDemoWindow();
        ImGui::ShowDemoWindow();

        // Render ImGui
        ImGui::Render();

        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Game rendering GOES HERE

        // Render ImGui over your game
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap front and back buffers
        SDL_GL_SwapWindow(window);
    }

    // Clean up
    scene.Destroy();
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}