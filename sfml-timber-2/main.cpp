#include "stdafx.h"

int main()
{
    Utils::Init();
    FRAMEWORK.Init(1920, 1080, "Timber!!");
    FRAMEWORK.Do();
    FRAMEWORK.Release();

    return 0;
}