#include <iostream>

Class GraphicsObject {
private:
    string stroke;
    int stroke_width;
    string fill;

public:
    void set_stroke(string s){
        stroke = s;
    }
    void set_stroke_width(int sw){
        stroke_width = sw;
    }
    void set_fill(string f){
        fill = f;
    }
}

Class rectanlge : public  GraphicsObject {
private:
    int width,height,x,y,rx,ry;

public:
    rectangle (int w,int h, int x, int y, int rx, int ry, string stroke,int stroke_width,steing fill){
        width(w);height(h);x(x);y(y);rx(rx);ry(ry);
        set_stroke(stroke);set_stroke_width(stroke_width);set_fill(fill);
    }

}

Class circle : public GraphicsObject {
private:
    int r,cx,cy;

public:
    circle (int r, int cx, int cy, string stroke,int stroke_width,steing fill){
        r(r);cx(cx);cy(cy);
        set_stroke(stroke);set_stroke_width(stroke_width);set_fill(fill);
    }
}

