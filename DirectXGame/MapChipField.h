#includ

class MapChipField{
//1ブロックのサイズ
	static inline const float kBlockWidth = 1.0f;
	static inline const float kBlockHeidth = 1.0f;
//ブロックの個数
	static inline const uint32_t kNumBlockVirtical = 20;
	static inline const uint32_t kNumBlockHorizontal = 100;
	MapChipData mapChipData_;
};

enum class MapChipType {
	kBlock,
	kBlock,
};
struct MapChipData {
	std::vector<std::vector<MapChipType>> data;
};