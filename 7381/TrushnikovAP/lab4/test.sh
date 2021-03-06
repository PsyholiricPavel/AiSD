#!/bin/bash

echo "Запуск тестов..."

echo "Тест №1: ((a+b)*3)"
./lab4 \( a + b \) \* 3

echo "Тест №2: ((a+c)-(3+9))"
./lab4 \( \( a + c \) - \( 3 + 9 \) \)

echo "Тест №3: ((a*(b+c)+d)*(7+h))"
./lab4 \( \( a \* \( b + c \) + d \) \* \( 7 + h \) \)

echo "Тест №4: (((a*b)+(a*c))*9) "
./lab4 \( \( \( a \* b \) + \( a \* c \) \) \* 9 \)

echo "Тест №5: (a+) "
./lab4 \( a + \)

echo "Тест №6: ((2+k) "
./lab4 \( \( 2 + k \)