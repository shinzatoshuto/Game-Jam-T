#include "Player_T.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

float Player_T::stick2[2] = {};

Player_T::Player_T() : Hp(0)
{

}

Player_T::~Player_T()
{

}

void Player_T::Initialize()
{
	Hp = 1000;
}

void Player_T::Update()
{
	//操作不可状態であれば、自身を回転させる
	if (!is_Pause)
	{
		//STARTボタンで回転する（多分）
		if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
		{
			is_Pause = true;
		}
		return;
	}

	//STARTボタンで回転する（多分）
	if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
	{
		is_Pause = false;
	}

	InputControlUi();


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

void Player_T::InputControlUi()
{
	//十字移動処理
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_LEFT))
	{
		
	}
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_RIGHT))
	{
		
	}

	//スティック移動処理
	if (InputControl::GetLeft_Stick_X)
	{
		if (stick2[0] >= 0.1f)
		{
			
		}
		else if (stick2[0] <= -0.1f)
		{
			
		}

		else if (stick2[0] == 0.0f)
		{

		}
	}

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