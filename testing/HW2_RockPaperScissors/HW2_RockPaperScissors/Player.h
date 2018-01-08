#pragma once


class Player
{

public:
	Player();  // Constructor, default
	Player(std::string name, char type);  // Constructor, parameterized
	virtual ~Player();  // Destructor
	std::string getName();  // Returns player's name
	char getType();  // Returns character's type

	virtual void print() = 0;  // pure virtual (abstract) method

	// Operators - pure virtual (abstract) method
	virtual bool operator>(Player* other) = 0;  // win win!
	virtual bool operator<(Player* other) = 0;  // defeat!
	virtual bool operator==(Player* other) = 0;  // ow!

	//friend std::ostream& operator<<(std::ostream& os, const Player* player)
	//{
	//	os << player->print();
	//	return os;
	//}*/

protected:
	std::string name;  // name of player
	char type;  // rock, paper, or scissor?

};

