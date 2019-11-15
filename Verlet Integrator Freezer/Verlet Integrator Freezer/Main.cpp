#include <stdlib.h>
#include <stdio.h>

#include <iostream>

class Vec3d
{
public:
	Vec3d() { x = 0; y = 0; z = 0; };

	float x, y, z;
};

class particle 
{
public:
	particle() {};

	Vec3d pos;
	Vec3d speed;
	Vec3d acc;
};

void Verlet(particle input_part, particle previous_part, particle& output_part, Vec3d force) {

	float dt = 1.0f / 30.0f; //We assume 30 fps logic for now


	output_part.acc.x	=  input_part.acc.x; //MRUA for now

	output_part.speed.x = input_part.speed.x + input_part.acc.x * dt;

	output_part.pos.x	= input_part.pos.x + input_part.speed.x * dt + 0.5f * input_part.acc.x * dt * dt;



	
	return;
}



/*
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

}*/

using namespace std;
int main() {


	Vec3d position;
	position.x = 100;
	position.y = 0.0f;
	position.z = 0.0f;

	Vec3d velocity;
	velocity.x = 16.0f;
	velocity.y = 0.0f;
	velocity.z = 0.0f;

	Vec3d acceleration;
	acceleration.x = 64.0f;
	acceleration.y = 0.0f;
	acceleration.z = 0.0f;


	particle part_in;
	part_in.acc = acceleration;
	part_in.pos = position;
	part_in.speed = velocity;
	
	particle part_out;
	particle part_prev;
	
	Vec3d force;

	Verlet(part_in, part_prev, part_out, force);

	cout << "---------Input----------" << endl;
	cout << "POSITION: " << "x: " << part_in.pos.x << "  y: " << part_in.pos.y << "  z: " << part_in.pos.z << endl;
	cout << "SPEED: " << "x: " << part_in.speed.x << "  y: " << part_in.speed.y << "  z: " << part_in.speed.z << endl;
	cout << "ACCELERATION: " << "x: " << part_in.acc.x << "  y: " << part_in.acc.y << "  z: " << part_in.acc.z << endl << endl;


	cout << "---------Output----------" << endl;
	cout << "POSITION: "<< "x: " << part_out.pos.x << "  y: " << part_out.pos.y << "  z: " << part_out.pos.z << endl;
	cout << "SPEED: " << "x: " << part_out.speed.x << "  y: " << part_out.speed.y << "  z: " << part_out.speed.z << endl;
	cout << "ACCELERATION: " << "x: " << part_out.acc.x << "  y: " << part_out.acc.y << "  z: " << part_out.acc.z << endl << endl;




	system("pause");
	return 0;
}