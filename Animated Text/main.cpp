#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <ctime>


class AnimatedText {
private:
    std::string text;
    size_t duration;
public:
    AnimatedText(const std::string& _text, const int& _duration): text(_text), duration(_duration) { }

    std::string get_Text(size_t current_Time) {
        size_t time = current_Time % (duration + 1);
        std::string Text = text.substr(0, text.length() * time / duration);

        return Text;
    }
};

int main() {
    AnimatedText Animated = AnimatedText("Hello, world!", 12);
    sf::RenderWindow window(sf::VideoMode(400, 200), "SFML works!");

    sf::Text text;
    sf::Font font;

    font.loadFromFile("Arial.ttf");
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Yellow);   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float running_time = std::clock();
        text.setPosition(0, 0);
        text.setString(Animated.get_Text(running_time / 1000 + 1));

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}
