#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Player {
    std::string name;
    int wins;

    Player(const std::string& n, int w) : name(n), wins(w) {}
};

void savePlayerData(const std::vector<Player>& players) {
    std::ofstream outFile("player_data.txt");

    if (outFile.is_open()) {
        for (const Player& player : players) {
            outFile << player.name << " " << player.wins << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

std::vector<Player> loadPlayerData() {
    std::vector<Player> players;
    std::ifstream inFile("player_data.txt");

    if (inFile.is_open()) {
        std::string name;
        int wins;

        while (inFile >> name >> wins) {
            players.emplace_back(name, wins);
        }

        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading. Returning empty player list." << std::endl;
    }

    return players;
}

void inputPlayerData(std::vector<Player>& players) {
    std::string name;
    std::cout << "Enter player name: ";
    std::cin >> name;

    // Open a file with the player's name
    std::ifstream playerFile(name + ".txt");
    if (playerFile.is_open()) {
        int wins;
        // Read the second line of the file as the number of wins
        if (playerFile >> wins) {
            players.emplace_back(name, wins);
            std::cout << "Player data loaded successfully." << std::endl;
        } else {
            std::cerr << "Failed to read player data. Using default wins: 0." << std::endl;
            players.emplace_back(name, 0);
        }
        playerFile.close();
    } else {
        std::cerr << "Unable to open player file. Using default wins: 0." << std::endl;
        players.emplace_back(name, 0);
    }
}

void displayTopPlayers(const std::vector<Player>& players) {
    std::vector<Player> sortedPlayers = players;

    std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](const Player& a, const Player& b) {
        return a.wins > b.wins;
    });

    std::cout << "Top Players:" << std::endl;
    int rank = 1;
    for (const Player& player : sortedPlayers) {
        std::cout << rank++ << ". " << player.name << " - Wins: " << player.wins << std::endl;
        if (rank > 3) {
            break; // Display only the top 3 players
        }
    }
}

int main() {
    std::vector<Player> players = loadPlayerData();

    inputPlayerData(players);

    savePlayerData(players);

    displayTopPlayers(players);

    return 0;
}
