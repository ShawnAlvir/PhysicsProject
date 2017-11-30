#include "Collider.h"
#include "SphereCollider.h"

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

using namespace Physics;

Collider::Collider(Type type) : m_type(type)
{
}

Collider::~Collider()
{
}

Collider * Collider::GetNullInstance()
{
	// will be created once and wll always re-reference this.
	static Collider collider(Type::NONE);
	return &collider;
}

bool Physics::Collider::SphereToSphereIntersect(const SphereCollider * objA, const SphereCollider * objB)
{
	glm::vec3 vSpheres = objA->GetPosition() - objB->GetPosition();
	float distance = glm::length(vSpheres);

	float colDistance = objA->GetRadius() + objB->GetRadius();

	return distance < colDistance;
}
