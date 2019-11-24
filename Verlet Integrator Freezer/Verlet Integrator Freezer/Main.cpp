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


void Verlet(particle* prev_part, particle* output_part, Vec3d force,float dt) 
{

	//previous valours to output particle
	//output_part->acc.x =  prev_part->acc.x; //MRUA for now
	//output_part->acc.y = prev_part->acc.y;
	//output_part->acc.z = prev_part->acc.z;

	//Calculate new speed based on prev speed and acceleration
	output_part->speed.x = prev_part->speed.x + prev_part->acc.x * dt; // v = vi + a*t
	output_part->speed.y = prev_part->speed.y + prev_part->acc.y * dt;
	output_part->speed.z = prev_part->speed.z + prev_part->acc.z * dt;

	//Calculate position based on previous position and new speed and acceleration
	output_part->pos.x = prev_part->pos.x + output_part->speed.x * dt + 0.5f * prev_part->acc.x * dt * dt; // x = xi + v*t + 1/2*a*t*t
	output_part->pos.y = prev_part->pos.y + output_part->speed.y * dt + 0.5f * prev_part->acc.y * dt * dt;
	output_part->pos.z = prev_part->pos.z + output_part->speed.z * dt + 0.5f * prev_part->acc.z * dt * dt;

	//Store calculated stuff into prev so that we can iterate next output from this prev
	prev_part->acc.x = output_part->acc.x;
	prev_part->acc.y = output_part->acc.y;
	prev_part->acc.z = output_part->acc.z;

	prev_part->speed.x = output_part->speed.x;
	prev_part->speed.y = output_part->speed.y;
	prev_part->speed.z = output_part->speed.z;

	prev_part->pos.x = output_part->pos.x;
	prev_part->pos.y = output_part->pos.y;
	prev_part->pos.z = output_part->pos.z;

	return;
}

using namespace std;
int main() {

	float dt = 1.0f / 30.0f; //We assume 30 fps logic for now

	Vec3d position;
	position.x = 100;
	position.y = 10.0f;
	position.z = 0.0f;

	Vec3d velocity;
	velocity.x = 10.0f;
	velocity.y = 5.0f;
	velocity.z = 0.0f;

	Vec3d acceleration;
	acceleration.x = 10.0f;
	acceleration.y = 20.0f;
	acceleration.z = 0.0f;

	particle part_prev;
	part_prev.acc = acceleration;
	part_prev.pos = position;
	part_prev.speed = velocity;
	
	particle part_out;
	
	Vec3d force;

	//TODO 
	//add friction that varies a somehow
	//add some kind of collision

	cout << "---------Input----------" << endl;
	cout << "POSITION: " << "x: " << part_prev.pos.x << "  y: " << part_prev.pos.y << "  z: " << part_prev.pos.z << endl;
	cout << "SPEED: " << "x: " << part_prev.speed.x << "  y: " << part_prev.speed.y << "  z: " << part_prev.speed.z << endl;
	cout << "ACCELERATION: " << "x: " << part_prev.acc.x << "  y: " << part_prev.acc.y << "  z: " << part_prev.acc.z << endl << endl;

	for (int i = 0; i < 4; i++)
	{
		Verlet(&part_prev, &part_out, force, 1 );

		cout << "---------Output----------" << endl;
		cout << "POSITION: " << "x: " << part_out.pos.x << "  y: " << part_out.pos.y << "  z: " << part_out.pos.z << endl;
		cout << "SPEED: " << "x: " << part_out.speed.x << "  y: " << part_out.speed.y << "  z: " << part_out.speed.z << endl;
		cout << "ACCELERATION: " << "x: " << part_out.acc.x << "  y: " << part_out.acc.y << "  z: " << part_out.acc.z << endl << endl;
	}

	system("pause");
	return 0;
}