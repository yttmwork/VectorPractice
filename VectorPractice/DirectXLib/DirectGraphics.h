#ifndef DIRECT_GRAPHICS_H_
#define DIRECT_GRAPHICS_H_

#include <Windows.h>

// 読み込めるテクスチャの最大数
#define MAX_TEXTURE_NUM (100)

/*
	DirectGraphicsの初期化
		戻り値：
			初期化成功：
				true
			初期化失敗：
				false

		引数：
			HWND window_handle：
				DirectGraphicsで描画する対象となるウィンドウのハンドル

		内容：
			DirectXの初期化を行う
			必ずゲームループの前に1度だけ実行すること
			※現状はDirectGraphicsのみ初期化してる
*/
bool InitDirectGraphics(HWND window_handle);

/*
	DirectGraphicsの終了
		戻り値：
			なし

		引数：
			なし

		内容：
			DirectXを終了させる
			ゲームループを抜けた後必ず１度だけ実行すること
*/
void ReleaseDirectGraphics();

/*
	テクスチャ読み込み
		戻り値：
			成功：
				テクスチャ番号(0以上の値)
			失敗：
				-1
		引数：
			char * file_name：
				ファイル名

		内容：
			指定されたテクスチャを読み込む
			成功したらテクスチャ番号が返り、失敗したら-1が返る
*/
int LoadTexture(char *file_name);

/*
	テクスチャの解放
		戻り値：
			なし

		引数：
			int texture_id：
				テクスチャ番号

		内容：
			引数で指定したテクスチャを解放する
*/
void ReleaseTexture(int texture_id);

/*
	描画開始
		戻り値：
			なし

		引数：
			なし

		内容：
			描画処理を開始するための関数
			描画処理はこの関数を呼び出した後に行うこと
*/
void DrawStart();

/*
	描画終了
		戻り値：
			なし

		引数：
			なし

		内容：
			描画処理終了関数
			描画内容を画面に反映するにはこの関数を呼び出す必要がある
*/
void DrawEnd();

/*
	描画
		戻り値：
			なし

		引数：
			int texture_id：
				描画するテクスチャの番号

			float x：
				描画位置(X軸)

			float y：
				描画位置(Y軸)

		内容：
			テクスチャを指定した座標に描画する
			描画するテクスチャの原点は左上を使用する
*/
void Draw(int texture_id, float pos_x, float pos_y);


/*
	描画処理の例

	DrawStart();

	Draw(0, 100, 200);

	Draw(1, 300, 100);

	DrawEnd();

*/

#endif
