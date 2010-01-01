#include <windows.h>

int WINAPI WinMain( HINSTANCE hInstance,
				    HINSTANCE hPrevInstance,
					PSTR cmdLine,
					int showCmd )
{
	MessageBox( 0, L"Hello!", L"Title Bar", MB_OK );
}