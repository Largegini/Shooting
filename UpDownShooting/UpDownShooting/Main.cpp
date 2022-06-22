#include "Headers.h"

int main(void)
{
	ULONGLONG Time = GetTickCount64();
	ULONGLONG EnemyTime = GetTickCount64();
	ULONGLONG EBulletTime = GetTickCount64();
	ULONGLONG BossAttTime = GetTickCount64();

	DrawTextInfo CPosition[4];

	for (int i = 0; i < 4; ++i)
	{
		srand((GetTickCount() + i * i) * GetTickCount());
		CPosition[i].TransInfo.Position.x = rand() % 80;

		CPosition[i].TransInfo.Position.y = rand() % 45;
	}

	System* SystemInfo = new System;

	TimeInfomation* TimeInfo = new TimeInfomation;

	Object* Player = new Object;
	Initialize(Player, (char*)"┌┃┐", 10, 10, 40.0f, 52.0f);
	Player->Power = 1;
	Player->Info.Color = 11;

	Object* Boss = new Object;
	Initialize(Boss, (char*)"⊙", 1000, 1000, 40.0f, 10.0f);
	Boss->Info.Option = 1;

	Object* Enemy[32];
	for (int i = 0; i < 32; ++i)
		Enemy[i] = nullptr;

	Object* Destination[32];
	for (int i = 0; i < 32; ++i)
		Destination[i] = nullptr;

	Object* PBullet[256];
	for (int i = 0; i < 256; ++i)
		PBullet[i] = nullptr;

	Object* Item[16];
	for (int i = 0; i < 16; ++i)
		Item[i] = nullptr;

	Object* Cursor1 = new Object;
	Initialize(Cursor1, (char*)"◀", 0, 0, 0.0f, 25.0f);
	Object* Cursor2 = new Object;
	Initialize(Cursor2, (char*)"◀", 0, 0, 50.0f + (float)strlen("예"),
		27.0f);

	RecordScore* Ranking[10];
	for (int i = 0; i < 10; ++i)
	{
		Ranking[i] = new RecordScore;
		Initialize(Ranking[i], (char*)"***", 0, 0, 0, 0, 0, 0);
	}
	Vector3 Direction[128];
	Vector3 EDirection[32];

	system("mode con:cols=120 lines=55");

	HideCursor(false);
	//테스트용
	SystemInfo->ClearStage = 4;
	Player->Power = 7;
	
	while (true)
	{
		if (Time + 100 < GetTickCount64())
		{
			Time = GetTickCount64();

			if (SystemInfo->StageNum > 0)
			{
				if (EnemyTime + 3000 < GetTickCount64())
				{
					EnemyTime = GetTickCount64();
					TimeInfo->EnemyTime = true;
				}

				if (EBulletTime + 500 < GetTickCount64())
				{
					EBulletTime = GetTickCount64();
					TimeInfo->EBulletTime = true;
				}
			}

			if (SystemInfo->PlayerKill == 0 && SystemInfo->ClearStage >= 4)
			{
				if (BossAttTime + 1750 + TimeInfo->PaDelay < GetTickCount64() && !TimeInfo->BossAttack)
				{
					BossAttTime = GetTickCount64();
					TimeInfo->BossAttack = true;
					SystemInfo->RandNum2 = rand() % 2;
				}
			}
			system("cls");

			SceneManager(CPosition, Cursor1, Cursor2, Player,
				Enemy, PBullet, Item, Destination, Boss, Ranking, Direction, EDirection, SystemInfo, TimeInfo);
		}
	}
	return 0;
}