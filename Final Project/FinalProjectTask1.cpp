#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Task 1 (DONE)
class PlayerData {
private:
	string firstName;
	string lastName;
	string team;

public:
	PlayerData(string firstName, string lastName, string team)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->team = team;
	}

	string getFirstName()
	{
		return this->firstName;
	}

	string getLastName()
	{
		return this->lastName;
	}

	string getTeam()
	{
		return this->team;
	}
};

vector<string> findPlayersInBothSports(vector<PlayerData> sport1, vector<PlayerData> sport2)
{
	// Time Complexity MUST be O(N + M)

	// 1. This algorithm will take one of the given arrays of PlayerData, and put it into an unordered set. This step gives a time complexity of O(N).
	// The keys for the unordered set are the player's full names.

	// 2. We will then loop over the second sport's player data onto the unordered map to check for any matches, giving a time complexity of O(M).
	// Unordered maps have an average constant-time complexity of O(1) for searches, insertions, and deletions.

	if (sport1.empty() || sport2.empty())
	{
		return vector<string>(); // Return an empty array. There is no player in common if at least one of the arrays is empty
	}

	unordered_set<string> players;
	for (PlayerData playerData : sport1)
	{
		string key = playerData.getFirstName() + " " + playerData.getLastName();
		players.insert(key);
	}

	vector<string> commonPlayers;
	for (PlayerData playerData : sport2)
	{
		string key = playerData.getFirstName() + " " + playerData.getLastName();
		if (players.find(key) != players.end())
		{
			commonPlayers.push_back(key);
		}
	}
	return commonPlayers;
}

int main()
{
	vector<PlayerData> basketballPlayers = {
		PlayerData("Jill", "Huang", "Gators"),
		PlayerData("Janko", "Barton", "Sharks"),
		PlayerData("Wanda", "Vakulskas", "Sharks"),
		PlayerData("Jill", "Moloney", "Gators"),
		PlayerData("Luuk", "Watkins", "Gators")
	};

	vector<PlayerData> footballPlayers = {
		PlayerData("Hanzla", "Radosti", "32ers"),
		PlayerData("Tina", "Watkins", "Barleycorns"),
		PlayerData("Alex", "Patel", "32ers"),
		PlayerData("Jill", "Huang", "Barleycorns"),
		PlayerData("Wanda", "Vakulskas", "Barleycorns")
	};

	vector<string> commonPlayers = findPlayersInBothSports(basketballPlayers, footballPlayers);
	cout << "Task 1:" << endl << "These players play both sports:" << endl;
	for (string name : commonPlayers)
	{
		cout << name << endl;
	}
	cout << endl;
}