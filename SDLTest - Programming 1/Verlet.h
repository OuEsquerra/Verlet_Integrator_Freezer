
struct Vec3d
{

	Vec3d() { x = 0; y = 0; z = 0; };

	float x, y, z;
};

struct particle
{
	particle() {};

	Vec3d pos;
	Vec3d speed;
	Vec3d acc;
};


void Verlet(particle* prev_part, particle* output_part, Vec3d force, float dt)
{

	//previous valours to output particle
	output_part->acc.x = prev_part->acc.x; //MRUA for now
	output_part->acc.y = prev_part->acc.y;
	output_part->acc.z = prev_part->acc.z;

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
}