#include "gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_leds = new Gpio(this);
    m_state = 0;
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle); // verbindung Timer -> Gui Label
 }

void Gui::on_speedSlider_valueChanged(int value)
{
    m_timer->start(1000/value);
}

void Gui::on_blinkButton_clicked()              // Funktion falls BlinkButton gedrückt wurde
{
    m_lauflicht = 1;
}

void Gui::on_lauflichtButton_clicked()          // Funktion falls LauflichtButton gedrückt wurde
{
    m_lauflicht = 0;
    count = 1;
}

void Gui::toggle()
{
    m_state = !m_state;

    if(m_lauflicht == 1)
    {
        if(m_state == 1)
        {
            count = 15;
        }else {
            count = 0;
        }
        m_leds->set(count);
    }

    if(m_lauflicht == 0)
    {
        m_leds->set(count);
            if(count < 8)
            {
                count = count * 2;
            }
            else {
                count = 1;
            }
    }
}
