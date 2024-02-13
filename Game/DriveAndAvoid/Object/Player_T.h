#pragma once
#include "../Utility/Vector2D.h"
#include "Character.h"

#define _MAX_CHARACTOR_ 10

class Player_T
{
private:
	int Hp;    //���Hp
	bool is_Pause;  //�|�[�Y��?
	int Cursor;     //�J�[�\��
	int Level;      //Level�̊Ǘ�
	int ExPoint;    //�o���l�̊Ǘ�

	Character** chara;

	int charaCount;

private:
	static float stick2[2];
	static Vector2D stick[2];
	
public:

	//�R���X�g���N�^(�C���X�^���X�������ɍŏ��ɌĂ΂��֐�)
	Player_T();

	//�f�X�g���N�^
	~Player_T();

	void Initialize();		//����������
	void Update();			//�X�V����
	void Draw() const;			//�`�揈��
	void Finalize();		//�I��������

	void DecreaseCastleHp(float Attack);
	void SetExPoint(int point);

	bool Is_PauseCheck() { return this->is_Pause; }
	int GetCursor() { return this->Cursor; }
	int GetCastleHp() { return this->Hp; }
	int GetExPoint() { return this->ExPoint; }
	int GetLevel() { return this->Level; }

private:
	void InputControlUi();

	static float SetLeft_Stick_X();	//���X�e�B�b�NX���W���Z�b�g
	static float SetLeft_Stick_Y();	//���X�e�B�b�NY���W���Z�b�g
	static float SetRight_Stick_X();//�E�X�e�B�b�NY���W���Z�b�g
};

