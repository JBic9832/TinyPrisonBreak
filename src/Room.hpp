#pragma once
#include <string>
#include <vector>

#include "Item.hpp"
#include "Enemy.hpp"

struct Room
{
	Room() {};
	
	std::string                 name_;
	std::vector<std::string> connectedRooms_;
	std::string                 dialogue_;
	Item                        item_;
	Enemy                       enemy_;
};
