#ifndef CELSIUS_H
#define CELSIUS_H
class kelvin;
class fahrenheit;
class celsius{
    private:
    float celsius_temp;
    public:
    celsius (float temp);
    void assign(float temp);
    
    void display();
    operator kelvin() const;
    operator fahrenheit() const;
};
#endif