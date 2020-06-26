#include "game.h"
#include <iostream>
#include "SDL.h"
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include <thread>

Game::Game(std::size_t grid_width, std::size_t grid_height)
: snake(grid_width, grid_height),
  engine(dev()),
  random_w(0, static_cast<int>(grid_width - 1)),
  random_h(0, static_cast<int>(grid_height - 1)) {
	PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
		std::size_t target_frame_duration) {
	Uint32 title_timestamp = SDL_GetTicks();
	Uint32 frame_start;
	Uint32 frame_end;
	Uint32 frame_duration;
	int frame_count = 0;
	bool running = true;

	while (running) {
		frame_start = SDL_GetTicks();

		// Input, Update, Render - the main game loop.
		controller.HandleInput(running, snake);
		Update();
		renderer.Render(snake, food);

		frame_end = SDL_GetTicks();

		// Keep track of how long each loop through the input/update/render cycle
		// takes.
		frame_count++;
		frame_duration = frame_end - frame_start;

		// After every second, update the window title.
		if (frame_end - title_timestamp >= 1000) {
			renderer.UpdateWindowTitle(score, frame_count);
			frame_count = 0;
			title_timestamp = frame_end;
		}

		// If the time for this frame is too small (i.e. frame_duration is
		// smaller than the target ms_per_frame), delay the loop to
		// achieve the correct frame rate.
		if (frame_duration < target_frame_duration) {
			SDL_Delay(target_frame_duration - frame_duration);
		}
	}
}

void Game::PlaceFood() {
	int x, y,randomEffect;
	while (true) {
		x = random_w(engine);
		y = random_h(engine);

		if((!(score%5)) && score>0)
		{
			randomEffect = (rand() % 4 + 1);
			food.SetFoodType((FoodType)randomEffect);
		}
		else
		{
			food.SetFoodType(FoodType::normal);
		}
		// Check that the location is not occupied by a snake item before placing
		// food.
		if (!snake.SnakeCell(x, y)) {
			food.location.x = x;
			food.location.y = y;
			return;
		}
	}
}

void Game::Update() {
	if (!snake.alive) return;

	snake.Update();

	int new_x = static_cast<int>(snake.head_x);
	int new_y = static_cast<int>(snake.head_y);
	FoodType currentFood= food.GetFoodType();

	// Check if there's food over here
	if (food.location.x == new_x && food.location.y == new_y) {

		switch(currentFood) {
		case FoodType::normal  :
			score++;
			snake.GrowBody();
			break;

		case FoodType::faster  :
			snake.speed =abs(snake.speed+0.1);
			score+= 5;
			break;

		case FoodType::slower  :
			//if subtracted speed is less than initial speed return initial speed, else return (speed -0.3)
			snake.speed = ((snake.speed-0.3) > 0.1) ? (snake.speed-0.3) : 0.1;
			score+= 5;
			break;

		case FoodType::shorter  : //cut snake length by half
			snake.body.erase(snake.body.begin(),(snake.body.begin())+(snake.size/2));
			snake.size=snake.size-(snake.size/2);
			score+= 5;
			break;

		case FoodType::longer  :
		{
			std::thread Enlarge = snake.SpawnThread();
			Enlarge.detach();
			score+= 5;
			break;
		}
		default :;
		}



		PlaceFood();
		// Grow snake and increase speed.

		snake.speed += 0.02;
	}
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
FoodType Food::GetFoodType() {
	return(this->type);
}
void Food::SetFoodType(FoodType inType)
{
	this->type=inType;
	return;
}


