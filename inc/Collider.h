#pragma once

namespace Physics 
{
	class PhysicsObjects;
	class SphereCollider;

	class Collider
	{
	public:
		enum class Type 
		{
			NONE,
			SPHERE,
			AABB,
			OBB
		};

		Collider(Type type);
		virtual ~Collider();

		Type GetType() const { return m_type; };

		virtual void Transform(PhysicsObjects* obj) {/* Intentionally left blank*/};

		virtual bool Intersects(Collider* other) const { return false; };

		// static function: a single fuhction no matter how many instances
		static Collider* GetNullInstance();

		static bool SphereToSphereIntersect(const SphereCollider *objA, const SphereCollider *objB);

	protected:
		Type m_type;

	private:

	};
}