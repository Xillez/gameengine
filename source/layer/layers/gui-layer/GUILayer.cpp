#include "_sdl.hpp"
#include <GL/glew.h>
#include <AL/al.h>
#include <AL/alc.h>
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

#include "Logging.hpp"
#include "GUILayer.hpp"

GUILayer::GUILayer(SDL_Window* window, SDL_GLContext& glContext) : Layer("GUILayer")
{
    this->window = window;
    this->glContext = glContext;
}

void GUILayer::Init()
{
    // Initialize ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable | ImGuiConfigFlags_DockingEnable;

    // Setup ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(this->window, this->glContext);
    ImGui_ImplOpenGL3_Init("#version 150"); // Replace 'glsl_version' with your OpenGL shader version, e.g., "#version 150"

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Enable alpha blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Enable face culling
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    // Enable multisampling
    glEnable(GL_MULTISAMPLE);

    // Enable debug output
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    //glDebugMessageCallback(MessageCallback, 0);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
}

void GUILayer::Update()
{
    //
}

void GUILayer::Destroy()
{
    // Clean up
    SDL_GL_DeleteContext(this->glContext);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void GUILayer::OnAttach()
{
    //
}

void GUILayer::OnDetach()
{
    //
}

//void Layer::OnEvent(Event& event)
//{
//    //
//}

const std::string& GUILayer::GetName() const
{
    return this->name;
}