import random
import tkinter
# Исходные параметрые
# import GameBalls
# from logging import root
from mimetypes import init
from tkinter import Canvas

WIDTH = 600
HEIGHT = 400
BG_COLOR = 'white'
MAIN_BALL_RADIUS = 30
MAIN_BALL_COLOR = 'BLUE'
INIT_DX = 1
INIT_DY = 1
BAD_COLOR = 'red'
COLORS = ['green', 'yellow', BAD_COLOR,'aqua', 'gold', 'pink']
Number_balls = 6


# Klacc шapа
class Balls():
    # метод конструктора
    def __init__(self, x, y, r, color, dx=0, dy=0):
        self.x = x
        self.y = y
        self.r = r
        self.color = color
        self.dx = dx
        self.dy = dy


 # Рисует шар
    def draw(self):
      canvas.create_oval(self.x - self.r, self.y - self.r, self.x + self.r, self.y + self.r, fill=self.color,
                       outline=BG_COLOR)


# функция очистить шара
    def hide(self):
      canvas.create_oval(self.x - self.r, self.y - self.r, self.x + self.r, self.y + self.r, fill=BG_COLOR,
                       outline=BG_COLOR)


    def is_collision(self, ball):
      a = abs(self.x + self.dx - ball.x)
      b = abs(self.y + self.dy - ball.y)
      return (a*a + b*b)**0.5 <= self.r + ball.r


    # Функции движение
    def move(self):
       if (self.x + self.r + self.dx >= WIDTH) or (self.x - self.r + self.dx <= 0):
        self.dx = -self.dx
       if (self.y + self.r + self.dy >= HEIGHT) or (self.y - self.r + self.dy <= 0):
        self.dy = -self.dy


    # солкинование с шаром
       for ball in balls:
         if self.is_collision(ball):
             if ball.color != BAD_COLOR:
                ball.hide()
                balls.remove(ball)
                #self.hide()
                self.dx = -self.dx
                self.dy = -self.dy
             else:
                 self.dx=self.dy=0
       self.hide()
       self.x += self.dx
       self.y += self.dy
       self.draw()


# Функции клика Мышка
def mouse_click(event):
    # Столкиванием со стенной
     global main_ball
     if event.num == 1:
        if 'main_ball' not in globals():
            main_ball = Balls(event.x, event.y, MAIN_BALL_RADIUS, MAIN_BALL_COLOR, INIT_DX, INIT_DY)
            main_ball.draw()
            # main_ball.move()
        else:  # поворот налево
            if main_ball.dx * main_ball.dy > 0:
                main_ball.dy = -main_ball.dy
            else:
              main_ball.dx = -main_ball.dx
     elif event.num == 3:  # поворот направо
        if main_ball.dx * main_ball.dy > 0:
            main_ball.dx = -main_ball.dx
        else:
            main_ball.dy = -main_ball.dy

    # Списков шаров

def create_list_of_balls(number):
      lst = []
      while len(lst) < number:
        next_ball = Balls(random.choice(range(0, WIDTH)), random.choice(range(0, HEIGHT)), random.choice(range(20, 30)),
                          random.choice(COLORS))
        lst.append(next_ball)
        next_ball.draw()
      return lst

# количество шаров
def count_bad_balls(list_of_balls):
        res=0
        for ball in list_of_balls:
            if ball.color==BAD_COLOR:
                res +=1
        return  res
    # else:
    #     main_ball.hide()
    # главная функция
def main():
 num_of_bad_balls = count_bad_balls(balls)
 if 'main_ball' in globals():
        main_ball.move()
        if len(balls) - num_of_bad_balls== 0:
         canvas.create_text(WIDTH / 2, HEIGHT / 2, text='you have won', font='Arial 20', fill=MAIN_BALL_COLOR)
         main_ball.dx = main_ball.dy = 0
        elif main_ball.dx==0:
         canvas.create_text(WIDTH / 2, HEIGHT / 2, text='Game over, you lost',font='Arial 20', fill=MAIN_BALL_COLOR)
 root.after(20, main)
        # root=tkinter.tk()
        # root.title('Balls')
    # canvas=tkinter.('Balls')


# Создаем окно игри (холст)
root = tkinter.Tk()
root.title('Balls')
canvas= tkinter.Canvas(root, width=WIDTH, height=HEIGHT, bg=BG_COLOR)
canvas.pack()  # Открываем экран
canvas.bind('<Button-1>', mouse_click)
canvas.bind('<Button-3>', mouse_click, '+')
if 'main_ball' in globals():
     del main_ball
balls = create_list_of_balls((Number_balls))
num_of_bad_balls=count_bad_balls(balls)
main()
root.mainloop()  # закрыть экран