#ifndef WINDOW_H_
#define WINDOW_H_

#include <Windows.h>

/*
	�E�B���h�E�쐬
		�߂�l�F
			�쐬�����F
				��0
			�쐬���s�F
				-1

		�����F
			HINSTANCE instance
				�E�B���h�E���쐬����A�v���̃C���X�^���X�n���h��

			int width
				���̃T�C�Y

			int height
				�c�̃T�C�Y

		���e�F
			�����Ŏw�肵���T�C�Y�ŃE�B���h�E���쐬����
			����������Window�n���h�����Ԃ�A���s������-1���Ԃ�
*/
HWND MakeWindow(HINSTANCE instance, int width, int height);

#endif
