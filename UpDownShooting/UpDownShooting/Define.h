#pragma once
const int Scene_Logo = 0;
const int Scene_Menu = 1;
const int Scene_Stage = 2;
const int Scene_Exit = 3;
const int Scene_End = 4;
const int Scene_GameOver = 5;

void SceneManager(DrawTextInfo* CPosition, Object* MenuCursor,
	Object* StageCursor, Object* Player, Object* Enemy[],
	Object* PBullet[], Object* Item[], Vector3 Direction[],
	System* System);
void Logo();
void Menu(DrawTextInfo* _DrawTextInfo, Object* _Object, System* _System);
void Stage(Object* StageCursor, Object* Player, Object* Enemy[],
	Object* PBullet[], Object* Item[], Vector3 _Direction[],
	System* _System);
void End();
void GameOver();

void PlayStage(Object* Player, Object* Enemy[], Object* PBullet[], 
	Object* Item[],	Vector3 Direction[], System* _System, 
	const int StageNum);
int ShowPlayStage(Object* Player, System* System);

void SetCursorPosition(const float _x, const float _y);
void OnDrawText(const char* _str, const float _x, const float _y, const int _Color = 15);
void OnDrawText(const int _Value, const float _x, const float _y, const int _Color = 15);
void UpdateInput(Object* _Object);
void Initialize(Object* _Object, char* _Texture, const int _MaxHP,
	const int HP, const float _PosX, const float _PosY,
	const float _PosZ = 0);

bool Collision(Object* ObjectA, Object* ObjectB);
char* SetName();
float GetMidleWidth(const char* _str);
float GetDistance(const Object* ObjectA, const Object* ObjectB);

Vector3 GetDirection(const Object* ObjectA, const Object* ObjectB);
Object* CreateEnemy(const float _x, const float _y);
Object* CreateBullet(const float _x, const float _y,const int _Power,
	const int Option);
Object* CreateItem(const float _x, const float _y);
Object* CreateEnemy(const float _x, const float _y);

void DrawTree(const float Width, const float Height, const float _x = 0, const float _y = 0);
void DrawMountain(const float Width, const float Height, const float _x = 0, const float _y = 0);
void DrawCloud(const float Width, const float Height, const float _x = 0, const float _y = 0);
void DrawCircle(const float Width, const float Height, const float _x = 0, const float _y= 0);

void HideCursor(bool _Visible);

//	***	매개변수 관리법 물어보기
void SceneManager(DrawTextInfo* CPosition, Object* MenuCursor,
	Object* StageCursor, Object* Player, Object* Enemy[],
	Object* PBullet[], Object* Item[], Vector3 Direction[],
	System* _System)
{
	switch (_System->Scene_State)
	{
	case Scene_Logo :
		Logo();
		_System->Scene_State++;
		break;
	case Scene_Menu :
		Menu(CPosition, MenuCursor, _System);
		break;
	case Scene_Stage :
		Stage(StageCursor, Player, Enemy, PBullet, Item, Direction, _System);
		break;
	case Scene_Exit :
		exit(NULL);
		break;
	case Scene_GameOver:
		GameOver();
		break;
	}
}

