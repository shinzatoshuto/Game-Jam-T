#include"Character.h"
#include"DxLib.h"
#include"Range.h"

Range::Range() : hp(NULL), power(NULL)
{
}

Range::~Range()
{
}

void Range::Initialize()
{
	hp = 500;
	power = 20;

	graphic = LoadGraph("Resource/images/kiba.png");

	if (graphic == -1)
	{
		throw("Resource/images/kiba.png‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}
}

void Range::Update()
{
}

void Range::Draw()
{
	DrawRotaGraph(location.x, location.y, 0.3, 0.0, graphic, TRUE);
}