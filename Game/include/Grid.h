#pragma once

template <class T>

class Grid {

private:
	int width;
	int height;
	T* data;

public:
	Grid():Grid(0, 0){}
	Grid(int w, int h) {
		width = w;
		height = h;

		data = new T[width * height];
	}

	~Grid() {
		delete[] data;
	}

	int getWidth(){
		return width;
	}

	int getHeight() {
		return height;
	}

	T get(int x, int y) {
		assert(!(x < 0 || x >= width || y < 0 || y >= height));
		return data[x * height + y];
	}

	void set(T newThing, int x, int y) {
		assert(!(x < 0 || x >= width || y < 0 || y >= height));
		data[x * height + y] = newThing;
	}

	T* operator[](int x) { 
		assert(!(x < 0 || x >= width));
		return data + x * height; 
	};
};
