#include <iostream>
#include <fstream>
#include <algorithm>

struct Player {
    std::string name;
    int wins;

    Player(const std::string& n, int w) : name(n), wins(w) {}
};

void savePlayerData(Player* players[], int size) {
    std::ofstream outFile("player_data.txt");

    if (outFile.is_open()) {
        for (int i = 0; i < size; ++i) {
            outFile << players[i]->name << " " << players[i]->wins << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void loadPlayerData(Player* players[], int& size) {
    std::ifstream inFile("player_data.txt");

    size = 0;

    if (inFile.is_open()) {
        std::string name;
        int wins;

        while (inFile >> name >> wins && size < 100) {
            players[size++] = new Player(name, wins);
        }

        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading. Returning empty player list." << std::endl;
    }
}

void inputPlayerData(Player* players[], int& size) {
    std::string name;
    std::cout << "Enter player name: ";
    std::cin >> name;

    std::ifstream playerFile(name + ".txt");
    if (playerFile.is_open()) {
        int wins;
        if (playerFile >> wins && size < 100) {
            players[size++] = new Player(name, wins);
            std::cout << "Player data loaded successfully." << std::endl;
        } else {
            std::cerr << "Failed to read player data. Using default wins: 0." << std::endl;
            players[size++] = new Player(name, 0);
        }
        playerFile.close();
    } else {
        std::cerr << "Unable to open player file. Using default wins: 0." << std::endl;
        players[size++] = new Player(name, 0);
    }
}

void displayTopPlayers(Player* players[], int size) {
    Player* sortedPlayers[100];

    std::copy(players, players + size, sortedPlayers);

    std::sort(sortedPlayers, sortedPlayers + size, [](const Player* a, const Player* b) {
        return a->wins > b->wins;
    });

    std::cout << "Top Players:" << std::endl;
    int rank = 1;
    for (int i = 0; i < size && rank <= 3; ++i) {
        std::cout << rank++ << ". " << sortedPlayers[i]->name << " - Wins: " << sortedPlayers[i]->wins << std::endl;
    }
}

int main() {
    Player* players[100];
    int size = 0;

    loadPlayerData(players, size);

    inputPlayerData(players, size);

    savePlayerData(players, size);

    displayTopPlayers(players, size);

    // Clean up allocated memory
    for (int i = 0; i < size; ++i) {
        delete players[i];
    }

    return 0;
}

