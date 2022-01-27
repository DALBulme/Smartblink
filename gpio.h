#ifndef GPIO_H
#define GPIO_H

#include <QObject>

const QList<int> LEDS = {18, 23, 24, 25};
const int LFLAGS = 0;                                   //Konstanten für verwenden der LEDS definieren
const int CHIP = 0;

class Gpio : public QObject
{
    Q_OBJECT
public:
    explicit Gpio(QObject *parent = nullptr);
    ~Gpio();                                    // Destructor
    void set(int pin,bool value);               // Funktion für Blinklicht
    void set(unsigned int pattern);             // Funktion für Lauflicht

signals:

public slots:

private:
    int m_handle;       //membervariable m_handle
};

#endif // GPIO_H
