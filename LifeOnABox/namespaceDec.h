#include <math.h>
#include <iostream>
namespace JBnamespace {
	class vector3D {
	private:
		float p;
	public:
		float x, y, z;
		vector3D() : x(0), y(0), z(0) {}
		vector3D(const float x, const float y, const float z) : x(x), y(y), z(z) {}

		vector3D operator+(const vector3D &v) const {
			return vector3D(x + v.x, y + v.y, z + v.z);
		}

		void operator+=(const vector3D &v) {
			x += v.x;
			y += v.y;
			z += v.z;
		}


		vector3D operator-(const vector3D &v) const {
			return vector3D(x - v.x, y - v.y, z - v.z);
		}

		void operator-=(const vector3D &v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
		}


		vector3D operator*(const float &v) const {
			return vector3D(x * v, y * v, z * v);
		}

		void operator*=(const float &v) {
			x *= v;
			y *= v;
			z *= v;
		}

		float magnitude() {
			return sqrtf(x*x + y*y + z*z);
		}

		float squareMagnitude(){
			return (x*x + y*y + z*z);
		}

		void normalize() {
			float l = magnitude();
			x /= l;
			y /= l;
			z /= l;
		}


	};
	class particle {
	public:
		vector3D acceleration, velocity, position;
		particle() : acceleration(vector3D(0, 0, 0)), velocity(vector3D(0, 0, 0)), position(vector3D(0, 0, 0)) {}
		particle(const vector3D acceleration, const vector3D velocity, const vector3D position) : acceleration(acceleration), velocity(velocity), position(position) {}

		void update(float deltaTime) {
			velocity += acceleration * deltaTime;
			position += velocity * deltaTime;
		}
	};	
}