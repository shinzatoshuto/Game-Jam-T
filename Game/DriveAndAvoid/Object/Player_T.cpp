#include "Player_T.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

float Player_T::stick2[2] = {};
Vector2D Player_T::stick[2] = {};

Player_T::Player_T() : Hp(0), Cursor(0)
{

}

Player_T::~Player_T()
{

}

void Player_T::Initialize()
{
	Hp = 1000;
	Cursor = 0;
}

void Player_T::Update()
{
	InputControlUi();

	//操作不可状態であれば、自身を回転させる
	if (!is_Pause)
	{
		//もう一度Startボタンを押すと、Pause解除
		if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
		{
			is_Pause = true;
		}
		return;
	}

	//STARTボタンでPause
	if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
	{
		is_Pause = false;
	}


}

void Player_T::Draw() const
{

}

void Player_T::Finalize()
{

}

//左スティックの値をセット
float Player_T::SetLeft_Stick_X()
{
	stick2[0] = InputControl::GetLeft_Stick_X();

	return stick2[0];
}

//左スティックの値をセット
float Player_T::SetLeft_Stick_Y()
{
	stick2[1] = InputControl::GetLeft_Stick_Y();

	return stick2[1];
}

//右スティックの値をセット
float Player_T::SetRight_Stick_X()
{
	stick[0] = InputControl::GetLeft_Stick_Y();

	return stick2[0];
}

void Player_T::InputControlUi()
{
	if (!is_Pause)
	{
		//十字移動処理
		if (InputControl::GetButton(XINPUT_BUTTON_DPAD_LEFT))
		{
			Cursor--;
			if (Cursor < 0)
			{
				Cursor = 4;
			}
		}
		if (InputControl::GetButton(XINPUT_BUTTON_DPAD_RIGHT))
		{
			Cursor++;
			if (Cursor > 4)
			{
				Cursor = 0;
			}
		}

		//スティック移動処理
		if (InputControl::GetLeft_Stick_X)
		{
			if (stick2[0] >= 0.1f)
			{
				Cursor++;
				if (Cursor > 4)
				{
					Cursor = 0;
				}
			}
			else if (stick2[0] <= -0.1f)
			{
				Cursor--;
				if (Cursor < 0)
				{
					Cursor = 4;
				}
			}
			else if (stick2[0] == 0.0f)
			{
				Cursor;
			}
		}

		if (InputControl::GetRightStick)
		{
			if (stick[0].x >= 0.1f)
			{
				Cursor++;
				if (Cursor > 4)
				{
					Cursor = 0;
				}
			}
			else if (stick[0].x <= -0.1f)
			{
				Cursor--;
				if (Cursor < 0)
				{
					Cursor = 4;
				}
			}
			else if (stick[0].x == 0.0f)
			{
				Cursor;
			}
		}
	}
	else
	{
		if (InputControl::GetLeft_Stick_Y)
		{

		}
		if (InputControl::GetButton(XINPUT_BUTTON_DPAD_UP))
		{

		}
		if (InputControl::GetButton(XINPUT_BUTTON_DPAD_DOWN))
		{

		}
	}
}

void Player_T::DecreaseCastleHp(float Attack)
{
	this->Hp -= Attack;
}

void Player_T::SetExPoint(int point)
{
	this->ExPoint += point;

}