void Logo()
{
	float Width = (float)(60 - (strlen("LLLLLLLLLLL                              BBBBBBBBBBBBBBBBB                         ") / 2));
	float Height = 15.0f;

	OnDrawText((char*)"LLLLLLLLLLL                              BBBBBBBBBBBBBBBBB                         ", Width, Height);
	OnDrawText((char*)"L:::::::::L                              B::::::::::::::::B                        ", Width, Height+1.0f);
	OnDrawText((char*)"L:::::::::L                              B::::::BBBBBB:::::B                       ", Width, Height+2.0f);
	OnDrawText((char*)"LL:::::::LL                              BB:::::B     B:::::B                      ", Width, Height+3.0f);
	OnDrawText((char*)"  L:::::L                  ooooooooooo     B::::B     B:::::B   ooooooooooo        ", Width, Height+4.0f);
	OnDrawText((char*)"  L:::::L                oo:::::::::::oo   B::::B     B:::::B oo:::::::::::oo      ", Width, Height+5.0f);
	OnDrawText((char*)"  L:::::L               o:::::::::::::::o  B::::BBBBBB:::::B o:::::::::::::::o     ", Width, Height+6.0f);
	OnDrawText((char*)"  L:::::L               o:::::ooooo:::::o  B:::::::::::::BB  o:::::ooooo:::::o     ", Width, Height+7.0f);
	OnDrawText((char*)"  L:::::L               o::::o     o::::o  B::::BBBBBB:::::B o::::o     o::::o     ", Width, Height+8.0f);
	OnDrawText((char*)"  L:::::L               o::::o     o::::o  B::::B     B:::::Bo::::o     o::::o     ", Width, Height+9.0f);
	OnDrawText((char*)"  L:::::L               o::::o     o::::o  B::::B     B:::::Bo::::o     o::::o     ", Width, Height+10.0f);
	OnDrawText((char*)"  L:::::L         LLLLLLo::::o     o::::o  B::::B     B:::::Bo::::o     o::::o     ", Width, Height+11.0f);
	OnDrawText((char*)"LL:::::::LLLLLLLLL:::::Lo:::::ooooo:::::oBB:::::BBBBBB::::::Bo:::::ooooo:::::o     ", Width, Height+12.0f);
	OnDrawText((char*)"L::::::::::::::::::::::Lo:::::::::::::::oB:::::::::::::::::B o:::::::::::::::o     ", Width, Height+13.0f);
	OnDrawText((char*)"L::::::::::::::::::::::L oo:::::::::::oo B::::::::::::::::B   oo:::::::::::oo      ", Width, Height+14.0f);
	OnDrawText((char*)"LLLLLLLLLLLLLLLLLLLLLLLL   ooooooooooo   BBBBBBBBBBBBBBBBB      ooooooooooo        ", Width, Height+15.0f);
	Sleep(2500);
}

void Menu(DrawTextInfo* _DrawTextInfo, Object* _Object, System* _System)
{
	bool Blank = 0;
	for (int i = 0; i < 4; ++i)
	{
		
		OnDrawText((char*)"       '..:", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y);
		OnDrawText((char*)"     '     '", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 1);
		OnDrawText((char*)"  `          .", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 2);
		OnDrawText((char*)";.            '", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 3);
		OnDrawText((char*)";............,     ,``;", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 4);
		OnDrawText((char*)"                 '      ;", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 5);
		OnDrawText((char*)"               ,.        ...:", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 6);
		OnDrawText((char*)"            ,                ,", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 7);
		OnDrawText((char*)"            ;                  .,", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 8);
		OnDrawText((char*)"            .                   :", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 9);
		OnDrawText((char*)"              ;````,,,,,,,,,;;; ", _DrawTextInfo[i].TransInfo.Position.x, _DrawTextInfo[i].TransInfo.Position.y + 10);
	}

	float Width = GetMidleWidth((char*)" __   __  __    _  _______  ___   _______  ___      _______  ______  ");
	float Height = 15.0f;

	OnDrawText((char*)" __   __  __    _  _______  ___   _______  ___      _______  ______  ", Width, Height);
	OnDrawText((char*)"|  | |  ||  |  | ||       ||   | |       ||   |    |       ||      | ", Width, Height+1);
	OnDrawText((char*)"|  | |  ||   |_| ||_     _||   | |_     _||   |    |    ___||  _    |", Width, Height+2);
	OnDrawText((char*)"|  |_|  ||       |  |   |  |   |   |   |  |   |    |   |___ | | |   |", Width, Height+3);
	OnDrawText((char*)"|       ||  _    |  |   |  |   |   |   |  |   |___ |    ___|| |_|   |", Width, Height+4);
	OnDrawText((char*)"|       || | |   |  |   |  |   |   |   |  |       ||   |___ |       |", Width, Height+5);
	OnDrawText((char*)"|_______||_|  |__|  |___|  |___|   |___|  |_______||_______||______| ", Width, Height+6);

	Width = GetMidleWidth((char*)"게임 시작");
	OnDrawText((char*)"게임 시작", Width, Height + 10);
	OnDrawText((char*)"게임 종료", Width, Height + 12);

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
			++_System->Scene_State;
		else
			_System->Scene_State = Scene_Exit;
	}
	OnDrawText(_Object->Info.Texture, _Object->TransInfo.Position.x, _Object->TransInfo.Position.y);

	Blank = rand() % 2;
	Width = GetMidleWidth((char*)"Press Sapce to Select!");
	if(Blank  == 0)
		OnDrawText((char*)"Press Sapce to Select!", Width, Height + 14.0f, 8);
	else
		OnDrawText((char*)"Press Sapce to Select!", Width, Height + 14.0f, 15);
}

