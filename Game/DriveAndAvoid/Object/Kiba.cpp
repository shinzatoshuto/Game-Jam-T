#include"Character.h"
#include"DxLib.h"
#include"Kiba.h"

Kiba::Kiba() : hp(NULL), power(NULL)
{
}

Kiba::~Kiba()
{
}

void Kiba::Initialize()
{

	hp = 500;
	power = 20;

	graphic = LoadGraph("Resource/images/kiba.png");

	if (graphic == -1)
	{
		throw("Resource/images/kiba.png‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}

}

void Kiba::Update()
{
}

void Kiba::Draw()
{
	DrawRotaGraph(location.x, location.y, 0.3, 0.0, graphic, TRUE);
}