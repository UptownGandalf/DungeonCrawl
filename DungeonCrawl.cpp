// DungeonCrawl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Maps.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
using namespace std;

Maps maps;

int gameSpeed = 50;
char dock[20][20] = {
	"###################",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 O",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#        W        #",
	"###################" };
bool gameOver = false;

void LoadNewMap()
{
	system("CLS");
	cout << "Loading..." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	maps.Dungeon2();
}

int main()
{
	while (gameOver == false)
	{
		system("CLS");
		for (int y = 0; y < 20; y++)
		{
			cout << dock[y] << endl;
		}
			for (int y = 0; y < 20; y++)
			{
				for (int x = 0; x < 20; x++)
				{
					switch (dock[y][x])
					{
					case 'W':
						if (GetAsyncKeyState(VK_LEFT) != 0)
						{
							int newX = x - 1;
							switch (dock[y][newX])
							{
							case ' ':
								dock[y][x] = ' ';
								x--;
								dock[y][newX] = 'W';
								break;
							case 'O':
								LoadNewMap();
								break;
							}
						}
						if (GetAsyncKeyState(VK_RIGHT) != 0)
						{
							int newX = x + 1;
							switch (dock[y][newX])
							{
							case ' ':
								dock[y][x] = ' ';
								x++;
								dock[y][newX] = 'W';
								break;
							case 'O':
								LoadNewMap();
								break;
							}
						}
						if (GetAsyncKeyState(VK_UP) != 0)
						{
							int newY = y - 1;
							switch (dock[newY][x])
							{
							case ' ':
								dock[y][x] = ' ';
								y--;
								dock[newY][x] = 'W';
								break;
							case 'O':
								LoadNewMap();
								break;
							}
						}
						if (GetAsyncKeyState(VK_DOWN) != 0)
						{
							int newY = y + 1;
							switch (dock[newY][x])
							{
							case ' ':
								dock[y][x] = ' ';
								y++;
								dock[newY][x] = 'W';
								break;
							case 'O':
								LoadNewMap();
								break;
							}
						}
						break;
					}
				}
				
			}
		Sleep(gameSpeed);
	}
    return 0;
}

