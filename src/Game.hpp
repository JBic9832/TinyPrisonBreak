#include "Player.hpp"
#include "RoomLoader.hpp"

class Game
{
private:
	Game() {}

public:
	Game(const Game&)            = delete;
	Game& operator=(const Game&) = delete;

public:
	static Game& GetInstance()
	{
		static Game instance;
		return instance;
	}

	void Start();

private:
	Player player_;
};
