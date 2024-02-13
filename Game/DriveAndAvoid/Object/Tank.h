#pragma once

#include"Character.h"

class Tank : public Character
{
private:

	Vector2D location;

	float hp;		//�̗�
	float power;	//�U����

	//�摜�f�[�^�i�[
	int graphic;

public:

	Tank();
	~Tank();

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;

};