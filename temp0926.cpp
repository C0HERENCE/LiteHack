uint64 dec_fname(uint64 fname1, uint64 fname2) // 0x18  0x1C
{
	uint64 v48 = fname1;
	uint64 v45 = fname2;
	uint64 a12;
	LODWORD(a12) = __ROR4__(v48 ^ 0xD0F31505, 12) ^ (__ROR4__(v48 ^ 0xD0F31505, 12) << 16) ^ 0x52070AF0;
	HIDWORD(a12) = __ROR4__(v45 ^ 0xAF058F7, 6) ^ (__ROR4__(v45 ^ 0xAF058F7, 6) << 16) ^ 0xC5F6D0F3;
}
uint64 dec_uclass(uint64 uclass) //0x28
{
	uint64 v24 = uclass;
	return (__ROL8__(v24 ^ 0x665B98933272E58C, 21) ^ (__ROL8__(v24 ^ 0x665B98933272E58C, 21) << 32) ^ 0xBB57415CF335D646);
}
uint64 dec_outer(uint64 out) //0x10
{
	uint64 v30 = out;
	return (__ROR8__(v30 ^ 0xE2FFCEA309ED3A2B, 30) ^ (__ROR8__(v30 ^ 0xE2FFCEA309ED3A2B, 30) << 32) ^ 0xD6AECB5A6D8252C0);
}
uint64 dec_gname(uint64 gname) //0x46546c0 0x4178
{
	v3 = gname;
	LODWORD(v24) = (v3 + 638921045) ^ 0x157521DB;
	HIDWORD(v24) = (HIDWORD(v3) + 1878663819) ^ 0x6B056B45;
	v12 = *v24 >> 32;
	v13 = ((unsigned __int16)* v24 ^ ((unsigned int)* v24 >> 16) | *v24 & 0xFFFF0000) + 779007602;
	LODWORD(v24) = ((unsigned __int16)v13 ^ (v13 >> 16) | ((unsigned __int16)__ROR2__(HIWORD(v13), 8) << 16)) ^ 0x2E6EB672;
	HIDWORD(v24) = ((((unsigned __int16)__ROR2__(v12 ^ WORD1(v12), 8) | ((unsigned __int16)__ROR2__(WORD1(v12), 8) << 16))
		+ 758197682) & 0xFFFF0000 | (unsigned __int16)__ROR2__(
		(__ROR2__(v12 ^ WORD1(v12), 8) + 11698) ^ ((((unsigned __int16)__ROR2__(v12 ^ WORD1(v12), 8) | ((unsigned int)(unsigned __int16)__ROR2__(WORD1(v12), 8) << 16)) + 758197682) >> 16),
			8)) ^ 0xD2CED24E;
	v14 = ((*v24 >> 32) + 1511283285) ^ 0xA5EBA5AB;
	LODWORD(v24) = __ROL4__(__ROL4__((*v24 - 612692171) ^ 0x5CDC84FC, 8) + 2019062839, 8);
	HIDWORD(v24) = (v14 ^ 0xF9D7F997) - 103286377;
	a6 = v24;

	v9 = *v7;
	LODWORD(a7) = __ROR4__(__ROR4__(a6, 8) - 2019062839, 8) ^ 0x87A78BC9;
	HIDWORD(a7) = (HIDWORD(a6) + 103286377) ^ 0xF9D7F997;
	v10 = (*a7 + 375732485) ^ 0x65C5318B;
	v11 = ((*a7 >> 32) + 1605005883) ^ 0x1B551B95;
	a7 = (_QWORD*)__PAIR__(v11, v10);
	/*
	v12 = *(_QWORD*)(*(_QWORD*)(__PAIR__(v11, v10) + 8i64 * (v9 / 16760)) + 8i64 * (v9 % 16760));
	LODWORD(a6) = __ROL4__((__ROL4__(v12 ^ 0x34B4E48C, 8) ^ 0x34D003BD) - 884270220, 8) ^ 0x99D003BD;
	HIDWORD(a6) = ((HIDWORD(v12) ^ 0x550B0A1C) - 856371980) ^ 0xFEFFC6E8;
	*v8 = a6;*/
	return a7;
}
uint64 dec_gobjid(int v2)//0x20
{
	v9 = __ROL4__(v2 ^ 0x45053BED, 3) ^ (__ROL4__(v2 ^ 0x45053BED, 3) << 16) ^ 0xE87EAEA0;
	return v9;
}


