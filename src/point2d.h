#ifndef POINT2D_H
#define POINT2D_H

//template<class T>
class Point2D {
public:
    Point2D(int x, int y);
    //virtual ~Point2D();
    int GetX() const;
    int GetY() const;
    void SetX(const int& x);
    void SetY(const int& y);
    int Sum() const;
private:
    int x;
    int y;
};

#endif