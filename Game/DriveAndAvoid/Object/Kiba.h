#pragma once
#pragma once

#include"Character.h"

class Kiba : public Character
{
private:

	Vector2D location;

	float hp;		//‘Ì—Í
	float power;	//UŒ‚—Í

	//‰æ‘œƒf[ƒ^Ši”[
	int graphic;

public:

	Kiba();
	~Kiba();

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;

};