#pragma once
const int Scene_Logo = 0;
const int Scene_Menu = 1;
const int Scene_Stage = 2;
const int Scene_Exit = 3;
const int Scene_End = 4;
const int Scene_GameOver = 5;
const int Scene_Ranking = 6;


void SceneManager(DrawTextInfo* CPosition, Object* MenuCursor,
	Object* StageCursor, Object* Player, Object* Enemy[],
	Object* PBullet[], Object* Item[], Object* Destination[], Object* Boss,
	RecordScore* Ranking[], Vector3 Direction[], Vector3 EDirection[],
	System* _System, TimeInfomation* TimeInfo);
void Logo();
void Menu(DrawTextInfo* _DrawTextInfo, Object* _Object, System* _System);
void Stage(Object* StageCursor, Object* Player, Object* Enemy[],
	Object* PBullet[], Object* Item[], Object* Boss, Object* Destination[],
	Vector3 _Direction[], Vector3 EDirection[], System* _System,
	TimeInfomation* TimeInfo);
void End(Object* Player, Object* PBullet[], System* _System,
	TimeInfomation* TimeInfo);
void GameOver(Object* Player, Object* PBullet[], System* _System);
void ShowRanking(RecordScore* Ranking[], System* _System);

void PlayStage(Object* Player, Object* Enemy[], Object* PBullet[],
	Object* Item[], Object* _Boss, Object* Destination[], Vector3 _Direction[],
	Vector3 EDirection[], System* _System, TimeInfomation* TimeInfo);
void ShowPlayStage(Object* Player, System* System);
void StageClear(Object* Player, Object* PBullet[], System* _System,
	TimeInfomation* TimeInfo);
void StageSet(Object* Player, Object* Enemy[], Object* PBullet[],
	Object* Destination[], Vector3 _Direction[], Vector3 EDirection[],
	System* _System, TimeInfomation* TimeInfo);

void SetCursorPosition(const float _x, const float _y);
void OnDrawText(const char* _str, const float _x, const float _y, const int _Color = 15);
void OnDrawText(const int _Value, const float _x, const float _y, const int _Color = 15);
//Ű�Է��� �޾ƿ��� �Լ�(����Ű)
void UpdateInput(Object* _Object);
void Initialize(Object* _Object, char* _Texture, const int _MaxHP,
	const int HP, const float _PosX, const float _PosY,
	const float _PosZ = 0);
void Initialize(RecordScore* Ranking, char* _Name, const int _Total,
	const int _Stage1, const int _Stage2, const int _Stage3,
	const int _Stage4, const int _Stage5);
void ResetSystem(Object* Player, Object* PBullet[], System* _System);
void ChargeAttackBullet(Object* Player, Object* PBullet[], TimeInfomation* _Time);
void Boss(Object* BossEnemy, Object* PBullet[], Object* Item[], Object* Player,
	Vector3 Direction[], TimeInfomation* TimeInfo);

bool Collision(Object* ObjectA, Object* ObjectB);
char* SetName();
int CaculationScore(Object* Player, System* _System, int Score);
float GetMidleWidth(const char* _str);
float GetDistance(const Object* ObjectA, const Object* ObjectB);

Vector3 GetDirection(const Object* ObjectA, const Object* ObjectB);
Object* CreateEnemy(const float _x, const float _y);
Object* CreateBullet(const float _x, const float _y, const int _Power,
	const int Option);
Object* CreateItem(const float _x, const float _y);
Object* CreateDestination(const float _x, const float _y);

void DrawTree(const float Width, const float Height, const float _x = 0, const float _y = 0);
void DrawMountain(const float Width, const float Height, const float _x = 0, const float _y = 0);
void DrawCloud(const float Width, const float Height, const float _x = 0, const float _y = 0);
void DrawCircle(const float Width, const float Height, const float _x = 0, const float _y = 0);
void DrawCross(const float Width, const float Height, const float _x, const float _y);
void ShowUI(Object* Player, System* _System);
void HideCursor(bool _Visible);

//	***	�Ű����� ������ �����
void SceneManager(DrawTextInfo* CPosition, Object* MenuCursor,
	Object* StageCursor, Object* Player, Object* Enemy[],
	Object* PBullet[], Object* Item[], Object* Destination[], Object* Boss,
	RecordScore* Ranking[], Vector3 Direction[], Vector3 EDirection[],
	System* _System, TimeInfomation* TimeInfo)
{
	switch (_System->Scene_State)
	{
	case Scene_Logo:
		Logo();
		_System->Scene_State++;
		break;
	case Scene_Menu:
		Menu(CPosition, MenuCursor, _System);
		break;
	case Scene_Stage:
		Stage(StageCursor, Player, Enemy, PBullet, Item, Boss, Destination,
			Direction, EDirection, _System, TimeInfo);
		break;
	case Scene_Exit:
		exit(NULL);
		break;
	case Scene_End:
		End(Player, PBullet, _System, TimeInfo);
		break;
	case Scene_GameOver:
		GameOver(Player, PBullet, _System);
		break;
	case Scene_Ranking:
		ShowRanking(Ranking, _System);
		break;
	}
}

void Logo()
{
	float Width = (float)(60 - (strlen("LLLLLLLLLLL                              BBBBBBBBBBBBBBBBB                         ") / 2));
	float Height = 15.0f;

	OnDrawText((char*)"LLLLLLLLLLL                              BBBBBBBBBBBBBBBBB                         ", Width, Height);
	OnDrawText((char*)"L:::::::::L                              B::::::::::::::::B                        ", Width, Height + 1.0f);
	OnDrawText((char*)"L:::::::::L                              B::::::BBBBBB:::::B                       ", Width, Height + 2.0f);
	OnDrawText((char*)"LL:::::::LL                              BB:::::B     B:::::B                      ", Width, Height + 3.0f);
	OnDrawText((char*)"  L:::::L                  ooooooooooo     B::::B     B:::::B   ooooooooooo        ", Width, Height + 4.0f);
	OnDrawText((char*)"  L:::::L                oo:::::::::::oo   B::::B     B:::::B oo:::::::::::oo      ", Width, Height + 5.0f);
	OnDrawText((char*)"  L:::::L               o:::::::::::::::o  B::::BBBBBB:::::B o:::::::::::::::o     ", Width, Height + 6.0f);
	OnDrawText((char*)"  L:::::L               o:::::ooooo:::::o  B:::::::::::::BB  o:::::ooooo:::::o     ", Width, Height + 7.0f);
	OnDrawText((char*)"  L:::::L               o::::o     o::::o  B::::BBBBBB:::::B o::::o     o::::o     ", Width, Height + 8.0f);
	OnDrawText((char*)"  L:::::L               o::::o     o::::o  B::::B     B:::::Bo::::o     o::::o     ", Width, Height + 9.0f);
	OnDrawText((char*)"  L:::::L               o::::o     o::::o  B::::B     B:::::Bo::::o     o::::o     ", Width, Height + 10.0f);
	OnDrawText((char*)"  L:::::L         LLLLLLo::::o     o::::o  B::::B     B:::::Bo::::o     o::::o     ", Width, Height + 11.0f);
	OnDrawText((char*)"LL:::::::LLLLLLLLL:::::Lo:::::ooooo:::::oBB:::::BBBBBB::::::Bo:::::ooooo:::::o     ", Width, Height + 12.0f);
	OnDrawText((char*)"L::::::::::::::::::::::Lo:::::::::::::::oB:::::::::::::::::B o:::::::::::::::o     ", Width, Height + 13.0f);
	OnDrawText((char*)"L::::::::::::::::::::::L oo:::::::::::oo B::::::::::::::::B   oo:::::::::::oo      ", Width, Height + 14.0f);
	OnDrawText((char*)"LLLLLLLLLLLLLLLLLLLLLLLL   ooooooooooo   BBBBBBBBBBBBBBBBB      ooooooooooo        ", Width, Height + 15.0f);
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
	OnDrawText((char*)"|  | |  ||  |  | ||       ||   | |       ||   |    |       ||      | ", Width, Height + 1);
	OnDrawText((char*)"|  | |  ||   |_| ||_     _||   | |_     _||   |    |    ___||  _    |", Width, Height + 2);
	OnDrawText((char*)"|  |_|  ||       |  |   |  |   |   |   |  |   |    |   |___ | | |   |", Width, Height + 3);
	OnDrawText((char*)"|       ||  _    |  |   |  |   |   |   |  |   |___ |    ___|| |_|   |", Width, Height + 4);
	OnDrawText((char*)"|       || | |   |  |   |  |   |   |   |  |       ||   |___ |       |", Width, Height + 5);
	OnDrawText((char*)"|_______||_|  |__|  |___|  |___|   |___|  |_______||_______||______| ", Width, Height + 6);

	Width = GetMidleWidth((char*)"���� ����");
	OnDrawText((char*)"���� ����", Width, Height + 10);
	OnDrawText((char*)"���� ����", Width, Height + 12);

	_Object->TransInfo.Position.x = (Width + strlen("���� ����"));
	if (GetAsyncKeyState(VK_UP))
	{
		if (_Object->TransInfo.Position.y > 25.0f)
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
	if (Blank == 0)
		OnDrawText((char*)"Press Sapce to Select!", Width, Height + 14.0f, 8);
	else
		OnDrawText((char*)"Press Sapce to Select!", Width, Height + 14.0f, 15);
}

void Stage(Object* StageCursor, Object* Player, Object* Enemy[],
	Object* PBullet[], Object* Item[], Object* Boss, Object* Destination[],
	Vector3 _Direction[], Vector3 EDirection[], System* _System,
	TimeInfomation* TimeInfo)
{
	float Width = 0;
	if (_System->StageState == 0) //	������ ��ŵ���� Ȯ��
	{
		Width = GetMidleWidth((char*)"�������� ��ŵ�մϱ�?");
		OnDrawText((char*)"�������� ��ŵ�մϱ�?", Width, 25.0f);
		OnDrawText((char*)"��", 50.0f, 27.0f);
		OnDrawText((char*)"�ƴϿ�", 60.0f, 27.0f);
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (StageCursor->TransInfo.Position.x > 50.0f)
				StageCursor->TransInfo.Position.x = 50.0f + (float)strlen("��");
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (StageCursor->TransInfo.Position.x < 60.0f + (float)strlen("�ƴϿ�"))
				StageCursor->TransInfo.Position.x = 60.0f + (float)strlen("�ƴϿ�");
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (StageCursor->TransInfo.Position.x == 60.0f + (float)strlen("�ƴϿ�"))
				++_System->StageState;
			else if (StageCursor->TransInfo.Position.x = 50.0f + (float)strlen("��"))
				_System->StageState = 2;
		}
		OnDrawText(StageCursor->Info.Texture, StageCursor->TransInfo.Position.x, StageCursor->TransInfo.Position.y);
	}
	else if (_System->StageState == 1) //	������
	{
		OnDrawText((char*)"Intro", Width, 25.0f);
		OnDrawText((char*)"Press Sapce", Width, 27.0f);
		if (GetAsyncKeyState(VK_SPACE))
		{
			++_System->StageState;
		}
	}
	else if (_System->StageState == 2)	// �������� ǥ��, �÷���
	{
		if (_System->ClearStage >= 5)
		{
			_System->Scene_State = Scene_End;
		}
		ShowPlayStage(Player, _System);
		if (_System->StageNum > 0 && _System->StageNum < 3)
			PlayStage(Player, Enemy, PBullet, Item, Boss, Destination, _Direction,
				EDirection, _System, TimeInfo);
		else if (_System->StageNum == 3)
			StageClear(Player, PBullet, _System, TimeInfo);
	}
}

