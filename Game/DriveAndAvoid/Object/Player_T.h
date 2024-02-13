#pragma once
#include "../Utility/Vector2D.h"
#include "Character.h"

#define _MAX_CHARACTOR_ 10

class Player_T
{
private:
	int Hp;    //城のHp
	bool is_Pause;  //ポーズか?
	int Cursor;     //カーソル
	int Level;      //Levelの管理
	int ExPoint;    //経験値の管理

	Character** chara;

	int charaCount;

private:
	static float stick2[2];
	static Vector2D stick[2];
	
public:

	//コンストラクタ(インスタンス生成時に最初に呼ばれる関数)
	Player_T();

	//デストラクタ
	~Player_T();

	void Initialize();		//初期化処理
	void Update();			//更新処理
	void Draw() const;			//描画処理
	void Finalize();		//終了時処理

	void DecreaseCastleHp(float Attack);
	void SetExPoint(int point);

	bool Is_PauseCheck() { return this->is_Pause; }
	int GetCursor() { return this->Cursor; }
	int GetCastleHp() { return this->Hp; }
	int GetExPoint() { return this->ExPoint; }
	int GetLevel() { return this->Level; }

private:
	void InputControlUi();

	static float SetLeft_Stick_X();	//左スティックX座標をセット
	static float SetLeft_Stick_Y();	//左スティックY座標をセット
	static float SetRight_Stick_X();//右スティックY座標をセット
};

