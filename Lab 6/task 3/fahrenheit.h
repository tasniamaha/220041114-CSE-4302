#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H
class celsius;
class kelvin;
class fahrenheit{
    private:
    float fahrenheit_temp;
    public:
    fahrenheit (float temp);
    void assign(float temp);
    void display();
    operator celsius() const;
    operator kelvin() const;
};
#endif