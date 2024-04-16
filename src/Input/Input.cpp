#include "DxLib.h"
#include "Input.h"

char Input::currentKeyBuf[];
char Input::preKeyBuf[];

// マウス関連変数

int Input::currentMouseBuf[];
int Input::preMouseBuf[];

void Input::InitInput()
{
	for (int i=0; i < KEY_BUF_LEN; i++)
	{
		currentKeyBuf[i] = '\0';
		preKeyBuf[i] = '\0';
	}
	for (int i = 0; i < MOUSE_BUF_LEN; i++)
	{
		currentMouseBuf[i] = 0;
		preMouseBuf[i] = 0;
	}
}

void Input::StepInput()
{
	for (int i = 0; i < KEY_BUF_LEN; i++)
		preKeyBuf[i] = currentKeyBuf[i];

	for (int i = 0; i < MOUSE_BUF_LEN; i++)
		preMouseBuf[i] = currentMouseBuf[i];

	GetHitKeyStateAll(currentKeyBuf);

	currentMouseBuf[0] = CheckMouse(MOUSE_INPUT_LEFT);
	currentMouseBuf[1] = CheckMouse(MOUSE_INPUT_RIGHT);
	currentMouseBuf[2] = CheckMouse(MOUSE_INPUT_MIDDLE);
}

//今押された
bool Input::IsKeyPush(int key_code)
{
	//前フレで押されてない かつ 現フレで押されている
	if (preKeyBuf[key_code] == 0 && currentKeyBuf[key_code] == 1)
		return true;

	//押されてないので false
	return false;
}

//押され続けている
bool Input::IsKeyKeep(int key_code)
{
	//前フレでおされている かつ 現フレで押されている
	if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 1)
		return true;

	return false;
}

//離された
bool Input::IsKeyRelease(int key_code)
{
	//前フレで押されていた かつ 現フレで押されていない
	if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 0)
		return true;

	return false;
}

//単純に押されているか
bool Input::IsKeyDown(int key_code)
{
	//現フレで押されている（前フレの状態は関係なし）
	if (currentKeyBuf[key_code] == 1)
		return true;

	return false;
}

int Input::CheckMouse(int mouse_code)
{
	if ((GetMouseInput() & mouse_code) != 0){
		return 1;
	}
	else {
		return 0;
	}
}

int Input::ChangeMouseCode(int mouse_code)
{
	if (mouse_code == MOUSE_INPUT_LEFT)
		return 0;
	if (mouse_code == MOUSE_INPUT_RIGHT)
		return 1;
	if (mouse_code == MOUSE_INPUT_MIDDLE)
		return 2;

	return 3;
}

//今押された
bool Input::IsMousePush(int mouse_code)
{
	mouse_code = ChangeMouseCode(mouse_code);

	if (mouse_code == 3)
		return false;

	//前フレで押されてない かつ 現フレで押されている
	if (preMouseBuf[mouse_code] == 0 && currentMouseBuf[mouse_code] == 1)
		return true;

	//押されてないので false
	return false;
}

//押され続けている
bool Input::IsMouseKeep(int mouse_code)
{
	mouse_code = ChangeMouseCode(mouse_code);

	if (mouse_code == 3)
		return false;

	//前フレでおされている かつ 現フレで押されている
	if (preMouseBuf[mouse_code] == 1 && currentMouseBuf[mouse_code] == 1)
		return true;

	return false;
}

//離された
bool Input::IsMouseRelease(int mouse_code)
{
	mouse_code = ChangeMouseCode(mouse_code);

	if (mouse_code == 3)
		return false;

	//前フレで押されていた かつ 現フレで押されていない
	if (preMouseBuf[mouse_code] == 1 && currentMouseBuf[mouse_code] == 0)
		return true;

	return false;
}

//単純に押されているか
bool Input::IsMouseDown(int mouse_code)
{
	mouse_code = ChangeMouseCode(mouse_code);

	if (mouse_code == 3)
		return false;

	//現フレで押されている（前フレの状態は関係なし）
	if (currentMouseBuf[mouse_code] == 1)
		return true;

	return false;
}