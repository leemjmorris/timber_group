#pragma once

// Defines.h

enum class Origins
{
	TL, TC, TR,	// 0 1 2
	ML, MC, MR,	// 3 4 5
	BL, BC, BR, // 6 7 8
	Custom
};

enum class SceneIds
{
	None = -1,
	Title, //0
	Game, //1
	Select, //2
	Mode, //3   임시로 2번 3번 자리 바꿈. 나중에 꼭 바꿔줘야함. 테스트용.
	Dev1, //4
	Dev2, //5
	Count,
};

enum class Sides
{
	Left,
	Right,
	None,
};