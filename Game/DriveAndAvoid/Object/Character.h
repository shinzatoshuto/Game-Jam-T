#pragma once


#include"../Utility/Vector2D.h"
#include"DxLib.h"

#define CHARACTER_SPEED 1.0f


//キャラクターの種類
enum CharacterType
{
	Nomal,	//ノーマル
	Tank,	//タンク
	Range,	//範囲攻撃
	Kiba	//騎馬
};

//キャラクターの基底クラス
class Character
{

public:

	//コンストラクタ
	Character() {};

	virtual ~Character() {};

	virtual void Initialize() {};	//初期化処理 
	virtual void Update() {};		//更新処理 
	virtual void Draw() {};			//描画処理 

};