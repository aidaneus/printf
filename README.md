# printf

> :warning: **This program is implemented under the Mac OS system.**

## Rus

#### Задача:
```
 Переписать функцию printf(урезанную).
```
#### Реализовано:
```
1. Обработка форматов:
   · %c - печатает один символ.
   · %s - печатает строку.
   · %p - аргумент указателя void * должен быть напечатан в шестнадцатеричном формате.
   · %d - печатает десятичное число (с основанием 10).
   · %i - выводит целое число по основанию 10.
   · %u - печатает десятичное число без знака (с основанием 10).
   · %x - печатает число в шестнадцатеричном формате (с основанием 16) в нижнем регистре.
   · %X - печатает число в шестнадцатеричном формате (с основанием 16) в верхнем регистре.
   · %% - печатает знак процента.
2. Поведение функции совпадает с оригинальной.
3. Обработка флагов:
   · '0' - дополнять поле до ширины, указанной в поле ширина управляющей последовательности,
     символом 0.
   · '-' - выводимое значение выравнивается по левому краю в пределах минимальной ширины поля.
4. Модификатор точности:
   · '.' - точность с последующим десятичным числом.
   · '*' - при обработке строки форматирования значение для поля читается из списка аргументов.
```
#### Инструкция для теста:
```
gcc .\main.c .\srcs\*.c
```

## Eng

#### The Task:
```
Rewrite the printf function(cut verion).
```
#### Implemented:
```
1. Format processing:
   · %c - prints one character.
   · %s - prints a string.
   · %p - the void * pointer argument has to be printed in hexadecimal format.
   · %d - prints a decimal (base 10) number.
   · %i - prints an integer in base 10.
   · %u - prints an unsigned decimal (base 10) number.
   · %x - prints a number in hexadecimal (base 16) lowercase format.
   · %X - prints a number in hexadecimal (base 16) uppercase format.
   · %% - Prints a percent sign.
2. The behavior of the function matched the original.
3. Flag processing:
   · '0' - left-pads the number with zeroes (0) instead of spaces when padding is specified.
   · '-' - left-justify within the given field width.
4. Precision modifier:
   · '.' - precision followed by a decimal number.
   · '*' - when processing the format string, the value is read from the argument list.
```
#### Instruction for test:
```
gcc .\main.c .\srcs\*.c
```