void Stage(Object* StageCursor, Object* Player, Object* Enemy[],
	Object* PBullet[], Object* Item[], Vector3 _Direction[], 
	System* _System)
{
	float Width = 0;
	if (_System->StageState == 0) //	오프닝 스킵유무 확인
	{
		Width = GetMidleWidth((char*)"오프닝을 스킵합니까?");
		OnDrawText((char*)"오프닝을 스킵합니까?", Width, 25.0f);
		OnDrawText((char*)"예", 50.0f, 27.0f);
		OnDrawText((char*)"아니오", 60.0f, 27.0f);
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
				++_System->StageState;
			else if (StageCursor->TransInfo.Position.x = 50.0f + (float)strlen("예"))
				_System->StageState = 2;
		}
		OnDrawText(StageCursor->Info.Texture, StageCursor->TransInfo.Position.x, StageCursor->TransInfo.Position.y);
	}
	else if (_System->StageState == 1) //	오프닝
	{
		OnDrawText((char*)"Intro", Width, 25.0f);
		OnDrawText((char*)"Press Sapce", Width, 27.0f);
		if (GetAsyncKeyState(VK_SPACE))
		{
			++_System->StageState;
		}
	}
	else if (_System->StageState == 2)	// 스테이지 확인
	{
		ShowPlayStage(Player, _System);
		PlayStage(Player, Enemy, PBullet, Item, _Direction, _System, 
			_System->StageNum);
	}
}

void End()
{

}

void GameOver()
{

}

