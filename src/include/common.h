#ifndef COMMON_H
#define COMMON_H

#define BP_AMOUNT 23

#include <string>
#include <map>

extern std::string bp_names[];
extern std::map<std::string, std::string> item_bp;
extern std::map<std::string, int> to_idx;
extern int bp_init_hp[], cl_init_hp[];
extern std::map<std::string, std::map<std::string, int>> init_params;

long long count_score(int lv1, int lv2, int dmg, int heal);
void init_values(int &hp, int &mn, int &agi, int &strength, int &intellect, int &speed, int cl);
#endif // COMMON_H
