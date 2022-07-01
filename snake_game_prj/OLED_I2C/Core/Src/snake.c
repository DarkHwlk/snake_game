#include "snake.h"
#include <stdlib.h>
#include "ssd1306.h"

extern int timer_flag;
extern GameState game_state; 
extern Snake snake;

void game_init(void)
{
	snake.length = 4;
	snake.direction = RIGHT;
	snake.point[0].x = rand() % 50 + 20;
	snake.point[1].x = snake.point[0].x - 3;
	snake.point[2].x = snake.point[1].x - 3;
	snake.point[3].x = snake.point[2].x - 3;
	snake.point[0].y = snake.point[1].y = snake.point[2].y = snake.point[3].y = rand() % 50 + 20;
	for (int i = 0; i < snake.length; i++)
	{
		SSD1306_DrawFilledCircle(snake.point[i].x, snake.point[i].y, 3, SSD1306_COLOR_WHITE);
	}
	SSD1306_UpdateScreen();
	ingame();
}

void ingame()
{
	while(1)
	{
    while(timer_flag)
    {
				Point apple = snake_create_new_apple();
        snake_go();
        // kiem tra game over
				if(snake_check_game_over(&snake) == 1)
				{
					game_state = GAMEOVER;
					break;
				}
				// kiem tra ran co an apple hay khong
        if((snake.point[SNAKE_HEAD].x == apple.x)&&(snake.point[SNAKE_HEAD].y == apple.y)){
            snake.length++;
            Point temp = snake.point[SNAKE_HEAD];
            snake.point[SNAKE_HEAD] = apple;
            snake.point[SNAKE_HEAD - 1] = temp;
            apple = snake_create_new_apple();
        }
				else{
            snake_follow_head();
            snake_draw(snake, apple);
        }
        timer_flag = 0;
    }
	}
}

Point snake_create_new_apple(){
    Point apple;
    apple.x = rand()%LCD_SIZE_X;
    apple.y = rand()%LCD_SIZE_Y;
    return apple;
}

void snake_follow_head(){
    for(int i = SNAKE_HEAD; i >= 0 ; i--)
    {
        snake.point[i-1].x = snake.point[i].x;
        snake.point[i-1].y = snake.point[i].y;
    }
}

void snake_draw(Snake snake, Point apple){
	
	for(int i = snake.length - 1; i >= 0; i--){
			SSD1306_DrawFilledCircle(snake.point[i].x, snake.point[i].y, 3, SSD1306_COLOR_WHITE);
	}
	SSD1306_DrawFilledCircle(apple.x, apple.y, 3, SSD1306_COLOR_WHITE);
	SSD1306_UpdateScreen();
}

void snake_go(){
        switch(snake.direction)
        {
					case UP:
							snake.point[SNAKE_HEAD].y = snake.point[SNAKE_HEAD].y % LCD_SIZE_Y + 1;
							break;
					case DOWN:
							snake.point[SNAKE_HEAD].y = snake.point[SNAKE_HEAD].y % LCD_SIZE_Y - 1;
							break;
					case LEFT:
							snake.point[SNAKE_HEAD].x = snake.point[SNAKE_HEAD].y % LCD_SIZE_X - 1;
							break;
					case RIGHT:
							snake.point[SNAKE_HEAD].y = snake.point[SNAKE_HEAD].y % LCD_SIZE_X + 1;
							break;
        }
}
int snake_check_game_over(const Snake* snake){
	return 0;
}

void information()
{
	return;
}
void setting(){
	return;
}
void gameover(){
	return;
}
void menu(){
	return;
}

