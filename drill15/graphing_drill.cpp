/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double slope(double x) { return x/2; }

double square(double x) { return x*x; }

double sloping_cos(double x) { return cos(x) + slope(x); }

int main(){
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;

    int x_point = 100;
    int y_point = 100;
    int origin = 300;
    int axis_length = 400;
    int notch = 20;
    int min_range = -10;
    int max_range = 11;
    int scale = 20;
    int points = 400;

    Point originate{origin, origin};

    Simple_window win {Point{y_point,y_point}, xmax, ymax, "Function graphs"};

    Axis x_axis (Axis::Orientation::x, Point{100,origin},axis_length,axis_length/notch, "1 == 20 pixels");
    Axis y_axis (Axis::Orientation::y, Point{origin,500},axis_length,axis_length/notch, "1 == 20 pixels");

    x_axis.set_color(Color::red);
    y_axis.set_color(Color::red);

    Function first_function(one, min_range, max_range, originate, points, scale, scale);

    Function slope_function(slope, min_range, max_range, originate, points, scale, scale);

    Function square_function(square, min_range, max_range, originate, points, scale, scale);

    Function cosine_function(cos, min_range, max_range, originate, points, scale, scale);
    cosine_function.set_color(Color::blue);

    Function sloping_cosine_function(sloping_cos, min_range, max_range, originate, points, scale, scale);

    int pos = min_range;

    Text slope_label(Point(abs(originate.x + (scale * pos)), originate.y - ((slope(pos) + 1) * scale)), "x/2");

    win.attach(x_axis);
    win.attach(y_axis);
    win.attach(first_function);
    win.attach(slope_function);
    win.attach(slope_label);
    win.attach(square_function);
    win.attach(cosine_function);
    win.attach(sloping_cosine_function);

    win.wait_for_button();

}
