/**********************************************************************
 *
 * IMPORTANT NOTE:
 * Make sure you compile the project in x86 architecture.
 * If you see x64 in the combo box above, change it to x86.
 * This is because the libraries we are using (SDL, libpng, etc) are
 * compiled in x86 architecture, so we have to adapt.
 *
 **********************************************************************/

#pragma comment(linker,"/ENTRY:mainCRTStartup")
#pragma comment(linker,"/SUBSYSTEM:WINDOWS")

#include <stdlib.h>
#include "sdl_functions.h"
#include "j1PerfTimer.h"
#include "j1Timer.h"

struct Ball
{
	SDL_Rect rect;    // position in the texture
	SDL_Texture *tex; // texture
	float x, y;       // position in the world
	float vx, vy;     // velocity in the world
};

j1PerfTimer			ptimer;
j1PerfTimer			delay_timer;
int				frame_count = 0;
j1Timer				startup_time;
j1Timer				frame_time;
j1Timer				last_sec_frame_time;
int				last_sec_frame_count = 0;
int				prev_last_sec_frame_count = 0;
int					frame_rate;

int main(int argc, char* argv[])
{
	// Initialize SDL
	if (Init() == 0) {
		return 1;
	}

	// Load a texture
	SDL_Texture *texScreen = LoadTexture("Assets/Screens/spacee.png");
	SDL_Texture *texBall = LoadTexture("Assets/Sprites/kirby_ball.png");

	Ball ball = {
		{0, 0, 200, 200}, // SDL_Rect
		texBall,          // SDL_Texture
		270, 100,         // Initial position in the screen
		0, 0              // Initial velocity
	};





	const float gravity = 600.0f;         // pixels / second^2
	const float deltaTime = 1.0f / 30.0f; // More or less 60 frames per second

	while (exitApplication != 1)
	{
		PreUpdate(); // Updates events


		/* Draw the screen */
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = 1920;
		rect.h = 1080;
		Blit(texScreen, -500, 0, &rect);

		// Apply gravity
		// TODO 1: Update ball position based on the current position, the current velocity, the acceleration (gravity) and the time passed (deltaTime)
		// TODO 2: Update ball velocity based on the current velocity, the acceleration (gravity) and the time passed (deltaTime)

		// Ball touched the floor
		if (ball.y >= 350)
		{	
			// TODO 3: If the floor was reached, do something, stop the ball, make it bounce...
		}

		/* Draw the ball */
		Blit(ball.tex, ball.x, ball.y, &ball.rect);

		PostUpdate(); // Presents the screen
	}

	// Unload textures
	UnloadTexture(texBall);
	UnloadTexture(texScreen);

	// Finalize SDL
	CleanUp();

	return 0;
}
