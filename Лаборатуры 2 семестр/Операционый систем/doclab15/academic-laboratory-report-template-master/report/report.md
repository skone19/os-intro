---
# Front matter
lang: ru-RU
title: "Отчёта по лабораторной работе №15"
subtitle: "Операционый Систем"
author: "Коне Сирики НФИБД-01-20"

# Formatting
toc-title: "Содержание"
toc: true # Table of contents
toc_depth: 2
lof: true # List of figures
lot: true # List of tables
fontsize: 12pt
linestretch: 1.5
papersize: a4paper
documentclass: scrreprt
polyglossia-lang: russian
polyglossia-otherlangs: english
mainfont: PT Serif
romanfont: PT Serif
sansfont: PT Sans
monofont: PT Mono
mainfontoptions: Ligatures=TeX
romanfontoptions: Ligatures=TeX
sansfontoptions: Ligatures=TeX,Scale=MatchLowercase
monofontoptions: Scale=MatchLowercase
indent: true
pdf-engine: lualatex
header-includes:
  - \linepenalty=10 # the penalty added to the badness of each line within a paragraph (no associated penalty node) Increasing the value makes tex try to have fewer lines in the paragraph.
  - \interlinepenalty=0 # value of the penalty (node) added after each line of a paragraph.
  - \hyphenpenalty=50 # the penalty for line breaking at an automatically inserted hyphen
  - \exhyphenpenalty=50 # the penalty for line breaking at an explicit hyphen
  - \binoppenalty=700 # the penalty for breaking a line at a binary operator
  - \relpenalty=500 # the penalty for breaking a line at a relation
  - \clubpenalty=150 # extra penalty for breaking after first line of a paragraph
  - \widowpenalty=150 # extra penalty for breaking before last line of a paragraph
  - \displaywidowpenalty=50 # extra penalty for breaking before last line before a display math
  - \brokenpenalty=100 # extra penalty for page breaking after a hyphenated line
  - \predisplaypenalty=10000 # penalty for breaking before a display
  - \postdisplaypenalty=0 # penalty for breaking after a display
  - \floatingpenalty = 20000 # penalty for splitting an insertion (can only be split footnote in standard LaTeX)
  - \raggedbottom # or \flushbottom
  - \usepackage{float} # keep figures where there are in the text
  - \floatplacement{figure}{H} # keep figures where there are in the text
---

# Цель работы

приобретение практических навыков работы с именованными каналами.

# Задание

Именованные каналы

# Выполнение лабораторной работы

Ход работы:
1.Изучил приведённые в тексте программы server.c и client.c и взяла данные
примеры за образец.

common.h:

 (рис. -@fig:001)

![рисунок 1](image/co.png){ #fig:001 width=70% }
 
server.c:
  

 (рис. -@fig:002)

![рисунок 2](image/sero.png){ #fig:002 width=70% }

(рис. -@fig:003)

![рисунок 3](image/servos.png){ #fig:003 width=70% }


client.c:

(рис. -@fig:004)

![рисунок 4](image/clo.png){ #fig:004 width=70% }

(рис. -@fig:005)

![рисунок 5](image/rone.png){ #fig:005 width=70% }



2. Написал аналогичные программы, внеся следующие изменения:
- работает не 1 клиент, а несколько (например, два).
- клиенты передают текущее время с некоторой периодичностью (например, раз
в пять секунд). Использовала функцию sleep() для приостановки работы клиента.

3. сервер работает не бесконечно, а прекращает работу через некоторое время (например, 30 сек). Использовала функцию clock() для определения времени работы
сервера.

common.h:

(рис. -@fig:006)

![рисунок 6](image/co1.png){ #fig:006 width=70% }

server.c:

(рис. -@fig:007)

![рисунок 7](image/Ser1.png){ #fig:007 width=70% }

(рис. -@fig:008)
 
![рисунок 8](image/Serv2.png){ #fig:008 width=70% }


client.c:

(рис. -@fig:009)
 
![рисунок 9](image/clo.png){ #fig:009 width=70% }


 client1.c:

(рис. -@fig:010)
 
![рисунок 10](image/cl1.png){ #fig:010 width=70% }

(рис. -@fig:011)
 
![рисунок 11](image/cl1s.png){ #fig:011 width=70% }

(рис. -@fig:012)
 
![рисунок 12](image/r231.png){ #fig:012 width=70% }
 
(рис. -@fig:013)
 
![рисунок 13](image/r232.png){ #fig:013 width=70% }
 
 
 



 

В случае, если сервер завершит работу, не закрыв канал, файл FIFO не удалится, поэтому его в следующий раз создать будет нельзя и вылезет ошибка, следовательно, работать ничего не будет.



Контрольные вопросы:

1. Именованные каналы отличаются от неименованных наличием идентификатора 
канала, который представлен как специальный файл (соответственно имя именованного канала — это имя файла). Поскольку файл находится на локальной файловой системе, данное IPC используется внутри одной системы.
2.Создание неименованного канала из командной строки невозможно.
3.Создание именованного канала из командной строки возможно.

4. int read(int pipe_fd, void *area, int cnt);
int write(int pipe_fd, void *area, int cnt);
Первый аргумент этих вызовов - дескриптор канала, второй - указатель на область памяти, с которой происходит обмен, третий - количество байт. Оба вызова возвращают число переданных байт (или -1 - при ошибке).

5. int mkfifo (const char *pathname, mode_t mode) ;
mkfifo(FIFO_NAME, 0600) ;
Первый параметр — имя файла, идентифицирующего канал, второй параметр маска прав доступа к файлу. Вызов функции mkfifo() создаёт файл канала (с именем, заданным макросом FIFO_NAME).
6. При чтении меньшего числа байтов, чем находится в канале, возвращается требуемое число байтов, остаток сохраняется для последующих чтений. При чтении большего числа байтов, чем находится в канале или FIFO возвращается доступное число байтов.

7. При записи большего числа байтов, чем это позволяет канал или FIFO, вызов write(2) блокируется до освобождения требуемого места. При этом атомарность операции не гарантируется. Если процесс пытается записать данные в канал, не открытый ни одним процессом на чтение, процессу генерируется сигнал. Запись числа байтов, меньшего емкости канала или FIFO, гарантированно атомарно. Это означает, что в случае, когда несколько процессов одновременно записывают в канал, порции данных от этих процессов не перемешиваются.

8. В общем случае возможна много направленная работа процессов с каналом, т.е. возможна ситуация, когда с одним и тем же каналом 
взаимодействуют два и более процесса, и каждый из взаимодействующих каналов пишет и читает информацию в канал. Но традиционной схемой 
организации работы с каналом является однонаправленная организация, когда канал связывает два, в большинстве случаев, или несколько 
взаимодействующих процесса, каждый из которых может либо читать, 
либо писать в канал.

9. Write - Функция записывает length байтов из буфера buffer в файл, определенный дескриптором файла fd. Эта операция чисто 'двоичная' и без буферизации. Реализуется как непосредственный вызов DOS. С помощью функции write мы посылаем сообщение клиенту или серверу.

10. Строковая функция strerror - функция языков C/C++, транслирующая код ошибки, который обычно хранится в глобальной переменной errno, в сообщение об ошибке, понятном человеку. Ошибки эти возникают при вызове функций стандартных Си-библиотек. Возвращенный указатель ссылается на статическую строку с ошибкой, которая не должна быть изменена программой. Дальнейшие вызовы функции strerror перезапишут содержание этой строки. Интерпретированные сообщения об ошибках могут различаться, это зависит от платформы и компилятора.


# Выводы

Приобрел практические навыки работы с именованными каналами.
