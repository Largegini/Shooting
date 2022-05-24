#pragma once
const int Scene_Logo = 0;
const int Scene_Menu = 1;
const int Scene_Stage = 2;
const int Scene_Exit = 3;
const int Scene_End = 4;

static int Scene_State = 0;

void SceneManager(int _SceneState);
void Logo();
void Menu();
void End();

void SetCursorPosition(const float _x, const float _y);
void OnDrawText(Object* _Object, const char* _str, const float _x, const float _y, const int _Color = 15);
void OnDrawText(Object* _Object, const int _Value, const float _x, const float _y, const int _Color = 15);
float GetWidth(char* _str);
void HideCursor(bool _Visible);

void SceneManager(int _SceneState)
{
	switch (_SceneState)
	{
	case Scene_Logo :
		Logo();
		Scene_State++;
		break;
	case Scene_Menu :
		Menu();
		break;
	}
}

void Logo()
{
	float Width = (float)(60 - (strlen("LLLLLLLLLLL                              BBBBBBBBBBBBBBBBB                         ") / 2));
	float Height = 15.0f;

	OnDrawText(nullptr, (char*)"LLLLLLLLLLL                              BBBBBBBBBBBBBBBBB                         ", Width, Height);
	OnDrawText(nullptr, (char*)"L:::::::::L                              B::::::::::::::::B                        ", Width, Height+1.0f);
	OnDrawText(nullptr, (char*)"L:::::::::L                              B::::::BBBBBB:::::B                       ", Width, Height+2.0f);
	OnDrawText(nullptr, (char*)"LL:::::::LL                              BB:::::B     B:::::B                      ", Width, Height+3.0f);
	OnDrawText(nullptr, (char*)"  L:::::L                  ooooooooooo     B::::B     B:::::B   ooooooooooo        ", Width, Height+4.0f);
	OnDrawText(nullptr, (char*)"  L:::::L                oo:::::::::::oo   B::::B     B:::::B oo:::::::::::oo      ", Width, Height+5.0f);
	OnDrawText(nullptr, (char*)"  L:::::L               o:::::::::::::::o  B::::BBBBBB:::::B o:::::::::::::::o     ", Width, Height+6.0f);
	OnDrawText(nullptr, (char*)"  L:::::L               o:::::ooooo:::::o  B:::::::::::::BB  o:::::ooooo:::::o     ", Width, Height+7.0f);
	OnDrawText(nullptr, (char*)"  L:::::L               o::::o     o::::o  B::::BBBBBB:::::B o::::o     o::::o     ", Width, Height+8.0f);
	OnDrawText(nullptr, (char*)"  L:::::L               o::::o     o::::o  B::::B     B:::::Bo::::o     o::::o     ", Width, Height+9.0f);
	OnDrawText(nullptr, (char*)"  L:::::L               o::::o     o::::o  B::::B     B:::::Bo::::o     o::::o     ", Width, Height+10.0f);
	OnDrawText(nullptr, (char*)"  L:::::L         LLLLLLo::::o     o::::o  B::::B     B:::::Bo::::o     o::::o     ", Width, Height+11.0f);
	OnDrawText(nullptr, (char*)"LL:::::::LLLLLLLLL:::::Lo:::::ooooo:::::oBB:::::BBBBBB::::::Bo:::::ooooo:::::o     ", Width, Height+12.0f);
	OnDrawText(nullptr, (char*)"L::::::::::::::::::::::Lo:::::::::::::::oB:::::::::::::::::B o:::::::::::::::o     ", Width, Height+13.0f);
	OnDrawText(nullptr, (char*)"L::::::::::::::::::::::L oo:::::::::::oo B::::::::::::::::B   oo:::::::::::oo      ", Width, Height+14.0f);
	OnDrawText(nullptr, (char*)"LLLLLLLLLLLLLLLLLLLLLLLL   ooooooooooo   BBBBBBBBBBBBBBBBB      ooooooooooo        ", Width, Height+15.0f);
	Sleep(2500);
}

void Menu()
{

	OnDrawText(nullptr, (char*)"       '..:                         ", rand()% 90, rand()% 
	OnDrawText(nullptr, (char*)"     '     '                        ", rand()% 90, rand()% 
	OnDrawText(nullptr, (char*)"  `          .                      ", rand()% 90, rand()% 
	OnDrawText(nullptr, (char*)";.            '                     ", rand()% 90, rand()% 
	OnDrawText(nullptr, (char*)";............,     ,``;             ", rand()% 90, rand()% 
	OnDrawText(nullptr, (char*)"                 '      ;           ", rand()% 90, rand()% 
	OnDrawText(nullptr, (char*)"               ,.        ...:       ", rand()% 90, rand()% 
	OnDrawText(nullptr, (char*)"            ,                ,      ", rand()% 90, rand()% 
	OnDrawText(nullptr, (char*)"            ;                  .,   ", rand()% 90, rand()% 
	OnDrawText(nullptr, (char*)"            .                   :   ", rand()% 90, rand()% 
	OnDrawText(nullptr, (char*)"              ;````,,,,,,,,,;;;     ", rand()% 90, rand()% 
	float Width = GetWidth((char*)" __   __  __    _  _______  ___   _______  ___      _______  ______  ");
	float Height = 15.0f;

	OnDrawText(nullptr, (char*)" __   __  __    _  _______  ___   _______  ___      _______  ______  ", Width, Height);
	OnDrawText(nullptr, (char*)"|  | |  ||  |  | ||       ||   | |       ||   |    |       ||      | ", Width, Height+1);
	OnDrawText(nullptr, (char*)"|  | |  ||   |_| ||_     _||   | |_     _||   |    |    ___||  _    |", Width, Height+2);
	OnDrawText(nullptr, (char*)"|  |_|  ||       |  |   |  |   |   |   |  |   |    |   |___ | | |   |", Width, Height+3);
	OnDrawText(nullptr, (char*)"|       ||  _    |  |   |  |   |   |   |  |   |___ |    ___|| |_|   |", Width, Height+4);
	OnDrawText(nullptr, (char*)"|       || | |   |  |   |  |   |   |   |  |       ||   |___ |       |", Width, Height+5);
	OnDrawText(nullptr, (char*)"|_______||_|  |__|  |___|  |___|   |___|  |_______||_______||______| ", Width, Height+6);

	Width = GetWidth((char*)"게임 시작");
	OnDrawText(nullptr, (char*)"게임 시작", Width, Height + 10);
	OnDrawText(nullptr, (char*)"게임 종료", Width, Height + 12);

}

void End()
{

}

void SetCursorPosition(const float _x, const float _y)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetTextColor(const int _Color)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}

void OnDrawText(Object* _Object, const char* _str, const float _x, const float _y, const int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);
	cout << _str;
}

void OnDrawText(Object* _Object, const int _Value, const float _x, const float _y, const int _Color)
{
	char* pText = new char[4];

	SetCursorPosition(_x, _y);
	SetTextColor(_Color);

	_itoa(_Value, pText, 10);
	cout << _Value;
}

float GetWidth(char* _str)
{
	float Width = (float)(60 - (strlen(_str) / 2));

	return Width;
}
void HideCursor(bool _Visible)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	CursorInfo.bVisible = _Visible;
	CursorInfo.dwSize = 1;

	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}