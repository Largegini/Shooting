#include "Headers.h"
// *�� ������ �켱��

// ž �ٿ� ���� 
// 
// �� ũ��� ������
//  �÷��̾�� �� �浹
// �� �Ѿ˰� �÷��̾� �浹
// �� �Ѿ˰� �÷��̾� �浹 �� �÷��̾� ü�� ����
// �÷��̾� �Ѿ˰� �� �浹
// �÷��̾� �̵�(����Ű)
// �÷��̾� �Ѿ� �߻�(SpaceŰ)
// �� �Ѿ� �߻�
// 
// �� ũ��, ������, ����
// �÷��̾� ������
// 
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
	Object* Cursor1 = new Object;
	Initialize(Cursor1, (char*)"��", 0.0f, 25.0f);
	Object* Cursor2 = new Object;
	Initialize(Cursor2, (char*)"��", 50.0f + (float)strlen("��"), 27.0f);

	system("mode con:cols=120 lines=55");
	HideCursor(false);

	while (true)
	{
		if (Time + 100 < GetTickCount64())
		{
			Time  = GetTickCount64();
			system("cls");

			SceneManager(CPosition, Cursor1, Cursor2, Player, SystemInfo);
		}
	}
}