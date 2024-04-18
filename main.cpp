#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/VideoMode.hpp>

struct Body {
    float x;
    float y;
    float w;
    float h;
    float v;
    bool up;
    bool down;
    bool left;
    bool right;
};

int main()
{
    // Criar a janela principal
    sf::RenderWindow window(sf::VideoMode(800, 500), "Pong", sf::Style::Titlebar | sf::Style::Close);
    sf::Font font;
    if (!font.loadFromFile("./font/Roboto-Medium.ttf")) {
        return -1;
    }
    // Inicialização

    // Aqui você pode inicializar seus objetos.
    int player1Points = 0;
    int player2Points = 0;
    Body player1 = {720,190,20,100,0.2,false,false,false,false};
    Body player2 = {30,190,20,100,0.2,false,false,false,false};
    Body ball = {390,220,5,5,0.2,false,false,true,false};
    // Aqui você pode inicializar suas texturas e cores.

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

    sf::Text textPoint1;
    textPoint1.setFont(font);
    textPoint1.setCharacterSize(24);
    textPoint1.setFillColor(sf::Color::Black);
    textPoint1.setPosition(200, 10);
    textPoint1.setString(std::to_string(player1Points));

    sf::Text textPoint2;
    textPoint2.setFont(font);
    textPoint2.setCharacterSize(24);
    textPoint2.setFillColor(sf::Color::Black);
    textPoint2.setPosition(600, 10);
    textPoint2.setString(std::to_string(player2Points));


    // Loop principal do jogo
    while (window.isOpen())
    {
        // Processar eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            };

            //================================Eventos de keyUP===========================================
            if (event.type == sf::Event::KeyReleased)
            {
                //Movimentação de keyup do player 1
                if (event.key.code == sf::Keyboard::Up)
                {
                    player1.up = false;
                };
                if (event.key.code == sf::Keyboard::Down)
                {
                    player1.down = false;
                };

                //Movimentação de keyup do player2
                if (event.key.code == sf::Keyboard::W)
                {
                    player2.up = false;
                };
                if (event.key.code == sf::Keyboard::S)
                {
                    player2.down = false;
                };
            };
        }


        //================================Eventos de KeyDown===========================================

        //Movimentação de keydown do player 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player1.up = true;
        };
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player1.down = true;
        };

        //Movimentação de keydown do player 2
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player2.up = true;
        };

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player2.down = true;
        };

        //================================Atualiza o estado do jogo========================================

        if(player1Points > 4 || player2Points > 4){
            window.close();
        };

        //movimentação player1
        if(player1.up){
            player1.y -= player1.v;
        };
        if(player1.down){
            player1.y+=player1.v;
        };

        //movimentação player2
        if(player2.up){
            player2.y -= player2.v;
        };
        if(player2.down){
            player2.y += player2.v;
        };

        //movimentação da bola
        if(ball.up){
          ball.y -= ball.v;
        };
        if(ball.down){
          ball.y += ball.v;
        };
        if(ball.left){
            ball.x -= ball.v;
        };
        if(ball.right){
          ball.x += ball.v  ;
        };

        //================================Colisões e lógica===========================================

        //Colisões player 1
        if(player1.y<0){
            player1.y = 0;
        };
        if(player1.y+player1.h>500){
            player1.y = 500-player1.h;
        };

        //colisões player 2
        if(player2.y<0){
            player2.y = 0;
        };
        if(player2.y+player2.h>500){
            player2.y = 500-player2.h;
        };

        //colisões da bola com o player 1
        if(ball.x+ball.w >= player1.x){
            if((ball.y+(ball.h/2))<(player1.y+(player1.h/3)) && (ball.y+(ball.h/2)) >= player1.y){
                ball.right = false;
                ball.left = true;
                ball.up = true;
                ball.down = false;
            };
            if((ball.y+(ball.h/2)) <= (player1.y+(player1.h/3)*2) && (ball.y+(ball.h/2)) >= (player1.y+(player1.h/3))){
                ball.right = false;
                ball.left = true;
                ball.up = false;
                ball.down = false;
            };
            if((ball.y+(ball.h/2)) <= (player1.y+player1.h) && (ball.y+(ball.h/2)) > (player1.y+(player1.h/3*2))){
                ball.right = false;
                ball.left = true;
                ball.up = false;
                ball.down = true;
            };
        };

        //colisões da bola com o player 2
        if(ball.x <= player2.x+player2.w){
            if((ball.y+(ball.h/2))<(player2.y+(player2.h/3)) && (ball.y+(ball.h/2)) >= player2.y){
                ball.right = true;
                ball.left = false;
                ball.up = true;
                ball.down = false;
            };
            if((ball.y+(ball.h/2)) <= (player2.y+(player2.h/3)*2) && (ball.y+(ball.h/2)) >= (player2.y+(player2.h/3))){
                ball.right = true;
                ball.left = false;
                ball.up = false;
                ball.down = false;
            };
            if((ball.y+(ball.h/2)) <= (player2.y+player2.h) && (ball.y+(ball.h/2)) > (player2.y+(player2.h/3*2))){
                ball.right = true;
                ball.left = false;
                ball.up = false;
                ball.down = true;
            };
        };

        //colisão da bola com o mapa
        if(ball.y<=0){
            ball.up=false;
            ball.down=true;
        }
        if(ball.y+ball.h>=500){
            ball.down=false;
            ball.up=true;
        }

        //lógica
        //ponto player 2
        if(ball.x+ball.w>player1.x + 1){
            player2Points+=1;
            ball = {390,220,5,5,0.2,false,false,false,true};
        };
        //ponto player 1
        if(ball.x<player2.x+player2.w - 1){
            player1Points+=1;
            ball = {390,220,5,5,0.2,false,false,true,false};
        };
        //Atualização das posições
        rectanglePlayer1.setPosition(player1.x,player1.y);
        rectanglePlayer2.setPosition(player2.x,player2.y);
        rectangleBall.setPosition(ball.x,ball.y);
        textPoint1.setString(std::to_string(player1Points));
        textPoint2.setString(std::to_string(player2Points));
        // Renderização
        window.clear(sf::Color::White);
        
        // Desenhar coisas na tela
        window.draw(rectanglePlayer1);
        window.draw(rectanglePlayer2);
        window.draw(rectangleBall);
        window.draw(textPoint1);
        window.draw(textPoint2);

        // Aqui você pode desenhar seus objetos, textos, etc.
        
        window.display();
    }
    return 0;
}

