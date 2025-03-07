#include <iostream>
using namespace std;

class Level {
    string name;
    int difficulty;
public:
    Level(string n, int d) : name(n), difficulty(d) {}
    void display() { cout << name << " (Difficulty: " << difficulty << ")\n"; }
};

class VideoGame {
    string title;
    string genre;
    Level** levels;
    int maxLevels;
    int numLevels = 0;

public:
    VideoGame(string t, string g, int max = 10) : title(t), genre(g), maxLevels(max) {
        levels = new Level*[max];
    }

    void addLevel(string name, int diff) {
        if(numLevels < maxLevels) {
            levels[numLevels++] = new Level(name, diff);
        }
    }

    void display() {
        cout << "Game: " << title << " (" << genre << ")\nLevels:\n";
        for(int i = 0; i < numLevels; i++) {
            levels[i]->display();
        }
    }

    ~VideoGame() {
        for(int i = 0; i < numLevels; i++) {
            delete levels[i];
        }
        delete[] levels;
    }
};

int main() {
    VideoGame game("Space Quest", "RPG");
    game.addLevel("Intro", 1);
    game.addLevel("Boss Fight", 5);
    game.display();
    return 0;
}