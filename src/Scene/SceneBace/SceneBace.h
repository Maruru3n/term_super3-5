#pragma once

class SceneBace
{
protected:
	int m_bg_handle;

public:
	virtual void Init() = 0;
	virtual void Step() = 0;
	virtual void Draw() = 0;
	virtual void Fin() = 0;
};