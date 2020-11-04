#include "GameOverState.h"
#include "GamePlayState.h"

GLint GameOverState::Init()
{
    // Initialize Background
    auto shader = GetShaderManager().getShader(0);
    auto texture = GetTextureManager().getTexture(0);
    auto model = GetModelManager().getModel(0);
    m_backGround = std::make_shared<Sprite2D>(model, shader, texture);
    m_backGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
    m_backGround->SetSize(screenWidth, screenHeight);

    // Initialize Buttons
    std::shared_ptr<GameButton> button;
    texture = GetTextureManager().getTexture(5);
    button = std::make_shared<GameButton>(model, shader, texture);
    button->Set2DPosition(screenWidth / 2, 400);
    button->SetSize(200, 50);
    button->SetOnClick([]() 
    {
            GetMainContext().popState();
            auto state = new GamePlayState(20);
            state->Init();
            GetMainContext().changeState(state);
    });
    m_listButtons.push_back(button);

    texture = GetTextureManager().getTexture(4);
    button = std::make_shared<GameButton>(model, shader, texture);
    button->Set2DPosition(screenWidth / 2, 500);
    button->SetSize(200, 50);
    button->SetOnClick([]() {
        exit(0);
        });
    m_listButtons.push_back(button);

    auto font = GetFontManager().getFont(0);
    shader = GetShaderManager().getShader(1);
    m_displayScore = std::make_shared<Text>(shader, font, "Your Score:" + std::to_string(m_score) , TEXT_COLOR::CYAN, 1.5);
    m_displayScore->Set2DPosition(Vector2(screenWidth/2 - 140, screenHeight/2 - 40));

    return 0;
}

void GameOverState::Draw()
{
    m_backGround->Draw();
    for (auto& btn : m_listButtons)
        btn->Draw();
    m_displayScore->Draw();
}

void GameOverState::Update(GLfloat deltatime)
{
    m_backGround->Update(deltatime);
    for (auto& btn : m_listButtons)
        btn->Update(deltatime);
}

void GameOverState::Key(unsigned char key, bool bbIsPressed){}

void GameOverState::Mouse(GLint x, GLint y, bool bbIsPressed)
{
    for (auto it : m_listButtons)
    {
        (it)->HandleTouchEvents(x, y, bbIsPressed);
        if ((it)->IsHandle()) break;
    }
}
