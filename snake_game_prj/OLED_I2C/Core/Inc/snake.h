#ifndef SNAKE_H
#define SNAKE_H

#define LCD_SIZE_X 128
#define LCD_SIZE_Y 64
#define SNAKE_HEAD (snake.length - 1)
#define SNAKE_TAIL 0

typedef enum state{
	INFORMATION = 0,
	INGAME,
	SETTING,
	GAMEOVER,
	MENU
}GameState;

typedef enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}Direction;

typedef struct point{
	int x;
	int y;
}Point;

typedef struct snake{
	Point point[100];
	int length;
  Direction direction;
}Snake;

//function prototypes
void game_init(void);
void ingame(void);
void snake_follow_head(void);
void snake_draw(Snake snake,Point apple);
void snake_go(void);
void information(void);
void setting();
void gameover(void);
void menu(void);
int snake_check_game_over(const Snake* snake);
Point snake_create_new_apple(void);

#endif
