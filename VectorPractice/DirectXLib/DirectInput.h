#ifndef DIRECT_INPUT_H_
#define DIRECT_INPUT_H_

#include <Windows.h>

// �L�[���GetKey�V���[�Y�̊֐��Ŏg�p����
#define CLEAR_KEY	0x0000		// �L�[�N���A�p
#define UP_KEY		0x0001		// ��L�[
#define DOWN_KEY	0x0002		// ���L�[
#define LEFT_KEY	0x0004		// ���L�[
#define RIGHT_KEY	0x0008		// �E�L�[
#define RETURN_KEY	0x0010		// ���^�[���L�[

/*
	DirectInput�̏�����
		�߂�l�F
			���� => true
			���s => false

		�����F
			HINSTANCE instance_handle
				�Ώۂ̃A�v���̃C���X�^���X�n���h��

			HWND window_handle
				�E�B���h�E�n���h��

		���e�F
			DirectInput������������
			����������true�A���s������false
*/
bool InitDirectInput(HINSTANCE instance_handle, HWND window_handle);

/*
	DirectInput�̉��
		�߂�l�F
			�Ȃ�

		�����F
			�Ȃ�

		���e�F
			DirectInput���������
*/
void ReleaseDirectInput();

/*
	�L�[���̍X�V
		�߂�l�F
			�Ȃ�

		�����F
			�Ȃ�

		���e�F
			�L�[�̏����X�V����GetKey�V���[�Y�̊֐��̎擾�����ŐV�ɂ���
			���̏����͖��t���[���̊J�n���ɌĂяo������
*/
void KeyUpDate();

/*
	�L�[�������Ă邩�𔻒�
		�߂�l�F
			������Ă� => true
			������ĂȂ� => false

		�����F
			DWORD key_code
				���f�������L�[�R�[�h

		���e
			�L�[��������Ă���Ȃ�true�A������Ă��Ȃ��Ȃ�false��Ԃ�
*/
bool GetKey(DWORD key_code);

/*
	�L�[���������u�Ԃ𔻒�
		�߂�l�F
			�������u�� => true
			�������u�Ԃ���Ȃ� => false

		�����F
			DWORD key_code
				���f�������L�[�R�[�h

		���e
			�L�[�������ꂽ�u�ԂȂ�true�A������ĂȂ��u�ԂȂ�false
*/
bool GetKeyDown(DWORD key_code);

/*
	�L�[�𗣂����u�Ԃ𔻒�
		�߂�l�F
			�������u�� => true
			�������u�Ԃ���Ȃ� => false

		�����F
			DWORD key_code
				���f�������L�[�R�[�h

		���e
			�L�[���������u�ԂȂ�true�A�������u�Ԃ���Ȃ��Ȃ�false
*/
bool GetKeyUp(DWORD key_code);

#endif
