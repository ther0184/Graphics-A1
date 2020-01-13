#pragma once
namespace GameDev2D
{
    class Timer
    {
    public:
        Timer(double duration);

        void Update(double delta);

        void Start();
        void Stop();

        void Reset();
        void Restart();

        void SetDuration(double duration);

        double GetDuration();
        double GetElapsed();
        double GetRemaining();

        float GetPercentageComplete();
        
        bool IsRunning();
        bool IsDone();

    private:
        double m_Duration;
        double m_Elapsed;
        bool m_IsRunning;
    };
}
