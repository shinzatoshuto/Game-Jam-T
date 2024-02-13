#include"Player.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

float Player::stick2[2] = {};


Player::Player() : is_active(false), image(NULL), location(0.0f), box_size(0.0f), angle(0.0f),crash(),
												  fuel_max(),sound_c(),sound_f(),sound_b(),
				                                  speed(0.0f), hp(0.0f), fuel(0.0f), barrier_count(0),
barrier(nullptr)
{

}

Player::~Player()
{
}

//����������
void Player::Initialize()
{

	is_active = true;

	location = Vector2D(250.0f, 380.0f);
	box_size = Vector2D(26.0f, 54.0f);

	angle = 0.0f;
	speed = 24.5f;			//�X�s�[�h

	hp = 1000;				//�̗�
	fuel = 85000;			//�R��
	//fuel_max = 85000;

	barrier_count = 4;		//�o���A�̖���
	fuel_max = fuel;

	//�摜�̓ǂݍ���
	image = LoadGraph("Resource/images/car1pol.bmp");
	//image = LoadGraph("Resource/images/gentuki.bmp");
	//image = LoadGraph("Resource/images/Player.bmp");
	//image = LoadGraph("Resource/images/car3.bmp");

	//���ʉ�
	sound_c = LoadSoundMem("Resource/sound/carcrash.mp3");
	sound_f = LoadSoundMem("Resource/sound/Fuelup.mp3");
	sound_b = LoadSoundMem("Resource/sound/Barrier.mp3");

	ChangeVolumeSoundMem(255 * 70 / 100, sound_b);


	//�G���[�`�F�b�N
	if (image == -1)
	{
		throw("Resource/images/car1pol.bmp������܂���\n");
	}

}


//�X�V����
void Player::Update()
{

	//����s��Ԃł���΁A���g����]������
	if (!is_active)
	{
		angle += DX_PI_F / 10.0f;
		speed = 8.0f;

		if (angle >= DX_PI_F * 4.0f)
		{
			is_active = true;
				//GraphFilter(image, DX_GRAPH_FILTER_INVERT);
			
		}
		return;
	}

	//�R���̏���
	fuel -= speed;

	//�ړ�����
	Movement();

	//�擾�������X�e�B�b�N�̒l���Z�b�g����
	SetLeft_Stick_X();
	SetLeft_Stick_Y();

	//����������
	Acceleration();

	//START�{�^���ŉ�]����i�����j
	if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
	{
		is_active = false;
	}


	//�o���A����(B�{�^��)
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B) && barrier_count > 0)
	{
		BarrierSound();

		if (barrier == nullptr)
		{
			barrier_count--;
			barrier = new Barrier;
		}
	}

	//�o���A�����i�X�y�[�X�L�[�j
	if (CheckHitKey(KEY_INPUT_SPACE) && barrier_count > 0)
	{
		if (barrier == nullptr)
		{
			barrier_count--;
			barrier = new Barrier;
		}
	}


	//�o���A���������ꂽ��A�X�V���s��
	if (barrier != nullptr)
	{

		//�o���A���Ԃ��o�߂������H���Ă�����A�폜����
		if (barrier->IsFinished(this->speed))
		{
			delete barrier;
			barrier = nullptr;
		}
	}

}

//�`�揈��
void Player::Draw()
{
	//�v���C���[�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, angle, image, TRUE);

	//�o���A���������ꂽ��A�`����s��
	if (barrier != nullptr)
	{
		barrier->Draw(this->location);
	}
}

//�I��������
void Player::Finalize()
{
	//�ǂݍ��񂾉摜���폜
	DeleteGraph(image);

	//�o���A����������Ă�����A�폜����
	if (barrier != nullptr)
	{
		delete barrier;
	}
}

//��Ԑݒ菈��
void Player::SetActive(bool flg)
{
	this->is_active = flg;
}

//�̗͌�������
void Player::DecreaseHp(float value)
{
	this->hp += value;
}

//�R���񕜂����邽�߂̏����i���������ł͂Ȃ��j
void Player::DecreaseFuel(float value)
{
	this->fuel += value;
}

//�N���b�V�����ʉ�
void Player::CarCrash()
{
	if (!is_active)
	{
		PlaySoundMem(sound_c, TRUE);
		//GraphFilter(image, DX_GRAPH_FILTER_INVERT);
		
	}
}

//�R���񕜌��ʉ�
void Player::FuelUp()
{
	PlaySoundMem(sound_f, TRUE);
}

//�o���A���ʉ�
void Player::BarrierSound()
{
	PlaySoundMem(sound_b, TRUE);
}

