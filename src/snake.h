#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include <thread>

enum FoodType //creating a new type of food
{
	normal, // orange
	faster, // yellow
	slower,  //blue
	shorter, //green
	longer  //red
};
class Food{ // modefting Food to be a class instead of a only a location
public:
	//construct first Food to be of type normal
	Food():type(FoodType::normal){}

	void SetFoodType(FoodType inType);
	FoodType GetFoodType();


	SDL_Point location;

private:
	FoodType  type;

};


class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Update();

  void GrowBody();
  void SuperGrow();
  std::thread SpawnThread();
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif
