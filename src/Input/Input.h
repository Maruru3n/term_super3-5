#pragma once

#define KEY_BUF_LEN	(256)
#define MOUSE_BUF_LEN	(3)

class Input
{
private:
	static char currentKeyBuf[KEY_BUF_LEN];
	static char preKeyBuf[KEY_BUF_LEN];

	// マウス関連変数

	static int currentMouseBuf[MOUSE_BUF_LEN];
	static int preMouseBuf[MOUSE_BUF_LEN];

public:
	static void InitInput();

	static void StepInput();

	//キーボード
	static bool IsKeyPush(int key_code);
	static bool IsKeyKeep(int key_code);
	static bool IsKeyRelease(int key_code);
	static bool IsKeyDown(int key_code);

	//マウス
	static int CheckMouse(int mouse_code);
	static int ChangeMouseCode(int mouse_code);

	static bool IsMousePush(int mouse_code);
	static bool IsMouseKeep(int mouse_code);
	static bool IsMouseRelease(int mouse_code);
	static bool IsMouseDown(int mouse_code);


	static char GetCurrentKey(int index) { return currentKeyBuf[index]; }
	static char GetPreKey(int index) { return preKeyBuf[index]; }
};