#include "Window.hpp"
#include "GLFW/glfw3.h"
#include "Input.hpp"
#include <GL/gl.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

TinyOglWindow::TinyOglWindow(const int width, const int height, const std::string& name)
  : width_   { width }
  , height_ { height }
  , appName_  { name }
{
  CreateWindow();
  InitGlad();
  ConfigureWindow();
}

TinyOglWindow::~TinyOglWindow()
{
  glfwTerminate();
}

void TinyOglWindow::CreateWindow()
{
  if(!glfwInit())
    std::cerr << "Failed to init glfw" << std::endl;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window_ = glfwCreateWindow(width_, height_, appName_.c_str(), nullptr, nullptr);
  if(!window_) {
    glfwTerminate();
    std::cout << "Failed to create the window. This is very fucked up." << std::endl;
  }

  glfwMakeContextCurrent(window_);
  Input::initialize(window_);
}

void TinyOglWindow::InitGlad()
{
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to init glad" << std::endl;
  }
}

void TinyOglWindow::ConfigureWindow()
{
  glViewport(0, 0, width_, height_);
  glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);

}

bool TinyOglWindow::IsOpen() const
{
  return !glfwWindowShouldClose(window_);
}

GLFWwindow* TinyOglWindow::GetWindowHandle() const
{
  return window_;
}

int TinyOglWindow::GetWindowWidth() const
{
  return width_;
}

int TinyOglWindow::GetWindowHeight() const
{
  return height_;
}

void TinyOglWindow::Clear(unsigned int mask) const
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(mask);
}

void TinyOglWindow::SwapAndPoll() const
{
  glfwSwapBuffers(window_);
  glfwPollEvents();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}
