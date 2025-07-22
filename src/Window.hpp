#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class TinyOglWindow
{
public:
  TinyOglWindow(const int width, const int height, const std::string& name);
  ~TinyOglWindow();
  bool IsOpen() const;
  GLFWwindow* GetWindowHandle() const;
  int GetWindowWidth() const;
  int GetWindowHeight() const;
  void Clear(unsigned int mask) const;
  void SwapAndPoll() const;

private:
  void CreateWindow();
  void InitGlad();
  void ConfigureWindow();

private:
  GLFWwindow*  window_;
  int  width_, height_;
  std::string appName_;
};