__int64 __usercall sub_7FF6E2A01AA0@<rax > (AK::MusicEngine* a1@<rdx > , AK::MusicEngine* a2@<rcx > , __int64 a3@<rdi > , __int64 a4@<r8 > , __int64 a5@<r12 > , __int64 a6@<r13 > , __int64 a7, __int64 a8, __int64 a9, __int64 a10, __int64 a11, __int64 a12, __int64 a13, __int64 a14, __int64 a15)
{
	__int64 v15; // rsi
	AK::MusicEngine* v16; // r14
	AK::MusicEngine* v17; // rbp
	__int64 v18; // rbx
	AK::MusicEngine* v19; // rcx
	AK::MusicEngine* v20; // rcx
	AK::MusicEngine* v21; // rcx
	__int64 v22; // rbx
	unsigned __int64 v23; // rdi
	__int64 v24; // rbx
	AK::MusicEngine* v25; // rcx
	AK::MusicEngine* v26; // rcx
	AK::MusicEngine* v27; // rcx
	__int64 v28; // rax
	AK::MusicEngine* v29; // rcx
	__int64 v30; // rbx
	AK::MusicEngine* v31; // rcx
	AK::MusicEngine* v32; // rcx
	__int64 v33; // rbx
	AK::MusicEngine* v34; // rcx
	AK::MusicEngine* v35; // rcx
	AK::MusicEngine* v36; // rcx
	__int64 v37; // rbx
	int v38; // eax
	_BOOL8 v39; // rax
	signed __int16* v40; // rdx
	signed __int16 v41; // ax
	__int64 v42; // rbx
	int v43; // eax
	_BOOL8 v44; // rax
	int v45; // edi
	AK::MusicEngine* v46; // rcx
	AK::MusicEngine* v47; // rcx
	int v48; // ebx
	AK::MusicEngine* v49; // rcx
	AK::MusicEngine* v50; // rcx
	AK::MusicEngine* v51; // rcx
	__int64 result; // rax
	__int64 v53; // rbx
	int v54; // eax
	__int64 v55; // rcx

	v15 = a4;
	v16 = a1;
	v17 = a2;
	if (a2 != a1 && a2)
	{
		v18 = *((_QWORD*)a2 + 2);                  // 0x10 Outer
		a13 = a3;
		a14 = a5;
		AK::MusicEngine::Term(a2);
		AK::MusicEngine::Term(v19);
		AK::MusicEngine::Term(v20);                 // ID Dec
		v22 = __ROR8__(v18 ^ 0xE2FFCEA309ED3A2Bui64, 30);
		v23 = v22 ^ (v22 << 32) ^ 0xD6AECB5A6D8252C0ui64;
		if (v22 != ((v22 << 32) ^ 0xD6AECB5A6D8252C0ui64) && (AK::MusicEngine*)v23 != v16)
		{
			a15 = a6;
			((void(__fastcall*)(unsigned __int64, AK::MusicEngine*, __int64))sub_7FF6E2A01AA0)(
				v22 ^ (v22 << 32) ^ 0xD6AECB5A6D8252C0ui64,
				v16,
				v15);
			v24 = *(_QWORD*)((v22 ^ (v22 << 32) ^ 0xD6AECB5A6D8252C0ui64) + 0x28); // 0x28 Class
			AK::MusicEngine::Term(v25);
			AK::MusicEngine::Term(v26);
			AK::MusicEngine::Term(v27);
			v28 = sub_7FF6E2306EA0();
			v29 = (AK::MusicEngine*)(__ROL8__(v24 ^ 0x665B98933272E58Ci64, 21) ^ (__ROL8__(v24 ^ 0x665B98933272E58Ci64, 21) << 32) ^ 0xBB57415CF335D646ui64);//class dec
			if (v29 == (AK::MusicEngine*)v28)
				goto LABEL_20;
			v30 = *(_QWORD*)(v23 + 0x10);//0x10 Outer
			AK::MusicEngine::Term(v29);
			AK::MusicEngine::Term(v31);
			AK::MusicEngine::Term(v32);
			v33 = *(_QWORD*)((__ROR8__(v30 ^ 0xE2FFCEA309ED3A2Bui64, 30) ^ (__ROR8__(v30 ^ 0xE2FFCEA309ED3A2Bui64, 30) << 32) ^ 0xD6AECB5A6D8252C0ui64)
				+ 0x28);
			AK::MusicEngine::Term(v34);
			AK::MusicEngine::Term(v35);
			AK::MusicEngine::Term(v36);
			if ((__ROL8__(v33 ^ 0x665B98933272E58Ci64, 21) ^ (__ROL8__(v33 ^ 0x665B98933272E58Ci64, 21) << 32) ^ 0xBB57415CF335D646ui64) != sub_7FF6E2306EA0())
			{
			LABEL_20:
				v42 = *(signed int*)(v15 + 8);
				v43 = v42 + 2 - (*(_DWORD*)(v15 + 8) != 0);
				*(_DWORD*)(v15 + 8) = v43;
				if (v43 > * (_DWORD*)(v15 + 12))
					sub_7FF6E1BBCE40(v15);
				v44 = (_DWORD)v42 != 0;
				v21 = (AK::MusicEngine*)(v42 - v44);
				v40 = (signed __int16*)(*(_QWORD*)v15 + 2 * (v42 - v44));
				v41 = 46;
			}
			else
			{
				v37 = *(signed int*)(v15 + 8);
				v38 = v37 + 2 - (*(_DWORD*)(v15 + 8) != 0);
				*(_DWORD*)(v15 + 8) = v38;
				if (v38 > * (_DWORD*)(v15 + 12))
					sub_7FF6E1BBCE40(v15);
				v39 = (_DWORD)v37 != 0;
				v21 = (AK::MusicEngine*)(v37 - v39);
				v40 = (signed __int16*)(*(_QWORD*)v15 + 2 * (v37 - v39));
				v41 = 58;
			}
			*v40 = v41;
			v40[1] = 0;
		}
		v45 = *((_DWORD*)v17 + 7);
		AK::MusicEngine::Term(v21);
		AK::MusicEngine::Term(v46);
		AK::MusicEngine::Term(v47);
		v48 = *((_DWORD*)v17 + 6);
		AK::MusicEngine::Term(v49);
		AK::MusicEngine::Term(v50);
		AK::MusicEngine::Term(v51);
		LODWORD(a12) = __ROR4__(v48 ^ 0xD0F31505, 12) ^ (__ROR4__(v48 ^ 0xD0F31505, 12) << 16) ^ 0x52070AF0;
		HIDWORD(a12) = __ROR4__(v45 ^ 0xAF058F7, 6) ^ (__ROR4__(v45 ^ 0xAF058F7, 6) << 16) ^ 0xC5F6D0F3;
		result = sub_7FF6E361F5C0(&a12, v15);
	}
	else
	{
		v53 = *(signed int*)(a4 + 8);
		v54 = v53 + 5 - (*(_DWORD*)(a4 + 8) != 0);
		*(_DWORD*)(a4 + 8) = v54;
		if (v54 > * (_DWORD*)(a4 + 12))
			sub_7FF6E1BBCE40(a4);
		v55 = v53 - ((_DWORD)v53 != 0);
		result = *(_QWORD*)v15;
		*(_QWORD*)(result + 2 * v55) = 28429445101453390i64;
		*(_WORD*)(result + 2 * v55 + 8) = 0;
	}
	return result;
}

