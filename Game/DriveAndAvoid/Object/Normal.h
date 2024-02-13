#pragma once

#include"../Utility/Vector2D.h"
#include"Character.h"

class Nomal : public Character
{
private:

	Vector2D location;

	float hp;		//‘Ì—Í
	float power;	//UŒ‚—Í

	//‰æ‘œƒf[ƒ^Ši”[
	int graphic;

public:

	Nomal();
	~Nomal();

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;

};