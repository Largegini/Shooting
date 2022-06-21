#pragma once

struct Vector3
{
	float x = 0.0f, y = 0.0f, z = 0.0f;

	Vector3() {};

	Vector3(float _x, float _y) :
		x(_x), y(_y) {};
	Vector3(float _x, float _y, float _z) :
		x(_x), y(_y), z(_z) {};
};

struct Transform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};

struct Information
{
	char* Texture;

	int BulletCount = 1;
	int ChangeTexture = 0;
	int Color;
	int Option;

	float MoveX = 1.0f;
	float MoveY = 1.0f;
};

struct ChargeInfo
{
	int Stack = 0;

	bool Check = false;

	Transform TransInfo;
};

struct Object
{

	int Power;
	int HP;
	int MaxHP;
	int Fuel;
	int Phase = 1;

	bool Damaged = false;

	Information Info;
	Transform TransInfo;
	ChargeInfo Charge;
};

struct  DrawTextInfo
{
	Information Info;
	Transform TransInfo;
};
struct RecordScore
{
	char* Name;

	int Total=0;
	int Stage1 = 0;
	int Stage2 = 0;
	int Stage3 = 0;
	int Stage4 = 0;
	int Stage5 = 0;
	int Temp = 0;
};

struct TimeInfomation
{
	int ChargeAttackTime = 0;
	int CountTime = 0;
	int EBHomingTime[128] = { 0 };
	int EndTime = 0;
	int Pattern = 0;
	int PaDelay = 0;
	int Result = 0;
	int ShowRanking = 0;
	int SplitTime[128] = { 0 };
	int UseFuel = 0;
	int Warning = 0;

	bool BossAttack = false;
	bool EnemyTime = false;
	bool EBulletTime = false;
};

struct System
{
	int ClearStage = 0;
	int EnemyCount = 0;
	int MaxEnemy = 0;
	int PlayerKill = 0;
	int PlayerNameInput = 0;
	int RandNum = 0;
	int RandNum2 = 0;
	int Scene_State = 0;
	int StageState = 0;
	int StageNum = 0;
	int Score = 0;
	int Fuel = 0;
	
	bool Check = false;
	bool Complete = false;

	RecordScore RScore;
	TimeInfomation TimeInfo;
};