#include "Headers.h"
// *�� ������ �켱��

// ž �ٿ� ���� 
// 
// �÷��̾�� �� �浹
// �� �Ѿ˰� �÷��̾� �浹
// �� �Ѿ˰� �÷��̾� �浹 �� �÷��̾� ü�� ����
// 
// �� ũ��, ������, ����
// �÷��̾� ������
// 
//	*****	������ ��ǥ�� ������ ���ؼ� ���ƴٴϴ� ��(�� �̵�)
// �ѹ濡 �� �״� ���� �ƴ� ���� Ÿ�� �̻� �¾��� �� �״� ��
// ������ �Ѿ� �� ���� �÷��ִ� ������ ���ٴϱ�
// �Ŀ����� ǥ��
// ü�� ȸ�� ������ ���ٴϱ�
// �� ���� �������� ��
// �� �Ʒ� �Ӹ��ƴ϶� �¿�ε� ��ȯ�غ���?
// ���� ����

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
	Initialize(Player, (char*)"��", 40.0f, 52.0f);

	Object* Enemy[32];
	for (int i = 0; i < 32; ++i)
		Enemy[i] = nullptr;
	
	Object* PBullet[128];
	for (int i = 0; i < 128; ++i)
		PBullet[i] = nullptr;

	Object* Cursor1 = new Object;
	Initialize(Cursor1, (char*)"��", 0.0f, 25.0f);
	Object* Cursor2 = new Object;
	Initialize(Cursor2, (char*)"��", 50.0f + (float)strlen("��"), 27.0f);
	
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