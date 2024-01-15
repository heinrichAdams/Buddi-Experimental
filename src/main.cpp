#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

class GameEngine {
public:
    GameEngine() : window(sf::VideoMode(800, 600), "Simple Platformer"), deltaTime(0.0f) {}

    void run() {
        sf::Clock clock;

        while (window.isOpen()) {
            handleEvents();

            deltaTime = clock.restart().asSeconds();

            update();
            draw();
        }
    }

    void addObject(std::unique_ptr<GameObject> object) {
        gameObjects.push_back(std::move(object));
    }

private:
    sf::RenderWindow window;
    std::vector<std::unique_ptr<GameObject>> gameObjects;
    float deltaTime;

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    void update() {
        for (auto& object : gameObjects) {
            object->update(deltaTime);
        }
    }

    void draw() {
        window.clear();

        for (auto& object : gameObjects) {
            object->draw(window);
        }

        window.display();
    }
};

class Player : public GameObject {
public:
    Player(float x, float y) : position(x, y), velocity(0.0f, 0.0f), speed(200.0f) {
        player.setSize(sf::Vector2f(50.0f, 50.0f));
        player.setFillColor(sf::Color::Green);
    }

    void update(float dt) override {
        handleInput();
        applyPhysics(dt);
    }

    void draw(sf::RenderWindow& window) override {
        player.setPosition(position);
        window.draw(player);
    }

private:
    sf::RectangleShape player;
    sf::Vector2f position;
    sf::Vector2f velocity;
    float speed;

    void handleInput() {
        velocity.x = 0.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity.x = -speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocity.x = speed;
        }
    }

    void applyPhysics(float dt) {
        position += velocity * dt;
    }
};

int main() {
    GameEngine engine;

    engine.addObject(std::make_unique<Player>(100.0f, 100.0f));

    engine.run();

    return 0;
}
