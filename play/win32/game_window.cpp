#include "game_window.h"
#include <cassert>





GameWindow* GameWindow::this_window_ = nullptr;

GameWindow::GameWindow()
{
	assert(this_window_ == nullptr);
	this_window_ = this;
}

LRESULT CALLBACK GameWindow::GameWindowProc(
	HWND wnd,
	UINT msg,
	WPARAM wparam,
	LPARAM lparam)
{
	LRESULT result{};
	
	switch (msg)
	{
	case WM_CREATE:
		result = this_window_->OnCreate(
					wnd,
					reinterpret_cast<LPCREATESTRUCTW>(lparam));
		break;

	case WM_DESTROY:
		result = this_window_->OnDestroy();
		break;

	case WM_CLOSE:
		result = this_window_->OnClose();
		break;

	default:
		return DefWindowProcW(wnd, msg, wparam, lparam);		
	}

	return result;
}


LRESULT GameWindow::OnCreate(HWND wnd, LPCREATESTRUCTW create_struct)
{
	this_window_->wnd_ = wnd; //attach

	return 0;
}

LRESULT GameWindow::OnDestroy()
{
	PostQuitMessage(0);

	return 0;
}

LRESULT GameWindow::OnClose()
{
	DestroyWindow(wnd_);
	this_window_->wnd_ = nullptr; //detach

	return 0;
}

bool GameWindow::CreateGameWindow(WindowParams& params)
{



	return true;
}