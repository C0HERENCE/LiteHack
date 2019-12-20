#include "Updates.h"
#include "Global.h"
uint64 Dec::ulevel(uint64 v27)
{
	int v28; // eax@7
	int v29; // eax@7
	__int64 v42; // [sp+40h] [bp+18h]@7

	v28 = __ROR4__(v27, 8);
	v29 = __ROR4__(v28 + 928480025, 8);
	LODWORD(v42) = v29 ^ 0x37577B19;
	HIDWORD(v42) = (HIDWORD(v27) - 1233602887) ^ 0x49874947;

	return v42;
}
uint64 Dec::gameinstance(uint64 v1)
{
	int v2; // eax@1
	int v3; // eax@1
	__int64 v5; // [sp+8h] [bp+8h]@1

	v2 = __ROL4__(v1 + 1667009167, 8);
	LODWORD(v1) = __ROR4__(HIDWORD(v1) - 721562248, 16);
	v3 = __ROR4__(v2 - 2113143344, 16);
	LODWORD(v1) = __ROR4__(v1 + 1922950233, 8);
	LODWORD(v5) = v3 ^ 0x8FAF7341;
	HIDWORD(v5) = v1 ^ 0xF15FF11F;

	return v5;
}
// ULevel
uint64 Dec::actor(uint64 v30)
{
	int v31; // eax@7
	int v32; // eax@7
	__int64 v42; // [sp+40h] [bp+18h]@7

	v31 = __ROR4__(v30, 8);
	v32 = __ROR4__(~v31 - 1315844737, 8);
	LODWORD(v42) = v32 ^ 0x4E6E3280;
	HIDWORD(v42) = (~HIDWORD(v30) + 807284959) ^ 0x301E30DE;

	return v42;
}
// AActor
uint64 Dec::pawn(uint64 v37)
{
	unsigned __int64 v38; // r9@55
	unsigned __int16 v39; // ax@55
	unsigned int v40; // edx@55
	unsigned __int16 v41; // ax@55
	unsigned __int16 v42; // ax@55
	__int64 v49; // [sp+38h] [bp-30h]@7

	v38 = v37 >> 32;
	v39 = __ROL2__(WORD1(v37), 8);
	v40 = (((unsigned int)v37 >> 16) ^ (unsigned __int16)v37 | (v39 << 16)) + 1139005261;
	v41 = __ROR2__((v37 >> 32) ^ WORD1(v38), 8);
	LODWORD(v49) = (v40 & 0xFFFF0000 | (unsigned __int16)((WORD1(v37) ^ v37) - 10419) ^ (v40 >> 16)) ^ 0x43E3D74D;
	LODWORD(v37) = (HIDWORD(v37) & 0xFFFF0000 | v41) - 1037254035;
	v42 = __ROL2__(WORD1(v37), 8);
	LODWORD(v40) = __ROR2__(v37 ^ WORD1(v37), 8);
	HIDWORD(v49) = ((unsigned __int16)v40 | (v42 << 16)) ^ 0x3DD33D93;

	return v49;

}
// UGameInstance
uint64 Dec::localplayer(uint64 v20)
{
	__int64 v6; // rax@4
	__int64 v14; // [sp+58h] [bp+10h]@9
	v6 = Global::GMemory->Read64(v20); //*(_QWORD *)(v7 + *(_QWORD *)(v1 + 0x100));
	LODWORD(v14) = (v6 + 734732261) ^ 0x2BCB1FE5;
	HIDWORD(v14) = (HIDWORD(v6) - 1429951995) ^ 0x553B55FB;

	return v14;
}
// ULocalPlayer
uint64 Dec::playercontroller(uint64 v9)
{
	__int64 v6; // rax@4
	unsigned int v10; // ecx@9
	unsigned __int64 v11; // rbx@9

	LODWORD(v6) = __ROL4__(v9 - 205813105, 8);
	LODWORD(v9) = __ROR4__(HIDWORD(v9) + 1683805560, 16);
	LODWORD(v6) = __ROR4__(v6 - 499479040, 16);
	LODWORD(v6) = v6 ^ 0x5F7F0371;
	LODWORD(v9) = __ROR4__(v9 - 768756855, 8);
	v10 = v9 ^ 0x212F21EF;
	v11 = __PAIR__(v10, (unsigned int)v6);

	return v11;
}
uint32 Dec::ObjID(uint32 v10)
{
	return __ROR4__(v10 ^ 0x9573A54F, 15) ^ (__ROR4__(v10 ^ 0x9573A54F, 15) << 16) ^ 0xFEFD1DCA;
}