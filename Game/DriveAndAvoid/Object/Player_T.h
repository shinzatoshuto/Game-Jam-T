#pragma once

class Player_T
{
private:
	int Hp;    //���Hp
	bool is_Pause;  //�|�[�Y��?

private:
	static float stick2[2];

public:

	//�R���X�g���N�^(�C���X�^���X�������ɍŏ��ɌĂ΂��֐�)
	Player_T();

	//�f�X�g���N�^
	~Player_T();

	void Initialize();		//����������
	void Update();			//�X�V����
	void Draw() const;			//�`�揈��
	void Finalize();		//�I��������

private:
	void InputControlUi();

	static float SetLeft_Stick_X();	//���X�e�B�b�NX���W���Z�b�g
	static float SetLeft_Stick_Y();	//���X�e�B�b�NY���W���Z�b�g
};

