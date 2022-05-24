#include "Headers.h"
// *의 개수는 우선도

// 탑 다운 형식 
// 
// 맵 크기와 디자인
//  플레이어와 적 충돌
// 적 총알과 플레이어 충돌
// 적 총알과 플레이어 충돌 후 플레이어 체력 감소
// 플레이어 총알과 적 충돌
// 플레이어 이동(방향키)
// 플레이어 총알 발사(Space키)
// 적 총알 발사
// 
// 적 크기, 디자인, 정보
// 플레이어 디자인
// 
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

	system("mode con:cols=120 lines=55");
	HideCursor(false);

	while (true)
	{
		if (Time + 100 < GetTickCount64())
		{
			Time  = GetTickCount64();
			system("cls");

			SceneManager(Scene_State);
		}
	}
}