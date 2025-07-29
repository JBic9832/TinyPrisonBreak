#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SFML/Audio.hpp>

#include <vector>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Window.hpp"
#include "Shader.hpp"
#include "RoomLoader.hpp"
#include "Input.hpp"
#include "Player.hpp"
#include "ResourceManager.hpp"

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

 // VertexArray vertexArray;
 // vertexArray.Bind();

 // VertexBuffer vertexBuffer;
 // vertexBuffer.Bind();
 // vertexBuffer.FillBufferData(verts, GL_STATIC_DRAW);
 // vertexBuffer.EnableVertexAttribArray(0, 3, GL_FLOAT, false, 0, (void*)0);

  Shader shader = ResourceManager::LoadShader(RESOURCES_PATH "basicVert.glsl", RESOURCES_PATH "basicFrag.glsl", "basic");
  sf::SoundBuffer buffer;
  if(!buffer.loadFromFile(RESOURCES_PATH "sound.wav"))
	  return -1;

  sf::Sound sound(buffer);
  sound.play();


  RoomLoader::LoadRoomFromFile("prison_cell", RESOURCES_PATH "rooms/prison_cell.json");
  Room* room = RoomLoader::GetRoom("prison_cell");
  Player player(50, 50, "basic");
  TexturedRect tr("", "basic", 200, 200);

  std::cout << "Room name: " << room->name_ << "\nItem name: " << room->item_.name_ << std::endl;

  glm::mat4 view = glm::mat4(1.0f);
  glm::mat4 proj = glm::ortho(0.0f, (float)window.GetWindowWidth(), (float)window.GetWindowHeight(), 0.0f);

  float deltaTime = 0.0f;
  float lastTime = 0.0f;

  while(window.IsOpen())
  {
	  float currentTime = static_cast<float>(glfwGetTime());
	  deltaTime = currentTime - lastTime;
	  lastTime = currentTime;

	  window.Clear(GL_COLOR_BUFFER_BIT);

	  shader.Bind();
	  player.Update(deltaTime);
	  player.Draw(proj, view);
	  glUseProgram(0);

	  window.SwapAndPoll();
  }

  return 0;
}

