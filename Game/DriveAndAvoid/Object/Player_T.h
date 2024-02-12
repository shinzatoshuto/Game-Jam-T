#pragma once

class Player_T
{
private:
	int Hp;    //城のHp
	bool is_Pause;  //ポーズか?

private:
	static float stick2[2];

public:

	//コンストラクタ(インスタンス生成時に最初に呼ばれる関数)
	Player_T();

	//デストラクタ
	~Player_T();

	void Initialize();		//初期化処理
	void Update();			//更新処理
	void Draw() const;			//描画処理
	void Finalize();		//終了時処理

private:
	void InputControlUi();

	static float SetLeft_Stick_X();	//左スティックX座標をセット
	static float SetLeft_Stick_Y();	//左スティックY座標をセット
};

