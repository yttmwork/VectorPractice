#include <d3d9.h>
#include <d3dx9.h>
#include <time.h>
#include "DirectXLib/Lib.h"

// ウィンドウのサイズ
#define WINDOW_WIDTH (800)
#define WINDOW_HEIGHT (600)

// 描画用データの構造体
struct DrawObject
{
	int m_TextureId;	// テクスチャの種類
	float m_PosX;		// 描画座標X
	float m_PosY;		// 描画座標Y
};

// プレイヤーキャラの挙動処理
void PlayerControl(DrawObject *player)
{
	float speed = 2.0f;
	float vec_x = 0.0f;		// x成分
	float vec_y = 0.0f;		// y成分
	float length = 0.0f;	// 長さ

	// リターンでランダム移動
	if (GetKeyDown(RETURN_KEY) == true)
	{
		player->m_PosX = rand() % WINDOW_WIDTH;
		player->m_PosY = rand() % WINDOW_HEIGHT;
		return;
	}

	// 上下
	if (GetKey(UP_KEY) == true)
	{
		vec_y = -speed;
	} else if (GetKey(DOWN_KEY) == true) {
		vec_y = speed;
	}

	// 左右
	if (GetKey(LEFT_KEY) == true)
	{
		vec_x = -speed;
	} else if(GetKey(RIGHT_KEY) == true) {
		vec_x = speed;
	}

	if (vec_x != 0.0f || vec_y != 0.0f)
	{
		// ベクトルの距離を出す
		length = sqrt(vec_x * vec_x + vec_y * vec_y);

		// 単位ベクトルの成分を計算で出す
		float normal_x = vec_x / length;
		float normal_y = vec_y / length;

		// 単位ベクトルの証明
		//float normal_length = sqrt(normal_x * normal_x + normal_y * normal_y);

		// 単位ベクトルに移動量を反映する
		normal_x *= speed;
		normal_y *= speed;

		// 移動量の照明
		//float move_length = sqrt(normal_x * normal_x + normal_y * normal_y);

		// 移動量を座標に加算
		player->m_PosX += normal_x;
		player->m_PosY += normal_y;

	}
}

void EnemyControl(DrawObject *enemy, DrawObject *player)
{
	// ベクトルを出す
	float vecx = player->m_PosX - enemy->m_PosX;
	float vecy = player->m_PosY - enemy->m_PosY;

	// ベクトルをそのまま座標に足す
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

	// ウィンドウ作成
	HWND window_handle = MakeWindow(hInstance, WINDOW_WIDTH, WINDOW_HEIGHT);

	if (window_handle == 0)
	{
		return 0;
	}

	// DirectX初期化
	if (InitDirectX(hInstance, window_handle) == false)
	{
		return 0;
	}

	// テクスチャの読み込み
	int player_texture = LoadTexture((char*)"Player.png");
	int enemy_texture = LoadTexture((char*)"Enemy.png");
	int bg_texture = LoadTexture((char*)"BackGround.png");

	// プレイヤーオブジェクト作成
	DrawObject player =
	{
		player_texture, 200, 470
	};

	// 敵オブジェクト作成
	DrawObject enemy =
	{
		enemy_texture, 500, 470
	};

	// 背景オブジェクト作成
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
			// キー情報の更新
			KeyUpDate();

			// プレイヤーゲーム処理
			PlayerControl(&player);

			EnemyControl(&enemy, &player);

			// 描画開始(ここから描画処理を書くこと)
			DrawStart();

			// 背景描画
			Draw(bg.m_TextureId, bg.m_PosX, bg.m_PosY);

			// プレイヤー描画
			Draw(player.m_TextureId, player.m_PosX, player.m_PosY);

			// 敵描画
			Draw(enemy.m_TextureId, enemy.m_PosX, enemy.m_PosY);

			// 描画終了(ここまでに描画処理を書くこと)
			DrawEnd();
		}
	}

	// DirectX終了
	EndDirectX();
}
