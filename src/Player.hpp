#include "Transform.hpp"
#include <string>

class Player
{
public:
	Player();
	Player(int posX, int posY);

private:
	Transform transform_;
	std::string textureName_;
};

