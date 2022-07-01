#ifndef SNAKE_H
#define SNAKE_H

#define LCD_SIZE_X 120
#define LCD_SIZE_Y 80
#define SNAKE_HEAD (snake.length - 1)
#define SNAKE_TAIL 0

enum state{
	INFORMATION = 0,
	INGAME,
	SETTING,
	GAMEOVER,
	MENU
}game_state;

typedef enum Button
{
    BTN_UP,
    BTN_DOWN,
    BTN_LEFT,
    BTN_RIGHT,
    BTN_SELECT,
    BTN_QUIT
}Button;
Button btn;
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
}point;

struct snake{
	point point[100];
	int length;
    volatile Direction direction;
}snake;

//function prototypes
void game_init(void);
void ingame(void);
void snake_follow_head(void);
void snake_draw(point apple);
void snake_go(void);
void information();
void setting();
void gameover();
void menu();
void snake_check_game_over(void);

#endif