#include<iostream>

class Vector 
{
	public:
		Vector(const int size = 100);
		~Vector();
		void push_back (int elem);
		void insert_at(int index, int elem);
		int get_at(int index);
		int get_size();
		void print();
	private:
		int* m_arr;
		int m_size;
		int m_top;
};

int main () {
	Vector v;
	v.push_back (5);
	v.push_back (10);
	v.push_back (15);
	v.push_back (25);
	v.print ();
	v.insert_at (1, 33);
	std::cout<< v.get_at (0) << std::endl;
	std::cout<< "SIZE = " << v.get_size ()<< std::endl;
	v.print ();
	
	
}	

Vector::Vector (const int size) {
	this -> m_size = size;
	if (this -> m_size < 1) {
		return;
	}
	this -> m_arr = new int[m_size];
	this -> m_top = -1;
}

void Vector::push_back (int elem) {
	if (this -> m_top == this -> m_size - 1) {
		int* array = new int[this -> m_size * 2];
		for (int i = 0; i < this -> m_size - 1; i++) {
			array[i] = this -> m_arr[i];
		}
		delete [] this -> m_arr;
		this -> m_arr = array;
		this -> m_size *= 2;
	}
	++this -> m_top;
	this -> m_arr[this -> m_top] = elem;
}


void Vector::insert_at(int index, int elem) {
	if (index < 0 || index > this -> m_top) {
		return;
	}
	this -> m_arr[index] = elem;

}

int Vector::get_at(int index) {
	if (index < 0 || index > this -> m_top) {
		return -1;
	}
	return this -> m_arr[index];
}

int Vector::get_size() {
	return this -> m_top + 1;
}

void Vector::print () {
	for (int i = 0; i < this -> m_top + 1; ++i) {
		std::cout<< this -> m_arr[i] <<std::endl;
	}
}

Vector:: ~Vector () {
	delete [] this -> m_arr;
	this -> m_arr = NULL;
}