__int64 sub_7FF6E361F5C0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, ...)
{
	__int64 v7; // rbx
	__int64 v8; // rsi
	__int64 v9; // rdx
	__int64 result; // rax
	__int64 v11; // rdi
	int v12; // eax
	_WORD* v13; // rdx
	__int64 v14; // [rsp+58h] [rbp+30h]
	va_list va; // [rsp+68h] [rbp+40h]

	va_start(va, a7);
	v7 = a2;
	v8 = a1;
	v9 = *(_QWORD*)sub_7FF6E29195D0(a1, (__int64*)va);
	LODWORD(v14) = __ROR4__((__ROR4__(v9 ^ 0x99D003BD, 8) + 884270220) ^ 0x34D003BD, 8) ^ 0x34B4E48C;
	HIDWORD(v14) = ((HIDWORD(v9) ^ 0xFEFFC6E8) + 856371980) ^ 0x550B0A1C;
	result = sub_7FF6E361F3D0(v14, v7);
	if (*(_DWORD*)(v8 + 4))
	{
		v11 = *(signed int*)(v7 + 8);
		v12 = v11 + 2 - (*(_DWORD*)(v7 + 8) != 0);
		*(_DWORD*)(v7 + 8) = v12;
		if (v12 > * (_DWORD*)(v7 + 12))
			sub_7FF6E1BBCE40(v7);
		v13 = (_WORD*)(*(_QWORD*)v7 + 2 * (v11 - ((_DWORD)v11 != 0)));
		*v13 = 95;
		v13[1] = 0;
		result = sub_7FF6E1DA6080(v7, (unsigned int)(*(_DWORD*)(v8 + 4) - 1));
	}
	return result;
}
_QWORD* __fastcall sub_7FF6E29195D0(int* a1, _QWORD* a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, _QWORD* a7)
{
	int* v7; // rbx
	_QWORD* v8; // rdi
	int v9; // esi
	unsigned int v10; // eax
	unsigned int v11; // ecx
	__int64 v12; // rdx

	v7 = a1;
	v8 = a2;
	sub_7FF6E3620570(&a6);
	v9 = *v7;
	LODWORD(a7) = __ROR4__(__ROR4__(a6, 8) - 2019062839, 8) ^ 0x87A78BC9;
	HIDWORD(a7) = (HIDWORD(a6) + 103286377) ^ 0xF9D7F997;
	v10 = (*a7 + 375732485) ^ 0x65C5318B;
	v11 = ((*a7 >> 32) + 1605005883) ^ 0x1B551B95;
	a7 = (_QWORD*)__PAIR__(v11, v10);
	v12 = *(_QWORD*)(*(_QWORD*)(__PAIR__(v11, v10) + 8i64 * (v9 / 16760)) + 8i64 * (v9 % 16760));
	LODWORD(a6) = __ROL4__((__ROL4__(v12 ^ 0x34B4E48C, 8) ^ 0x34D003BD) - 884270220, 8) ^ 0x99D003BD;
	HIDWORD(a6) = ((HIDWORD(v12) ^ 0x550B0A1C) - 856371980) ^ 0xFEFFC6E8;
	*v8 = a6;
	return v8;
}
AK::MusicEngine* __fastcall sub_7FF6E3620570(AK::MusicEngine* a1)
{
	AK::MusicEngine* v1; // rdi
	_DWORD* v2; // rbx
	__int64 v3; // rcx
	unsigned __int64 v4; // r10
	unsigned int v5; // er8
	__int64 v6; // rdx
	__int64 v7; // rbx
	__int64 v8; // rax
	__int64 v9; // r9
	unsigned int v10; // edx
	_QWORD* v11; // rsi
	__int64 v12; // r9
	unsigned int v13; // edx
	int v14; // ch^3
	int v16; // er8
	unsigned int v17; // edx
	int v18; // eax
	unsigned __int16 v19; // r9
	int v20; // er8
	__int64* v21; // [rsp+58h] [rbp+30h]
	__int64 v22; // [rsp+58h] [rbp+30h]
	_QWORD* v23; // [rsp+58h] [rbp+30h]
	_QWORD* v24; // [rsp+58h] [rbp+30h]
	__int64 v25; // [rsp+58h] [rbp+30h]
	__int64 v26; // [rsp+58h] [rbp+30h]

	v1 = a1;
	AK::MusicEngine::Term(a1);
	v2 = (_DWORD*)(*(_QWORD*)(__readgsqword(0x58u) + 8i64 * (unsigned int)dword_7FF6E5F5AFA8) + 24i64);
	if (dword_7FF6E5F146A8 > * v2)
	{
		sub_7FF6E3DE3EA4(&dword_7FF6E5F146A8);
		if (dword_7FF6E5F146A8 == -1)
		{
			qword_7FF6E5F146A0 = 5464919505576656896i64;
			sub_7FF6E3DE3E44(&dword_7FF6E5F146A8);
		}
	}
	if (dword_7FF6E5F146B8 > * v2)
	{
		sub_7FF6E3DE3EA4(&dword_7FF6E5F146B8);
		if (dword_7FF6E5F146B8 == -1)
		{
			v16 = (unsigned __int64)& qword_7FF6E5F146A0;
			v17 = (((unsigned __int16)__ROL2__((v16 ^ 0x2E6EB672u) >> 16, 8) << 16) | (unsigned __int16)(v16 ^ 0xB672) ^ (unsigned __int16)__ROL2__((v16 ^ 0x2E6EB672u) >> 16, 8))
				- 779007602;
			v18 = (((unsigned __int64)& qword_7FF6E5F146A0 >> 32) ^ 0xD2CED24E) >> 16;
			v19 = __ROL2__(((unsigned __int64)& qword_7FF6E5F146A0 >> 32) ^ 0xD24E, 8);
			LODWORD(v25) = v17 & 0xFFFF0000 | (unsigned __int16)((v16 ^ 0xB672 ^ __ROL2__((v16 ^ 0x2E6EB672u) >> 16, 8))
				+ 18830) ^ (v17 >> 16);
			v20 = ((v18 << 16) | v18 ^ v19) - 758197682;
			HIDWORD(v25) = ((unsigned __int16)__ROL2__(HIWORD(v20), 8) << 16) | (unsigned __int16)__ROL2__(HIWORD(v20), 8) ^ (unsigned __int16)__ROL2__((v18 ^ v19) - 11698, 8);
			qword_7FF6E5F146B0 = v25;
			sub_7FF6E3DE3E44(&dword_7FF6E5F146B8);
		}
	}
	if (dword_7FF6E5F146C8 > * v2)
	{
		sub_7FF6E3DE3EA4(&dword_7FF6E5F146C8);
		if (dword_7FF6E5F146C8 == -1)
		{
			LODWORD(v26) = ((unsigned __int64)& qword_7FF6E5F146B0 ^ 0x157521DB) - 638921045;
			HIDWORD(v26) = (((unsigned __int64)& qword_7FF6E5F146B0 >> 32) ^ 0x6B056B45) - 1878663819;
			qword_7FF6E5F146C0 = v26;
			sub_7FF6E3DE3E44(&dword_7FF6E5F146C8);
		}
	}
	v3 = qword_7FF6E5F146C0;
	LODWORD(v21) = (qword_7FF6E5F146C0 + 638921045) ^ 0x157521DB;
	HIDWORD(v21) = (HIDWORD(qword_7FF6E5F146C0) + 1878663819) ^ 0x6B056B45;
	v4 = (unsigned __int64)* v21 >> 32;
	v5 = ((unsigned __int16)* v21 ^ ((unsigned int)* v21 >> 16) | *v21 & 0xFFFF0000) + 779007602;
	LODWORD(v21) = ((unsigned __int16)v5 ^ (v5 >> 16) | ((unsigned __int16)__ROR2__(HIWORD(v5), 8) << 16)) ^ 0x2E6EB672;
	HIDWORD(v21) = ((((unsigned __int16)__ROR2__(WORD1(v4) ^ v4, 8) | ((unsigned __int16)__ROR2__(WORD1(v4), 8) << 16))
		+ 758197682) & 0xFFFF0000 | (unsigned __int16)__ROR2__(
		(__ROR2__(WORD1(v4) ^ v4, 8) + 11698) ^ ((((unsigned __int16)__ROR2__(WORD1(v4) ^ v4, 8) | ((unsigned int)(unsigned __int16)__ROR2__(WORD1(v4), 8) << 16)) + 758197682) >> 16),
			8)) ^ 0xD2CED24E;
	v6 = *v21;
	LODWORD(v21) = ((unsigned __int64)* v21 - 612692171) ^ 0xDB7B0F35;
	HIDWORD(v21) = (HIDWORD(v6) + 1511283285) ^ 0xA5EBA5AB;
	if (!v21)
	{
		v7 = sub_7FF6E1DC6C60(24i64);
		if (v7)
		{
			*(_QWORD*)v7 = -4923937037232375674i64;
			*(_QWORD*)(v7 + 8) = 912473201220853264i64;
			*(_QWORD*)(v7 + 16) = -6116713020545624802i64;
			v8 = sub_7FF6E1DC6C60(1008i64);
			LODWORD(v22) = (v8 ^ 0x65C5318B) - 375732485;
			HIDWORD(v22) = (HIDWORD(v8) ^ 0x1B551B95) - 1605005883;
			*(_QWORD*)v7 = v22;
			j_memset((void*)v8, 0, 0x3F0ui64);
		}
		else
		{
			v7 = 0i64;
		}
		LODWORD(v23) = (qword_7FF6E5F146C0 + 638921045) ^ 0x157521DB;
		HIDWORD(v23) = (HIDWORD(qword_7FF6E5F146C0) + 1878663819) ^ 0x6B056B45;
		v9 = *v23 >> 32;
		v10 = ((unsigned __int16)* v23 ^ ((unsigned int)* v23 >> 16) | *v23 & 0xFFFF0000) + 779007602;
		LODWORD(v23) = ((unsigned __int16)v10 ^ (v10 >> 16) | ((unsigned __int16)__ROR2__(HIWORD(v10), 8) << 16)) ^ 0x2E6EB672;
		HIDWORD(v23) = ((((unsigned __int16)__ROR2__(v9 ^ WORD1(v9), 8) | ((unsigned __int16)__ROR2__(WORD1(v9), 8) << 16))
			+ 758197682) & 0xFFFF0000 | (unsigned __int16)__ROR2__(
			(__ROR2__(v9 ^ WORD1(v9), 8) + 11698) ^ ((((unsigned __int16)__ROR2__(v9 ^ WORD1(v9), 8) | ((unsigned int)(unsigned __int16)__ROR2__(WORD1(v9), 8) << 16)) + 758197682) >> 16),
				8)) ^ 0xD2CED24E;
		v11 = v23;
		LODWORD(v23) = (v7 ^ 0xDB7B0F35) + 612692171;
		HIDWORD(v23) = (HIDWORD(v7) ^ 0xA5EBA5AB) - 1511283285;
		*v11 = v23;
		v3 = qword_7FF6E5F146C0;
	}
	LODWORD(v24) = (v3 + 638921045) ^ 0x157521DB;
	HIDWORD(v24) = (HIDWORD(v3) + 1878663819) ^ 0x6B056B45;
	v12 = *v24 >> 32;
	v13 = ((unsigned __int16)* v24 ^ ((unsigned int)* v24 >> 16) | *v24 & 0xFFFF0000) + 779007602;
	LODWORD(v24) = ((unsigned __int16)v13 ^ (v13 >> 16) | ((unsigned __int16)__ROR2__(HIWORD(v13), 8) << 16)) ^ 0x2E6EB672;
	HIDWORD(v24) = ((((unsigned __int16)__ROR2__(v12 ^ WORD1(v12), 8) | ((unsigned __int16)__ROR2__(WORD1(v12), 8) << 16))
		+ 758197682) & 0xFFFF0000 | (unsigned __int16)__ROR2__(
		(__ROR2__(v12 ^ WORD1(v12), 8) + 11698) ^ ((((unsigned __int16)__ROR2__(v12 ^ WORD1(v12), 8) | ((unsigned int)(unsigned __int16)__ROR2__(WORD1(v12), 8) << 16)) + 758197682) >> 16),
			8)) ^ 0xD2CED24E;
	v14 = ((*v24 >> 32) + 1511283285) ^ 0xA5EBA5AB;
	LODWORD(v24) = __ROL4__(__ROL4__((*v24 - 612692171) ^ 0x5CDC84FC, 8) + 2019062839, 8);
	HIDWORD(v24) = (v14 ^ 0xF9D7F997) - 103286377;
	*(_QWORD*)v1 = v24;
	return v1;
}