#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include "mandelbrot.hpp"
#include <iostream>
#include <FL/fl_draw.H>

const int NUM_ITERATIONS = 100;

class Main_Window : public Fl_Window {
public:
	Mandelbrot *mandel;
	Main_Window(int width, int height) : Fl_Window(width, height, "Mandelbrot") {
		// resizable(this);
		mandel = new Mandelbrot(width, height, -2.1, 0.58, -1.24, 1.24);
	}

protected:
	void draw() override {
		Fl_Window::draw();

		for (int i = 0; i < NUM_ITERATIONS; i++) {
			mandel->next_iter_set();
			mandel->draw();
		}

		std::cout << "drawn" << std::endl;
	}
};

int main(int argc, char **argv) {
	Main_Window w(800, 800);
	w.show(argc, argv);
	return Fl::run();
}
