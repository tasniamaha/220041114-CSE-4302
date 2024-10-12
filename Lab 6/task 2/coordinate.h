#ifndef COORDINATE_H
#define COORDINATE_H

class coordinate{
    private:
    double abscissa;
    double ordinate;
    public:
    coordinate (double x,double y) : abscissa(x),ordinate(y){};
    coordinate () : abscissa(0.0),ordinate(0.0){};
    ~coordinate(){};
    void display();
    double operator-(const coordinate& c) const;
    double getDistance()const;

    void move_x(double x);
    void move_y(double y);
    void move(double x,double y);
    bool operator < (const coordinate& other)const;
    bool operator > (const coordinate& other)const;
    bool operator <= (const coordinate& other)const;
    bool operator >= (const coordinate& other)const;
    bool operator == (const coordinate& other)const;
    bool operator != (const coordinate& other)const;
};
#endif