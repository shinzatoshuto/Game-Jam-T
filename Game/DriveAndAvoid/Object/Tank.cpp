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

	graphic = LoadGraph("Resource/images/war_shield_man.png");

	if (graphic == -1)
	{
		throw("Resource/images/war_shield_man.png‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}

}

void Tank::Update()
{
}

void Tank::Draw()
{
	DrawRotaGraph(location.x, location.y, 0.3, 0.0, graphic, TRUE);
}