#include "GameManager.h"
#include <Novice.h>

const char kWindowTitle[] = "LE2C_03_イケダ_タクミ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    GameManager* gameManager = new GameManager();

    gameManager->Run();

    delete gameManager;

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}
