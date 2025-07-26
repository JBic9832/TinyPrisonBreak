#include "Transform.hpp"
#include <string>
#include <glm/glm.hpp>

class Player
{
public:
	Player();
	Player(int posX, int posY);
	void Draw() const;

private:
	Transform transform_;
	std::string textureName_;

};

