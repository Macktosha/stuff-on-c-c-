#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//C:\Users\Антон\source\repos\highlvl7\Debug\highlvl7.exe C:\Users\Антон\source\repos\highlvl7\source.txt
//Это пути для быстрой вставки в командную строку
    

int main(int argc, const char* argv[])
{

    for (int i = 0; i < argc; i++) // выводим построчно входные данные
    {
        printf("%d. %s\n", i+1, argv[i]);
    }

    printf("\n\n\n\n");
    if (argc < 2) // при отсутствии адреса файла
    {
        printf("First argument after adress of proj - file adress, than separator\n");
        return 0; // завершаем
    }

    printf("Separator: ");

    for (int i = 0; i < (argc - 2); i++)
    {
        printf("%s", argv[i + 2]);
    }

    printf("\n");

    FILE* txt = fopen(argv[1], "r"); // открываем файл

    if (txt == NULL) 
    {
        printf("Error opening file, check arguments or file path\n");
        return 0; 
    }

    char symbol ; // текущий символ
    int cnt = 0; // счетчик слов
    int separator_flag = 0; //флаг поиска разделителя

    do
    {
        if (separator_flag == 1) // разделитель был найден
        {
         
            printf("#%i ", cnt); // вывод номера слова
            separator_flag = 0; 
        }

        symbol = getc(txt); // получаем новый символ
        for (int i = 0; i < (argc - 2); i++) // сверяем его с разделителями
        {
            (symbol == argv[i + 2][0]) ? (separator_flag = 1) : (separator_flag = 0); // совпало 0, не совпало 1
            if (separator_flag == 1) // если совпало, дальше не проверяем
            {
                break;
            }
        }

        if (separator_flag != 1 && symbol != '\n'  && symbol != EOF) // не разделитель?: выводим текущий символ
        {
          
            printf("%c", symbol);
        }

        if (separator_flag == 1) // если текущий символ разделитель
        {
            printf("  ");
            cnt++; 
        }
        if (symbol == '\n') printf("\n"); // чтобы слова соответсвовали строкам на которых они находятся
    } while ((symbol) != EOF);

    printf("\n");
    return 0;
}