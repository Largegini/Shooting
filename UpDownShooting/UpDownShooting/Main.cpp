#include "Headers.h"
// *의 개수는 우선도

// 탑 다운 형식 
// 
// 플레이어와 적 충돌
// 적 총알과 플레이어 충돌
// 적 총알과 플레이어 충돌 후 플레이어 체력 감소
// 
// 적 크기, 디자인, 정보
// 플레이어 디자인
// 
//	*****	랜덤한 좌표로 방향을 정해서 날아다니는 적(적 이동)
// 한방에 다 죽는 적이 아닌 일정 타수 이상 맞았을 때 죽는 적
// 나오는 총알 갯 수를 늘려주는 아이템 떠다니기
// 파워레벨 표시
// 체력 회복 아이템 떠다니기
// 위 에서 내려오는 벽
// 위 아래 뿐만아니라 좌우로도 전환해보기?
// 차지 공격

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

	Object* Player = new Object;
	Initialize(Player, (char*)"▲", 40.0f, 52.0f);

	Object* Enemy[32];
	for (int i = 0; i < 32; ++i)
		Enemy[i] = nullptr;
	
	Object* PBullet[128];
	for (int i = 0; i < 128; ++i)
		PBullet[i] = nullptr;

	Object* Cursor1 = new Object;
	Initialize(Cursor1, (char*)"◀", 0.0f, 25.0f);
	Object* Cursor2 = new Object;
	Initialize(Cursor2, (char*)"◀", 50.0f + (float)strlen("예"), 27.0f);
	
	Vector3 Direction[128];

	system("mode con:cols=120 lines=55");

	HideCursor(false);

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
					SystemInfo->EnemyTime = true;
				}

				if (EBulletTime + 500 < GetTickCount64())
				{
					EBulletTime = GetTickCount64();
					SystemInfo->EBulletTime = true;
				}
			}
			system("cls");

			SceneManager(CPosition, Cursor1, Cursor2, Player,
				Enemy, PBullet,Direction, SystemInfo);
		}
	}

	return 0;
}