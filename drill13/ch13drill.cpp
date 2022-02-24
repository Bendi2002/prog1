/*
    g++ ch13drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13drill `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main(){
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;
    int xgrid = 100;
    int ygrid = 100;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};
    
    Lines grid;
    for(int x = xgrid; x < xmax; x+=xgrid){
    	grid.add(Point{x,0}, Point{x,ymax});
    }
    for(int y = ygrid; y < ymax; y+=ygrid){
    	grid.add(Point{0,y}, Point{xmax,y});
    }

    win.attach(grid);

    Rectangle rect00 {Point{0,0},100,100};
    Rectangle rect01 {Point{100,100},100,100};
    Rectangle rect02 {Point{200,200},100,100};
    Rectangle rect03 {Point{300,300},100,100};
    Rectangle rect04 {Point{400,400},100,100};
    Rectangle rect05 {Point{500,500},100,100};
    Rectangle rect06 {Point{600,600},100,100};
    Rectangle rect07 {Point{700,700},100,100};

    rect00.set_fill_color(Color::red);
    rect01.set_fill_color(Color::red);
    rect02.set_fill_color(Color::red);
    rect03.set_fill_color(Color::red);
    rect04.set_fill_color(Color::red);
    rect05.set_fill_color(Color::red);
    rect06.set_fill_color(Color::red);
    rect07.set_fill_color(Color::red);

    win.attach(rect00);
    win.attach(rect01);
    win.attach(rect02);
    win.attach(rect03);
    win.attach(rect04);
    win.attach(rect05);
    win.attach(rect06);
    win.attach(rect07);

    Image big0 {Point{200,0},"img.jpg"};
    Image big1 {Point{400,0},"img.jpg"};
    Image big2 {Point{600,0},"img.jpg"};

    win.attach(big0);
    win.attach(big1);
    win.attach(big2);

    Image small {Point{0,0},"simg.jpg"};
    win.attach(small);
    win.wait_for_button();

    for(int i = 0; i < 8; i++){
    	for(int j = 0; j < 7; j++){
    		small.move(100,0);
    		win.wait_for_button();
    	}
    	small.move(-700,100);
    	win.wait_for_button();
    }
    win.wait_for_button();

}