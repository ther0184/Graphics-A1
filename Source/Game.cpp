#include "Game.h"
#include "Constants.h"
#include "Timer.h"

namespace GameDev2D
{
	Game::Game() :
        m_Velocity(0.0f, 0.0f),
        m_Displacement(0.0f, 0.0f),
        m_Origin(0,0),
        m_Target(0,0),
        m_Elapsed(0.0),
        m_Duration(0.0)
	{
        //Circle Object Features
        m_Circle = new Polygon();
        m_Circle->MakeCircle(15.0f, true);
        m_Circle->SetColor(Color::AppleGreenColor());
        m_Circle->SetAnchor(Vector2(0.5f, 0.5f));
        m_Circle->SetPosition(Vector2(100.0f, 50.0f));
        
        //Font
        LoadFont("heavy_data_150");
        m_Label = new SpriteFont("heavy_data_150");
        m_Label->SetColor(Color::SafetyYellowColor());
        m_Label->SetAnchor(Vector2(0.5f, 0.5f));
        m_Label->SetPosition(Vector2(490.0f, 650.0f));
        
        //Time and Animation Features
        m_ElapsedTime = 0.0;
        m_Displacement = Vector2(GetMousePosition());
        m_Velocity = m_Displacement / TRAVEL_DURATION;
	}

	Game::~Game()
	{
        if (m_Label != nullptr)
        {
            delete m_Label;
            m_Label = nullptr;
        }

        if (m_Circle != nullptr)
        {
            delete m_Circle;
            m_Circle = nullptr;
        }
        UnloadFont("heavy_data_150");
	}

	void Game::Update(double delta)
	{
        m_ElapsedTime += delta;
        m_Label->SetText(std::to_string(m_ElapsedTime));

        Vector2 displacement = m_Velocity * delta;
        Vector2 position = m_Circle->GetPosition();
        position += displacement;
        m_Circle->SetPosition(position);

        if (m_Elapsed < m_Duration)
        {
            m_Elapsed += delta;
            if (m_Elapsed > m_Duration)
            {
                m_Elapsed = m_Duration;
            }
            m_pct = m_Elapsed / m_Duration;
            Vector2 Position = m_Origin + m_Displacement * m_pct;
            m_Circle->SetPosition(Position);
        }
	}

	void Game::Draw()
	{
        m_Label->Draw();
        m_Circle->Draw();
	}

	void Game::HandleLeftMouseClick(float aMouseX, float aMouseY)
	{
        m_Origin = m_Circle->GetPosition();
        m_Target = GetMousePosition();

        m_Displacement = m_Target - m_Origin;
        float distance = m_Displacement.Length();
        m_Duration = distance / 200.0; //200 is speed
        m_Elapsed = 0;
        //Add a thing here?

     
	}

	void Game::HandleRightMouseClick(float aMouseX, float aMouseY)
	{

	}

	void Game::HandleMouseMove(float aMouseX, float aMouseY, float aPreviousX, float aPreviousY)
	{
		
	}

	void Game::HandleKeyPress(Keyboard::Key aKey)
	{

	}

	void Game::HandleKeyReleased(Keyboard::Key key)
	{

	}
}