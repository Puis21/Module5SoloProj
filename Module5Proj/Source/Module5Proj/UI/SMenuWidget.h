// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

class SMenuWidget : public SCompoundWidget
{

public:

	SLATE_BEGIN_ARGS(SMenuWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class AModule5ProjHUD>, OwningHUD)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	FReply OnPlayClicked() const;
	FReply OnQuitClicked() const;

	TWeakObjectPtr<class AModule5ProjHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };

};