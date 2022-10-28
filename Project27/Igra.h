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
            cout << "������: " << HP << endl;
            if (HP <= 0)
            {
                cout << "\n ��� �������� \n";
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
                cout << "\n �� �������� \n";
                Sleep(2000);
                return;
            }
            cout << "\n�������������� �����: " << playersym;
            cout << "\n\n������� ������: ";
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
        cout << "������ ���� - 1 \n������ ������� - 2\n";
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
            cout << (time(0) - start_time) / 60 << " ����� ";
        }
        cout << (time(0) - start_time) % 60 << " ������\n";
        Print();
    }
    void Print()
    {
        cout << "���������� ������������ �������: " << popitki << endl;
        cout << "����� ������� �� ������: " << randomword << endl;
        cout << "����� �������� �������: " << playersym << endl;
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
                cout << "��� ������ �����\n";
                Sleep(5000);
                system("cls");
            }
        }
    }
    void Rule()
    {
        cout << "���� �������� (�������) ���������� ����� � ������ �� ����� ����� ���������� �������������, ������� ���� � ����� (������, �������� ����� ������������ �������� ����� ��� ���� � ��������).\n";
        cout << "���� ����� ���� � �����, �� ������� ������ ������� � �� ��� ����� � ����� (���� ����� ���� ��������� � �� ����������� ���\n";
        cout << "� ���� ��� � �� �� ������ ���� ������� �������� � ���������� (������, �����������, ��������, ������, ������, ��������, 2 ����, 2 ���� � ����� 10 ���������-�������).\n";
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