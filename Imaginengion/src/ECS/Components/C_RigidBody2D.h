#pragma once

struct C_RigidBody2D {

	C_RigidBody2D() = default;
	C_RigidBody2D(const C_RigidBody2D&) = default;

	enum class BodyType {Static = 0, Dynamic, Kinematic};
	BodyType _Type = BodyType::Static;
	bool _bFixedRotation = false;

	void* RuntimeBody = nullptr;
};