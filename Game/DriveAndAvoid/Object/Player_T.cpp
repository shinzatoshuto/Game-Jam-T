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
	//����s��Ԃł���΁A���g����]������
	if (!is_Pause)
	{
		//START�{�^���ŉ�]����i�����j
		if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
		{
			is_Pause = true;
		}
		return;
	}

	//START�{�^���ŉ�]����i�����j
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

//���X�e�B�b�N�̒l���Z�b�g
float Player_T::SetLeft_Stick_X()
{
	stick2[0] = InputControl::GetLeft_Stick_X();

	return stick2[0];
}

//���X�e�B�b�N�̒l���Z�b�g
float Player_T::SetLeft_Stick_Y()
{
	stick2[1] = InputControl::GetLeft_Stick_Y();

	return stick2[1];
}

void Player_T::InputControlUi()
{
	//�\���ړ�����
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_LEFT))
	{
		
	}
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_RIGHT))
	{
		
	}

	//�X�e�B�b�N�ړ�����
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