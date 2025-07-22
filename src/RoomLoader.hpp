#pragma once

#include <string>
#include <unordered_map>
#include <json.hpp>

#include "Room.hpp"

class RoomLoader
{
public:
	static void GetRoomFiles();
	static void LoadRoomFromFile(const std::string& roomId, const std::string& filepath);

	static Room* GetRoom(const std::string& roomId);

	static void ClearAllRooms();

private:
	static std::unordered_map<std::string, Room> rooms_;

	RoomLoader() = delete;
	
	static Room ParseRoomFromJson(const nlohmann::json& j);
};
