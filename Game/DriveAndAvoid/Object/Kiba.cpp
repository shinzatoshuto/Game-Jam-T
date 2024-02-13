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

	LoadGraph("Resource/images/kiba.png");
}

void Kiba::Update()
{
}

void Kiba::Draw()
{
	DrawRotaGraph(location.x, location.y, 1.0, 0.0, graphic, TRUE);
}