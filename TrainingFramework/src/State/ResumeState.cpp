#include "ResumeState.h"
#include "IntroState.h"
#include "GamePlayState.h"

GLint ResumeState::Init()
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
    texture = GetTextureManager().getTexture(7);
    button = std::make_shared<GameButton>(model, shader, texture);
    button->Set2DPosition(screenWidth / 2, 400);
    button->SetSize(200, 50);
    button->SetOnClick([]() {
        GetMainContext().popState();
    });

    m_listButtons.push_back(button);
    texture = GetTextureManager().getTexture(6);
    button = std::make_shared<GameButton>(model, shader, texture);
    button->Set2DPosition(screenWidth / 2, 500);
    button->SetSize(200, 50);
    button->SetOnClick([]() {
        GetMainContext().popState();
        GetMainContext().popState();
        });
    m_listButtons.push_back(button);
    return 0;
}

void ResumeState::Draw()
{
    m_backGround->Draw();
    for (auto& btn : m_listButtons)
        btn->Draw();
}

void ResumeState::Update(GLfloat deltatime)
{
    m_backGround->Update(deltatime);
    for (auto& btn : m_listButtons)
        btn->Update(deltatime);
}

void ResumeState::Key(unsigned char key, bool bbIsPressed)
{
}

void ResumeState::Mouse(GLint x, GLint y, bool bbIsPressed)
{
    for (auto it : m_listButtons)
    {
        (it)->HandleTouchEvents(x, y, bbIsPressed);
        if ((it)->IsHandle()) break;
    }
}
