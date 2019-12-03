#include "Commons.h"



#define TextWidth 150
#define TextHeight 18.5
#define TextAboveHead 50
#define HealthHeight 10
#define BGColor FGRAY_DARKGRAY
#define TextColor FYELLOW_LIGHTGOLDENRODYELLOW

void Radar(ESPInfo& info);

void ESPText(ESPInfo& info);

void ESPLine(ESPInfo& info);

void ESPBone(ESPInfo& info);

void UpdateEnemyInfo(ESPInfo& info, ASTExtraPlayerCharacter^ enemy);

void UpdateLocalInfo(ESPInfo& info, ASTExtraPlayerCharacter^ local_pawn);

void ShowInfo(ASTExtraPlayerCharacter^ local_pawn);