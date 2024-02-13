#pragma once
#pragma once

#include"Character.h"

class Range : public Character
{
private:

	Vector2D location;

	float hp;		//‘Ì—Í
	float power;	//UŒ‚—Í


	//‰æ‘œƒf[ƒ^Ši”[
	int graphic;

public:

	Range();
	~Range();

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;

};