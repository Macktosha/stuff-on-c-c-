#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//C:\Users\�����\source\repos\highlvl7\Debug\highlvl7.exe C:\Users\�����\source\repos\highlvl7\source.txt
//��� ���� ��� ������� ������� � ��������� ������
    

int main(int argc, const char* argv[])
{

    for (int i = 0; i < argc; i++) // ������� ��������� ������� ������
    {
        printf("%d. %s\n", i+1, argv[i]);
    }

    printf("\n\n\n\n");
    if (argc < 2) // ��� ���������� ������ �����
    {
        printf("First argument after adress of proj - file adress, than separator\n");
        return 0; // ���������
    }

    printf("Separator: ");

    for (int i = 0; i < (argc - 2); i++)
    {
        printf("%s", argv[i + 2]);
    }

    printf("\n");

    FILE* txt = fopen(argv[1], "r"); // ��������� ����

    if (txt == NULL) 
    {
        printf("Error opening file, check arguments or file path\n");
        return 0; 
    }

    char symbol ; // ������� ������
    int cnt = 0; // ������� ����
    int separator_flag = 0; //���� ������ �����������

    do
    {
        if (separator_flag == 1) // ����������� ��� ������
        {
         
            printf("#%i ", cnt); // ����� ������ �����
            separator_flag = 0; 
        }

        symbol = getc(txt); // �������� ����� ������
        for (int i = 0; i < (argc - 2); i++) // ������� ��� � �������������
        {
            (symbol == argv[i + 2][0]) ? (separator_flag = 1) : (separator_flag = 0); // ������� 0, �� ������� 1
            if (separator_flag == 1) // ���� �������, ������ �� ���������
            {
                break;
            }
        }

        if (separator_flag != 1 && symbol != '\n'  && symbol != EOF) // �� �����������?: ������� ������� ������
        {
          
            printf("%c", symbol);
        }

        if (separator_flag == 1) // ���� ������� ������ �����������
        {
            printf("  ");
            cnt++; 
        }
        if (symbol == '\n') printf("\n"); // ����� ����� �������������� ������� �� ������� ��� ���������
    } while ((symbol) != EOF);

    printf("\n");
    return 0;
}