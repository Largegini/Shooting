#pragma once
const int Scene_Logo = 0;
const int Scene_Menu = 1;
const int Scene_Stage = 2;
const int Scene_Exit = 3;
const int Scene_End = 4;

static int Scene_State = 0;
static int StageState = 0;

void SceneManager(DrawTextInfo* CPosition, Object* MenuCursor, Object* StageCursor, const int _SceneState);
void Logo();
void Menu(DrawTextInfo* _DrawTextInfo, Object* _Object);
void Stage(Object* StageCursor);
void End();

void PlayStage(const int StageNum);
int ShowPlayStage();

void SetCursorPosition(const float _x, const float _y);
void OnDrawText(Object* _Object, const char* _str, const float _x, const float _y, const int _Color = 15);
void OnDrawText(Object* _Object, const int _Value, const float _x, const float _y, const int _Color = 15);
void UpdateInput(Object* _Object);
void Initialize(Object* _Object, char* _Texture, const float _PosX, const float _PosY, const float _PosZ = 0);

char* SetName();
float GetMidleWidth(const char* _str);

void HideCursor(bool _Visible);

//	***	매개변수 관리법 물어보기
void SceneManager(DrawTextInfo* CPosition, Object* MenuCursor, Object* StageCursor, const int _SceneState)
{
	switch (_SceneState)
	{
	case Scene_Logo :
		Logo();
		Scene_State++;
		break;
	case Scene_Menu :
		Menu(CPosition, MenuCursor);
		break;
	case Scene_Stage :
		Stage(StageCursor);
		break;
	case Scene_Exit :
		exit(NULL);
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

void Menu(DrawTextInfo* _DrawTextInfo, Object* _Object)
{
	bool Blank = 0;
	for (int i = 0; i < 4; ++i)
	{
		
		OnDrawText(nullptr, (char*)"       '..:", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y);
		OnDrawText(nullptr, (char*)"     '     '", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 1);
		OnDrawText(nullptr, (char*)"  `          .", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 2);
		OnDrawText(nullptr, (char*)";.            '", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 3);
		OnDrawText(nullptr, (char*)";............,     ,``;", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 4);
		OnDrawText(nullptr, (char*)"                 '      ;", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 5);
		OnDrawText(nullptr, (char*)"               ,.        ...:", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 6);
		OnDrawText(nullptr, (char*)"            ,                ,", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 7);
		OnDrawText(nullptr, (char*)"            ;                  .,", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 8);
		OnDrawText(nullptr, (char*)"            .                   :", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 9);
		OnDrawText(nullptr, (char*)"              ;````,,,,,,,,,;;; ", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 10);
	}

	float Width = GetMidleWidth((char*)" __   __  __    _  _______  ___   _______  ___      _______  ______  ");
	float Height = 15.0f;

	OnDrawText(nullptr, (char*)" __   __  __    _  _______  ___   _______  ___      _______  ______  ", Width, Height);
	OnDrawText(nullptr, (char*)"|  | |  ||  |  | ||       ||   | |       ||   |    |       ||      | ", Width, Height+1);
	OnDrawText(nullptr, (char*)"|  | |  ||   |_| ||_     _||   | |_     _||   |    |    ___||  _    |", Width, Height+2);
	OnDrawText(nullptr, (char*)"|  |_|  ||       |  |   |  |   |   |   |  |   |    |   |___ | | |   |", Width, Height+3);
	OnDrawText(nullptr, (char*)"|       ||  _    |  |   |  |   |   |   |  |   |___ |    ___|| |_|   |", Width, Height+4);
	OnDrawText(nullptr, (char*)"|       || | |   |  |   |  |   |   |   |  |       ||   |___ |       |", Width, Height+5);
	OnDrawText(nullptr, (char*)"|_______||_|  |__|  |___|  |___|   |___|  |_______||_______||______| ", Width, Height+6);

	Width = GetMidleWidth((char*)"게임 시작");
	OnDrawText(nullptr, (char*)"게임 시작", Width, Height + 10);
	OnDrawText(nullptr, (char*)"게임 종료", Width, Height + 12);

	_Object->TransInfo.Position.x = (Width + strlen("게임 시작"));
	if (GetAsyncKeyState(VK_UP))
	{
		if(_Object->TransInfo.Position.y > 25.0f)
			_Object->TransInfo.Position.y -= 2;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (_Object->TransInfo.Position.y < 27.0f)
			_Object->TransInfo.Position.y += 2;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (_Object->TransInfo.Position.y == 25.0f)
			++Scene_State;
		else
			Scene_State = Scene_Exit;
	}
	OnDrawText(_Object, _Object->Info.Texture, _Object->TransInfo.Position.x, _Object->TransInfo.Position.y);

	Blank = rand() % 2;
	Width = GetMidleWidth((char*)"Press Sapce to Select!");
	if(Blank  == 0)
		OnDrawText(nullptr, (char*)"Press Sapce to Select!", Width, Height + 14.0f, 8);
	else
		OnDrawText(nullptr, (char*)"Press Sapce to Select!", Width, Height + 14.0f, 15);
}

void Stage(Object* StageCursor)
{
	
	float Width = 0;
	int StageNum = 0;
	if (StageState == 0) //	오프닝 스킵유무 확인
	{
		Width = GetMidleWidth((char*)"오프닝을 스킵합니까?");
		OnDrawText(nullptr, (char*)"오프닝을 스킵합니까?", Width, 25.0f);
		OnDrawText(nullptr, (char*)"예", 50.0f, 27.0f);
		OnDrawText(nullptr, (char*)"아니오", 60.0f, 27.0f);
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (StageCursor->TransInfo.Position.x > 50.0f)
				StageCursor->TransInfo.Position.x = 50.0f + (float)strlen("예");
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (StageCursor->TransInfo.Position.x < 60.0f + (float)strlen("아니오"))
				StageCursor->TransInfo.Position.x = 60.0f + (float)strlen("아니오");
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (StageCursor->TransInfo.Position.x == 60.0f + (float)strlen("아니오"))
				++StageState;
			else if (StageCursor->TransInfo.Position.x = 50.0f + (float)strlen("예"))
				StageState = 2;
		}
		OnDrawText(StageCursor, StageCursor->Info.Texture, StageCursor->TransInfo.Position.x, StageCursor->TransInfo.Position.y);
	}
	else if (StageState == 1) //	오프닝
	{
		OnDrawText(nullptr, (char*)"Intro", Width, 25.0f);
		OnDrawText(nullptr, (char*)"Press Sapce", Width, 27.0f);
		if (GetAsyncKeyState(VK_SPACE))
		{
			++StageState;
		}
	}
	else if (StageState == 2)	// 스테이지 확인
	{
		StageNum = ShowPlayStage();
		PlayStage(StageNum);
	}
}

void End()
{

}

void PlayStage(const int StageNum)
{

}

int ShowPlayStage()
{
	int StageNum = 0;
	float Width = 5.0f;
	float Height = 40.0f;
	OnDrawText(nullptr, (char*)"     @     ", Width, Height, 2);
	OnDrawText(nullptr, (char*)"    @@@    ",Width, Height+1.0f, 2);
	OnDrawText(nullptr, (char*)"   #@@@@   ",Width, Height+2.0f, 2);
	OnDrawText(nullptr, (char*)"   @@@@@,  ",Width, Height+3.0f, 2);
	OnDrawText(nullptr, (char*)"  @@@@@@@  ",Width, Height+4.0f, 2);
	OnDrawText(nullptr, (char*)"  @@@@@@@  ",Width, Height+5.0f, 2);
	OnDrawText(nullptr, (char*)" @@@@@@@@@ ",Width, Height+6.0f, 2);
	OnDrawText(nullptr, (char*)" @@@@@@@@@,",Width, Height+7.0f, 2);
	OnDrawText(nullptr, (char*)"    !@@    ",Width, Height+8.0f, 4);
	OnDrawText(nullptr, (char*)"    !@@    ",Width, Height+9.0f, 4);
	OnDrawText(nullptr, (char*)"    !@@    ",Width, Height+10.0f, 4);

	OnDrawText(nullptr, (char*)"     @     ", Width+10.0f, (Height-5.0f), 2);
	OnDrawText(nullptr, (char*)"    @@@    ", Width+10.0f, (Height-5.0f) + 1.0f, 2);
	OnDrawText(nullptr, (char*)"   #@@@@   ", Width+10.0f, (Height-5.0f) + 2.0f, 2);
	OnDrawText(nullptr, (char*)"   @@@@@,  ", Width+10.0f, (Height-5.0f) + 3.0f, 2);
	OnDrawText(nullptr, (char*)"  @@@@@@@  ", Width+10.0f, (Height-5.0f) + 4.0f, 2);
	OnDrawText(nullptr, (char*)"  @@@@@@@  ", Width+10.0f, (Height-5.0f) + 5.0f, 2);
	OnDrawText(nullptr, (char*)" @@@@@@@@@ ", Width+10.0f, (Height-5.0f) + 6.0f, 2);
	OnDrawText(nullptr, (char*)" @@@@@@@@@,", Width+10.0f, (Height-5.0f) + 7.0f, 2);
	OnDrawText(nullptr, (char*)"    !@@    ", Width+10.0f, (Height-5.0f) + 8.0f, 4);
	OnDrawText(nullptr, (char*)"    !@@    ", Width+10.0f, (Height-5.0f) + 9.0f, 4);
	OnDrawText(nullptr, (char*)"    !@@    ", Width+10.0f, (Height-5.0f) + 10.0f, 4);

	return StageNum;
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

void UpdateInput(Object* _Object)
{
	if (GetAsyncKeyState(VK_UP))
		_Object->TransInfo.Position.y -= 1;
	if (GetAsyncKeyState(VK_DOWN))
		_Object->TransInfo.Position.y -= 1;
	if (GetAsyncKeyState(VK_LEFT))
		_Object->TransInfo.Position.y -= 1;
	if (GetAsyncKeyState(VK_RIGHT))
		_Object->TransInfo.Position.y -= 1;
}

void Initialize(Object* _Object, char* _Texture, const float _PosX, const float _PosY, const float _PosZ)
{
	_Object->Info.Texture = (_Texture == nullptr) ? SetName() : _Texture;

	_Object->TransInfo.Position = Vector3 (_PosX, _PosY, _PosZ);
	_Object->TransInfo.Rotation = Vector3 (0, 0, 0);
	_Object->TransInfo.Scale = Vector3 ((float)(strlen(_Object->Info.Texture)), 1, 0);

}

char* SetName()
{
	char Buffer[128] = "";
	char* pName = new char[strlen(Buffer) + 1];

	cout << "이름을 입력하세요 : ";	cin >> Buffer;
	strcpy(pName, Buffer);

	return pName;
}

float GetMidleWidth(const char* _str)
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