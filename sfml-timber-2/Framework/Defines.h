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
	Mode, //3   �ӽ÷� 2�� 3�� �ڸ� �ٲ�. ���߿� �� �ٲ������. �׽�Ʈ��.
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

enum class PlayerSlot
{
	Single,       
	CoopPlayer1,  
	CoopPlayer2   
};