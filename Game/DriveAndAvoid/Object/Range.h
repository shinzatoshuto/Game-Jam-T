#pragma once
#pragma once

#include"Character.h"

class Range : public Character
{
private:

	Vector2D location;

	float hp;		//�̗�
	float power;	//�U����


	//�摜�f�[�^�i�[
	int graphic;

public:

	Range();
	~Range();

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;

};