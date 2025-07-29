#include "TexturedRect.hpp"
#include "Shader.hpp"
#include <string>
#include <glm/glm.hpp>

class Player
{
public:
	Player();
	Player(float posX, float posY, const std::string& shader);
	void Draw(glm::mat4 proj, glm::mat4 view);
	void Update(float deltaTime);

private:
	TexturedRect texturedRect_;
	Shader shader_;
	float xPos_, yPos_;
	float speed_ = 1000.0f;
};

