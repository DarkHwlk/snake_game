#include "snake.h"

void game_init(void)
{
	snake.length = 4;
	snake.direction = RIGHT;
	snake.point[0].x = rand() % 50 + 20;
	snake.point[0].y = rand() % 50 + 20;
	for (int i = 0; i < snake.length; i++)
	{
//		gotoxy();
//		printf("o");
//		printf("%d ",snake.point[i].x);
//		printf("%d\n",snake.point[i].y);
	}
	ingame();
}

void ingame()
{
    point apple = snake_create_new_apple();
    while(flag_timer)
    {
        snake_go();
        // kiem tra game over

        if((snake.point[SNAKE_HEAD].x == apple.x)&&(snake.point[SNAKE_HEAD].y == apple.y)){
            snake.length++;
            point temp = snake.point[SNAKE_HEAD];
            snake.point[SNAKE_HEAD] = apple;
            snake.point[SNAKE_HEAD - 1] = temp;
            apple = snake_create_new_apple();
        }else{
            snake_follow_head();
            snake_draw(apple);
        }
        flag_timer = 0;
        hal_dalay(5000);
    }

}

while(flag_timer){

}

point snake_create_new_apple(){
    point apple;
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

void snake_draw(point apple){
    for(int i = SNAKE_HEAD; i >= 0; i--){
        lcd_gotoxy(snake.point[i].x,snake.point[i].y);
        lcd_write("o");
    }
    lcd_gotoxy(apple.x,apple.y);
    lcd_write("O");
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
void information();
void setting();
void gameover();
void menu();
