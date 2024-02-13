#include"Character.h"
#include"Normal.h"
#include"DxLib.h"

Nomal::Nomal() : hp(NULL), power(NULL), graphic(NULL), location(0.0f)
{
}

Nomal::~Nomal()
{
}

void Nomal::Initialize()
{

	hp = 100;
	power = 10;
	graphic = LoadGraph("Resource/images/walking2_man.png");

	if (graphic == -1)
	{
		throw("Resource/images/walking2_man.png‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}

}

void Nomal::Update()
{
	
}


void Nomal::Draw()
{
	DrawRotaGraph(location.x, location.y, 0.3, 0.0, graphic, TRUE);
}