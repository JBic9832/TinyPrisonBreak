#pragma once
#include <string>
#include <map>

#include "Item.hpp"
#include "Enemy.hpp"

struct Room
{
	Room() {};
	
	std::string                        name_;
	std::string                        dialogue_;
	Item                               item_;
	Enemy                              enemy_;
	std::map<std::string, std::string> connectedRooms_;
};
