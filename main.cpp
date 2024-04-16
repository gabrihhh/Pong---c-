#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Transformable.hpp>

struct Body {
    int x;
    int y;
    int w;
    int h;
};

int main()
{
    // Criar a janela principal
    sf::RenderWindow window(sf::VideoMode(800, 500), "SFML window");
    // Inicialização
    // Aqui você pode inicializar seus objetos, carregar texturas, sons, etc
    Body player1 = {30,10,20,100};
    Body player2 = {720,10,20,100};
    Body ball = {390,220,20,20};

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
            
            if(event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Right) {
                    player1.x = player1.x + 5;
                };
                if (event.key.code == sf::Keyboard::Left) {
                    player1.x = player1.x - 5;
                };
            };
        }

        // Atualizar o estado do jogo
        rectanglePlayer1.setPosition(player1.x,player1.y);

        // Aqui você pode adicionar a lógica para movimentar objetos, detectar colisões, etc.

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
