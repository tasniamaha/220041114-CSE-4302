#ifndef KELVIN_H
#define KELVIN_H
class celsius;
class fahrenheit;
class kelvin{
    private:
    float kelvin_temp;
    public:
    kelvin (float temp);
    void assign(float temp);
    void display();
    operator celsius() const;
    operator fahrenheit() const;
};
#endif