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
	int Option;
	int Color;
	float MoveX = 1.0f;
	float MoveY = 1.0f;
};

struct Object
{

	int Power;
	int HP;
	int MaxHP;
	
	Information Info;
	Transform TransInfo;
};

struct  DrawTextInfo
{
	Information Info;
	Transform TransInfo;
};
struct RecordScore
{
	int Total=0;
	int Stage1 = 0;
	int Stage2 = 0;
	int Stage3 = 0;
	int Stage4 = 0;
	int Stage5 = 0;
};

struct System
{
	int ClearStage = 0;
	int EnemyCount = 0;
	int EBHomingTime[128] = { 0 };
	int PlayerKill = 32;
	int RandNum = 0;
	int Scene_State = 0;
	int StageState = 0;
	int StageNum = 0;
	int Score = 0;


	bool EnemyTime = false;
	bool EBulletTime = false;
	RecordScore RScore;
};