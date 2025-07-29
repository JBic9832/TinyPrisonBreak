#include "Transform.hpp"
#include "TexturedRect.hpp"
#include "Shader.hpp"
#include <string>
#include <glm/glm.hpp>

class Player
{
public:
	Player();
	Player(int posX, int posY);
	void Draw(glm::mat4 proj, glm::mat4 view);

private:
	Transform transform_;
	TexturedRect texturedRect_;
	Shader shader_;
	int xPos_, yPos_;
};

