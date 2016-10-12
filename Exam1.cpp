//I affirm that all code given below was written solely 
//by me, Grant Bingham, and that any help I received 
//adhered to the rules stated for this exam.
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace Exam1 // NAMESPACE
{
	class Wheel
	{
	private:
		int _radius;
	public:
		Wheel(int radius) { _radius = radius; }
	};

	// STEP 1: Complete the implementation of the Vehicle base class
	// as described in the UML diagram
	class Vehicle
	{
	protected:
		string _color;
		int _topspeed;
		vector<Wheel> wheels;

	public:
		Vehicle();
		Vehicle(string color) {
			_color = color;
			// Complete the implementation
		}
		virtual void Description() = 0;
	};

	// STEP 2:  Define the RaceCar, Sedan, and Pickup classes as described
	// in the UML diagram.   For this test, you do not need to separate
	// the class implementation into a cpp file.
	class RaceCar : public Vehicle {
		//Top speed: 250mph
		//Wheel radius: 305mm
	public:
		RaceCar(string color) {
			_color = color;
			_topspeed = 205;
			Wheel A(305);
			wheels.push_back(A);
		}

		void Description() {
			cout << "I am a " << _color << " race car that can race " << _topspeed << "mph!" << endl;
		}
	};

	class Sedan : public Vehicle {
		//Top speed: 95mph
		//Wheel radius: 381mm
	public:
		Sedan(string color, int seats)
		{
			_color = color;
			number_of_seats = seats;
			_topspeed = 95;
			Wheel B(381);
			wheels.push_back(B);
		}
		void Description() {
			cout << "I am a " << _color << " sedan that can carry " << number_of_seats << " people at " << _topspeed << "!" << endl;
		}
	private:
		int number_of_seats;
	};

	class Pickup : public Vehicle {
		//Top speed: 85mph
		//Wheel radius: 432mm
	public:
		Pickup(string color, int capacity) {
			_color = color;
			hauling_capacity = capacity;
			_topspeed = 85;
			Wheel C(432);
			wheels.push_back(C);
		}
		void Description() {
			cout << "I am a " << _color << " pickup that can haul " << hauling_capacity << " at " << _topspeed << "mph." << endl;
		}
	private:
		int hauling_capacity;
	};
}


int main()
{
	Exam1::Vehicle * Garage[3];

	Exam1::RaceCar Car1("Black");
	Exam1::Sedan Car2("Blue", 5);
	Exam1::Pickup Car3("Red", 5);

	// STEP 3: Assign ONE RaceCar, ONE Sedan, AND ONE Pickup object to each of the elements
	// in the Garage array.  Remember the classes are defined in the namespace Exam1.
	Garage[0] = &Car1;
	Garage[1] = &Car2;
	Garage[2] = &Car3;

	for (int i = 0; i < 3; ++i)
	{
		// The method Description() should display an output like
		// "I am a red sedan (or racecar/pickup) and I can go 95 (or 250 or 85) mph"
		Garage[i]->Description();
	}
	return 0;
}
