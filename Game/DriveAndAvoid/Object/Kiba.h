#pragma once
#pragma once

#include"Character.h"

class Kiba : public Character
{
private:

	Vector2D location;

	float hp;		//�̗�
	float power;	//�U����

	//�摜�f�[�^�i�[
	int graphic;

public:

	Kiba();
	~Kiba();

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;

};