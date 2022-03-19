# printf

> :warning: **This program is implemented under the Mac OS system.**

## Rus

#### Цель:
```
 Переписать функцию printf(урезанную).
```
#### Задача:
```
1. Реализовать обработку форматов:
   · %c - печатает один символ.
   · %s - печатает строку.
   · %p - аргумент указателя void * должен быть напечатан в шестнадцатеричном формате.
   · %d - печатает десятичное число (с основанием 10).
   · %i - выводит целое число по основанию 10.
   · %u - печатает десятичное число без знака (с основанием 10).
   · %x - печатает число в шестнадцатеричном формате (с основанием 16) в нижнем регистре.
   · %X - печатает число в шестнадцатеричном формате (с основанием 16) в верхнем регистре.
   · %% - печатает знак процента.
2. Поведение функции должно совпадать с оригинальной.
3. Реализовать обработку флагов:
   · '0' - дополнять поле до ширины, указанной в поле ширина управляющей последовательности,
     символом 0.
   · '-' - выводимое значение выравнивается по левому краю в пределах минимальной ширины поля.
4. Реализовать модификатор точности:
   · '.' - точность с последующим десятичным числом.
   · '*' - при обработке строки форматирования значение для поля читается из списка аргументов.
```

## Eng

#### The Goal:
```
Rewrite the printf function(cut verion).
```
#### The Task:
```
1. Implement format processing:
   · %c - prints one character.
   · %s - prints a string.
   · %p - the void * pointer argument has to be printed in hexadecimal format.
   · %d - prints a decimal (base 10) number.
   · %i - prints an integer in base 10.
   · %u - prints an unsigned decimal (base 10) number.
   · %x - prints a number in hexadecimal (base 16) lowercase format.
   · %X - prints a number in hexadecimal (base 16) uppercase format.
   · %% - Prints a percent sign.
2. The behavior of the function must match the original.
3. Implement flag processing:
   · '0' - left-pads the number with zeroes (0) instead of spaces when padding is specified.
   · '-' - left-justify within the given field width.
4. Implement precision modifier:
   · '.' - precision followed by a decimal number.
   · '*' - when processing the format string, the value is read from the argument list.
```
