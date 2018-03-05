#include "stdafx.h"
#include "Maps.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
using namespace std;

bool mapRunning = true;
int refreshSpeed = 50;

char dungeon2[15][20] = {
	"###################",
	"#                 #",
	"#                 #",
	"#                 #",
	"# W               #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#           Z     #",
	"#                 #",
	"###################",
};

void Combat()
{
	system("CLS");
	cout << "Launching combat..." << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	//combat code
}
void LoadThirdMap()
{
	//third map code
}

void Maps::Dungeon2()
{
	while (mapRunning == true)
	{
		system("CLS");
		for (int y = 0; y < 20; y++)
		{
			cout << dungeon2[y] << endl;
		}

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				switch (dungeon2[y][x])
				{
				case 'W':
					if (GetAsyncKeyState(VK_LEFT) != 0)
					{
						int newX = x - 1;
						switch (dungeon2[y][newX])
						{
						case ' ':
							dungeon2[y][x] = ' ';
							x--;
							dungeon2[y][newX] = 'W';
							break;
						case 'O': 
							LoadThirdMap();
							break;
						case 'Z':
							Combat();
							break;
						}
					}
					if (GetAsyncKeyState(VK_RIGHT) != 0)
					{
						int newX = x + 1;
						switch (dungeon2[y][newX])
						{
						case ' ':
							dungeon2[y][x] = ' ';
							x++;
							dungeon2[y][newX] = 'W';
							break;
						case 'O':
							LoadThirdMap();
							break;
						case 'Z':
							Combat();
							break;
						}
					}
					if (GetAsyncKeyState(VK_UP) != 0)
					{
						int newY = y - 1;
						switch (dungeon2[newY][x])
						{
						case ' ':
							dungeon2[y][x] = ' ';
							y--;
							dungeon2[newY][x] = 'W';
							break;
						case 'O':
							LoadThirdMap();
							break;
						case 'Z':
							Combat();
							break;
						}
					}
					if (GetAsyncKeyState(VK_DOWN) != 0)
					{
						int newY = y + 1;
						switch (dungeon2[newY][x])
						{
						case ' ':
							dungeon2[y][x] = ' ';
							y++;
							dungeon2[newY][x] = 'W';
							break;
						case 'O':
							LoadThirdMap();
							break;
						case 'Z':
							Combat();
							break;
						}
					}
				}
			}
		}
		Sleep(refreshSpeed);
	}

}

// so on and so forth 