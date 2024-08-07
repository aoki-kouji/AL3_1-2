#pragma once
#include"Vector3.h"

struct AABB {

public:
	Vector3 min;
	Vector3 max;
};

bool IsCollision(const AABB&, const AABB& aabb2);