#include "Headers.h"
// *의 개수는 우선도

// 탑 다운 형식 
//	*****
// 스테이지 클리어
// 레벨 디자인
// 보스
// 
//	****	
// 스테이지 마다 점수저장
// 한방에 다 죽는 적이 아닌 일정 타수 이상 맞았을 때 죽는 적
// 적 HP
// 차지 공격
// 
// ***
// 마지막 스테이지 클리어시 이름 입력하기
// 플레이어 디자인
// 적 크기, 디자인
// 
// *
//  프로그램을 종료하지 않았다면 이름입력후 점수들 순위로 보여주기
// (종합 점수, 스테이지별 점수)
// 플레이어와 적 충돌
// 위 에서 내려오는 벽
// 폭탄 공격

int main(void)
{
	ULONGLONG Time = GetTickCount64();
	ULONGLONG EnemyTime = GetTickCount64();
	ULONGLONG EBulletTime = GetTickCount64();

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
	Initialize(Player, (char*)"▲", 10, 10, 40.0f, 52.0f);

	Object* Enemy[32];
	for (int i = 0; i < 32; ++i)
		Enemy[i] = nullptr;

	Object* Destination[32];
		for (int i = 0; i < 32; ++i)
			Destination[i] = nullptr;

	Object* PBullet[128];
	for (int i = 0; i < 128; ++i)
		PBullet[i] = nullptr;

	Object* Item[16];
	for (int i = 0; i < 16; ++i)
		Item[i] = nullptr;

	Object* Cursor1 = new Object;
	Initialize(Cursor1, (char*)"◀", 0,0,0.0f, 25.0f);
	Object* Cursor2 = new Object;
	Initialize(Cursor2, (char*)"◀", 0,0,50.0f + (float)strlen("예"), 
		27.0f);
	
	RecordScore* Ranking[10];

	Vector3 Direction[128];
	Vector3 EDirection[32];

	system("mode con:cols=120 lines=55");

	HideCursor(false);
	//테스트용
	SystemInfo->ClearStage = 4;
	while (true)
	{
		if (Time + 100 < GetTickCount64())
		{
			Time  = GetTickCount64();

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
			system("cls");

			SceneManager(CPosition, Cursor1, Cursor2, Player,
				Enemy, PBullet, Item, Destination, Ranking, Direction,EDirection, SystemInfo, TimeInfo);
		}
	}
	return 0;
}