void PlayStage(Object* Player, Object* Enemy[], Object* PBullet[],
	Object* Item[], Vector3 _Direction[], System* _System, 
	const int StageNum)
{
	if (_System->EnemyTime)
	{
		if (_System->EnemyCount < 32)
		{
			for (int i = 0; i < 32; ++i)
			{
				if (Enemy[i] == nullptr)
				{
					srand((GetTickCount() + i * i) * GetTickCount());
					Enemy[i] = CreateEnemy((float)((rand() % 79 + 1)),
						(float)((rand() % 19) + 1));
					_System->EnemyTime = false;
					_System->EnemyCount++;
					break;
				}
			}
		}
	}

	if (_System->EBulletTime)
	{
		srand(GetTickCount() * GetTickCount());

		_System->RandNum = rand() % 32;

		if (Enemy[_System->RandNum] != nullptr)
		{
			for (int i = 0; i < 128; ++i)
			{
				if (PBullet[i] == nullptr)
				{
					PBullet[i] = CreateBullet(
						Enemy[_System->RandNum]->TransInfo.Position.x,
						Enemy[_System->RandNum]->TransInfo.Position.y,
						0, 1+(rand()%2));
					_Direction[i] = GetDirection(Player, PBullet[i]);
					_System->EBulletTime = false;
					break;
				}

			}
		}
	}
	
	
	float Width = 95.0f - (float)strlen("Score:");

	OnDrawText((char*)"Stage  ", Width, 3.0f);
	OnDrawText(_System->StageNum, 110.0f, 3.0f);

	OnDrawText((char*)"Score: ", Width, 5.0f);
	OnDrawText(++_System->Score, 110.0f, 5.0f);

	OnDrawText((char*)"◆", Width, 13.0f, 14);
	OnDrawText((char*)": 일반 총알", Width+2.0f, 13.0f);
	OnDrawText((char*)"플레이어방향으로 날아옵니다.", Width, 14.0f);

	OnDrawText((char*)"▣", Width, 16.0f, 14);
	OnDrawText((char*)": 유도 총알", Width+2.0f, 16.0f);
	OnDrawText((char*)"5초간 플레이어를 따라옵니다.", Width, 17.0f);

	OnDrawText((char*)"PlayerHP", Width, 45.0f);
	for (int i = 0; i < Player->MaxHP; ++i)
	{
		if(i+1<=Player->HP)
			OnDrawText((char*)"♥", Width+(float)(i*2), 46.0f,11);
		else
			OnDrawText((char*)"♡", Width+(float)(i*2), 46.0f,11);
	}
	OnDrawText((char*)"Power Lv.", Width, 50.0f);
	OnDrawText(Player->Power, Width+(float)strlen("Power Lv."), 50.0f);
	OnDrawText((char*)"□□□", Width+20, 51.0f, 6);
	OnDrawText((char*)"□□□□□□", Width+14, 52.0f, 6);
	OnDrawText((char*)"□□□□□□□□", Width+10, 53.0f, 6);


	for(int i = 0; i < 55; ++i)
		OnDrawText((char*)"l", Width - 5.0f, (float)i);

	for (int i = 0; i < 16; ++i)
	{
		if (Item[i])
		{
			if (Item[i]->TransInfo.Position.x > 80.0f)
				Item[i]->TransInfo.Position.x -= 1.0f;
			else if(Item[i]->TransInfo.Position.x < 1.0f)
				Item[i]->TransInfo.Position.x += 1.0f;

			if (Item[i]->TransInfo.Position.y > 55.0f)
				Item[i]->TransInfo.Position.y -= 1.0f;
			else if (Item[i]->TransInfo.Position.y < 1.0f)
				Item[i]->TransInfo.Position.y += 1.0f;

			OnDrawText(Item[i]->Info.Texture, 
				Item[i]->TransInfo.Position.x,
				Item[i]->TransInfo.Position.y, 10);
		}
	}
	UpdateInput(Player);
	
	OnDrawText(Player->Info.Texture, Player->TransInfo.Position.x,
		Player->TransInfo.Position.y, 11);

	for (int i = 0; i < 32; ++i)
	{
		if(Enemy[i])
			OnDrawText(Enemy[i]->Info.Texture, 
				Enemy[i]->TransInfo.Position.x, Enemy[i]->TransInfo.Position.y, 2);
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		for (int i = 0; i < 128; ++i)
		{
			if (PBullet[i] == nullptr)
			{
				PBullet[i] = CreateBullet(Player->TransInfo.Position.x, 
					Player->TransInfo.Position.y, Player->Power, 
					0);
				break;
			}
		}
	}

	for (int i = 0; i < 128; ++i)
	{
		if (PBullet[i])
		{
			switch (PBullet[i]->Info.Option)
			{
				case 0 :
				{
					PBullet[i]->TransInfo.Position.y -= 1;
					OnDrawText(PBullet[i]->Info.Texture,
						PBullet[i]->TransInfo.Position.x,
						PBullet[i]->TransInfo.Position.y,
						11);
					break;
				}

				case 1:
				{
					PBullet[i]->TransInfo.Position.x += _Direction[i].x;
					PBullet[i]->TransInfo.Position.y += _Direction[i].y;
					OnDrawText(PBullet[i]->Info.Texture,
						PBullet[i]->TransInfo.Position.x,
						PBullet[i]->TransInfo.Position.y,
						14);
					break;
				}

				case 2:
				{
					if (_System->EBHomingTime[i] < 50)
					{
						_Direction[i] = GetDirection(Player, PBullet[i]);
						_System->EBHomingTime[i]++;
					}
					
					PBullet[i]->TransInfo.Position.x += _Direction[i].x;
					PBullet[i]->TransInfo.Position.y += _Direction[i].y;

					OnDrawText(PBullet[i]->Info.Texture,
						PBullet[i]->TransInfo.Position.x,
						PBullet[i]->TransInfo.Position.y,
						14);
					break;
				}
			}
		}
	}

	for (int i = 0; i < 128; ++i)
	{
		if (PBullet[i])
		{
			if (PBullet[i]->TransInfo.Position.y < 1.0f ||
				PBullet[i]->TransInfo.Position.y > 55.0f ||
				PBullet[i]->TransInfo.Position.x < 1.0f ||
				PBullet[i]->TransInfo.Position.x >= 80.0f)
			{
				delete PBullet[i];
				PBullet[i] = nullptr;
				_System->EBHomingTime[i] = 0;
				break;
			}
		}
	}

	for (int i = 0; i < 128; ++i)
	{
		if (PBullet[i] != nullptr && PBullet[i]->Info.Option > 0)
		{
			if (Collision(PBullet[i], Player))
			{
				delete PBullet[i];
				PBullet[i] = nullptr;
				Player->HP--;
				_System->EBHomingTime[i] = 0;
				break;
			}
		}
	}

	for (int i = 0; i < 128; ++i)
	{
		if (PBullet[i] != nullptr && PBullet[i]->Info.Option == 0)
		{
			for (int j = 0; j < 32; ++j)
			{
				if (Enemy[j] != nullptr)
				{
					if (Collision(PBullet[i], Enemy[j]))
					{
						delete PBullet[i];
						PBullet[i] = nullptr;

						if (Enemy[j]->Info.Option < 10)
						{
							for (int k = 0; k < 16; ++k)
								Item[k] = CreateItem(Enemy[j]->TransInfo.Position.x,
									Enemy[j]->TransInfo.Position.y);
							break;
						}

						delete Enemy[j];
						Enemy[j] = nullptr;
						

						_System->Score += 10;

						break;
					}
				}
			}
		}
	}
	// 게임오버
	//if (Player->HP <= 0)
	//	_System->Scene_State = Scene_GameOver;
}

