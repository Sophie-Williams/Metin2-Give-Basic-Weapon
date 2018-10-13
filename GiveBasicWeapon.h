#include <vector>
#include <array>
#include "../../common/length.h"
#include "item_manager.h"
using namespace std;
enum 
{ 
	MAX_ATTR = ITEM_MANAGER::MAX_NORM_ATTR_NUM + ITEM_MANAGER::MAX_RARE_ATTR_NUM, 
	COMMON_ITEMS = JOB_MAX_NUM,
};
struct GiveBasicWeapon
{
	DWORD	dwVnum, count;
	bool	equip;
	array<auto, ITEM_SOCKET_MAX_NUM> sockets;
	array<auto, MAX_ATTR> attr_types;
	array<auto, MAX_ATTR> attr_vals;
};
vector<GiveBasicWeapon> Give_Items[JOB_MAX_NUM];

auto PrepareItems()
{
	Give_Items[COMMON_ITEMS] {
		{11200, 1},
		{27989, 1},
		{50053, 1},
		{40002, 1},
		{27003, 200},
		{27006, 200},
		{70038, 1},
		{13009, 1, true, {}, {APPLY_CON, APPLY_BLOCK, APPLY_REFLECT_MELEE, APPLY_IMMUNE_STUN, APPLY_STR}, {12, 15, 10, 1, 12}},
		{14009, 1, true, {}, {APPLY_MAX_HP, APPLY_MAX_SP, APPLY_PENETRATE_PCT, APPLY_STEAL_HP, APPLY_MANA_BURN_PCT}, {2000, 80, 10, 10, 10}},
		{15009, 1, true, {}, {APPLY_MAX_HP, APPLY_MAX_SP, APPLY_MOV_SPEED, APPLY_ATT_SPEED, APPLY_CRITICAL_PCT}, {2000, 80, 8, 8, 10}},
		{16009, 1, true, {}, {APPLY_MAX_HP, APPLY_HP_REGEN, APPLY_CRITICAL_PCT, APPLY_PENETRATE_PCT, APPLY_STEAL_HP}, {2000, 30, 10, 10, 10}},
		{17009, 1, true, {}, {APPLY_MOV_SPEED, APPLY_ATTBONUS_ANIMAL, APPLY_POISON_REDUCE, APPLY_ATTBONUS_DEVIL, APPLY_ATTBONUS_UNDEAD}, {20, 20, 5, 20, 20}},
		{39036, 1, true},
		{76037, 1, true}
	}
	Give_Items[JOB_WARRIOR] {
		{11209, 1, true, {28442, 0, 0}, {APPLY_MAX_HP, APPLY_CAST_SPEED, APPLY_STEAL_HP, APPLY_REFLECT_MELEE, APPLY_ATT_GRADE_BONUS}, {2000, 20, 10, 10, 50}},
		{19, 	1, true, {28430, 0, 0}, {APPLY_STR, APPLY_CRITICAL_PCT, APPLY_PENETRATE_PCT, APPLY_ATTBONUS_ANIMAL, APPLY_STUN_PCT}, {12, 10, 10, 20, 8}},
		{12209, 1, true, {}, 			{APPLY_ATT_SPEED, APPLY_HP_REGEN, APPLY_ATTBONUS_ANIMAL, APPLY_DODGE, APPLY_STEAL_HP}, {8, 30, 20, 15, 10}},
	}
	Give_Items[JOB_ASSASSIN] {
		{11409, 1, true, {28442, 0, 0}, {APPLY_MAX_HP, APPLY_CAST_SPEED, APPLY_STEAL_HP, APPLY_REFLECT_MELEE, APPLY_ATT_GRADE_BONUS}, {2000, 20, 10, 10, 50}},
		{1009, 	1, true, {28430, 0, 0}, {APPLY_STR, APPLY_CRITICAL_PCT, APPLY_PENETRATE_PCT, APPLY_ATTBONUS_ANIMAL, APPLY_STUN_PCT}, {12, 10, 10, 20, 8}},
		{12349, 1, true, {},			{APPLY_ATT_SPEED, APPLY_HP_REGEN, APPLY_ATTBONUS_ANIMAL, APPLY_DODGE, APPLY_STEAL_HP}, {8, 30, 20, 15, 10}},
	}
	Give_Items[JOB_SURA] {
		{11609, 1, true, {28442, 0, 0}, {APPLY_MAX_HP, APPLY_CAST_SPEED, APPLY_STEAL_HP, APPLY_REFLECT_MELEE, APPLY_ATT_GRADE_BONUS}, {2000, 20, 10, 10, 50}},
		{19, 	1, true, {28430, 0, 0}, {APPLY_STR, APPLY_CRITICAL_PCT, APPLY_PENETRATE_PCT, APPLY_ATTBONUS_ANIMAL, APPLY_STUN_PCT}, {12, 10, 10, 20, 8}},
		{12489, 1, true, {}, 			{APPLY_ATT_SPEED, APPLY_HP_REGEN, APPLY_ATTBONUS_ANIMAL, APPLY_DODGE, APPLY_STEAL_HP}, {8, 30, 20, 15, 10}},
	}
	Give_Items[JOB_SHAMAN] {
		{11809, 1, true, {28442, 0, 0}, {APPLY_MAX_HP, APPLY_CAST_SPEED, APPLY_STEAL_HP, APPLY_REFLECT_MELEE, APPLY_ATT_GRADE_BONUS}, {2000, 20, 10, 10, 50}},
		{5009, 	1, true, {28430, 0, 0}, {APPLY_STR, APPLY_CRITICAL_PCT, APPLY_PENETRATE_PCT, APPLY_ATTBONUS_ANIMAL, APPLY_STUN_PCT}, {12, 10, 10, 20, 8}},
		{12629, 1, true, {}, 			{APPLY_ATT_SPEED, APPLY_HP_REGEN, APPLY_ATTBONUS_ANIMAL, APPLY_DODGE, APPLY_STEAL_HP}, {8, 30, 20, 15, 10}},
	}
#ifdef ENABLE_WOLFMAN_CHARACTER
	Give_Items[JOB_WOLFMAN] {
		{21009, 1, true, {28442, 0, 0}, {APPLY_MAX_HP, APPLY_CAST_SPEED, APPLY_STEAL_HP, APPLY_REFLECT_MELEE, APPLY_ATT_GRADE_BONUS}, {2000, 20, 10, 10, 50}},
		{6009, 	1, true, {28430, 0, 0}, {APPLY_STR, APPLY_CRITICAL_PCT, APPLY_PENETRATE_PCT, APPLY_ATTBONUS_ANIMAL, APPLY_STUN_PCT}, {12, 10, 10, 20, 8}},
		{21509, 1, true, {}, 			{APPLY_ATT_SPEED, APPLY_HP_REGEN, APPLY_ATTBONUS_ANIMAL, APPLY_DODGE, APPLY_STEAL_HP}, {8, 30, 20, 15, 10}},
	}
#endif	
}
void GiveBasicWeapon(LPCHARACTER ch)
{
	PrepareItems();
	auto GetHorse = [&ch]()
	{
		ch->SetHorseLevel(21);
		ch->StartRiding();
	};
	auto MakeFNotice = [](LPCHARACTER ch)
	{
		array<auto, JOB_MAX_NUM> JobNames {"Warrior", "Assassin", "Sura", "Shaman", "Lycan"};
		array<auto, EMPIRE_MAX_NUM> EmpireNames {"전제국","신수국","천조국","진노국"};
		array<auto, 256> buf;
		snprintf(buf,sizeof(buf), "New player %s, job: %s, empire: %s", ch->GetName(), JobNames[ch->GetJob()], LC_TEXT(EmpireNames[ch->GetEmpire()]));
		SendNotice(buf);
	};
	for (auto subdata : {ch->GetJob(), COMMON_ITEMS}) {
		for (auto data : Give_Items[subdata]) {
			auto item = ch->AutoGiveItem(data.dwVnum, data.count);
			if (item) {
				for (auto i = 0; i < MAX_ATTR; i++)
					item->SetForceAttribute(i, data.attr_types[i], data.attr_vals[i]);
				for (auto c = 0; c < ITEM_SOCKET_MAX_NUM; c++)
					item->SetSocket(c, data.sockets[c]);
				if (data.equip)
					ch->EquipItem(item);
			}
		}
	}
	MakeFNotice(ch);
	GetHorse();
}