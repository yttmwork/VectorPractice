#ifndef DIRECT_GRAPHICS_H_
#define DIRECT_GRAPHICS_H_

#include <Windows.h>

// �ǂݍ��߂�e�N�X�`���̍ő吔
#define MAX_TEXTURE_NUM (100)

/*
	DirectGraphics�̏�����
		�߂�l�F
			�����������F
				true
			���������s�F
				false

		�����F
			HWND window_handle�F
				DirectGraphics�ŕ`�悷��ΏۂƂȂ�E�B���h�E�̃n���h��

		���e�F
			DirectX�̏��������s��
			�K���Q�[�����[�v�̑O��1�x�������s���邱��
			�������DirectGraphics�̂ݏ��������Ă�
*/
bool InitDirectGraphics(HWND window_handle);

/*
	DirectGraphics�̏I��
		�߂�l�F
			�Ȃ�

		�����F
			�Ȃ�

		���e�F
			DirectX���I��������
			�Q�[�����[�v�𔲂�����K���P�x�������s���邱��
*/
void ReleaseDirectGraphics();

/*
	�e�N�X�`���ǂݍ���
		�߂�l�F
			�����F
				�e�N�X�`���ԍ�(0�ȏ�̒l)
			���s�F
				-1
		�����F
			char * file_name�F
				�t�@�C����

		���e�F
			�w�肳�ꂽ�e�N�X�`����ǂݍ���
			����������e�N�X�`���ԍ����Ԃ�A���s������-1���Ԃ�
*/
int LoadTexture(char *file_name);

/*
	�e�N�X�`���̉��
		�߂�l�F
			�Ȃ�

		�����F
			int texture_id�F
				�e�N�X�`���ԍ�

		���e�F
			�����Ŏw�肵���e�N�X�`�����������
*/
void ReleaseTexture(int texture_id);

/*
	�`��J�n
		�߂�l�F
			�Ȃ�

		�����F
			�Ȃ�

		���e�F
			�`�揈�����J�n���邽�߂̊֐�
			�`�揈���͂��̊֐����Ăяo������ɍs������
*/
void DrawStart();

/*
	�`��I��
		�߂�l�F
			�Ȃ�

		�����F
			�Ȃ�

		���e�F
			�`�揈���I���֐�
			�`����e����ʂɔ��f����ɂ͂��̊֐����Ăяo���K�v������
*/
void DrawEnd();

/*
	�`��
		�߂�l�F
			�Ȃ�

		�����F
			int texture_id�F
				�`�悷��e�N�X�`���̔ԍ�

			float x�F
				�`��ʒu(X��)

			float y�F
				�`��ʒu(Y��)

		���e�F
			�e�N�X�`�����w�肵�����W�ɕ`�悷��
			�`�悷��e�N�X�`���̌��_�͍�����g�p����
*/
void Draw(int texture_id, float pos_x, float pos_y);


/*
	�`�揈���̗�

	DrawStart();

	Draw(0, 100, 200);

	Draw(1, 300, 100);

	DrawEnd();

*/

#endif