int ShowPlayStage(Object* Player, System* _System)
{
	
	if (_System->StageNum == 0)
	{
		float Width = 5.0f;
		float Height = 40.0f;

		//	나무 배경 그리기
		DrawTree(Width, Height);
		DrawTree(Width, Height, 10.0f, 5.0f);
		DrawTree(Width, Height, 90.0f, 18.0f);
		DrawTree(Width, Height, 80.0f, 25.0f);

		//	산	배경 그리기
		DrawMountain(Width, Height, 70.0f, 6.0f);
		DrawMountain(Width, Height, 3.0f, 30.0f);

		//	구름 배경 그리기
		DrawCloud(Width, Height, 70.0f, 35.0f);
		DrawCloud(Width, Height, 5.0f, 40.0f);

		OnDrawText((char*)" $########$   ", (Width + 6.0f), (Height - 18.0f), 12);
		OnDrawText((char*)" @@@@@@@@@@ * ", (Width + 6.0f), (Height - 18.0f) + 1, 12);
		OnDrawText((char*)"@@@@@@@@@@   @", (Width + 6.0f), (Height - 18.0f) + 2, 12);
		OnDrawText((char*)"$        =   $", (Width + 6.0f), (Height - 18.0f) + 3);
		OnDrawText((char*)"$        =   $", (Width + 6.0f), (Height - 18.0f) + 4);
		OnDrawText((char*)"$    ~= ;=   $", (Width + 6.0f), (Height - 18.0f) + 5);
		OnDrawText((char*)"$;@@     =   $", (Width + 6.0f), (Height - 18.0f) + 6);
		OnDrawText((char*)"$;@@     =   $", (Width + 6.0f), (Height - 18.0f) + 7);
		OnDrawText((char*)"$;@@     =   $", (Width + 6.0f), (Height - 18.0f) + 8);
		OnDrawText((char*)"#$##=====$===#", (Width + 6.0f), (Height - 18.0f) + 9);

		DrawCircle(Width, Height, 30.0f, -6.0f);
		DrawCircle(Width, Height, 60.0f, 5.0f);
		DrawCircle(Width, Height, 40.0f, 13.0f);
		DrawCircle(Width, Height, 70.0f, 19.0f);

		OnDrawText((char*)"    ~@@@@@#    ", (Width + 47.0f), (Height - 30.0f), 14);
		OnDrawText((char*)"  !         -* ", (Width + 47.0f), (Height - 30.0f) + 1.0f, 14);
		OnDrawText((char*)"@             @", (Width + 47.0f), (Height - 30.0f) + 2.0f, 14);
		OnDrawText((char*)"@             @", (Width + 47.0f), (Height - 30.0f) + 3.0f, 14);
		OnDrawText((char*)" ~           ! ", (Width + 47.0f), (Height - 30.0f) + 4.0f, 14);
		OnDrawText((char*)"    ~@@@@@#-  ", (Width + 47.0f), (Height - 30.0f) + 5.0f, 14);

		if (_System->ClearStage == 0)
		{
			OnDrawText(Player->Info.Texture, Player->TransInfo.Position.x
				, Player->TransInfo.Position.y, 11);
			Sleep(2500);
			++_System->StageNum;
		}
	}
	return _System->StageNum;
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

void OnDrawText(const char* _str, const float _x, const float _y, const int _Color)
{
	SetCursorPosition(_x, _y);
	SetTextColor(_Color);
	cout << _str;
}

void OnDrawText( const int _Value, const float _x, const float _y, const int _Color)
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
	{
		if (_Object->TransInfo.Position.y > 2)
			_Object->TransInfo.Position.y -= 2;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (_Object->TransInfo.Position.y < 54)
			_Object->TransInfo.Position.y += 1;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (_Object->TransInfo.Position.x > 1)
			_Object->TransInfo.Position.x -= 2;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (_Object->TransInfo.Position.x < 82)
			_Object->TransInfo.Position.x += 2;
	}
}

