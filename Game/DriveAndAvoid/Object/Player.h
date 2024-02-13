#pragma once

#include"../Utility/Vector2D.h"
#include"Barrier.h"

#include"../Object/Character.h"
#include"../Object/Normal.h"

class Player
{
private:

	bool is_active;			//�L����Ԃ��H
	int image;				//�摜�f�[�^
	Vector2D location;		//�ʒu���W
	Vector2D box_size;		//�����蔻��̑傫��
	float angle;			//�p�x
	float speed;			//����
	float hp;				//�̗�
	float fuel;				//�R��
	int barrier_count;		//�o���A�̖���
	Barrier* barrier;		//�o���A

	float fuel_max;

	int sound_c;	//�N���b�V�����ʉ�
	int sound_f;	//�R���񕜌��ʉ�
	int sound_b;	//�o���A���ʉ�

	int crash;
;

public:

	//�R���X�g���N�^(�C���X�^���X�������ɍŏ��ɌĂ΂��֐�)
	Player();

	//�f�X�g���N�^
	~Player();

	void Initialize();		//����������
	void Update();			//�X�V����
	void Draw();			//�`�揈��
	void Finalize();		//�I��������

public:

	void SetActive(bool flg);		//�L���t���O�ݒ�
	void DecreaseHp(float value);	//�̗͌�������
	void DecreaseFuel(float value);			//��������Ȃ��đ��₷�����ł�

	void CarCrash();	//�N���b�V��
	void FuelUp();		//�R����
	void BarrierSound();

	float SetFuel();	//�Ȃ񂾂���

	Vector2D GetLocation() const;	//�ʒu���W�擾
	Vector2D GetBoxSize() const;	//�����蔻��̑傫���擾

	float GetSpeed() const;			//�����擾����
	float GetFuel() const;			//�R���擾
	float GetHp() const;			//�̗͎擾

	int GetBarrierCount() const;	//�o���A�̖����擾
	bool IsBarrier() const;			//�o���A�L�����H���擾

private:

	//�ړ�����
	void Movement();
	
	//��������
	void Acceleration();

	static float SetLeft_Stick_X();	//���X�e�B�b�NX���W���Z�b�g
	static float SetLeft_Stick_Y();	//���X�e�B�b�NY���W���Z�b�g
	static float stick2[2];
};