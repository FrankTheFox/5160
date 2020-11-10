#pragma once
#include <windows.h>
#include <string>



struct WindowParams
{
	HINSTANCE instance_exe;
	int fullscreen;
	int x;
	int y;
	int width;
	int height;
	std::wstring name;

	WindowParams() :
		instance_exe{},
		fullscreen{},
		x{},
		y{},
		width{},
		height{},
		name{}
	{
		// ctor
	}

	WindowParams(const WindowParams&) = delete;
	WindowParams& operator=(const WindowParams&) = delete;
};


class GameWindow
{
public:
	GameWindow(const GameWindow&) = delete;
	GameWindow& operator=(const GameWindow&) = delete;
	GameWindow();

public:
	bool CreateGameWindow(WindowParams &params);

private:
	static LRESULT CALLBACK GameWindowProc(
		HWND wnd,
		UINT msg,
		WPARAM wparam,
		LPARAM lparam);

private: //Handler
	LRESULT OnCreate(HWND wnd, LPCREATESTRUCTW create_struct);
	LRESULT OnDestroy();
	LRESULT OnClose();

private:
	HWND wnd_;
	static GameWindow* this_window_;
};