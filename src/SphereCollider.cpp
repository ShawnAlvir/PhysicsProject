#include"SphereCollider.h"
#include"PhysicsObjects.h"

using namespace Physics;

SphereCollider::SphereCollider() : m_radius(1.0f), Collider(Type::SPHERE)
{
}

SphereCollider::SphereCollider(float radius) : m_radius(radius), Collider(Type::SPHERE)
{
}

SphereCollider::~SphereCollider()
{
}

bool SphereCollider::Intersects(Collider * other) const
{
	switch (other->GetType())
	{
	case Type::SPHERE:
		return SphereToSphereIntersect(this, (SphereCollider*)other);
	}
	return false;
}

void SphereCollider::Transform(PhysicsObjects * obj)
{
	SetPosition(obj->GetPosition());
}
