#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SFML/Audio.hpp>

#include <vector>

#include "Window.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"

const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;

int main()
{
  TinyOglWindow window(WINDOW_WIDTH, WINDOW_HEIGHT, "TOE - App");

  std::vector<float> verts = {
    // Positions        
    0.0f,  0.5f,  0.0f,  // Top vertex
   -0.5f, -0.5f,  0.0f,  // Bottom-left vertex
    0.5f, -0.5f,  0.0f   // Bottom-right vertex
  };

  VertexArray vertexArray;
  vertexArray.Bind();

  VertexBuffer vertexBuffer;
  vertexBuffer.FillBufferData(verts, GL_STATIC_DRAW);
  vertexBuffer.Bind();
  vertexBuffer.EnableVertexAttribArray(0, 3, GL_FLOAT, false, 0, (void*)0);

  Shader shader(RESOURCES_PATH "basicVert.glsl", RESOURCES_PATH "basicFrag.glsl");

  sf::SoundBuffer buffer;
  if(!buffer.loadFromFile(RESOURCES_PATH "sound.wav"))
	  return -1;

  sf::Sound sound(buffer);
  sound.play();

  while(window.IsOpen())
  {
    window.Clear(GL_COLOR_BUFFER_BIT);

    shader.Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glUseProgram(0);

    window.SwapAndPoll();
  }
  
  return 0;
}

