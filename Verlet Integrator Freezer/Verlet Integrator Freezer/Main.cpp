#include <stdlib.h>
#include <stdio.h>

#include <iostream>

class Vec3d
{
public:
	float x, y, z;
};

void Verlet(Vec3d pos_i, Vec3d v_i, Vec3d& pos_f, Vec3d& v_f, float dt)
{

	int a = 0;
	//Get pos_f

	pos_f.x = pos_i.x + v_i.x + a * dt * dt;
	pos_f.y = pos_i.y + v_i.y + a * dt * dt;
	pos_f.z = pos_i.z + v_i.z + a * dt * dt;


	v_f.x = pos_f.x - pos_i.x;
	v_f.y = pos_f.y - pos_i.y;
	v_f.z = pos_f.z - pos_i.z;

}

using namespace std;
int main() {


	Vec3d position;
	position.x = 420.69f;
	position.y = 0.0f;
	position.z = 0.0f;

	Vec3d velocity;
	velocity.x = 420.69f;
	velocity.y = 69.69f;
	velocity.z = 0.0f;

	Vec3d position_f, velocity_f;

	int tmp = 0;
	cout << "Input number of steps:";
	cin >> tmp;
	
	Verlet(position, velocity, position_f, velocity_f, tmp);


	cout << "---------Initial position----------" << endl;
	cout << "x: " << position.x << "  y: " << position.y << "  z: " << position.x << endl << endl;

	cout << "---------Initial velocity----------" << endl;
	cout << "x: " << velocity.x << "  y: " << velocity.y << "  z: " << velocity.x << endl << endl;

	cout << "---------Final position----------" << endl;
	cout << "x: " << position_f.x << "  y: " << position_f.y << "  z: " << position_f.x << endl << endl;

	cout << "---------Final velocity----------" << endl;
	cout << "x: " << velocity_f.x << "  y: " << velocity_f.y << "  z: " << velocity_f.x << endl << endl;


	system("pause");
	return 0;
}