#include"Character.h"
#include"DxLib.h"
#include"Tank.h"

Tank::Tank() : hp(NULL), power(NULL), location(0.0f)
{
}

Tank::~Tank()
{
}

void Tank::Initialize()
{
	hp = 500;
	power = 20;

	LoadGraph("Resource/images/war_shield_man.png");
}

void Tank::Update()
{
}

void Tank::Draw()
{
	DrawRotaGraph(location.x, location.y, 1.0, 0.0, graphic, TRUE);
}