#pragma once

#include "PrimaryView.h"
#include "SignInUpView.h"
#include "UserPanel.h"

class UnitOfView
{
private:
	PrimaryView _startView;
	SignInUpView _signInUpView;
	UserPanel _userPanel;

public:
	UnitOfView() {
		_startView = * new PrimaryView();
		_signInUpView = * new SignInUpView();
		_userPanel = * new UserPanel();
	}

	PrimaryView Start() {
		return _startView;
	}

	SignInUpView SigningOnIn() {
		return _signInUpView;
	}

	UserPanel Panel() {
		return _userPanel;
	}

	void LoadMenu() {
		_startView.RenderStartView(_signInUpView);
	}
};

