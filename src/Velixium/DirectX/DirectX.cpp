#include "DirectX.h"
DirectX directx;

HRESULT __stdcall DirectX::hPresent(LPDIRECT3DDEVICE9 pDevice, const PRECT pSourceRect, const PRECT pDestRect, HWND hDestWindowOverride, const PRGNDATA pDirtyRegion)
{
	if (_pDevice != pDevice)
	{
		//reset everything here

		_pDevice = pDevice;
	}

	//render here

	return pPresent(pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

bool DirectX::Hook()
{

	return true;
}
