#include<map>
#include"MapChipField.h"

namespace {
std::map<std::string, MapChip> mapChipTable = {
    {"0", MapChipType::kBlock},
    {"1", MapChipType::kBlock},
};
}

void ResetMapChipData();