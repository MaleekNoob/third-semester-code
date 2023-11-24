#include <iostream>
#include <vector>
#include <queue>

// Class representing a node in the game map
class Node {
public:
    enum NodeType {
        Regular,
        PowerUp,
        Obstacle
    };

    Node(NodeType type) : type(type) {}

    NodeType getType() const {
        return type;
    }

private:
    NodeType type;
};

// Class representing the game map
class GameMap {
public:
    GameMap(int width, int height) : width(width), height(height) {
        map.resize(height, std::vector<Node>(width, Node(Node::Regular)));
    }

    void setNode(int x, int y, Node::NodeType type) {
        map[y][x] = Node(type);
    }

    Node::NodeType getNode(int x, int y) const {
        return map[y][x].getType();
    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

private:
    int width;
    int height;
    std::vector<std::vector<Node>> map;
};

// Class representing the race car
class RaceCar {
public:
    RaceCar(int x, int y) : x(x), y(y) {}

    void moveUp() {
        if (y > 0) {
            y--;
        }
    }

    void moveDown(int maxY) {
        if (y < maxY - 1) {
            y++;
        }
    }

    void moveLeft() {
        if (x > 0) {
            x--;
        }
    }

    void moveRight(int maxX) {
        if (x < maxX - 1) {
            x++;
        }
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

private:
    int x;
    int y;
};

int main() {
    // Create a game map
    GameMap gameMap(10, 10);

    // Set nodes in the map
    gameMap.setNode(2, 3, Node::PowerUp);
    gameMap.setNode(5, 7, Node::Obstacle);

    // Create a race car
    RaceCar raceCar(0, 0);

    // Game loop
    bool gameOver = false;
    while (!gameOver) {
        // Draw the game map
        for (int y = 0; y < gameMap.getHeight(); y++) {
            for (int x = 0; x < gameMap.getWidth(); x++) {
                if (x == raceCar.getX() && y == raceCar.getY()) {
                    std::cout << "C"; // Represent race car with 'C'
                } else {
                    switch (gameMap.getNode(x, y)) {
                        case Node::Regular:
                            std::cout << ".";
                            break;
                        case Node::PowerUp:
                            std::cout << "P";
                            break;
                        case Node::Obstacle:
                            std::cout << "O";
                            break;
                    }
                }
            }
            std::cout << std::endl;
        }

        // Get user input for race car movement
        char input;
        std::cin >> input;

        // Move the race car based on user input
        switch (input) {
            case 'w':
                raceCar.moveUp();
                break;
            case 's':
                raceCar.moveDown(gameMap.getHeight());
                break;
            case 'a':
                raceCar.moveLeft();
                break;
            case 'd':
                raceCar.moveRight(gameMap.getWidth());
                break;
            case 'q':
                gameOver = true;
                break;
        }

        // Clear the console
        system("cls");
    }

    return 0;
}
