#include "RoomLoader.hpp"
#include <fstream>
#include <iostream>

std::unordered_map<std::string, Room> RoomLoader::rooms_;

void RoomLoader::LoadRoomFromFile(const std::string& roomId, const std::string& filepath)
{
	// Room is already loaded in. Skip this room.
	if(rooms_.find(roomId) != rooms_.end())
		return;

	std::ifstream file(filepath);
	// Couldn't find the room file. Error and continue.
	if(!file)
	{
		std::cerr << "Failed to open room file: " << filepath << std::endl;
		return;
	}

	nlohmann::json j;
	file >> j;

	Room room = ParseRoomFromJson(j);
	rooms_[roomId] = room;
}

Room* RoomLoader::GetRoom(const std::string& roomId)
{
	auto iterator = rooms_.find(roomId);
	if(iterator != rooms_.end())
		return &iterator->second;

	return nullptr;
}

Room RoomLoader::ParseRoomFromJson(const nlohmann::json& j)
{
	Room room;

	// Load general room data
	room.name_ = j.at("name").get<std::string>();
	room.dialogue_ = j.at("dialogue").get<std::string>();

	// Load connected rooms
	nlohmann::json connectedRooms = j.at("connected_rooms");
	for (auto& roomPair : connectedRooms.items())
	{
		room.connectedRooms_[roomPair.key()] = roomPair.value();	
	}

	// Load item data if there is an item to be found in the current room
	if(j.contains("item"))
	{
		room.item_.name_ = j.at("item").at("name").get<std::string>();
		room.item_.strengthPoints_ = j.at("item").at("strength_points").get<int>();
	}

	// Load enemy data if there is an enemy in the current room
	if(j.contains("enemy"))
	{
		room.enemy_.name_ = j.at("enemy").at("name").get<std::string>();
		room.enemy_.health_ = j.at("enemy").at("health").get<int>();
		room.enemy_.strength_ = j.at("enemy").at("strength").get<int>();
	}

	return room;
}
