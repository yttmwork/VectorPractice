#ifndef DIRECTX_LIB_H_
#define DIRECTX_LIB_H_

#include "Window.h"
#include "DirectGraphics.h"
#include "DirectInput.h"

/*
	DirectX�̏�����
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
			�������DirectGraphics�ADirectInput�̏����������Ă�
*/
bool InitDirectX(HINSTANCE instance_handle, HWND window_handle);

/*
	DirectX�̏I��
		�߂�l�F
			�Ȃ�

		�����F
			�Ȃ�

		���e�F
			DirectX���I������
			�Q�[�����[�v�I�����1�x�������s���邱��
*/
void EndDirectX();

#endif
