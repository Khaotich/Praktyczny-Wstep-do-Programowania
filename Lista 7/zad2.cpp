#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

const int width = 800;
const int height = 800;
const int r = 200;

int main()
{
    int keyonoff = 1;
    RenderWindow window(VideoMode(width, height), "Lista 7");
    window.setFramerateLimit(60); // limit generowanych klatek    

    CircleShape shape(r);
    shape.setFillColor(Color::Green);

    // Aby wycentrowa� ko�o w oknie nale�y lewy g�rny punkt ko�a przemie�ci� o 200 jednostek na obu osiach

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