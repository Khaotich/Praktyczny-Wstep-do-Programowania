#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    int keyonoff = 1;
    RenderWindow window(VideoMode(400, 400), "Lista 7");
    window.setFramerateLimit(60); // limit generowanych klatek
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
            if (event.type == Event::KeyPressed) keyonoff = 1 - keyonoff;
        }
        
        window.clear(Color::Black);
        if (keyonoff)
        {
            window.draw(shape);
        }
        window.display();
    }
}