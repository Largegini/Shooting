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

struct System
{
	int Scene_State = 0;
	int StageState = 0;
	int StageNum = 0;
	int Score = 0;
	int ClearStage = 0;
	int RandNum = 0;
	int EnemyCount = 0;
	bool EnemyTime = false;
	bool EBulletTime = false;
};