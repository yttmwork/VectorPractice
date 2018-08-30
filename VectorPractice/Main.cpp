#include <d3d9.h>
#include <d3dx9.h>
#include <time.h>
#include "DirectXLib/Lib.h"

// �E�B���h�E�̃T�C�Y
#define WINDOW_WIDTH (800)
#define WINDOW_HEIGHT (600)

// �`��p�f�[�^�̍\����
struct DrawObject
{
	int m_TextureId;	// �e�N�X�`���̎��
	float m_PosX;		// �`����WX
	float m_PosY;		// �`����WY
};

// �v���C���[�L�����̋�������
void PlayerControl(DrawObject *player)
{
	float speed = 2.0f;
	float vec_x = 0.0f;		// x����
	float vec_y = 0.0f;		// y����
	float length = 0.0f;	// ����

	// ���^�[���Ń����_���ړ�
	if (GetKeyDown(RETURN_KEY) == true)
	{
		player->m_PosX = rand() % WINDOW_WIDTH;
		player->m_PosY = rand() % WINDOW_HEIGHT;
		return;
	}

	// �㉺
	if (GetKey(UP_KEY) == true)
	{
		vec_y = -speed;
	} else if (GetKey(DOWN_KEY) == true) {
		vec_y = speed;
	}

	// ���E
	if (GetKey(LEFT_KEY) == true)
	{
		vec_x = -speed;
	} else if(GetKey(RIGHT_KEY) == true) {
		vec_x = speed;
	}

	if (vec_x != 0.0f || vec_y != 0.0f)
	{
		// �x�N�g���̋������o��
		length = sqrt(vec_x * vec_x + vec_y * vec_y);

		// �P�ʃx�N�g���̐������v�Z�ŏo��
		float normal_x = vec_x / length;
		float normal_y = vec_y / length;

		// �P�ʃx�N�g���̏ؖ�
		//float normal_length = sqrt(normal_x * normal_x + normal_y * normal_y);

		// �P�ʃx�N�g���Ɉړ��ʂ𔽉f����
		normal_x *= speed;
		normal_y *= speed;

		// �ړ��ʂ̏Ɩ�
		//float move_length = sqrt(normal_x * normal_x + normal_y * normal_y);

		// �ړ��ʂ����W�ɉ��Z
		player->m_PosX += normal_x;
		player->m_PosY += normal_y;

	}
}

void EnemyControl(DrawObject *enemy, DrawObject *player)
{
	// �x�N�g�����o��
	float vecx = player->m_PosX - enemy->m_PosX;
	float vecy = player->m_PosY - enemy->m_PosY;

	// �x�N�g�������̂܂܍��W�ɑ���
	//enemy->m_PosX += vecx;
	//enemy->m_PosY += vecy;

	float length = sqrtf((vecx * vecx) + (vecy * vecy));
	float normal_x = vecx / length;
	float normal_y = vecy / length;

	enemy->m_PosX += normal_x;
	enemy->m_PosY += normal_y;
}

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmpLine,
	INT       nCmdShow)
{
	srand((unsigned)time(NULL));

	// �E�B���h�E�쐬
	HWND window_handle = MakeWindow(hInstance, WINDOW_WIDTH, WINDOW_HEIGHT);

	if (window_handle == 0)
	{
		return 0;
	}

	// DirectX������
	if (InitDirectX(hInstance, window_handle) == false)
	{
		return 0;
	}

	// �e�N�X�`���̓ǂݍ���
	int player_texture = LoadTexture((char*)"Player.png");
	int enemy_texture = LoadTexture((char*)"Enemy.png");
	int bg_texture = LoadTexture((char*)"BackGround.png");

	// �v���C���[�I�u�W�F�N�g�쐬
	DrawObject player =
	{
		player_texture, 200, 470
	};

	// �G�I�u�W�F�N�g�쐬
	DrawObject enemy =
	{
		enemy_texture, 500, 470
	};

	// �w�i�I�u�W�F�N�g�쐬
	DrawObject bg =
	{
		bg_texture, 0, 0
	};

	while (true)
	{
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else {
			// �L�[���̍X�V
			KeyUpDate();

			// �v���C���[�Q�[������
			PlayerControl(&player);

			EnemyControl(&enemy, &player);

			// �`��J�n(��������`�揈������������)
			DrawStart();

			// �w�i�`��
			Draw(bg.m_TextureId, bg.m_PosX, bg.m_PosY);

			// �v���C���[�`��
			Draw(player.m_TextureId, player.m_PosX, player.m_PosY);

			// �G�`��
			Draw(enemy.m_TextureId, enemy.m_PosX, enemy.m_PosY);

			// �`��I��(�����܂łɕ`�揈������������)
			DrawEnd();
		}
	}

	// DirectX�I��
	EndDirectX();
}
