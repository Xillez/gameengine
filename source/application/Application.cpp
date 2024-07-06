#include <iostream>
#include <stdio.h>
#include <memory>

#include <GL/glew.h>
#include <AL/al.h>
#include <AL/alc.h>
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

#include "Application.hpp"

#include "List.hpp"
#include "Scene.hpp"
#include "Entity.hpp"
#include "Component.hpp"
#include "Config.hpp"
#include "GUILayer.hpp"
//#include "ModelAsset.hpp"

Application::Application()
{
    // TODO: Needs implementation
}

Application::~Application()
{
    // TODO: Needs implementation
}

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
        Log::Info(PROJECT_NAME);
    #endif
    #if defined(VERSION)
        Log::Info(VERSION);
    #endif
    #if defined(VERSION_NAME)
        Log::Info(VERSION_NAME);
    #endif
    #if defined(OS_NAME)
        Log::Info(OS_NAME);
    #endif
    #if LOGGING
        Log::Info("Logging enabled!");
    #endif
    #if DEBUG
        Log::Debug("DEBUG BUILD!");
    #else
        Log::Info("RELEASE BUILD!");
    #endif
}

int Application::init()
{
    LogBuildInfo();

    // Failed to initialize SDL.
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        auto error = SDL_GetError();
        Log::Error("Failed to initialize SDL: {}", error);
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4); // Set major version (e.g., 3)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6); // Set minor version (e.g., 3 for OpenGL 3.3)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); // Use core profile

    // Create a GLFW window
    this->window = SDL_CreateWindow("SkyForgeEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
    if (this->window == nullptr) {
        Log::Error("Failed to create window: {}", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    this->glContext = SDL_GL_CreateContext(this->window);
    if (!this->glContext) {
        Log::Error("Could not create GL context. Error: {}", SDL_GetError());
        SDL_DestroyWindow(this->window);
        SDL_Quit();
        return 1;
    }

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        Log::Error("Failed to initialize GLEW");
        SDL_GL_DeleteContext(this->glContext);
        SDL_DestroyWindow(this->window);
        SDL_Quit();
        return 1;
    }

    this->guiLayer = std::make_shared<GUILayer>(this->window, this->glContext);
    this->layerStack.pushLayer(this->guiLayer);

    for (auto layer : this->layerStack)
    {
        layer->Init();
    }

    return 0;
}

int Application::run()
{
    //ModelAsset asset = ModelAsset("../assets/e-51dm-on-the-deck/source/e51dm deck.gltf");

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
            // TODO: Handle other events like keyboard, mouse, etc.
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                // TODO: Handle other events here
            }
        }

        scene.Update();

        //std::cout << asset.model.scene->mNumAnimations << std::endl;
        //std::cout << asset.model.scene->mNumCameras << std::endl;
        //std::cout << asset.model.scene->mNumLights << std::endl;
        //std::cout << asset.model.scene->mNumMaterials << std::endl;
        //std::cout << asset.model.scene->mNumMeshes << std::endl;
        //std::cout << asset.model.scene->mNumTextures << std::endl;
        //std::cout << "----------------------------------------------------" << std::endl;

        // Start the ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport());

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

        ImGuiIO& io = ImGui::GetIO(); (void)io;
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            SDL_Window* backup_current_window = SDL_GL_GetCurrentWindow();
            SDL_GLContext backup_current_context = SDL_GL_GetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            SDL_GL_MakeCurrent(backup_current_window, backup_current_context);
        }

        // Swap front and back buffers
        SDL_GL_SwapWindow(this->window);
    }

    // Clean up
    scene.Destroy();

    for (auto layer : this->layerStack)
    {
        layer->Destroy();
    }

    return 0;
}