void End(Object* Player, Object* PBullet[], System* _System,
	TimeInfomation* TimeInfo)
{
	float Width = GetMidleWidth((char*)"    dMMMMMMMMb    dMP   .dMMMb    .dMMMb     dMP   .aMMMb    dMMMMb");
	float Height = 20.0f;

	_System->StageState = 0;

	++TimeInfo->Result;

	if (TimeInfo->Result >= 3)
	{
		OnDrawText((char*)"    dMMMMMMMMb", Width, Height, 10);
		OnDrawText((char*)"   dMP'dMP'dMP", Width, Height + 1.0f, 10);
		OnDrawText((char*)"  dMP dMP dMP ", Width, Height + 2.0f, 10);
		OnDrawText((char*)" dMP dMP dMP  ", Width, Height + 3.0f, 10);
		OnDrawText((char*)"dMP dMP dMP   ", Width, Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 6)
	{
		OnDrawText((char*)"    dMP", Width + strlen("    dMMMMMMMMb"), Height, 10);
		OnDrawText((char*)"   amr ", Width + strlen("    dMMMMMMMMb"), Height + 1.0f, 10);
		OnDrawText((char*)"  dMP  ", Width + strlen("    dMMMMMMMMb"), Height + 2.0f, 10);
		OnDrawText((char*)" dMP   ", Width + strlen("    dMMMMMMMMb"), Height + 3.0f, 10);
		OnDrawText((char*)"dMP    ", Width + strlen("    dMMMMMMMMb"), Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 9)
	{
		OnDrawText((char*)"   .dMMMb ", Width + strlen("    dMMMMMMMMb    dMP"), Height, 10);
		OnDrawText((char*)"  dMP' VP", Width + strlen("    dMMMMMMMMb    dMP"), Height + 1.0f, 10);
		OnDrawText((char*)"  VMMMb  ", Width + strlen("    dMMMMMMMMb    dMP"), Height + 2.0f, 10);
		OnDrawText((char*)"dP .dMP ", Width + strlen("    dMMMMMMMMb    dMP"), Height + 3.0f, 10);
		OnDrawText((char*)"VMMMP' ", Width + strlen("    dMMMMMMMMb    dMP"), Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 12)
	{
		OnDrawText((char*)"   .dMMMb ", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb "), Height, 10);
		OnDrawText((char*)"  dMP' VP", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb "), Height + 1.0f, 10);
		OnDrawText((char*)"  VMMMb  ", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb "), Height + 2.0f, 10);
		OnDrawText((char*)"dP .dMP ", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb "), Height + 3.0f, 10);
		OnDrawText((char*)"VMMMP' ", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb "), Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 15)
	{
		OnDrawText((char*)"    dMP", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb "), Height, 10);
		OnDrawText((char*)"   amr ", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb "), Height + 1.0f, 10);
		OnDrawText((char*)"  dMP  ", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb "), Height + 2.0f, 10);
		OnDrawText((char*)" dMP   ", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb "), Height + 3.0f, 10);
		OnDrawText((char*)"dMP    ", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb "), Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 18)
	{
		OnDrawText((char*)"   .aMMMb", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb     dMP"), Height, 10);
		OnDrawText((char*)"  dMP'dMP", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb     dMP"), Height + 1.0f, 10);
		OnDrawText((char*)" dMP dMP	", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb     dMP"), Height + 2.0f, 10);
		OnDrawText((char*)"dMP.aMP	", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb     dMP"), Height + 3.0f, 10);
		OnDrawText((char*)"VMMMP'   ", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb     dMP"), Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 21)
	{
		OnDrawText((char*)"    dMMMMb", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb     dMP   .aMMMb"), Height, 10);
		OnDrawText((char*)"   dMP dMP", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb     dMP   .aMMMb"), Height + 1.0f, 10);
		OnDrawText((char*)"  dMP dMP ", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb     dMP   .aMMMb"), Height + 2.0f, 10);
		OnDrawText((char*)" dMP dMP  ", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb     dMP   .aMMMb"), Height + 3.0f, 10);
		OnDrawText((char*)"dMP dMP   ", Width + strlen("    dMMMMMMMMb    dMP   .dMMMb    .dMMMb     dMP   .aMMMb"), Height + 4.0f, 10);
	}

	Width = GetMidleWidth((char*)"   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP    dMMMMMP dMMMMMMP    dMMMMMP");
	Height = 27.0f;
	if (TimeInfo->Result >= 26)
	{
		OnDrawText((char*)"   .aMMMb", Width, Height, 10);
		OnDrawText((char*)"  dMP'VMP", Width, Height + 1.0f, 10);
		OnDrawText((char*)" dMP     ", Width, Height + 2.0f, 10);
		OnDrawText((char*)"dMP.aMP  ", Width, Height + 3.0f, 10);
		OnDrawText((char*)"VMMMP'   ", Width, Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 31)
	{
		OnDrawText((char*)"   .aMMMb", Width + strlen("   .aMMMb"), Height, 10);
		OnDrawText((char*)"  dMP'dMP", Width + strlen("   .aMMMb"), Height + 1.0f, 10);
		OnDrawText((char*)" dMP dMP	", Width + strlen("   .aMMMb"), Height + 2.0f, 10);
		OnDrawText((char*)"dMP.aMP	", Width + strlen("   .aMMMb"), Height + 3.0f, 10);
		OnDrawText((char*)"VMMMP'   ", Width + strlen("   .aMMMb"), Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 36)
	{
		OnDrawText((char*)"    dMMMMMMMMb", Width + strlen("   .aMMMb   .aMMMb"), Height, 10);
		OnDrawText((char*)"   dMP'dMP'dMP", Width + strlen("   .aMMMb   .aMMMb"), Height + 1.0f, 10);
		OnDrawText((char*)"  dMP dMP dMP ", Width + strlen("   .aMMMb   .aMMMb"), Height + 2.0f, 10);
		OnDrawText((char*)" dMP dMP dMP  ", Width + strlen("   .aMMMb   .aMMMb"), Height + 3.0f, 10);
		OnDrawText((char*)"dMP dMP dMP   ", Width + strlen("   .aMMMb   .aMMMb"), Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 41)
	{
		OnDrawText((char*)"    dMMMMb", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb"), Height, 10);
		OnDrawText((char*)"   dMP.dMP", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb"), Height + 1.0f, 10);
		OnDrawText((char*)"  dMMMMP' ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb"), Height + 2.0f, 10);
		OnDrawText((char*)" dMP      ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb"), Height + 3.0f, 10);
		OnDrawText((char*)"dMP       ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb"), Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 46)
	{
		OnDrawText((char*)"     dMP", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb"), Height, 10);
		OnDrawText((char*)"    dMP ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb"), Height + 1.0f, 10);
		OnDrawText((char*)"   dMP  ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb"), Height + 2.0f, 10);
		OnDrawText((char*)"  dMP   ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb"), Height + 3.0f, 10);
		OnDrawText((char*)" dMMMMMP", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb"), Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 51)
	{
		OnDrawText((char*)"    dMMMMMP", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP"), Height, 10);
		OnDrawText((char*)"   dMP     ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP"), Height + 1.0f, 10);
		OnDrawText((char*)"  dMMMP    ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP"), Height + 2.0f, 10);
		OnDrawText((char*)" dMP       ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP"), Height + 3.0f, 10);
		OnDrawText((char*)"dMMMMMP    ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP"), Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 56)
	{
		OnDrawText((char*)" dMMMMMMP", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP    dMMMMMP"), Height, 10);
		OnDrawText((char*)"   dMP   ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP    dMMMMMP"), Height + 1.0f, 10);
		OnDrawText((char*)"  dMP    ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP    dMMMMMP"), Height + 2.0f, 10);
		OnDrawText((char*)" dMP     ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP    dMMMMMP"), Height + 3.0f, 10);
		OnDrawText((char*)"dMP      ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP    dMMMMMP"), Height + 4.0f, 10);
	}
	if (TimeInfo->Result >= 61)
	{
		OnDrawText((char*)"    dMMMMMP", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP    dMMMMMP dMMMMMMP"), Height, 10);
		OnDrawText((char*)"   dMP     ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP    dMMMMMP dMMMMMMP"), Height + 1.0f, 10);
		OnDrawText((char*)"  dMMMP    ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP    dMMMMMP dMMMMMMP"), Height + 2.0f, 10);
		OnDrawText((char*)" dMP       ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP    dMMMMMP dMMMMMMP"), Height + 3.0f, 10);
		OnDrawText((char*)"dMMMMMP    ", Width + strlen("   .aMMMb   .aMMMb    dMMMMMMMMb    dMMMMb     dMP    dMMMMMP dMMMMMMP"), Height + 4.0f, 10);
		TimeInfo->EndTime++;
	}
	_System->ClearStage = 0;

	if (TimeInfo->EndTime >= 20)
	{
		_System->Scene_State = Scene_Ranking;
		TimeInfo->Result = 0;
		TimeInfo->EndTime = 0;
	}
}

void GameOver(Object* Player, Object* PBullet[], System* _System)
{
	float Width = GetMidleWidth((char*)" _______  _______  __   __  _______    _______  __   __  _______  ______   ");
	float Height = 20.0f;

	ResetSystem(Player, PBullet, _System);

	_System->ClearStage = 0;
	_System->StageState = 0;

	OnDrawText((char*)" _______  _______  __   __  _______    _______  __   __  _______  ______   ", Width, Height, 2);
	OnDrawText((char*)"|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  ", Width, Height + 1.0f, 2);
	OnDrawText((char*)"|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  ", Width, Height + 2.0f, 2);
	OnDrawText((char*)"|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ ", Width, Height + 3.0f, 2);
	OnDrawText((char*)"|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |", Width, Height + 4.0f, 2);
	OnDrawText((char*)"|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |", Width, Height + 5.0f, 2);
	OnDrawText((char*)"|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|", Width, Height + 6.0f, 2);
	Sleep(3000);

	_System->Scene_State = Scene_Logo;
}

void ShowRanking(RecordScore* Ranking[], System* _System)
{
	float Width = GetMidleWidth((char*)"������ ������ ��� ����� ���� ������ϴ�.");
	float Height = 2.0f;

	OnDrawText((char*)"������ ������ ��� ����� ���� ������ϴ�.", Width, 50.0f);

	Width = GetMidleWidth((char*)"_______  _____  _______ _______       ");
	if (_System->TimeInfo.ShowRanking < 20)
	{
		_System->TimeInfo.ShowRanking++;

		OnDrawText((char*)"_______  _____  _______ _______       ", Width, Height);
		OnDrawText((char*)"   |    |     |    |    |_____| |     ", Width, Height + 1.0f);
		OnDrawText((char*)"   |    |_____|    |    |     | |_____", Width, Height + 2.0f);

		if (_System->PlayerNameInput == 0)
		{
			for (int i = 0; i < 10; ++i)
			{
				for (int j = 0; j < 10; ++j)
				{
					if (Ranking[i]->Total > Ranking[j]->Total)
					{
						int Temp = Ranking[j]->Total;
						Ranking[j]->Total = Ranking[i]->Total;
						Ranking[i]->Total = Temp;
					}
				}
			}


			for (int i = 0; i < 10; ++i)
			{
				if (Ranking[i]->Total < _System->RScore.Total)
				{
					int Temp = Ranking[i]->Total;
					for (int j = 0; j < 10; ++j)
					{
						if (Temp > Ranking[j]->Total)
						{
							int Temp2 = Ranking[j]->Total;
							Ranking[j]->Total = Temp;
							Temp = Temp2;
						}

						else
							Ranking[j]->Total = Temp;
					}

					Ranking[i]->Total = _System->RScore.Total;

					Ranking[i]->Name = SetName();
					_System->PlayerNameInput = 1;

					break;
				}
				else
				{
					Ranking[i]->Name = (char*)"***";
				}
			}
		}

		Height = 7.0f;

		for (int i = 0; i < 10; ++i)
		{
			OnDrawText(i + 1, Width - (5.0f + strlen("st")), Height + i);
			switch (i)
			{
			case 0:
				OnDrawText((char*)"st", Width - 5.0f, Height + i);
				break;
			case 1:
				OnDrawText((char*)"nd", Width - 5.0f, Height + i);
				break;
			case 2:
				OnDrawText((char*)"rd", Width - 5.0f, Height + i);
				break;
			default:
				OnDrawText((char*)"th", Width - 5.0f, Height + i);
				break;
			}
			OnDrawText(Ranking[i]->Total, Width, Height + i);
			OnDrawText(Ranking[i]->Name, Width + strlen("_______  _____  _______ _______       "), Height + i);
		}
	}

	else if (_System->TimeInfo.ShowRanking >= 20 &&
		_System->TimeInfo.ShowRanking < 40)
	{
		_System->TimeInfo.ShowRanking++;
		Width = GetMidleWidth((char*)",---.|                    '|");

		OnDrawText((char*)",---.|                    '|", Width, Height);
		OnDrawText((char*)"`---.|--- ,---.,---.,---.  |", Width, Height + 1.0f);
		OnDrawText((char*)"    ||    ,---||   ||---'  |", Width, Height + 2.0f);
		OnDrawText((char*)"`---'`---'`---^`---|`---'  `", Width, Height + 3.0f);
		OnDrawText((char*)"               `---'        ", Width, Height + 4.0f);

		if (_System->PlayerNameInput == 1)
		{
			for (int i = 0; i < 10; ++i)
			{
				for (int j = 0; j < 10; ++j)
				{
					if (Ranking[i]->Stage1 > Ranking[j]->Stage1)
					{
						int Temp = Ranking[j]->Stage1;
						Ranking[j]->Stage1 = Ranking[i]->Stage1;
						Ranking[i]->Stage1 = Temp;
					}
				}
			}

			for (int i = 0; i < 10; ++i)
			{
				if (Ranking[i]->Stage1 < _System->RScore.Stage1)
				{
					int Temp = Ranking[i]->Stage1;
					for (int j = 0; j < 10; ++j)
					{
						if (Temp > Ranking[j]->Stage1)
						{
							int Temp2 = Ranking[j]->Stage1;
							Ranking[j]->Stage1 = Temp;
							Temp = Temp2;
						}

						else
							Ranking[j]->Stage1 = Temp;
					}
					Ranking[i]->Stage1 = _System->RScore.Stage1;

					Ranking[i]->Name = SetName();
					_System->PlayerNameInput = 0;
					break;
				}
				else
				{
					Ranking[i]->Name = (char*)"***";
				}
			}
		}

		Height = 7.0f;

		for (int i = 0; i < 10; ++i)
		{
			OnDrawText(i + 1, Width - (5.0f + strlen("st")), Height + i);
			switch (i)
			{
			case 0:
				OnDrawText((char*)"st", Width - 5.0f, Height + i);
				break;
			case 1:
				OnDrawText((char*)"nd", Width - 5.0f, Height + i);
				break;
			case 2:
				OnDrawText((char*)"rd", Width - 5.0f, Height + i);
				break;
			default:
				OnDrawText((char*)"th", Width - 5.0f, Height + i);
				break;
			}
			OnDrawText(Ranking[i]->Stage1, Width, Height + i);
			OnDrawText(Ranking[i]->Name, Width + strlen(",---.|                    '|"), Height + i);
		}
	}

	else if (_System->TimeInfo.ShowRanking >= 40 &&
		_System->TimeInfo.ShowRanking < 60)
	{
		_System->TimeInfo.ShowRanking++;
		Width = GetMidleWidth((char*)",---.|                   ,--.");

		OnDrawText((char*)",---.|                   ,--.", Width, Height);
		OnDrawText((char*)"`---.|--- ,---.,---.,---.,--'", Width, Height + 1.0f);
		OnDrawText((char*)"    ||    ,---||   ||---'|   ", Width, Height + 2.0f);
		OnDrawText((char*)"`---'`---'`---^`---|`---'`--'", Width, Height + 3.0f);
		OnDrawText((char*)"               `---'         ", Width, Height + 4.0f);

		if (_System->PlayerNameInput == 0)
		{
			for (int i = 0; i < 10; ++i)
			{
				for (int j = 0; j < 10; ++j)
				{
					if (Ranking[i]->Stage2 > Ranking[j]->Stage2)
					{
						int Temp = Ranking[j]->Stage2;
						Ranking[j]->Stage2 = Ranking[i]->Stage2;
						Ranking[i]->Stage2 = Temp;
					}
				}
			}

			for (int i = 0; i < 10; ++i)
			{
				if (Ranking[i]->Stage2 < _System->RScore.Stage2)
				{
					int Temp = Ranking[i]->Stage2;
					for (int j = 0; j < 10; ++j)
					{
						if (Temp > Ranking[j]->Stage2)
						{
							int Temp2 = Ranking[j]->Stage2;
							Ranking[j]->Stage2 = Temp;
							Temp = Temp2;
						}

						else
							Ranking[j]->Stage2 = Temp;
					}

					Ranking[i]->Stage2 = _System->RScore.Stage2;
					Ranking[i]->Name = SetName();
					_System->PlayerNameInput = 1;
					break;
				}
				else
				{
					Ranking[i]->Name = (char*)"***";
				}
			}
		}
		Height = 7.0f;

		for (int i = 0; i < 10; ++i)
		{
			OnDrawText(i + 1, Width - (5.0f + strlen("st")), Height + i);
			switch (i)
			{
			case 0:
				OnDrawText((char*)"st", Width - 5.0f, Height + i);
				break;
			case 1:
				OnDrawText((char*)"nd", Width - 5.0f, Height + i);
				break;
			case 2:
				OnDrawText((char*)"rd", Width - 5.0f, Height + i);
				break;
			default:
				OnDrawText((char*)"th", Width - 5.0f, Height + i);
				break;
			}
			OnDrawText(Ranking[i]->Stage2, Width, Height + i);
			OnDrawText(Ranking[i]->Name, Width + strlen(",---.|                   ,--."), Height + i);
		}
	}

	else if (_System->TimeInfo.ShowRanking >= 60 &&
		_System->TimeInfo.ShowRanking < 80)
	{
		_System->TimeInfo.ShowRanking++;
		Width = GetMidleWidth((char*)",---.|                   ,--.");

		OnDrawText((char*)",---.|                   ,--.", Width, Height);
		OnDrawText((char*)"`---.|--- ,---.,---.,---.  -|", Width, Height + 1.0f);
		OnDrawText((char*)"    ||    ,---||   ||---'   |", Width, Height + 2.0f);
		OnDrawText((char*)"`---'`---'`---^`---|`---'`--'", Width, Height + 3.0f);
		OnDrawText((char*)"               `---'         ", Width, Height + 4.0f);

		if (_System->PlayerNameInput == 1)
		{
			for (int i = 0; i < 10; ++i)
			{
				for (int j = 0; j < 10; ++j)
				{
					if (Ranking[i]->Stage3 > Ranking[j]->Stage3)
					{
						int Temp = Ranking[j]->Stage3;
						Ranking[j]->Stage3 = Ranking[i]->Stage3;
						Ranking[i]->Stage3 = Temp;
					}
				}
			}

			for (int i = 0; i < 10; ++i)
			{
				if (Ranking[i]->Stage3 < _System->RScore.Stage3)
				{
					int Temp = Ranking[i]->Stage3;
					for (int j = 0; j < 10; ++j)
					{
						if (Temp > Ranking[j]->Stage3)
						{
							int Temp2 = Ranking[j]->Stage3;
							Ranking[j]->Stage3 = Temp;
							Temp = Temp2;
						}

						else
							Ranking[j]->Stage3 = Temp;
					}
					Ranking[i]->Stage3 = _System->RScore.Stage3;
					Ranking[i]->Name = SetName();
					_System->PlayerNameInput = 0;
					break;
				}
				else
				{
					Ranking[i]->Name = (char*)"***";
				}
			}
		}

		Height = 7.0f;

		for (int i = 0; i < 10; ++i)
		{
			OnDrawText(i + 1, Width - (5.0f + strlen("st")), Height + i);
			switch (i)
			{
			case 0:
				OnDrawText((char*)"st", Width - 5.0f, Height + i);
				break;
			case 1:
				OnDrawText((char*)"nd", Width - 5.0f, Height + i);
				break;
			case 2:
				OnDrawText((char*)"rd", Width - 5.0f, Height + i);
				break;
			default:
				OnDrawText((char*)"th", Width - 5.0f, Height + i);
				break;
			}
			OnDrawText(Ranking[i]->Stage3, Width, Height + i);
			OnDrawText(Ranking[i]->Name, Width + strlen(",---.|                   ,--."), Height + i);
		}
	}

	else if (_System->TimeInfo.ShowRanking >= 80 &&
		_System->TimeInfo.ShowRanking < 100)
	{
		_System->TimeInfo.ShowRanking++;
		Width = GetMidleWidth((char*)", -- - .|                   |  |");

		OnDrawText((char*)",---.|                   |  |", Width, Height);
		OnDrawText((char*)"`---.|--- ,---.,---.,---.`--|", Width, Height + 1.0f);
		OnDrawText((char*)"    ||    ,---||   ||---'   |", Width, Height + 2.0f);
		OnDrawText((char*)"`---'`---'`---^`---|`---'   `", Width, Height + 3.0f);
		OnDrawText((char*)"               `---'         ", Width, Height + 4.0f);
		if (_System->PlayerNameInput == 0)
		{
			for (int i = 0; i < 10; ++i)
			{
				for (int j = 0; j < 10; ++j)
				{
					if (Ranking[i]->Stage4 > Ranking[j]->Stage4)
					{
						int Temp = Ranking[j]->Stage4;
						Ranking[j]->Stage4 = Ranking[i]->Stage4;
						Ranking[i]->Stage4 = Temp;
					}
				}
			}

			for (int i = 0; i < 10; ++i)
			{
				if (Ranking[i]->Stage4 < _System->RScore.Stage4)
				{
					int Temp = Ranking[i]->Stage4;
					for (int j = 0; j < 10; ++j)
					{
						if (Temp > Ranking[j]->Stage4)
						{
							int Temp2 = Ranking[j]->Stage4;
							Ranking[j]->Stage4 = Temp;
							Temp = Temp2;
						}

						else
							Ranking[j]->Stage4 = Temp;
					}
					Ranking[i]->Stage4 = _System->RScore.Stage4;
					Ranking[i]->Name = SetName();
					_System->PlayerNameInput = 1;
					break;
				}
				else
				{
					Ranking[i]->Name = (char*)"***";
				}
			}
		}
		Height = 7.0f;

		for (int i = 0; i < 10; ++i)
		{
			OnDrawText(i + 1, Width - (5.0f + strlen("st")), Height + i);
			switch (i)
			{
			case 0:
				OnDrawText((char*)"st", Width - 5.0f, Height + i);
				break;
			case 1:
				OnDrawText((char*)"nd", Width - 5.0f, Height + i);
				break;
			case 2:
				OnDrawText((char*)"rd", Width - 5.0f, Height + i);
				break;
			default:
				OnDrawText((char*)"th", Width - 5.0f, Height + i);
				break;
			}
			OnDrawText(Ranking[i]->Stage4, Width, Height + i);
			OnDrawText(Ranking[i]->Name, Width + strlen(", -- - .|                   |  |"), Height + i);
		}
	}

	else if (_System->TimeInfo.ShowRanking >= 100 &&
		_System->TimeInfo.ShowRanking < 120)
	{
		_System->TimeInfo.ShowRanking++;
		Width = GetMidleWidth((char*)",---.|                   ---.");

		OnDrawText((char*)",---.|                   ---.", Width, Height);
		OnDrawText((char*)"`---.|--- ,---.,---.,---.`--.", Width, Height + 1.0f);
		OnDrawText((char*)"    ||    ,---||   ||---'   |", Width, Height + 2.0f);
		OnDrawText((char*)"`---'`---'`---^`---|`---'`--'", Width, Height + 3.0f);
		OnDrawText((char*)"               `---'         ", Width, Height + 4.0f);

		if (_System->PlayerNameInput == 1)
		{
			for (int i = 0; i < 10; ++i)
			{
				for (int j = 0; j < 10; ++j)
				{
					if (Ranking[i]->Stage5 > Ranking[j]->Stage5)
					{
						int Temp = Ranking[j]->Stage5;
						Ranking[j]->Stage5 = Ranking[i]->Stage5;
						Ranking[i]->Stage5 = Temp;
					}
				}
			}

			for (int i = 0; i < 10; ++i)
			{
				if (Ranking[i]->Stage5 < _System->RScore.Stage5)
				{
					int Temp = Ranking[i]->Stage5;
					for (int j = 0; j < 10; ++j)
					{
						if (Temp > Ranking[j]->Stage5)
						{
							int Temp2 = Ranking[j]->Stage5;
							Ranking[j]->Stage4 = Temp;
							Temp = Temp2;
						}

						else
							Ranking[j]->Stage5 = Temp;
					}
					Ranking[i]->Stage5 = _System->RScore.Stage5;
					Ranking[i]->Name = SetName();
					_System->PlayerNameInput = 0;
					break;
				}
				else
				{
					Ranking[i]->Name = (char*)"***";
				}
			}
		}

		Height = 7.0f;

		for (int i = 0; i < 10; ++i)
		{
			OnDrawText(i + 1, Width - (5.0f + strlen("st")), Height + i);
			switch (i)
			{
			case 0:
				OnDrawText((char*)"st", Width - 5.0f, Height + i);
				break;
			case 1:
				OnDrawText((char*)"nd", Width - 5.0f, Height + i);
				break;
			case 2:
				OnDrawText((char*)"rd", Width - 5.0f, Height + i);
				break;
			default:
				OnDrawText((char*)"th", Width - 5.0f, Height + i);
				break;
			}
			OnDrawText(Ranking[i]->Stage5, Width, Height + i);
			OnDrawText(Ranking[i]->Name, Width + strlen(",---.|                   ---."), Height + i);
		}
	}

	else
	{
		_System->Scene_State = Scene_Logo;
		_System->TimeInfo.ShowRanking = 0;
		_System->StageState = 0;
		_System->RScore.Total = 0;
		_System->RScore.Stage1 = 0;
		_System->RScore.Stage2 = 0;
		_System->RScore.Stage3 = 0;
		_System->RScore.Stage4 = 0;
		_System->RScore.Stage5 = 0;
	}
}

void PlayStage(Object* Player, Object* Enemy[], Object* PBullet[],
	Object* Item[], Object* _Boss, Object* Destination[], Vector3 _Direction[],
	Vector3 EDirection[], System* _System, TimeInfomation* TimeInfo)
{
	StageSet(Player, Enemy, PBullet, Destination, _Direction, EDirection,
		_System, TimeInfo);

	//���� �Ҹ�
	TimeInfo->UseFuel++;
	if (TimeInfo->UseFuel > 10)
	{
		Player->Fuel--;
		TimeInfo->UseFuel = 0;
	}

	// �����̽��ٸ� ������ �� �Ѿ� ����
	if (!_System->Check && GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		for (int i = 0; i < 256; ++i)
		{
			if (PBullet[i] == nullptr)
			{
				if (Player->Power < 4)
				{
					PBullet[i] = CreateBullet(Player->TransInfo.Position.x,
						Player->TransInfo.Position.y, (Player->Power % 3),
						0);
					break;
				}

				else if (Player->Power >= 4 && Player->Power < 7)
				{
					PBullet[i] = CreateBullet(Player->TransInfo.Position.x - 2,
						Player->TransInfo.Position.y, (Player->Power % 3),
						0);
					for (int j = 0; j < 256; ++j)
					{
						if (PBullet[j] == nullptr)
						{
							PBullet[j] = CreateBullet(Player->TransInfo.Position.x + 2,
								Player->TransInfo.Position.y, (Player->Power % 3),
								0);
							break;
						}
					}
					break;
				}

				else if (Player->Power >= 7 && Player->Power < 10)
				{
					PBullet[i] = CreateBullet(Player->TransInfo.Position.x - 2,
						Player->TransInfo.Position.y, (Player->Power % 3),
						0);
					for (int j = 0; j < 256; ++j)
					{
						if (PBullet[j] == nullptr)
						{
							PBullet[j] = CreateBullet(Player->TransInfo.Position.x + 2,
								Player->TransInfo.Position.y, (Player->Power % 3),
								0);
							for (int k = 0; k < 256; ++k)
							{
								if (PBullet[k] == nullptr)
								{
									PBullet[k] = CreateBullet(Player->TransInfo.Position.x,
										Player->TransInfo.Position.y, (Player->Power % 3),
										0);
									break;
								}
							}
							break;
						}
					}
					break;
				}
			}
		}
		_System->Check = true;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		if (Player->Charge.Stack < 10 && !Player->Charge.Check)
			Player->Charge.Stack++;
		if (Player->Charge.Stack >= 10)
			Player->Info.Color = 15;
	}
	if (_System->Check && !(GetAsyncKeyState(VK_SPACE) & 0x8000))
	{
		if (Player->Charge.Stack >= 10)
		{
			Player->Charge.Check = true;
			Player->Charge.TransInfo.Position.x = Player->TransInfo.Position.x;
			Player->Charge.TransInfo.Position.y = Player->TransInfo.Position.y - 1;
			Player->Info.Color = 11;
		}
		Player->Charge.Stack = 0;
		_System->Check = false;
	}

	ChargeAttackBullet(Player, PBullet, TimeInfo);

	//�÷��̾� ����
	UpdateInput(Player);
	// ���������� ���� ���
	ShowUI(Player, _System);
	//������ ������ ���
	for (int i = 0; i < 16; ++i)
	{
		if (Item[i])
		{
			// x�� �浹�� x�����
			if ((Item[i]->TransInfo.Position.x + Item[i]->TransInfo.Scale.x) >= 80.0f)
				Item[i]->Info.MoveX = -1.0f;
			// x�� �浹�� x�����
			if (Item[i]->TransInfo.Position.x <= 1.0f)
				Item[i]->Info.MoveX = 1.0f;
			// y�� �浹�� y�����
			if (Item[i]->TransInfo.Position.y >= 54.0f)
				Item[i]->Info.MoveY = -1.0f;
			// y�� �浹�� y�����
			if (Item[i]->TransInfo.Position.y <= 1.0f)
				Item[i]->Info.MoveY = 1.0f;
			// ���
			OnDrawText(Item[i]->Info.Texture,
				Item[i]->TransInfo.Position.x += Item[i]->Info.MoveX,
				Item[i]->TransInfo.Position.y += Item[i]->Info.MoveY, 10);
		}
	}
	// �÷��̾� ���
	OnDrawText(Player->Info.Texture, Player->TransInfo.Position.x,
		Player->TransInfo.Position.y, Player->Info.Color);
	// �� ���
	for (int i = 0; i < 32; ++i)
	{
		if (Enemy[i])
		{

			Enemy[i]->TransInfo.Position.x += EDirection[i].x;
			Enemy[i]->TransInfo.Position.y += EDirection[i].y;
			OnDrawText(Enemy[i]->Info.Texture,
				Enemy[i]->TransInfo.Position.x,
				Enemy[i]->TransInfo.Position.y, Enemy[i]->Info.Color);
		}
	}
	// �Ѿ� ���
	for (int i = 0; i < 256; ++i)
	{
		if (PBullet[i])
		{
			switch (PBullet[i]->Info.Option)
			{
			case 0:	// �÷��̾� �Ѿ� ���
			{
				PBullet[i]->TransInfo.Position.y -= 1;
				OnDrawText(PBullet[i]->Info.Texture,
					PBullet[i]->TransInfo.Position.x,
					PBullet[i]->TransInfo.Position.y,
					11);
				break;
			}

			case 1:	// �� �Ϲ� �Ѿ� ���
			{
				PBullet[i]->TransInfo.Position.x += _Direction[i].x;
				PBullet[i]->TransInfo.Position.y += _Direction[i].y;
				OnDrawText(PBullet[i]->Info.Texture,
					PBullet[i]->TransInfo.Position.x,
					PBullet[i]->TransInfo.Position.y,
					14);
				break;
			}

			case 2: // �� ���� �Ѿ� ���
			{
				if (TimeInfo->EBHomingTime[i] < 50)
				{
					_Direction[i] = GetDirection(Player, PBullet[i]);
					TimeInfo->EBHomingTime[i]++;
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
	// ȭ�� ������ ���� �Ѿ� ����
	for (int i = 0; i < 256; ++i)
	{
		if (PBullet[i])
		{
			if (PBullet[i]->TransInfo.Position.y <= 1.0f ||
				PBullet[i]->TransInfo.Position.y >= 55.0f ||
				PBullet[i]->TransInfo.Position.x <= 1.0f ||
				PBullet[i]->TransInfo.Position.x >= 80.0f)
			{
				delete PBullet[i];
				PBullet[i] = nullptr;
				TimeInfo->EBHomingTime[i] = 0;
			}
		}
	}
	// ���� ȭ�� ������ ��������
	// �ݴ����� ��Ÿ������
	for (int i = 0; i < 32; ++i)
	{
		if (Enemy[i])
		{
			if (Enemy[i]->TransInfo.Position.x <= 1.0f)
				Enemy[i]->TransInfo.Position.x = 79.0f - Enemy[i]->TransInfo.Scale.x;
			if (Enemy[i]->TransInfo.Position.x + Enemy[i]->TransInfo.Scale.x >= 80.0f)
				Enemy[i]->TransInfo.Position.x = 2.0f;
			if (Enemy[i]->TransInfo.Position.y <= 1.0f)
				Enemy[i]->TransInfo.Position.y = 53.0f;
			if (Enemy[i]->TransInfo.Position.y >= 54.0f)
				Enemy[i]->TransInfo.Position.y = 2.0f;
		}
	}
	// ���� �� �Ѿ� �� �÷��̾�� �������� �� 
	// �÷��̾� ü�°��ҿ� �� �Ѿ� ����
	for (int i = 0; i < 256; ++i)
	{
		if (PBullet[i] != nullptr && PBullet[i]->Info.Option > 0)
		{
			if (Collision(PBullet[i], Player))
			{
				delete PBullet[i];
				PBullet[i] = nullptr;
				Player->HP--;
				TimeInfo->EBHomingTime[i] = 0;
			}
		}
	}
	// �÷��̾��� �Ѿ��� ������ ���� ���� �� Ȯ�������� ������ ����
	for (int i = 0; i < 256; ++i)
	{
		if (PBullet[i] != nullptr)
		{
			for (int j = 0; j < 32; ++j)
			{
				if (Enemy[j] != nullptr)
				{
					if (Enemy[j]->HP <= 0)
					{
						if (Enemy[j]->Info.Option < 10 &&
							Collision(PBullet[i], Enemy[j]))
						{
							for (int k = 0; k < 16; ++k)
							{
								if (Item[k] == nullptr)
									Item[k] = CreateItem(Enemy[j]->TransInfo.Position.x,
										Enemy[j]->TransInfo.Position.y);
							}

						}
					}
				}
			}
		}

	}
	// �÷��̾��� �Ѿ��� ������ ���� ���� �� �� ������ �߰����� ȹ��
	for (int i = 0; i < 256; ++i)
	{
		if (PBullet[i] != nullptr && PBullet[i]->Info.Option == 0)
		{
			for (int j = 0; j < 32; ++j)
			{
				if (Enemy[j] != nullptr)
				{
					if (Collision(PBullet[i], Enemy[j]))
					{
						Enemy[j]->HP -= PBullet[i]->Power;

						delete PBullet[i];
						PBullet[i] = nullptr;

						if (Enemy[j]->HP <= 0)
						{
							delete Enemy[j];
							Enemy[j] = nullptr;

							_System->PlayerKill--;
							_System->Score += 10;
						}
					}
				}
			}
		}
	}
	//�������� �Ծ�����
	for (int i = 0; i < 16; ++i)
	{
		if (Item[i])
		{
			if (Collision(Player, Item[i]))
			{
				// �Ŀ���
				if (Item[i]->Info.Option == 0)
				{
					if (Player->Power < 10)
						Player->Power += 1;
					else
						_System->Score += 1000;
				}
				//HPȸ��
				else if (Item[i]->Info.Option == 1)
				{
					if (Player->HP < Player->MaxHP)
						Player->HP++;
					else
						_System->Score += 1000;
				}
			}
		}
	}
	// ������ �Ծ��� �� �����
	for (int i = 0; i < 16; ++i)
	{
		if (Item[i])
		{
			if (Collision(Player, Item[i]))
			{
				delete Item[i];
				Item[i] = nullptr;
			}
		}
	}

	if (Player->Fuel <= 0)
	{
		Player->HP -= 2;
		Player->Fuel = 100;

		if (Player->Power > 1)
			Player->Power--;
	}

	// �������� Ŭ����
	if (_System->PlayerKill == 0)
	{
		if (_System->ClearStage == 4)
		{
			Boss(_Boss, PBullet, Item, Player, _Direction, TimeInfo);
		}

		else if (Enemy[0]->HP <= 0)
			_System->StageNum = 3;

		else
			_System->StageNum = 3;
	}
	// ���ӿ���
	if (Player->HP <= 0)
		_System->Scene_State = Scene_GameOver;
}

void ShowPlayStage(Object* Player, System* _System)
{

	if (_System->StageNum == 0)
	{
		float Width = 5.0f;
		float Height = 40.0f;

		//	���� ��� �׸���
		DrawTree(Width, Height);
		DrawTree(Width, Height, 10.0f, 5.0f);
		DrawTree(Width, Height, 90.0f, 18.0f);
		DrawTree(Width, Height, 80.0f, 25.0f);

		//	��	��� �׸���
		DrawMountain(Width, Height, 70.0f, 6.0f);
		DrawMountain(Width, Height, 3.0f, 30.0f);

		//	���� ��� �׸���
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

		if (_System->ClearStage > 0)
		{
			DrawCross(Width, Height, 30.0f, -6.0f);
		}
		if (_System->ClearStage > 1)
		{
			DrawCross(Width, Height, 60.0f, 5.0f);
		}
		if (_System->ClearStage > 2)
		{
			DrawCross(Width, Height, 40.0f, 13.0f);
		}
		if (_System->ClearStage > 3)
		{
			DrawCross(Width, Height, 70.0f, 19.0f);
		}
		switch (_System->ClearStage)
		{
		case 0:
		{
			OnDrawText(Player->Info.Texture, Player->TransInfo.Position.x - 2.0f
				, Player->TransInfo.Position.y - 5.0f, 11);
			Sleep(2500);
			++_System->StageNum;
			break;
		}

		case 1:
		{
			OnDrawText(Player->Info.Texture, Player->TransInfo.Position.x - 2.0f
				, Player->TransInfo.Position.y - 5.0f, 11);

			if (Player->TransInfo.Position.x - 2.0f < 69.0f)
				Player->TransInfo.Position.x += 2.0f;
			if (Player->TransInfo.Position.y - 5.0f > 36.0f)
				Player->TransInfo.Position.y -= 1.0f;

			if (Player->TransInfo.Position.x - 2.0f >= 69.0f &&
				Player->TransInfo.Position.y - 5.0f <= 36.0f)
			{
				Sleep(1000);
				++_System->StageNum;
				Player->TransInfo.Position.x = 40.0f;
				Player->TransInfo.Position.y = 52.0f;
			}
			break;
		}

		case 2:
		{
			OnDrawText(Player->Info.Texture, Player->TransInfo.Position.x + 28.0f
				, Player->TransInfo.Position.y - 16.0f, 11);

			if (Player->TransInfo.Position.x + 28.0f > 47.0f)
				Player->TransInfo.Position.x -= 2.0f;
			if (Player->TransInfo.Position.y - 16.0f > 28.0f)
				Player->TransInfo.Position.y -= 1.0f;

			if (Player->TransInfo.Position.x + 28.0f <= 47.0f &&
				Player->TransInfo.Position.y - 16.0f <= 28.0f)
			{
				Sleep(1000);
				++_System->StageNum;
				Player->TransInfo.Position.x = 40.0f;
				Player->TransInfo.Position.y = 52.0f;
			}
			break;
		}

		case 3:
		{
			OnDrawText(Player->Info.Texture, Player->TransInfo.Position.x + 8.0f
				, Player->TransInfo.Position.y - 24.0f, 11);

			if (Player->TransInfo.Position.x + 8.0f < 79.0f)
				Player->TransInfo.Position.x += 2.0f;

			if (Player->TransInfo.Position.y - 24.0f > 22.0f)
				Player->TransInfo.Position.y -= 1.0f;

			if (Player->TransInfo.Position.x + 8.0f >= 79.0f &&
				Player->TransInfo.Position.y - 24.0f <= 22.0f)
			{
				Sleep(1000);
				++_System->StageNum;
				Player->TransInfo.Position.x = 40.0f;
				Player->TransInfo.Position.y = 52.0f;
			}
			break;
		}

		case 4:
		{
			OnDrawText(Player->Info.Texture, Player->TransInfo.Position.x + 38.0f
				, Player->TransInfo.Position.y - 30.0f, 11);

			if (Player->TransInfo.Position.x + 38.0f > 59.0f)
				Player->TransInfo.Position.x -= 2.0f;

			if (Player->TransInfo.Position.y - 30.0f > 12.0f)
				Player->TransInfo.Position.y -= 1.0f;

			if (Player->TransInfo.Position.x + 38.0f <= 59.0f &&
				Player->TransInfo.Position.y - 30.0f <= 12.0f)
			{
				Sleep(1000);
				++_System->StageNum;
				Player->TransInfo.Position.x = 40.0f;
				Player->TransInfo.Position.y = 52.0f;
			}
			break;
		}
		}
	}
}

void StageClear(Object* Player, Object* PBullet[], System* _System,
	TimeInfomation* TimeInfo)
{
	float Width = GetMidleWidth((char*)" _______  _______  _______  _______  _______    _______  ___      _______  _______  ______    __   __ ");
	float Height = 20;

	TimeInfo->CountTime++;

	OnDrawText((char*)" _______  _______  _______  _______  _______    _______  ___      _______  _______  ______    __   __ ", Width, Height, 14);
	OnDrawText((char*)"|       ||       ||   _   ||       ||       |  |       ||   |    |       ||   _   ||    _ |  |  | |  |", Width, Height + 1.0f, 14);
	OnDrawText((char*)"|  _____||_     _||  |_|  ||    ___||    ___|  |       ||   |    |    ___||  |_|  ||   | ||  |  | |  |", Width, Height + 2.0f, 14);
	OnDrawText((char*)"| |_____   |   |  |       ||   | __ |   |___   |       ||   |    |   |___ |       ||   |_||_ |  | |  |", Width, Height + 3.0f, 14);
	OnDrawText((char*)"|_____  |  |   |  |       ||   ||  ||    ___|  |      _||   |___ |    ___||       ||    __  ||__| |__|", Width, Height + 4.0f, 14);
	OnDrawText((char*)" _____| |  |   |  |   _   ||   |_| ||   |___   |     |_ |       ||   |___ |   _   ||   |  | | __   __ ", Width, Height + 5.0f, 14);
	OnDrawText((char*)"|_______|  |___|  |__| |__||_______||_______|  |_______||_______||_______||__| |__||___|  |_||__| |__|", Width, Height + 6.0f, 14);

	if (TimeInfo->CountTime > 2)
		OnDrawText((char*)"Score", Width, Height + 7.0f, 14);
	if (TimeInfo->CountTime > 5)
		OnDrawText(_System->Score, Width + 15.0f, Height + 7.0f, 14);
	if (TimeInfo->CountTime > 7)
		OnDrawText((char*)"--------", Width + 1.0f, Height + 12.0f, 14);
	if (TimeInfo->CountTime > 9)
		OnDrawText((char*)"Total", Width, Height + 13.0f, 14);
	if (TimeInfo->CountTime > 12)
		switch (_System->ClearStage)
		{
		case 0:
			OnDrawText(_System->RScore.Stage1, Width + 15.0f, Height + 13.0f, 14);
			break;
		case 1:
			OnDrawText(_System->RScore.Stage2, Width + 15.0f, Height + 13.0f, 14);
			break;
		case 2:
			OnDrawText(_System->RScore.Stage3, Width + 15.0f, Height + 13.0f, 14);
			break;
		case 3:
			OnDrawText(_System->RScore.Stage4, Width + 15.0f, Height + 13.0f, 14);
			break;
		case 4:
			OnDrawText(_System->RScore.Stage5, Width + 15.0f, Height + 13.0f, 14);
			break;
		}

	if (TimeInfo->CountTime > 17)
		OnDrawText((char*)"Life", Width, Height + 8.0f, 14);

	if (TimeInfo->CountTime > 19)
		OnDrawText(Player->HP, Width + 10.0f, Height + 8.0f, 14);
	if (TimeInfo->CountTime > 24)
	{
		OnDrawText(Player->HP * 10, Width + 15.0f, Height + 8.0f, 14);
		OnDrawText((char*)"%", Width + 18.0f, Height + 8.0f, 14);
	}

	if (TimeInfo->CountTime > 26)
		OnDrawText((char*)"Fuel", Width, Height + 10.0f, 14);
	if (TimeInfo->CountTime > 28)
		OnDrawText(Player->Fuel, Width + 10.0f, Height + 10.0f, 14);
	if (TimeInfo->CountTime > 30)
	{
		OnDrawText(Player->Fuel, Width + 15.0f, Height + 10.0f, 14);
		OnDrawText((char*)"%", Width + 18.0f, Height + 10.0f, 14);
	}

	if (TimeInfo->CountTime > 32)
		OnDrawText((char*)"Power LV", Width, Height + 11.0f, 14);
	if (TimeInfo->CountTime > 34)
		OnDrawText(Player->Power, Width + 10.0f, Height + 11.0f, 14);
	if (TimeInfo->CountTime > 36)
	{
		OnDrawText(Player->Power * 1000, Width + 15.0f, Height + 11.0f, 14);

		switch (_System->ClearStage)
		{
		case 0:
			_System->RScore.Stage1 = CaculationScore(Player, _System,
				_System->RScore.Stage1);
			if (_System->Complete)
				break;
		case 1:
			_System->RScore.Stage2 = CaculationScore(Player, _System,
				_System->RScore.Stage2);
			if (_System->Complete)
				break;
		case 2:
			_System->RScore.Stage3 = CaculationScore(Player, _System,
				_System->RScore.Stage3);
			if (_System->Complete)
				break;
		case 3:
			_System->RScore.Stage4 = CaculationScore(Player, _System,
				_System->RScore.Stage4);
			if (_System->Complete)
				break;
		case 4:
			_System->RScore.Stage5 = CaculationScore(Player, _System,
				_System->RScore.Stage5);
			if (_System->Complete)
				break;
		}

		if (_System->RScore.Temp <= 0)
		{
			Sleep(1500);

			++_System->ClearStage;
			TimeInfo->CountTime = 0;
			ResetSystem(Player, PBullet, _System);
		}
	}
}

void StageSet(Object* Player, Object* Enemy[], Object* PBullet[],
	Object* Destination[], Vector3 _Direction[], Vector3 EDirection[],
	System* _System, TimeInfomation* TimeInfo)
{
	switch (_System->ClearStage)
	{
	case 0:
		if (_System->StageNum == 1)
		{
			//_System->PlayerKill = 16;
			_System->PlayerKill = 1;
			_System->MaxEnemy = _System->PlayerKill;
			Player->Fuel = 100;
			_System->StageNum++;
		}
	case 1:
		if (_System->StageNum == 1)
		{
			//_System->PlayerKill = 20;
			_System->PlayerKill = 1;
			_System->MaxEnemy = _System->PlayerKill;
			Player->Fuel = 100;
			_System->StageNum++;
		}
	case 2:
		if (_System->StageNum == 1)
		{
			//_System->PlayerKill = 24;
			_System->PlayerKill = 1;
			_System->MaxEnemy = _System->PlayerKill;
			Player->Fuel = 100;
			_System->StageNum++;
		}
	case 3:
		if (_System->StageNum == 1)
		{
			//_System->PlayerKill = 28;
			_System->PlayerKill = 1;
			_System->MaxEnemy = _System->PlayerKill;
			Player->Fuel = 100;
			_System->StageNum++;
		}
	case 4:
		if (_System->StageNum == 1)
		{
			//_System->PlayerKill = 32;
			_System->PlayerKill = 1;
			_System->MaxEnemy = _System->PlayerKill;
			Player->Fuel = 100;
			_System->StageNum++;
		}
	}
	//	�� ����
	if (TimeInfo->EnemyTime)
	{
		if (_System->EnemyCount < _System->MaxEnemy)
		{
			for (int i = 0; i < _System->MaxEnemy; ++i)
			{
				if (Enemy[i] == nullptr)
				{
					srand((GetTickCount() + i * i) * GetTickCount());
					Enemy[i] = CreateEnemy((float)(rand() % 79 + 1),
						(float)(rand() % 19 + 1));

					Destination[i] = CreateDestination(
						(float)(rand() % 79 + 1),
						(float)(rand() % 19 + 1));
					EDirection[i] = GetDirection(Enemy[i], Destination[i]);

					TimeInfo->EnemyTime = false;
					_System->EnemyCount++;
					break;
				}
			}
		}
	}
	// ������ �������� ������ �����Լ� ������ �Ѿ�
	if (TimeInfo->EBulletTime)
	{
		srand(GetTickCount() * GetTickCount());

		_System->RandNum = rand() % 32;

		if (Enemy[_System->RandNum] != nullptr)
		{
			for (int i = 0; i < 256; ++i)
			{
				if (PBullet[i] == nullptr)
				{
					PBullet[i] = CreateBullet(
						Enemy[_System->RandNum]->TransInfo.Position.x,
						Enemy[_System->RandNum]->TransInfo.Position.y,
						0, 1 + (rand() % 2));
					_Direction[i] = GetDirection(Player, PBullet[i]);
					TimeInfo->EBulletTime = false;
					break;
				}
			}
		}
	}
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

void OnDrawText(const int _Value, const float _x, const float _y, const int _Color)
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
	const int _HP, const float _PosX, const float _PosY, const float _PosZ)
{
	_Object->Info.Texture = (_Texture == nullptr) ? SetName() : _Texture;

	_Object->Power = 1;
	_Object->MaxHP = _MaxHP;
	_Object->HP = _HP;
	_Object->Fuel = 100;

	_Object->TransInfo.Position = Vector3(_PosX, _PosY, _PosZ);
	_Object->TransInfo.Rotation = Vector3(0, 0, 0);
	_Object->TransInfo.Scale = Vector3((float)(strlen(_Object->Info.Texture)), 1, 0);
}

void Initialize(RecordScore* Ranking, char* _Name, const int _Total,
	const int _Stage1, const int _Stage2, const int _Stage3,
	const int _Stage4, const int _Stage5)
{
	Ranking->Name = (_Name == nullptr) ? SetName() : _Name;

	Ranking->Total = _Total;
	Ranking->Stage1 = _Stage1;
	Ranking->Stage2 = _Stage2;
	Ranking->Stage3 = _Stage3;
	Ranking->Stage4 = _Stage4;
	Ranking->Stage5 = _Stage5;
}

void ResetSystem(Object* Player, Object* PBullet[], System* _System)
{
	_System->EnemyCount = 0;
	_System->StageNum = 0;
	_System->Score = 0;

	for (int i = 0; i < 256; ++i)
	{
		if (PBullet[i] != nullptr)
		{
			delete PBullet[i];
			PBullet[i] = nullptr;
		}
	}

	Player->Power = 1;
	Player->HP = Player->MaxHP;
	Player->TransInfo.Position.x = 40.0f;
	Player->TransInfo.Position.y = 52.0f;
}

void ChargeAttackBullet(Object* Player, Object* PBullet[], TimeInfomation* _Time)
{
	if (Player->Charge.Check)
	{
		//if (Player->Power < 4)
		//{
		if (_Time->ChargeAttackTime % 3 == 0)
		{
			for (int i = 0; i < 256; ++i)
			{
				if (PBullet[i] == nullptr)
				{
					PBullet[i] = CreateBullet(Player->Charge.TransInfo.Position.x,
						Player->Charge.TransInfo.Position.y - 1, 1, 0);
					for (int j = 0; j < 256; ++j)
					{
						if (PBullet[j] == nullptr)
						{
							PBullet[j] = CreateBullet(Player->Charge.TransInfo.Position.x + 2,
								Player->Charge.TransInfo.Position.y, 1, 0);

							for (int k = 0; k < 256; ++k)
							{
								if (PBullet[k] == nullptr)
								{
									PBullet[k] = CreateBullet(Player->Charge.TransInfo.Position.x - 2,
										Player->Charge.TransInfo.Position.y, 1, 0);
									break;
								}
							}
							break;
						}
					}
					break;
				}
			}
		}
		//}
		//else if (Player->Power)
		_Time->ChargeAttackTime++;
		OnDrawText((char*)"��", Player->Charge.TransInfo.Position.x,
			Player->Charge.TransInfo.Position.y + 1);
	}

	if (_Time->ChargeAttackTime > 30)
	{
		Player->Charge.Check = false;
		_Time->ChargeAttackTime = 0;
	}
}

void Boss(Object* BossEnemy, Object* PBullet[], Object* Item[], Object* Player,
	Vector3 _Direction[], TimeInfomation* TimeInfo)
{
	float Width = BossEnemy->TransInfo.Position.x - (strlen("    .      .-~|           ") / 2);
	float Height = BossEnemy->TransInfo.Position.y;

	srand(GetTickCount() * GetTickCount());

	OnDrawText((char*)"    .      .-~|           ", Width, Height - 5.0f);
	OnDrawText((char*)"   / `-'|.'    `- :		 ", Width, Height - 4.0f);
	OnDrawText((char*)"   |    /          `._	 ", Width, Height - 3.0f);
	OnDrawText((char*)"   |   |   .-.        {	 ", Width, Height - 2.0f);
	OnDrawText((char*)"    |  |   `-'         `. ", Width, Height - 1.0f);
	OnDrawText((char*)"     | |                / ", Width, Height);
	OnDrawText((char*)"~-.`. ||            .-~_	 ", Width, Height + 1.0f);
	OnDrawText((char*)"    .|-.|       .-~      |", Width, Height + 2.0f);
	OnDrawText((char*)"     `-'/~~ -.~          /", Width, Height + 3.0f);
	OnDrawText((char*)"   .-~/|`-._ /~~-.~ -- ~	 ", Width, Height + 4.0f);
	OnDrawText((char*)"  /  |  |    ~- . _|		 ", Width, Height + 5.0f);

	for (float i = 0; i < 70; ++i)
	{
		if (BossEnemy->HP > i * 14)
			OnDrawText((char*)"/", 5.0f + i, 0.0f);
	}

	BossEnemy->TransInfo.Position.x += BossEnemy->Info.MoveX;
	BossEnemy->TransInfo.Position.y += BossEnemy->Info.MoveY;

	for (int i = 0; i < 256; ++i)
	{
		if (PBullet[i])
		{
			if (Collision(PBullet[i], BossEnemy))
			{
				BossEnemy->HP -= PBullet[i]->Power;

				delete PBullet[i];
				PBullet[i] = nullptr;
			}
		}
	}

	if (BossEnemy->HP <= 600)
	{
		BossEnemy->Phase = 2;
		if (BossEnemy->Info.Option == 1)
			BossEnemy->Info.Option = 2;
	}
	else if (BossEnemy->HP <= 300)
		BossEnemy->Phase = 3;

	switch (BossEnemy->Phase)
	{
	case 1:
		break;
	case 2:
		if (BossEnemy->Info.Option == 2)
		{
			for (int i = 0; i < 16; ++i)
			{
				if (Item[i] == nullptr)
					Item[i] = CreateItem((rand() % 70) + 5.0f,
						BossEnemy->TransInfo.Position.y + 5.0f);
				BossEnemy->Info.Option = 3;
				break;
			}
		}
		break;
	case 3:
		if (BossEnemy->Info.Option == 3)
		{
			for (int i = 0; i < 16; ++i)
			{
				if (Item[i] == nullptr)
					Item[i] = CreateItem((rand() % 70) + 5.0f,
						BossEnemy->TransInfo.Position.y + 5.0f);
				BossEnemy->Info.Option = 4;
				break;
			}
		}
		break;
	}

	// x�� �浹�� x�����
	if ((BossEnemy->TransInfo.Position.x + (strlen("    .      .-~|           ") / 2)) >= 80.0f)
		BossEnemy->Info.MoveX = -rand() % 3;
	// x�� �浹�� x�����
	if (BossEnemy->TransInfo.Position.x - (strlen("    .      .-~|           ") / 2) <= 1.0f)
		BossEnemy->Info.MoveX = rand() % 3;
	// y�� �浹�� y�����
	if (BossEnemy->TransInfo.Position.y + 5.5f >= 25.0f)
		BossEnemy->Info.MoveY = -rand() % 3;
	// y�� �浹�� y�����
	if (BossEnemy->TransInfo.Position.y - 5.5f <= 1.0f)
		BossEnemy->Info.MoveY = rand() % 3;

	if (TimeInfo->BossAttack)
	{
		switch (rand() % 2)
		{
		case 0:
			if (TimeInfo->Pattern < 10)
			{
				TimeInfo->Pattern++;
				if (TimeInfo->Pattern % 2 == 0)
				{
					for (int j = 0; j < 256; ++j)
					{
						if (PBullet[j] == nullptr)
						{
							PBullet[j] = CreateBullet(
								BossEnemy->TransInfo.Position.x,
								BossEnemy->TransInfo.Position.y + 5.0f,
								0, 1);
							_Direction[j] = GetDirection(Player, PBullet[j]);
							break;
						}
					}
				}
			}

			else if (TimeInfo->Pattern >= 10)
			{
				TimeInfo->BossAttack = false;
				TimeInfo->Pattern = 0;
			}
			break;

		case 1:
			if (TimeInfo->Pattern < 6)
			{
				TimeInfo->Pattern++;

				if (TimeInfo->Pattern % 2 == 0)
				{
					for (int j = 0; j < 256; ++j)
					{
						if (PBullet[j] == nullptr)
						{
							PBullet[j] = CreateBullet(
								BossEnemy->TransInfo.Position.x,
								BossEnemy->TransInfo.Position.y + 5.0f,
								0, 2);
							_Direction[j] = GetDirection(Player, PBullet[j]);

							for (int k = 0; k < 256; ++k)
							{
								if (PBullet[k] == nullptr)
								{
									PBullet[k] = CreateBullet(
										BossEnemy->TransInfo.Position.x + 10.0f,
										BossEnemy->TransInfo.Position.y + 5.0f,
										0, 2);
									_Direction[k] = GetDirection(Player,
										PBullet[k]);

									for (int n = 0; n < 256; ++n)
									{
										if (PBullet[n] == nullptr)
										{
											PBullet[n] = CreateBullet(
												BossEnemy->TransInfo.Position.x - 10.0f,
												BossEnemy->TransInfo.Position.y + 5.0f,
												0, 2);
											_Direction[n] = GetDirection(Player,
												PBullet[n]);
											break;
										}
									}
									break;
								}
							}

							break;
						}
					}
				}
			}

			else if (TimeInfo->Pattern >= 6)
			{
				TimeInfo->BossAttack = false;
				TimeInfo->Pattern = 0;
			}
			break;
		}
	}
}

bool Collision(Object* ObjectA, Object* ObjectB)
{
	if (ObjectB->MaxHP >= 1000)
	{
		if (ObjectA->TransInfo.Position.y  < ObjectB->TransInfo.Position.y + 5.5f &&
			ObjectA->TransInfo.Position.y  > ObjectB->TransInfo.Position.y - 5.5f &&
			(ObjectA->TransInfo.Position.x + ObjectA->TransInfo.Scale.x) >=
			ObjectB->TransInfo.Position.x - (strlen((char*)"    .      .-~|           ") / 2) &&
			(ObjectB->TransInfo.Position.x + (strlen((char*)"    .      .-~|           ") / 2) >=
				ObjectA->TransInfo.Position.x))
			return true;
	}

	else if (ObjectB->MaxHP < 1000)
	{
		if (ObjectA->TransInfo.Position.y  < ObjectB->TransInfo.Position.y + 0.5f &&
			ObjectA->TransInfo.Position.y  > ObjectB->TransInfo.Position.y - 0.5f &&
			(ObjectA->TransInfo.Position.x + ObjectA->TransInfo.Scale.x) >=
			ObjectB->TransInfo.Position.x &&
			(ObjectB->TransInfo.Position.x + ObjectB->TransInfo.Scale.x) >=
			ObjectA->TransInfo.Position.x)
			return true;
	}
	return false;
}

char* SetName()
{
	float Width = GetMidleWidth((char*)"�̸��� �Է��ϼ��� : ");
	float Height = 20.0f;
	char Buffer[128] = "";
	char* pName = new char[strlen(Buffer) + 1];

	OnDrawText((char*)"�̸��� �Է��ϼ��� : ", Width, Height);
	SetCursorPosition(Width + strlen("�̸��� �Է��ϼ��� : "), Height);
	cin >> Buffer;
	strcpy(pName, Buffer);

	return pName;
}

int CaculationScore(Object* Player, System* _System, int Score)
{
	_System->RScore.Temp = _System->Score + (_System->Score * (float)((Player->HP / 10) +
		(Player->Fuel / 100))) + (Player->Power * 1000);

	if ((_System->RScore.Temp / 10000) * 10000 > Score)
		Score += 10000;
	else if ((_System->RScore.Temp / 1000) * 1000 > Score)
		Score += 1000;
	else if ((_System->RScore.Temp / 100) * 100 > Score)
		Score += 100;
	else if ((_System->RScore.Temp / 10) * 10 > Score)
		Score += 10;
	else if (_System->RScore.Temp > Score)
		Score += 1;

	else if (_System->RScore.Temp <= Score)
	{
		_System->RScore.Total += _System->RScore.Temp;
		_System->RScore.Temp = 0;
		_System->Complete = true;
	}

	return Score;
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

	Distance = sqrt((x * x) + (y * y));

	return Vector3(x / Distance, y / Distance);
}

Object* CreateBullet(const float _x, const float _y, const int _Power,
	const int Option)
{
	Object* _Object = new Object;
	switch (_Power)
	{
	case 1:
		Initialize(_Object, (char*)"��", 0, 0, (float)_x, (float)_y, 11);
		_Object->Info.Option = 0;
		_Object->Power = 1;
		break;
	case 2:
		Initialize(_Object, (char*)"��", 0, 0, (float)_x, (float)_y, 11);
		_Object->Info.Option = 0;
		_Object->Power = 2;
		break;
	case 0:
		Initialize(_Object, (char*)"��", 0, 0, (float)_x, (float)_y, 11);
		_Object->Info.Option = 0;
		_Object->Power = 3;
		break;
	}

	if (Option == 1)
	{
		Initialize(_Object, (char*)"��", 0, 0, (float)_x, (float)_y + 1.0f,
			14);
		_Object->Info.Option = 1;
	}

	else if (Option == 2)
	{
		Initialize(_Object, (char*)"��", 0, 0, (float)_x, (float)_y + 1.0f,
			14);
		_Object->Info.Option = 2;
	}
	return _Object;
}


Object* CreateItem(const float _x, const float _y)
{
	Object* _Object = new Object;
	switch (rand() % 2)
	{
	case 0:
		Initialize(_Object, (char*)"<P>", 0, 0, (float)_x, (float)_y);
		_Object->Info.Option = 0;
		break;
	case 1:
		Initialize(_Object, (char*)"[+]", 0, 0, (float)_x, (float)_y);
		_Object->Info.Option = 1;
		break;
	}
	return _Object;
}

Object* CreateEnemy(const float _x, const float _y)
{
	Object* _Object = new Object;
	Initialize(_Object, (char*)"��", 1, 1, (float)_x, (float)_y);
	_Object->Info.Option = rand() % 100;
	switch (_Object->Info.Option % 3)
	{
	case 0:
		_Object->HP = 2;
		_Object->Info.Color = 2;
		break;
	case 1:
		_Object->HP = 4;
		_Object->Info.Color = 3;
		break;
	case 2:
		_Object->HP = 8;
		_Object->Info.Color = 4;
		break;
	}
	return _Object;
}

Object* CreateDestination(const float _x, const float _y)
{
	Object* _Object = new Object;
	Initialize(_Object, (char*)"��", 1, 1, (float)_x, (float)_y);

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
	OnDrawText((char*)"      :   -~  ", (Width + _x), (Height - _y) + 1.0f);
	OnDrawText((char*)"   ;!      ;  ", (Width + _x), (Height - _y) + 2.0f);
	OnDrawText((char*)"   !       !  ", (Width + _x), (Height - _y) + 3.0f);
	OnDrawText((char*)" .:,       ,; ", (Width + _x), (Height - _y) + 4.0f);
	OnDrawText((char*)" $          ,,", (Width + _x), (Height - _y) + 5.0f);
	OnDrawText((char*)" $          ,,", (Width + _x), (Height - _y) + 6.0f);
	OnDrawText((char*)" :.         ; ", (Width + _x), (Height - _y) + 7.0f);
	OnDrawText((char*)"   $$$$$$$$~  ", (Width + _x), (Height - _y) + 8.0f);
}

void DrawCircle(const float Width, const float Height, const float _x, const float _y)
{
	OnDrawText((char*)"  @@@@  ", (Width + _x), (Height - _y), 14);
	OnDrawText((char*)"@      @", (Width + _x), (Height - _y) + 1.0f, 14);
	OnDrawText((char*)"@      @", (Width + _x), (Height - _y) + 2.0f, 14);
	OnDrawText((char*)"  @@@@  ", (Width + _x), (Height - _y) + 3.0f, 14);
}

void DrawCross(const float Width, const float Height, const float _x, const float _y)
{

	OnDrawText((char*)"_", (Width + _x + 3), (Height - _y - 1), 12);
	OnDrawText((char*)"__", (Width + _x + 6), (Height - _y - 1), 12);
	OnDrawText((char*)"| |/ /", (Width + _x + 2), (Height - _y - 1) + 1.0f, 12);
	OnDrawText((char*)"|   /", (Width + _x + 2), (Height - _y - 1) + 2.0f, 12);
	OnDrawText((char*)"/   |", (Width + _x + 1), (Height - _y - 1) + 3.0f, 12);
	OnDrawText((char*)"/_/|_|", (Width + _x), (Height - _y - 1) + 4.0f, 12);
}

void ShowUI(Object* Player, System* _System)
{
	float Width = 95.0f - (float)strlen("Score:");


	OnDrawText((char*)"Stage  ", Width, 3.0f);
	OnDrawText(_System->ClearStage + 1, 110.0f, 3.0f);

	OnDrawText((char*)"Score: ", Width, 5.0f);
	OnDrawText(++_System->Score, 110.0f, 5.0f);

	OnDrawText((char*)"��", Width, 7.0f, 2);
	OnDrawText((char*)" X ", Width + strlen("��"), 7.0f);
	OnDrawText(_System->PlayerKill, Width + strlen("�� X "), 7.0f);

	OnDrawText((char*)"��", Width, 13.0f, 14);
	OnDrawText((char*)": �Ϲ� �Ѿ�", Width + 2.0f, 13.0f);
	OnDrawText((char*)"�÷��̾�������� ���ƿɴϴ�.", Width, 14.0f);

	OnDrawText((char*)"��", Width, 16.0f, 14);
	OnDrawText((char*)": ���� �Ѿ�", Width + 2.0f, 16.0f);
	OnDrawText((char*)"5�ʰ� �÷��̾ ����ɴϴ�.", Width, 17.0f);

	OnDrawText((char*)"PlayerHP", Width, 45.0f);
	for (int i = 0; i < Player->MaxHP; ++i)
	{
		if (i + 1 <= Player->HP)
			OnDrawText((char*)"��", Width + (float)(i * 2), 46.0f, 11);
		else
			OnDrawText((char*)"��", Width + (float)(i * 2), 46.0f, 11);
	}

	for (int i = 0; i < 55; ++i)
		OnDrawText((char*)"l", Width - 5.0f, (float)i);

	OnDrawText((char*)"Power Lv.", Width, 50.0f);
	if (Player->Power == 9)
		OnDrawText((char*)"Max", Width + (float)strlen("Power Lv."), 50.0f);
	else
		OnDrawText(Player->Power, Width + (float)strlen("Power Lv."), 50.0f);

	for (int i = 0; i < 6; i += 2)
	{
		if (i / 2 >= Player->Power - 6)
			OnDrawText((char*)"��", Width + 20.0f + (float)i, 51.0f, 6);
		else
			OnDrawText((char*)"��", Width + 20.0f + (float)i, 51.0f, 6);
	}
	for (int i = 0; i < 12; i += 2)
	{
		if (i / 2 >= Player->Power - 3)
			OnDrawText((char*)"��", Width + 14.0f + (float)i, 52.0f, 6);
		else
			OnDrawText((char*)"��", Width + 14.0f + (float)i, 52.0f, 6);
	}
	for (int i = 0; i < 16; i += 2)
	{
		if (i / 2 >= Player->Power - 1)
			OnDrawText((char*)"��", Width + 10.0f + (float)i, 53.0f, 6);
		else
			OnDrawText((char*)"��", Width + 10.0f + (float)i, 53.0f, 6);
	}
}

void HideCursor(bool _Visible)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	CursorInfo.bVisible = _Visible;
	CursorInfo.dwSize = 1;

	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}