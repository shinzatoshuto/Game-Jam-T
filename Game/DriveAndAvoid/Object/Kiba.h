#pragma once
#pragma once

#include"Character.h"

class Kiba : public Character
{
private:

	float hp;		//‘Ì—Í
	float power;	//UŒ‚—Í

	//‰æ‘œƒf[ƒ^Ši”[
	int* graphic;

public:

	virtual void Initialize() override;
	virtual void Draw() override;
	virtual void Update() override;

};