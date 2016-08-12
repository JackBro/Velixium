#pragma once

#include <d3d9.h>

#include "../dll.h"
#include "imgui.h"
#include "../imgui/examples/directx9_example/imgui_impl_dx9.h"

class DirectX
{
private:
	LPDIRECT3DDEVICE9 _pDevice;

	typedef HRESULT(__stdcall *tPresent) (LPDIRECT3DDEVICE9 pDevice, const PRECT pSourceRect, const PRECT pDestRect, HWND hDestWindowOverride, const PRGNDATA pDirtyRegion);
	tPresent pPresent;
	HRESULT __stdcall hPresent(LPDIRECT3DDEVICE9 pDevice, const PRECT pSourceRect, const PRECT pDestRect, HWND hDestWindowOverride, const PRGNDATA pDirtyRegion);

public:

	bool Hook();

}; extern DirectX directx;