void Initialize(Object* _Object, char* _Texture, const int _MaxHP,
	const int _HP,const float _PosX, const float _PosY, const float _PosZ)
{
	_Object->Info.Texture = (_Texture == nullptr) ? SetName() : _Texture;

	_Object->Power = 1;
	_Object->MaxHP = _MaxHP;
	_Object->HP = _HP;

	_Object->TransInfo.Position = Vector3 (_PosX, _PosY, _PosZ);
	_Object->TransInfo.Rotation = Vector3 (0, 0, 0);
	_Object->TransInfo.Scale = Vector3 ((float)(strlen(_Object->Info.Texture)), 1, 0);

}

bool Collision(Object* ObjectA, Object* ObjectB)
{
	if (ObjectA->TransInfo.Position.y  < ObjectB->TransInfo.Position.y + 0.5 &&
		ObjectA->TransInfo.Position.y  > ObjectB->TransInfo.Position.y - 0.5 &&
		(ObjectA->TransInfo.Position.x + ObjectA->TransInfo.Scale.x) >=
		ObjectB->TransInfo.Position.x &&
		(ObjectB->TransInfo.Position.x + ObjectB->TransInfo.Scale.x) >=
		ObjectA->TransInfo.Position.x)
		return true;
	return false;
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

float GetDistance(const Object* ObjectA, const Object* ObjectB)
{
	float x = ObjectA->TransInfo.Position.x - ObjectB->TransInfo.Position.x;
	float y = ObjectA->TransInfo.Position.y - ObjectB->TransInfo.Position.y;
	return sqrt((x * x) + (y * y));
}

Vector3 GetDirection(const Object* ObjectA, const Object* ObjectB)
{
	float Distance = 0;

	float x = ObjectA->TransInfo.Position.x - ObjectB->TransInfo.Position.x;
	float y = ObjectA->TransInfo.Position.y - ObjectB->TransInfo.Position.y;

	Distance  = sqrt((x * x) + (y * y));

	return Vector3(x / Distance, y / Distance);
}

Object* CreateBullet(const float _x, const float _y, const int _Power,
	const int Option)
{
	Object* _Object = new Object;
	if (_Power == 1)
	{
		Initialize(_Object, (char*)"●", 0, 0, (float)_x, (float)_y, 11);
		_Object->Info.Option = 0;
	}

	if (Option == 1)
	{
		Initialize(_Object, (char*)"◆", 0, 0 ,(float)_x, (float)_y+1.0f,
			14);
		_Object->Info.Option = 1;
	}

	else if (Option == 2)
	{
		Initialize(_Object, (char*)"▣", 0, 0, (float)_x, (float)_y + 1.0f,
			14);
		_Object->Info.Option = 2;
	}
	return _Object;
}

Object* CreateItem(const float _x, const float _y)
{
	Object* _Object = new Object;
	Initialize(_Object, (char*)"<P>", 0, 0, (float)_x, (float)_y);
	return _Object;
}

Object* CreateEnemy(const float _x, const float _y)
{
	Object* _Object = new Object;
	Initialize(_Object, (char*)"⊙", 1 , 1, (float)_x, (float)_y);
	_Object->Info.Option = rand() % 100;

	return _Object;
}



void DrawTree(const float Width, const float Height, const float _x, const float _y)
{
	OnDrawText((char*)"     @     ", (Width + _x), (Height - _y), 2);
	OnDrawText((char*)"    @@@    ", (Width + _x), (Height - _y) + 1.0f, 2);
	OnDrawText((char*)"   #@@@@   ", (Width + _x), (Height - _y) + 2.0f, 2);
	OnDrawText((char*)"   @@@@@,  ", (Width + _x), (Height - _y) + 3.0f, 2);
	OnDrawText((char*)"  @@@@@@@  ", (Width + _x), (Height - _y) + 4.0f, 2);
	OnDrawText((char*)"  @@@@@@@  ", (Width + _x), (Height - _y) + 5.0f, 2);
	OnDrawText((char*)" @@@@@@@@@ ", (Width + _x), (Height - _y) + 6.0f, 2);
	OnDrawText((char*)" @@@@@@@@@,", (Width + _x), (Height - _y) + 7.0f, 2);
	OnDrawText((char*)"    !@@    ", (Width + _x), (Height - _y) + 8.0f, 4);
	OnDrawText((char*)"    !@@    ", (Width + _x), (Height - _y) + 9.0f, 4);
	OnDrawText((char*)"    !@@    ", (Width + _x), (Height - _y) + 10.0f, 4);
}

void DrawMountain(const float Width, const float Height, const float _x, const float _y)
{
	OnDrawText((char*)"          :@!                  ", (Width + _x), (Height - _y), 2);
	OnDrawText((char*)"         @@@@@                 ", (Width + _x), (Height - _y) + 1.0f, 2);
	OnDrawText((char*)"        :@@@@@@                ", (Width + _x), (Height - _y) + 2.0f, 2);
	OnDrawText((char*)"        @@@@@@@*               ", (Width + _x), (Height - _y) + 3.0f, 2);
	OnDrawText((char*)"       @@@@@@@@@               ", (Width + _x), (Height - _y) + 4.0f, 2);
	OnDrawText((char*)"      #@@@@@@@@@@    @@#       ", (Width + _x), (Height - _y) + 5.0f, 2);
	OnDrawText((char*)"     -@@@@@@@@@@@@  @@@@#      ", (Width + _x), (Height - _y) + 6.0f, 2);
	OnDrawText((char*)"     @@@@@@@@@@@@@~~@@@@@,     ", (Width + _x), (Height - _y) + 7.0f, 2);
	OnDrawText((char*)"    @@@@@@@@@@@@@@@@@@@@@@     ", (Width + _x), (Height - _y) + 8.0f, 2);
	OnDrawText((char*)"   ;@@@@@@@@@@@@@@@@@@@@@@@    ", (Width + _x), (Height - _y) + 9.0f, 2);
	OnDrawText((char*)"   @@@@@@@@@@@@@@@@@@@@@@@@-   ", (Width + _x), (Height - _y) + 10.0f, 2);
	OnDrawText((char*)"  @@@@@@@@@@@@@@@@@@@@@@@@@@   ", (Width + _x), (Height - _y) + 11.0f, 2);
	OnDrawText((char*)" @@@@@@@@@@@@@@@@@@@@@@@@@@@@  ", (Width + _x), (Height - _y) + 12.0f, 2);
}

void DrawCloud(const float Width, const float Height, const float _x, const float _y)
{
	 OnDrawText((char*)"       .###.  ", (Width + _x), (Height - _y));       
     OnDrawText((char*)"      :   -~  ", (Width + _x), (Height - _y)+1.0f);      
     OnDrawText((char*)"   ;!      ;  ", (Width + _x), (Height - _y)+2.0f);      
     OnDrawText((char*)"   !       !  ", (Width + _x), (Height - _y)+3.0f);      
     OnDrawText((char*)" .:,       ,; ", (Width + _x), (Height - _y)+4.0f);      
     OnDrawText((char*)" $          ,,", (Width + _x), (Height - _y)+5.0f);      
     OnDrawText((char*)" $          ,,", (Width + _x), (Height - _y)+6.0f);      
     OnDrawText((char*)" :.         ; ", (Width + _x), (Height - _y)+7.0f);      
     OnDrawText((char*)"   $$$$$$$$~  ", (Width + _x), (Height - _y)+8.0f);  
}

void DrawCircle(const float Width, const float Height, const float _x, const float _y)
{
	OnDrawText((char*)"  @@@@    ", (Width + _x), (Height - _y), 14);
	OnDrawText((char*)"@      @", (Width + _x), (Height - _y) + 1.0f, 14);
	OnDrawText((char*)"@      @", (Width + _x), (Height - _y) + 2.0f, 14);
	OnDrawText((char*)"  @@@@  ", (Width + _x), (Height - _y) + 3.0f, 14);
}

void HideCursor(bool _Visible)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	CursorInfo.bVisible = _Visible;
	CursorInfo.dwSize = 1;

	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}