//�R���̍ő�l
float Player::SetFuel()
{
	return this->fuel_max;
}

//�ʒu���擾����
Vector2D Player::GetLocation() const
{
	return this->location;
}


//�����蔻��̑傫���擾����
Vector2D Player::GetBoxSize() const
{
	return this->box_size;
}

//�����擾����
float Player::GetSpeed() const
{
	return this->speed;
}

//�R���擾����
float Player::GetFuel() const
{
	return this->fuel;
	//return GetFuel();
}

//�̗͎擾����
float Player::GetHp() const
{
	return this->hp;
}

//�o���A�����擾����
int Player::GetBarrierCount() const
{
	return this->barrier_count;
}

//�o���A�L�����H���擾
bool Player::IsBarrier() const
{
	return (barrier != nullptr);
}


//���X�e�B�b�N�̒l���Z�b�g
float Player::SetLeft_Stick_X()
{
	stick2[0] = InputControl::GetLeft_Stick_X();
	
	return stick2[0];
}

//���X�e�B�b�N�̒l���Z�b�g
float Player::SetLeft_Stick_Y()
{
	stick2[1] = InputControl::GetLeft_Stick_Y();

	return stick2[1];
}

//�ړ�����
void Player::Movement()
{
	float x, y;

	Vector2D move = Vector2D(0.0f, 0.0f);
	angle = 0.0f;

	//�\���ړ�����
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_LEFT))
	{
		move += Vector2D(-3.0f, 0.0f);
		angle = -DX_PI_F / 18;
	}
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_RIGHT))
	{
		move += Vector2D(3.0f, 0.0f);
		angle = DX_PI_F / 18;
	}
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_UP))
	{
		move += Vector2D(0.0f, -3.0f);
	}
	if (InputControl::GetButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		move += Vector2D(0.0f, 3.0f);
	}
	//�X�e�B�b�N�ړ�����
	if (InputControl::GetLeft_Stick_X)
	{
		move += Vector2D(stick2[0], 0.0f);

		if (stick2[0] >= 0.1f)
		{
			angle = DX_PI_F / 25;
		}
		else if (stick2[0] <= -0.1f)
		{
			angle = -DX_PI_F / 25;
		}
		
		else if (stick2[0] == 0.0f)
		{
			angle = -DX_PI_F / 25;
		}
	}
	if (InputControl::GetLeft_Stick_Y)
	{
		move -= Vector2D(0.0f, stick2[1]);
	}

	//�L�[����
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		move += Vector2D(-3.0f, 0.0f);
		angle = -DX_PI_F / 18;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		move += Vector2D(3.0f, 0.0f);
		angle = DX_PI_F / 18;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		move += Vector2D(0.0f, -3.0f);
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		move += Vector2D(0.0f, 3.0f);
	}

	if (CheckHitKey(KEY_INPUT_A))
	{
		move += Vector2D(-3.0f, 0.0f);
		angle = -DX_PI_F / 18;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		move += Vector2D(3.0f, 0.0f);
		angle = DX_PI_F / 18;
	}

	location += move;

	//��ʊO�ɍs���Ȃ��悤�ɐ�������
	if ((location.x < box_size.x) || (location.x >= 640.0f - 170.0f) ||
		(location.y < box_size.y) || (location.y >= 480.0f - box_size.y))
	{
		location -= move;
	}
}

//����������
void Player::Acceleration()
{
	//LB�{�^���������ꂽ��A��������
	if (InputControl::GetButtonDown(XINPUT_BUTTON_LEFT_SHOULDER) && speed > 1.0f)
	{
		speed -= 3.0f;
	}

	//RB�{�^���������ꂽ��A��������(���E�˔j�X�s�[�h40�܂ł����܂�^^)
	if (InputControl::GetButtonDown(XINPUT_BUTTON_RIGHT_SHOULDER) && speed < 40.1f)
	{
		speed += 2.0f;
	}

	//�E�g���K�[�ŉ���
	if (InputControl::GetRightTrigger() && speed <= 30.0f)
	{
		speed += 0.3f;
	}
	else
	{
		/*/(�����Ƃ�����茸��)
		for (int i = 0; i < speed - 4; i++)
		{
			speed -= 0.001f;
		}
		*/
		
	}
	//���g���K�[�Ō���
	if (InputControl::GetLeftTrigger() && speed > 1.0f)
	{
		speed -= 0.3f;
	}

	if (CheckHitKey(KEY_INPUT_W) && speed <= 30.0f)
	{
		speed += 0.3f;
	}
	if (CheckHitKey(KEY_INPUT_S) && speed > 1.0f)
	{
		speed -= 0.3f;

	}
}
