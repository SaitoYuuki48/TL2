#include <cstdio>
#include <cstdlib>
#include "Windows.h"

#include "TextureConverter.h"
#include <cassert>

enum Argument {
	kApplicationPath,  //アプリケーションのパス
	kFilePath,         //渡されたファイルのパス

	NumArgument
};

int main(int argc,char* argv[])
{
	assert(argc >= NumArgument);

	// COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// テクスチャコンバータ
	TextureConverter converter;

	//テクスチャ変換
	converter.ConvertTexWICToDDS(argv[kFilePath]);

	// COM ライブラリの終了
	CoUninitialize();

	system("pause");
	return 0;
}