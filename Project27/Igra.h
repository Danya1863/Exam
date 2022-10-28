#pragma once
#include <iostream>
#include <fstream>
#include "Windows.h"
using namespace std;

class Igra
{
    int popitki;
    string randomword;
    string playersym;
public:
    Igra()
    {
        popitki = 0;
        randomword = playersym = "";
    }
    Igra(int count) :Igra()
    {
        ifstream file;
        file.open("Game.txt");
        int words = count;
        int c = rand() % (1 - words) + 1;
        for (int i = 0; i < c; i++)
        {
            char buf[300];
            file.getline(buf, 300);
            randomword = string(buf);
        }
        file.close();
    }
    void Play()
    {
        int HP = 5, test = 0;
        for (;;)
        {
            system("cls");
            cout << "Жизней: " << HP << endl;
            if (HP <= 0)
            {
                cout << "\n Вас повесили \n";
                Sleep(2000);
                return;
            }
            char player;
            char buf[255];
            strcpy(buf, randomword.c_str());
            cout << endl;
            for (int i = 0; i < randomword.size(); i++)
            {
                if (playersym.find(buf[i]) != -1)
                    cout << randomword[i];
                if (i != randomword.size() - 1)
                {
                    cout << "|";
                }
            }
            cout << endl;
            if (test == randomword.length())
            {
                cout << "\n Вы выиграли \n";
                Sleep(2000);
                return;
            }
            cout << "\nИспользованные буквы: " << playersym;
            cout << "\n\nВведите символ: ";
            cin >> player;
            if (randomword.find(player) != -1)
            {
                playersym += player;
                playersym += " ";
                for (int j = 0; j < randomword.size(); j++)
                {
                    if (randomword[j] == player)
                        test++;
                }
            }
            else
            {
                playersym += player;
                playersym += " ";
                popitki++;
                HP--;
            }
        }
    }
    int start()
    {
        cout << "Начать игру - 1 \nУзнать правила - 2\n";
        int temp;
        cin >> temp;
        return temp;
    }
    void start_game()
    {
        time_t start_time = time(0);
        Play();
        cout << endl;
        if ((time(0) - start_time) >= 60)
        {
            cout << (time(0) - start_time) / 60 << " Минут ";
        }
        cout << (time(0) - start_time) % 60 << " Секунд\n";
        Print();
    }
    void Print()
    {
        cout << "Количество неправильных попыток: " << popitki << endl;
        cout << "Слово которое мы искали: " << randomword << endl;
        cout << "Буквы введеные игроком: " << playersym << endl;
    }
    void menu()
    {
        while (true)
        {
            int temp = start();
            if (temp == 1)
            {
                start_game();
                break;
            }
            else if (temp == 2)
            {
                Rule();
            }
            else
            {
                cout << "Нет данной опции\n";
                Sleep(5000);
                system("cls");
            }
        }
    }
    void Rule()
    {
        cout << "Один участник (водящий) загадывает слово и рисует на листе такое количество подчёркиваний, сколько букв в слове (кстати, желающие могут использовать дорожный набор для игры в Виселицу).\n";
        cout << "Если буква есть в слове, то водящий обязан вписать её на своё место в слово (если таких букв несколько — то вписываются все\n";
        cout << "А если нет — то он рисует один элемент виселицы с человечком (стойка, перекладина, распорка, верёвка, голова, туловище, 2 руки, 2 ноги — всего 10 элементов-попыток).\n";
        system("pause");
        system("cls");
    }
}; 
int Words()
{
    ifstream file;
    file.open("Game.txt");
    int co = 0;
    do
    {
        char temp[255];
        file.getline(temp, 255);
        if (!strstr(temp, "\n"))
        {
            co++;
        }
    } while (file);
    file.close();
    return co;
}