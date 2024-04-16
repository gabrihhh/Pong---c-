#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Transformable.hpp>

struct Body {
    int x;
    int y;
    int w;
    int h;
};

struct Moviment {
    bool up;
    bool down;
    bool left;
    bool right;
};

int main()
{
    // Criar a janela principal
    sf::RenderWindow window(sf::VideoMode(800, 500), "SFML window");
    // Inicialização
    // Aqui você pode inicializar seus objetos, carregar texturas, sons, etc
    Body player1 = {30,10,20,100};
    Moviment movimentPlayer1 = {false,false,false,false};

    Body player2 = {720,10,20,100};
    Moviment movimentPlayer2 = {false,false,false,false};

    Body ball = {390,220,20,20};
    Moviment movimentBall = {false,false,false,false};

    sf::RectangleShape rectanglePlayer1;
    rectanglePlayer1.setSize(sf::Vector2f(player1.w, player1.h));
    rectanglePlayer1.setFillColor(sf::Color::Black);
    rectanglePlayer1.setPosition(player1.x,player1.y);

    sf::RectangleShape rectanglePlayer2;
    rectanglePlayer2.setSize(sf::Vector2f(player2.w, player2.h));
    rectanglePlayer2.setFillColor(sf::Color::Black);
    rectanglePlayer2.setPosition(player2.x,player2.y);


    sf::RectangleShape rectangleBall;
    rectangleBall.setSize(sf::Vector2f(ball.w, ball.h));
    rectangleBall.setFillColor(sf::Color::Black);
    rectangleBall.setPosition(ball.x,ball.y);



    // Loop principal do jogo
    while (window.isOpen())
    {
        // Processar eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            //Eventos de keyDown
            if(event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Up) {
                    movimentPlayer1.up = true;
                };
                if (event.key.code == sf::Keyboard::Down) {
                    movimentPlayer1.down = true;
                };
            };
            //Eventos de keyUP
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    movimentPlayer1.up = false;
                };
                if (event.key.code == sf::Keyboard::Down)
                {
                    movimentPlayer1.down = false;
                };
            };
        }

        // Atualizar o estado do jogo
        if(movimentPlayer1.up){
            player1.y--;
        };
        if(movimentPlayer1.down){
            player1.y++;
        };

        // Aqui você pode adicionar a lógica para movimentar objetos, detectar colisões, etc.

        if(player1.y<0){
            player1.y = 0;
        };
        if(player1.y+player1.h>500){
            player1.y = 500-player1.h;
        };

        //Atualização das posições
        rectanglePlayer1.setPosition(player1.x,player1.y);


        // Renderização
        window.clear(sf::Color::White);
        
        // Desenhar coisas na tela
        window.draw(rectanglePlayer1);
        window.draw(rectanglePlayer2);
        window.draw(rectangleBall);
        // Aqui você pode desenhar seus objetos, textos, etc.
        
        window.display();
    }

    return 0;
}
